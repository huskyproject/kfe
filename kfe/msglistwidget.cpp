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


msgListWidget::msgListWidget(QWidget *parent, Ksmapi* newSmapi = 0)
    : KTabListBox(parent, 0, 6)
{
    smapi = newSmapi;

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


void msgListWidget::rescanContent()
{
    printf("msgListWidget::rescanContent\n");

    clear();
    QString hdr(256);
    setAutoUpdate(FALSE);
    smapiMsg* msg;
    printf("msgListWidget::rescanContent\n");
    
    int i = 0; // *** check for real msg num instead
    debug("vor schleife");
    // *** check for null pointer here, may become a bug
    if (smapi->getCurArea()->getMsgNum() > 0) {
        for(msg = smapi->getFirstMsg(); msg != 0; msg = smapi->getNextMsg()) {
            debug("in schleife");
            hdr.sprintf("%d\n%s\n%s\n%s", ++i, (const char*)msg->getFrom(), (const char*)msg->getTo(), (const char*)msg->getSubject());
            insertItem(hdr);
            if (msg->getTo().contains("Michael Espey") > 0) {
                changeItemColor(QColor(0,0,255));
            }
            //else
            if (msg->getFrom().contains("Michael Espey") > 0) {
                changeItemColor(QColor(0,255,0));
            }
        }
    }
    setAutoUpdate(TRUE);
    repaint();
}


void msgListWidget::msgSelected(int item)
{
    printf("msgListWidget::msgSelected\n");
    emit newSelection(item);
}
