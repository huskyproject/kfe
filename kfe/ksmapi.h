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
 * It also provides all means to communicate with the smapi
 */

#ifndef _KSMAPI_H
#define _KSMAPI_H

#include <qlist.h>
#include <kconfig.h>

extern "C" {
#include <fidoconfig/fidoconfig.h>
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
    int getAreaCount();
    smapiArea* getCurArea();
    int getCurAreaNum();
    smapiArea* getFirstArea();
    smapiArea* getPrevArea();
    smapiArea* getNextArea();
    smapiArea* getLastArea();
    smapiArea* getFirstNewArea();
    smapiArea* setCurAreaNum(int newareanum);

    void rescanMsgs();
    int getMsgCount();
    smapiMsg* getCurMsg();
    int getCurMsgNum();
    UMSGID getCurUmsgId();
    smapiMsg* getFirstMsg();
    smapiMsg* getPrevMsg();
    smapiMsg* getNextMsg();
    smapiMsg* getLastMsg();
    smapiMsg* getFirstNewMsg();
    smapiMsg* setCurMsgNum(int newareanum);
    smapiMsg* setCurMsgUMSGID(UMSGID newumsgid);

private:
    struct _minf m;
    s_fidoconfig* fidoconfig;

    QList<smapiArea> areaList;
    QList<smapiMsg> msgList;

    KConfig* kdeconfig;    
};

#endif

