/*
 *   kfe - a squish base message editor
 *   Copyright (C) 1998  Michael Espey
 *
 */

#include <kapp.h>
#include <kprogress.h>
#include "ksmapi.h"


Ksmapi::Ksmapi(word defZone)
{
    //init the SMAPI
    m.req_version = 0;
    m.def_zone = defZone;
    if (MsgOpenApi(&m) != 0) {
        fatal("MsgApiOpen Error");
        // *** make error box here
    }

    //init fidoconfig
    fidoconfig = readConfig();
    if (fidoconfig != 0) {
        debug("fidoconfig is open");
    } else {
        fatal("error opening fidoconfig");
    }
}



Ksmapi::~Ksmapi()
{
		kdeconfig = KApplication::getKApplication()->getConfig();
		CHECK_PTR(kdeconfig);
		
		// write current area
		kdeconfig->writeEntry("curarea", getCurAreaNum());
		
		smapiArea* area;
    debug("vor schreiben");
    for (area = areaList.first(); area != 0; area = areaList.next()) {
        debug("write curumsgid:%d", getCurUmsgId());
        kdeconfig->writeEntry(area->getName(), (double)getCurUmsgId());
        delete area;
    }
    kdeconfig->sync();

    debug("nach schreiben");
		
    MsgCloseApi();
}


void Ksmapi::rescanAreas()
{
    debug("Ksmapi::rescanAreas()");
    smapiArea* newarea;
    address* newaddress;

    kdeconfig = KApplication::getKApplication()->getConfig();
    CHECK_PTR(kdeconfig);
    kdeconfig->setGroup("ksmapi");

    if (getCurArea() > 0) {
        // if we don't have a current area, keep the old one
        debug("config lesen");
        kdeconfig->writeEntry("curarea", getCurAreaNum());
        kdeconfig->sync();
    }
    // *** Check, if arealist is empty, before clearing it?
    areaList.clear();

    // open netmail area
    newaddress = new address();
    newaddress->setZone(fidoconfig->netMailArea.useAka->zone);
    newaddress->setNet(fidoconfig->netMailArea.useAka->net);
    newaddress->setNode(fidoconfig->netMailArea.useAka->node);
    newaddress->setPoint(fidoconfig->netMailArea.useAka->point);
    newaddress->setDomain(fidoconfig->netMailArea.useAka->domain);

    newarea = new smapiArea(
			    fidoconfig->netMailArea.areaName,
			    fidoconfig->netMailArea.fileName,
			    MSGAREA_NORMAL,
			    fidoconfig->netMailArea.msgbType,
			    newaddress);
    if (newarea != 0) {
//				areaList.append(newarea);
    } else {
        CHECK_PTR(newarea);
    }

    debug("found lastread: %d", kdeconfig->readDoubleNumEntry(newarea->getName(), (UMSGID)-1));
//    getCurArea()->setLastRead((UMSGID)kdeconfig->readDoubleNumEntry(newarea->getName(), (UMSGID)-1));
    debug("nach new area");

    // open all non-passthrough echo area
    debug("AreaCount: %d", fidoconfig->echoAreaCount);

    for (unsigned int i = 0; i < fidoconfig->echoAreaCount; i++) {
    		debug("in for()");
        // do this only, if it no passthrough area
        if (fidoconfig->echoAreas[i].msgbType != MSGTYPE_PASSTHROUGH) {
        		debug("vor new address");
	    			newaddress = new address();
				    // *** build method s_addr2address
	    			newaddress->setZone(fidoconfig->echoAreas[i].useAka->zone);
				    newaddress->setNet(fidoconfig->echoAreas[i].useAka->net);
            newaddress->setNode(fidoconfig->echoAreas[i].useAka->node);
            newaddress->setPoint(fidoconfig->echoAreas[i].useAka->point);
            newaddress->setDomain(fidoconfig->echoAreas[i].useAka->domain);
            debug("vor new area");
            newarea = new smapiArea(
                                    fidoconfig->echoAreas[i].areaName,
                                    fidoconfig->echoAreas[i].fileName,
                                    MSGAREA_NORMAL,
                                    fidoconfig->echoAreas[i].msgbType | MSGTYPE_ECHO,
                                    newaddress);
            if (newarea != 0) {
                areaList.append(newarea);
            } else {
                CHECK_PTR(newarea);
            }

            debug("found lastread: %d", kdeconfig->readDoubleNumEntry(newarea->getName(), (UMSGID)-1));
            getCurArea()->setLastRead((UMSGID)kdeconfig->readDoubleNumEntry(newarea->getName(), (UMSGID)-1));
            debug("nach new area");
        }
    }
    setCurAreaNum(kdeconfig->readNumEntry("curarea", 1));
    debug("nach rescan. areanum:%d", getCurAreaNum());
    debug("/Ksmapi::rescanAreas()");
}



smapiArea* Ksmapi::getCurArea()
{
    return areaList.current();
}



int Ksmapi::getCurAreaNum()
{
		return areaList.at();
}



smapiArea *Ksmapi::setCurAreaNum(int newat)
{
    debug("smapiArea* Ksmapi::setCurAreaNum(int newarea)");
    debug("new current area num: %d", newat);

    return areaList.at(newat);
    debug("/smapiArea* Ksmapi::setCurArea(int newarea)");
}




smapiArea* Ksmapi::getFirstArea()
{
    return areaList.first();
}



smapiArea* Ksmapi::getNextArea()
{
    return areaList.next();
}



smapiArea* Ksmapi::getPrevArea()
{
    return areaList.prev();
}



smapiArea* Ksmapi::getLastArea()
{
    return areaList.last();
}



void Ksmapi::rescanMsgs()
{
    debug("Ksmapi::rescanMsgs()");
    QString hdr(256);
    debug("CurArea:%d", getCurAreaNum());
    CHECK_PTR(getCurArea());
    msgList.clear();

    if (getCurArea()->getHAREA() != 0) {
        msgList.clear();

        int i = 1;
        KProgress* prog = new KProgress(i, getMsgCount(), i, KProgress::Horizontal);
        prog->resize(400,40);
        prog->show();

        while (i <= getCurArea()->getAreaSize()) {
            msgList.append(new smapiMsg(getCurArea()->getHAREA(), (dword)i++));
            prog->advance(1);
        }
        prog->hide();
        delete prog;
    } else {
        fatal("Could not open %s", "echo->filename");
    }
}



int Ksmapi::getMsgCount()
{
    return msgList.count();
}



smapiMsg* Ksmapi::getCurMsg()
{
		if (msgList.isEmpty() != 0) {
		    return msgList.current();
		} else {
				return 0;
		}
}



int Ksmapi::getCurMsgNum()
{
    return msgList.at() + 1;
}



UMSGID Ksmapi::getCurUmsgId()
{
    return (getCurArea()->msgNum2UmsgId(getCurMsgNum()));
}



smapiMsg* Ksmapi::getFirstMsg()
{
    return msgList.first();
}



smapiMsg* Ksmapi::getPrevMsg()
{
    return msgList.prev();
}



smapiMsg* Ksmapi::getNextMsg()
{
    return msgList.next();
}



smapiMsg* Ksmapi::getLastMsg()
{
    return msgList.last();
}



smapiMsg* Ksmapi::getFirstNewMsg()
{
    return 0; //msgList.current();
}
















































