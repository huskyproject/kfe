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

public:
    areaListWidget(QWidget* parent = 0);
    ~areaListWidget();


public slots:
    void areaSelected(int);
    void updateContent(Ksmapi* smapi);
    
signals:
    void newSelection(int);
};

#endif

