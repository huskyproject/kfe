/*
 *   khexdit - a little hex editor
 *   Copyright (C) 1996,97  Stephan Kulow
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef _MSGWIDGET_H
#define _MSGWIDGET_H

#include <qpopmenu.h>

#include <kfm.h>
#include <kapp.h>
#include <kurl.h>
#include <klocale.h>
#include <qmlined.h>

#include "f_message.h"



class msgWidget : public QWidget {
    Q_OBJECT
    
public:
    msgWidget(QWidget *parent=0, const char *name=0 );
    ~msgWidget();

    void update(int msgnum);


    QLabel *lfrom;
    QLabel *from;
    QLabel *lto;
    QLabel *to;
    QLabel *lsubject;
    QLabel *subject;
    QMultiLineEdit *body;

public slots:
    void showMsg(f_message* item);

private:
    int winID;
    
protected:
    //void paintEvent(QPaintEvent *pa);
//    void closeEvent ( QCloseEvent *e);
    void initGeometry();
};

#endif
