/***************************************************************************
                          composeview.cpp  -  description                              
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


#include "composeview.h"
#include <qlabel.h>
#include <klined.h>
#include <qcombobox.h>
#include <keditcl.h>
#include <msgapi.h>

composeView::composeView(QWidget *parent,  const char *newfrom, address *newaddress, const char *newsubject)
  : QWidget(parent, "composeView")
{
    resize(300, 300);
    // the from label
    QLabel *lfrom = new QLabel("from:", this);
    lfrom->setAlignment(AlignRight | AlignVCenter);
    lfrom->setGeometry(3, 5, 45, 25);

    // the from edit field, better to use the fromdialog
    from = new KLined(this);
    from->setText("Michael Espey <2:240/5034>");
    from->setGeometry(50, 5, 200, 25);

    // the to label
    QLabel *lto = new QLabel("to:", this);
    lto->setAlignment(AlignRight | AlignVCenter);
    lto->setGeometry(3, 35, 45, 25);

    // the to edit field, see above
    to = new KLined(this);
    to->setText("All");
    to->setGeometry(50, 35, 200, 25);

    // the subject label
    QLabel *lsubject = new QLabel("subject:", this);
    lsubject->setAlignment(AlignRight | AlignVCenter);
    lsubject->setGeometry(3, 65, 45, 25);

    subject = new KLined(this);
    subject->setGeometry(50, 65, this->width(), 25);

    // *** the edit box, make this a colored one later
    // maybe use kwrite?
    edit = new KEdit(kapp, this);
    edit->setGeometry(5, 95, 200, 100);
}



composeView::~composeView()
{
;
}


	
QString composeView::getFrom()
{
    QString fromfield = from->text();
    // check, if fromfield conatains <address>
    if (fromfield.contains('<') != 0) {
        debug("addr included");
        return fromfield.left(fromfield.find('<')).stripWhiteSpace();
    } else {
        debug("no addr");
        return fromfield;
    }
}



NETADDR composeView::getFromAddr()
{
    QString fromfield = from->text();
    // check, if fromfield conatains <address>
    if (fromfield.contains('<') != 0) {
        debug("addr included");
        QString fromaddr = fromfield.right(fromfield.find('<'));
        debug(fromaddr);
        fromfield.left(fromfield.find('<')).stripWhiteSpace();
 //       return 0;
    } else {

        debug("no addr");
//        return 0;
    }
}



QString composeView::getTo()
{
    QString newto;
    newto.sprintf(to->text());
    return newto;
}



QString composeView::getSubject()
{
    return subject->text();
}



QString composeView::getEdit()
{
    QString newedit;
    newedit.sprintf(edit->text());
    return newedit;
}












