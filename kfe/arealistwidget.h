/*
 *
 */

#ifndef AREALISTWIDGET_H
#define AREALISTWIDGET_H

#include <ktablistbox.h>
#include <qlist.h>
#include <qstring.h>

#include "ksmapi.h"

class areaListWidget : public KTabListBox
{
    Q_OBJECT

private:
    Ksmapi* smapi;
    
public:
    areaListWidget(QWidget* parent = 0, Ksmapi* newSmapi = 0);
    ~areaListWidget();


public slots:
    void updateContent();
    void reSort(int sortorder);
};

#endif




