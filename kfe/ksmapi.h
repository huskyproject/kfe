/*
 *   kfe - a squish base message editor
 *   Copylefted (C) 1998  Michael Espey
 *
 *****************************************************************************
 *
 * class Ksmapi
 * This class is a complete wrapper around the functionality of the
 * Squish Msg Api. It maintains a QList of all areas mentioned in
 * fidoconfig.
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
    smapiArea* getNextArea();
    smapiArea* getPrevArea();
    smapiArea* getLastArea();
    smapiArea* getFirstNewArea();

    void rescanMsgs();

private:
    struct _minf m;

    QList<smapiArea> areaList;

    s_fidoconfig* fidoconfig;
};

#endif
