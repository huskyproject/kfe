#include "f_area.h"

// *************************************************************
// class msgArea

f_area::f_area(char* aname)
{
    name = aname;

    char* areapath;
    areapath = (char*) malloc(200);

    strcpy(areapath, "/var/spool/fido/msgbase/");
    strcat(areapath, aname);
    printf("areapath: %s\n", areapath);
    
    HAREA marea = MsgOpenArea((unsigned char*)areapath, MSGAREA_NORMAL, MSGTYPE_SQUISH | MSGTYPE_ECHO);
    printf("msgapierr:%d\n", msgapierr);
    if (marea) {
        // store the info
        harea = marea;
        msgs = MsgNumMsg(marea);
        curmsg = MsgCurMsg(marea);
        newmsgs = (msgs - curmsg);
        
    } else {
        printf("fehler beim oeffnen: \n");
    }
}


QString f_area::getName()
{
    return name;
}


int f_area::getMsgs()
{
    return msgs;
}


int f_area::getCurMsg()
{
    return curmsg;
}

    
int f_area::getNewMsgs()
{
    return newmsgs;
}


HAREA f_area::getHarea() {
    return harea;
}
