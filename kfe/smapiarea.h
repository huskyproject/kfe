#ifndef _SMAPIAREA_H
#define _SMAPIAREA_H

#include "qstring.h"
#include "qlist.h"
#include <stdio.h>

extern "C" {
#include <msgapi.h>
}
#include "smapimsg.h"


class smapiArea
{
public:
    smapiArea(char* newname, char* newpath, word mode, word type);
    ~smapiArea();

    QString getName();
    QString getPath();
    int getMsgNum();
    int getCurMsgNum();
    int getNewMsgNum();
    HAREA getHAREA();

    enum OPENMODE {NORMAL, CREAT, CRIFNEC};
    enum AREATYPE {SDM, SQUISH, ECHO};

private:
    HAREA harea;

    QString name;
    QString path;
    
    int msgs;
    int curmsg;
    int newmsgs;

};

#endif