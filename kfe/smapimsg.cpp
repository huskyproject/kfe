#include "smapimsg.h"


smapiMsg::smapiMsg(HAREA newarea, dword newmsgnum)
{
		debug("smapiMsg::smapiMsg");
		areaheader = newarea;
		msgnum = newmsgnum;
    if (msgnum != 0) {
    		// not a new msg
		 		msgheader = MsgOpenMsg(areaheader, MOPEN_READ, msgnum);
		    if (msgheader != 0) {
		  			MsgReadMsg(msgheader, &extendedmsginfo, 0, 0, NULL, 0, NULL);
				    addr = new address();
		
		        // parse the attributes
				    attr = new msgattributes();
		        attr->setMsgPrivate((extendedmsginfo.attr & MSGPRIVATE) == MSGPRIVATE);
		        attr->setMsgLocal((extendedmsginfo.attr & MSGLOCAL) == MSGLOCAL);
    		    attr->setMsgCrash((extendedmsginfo.attr & MSGCRASH) == MSGCRASH);
		        attr->setMsgHold((extendedmsginfo.attr & MSGHOLD) == MSGHOLD);
    		    attr->setMsgDirect((extendedmsginfo.attr & MSGCRASH & MSGHOLD) == MSGCRASH & MSGHOLD);
		        attr->setMsgRead((extendedmsginfo.attr & MSGREAD) == MSGREAD);
    		    attr->setMsgSent((extendedmsginfo.attr & MSGSENT) == MSGSENT);
		        attr->setMsgScanned((extendedmsginfo.attr & MSGSCANNED) == MSGSCANNED);
    		    attr->setMsgFile((extendedmsginfo.attr & MSGFILE) == MSGFILE);
		        attr->setMsgFrq((extendedmsginfo.attr & MSGFRQ) == MSGFRQ);
		        attr->setMsgUrq((extendedmsginfo.attr & MSGURQ) == MSGURQ);
		        attr->setMsgKill((extendedmsginfo.attr & MSGKILL) == MSGKILL);
    		    attr->setMsgRrq((extendedmsginfo.attr & MSGRRQ) == MSGRRQ);
        		attr->setMsgCpt((extendedmsginfo.attr & MSGCPT) == MSGCPT);
		        attr->setMsgArq((extendedmsginfo.attr & MSGARQ) == MSGARQ);
    		    attr->setMsgFwd((extendedmsginfo.attr & MSGFWD) == MSGFWD);
        		attr->setMsgOrphan((extendedmsginfo.attr & MSGORPHAN) == MSGORPHAN);
		        // attr->setMsgUid((xmsg.attr & MSGUID) == MSGUID);
				    MsgCloseMsg(msgheader);
		    } else {
		    		fatal("smapiMsg::smapiMsg(HAREA newarea, dword newmsgnum)\nerror opening a msg. ErrorNr: %d", msgapierr);
		    }
		} else {
				// a new message
				debug("new msg - num: %d", msgnum);
		 		msgheader = MsgOpenMsg(newarea, MOPEN_CREATE, msgnum);
				debug("new msg - num: %d", msgnum);
				// *** make it appear in the msglist
		    attr = new msgattributes();
		    /// *** initialize with defaults for area
		    addr = new address();
		    MsgCloseMsg(msgheader);
		}
}



smapiMsg::~smapiMsg()
{
    delete attr;
    delete addr;
}



int smapiMsg::getCurMsg()
{
    return msgnum;
}



QString smapiMsg::getFrom()
{
    QString from;
    from.sprintf((char *)extendedmsginfo.from);
    return from;
}


QString smapiMsg::getTo()
{
    QString to;
    to.sprintf((char *)extendedmsginfo.to);
    return to;
}


QString smapiMsg::getSubject()
{
    QString subject;
    subject.sprintf((char *)extendedmsginfo.subj);
    return subject;
}



msgattributes *smapiMsg::getAttr()
{
    return attr;
}



bool smapiMsg::isUnread()
{
		return (! attr->isMsgRead());
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
    char *bodycontent;
    char *ctrlinfo;

    char *pid;
    char *tid;
    char *charset;

    debug("smapiMsg::getBody()");

    msgheader = MsgOpenMsg(areaheader, MOPEN_READ, msgnum);
    if (msgheader != 0) {
		    bodycontent = new char[MsgGetTextLen(msgheader)];
    		ctrlinfo = new char[MsgGetCtrlLen(msgheader)];
    		
        debug("hmsg != null");
        MsgReadMsg(msgheader, 0L, 0L, MsgGetTextLen(msgheader), bodycontent, MsgGetCtrlLen(msgheader), ctrlinfo);

        // parse the control info
        debug("PID: %s",  GetCtrlToken(ctrlinfo, (byte *) "PID"));
        // *** store them!

        // find something nicer, when I have time
        debug("vor normalize");
        normalize(bodycontent, 0);
        return (const char *)bodycontent;
    } else {
        fatal("Could not open %s", "echo->filename");
        return 0;
    }
}



