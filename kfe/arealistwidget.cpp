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
    debug("areaListWidget::areaListWidget");

    smapi = newSmapi;

    // setup the Widget
    setMinimumSize(180, 100);

    setColumn(0, "Area", 100);
    setColumn(1, "new", 40);
    setColumn(2, "total", 40);

    readConfig();
    resize(size());

//    connect(this, SIGNAL(headerClicked(int)), this, SLOT(reSort(int)));
}



areaListWidget::~areaListWidget()
{
    writeConfig();
}



void areaListWidget::updateContent()
{
    debug("areaListWidget::updateContent()");
    QString hdr(256);

    smapi->rescanAreas();

    int curarea = smapi->getCurAreaNum();
    debug("current area vor rescan:%d", curarea);

    setAutoUpdate(FALSE);
    clear();
    
    smapiArea* area;
    debug("---------");
    debug("vor for()");
    for(area = smapi->getFirstArea(); area != 0; area = smapi->getNextArea()) {
        debug("in for()");
        CHECK_PTR(area->getName());
        debug("Areaname: %s, size: %d", (const char*)area->getName(), area->getAreaSize());
//				CHECK_PTR(area->getAreaSize());
				CHECK_PTR(area->getLastRead());
        hdr.sprintf("%s\n%d\n%d",
        					  (const char*)area->getName(),
        					  area->getAreaSize() - area->getLastRead(),
        					  area->getAreaSize());
        insertItem(hdr);
    }
    debug("nach for()");
    setCurrentItem(curarea);
    smapi->setCurAreaNum(curarea);
    setAutoUpdate(TRUE);
    debug("/areaListWidget::updateContent()");
};



void areaListWidget::reSort(int sortorder)
{
    debug("areaListWidget::reSort");

}



















