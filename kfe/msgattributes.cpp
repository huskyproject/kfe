/***************************************************************************
                          msgattributes.cpp  -  description                              
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


#include "msgattributes.h"

msgattributes::msgattributes()
{
    msgprivate = false;
    msglocal = false;
    msgcrash = false;
    msghold = false;
    msgdirect = false;
    msgread = false;
    msgsent = false;
    msgscanned = false;
    msgfile = false;
    msgfrq = false;
    msgurq = false;
    msgkill = false;
    msgrrq = false;
    msgcpt = false;
    msgarq = false;
    msgfwd = false;
    msgorphan = false;
    msguid = false;
}



msgattributes::~msgattributes(){
}



bool msgattributes::isMsgPrivate()
{
    return msgprivate;
}



bool msgattributes::isMsgLocal()
{
    return msglocal;
}



bool msgattributes::isMsgCrash()
{
    return msgcrash;
}




bool msgattributes::isMsgHold()
{
    return msghold;
}



bool msgattributes::isMsgDirect()
{
    return msgdirect;
}



bool msgattributes::isMsgRead()
{
    return msgread;
}



bool msgattributes::isMsgSent()
{
    return msgsent;
}



bool msgattributes::isMsgScanned()
{
    return msgscanned;
}




bool msgattributes::isMsgFile()
{
    return msgfile;
}



bool msgattributes::isMsgFrq()
{
    return msgfrq;
}



bool msgattributes::isMsgUrq()
{
    return msgurq;
}



bool msgattributes::isMsgKill()
{
    return msgkill;
}



bool msgattributes::isMsgRrq()
{
    return msgrrq;
}



bool msgattributes::isMsgCpt()
{
    return msgcpt;
}



bool msgattributes::isMsgArq()
{
    return msgarq;
}



bool msgattributes::isMsgFwd()
{
    return msgfwd;
}



bool msgattributes::isMsgOrphan()
{
    return msgorphan;
}



bool msgattributes::isMsgUid()
{
    return msguid;
}



void msgattributes::setMsgPrivate(bool newmsgprivate)
{
    msgprivate = newmsgprivate;
}



void msgattributes::setMsgLocal(bool newmsglocal)
{
    msglocal =newmsglocal;
}



void msgattributes::setMsgCrash(bool newmsgcrash)
{
    msgcrash = newmsgcrash;
}



void msgattributes::setMsgHold(bool newmsghold)
{
    msghold = newmsghold;
}



void msgattributes::setMsgDirect(bool newmsgdirect)
{
    msgdirect = newmsgdirect;
}



void msgattributes::setMsgRead(bool newmsgread)
{
    msgread = newmsgread;
}



void msgattributes::setMsgSent(bool newmsgsent)
{
    msgsent = newmsgsent;
}



void msgattributes::setMsgScanned(bool newmsgscanned)
{
    msgscanned = newmsgscanned;
}



void msgattributes::setMsgFile(bool newmsgfile)
{
    msgfile = newmsgfile;
}



void msgattributes::setMsgFrq(bool newmsgfrq)
{
    msgfrq = newmsgfrq;
}



void msgattributes::setMsgUrq(bool newmsgurq)
{
    msgurq = newmsgurq;
}



void msgattributes::setMsgKill(bool newmsgkill)
{
    msgkill = newmsgkill;
}



void msgattributes::setMsgRrq(bool newmsgrrq)
{
    msgrrq = newmsgrrq;
}



void msgattributes::setMsgCpt(bool newmsgcpt)
{
    msgcpt = newmsgcpt;
}



void msgattributes::setMsgArq(bool newmsgarq)
{
    msgarq = newmsgarq;
}



void msgattributes::setMsgFwd(bool newmsgfwd)
{
    msgfwd = newmsgfwd;
}



void msgattributes::setMsgOrphan(bool newmsgorphan)
{
    msgorphan = newmsgorphan;
}



void msgattributes::setMsgUid(bool newmsguid)
{
    msguid = newmsguid;
}










