/*
 *   kfe - a squish base message editor
 *   Copyright (C) 1998  Michael Espey
 *
 */


#include <stdio.h>

#include <ktablistbox.h>
#include <kprogress.h>
#include "msglistwidget.h"


// *************************************************************
// class msgList


msgListWidget::msgListWidget(QWidget *parent)
    : KTabListBox(parent, 0, 6)
{
    setMinimumSize(400, 100);

    setColumn(0, "nr", 40);
    setColumn(1, "from", 170);
    setColumn(2, "to", 170);
    setColumn(3, "subject", 200);
    setColumn(4, "written", 40);
    setColumn(5, "received", 40);

    resize(size());

    connect(this, SIGNAL(selected(int, int)), this, SLOT(msgSelected(int)));

}


msgListWidget::~msgListWidget()
{
;//    delete lb;
}


void msgListWidget::rescanContent(smapiArea* newarea)
{
    printf("msgListWidget::rescanContent\n");

    clear();
    smapiMsg* msg;
    QString hdr(256);
    setAutoUpdate(FALSE);
    int i = 0; // *** check for real msg num instead
    for(msg = newarea->getFirstMsg(); msg != 0; msg = newarea->getNextMsg()) {
        hdr.sprintf("%d\n%s\n%s\n%s", ++i, (const char*)msg->getFrom(), (const char*)msg->getTo(), (const char*)msg->getSubject());
        insertItem(hdr);
        if (msg->getFrom().contains("Michael Espey") > 0) {
            changeItemColor(QColor(0,255,0));
        };
        printf("From %s\n", (const char*)msg->getFrom());

    }
        printf("hier\n");
    setAutoUpdate(TRUE);
    repaint();
}


void msgListWidget::msgSelected(int item)
{
    printf("msgListWidget::msgSelected\n");
    emit newSelection(item);
}


