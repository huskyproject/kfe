/*
 *
 */

#ifndef _AREALISTWIDGET_H
#define _AREALISTWIDGET_H

#include <ktablistbox.h>
#include <qlist.h>
#include <qstring.h>

#include "f_area.h"
#include "msgwidget.h"


class areaListWidget : public KTabListBox
{
    Q_OBJECT

public:
    areaListWidget(QWidget *parent=0, const char *name=0 );
    ~areaListWidget();

signals:
    void newSelection(f_area*);

private slots:
    void areaSelected(int);
    
protected:
    QList<f_area> arealist;
};

#endif

