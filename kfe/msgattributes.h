/***************************************************************************
                          msgattributes.h  -  description                              
                             -------------------                                         
    begin                : Sun Apr 4 1999                                           
    copyright            : (C) 1999 by Michael Espey                         
    email                : tracer@camouflage.hh.uunet.de                                     
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   * 
 *                                                                         *
 ***************************************************************************/


#ifndef MSGATTRIBUTES_H
#define MSGATTRIBUTES_H


/**
  *@author Michael Espey
  */

class msgattributes
{
public: 
  	msgattributes();
	  ~msgattributes();
	
    bool isMsgPrivate();
    bool isMsgLocal();
    bool isMsgCrash();
    bool isMsgHold();
    bool isMsgDirect();
    bool isMsgRead();
    bool isMsgSent();
    bool isMsgScanned();
    bool isMsgFile();
    bool isMsgFrq();
    bool isMsgUrq();
    bool isMsgKill();
    bool isMsgRrq();
    bool isMsgCpt();
    bool isMsgArq();
    bool isMsgFwd();
    bool isMsgOrphan();
    bool isMsgUid();

    void setMsgPrivate(bool newmsgprivate);
    void setMsgLocal(bool newmsglocal);
    void setMsgCrash(bool newmsgcrash);
    void setMsgHold(bool newmsghold);
    void setMsgDirect(bool newmsgdirect);
    void setMsgRead(bool newmsgread);
    void setMsgSent(bool newmsgsent);
    void setMsgScanned(bool newmsgscanned);
    void setMsgFile(bool newmsgfile);
    void setMsgFrq(bool newmsgfrq);
    void setMsgUrq(bool newmsgurq);
    void setMsgKill(bool newmsgkill);
    void setMsgRrq(bool newmsgrrq);
    void setMsgCpt(bool newmsgcpt);
    void setMsgArq(bool newmsgarg);
    void setMsgFwd(bool newmsgfwd);
    void setMsgOrphan(bool newmsgorphan);
    void setMsgUid(bool newmsguid);

private:
    bool msgprivate;
    bool msglocal;
    bool msgcrash;  // msgcrash & msghold means direct
    bool msghold;   //  msgcrash & msghold means direct
    bool msgdirect;
    bool msgread;   // is read
    bool msgsent;   // is tossed
    bool msgscanned;
    bool msgfile;   // attachment
    bool msgfrq;    // file request
    bool msgurq;    // update request
    bool msgkill;   // delete when packing
    bool msgrrq;    // receipt is requested
    bool msgcpt;    // message is a receipt
    bool msgarq;    // audit trail request
    bool msgfwd;    // in transit message
    bool msgorphan; // Destination not in Nodelist
    bool msguid;    // MSGUID used internally
};

#endif





