/*
 *
 */

#include <stdio.h>

#include "kmsgbox.h"
#include "arealistwidget.h"
#include "ktablistbox.h"

// *************************************************************
// class msgArea

areaListWidget::areaListWidget(QWidget *parent, const char *name)
    : KTabListBox(parent, name, 3)
{
    // setup the Arealist
    arealist.append(new f_area("linux.ger"));
    arealist.append(new f_area("linux"));
    arealist.append(new f_area("linux.develop.ger"));
    arealist.append(new f_area("spiele.ger"));

    // setup the Widget
    setMinimumSize(180, 100);

    setColumn(0, "Area", 100);
    setColumn(1, "new", 40);
    setColumn(2, "total", 40);

    // insert Areas in ListBox
    bool first = TRUE;
    
    f_area* foo;
    for(foo = arealist.first(); foo != 0; foo = arealist.next()) {
        printf("start arealistwidget\n");
        QString hdr(256);
        hdr.sprintf("%s\n%d\n%d", (const char*)foo->getName(), foo->getNewMsgs(), foo->getMsgs());
        insertItem(hdr);
        if (first) {
            printf("first\n");
            emit newSelection(foo);
            first = FALSE;
        }
    }
    resize(size());
    setAutoUpdate(TRUE);
}


areaListWidget::~areaListWidget()
{
    ;
}


//    f_area* sel = arealist.at(item);
//    emit newSelection(sel);
