/***************************************************************************
                          composewidget.h  -  description                              
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


#ifndef COMPOSEWIDGET_H
#define COMPOSEWIDGET_H

#include <ktmainwindow.h>
#include <qaccel.h>
#include <qpopmenu.h>
#include <kmenubar.h>
#include <kiconloader.h>
#include "composeview.h"
#include "ksmapi.h"
#include "smapimsg.h"
#include "msgattributes.h"

/**
  *@author Michael Espey
  */

class composeWidget : public KTMainWindow  {
  Q_OBJECT

public: 
        composeWidget(Ksmapi* newSmapi, const char *newfrom = 0, address* newaddress = 0, const char *newsubject = 0);       
	  ~composeWidget();
	
private:
    void setupMenuBar();
    void setupStatusBar();
    void setupToolBar();

private slots:
    void cmFileSaveMsg();
    void cmFileNewMsg();

private:
    Ksmapi *smapi;

    QAccel *accel;
    KMenuBar *menubar;
    KToolBar *toolbar;
    // statusbar

    msgattributes* attr;
    composeView *composeview;

    QPopupMenu *mFile, *mEdit, *mHelp;

    int ID_FILE_SAVEMSG, ID_FILE_NEWMSG, ID_FILE_NEWREADER, ID_FILE_CLOSE;
};

#endif

























