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


#include <stdio.h>

#include "msglistwidget.h"
#include "arealistwidget.h"
#include "ktablistbox.h"
#include "kprogress.h"


// *************************************************************
// class msgList


msgListWidget::msgListWidget(QWidget *parent)
    : KTabListBox(parent, 0, 6)
{
    setMinimumSize(400, 100);

    setColumn(0, "nr", 40);
    setColumn(1, "from", 170);
    setColumn(2, "to", 170);
    setColumn(3, "topic", 200);
    setColumn(4, "written", 40);
    setColumn(5, "received", 40);

    resize(size());
}


msgListWidget::~msgListWidget()
{
;//    delete lb;
}


void msgListWidget::rescan(f_area *area)
{
    printf("start rescan\n");
    
    if (area) {
        hide();
        printf("area != NULL\n");
        int i = 1;
        int highestMsg  = area->getMsgs();

        KProgress* prog = new KProgress(i, highestMsg, i, KProgress::Horizontal);

        prog->resize(400,40);
        prog->show();

        printf("high: %d", highestMsg);
        clear();
        f_message* foo;
        QString hdr(256);
        while (i <= highestMsg) {
            foo = new f_message(area, i++);
//            msglist.append(foo);
//            hdr.sprintf("%d\n%s\n%s\n%s", i, (const char*)foo->getFrom(), (const char*)foo->getTo(), (const char*)foo->getSubject());
//            insertItem(hdr);
            prog->advance(1);
        }
        prog->hide();
        delete prog;
        show();
    } else {
        printf("Could not open %s", "echo->filename");
    }
}


f_message* msgListWidget::getNext()
{
    return msglist.next();
}


f_message* msgListWidget::getPrev()
{
    return msglist.prev();
}


//    f_message* sel = msglist.at(item);
//    emit newSelection(sel);

