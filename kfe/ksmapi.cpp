/*
 *   kfe - a squish base message editor
 *   Copyright (C) 1998  Michael Espey
 *
 */

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

    // *** How should I handle the 'public problem' with libfidoconfig?
    // Mayber I will change it, or someone else, time will tell

    //init fidoconfig
    fidoconfig = readConfig();
}


Ksmapi::~Ksmapi()
{
    smapiArea* area;
    for (area = areaList.first(); area != 0; area = areaList.next()) {
        delete area;
    }
    MsgCloseApi();
}


void Ksmapi::rescanAreas()
{
    printf("Ksmapi::rescanAreas()\n");
    // *** make this scan all areas from fidoconfig

    // *** Check, if arealist is empty, before clearing it?
    // Doesn't seem to make much sense
    
    areaList.clear();

    // *** Check here also for non EchoAreas.

    smapiArea* newArea;
    s_area* fidoconfigarea;

    for (unsigned int i = 0; i < fidoconfig->echoAreaCount; i++) {
        debug("Echo: %s", fidoconfig->echoAreas[i].areaName);
        debug("Nr: %d", i);

        // *** do this only, if it are no passthrough areas
        debug ("is: %d", fidoconfig->echoAreas[i].msgbType);
        if (fidoconfig->echoAreas[i].msgbType == MSGTYPE_SQUISH) {
            debug("passth");
        }
            
        newArea = new smapiArea(
                                fidoconfig->echoAreas[i].areaName,
                                fidoconfig->echoAreas[i].fileName,
                                smapiArea::NORMAL,
                                (fidoconfig->echoAreas[i].msgbType == MSGTYPE_SDM?smapiArea::SDM:smapiArea::SQUISH) | smapiArea::ECHO
                               );
        areaList.append(newArea);
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
    getCurArea()->rescanMsgs();
    printf("\Ksmapi::rescanMsgs()\n");
}

