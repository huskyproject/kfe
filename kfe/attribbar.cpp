/***************************************************************************
                          attribbar.cpp  -  description                              
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


#include <kapp.h>
#include <kiconloader.h>
#include "attribbar.h"
#include "msgattributes.h"

attribBar::attribBar(QWidget *parent, msgattributes* newattr, bool status = false)
  : KToolBar(parent)
{
    attr = newattr;
    CHECK_PTR(attr);

    KIconLoader iconLoader;

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgprivate, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgPrivate()), status, i18n("Private Message"));
    setToggle(msgprivate);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msglocal, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgLocal()), status, i18n("Local Message"));
    setToggle(msglocal);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgcrash, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgCrash()), status, i18n("CrashMail"));
    setToggle(msgcrash);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msghold, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgHold()), status, i18n("On Hold"));
    setToggle(msghold);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgdirect, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgDirect()), status, i18n("Direct Message"));
    setToggle(msgdirect);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgread, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgRead()), status, i18n("Message Read"));
    setToggle(msgread);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgsent, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgSent()), status, i18n("Message Sent"));
    setToggle(msgsent);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgscanned, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgScanned()), status, i18n("Message Scanned"));
    setToggle(msgscanned);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgfile, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgFile()), status, i18n("File Attachement"));
    setToggle(msgfile);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgfrq, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgFrq()), status, i18n("File Request"));
    setToggle(msgfrq);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgurq, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgUrq()), status, i18n("Update Request"));
    setToggle(msgurq);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgkill, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgKill()), status, i18n("Message Killed"));
    setToggle(msgkill);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgrrq, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgRrq()), status, i18n("Return Recept Request"));
    setToggle(msgrrq);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgcpt, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgCpt()), status, i18n("Recept Return"));
    setToggle(msgcpt);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgarq, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgArq()), status, i18n("Audit Request"));
    setToggle(msgarq);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgfwd, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgFwd()), status, i18n("In Transit Message"));
    setToggle(msgfwd);

    insertButton(iconLoader.loadIcon("filenew.xpm"), msgorphan, SIGNAL(clicked()),
                          this, SLOT(cmToggleItemMsgOrphan()), status, i18n("Orphaned Message"));
    setToggle(msgorphan);

    upDate(attr);
}



attribBar::~attribBar()
{
}



void attribBar::upDate(msgattributes* newattr)
{
    attr = newattr;
    setButton(msgprivate, attr->isMsgPrivate());
    setButton(msglocal, attr->isMsgLocal());
    setButton(msgcrash, attr->isMsgCrash());
    setButton(msghold, attr->isMsgHold());
    setButton(msgdirect, attr->isMsgDirect());
    setButton(msgread, attr->isMsgRead());
    setButton(msgsent, attr->isMsgSent());
    setButton(msgscanned, attr->isMsgScanned());
    setButton(msgprivate, attr->isMsgPrivate());
    setButton(msgfrq, attr->isMsgFrq());
    setButton(msgurq, attr->isMsgUrq());
    setButton(msgkill, attr->isMsgKill());
    setButton(msgprivate, attr->isMsgPrivate());
    setButton(msgcpt, attr->isMsgCpt());
    setButton(msgarq, attr->isMsgArq());
    setButton(msgfwd, attr->isMsgFwd());
    setButton(msgorphan, attr->isMsgOrphan());
}



void attribBar::enableBar()
{
    setItemEnabled(msgprivate, true);
    setItemEnabled(msglocal, true);
    setItemEnabled(msgcrash, true);
    setItemEnabled(msghold, true);
    setItemEnabled(msgdirect, true);
    setItemEnabled(msgread, true);
    setItemEnabled(msgsent, true);
    setItemEnabled(msgscanned, true);
    setItemEnabled(msgprivate, true);
    setItemEnabled(msgfrq, true);
    setItemEnabled(msgurq, true);
    setItemEnabled(msgkill, true);
    setItemEnabled(msgprivate, true);
    setItemEnabled(msgcpt, true);
    setItemEnabled(msgarq, true);
    setItemEnabled(msgfwd, true);
    setItemEnabled(msgorphan, true);
}
	


void attribBar::disableBar()
{
    setItemEnabled(msgprivate, false);
    setItemEnabled(msglocal, false);
    setItemEnabled(msgcrash, false);
    setItemEnabled(msghold, false);
    setItemEnabled(msgdirect, false);
    setItemEnabled(msgread, false);
    setItemEnabled(msgsent, false);
    setItemEnabled(msgscanned, false);
    setItemEnabled(msgprivate, false);
    setItemEnabled(msgfrq, false);
    setItemEnabled(msgurq, false);
    setItemEnabled(msgkill, false);
    setItemEnabled(msgprivate, false);
    setItemEnabled(msgcpt, false);
    setItemEnabled(msgarq, false);
    setItemEnabled(msgfwd, false);
    setItemEnabled(msgorphan, false);
}



void attribBar::cmSetItemMsgPrivate(bool status)
{
		attr->setMsgPrivate(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgLocal(bool status)
{
		attr->setMsgLocal(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgCrash(bool status)
{
		attr->setMsgCrash(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgHold(bool status)
{
		attr->setMsgHold(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgDirect(bool status)
{
		attr->setMsgDirect(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgRead(bool status)
{
		attr->setMsgRead(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgSent(bool status)
{
		attr->setMsgSent(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgScanned(bool status)
{
		attr->setMsgScanned(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgFile(bool status)
{
		attr->setMsgFile(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgFrq(bool status)
{
		attr->setMsgFrq(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgUrq(bool status)
{
		attr->setMsgUrq(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgKill(bool status)
{
		attr->setMsgKill(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgRrq(bool status)
{
		attr->setMsgRrq(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgCpt(bool status)
{
		attr->setMsgCpt(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgArq(bool status)
{
		attr->setMsgArq(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgFwd(bool status)
{
		attr->setMsgFwd(status);
		upDate(attr);
}



void attribBar::cmSetItemMsgOrphan(bool status)
{
		attr->setMsgOrphan(status);
		upDate(attr);
}



void attribBar::cmToggleItemMsgPrivate()
{
		attr->setMsgPrivate(! attr->isMsgPrivate());
		upDate(attr);
}



void attribBar::cmToggleItemMsgLocal()
{
		attr->setMsgLocal(! attr->isMsgLocal());
		upDate(attr);
}



void attribBar::cmToggleItemMsgCrash()
{
		attr->setMsgCrash(! attr->isMsgCrash());
		upDate(attr);
}



void attribBar::cmToggleItemMsgHold()
{
		attr->setMsgHold(! attr->isMsgHold());
		upDate(attr);
}



void attribBar::cmToggleItemMsgDirect()
{
		attr->setMsgDirect(! attr->isMsgDirect());
		upDate(attr);
}



void attribBar::cmToggleItemMsgRead()
{
		attr->setMsgRead(! attr->isMsgRead());
		upDate(attr);
}



void attribBar::cmToggleItemMsgSent()
{
		attr->setMsgSent(! attr->isMsgSent());
		upDate(attr);
}



void attribBar::cmToggleItemMsgScanned()
{
		attr->setMsgScanned(! attr->isMsgScanned());
		upDate(attr);
}



void attribBar::cmToggleItemMsgFile()
{
		attr->setMsgFile(! attr->isMsgFile());
		upDate(attr);
}



void attribBar::cmToggleItemMsgFrq()
{
		attr->setMsgFrq(! attr->isMsgFrq());
		upDate(attr);
}



void attribBar::cmToggleItemMsgUrq()
{
		attr->setMsgUrq(! attr->isMsgUrq());
		upDate(attr);
}



void attribBar::cmToggleItemMsgKill()
{
		attr->setMsgKill(! attr->isMsgKill());
		upDate(attr);
}



void attribBar::cmToggleItemMsgRrq()
{
		attr->setMsgRrq(! attr->isMsgRrq());
		upDate(attr);
}



void attribBar::cmToggleItemMsgCpt()
{
		attr->setMsgCpt(! attr->isMsgCpt());
		upDate(attr);
}



void attribBar::cmToggleItemMsgArq()
{
		attr->setMsgArq(! attr->isMsgArq());
		upDate(attr);
}



void attribBar::cmToggleItemMsgFwd()
{
		attr->setMsgFwd(! attr->isMsgFwd());
		upDate(attr);
}



void attribBar::cmToggleItemMsgOrphan()
{
		attr->setMsgOrphan(! attr->isMsgOrphan());
		upDate(attr);
}






