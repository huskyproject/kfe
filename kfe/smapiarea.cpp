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
        newmsgs = (msgs - curmsg);
    } else {
        printf("fehler beim oeffnen: \n");
    }
}


smapiArea::~smapiArea()
{
    printf("smapiArea::~smapiArea()\n");
    smapiMsg* msg;
    for (msg = msgList.first(); msg != 0; msg = msgList.next()) {
        printf ("closing Message");
        delete msg;
    }
    MsgCloseArea(harea);
}


void smapiArea::rescanMsgs()
{
    printf("smapiArea::rescanMsgs\n");

    if (harea != NULL) {
        printf("area != NULL\n");

        int i = 1;
        KProgress* prog = new KProgress(i, msgs, i, KProgress::Horizontal);
        prog->resize(400,40);
        prog->show();

        printf("high: %d\n", msgs);

        // Delete old entries in List *** move this to msglistwidget

        smapiMsg* foo;
        QString hdr(256);

        msgList.clear();
        while (i <= msgs) {
            foo = new smapiMsg(harea, MOPEN_READ, (dword)i++);
            msgList.append(foo);
            prog->advance(1);
        }

        prog->hide();
        delete prog;
    } else {
        printf("Could not open %s", "echo->filename");
    }
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


int smapiArea::getCurMsgNum()
{
    return curmsg;
}


int smapiArea::getNewMsgNum()
{
    return newmsgs;
}


smapiMsg* smapiArea::getCurMsg()
{
    return msgList.current();
}


smapiMsg* smapiArea::setCurMsg(int newMsgNum)
{
    return msgList.at(newMsgNum);
    
}


smapiMsg* smapiArea::getFirstMsg()
{
    return msgList.first();
}


smapiMsg* smapiArea::getNextMsg()
{
    return msgList.next();
}


smapiMsg* smapiArea::getPrevMsg()
{
    return msgList.prev();
}


smapiMsg* smapiArea::getLastMsg()
{
    return msgList.last();
}