void smapiMsg::setAttr(msgattributes *newattr)
{
    attr = newattr;

    // *** make attr.toxmsgAttr
    extendedmsginfo.attr = 0;

    if (attr->isMsgPrivate()) extendedmsginfo.attr = extendedmsginfo.attr | MSGPRIVATE;
    if (attr->isMsgLocal()) extendedmsginfo.attr = extendedmsginfo.attr | MSGLOCAL;
    if (attr->isMsgCrash()) extendedmsginfo.attr = extendedmsginfo.attr | MSGCRASH;
    if (attr->isMsgHold()) extendedmsginfo.attr = extendedmsginfo.attr | MSGHOLD;
    if (attr->isMsgRead()) extendedmsginfo.attr = extendedmsginfo.attr | MSGREAD;
    if (attr->isMsgSent()) extendedmsginfo.attr = extendedmsginfo.attr | MSGSENT;
    if (attr->isMsgScanned()) extendedmsginfo.attr = extendedmsginfo.attr | MSGSCANNED;
    if (attr->isMsgFile()) extendedmsginfo.attr = extendedmsginfo.attr | MSGFILE;
    if (attr->isMsgFrq()) extendedmsginfo.attr = extendedmsginfo.attr | MSGFRQ;
    if (attr->isMsgUrq()) extendedmsginfo.attr = extendedmsginfo.attr | MSGURQ;
    if (attr->isMsgKill()) extendedmsginfo.attr = extendedmsginfo.attr | MSGKILL;
    if (attr->isMsgRrq()) extendedmsginfo.attr = extendedmsginfo.attr | MSGRRQ;
    if (attr->isMsgCpt()) extendedmsginfo.attr = extendedmsginfo.attr | MSGCPT;
    if (attr->isMsgArq()) extendedmsginfo.attr = extendedmsginfo.attr | MSGARQ;
    if (attr->isMsgFwd()) extendedmsginfo.attr = extendedmsginfo.attr | MSGFWD;
    if (attr->isMsgOrphan()) extendedmsginfo.attr = extendedmsginfo.attr | MSGORPHAN;
}



void smapiMsg::setRead()
{
		attr->setMsgRead(true);
}



void smapiMsg::setKludges(char* newkludges)
{
    debug("void smapiMsg::setKludges(char* newkludges)");
//    kludges = new  char[sizeof(newkludges)];
    char* kludges = (char*) malloc(255);
    strcpy(kludges, newkludges);
    debug("kludges: %s", kludges);
    debug("size of kludges: %d", sizeof(kludges));
}



void smapiMsg::setFrom(QString newfrom)
{
    strcpy((char *)extendedmsginfo.from, newfrom);
}



void smapiMsg::setTo(QString newto)
{
    strcpy((char *)extendedmsginfo.to, newto);
}



void smapiMsg::setSubject(QString newsubject)
{
    strcpy((char *)extendedmsginfo.subj, newsubject);
}



void smapiMsg::setOrigAddr(address* newaddress)
{
    // *** create address::address2NETADDR
    addr = newaddress;
    extendedmsginfo.orig.zone = newaddress->getZone();
    extendedmsginfo.orig.net = newaddress->getNet();
    extendedmsginfo.orig.node = newaddress->getNode();
    extendedmsginfo.orig.point = newaddress->getPoint();
}



void smapiMsg::setDateWritten(QDateTime newdatetime)
{
    debug("smapiMsg::setDateWritten(QDateTime)");
    SCOMBO newdt;
    newdt.msg_st.date.yr = newdatetime.date().year()-1980; // squish starts 1980
    newdt.msg_st.date.mo = newdatetime.date().month();
    newdt.msg_st.date.da = newdatetime.date().day();
    newdt.msg_st.time.hh = newdatetime.time().hour();
    newdt.msg_st.time.mm = newdatetime.time().minute();
    newdt.msg_st.time.ss = (int)newdatetime.time().second()/2;   // squish is unsharp, only 2 second steps

    extendedmsginfo.date_written = newdt.msg_st;
}



void smapiMsg::setBody(QString newbody)
{
    body = new char[sizeof("newbody")];
    sprintf(body, "newbody");
    debug("body:%s", body);
    debug("size of body: %d", strlen(body));
}



void smapiMsg::writeMsg()
{
    debug("smapiMsg::writeMsg()");

    /* sword MsgWriteMsg(HMSG hmsg, word fAppend, PXMSG msg,
                         byte *text, dword textlen, dword totlen,
                         dword clen, byte *ctxt);
    */
    // the kludges
    char* tmp = (char*) calloc(128, sizeof(char));
    sprintf(tmp, "\1PID: %s %s\1MSGID: %s",
           "kfe", "0.1.0", addr->toMsgId);


    MsgWriteMsg(msgheader, 0, &extendedmsginfo,
                (byte*) body, (dword) strlen(body), (unsigned char*) strlen(body),
                (dword) strlen(tmp), (unsigned char*) tmp);
}















































