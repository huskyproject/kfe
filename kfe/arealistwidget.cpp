/*
 *
 */

#include <stdio.h>

#include <kmsgbox.h>
#include <arealistwidget.h>
#include <ktablistbox.h>

#include "ksmapi.h"


// *************************************************************
// class areaListWidget

areaListWidget::areaListWidget(QWidget *parent, Ksmapi* newSmapi = 0)
    : KTabListBox(parent, "areaListWidget", 3)
{
    printf("areaListWidget::areaListWidget\n");

    smapi = newSmapi;

    // setup the Widget
    setMinimumSize(180, 100);

    setColumn(0, "Area", 100);
    setColumn(1, "new", 40);
    setColumn(2, "total", 40);

    resize(size());

    connect(this, SIGNAL(selected(int, int)), this, SLOT(areaSelected(int)));
}



areaListWidget::~areaListWidget()
{
    ;
}



void areaListWidget::updateContent(int selected)
{
    debug("areaListWidget::updateContent()");
    QString hdr(256);
    smapiArea* area;

    setAutoUpdate(FALSE);
    clear();
    
    for(area = smapi->getFirstArea(); area != 0; area = smapi->getNextArea()) {
        hdr.sprintf("%s\n%d\n%d", (const char*)area->getName(), area->getNewMsgNum(), area->getMsgNum());
        insertItem(hdr);
    }
    setCurrentItem(selected);
    setAutoUpdate(TRUE);
};



void areaListWidget::areaSelected(int item)
{
    printf("areaListWidget:areaSelected\n");
    emit newSelection(item);
}
