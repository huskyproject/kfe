/*
 *   kfe - a squish base message editor
 *   Copylefted (C) 1998  Michael Espey
 *
 *****************************************************************************
 *
 * class Ksmapi
 * This class is a complete wrapper around the functionality of the
 * Squish Msg Api. It maintains a QList of all areas mentioned in
 * fidoconfig and a QList of all Msgs in the current Area
 */

#ifndef _KSMAPI_H
#define _KSMAPI_H

#include <qlist.h>

extern "C" {
#include <fidoconfig.h>
}

#include "smapiarea.h"
#include "smapimsg.h"


class Ksmapi
{
public:
    Ksmapi(word defZone);
    ~Ksmapi();

    // Area orientated functions
    void rescanAreas();
    smapiArea* getCurArea();
    smapiArea* setCurArea(int newAreaNum);
    smapiArea* getFirstArea();
    smapiArea* getPrevArea();
    smapiArea* getNextArea();
    smapiArea* getLastArea();
    smapiArea* getFirstNewArea();

    void rescanMsgs();
    smapiMsg* getCurMsg();
    smapiMsg* setCurMsg(int newAreaNum);
    smapiMsg* getFirstMsg();
    smapiMsg* getPrevMsg();
    smapiMsg* getNextMsg();
    smapiMsg* getLastMsg();
    smapiMsg* getFirstNewMsg();

private:
    struct _minf m;

    QList<smapiArea> areaList;
    QList<smapiMsg> msgList;
    
    s_fidoconfig* fidoconfig;
};

#endif