#ifndef _SMAPIMSG_H
#define _SMAPIMSG_H

#include <qstring.h>
#include <stdio.h>

extern "C" {
#include <msgapi.h>
}


class smapiMsg
{
    HMSG hmsg;
    XMSG xmsg;


    QString from;
    QString to;
    QString subject;
    QString body;

public:
    smapiMsg(HAREA newarea, word mode, dword msgn);
    ~smapiMsg();

    killMsg();

    QString getFrom();
    QString getTo();
    QString getSubject();
    QString getBody();

private:
    readMsg();
    writeMsg();
};

#endif