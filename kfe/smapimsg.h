#ifndef _SMAPIMSG_H
#define _SMAPIMSG_H

#include <qstring.h>
#include <qdatetime.h>
#include <stdio.h>

extern "C" {
#include <msgapi.h>
}
#include "address.h"
#include "msgattributes.h"

class smapiMsg
{
		HAREA areaheader;
    HMSG msgheader;
    XMSG extendedmsginfo;

    dword msgnum;
    msgattributes* attr;  // *** hide them later
    address* addr;
    char* body;
    char* kludges;

public:
    smapiMsg(HAREA newarea, dword newmsgnum);
    ~smapiMsg();

    void killMsg();
    int getCurMsg();

    // the XMSG Infos
    QString getFrom();        // char[36]
    QString getTo();          // char[36]
    QString getSubject();     // char[72]
    address getOrigAddr();    // *** make this a class later?
    address getDestAddr();    // netmail only
    msgattributes *getAttr();
    bool isUnread();					// Is the unreadflag set?
    SCOMBO getDateWritten();  // *** dito a class?
    SCOMBO getDateArrived();  // date of tossing
    // utc_ofs        sword     172  The  message  writer's offset  from UTC, in minutes. Currently, this field is not used.
    UMSGID getReplyTo();      // UMSGID, if mail is a reply, else 0
    //UMSGID[9] getReplies();   // UMSGIDs of up to nine reply messages.
    UMSGID getUMSGID();       // The UMSGID of this message. FIELD IS ONLY VALID IF MSGUID BIT IS SET
    // mail body
    QString getBody();

    void setFrom(QString newfrom);        // *** char[36] check length
    void setTo(QString newto);            // *** char[36] check length
    void setSubject(QString newsubject);  // *** char[72] check length
    void setOrigAddr(address* newaddress);
    void setDestAddr(address* newaddress);
    void setAttr(msgattributes *newattr);
    void setRead();
    void setDateWritten(QDateTime);
    //    UMSGID getUMSGID();       // The UMSGID of this message. FIELD IS ONLY VALID IF MSGUID BIT IS SET
    void setKludges(char* newkludges);

    void setBody(QString newbody);
    void writeMsg();
};

#endif


















