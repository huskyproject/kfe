#include "f_message.h"

// *************************************************************
// class msg

f_message::f_message(f_area* aarea, int ahw)
{
    area = aarea;
    hw = ahw;

    hmsg = MsgOpenMsg(area->getHarea(), MOPEN_RW, hw);

    if (hmsg != NULL) {
        MsgReadMsg(hmsg, &xmsg, 0, 0, NULL, 0, NULL);
        from = (const char *)xmsg.from;
        to = (const char *)xmsg.to;
        subject = (const char *)xmsg.subj;
    } else {
        printf("error in f_message()");
    }
}

    
f_message::~f_message()
{
    ;
//    printf();
//    MsgCloseMsg(hmsg);
}


QString f_message::getFrom()
{
    return from;
}


QString f_message::getTo()
{
    return to;
}


QString f_message::getSubject()
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


QString f_message::getBody()
{
    char* minfo;
    char* bodycontent;

//    bodycontent = (char*) malloc(32768);

    if (hmsg != NULL) {
    
        //        make it faster
        //dword MsgReadMsg(HMSG hmsg, dword ofs, dword bytes,
        // byte *text, dword cbyt, byte *ctxt);
        //        MsgReadMsg(hmsg, &xmsg, 0L, 32768, bodycontent, 0, NULL);
;//        MsgReadMsg(hmsg, &xmsg, 0L, 0L, NULL, 0, NULL);
        // find something nicer, when I have time
//        normalize(bodycontent, 0);
//        body = (const char *)bodycontent;
    } else {
        printf("Could not open %s", "echo->filename");
    }
    return body;
}




