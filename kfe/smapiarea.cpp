#include "kprogress.h"
#include "smapiarea.h"


smapiArea::smapiArea(char* newname, char* newpath, word mode, word type)
{
    name = newname;
    path = newpath;
    
    char* foo = (char*)malloc(255); // *** remove this, use QString. somehow
    strcpy(foo, path);
    
    harea = MsgOpenArea((unsigned char*)foo, mode, type);
    
    //    printf("msgapierr:%d\n", msgapierr); // *** make this nice
    
    if (harea) {
        // store the info
        msgs = (int)MsgNumMsg(harea);
        curmsg = (int)MsgCurMsg(harea);
        //        printf("Num: %d Cur: %d\n", msgs, curmsg);
        newmsgs = (msgs - curmsg);
    } else {
        printf("fehler beim oeffnen: \n");
    }
}


smapiArea::~smapiArea()
{
    printf("smapiArea::~smapiArea()\n");
    MsgCloseArea(harea);
}




QString smapiArea::getName()
{
    return QString(name);
}


QString smapiArea::getPath()
{
    return QString(path);
}



int smapiArea::getMsgNum()
{
    return msgs;
}



int smapiArea::getNewMsgNum()
{
    return newmsgs;
}



HAREA smapiArea::getHAREA()
{
    return harea;
}