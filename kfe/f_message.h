#ifndef _F_MESSAGE_H
#define _F_MESSAGE_H


#include <qstring.h>
#include <stdio.h>

#include "f_area.h"

class f_message
{
    HMSG hmsg;
    XMSG xmsg;
    f_area* area;
    int hw;

    QString from;
    QString to;
    QString subject;
    QString body;

    // *** make class complete
public:
    f_message(f_area* aarea, int ahw);
    ~f_message();

    QString getFrom();
    QString getTo();
    QString getSubject();
    QString getBody();
};

#endif