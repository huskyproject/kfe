/***************************************************************************
                          attribbar.h  -  description                              
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


#ifndef ATTRIBBAR_H
#define ATTRIBBAR_H

#include <ktoolbar.h>
#include <kbutton.h>
#include "msgattributes.h"


#define msgprivate  0
#define msglocal    1
#define msgcrash    2   // msgcrash & msghold means direct
#define msghold     3   //  msgcrash & msghold means direct
#define msgdirect   4
#define msgread     5   // is read
#define msgsent     6   // is tossed
#define msgscanned  7
#define msgfile     8   // attachment
#define msgfrq      9   // file request
#define msgurq      10  // update request
#define msgkill     11  // delete when packing
#define msgrrq      12  // receipt is requested
#define msgcpt      13  // message is a receipt
#define msgarq      14  // audit trail request
#define msgfwd      15  // in transit message
#define msgorphan   16  // Destination not in Nodelist
// MSGUID used internally


class attribBar : public KToolBar
{
  Q_OBJECT

public:
  	attribBar(QWidget *parent, msgattributes* newattr, bool status = false);
	  ~attribBar();
	  void upDate(msgattributes* newattr);
	  void enableBar();
	  void disableBar();
	
public slots:
    void cmSetItemMsgPrivate(bool status);
    void cmSetItemMsgLocal(bool status);
    void cmSetItemMsgCrash(bool status);
    void cmSetItemMsgHold(bool status);
    void cmSetItemMsgDirect(bool status);
    void cmSetItemMsgRead(bool status);
    void cmSetItemMsgSent(bool status);
    void cmSetItemMsgScanned(bool status);
    void cmSetItemMsgFile(bool status);
    void cmSetItemMsgFrq(bool status);
    void cmSetItemMsgUrq(bool status);
    void cmSetItemMsgKill(bool status);
		void cmSetItemMsgRrq(bool status);
    void cmSetItemMsgCpt(bool status);
    void cmSetItemMsgArq(bool status);
    void cmSetItemMsgFwd(bool status);
    void cmSetItemMsgOrphan(bool status);
		
    void cmToggleItemMsgPrivate();
    void cmToggleItemMsgLocal();
    void cmToggleItemMsgCrash();
    void cmToggleItemMsgHold();
    void cmToggleItemMsgDirect();
    void cmToggleItemMsgRead();
    void cmToggleItemMsgSent();
    void cmToggleItemMsgScanned();
    void cmToggleItemMsgFile();
    void cmToggleItemMsgFrq();
    void cmToggleItemMsgUrq();
    void cmToggleItemMsgKill();
    void cmToggleItemMsgRrq();
    void cmToggleItemMsgCpt();
    void cmToggleItemMsgArq();
    void cmToggleItemMsgFwd();
    void cmToggleItemMsgOrphan();

private:
    msgattributes* attr;	
};

#endif
















