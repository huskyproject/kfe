#ifndef _SMAPIAREA_H
#define _SMAPIAREA_H

#include <stdio.h>
#include <qstring.h>
#include <qlist.h>

extern "C" {
#include <smapi/msgapi.h>
}
#include "address.h"
#include "smapimsg.h"


class smapiArea
{
public:
    smapiArea(char* newname, char* newpath, word mode, word type, address* newareaaddr);

    ~smapiArea();

    QString getName();
    QString getPath();
    UMSGID msgNum2UmsgId(int num);
    int umsgId2MsgNum(UMSGID umsgid);
    int getCurMsgNum();
    int getCurUmsgId();
    int getLastRead();
    void setCurUmsgId(UMSGID newumsgid);
    int getAreaSize();
    address *getAddress();
    HAREA getHAREA();
    void setLastRead(UMSGID newlastread);

    enum OPENMODE {NORMAL, CREAT, CRIFNEC};
    enum AREATYPE {SDM, SQUISH, ECHO};

private:
    HAREA harea;
    UMSGID lastread;

    QString name;
    QString path;
    
    address* areaaddress;
};

#endif

