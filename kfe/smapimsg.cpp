#include "smapimsg.h"


smapiMsg::smapiMsg(HAREA newarea, word mode, dword msgn)
{
    debug("smapiMsg::smapiMsg");
    hmsg = MsgOpenMsg(newarea, mode, msgn);

    if (hmsg != NULL) {
        MsgReadMsg(hmsg, &xmsg, 0, 0, NULL, 0, NULL);
        from = (const char *)xmsg.from;
        to = (const char *)xmsg.to;
        subject = (const char *)xmsg.subj;
    } else {
        printf("error in smapiMsg()%d\n", msgapierr);
    }

    //    if (hmsg == GetCurPos) {
    //        printf("current\n");
    //    }
}



smapiMsg::~smapiMsg()
{
    printf("smapiMsg::~smapiMsg()\n");
    MsgCloseMsg(hmsg);
}


QString smapiMsg::getFrom()
{
    return from;
}


QString smapiMsg::getTo()
{
    return to;
}


QString smapiMsg::getSubject()
{
    return subject;
}


// normalize, borrowed from msged, with slight modifications

void normalize(char *s, int stripSoft)
{
    char *tmp = s;

    while (*s)
    {
        if (stripSoft && ((unsigned char)*s == 0x8d))
        {
            s++;
        }
        else if (*s == 0x0a)
        {
            s++;
        }
        else if (*s == 0x0d)                    {
            s++, *tmp++ = '\n';
        }
        else
        {
            *tmp++ = (char)/*DOROT13*/((int)*s);
            s++;
        }
    }
    *tmp = '\0';
}



QString smapiMsg::getBody()
{
    char* minfo;
    char* bodycontent;

    printf("smapiMsg::getBody()\n");
    bodycontent = (char*) malloc(32768);
    printf("smapiMsg::getBody()\n");

    if (hmsg != NULL) {
        printf("smapiMsg::getBody()\n");
        //        make it faster
        //        dword MsgReadMsg(HMSG hmsg, dword ofs, dword bytes, byte *text, dword cbyt, byte *ctxt);

        MsgReadMsg(hmsg, &xmsg, 0L, 32768, bodycontent, 0, NULL);
        printf("smapiMsg::getBody()\n");

        //        MsgReadMsg(hmsg, &xmsg, 0L, 0L, NULL, 0, NULL);
        // find something nicer, when I have time
        normalize(bodycontent, 0);
        body = (const char *)bodycontent;
    } else {
        printf("Could not open %s", "echo->filename");
    }
    return body;
}
