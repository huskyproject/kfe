#ifndef _F_AREA_H
#define _F_AREA_H

#include <qstring.h>
extern "C" {
#include <msgapi.h>
}

class f_area
{
    QString name;
    int msgs;
    int curmsg;
    int newmsgs;
    HAREA harea;

public:
    f_area(char* aname);
    QString getName();
    int getMsgs();
    int getCurMsg();
    int getNewMsgs();
    HAREA getHarea();
};

#endif
