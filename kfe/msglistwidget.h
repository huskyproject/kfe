/*
 *   kfe - a squish base message editor
 *   Copyright (C) 1998  Michael Espey
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

#ifndef _MSGLISTWIDGET_H
#define _MSGLISTWIDGET_H

#include <ktablistbox.h>
#include <qstring.h>
#include "f_area.h"
#include "f_message.h"

class msgListWidget : public KTabListBox
{
    Q_OBJECT

public:
    msgListWidget(QWidget* parent=0);
    ~msgListWidget();
    
    void rescan(f_area* aarea);
    f_message* getNext();
    f_message* getPrev();

signals:
    void newSelection(f_message *);

private slots:
    void msgSelected(int item);
    
protected:
    f_area* area;
    QList<f_message> msglist;
};

#endif
