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
    //    fidoconfig = readConfig();
    //    printf ("hier knallt\n");

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
    // *** make this scan all areas from fidoconfig

    // *** Check, if arealist is empty, before clearing it?
    // Doesn't seem to make much sense
    
    areaList.clear();

    smapiArea* newArea;

    // *** removed, when fidoconfig is done
#include "areas.c"
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

