/***************************************************************************
                          composeview.h  -  description                              
                             -------------------                                         
    begin                : Sun Mar 21 1999                                           
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


#ifndef COMPOSEVIEW_H
#define COMPOSEVIEW_H

#include <qwidget.h>
#include <klined.h>
#include <keditcl.h>
#include <smapi/msgapi.h>
#include "address.h"

/**
  *@author Michael Espey
  */

class composeView : public QWidget {
   Q_OBJECT

public: 
  	composeView(QWidget *parent, const char *newfrom, address *newaddress, const char *newsubject);
	  ~composeView();
	  QString getFrom();
    NETADDR getFromAddr();
	  QString getTo();
	  QString getSubject();
	  QString getEdit();
	
    KLined *from, *to, *subject;
    KEdit *edit;
};

#endif












