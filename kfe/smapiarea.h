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

    HAREA harea;

    QString name;
    QString path;
    
    int msgs;
    int curmsg;
    int newmsgs;

public:
    void rescanMsgs();

    QString getName();
    QString getPath();
    int getMsgNum();
    int getCurMsgNum();
    int getNewMsgNum();

    // functions related to this area msg, all called from Ksmapi
    smapiMsg* getCurMsg();
    smapiMsg* setCurMsg(int newMsgNum);
    smapiMsg* getFirstMsg();
    smapiMsg* getNextMsg();
    smapiMsg* getPrevMsg();
    smapiMsg* getLastMsg();

    enum OPENMODE {NORMAL, CREAT, CRIFNEC};
    enum AREATYPE {SDM, SQUISH, ECHO};

    QList<smapiMsg> msgList;

};

#endif