/*
 *   kfe - a squish base message editor
 *   Copyright (C) 1998  Michael Espey
 *
 */

#include <kprogress.h>
#include "ksmapi.h"


Ksmapi::Ksmapi(word defZone)
{
    //init the SMAPI
    m.req_version = 0;
    m.def_zone = defZone;
    if (MsgOpenApi(&m) != 0) {
        printf("MsgApiOpen Error\n");
        // *** make error box here
    }

    //init fidoconfig
    fidoconfig = readConfig();
    if (fidoconfig != 0) {
        debug("fidoconfig is open");
    } else {
        debug("error opening fidoconfig");
    }
}



Ksmapi::~Ksmapi()
{
    printf("Ksmapi::~Ksmapi()\n");
    
    smapiArea* area;
    for (area = areaList.first(); area != 0; area = areaList.next()) {
        printf("now: %s\n", (const char *)area->getName());
        delete area;
        printf ("--closed area\n");
    }
    printf ("closing done\n");

    MsgCloseApi();
    printf ("after msgcloseapi\n");
}


void Ksmapi::rescanAreas()
{
    printf("Ksmapi::rescanAreas()\n");

    // *** Check, if arealist is empty, before clearing it?
    areaList.clear();

    smapiArea* newArea;

    debug("AreaCount: %d", fidoconfig->echoAreaCount);

    for (unsigned int i = 0; i < fidoconfig->echoAreaCount; i++) {
        // do this only, if it no passthrough area
        if (fidoconfig->echoAreas[i].msgbType != MSGTYPE_PASSTHROUGH) {
            newArea = new smapiArea(
                                    fidoconfig->echoAreas[i].areaName,
                                    fidoconfig->echoAreas[i].fileName,
                                    smapiArea::NORMAL,
                                    (fidoconfig->echoAreas[i].msgbType == MSGTYPE_SDM?smapiArea::SDM:smapiArea::SQUISH) | smapiArea::ECHO);
            areaList.append(newArea);
        }
    }
}



smapiArea* Ksmapi::getCurArea()
{
    return areaList.current();
}



smapiArea* Ksmapi::setCurArea(int newarea)
{
    return areaList.at(newarea);
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
    printf("Ksmapi::rescanMsgs()\n");
    smapiArea* area;
    area = getCurArea();
    
    if (area->getHAREA() != NULL) {
        printf("area != NULL\n");

        int i = 1;
        KProgress* prog = new KProgress(i, area->getMsgNum(), i, KProgress::Horizontal);
        prog->resize(400,40);
        prog->show();

        printf("high: %d\n", area->getMsgNum());

        // Delete old entries in List *** move this to msglistwidget

        smapiMsg* foo;
        QString hdr(256);

        msgList.clear();
        while (i <= area->getMsgNum()) {
            foo = new smapiMsg(area->getHAREA(), MOPEN_READ, (dword)i++);
            msgList.append(foo);
            prog->advance(1);
        }
        prog->hide();
        delete prog;
    } else {
        printf("Could not open %s", "echo->filename");
    }
}



smapiMsg* Ksmapi::getCurMsg()
{
    return msgList.current();
}



smapiMsg* Ksmapi::setCurMsg(int newAreaNum)
{
    return msgList.at(newAreaNum);
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


