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
    : KTabListBox(parent, 0, 7)
{
    smapi = newSmapi;

    setMinimumSize(400, 100);
    setColumn(0, 0, 20);
    setColumn(1, "nr", 40);
    setColumn(2, "from", 170);
    setColumn(3, "to", 170);
    setColumn(4, "subject", 200);
    setColumn(5, "written", 40);
    setColumn(6, "received", 40);
    resize(size());
}



msgListWidget::~msgListWidget()
{
;//    delete lb;
}



void msgListWidget::rescan()
{
    QString hdr(256);

    clear();
    setAutoUpdate(FALSE);
    smapiMsg* msg;

    smapi->rescanMsgs();
    int i = 0; // *** check for real msg num instead
    // *** check for null pointer here, may become a bug
    if (smapi->getCurArea() !=  0) {
    		debug("beim scannen der msgs");
    		debug("area: %s", (const char*)smapi->getCurArea()->getName());
        for(msg = smapi->getFirstMsg(); msg != 0; msg = smapi->getNextMsg()) {
            debug("in for beim scannen");
        		if (msg->isUnread()) {
		            hdr.sprintf("%d\n%d\n%s\n%s\n%s", 1, ++i, (const char*)msg->getFrom(), (const char*)msg->getTo(), (const char*)msg->getSubject());
		        } else {
						    hdr.sprintf("%d\n%d\n%s\n%s\n%s", 0, ++i, (const char*)msg->getFrom(), (const char*)msg->getTo(), (const char*)msg->getSubject());		
						}
						debug("insertItem(hdr);");
            insertItem(hdr);
            if (msg->getTo().contains("Michael Espey") > 0) {
                changeItemColor(QColor(0,0,255));
            }
            //else
            if (msg->getFrom().contains("Michael Espey") > 0) {
                changeItemColor(QColor(0,255,0));
            }
        }
    } else {
    		debug("no current Area");
    }
    setAutoUpdate(TRUE);
    repaint();
}






