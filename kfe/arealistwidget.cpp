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

areaListWidget::areaListWidget(QWidget *parent)
    : KTabListBox(parent, "areaListWidget", 3)
{
    printf("areaListWidget::areaListWidget\n");

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


void areaListWidget::updateContent(Ksmapi* smapi)
{
    smapiArea* area;

    setAutoUpdate(FALSE);
    clear();
    QString hdr(256);
    for(area = smapi->getFirstArea(); area != 0; area = smapi->getNextArea()) {
        hdr.sprintf("%s\n%d\n%d", (const char*)area->getName(), area->getNewMsgNum(), area->getMsgNum());
        insertItem(hdr);
    }
    setAutoUpdate(TRUE);
};


void areaListWidget::areaSelected(int item)
{
    printf("areaListWidget:areaSelected\n");
    emit newSelection(item);
}
