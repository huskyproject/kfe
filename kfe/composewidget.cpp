/***************************************************************************
                          composewidget.cpp  -  description                              
                             -------------------                                         
    begin                : Sat Mar 20 1999                                           
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
#include "composewidget.h"
#include "attribbar.h"

composeWidget::composeWidget(Ksmapi* newSmapi, const char *newto, address* newaddress, const char *newsubject)
{
    debug("composeWidget::composeWidget()");
    smapi = newSmapi;

    setupMenuBar();
    setupToolBar();
    // setupStatusBar();

    attr = new msgattributes();

    // *** get Areainfo for default
    attr->setMsgLocal(true);
    attribBar* ab = new attribBar(this, attr, true);
    addToolBar(ab);
    ab->setBarPos(KToolBar::Top);

    composeview = new composeView(this, newto, newaddress, newsubject);
    setView(composeview);
}



composeWidget::~composeWidget()
{
}



void composeWidget::setupMenuBar()
{
    // The Keyboard Accellerator, make this a seperate Method later
    accel = new QAccel(this);

    menubar = new KMenuBar(this);
    setMenu(menubar);

    // File Menu
    mFile = new QPopupMenu();

    ID_FILE_SAVEMSG = mFile->insertItem(i18n("&Save Message"));
    mFile->connectItem(ID_FILE_SAVEMSG, this, SLOT(cmFileSaveMsg()));

    mFile->insertSeparator();

    ID_FILE_NEWMSG = mFile->insertItem(i18n("&New Message..."));
    mFile->connectItem(ID_FILE_NEWMSG, this, SLOT(cmFileNewMsg()));

    ID_FILE_NEWREADER = mFile->insertItem(i18n("&New Reader..."));
    mFile->connectItem(ID_FILE_NEWREADER, kapp, SLOT(cmFileNewReader()));

    mFile->insertSeparator();

    ID_FILE_CLOSE = mFile->insertItem(i18n("&Close"));
    mFile->connectItem(ID_FILE_CLOSE, this, SLOT(cmFileClose()));

    menubar->insertItem(i18n("&File"), mFile);

    // Edit Menu
//    mArea = new QPopupMenu();

    // Help Menu
    mHelp = kapp->getHelpMenu(true,
                              i18n("kfe - kde fido editor\n\n"
                                   "(c) 1998 Michael Espey\n"
                                   "a KDE Squish Editor"));
    menubar->insertItem(i18n("&Help"), mHelp);
}


void composeWidget::setupStatusBar()
{
}



void composeWidget::setupToolBar()
{
    KIconLoader iconLoader;
    toolbar = new KToolBar(this);

    addToolBar(toolbar);

    toolbar->insertButton(iconLoader.loadIcon("filenew.xpm"), 1, SIGNAL(clicked()),
                          this, SLOT(cmFileNewMsg()), TRUE, i18n("New Message"));
    toolbar->insertButton(iconLoader.loadIcon("start.xpm"), 1, SIGNAL(clicked()),
                          this, SLOT(cmMessageFirst()), TRUE, i18n("First Message"));
    toolbar->insertButton(iconLoader.loadIcon("prev.xpm"), 2, SIGNAL(clicked()),
                          this, SLOT(cmMessagePrev()), TRUE, i18n("Previous Message"));
    toolbar->insertButton(iconLoader.loadIcon("next.xpm"), 3, SIGNAL(clicked()),
                          this, SLOT(cmMessageNext()), TRUE, i18n("Next Message"));
    toolbar->insertButton(iconLoader.loadIcon("finish.xpm"), 4, SIGNAL(clicked()),
                          this, SLOT(cmMessageLast()), TRUE, i18n("Last Message"));
    toolbar->insertSeparator();
    toolbar->insertButton(iconLoader.loadIcon("help.xpm"),5,SIGNAL(pressed()),
                          kapp, SLOT(appHelpActivated()), TRUE, i18n("Help Contents"));

    toolbar->setBarPos(KToolBar::Top);
}



void composeWidget::cmFileSaveMsg()
{
    debug("composeWiget::cmFileSaveMsg()");
    smapiMsg* newmsg;
    if (smapi->getCurArea() != 0) {
        debug("curArea not null");
        if (smapi->getCurArea()->getHAREA() != 0) {
            debug("vor new");
            // apend the new mail
            newmsg = new smapiMsg(smapi->getCurArea()->getHAREA(), 0);
            // set the fields
            debug("vor set kludges");
//            newmsg->setKludges("\1PIDxx:xxkfe 0.1.0\r\1MSGID:2:240/5034@fidonet 08/15\r");
            debug("nach set kludges");
            newmsg->setAttr(attr);
            newmsg->setFrom(composeview->getFrom());
            newmsg->setOrigAddr(smapi->getCurArea()->getAddress());
            // init timestamp
            QDateTime timestamp = QDateTime::currentDateTime();
            newmsg->setDateWritten(timestamp);
            newmsg->setTo(composeview->getTo());
            newmsg->setSubject(composeview->getSubject());
            newmsg->setBody(composeview->getEdit());
            newmsg->writeMsg();
        }
    }
}



void composeWidget::cmFileNewMsg()
{
    composeWidget* composewidget = new composeWidget(smapi);
    composewidget->show();
}




























































