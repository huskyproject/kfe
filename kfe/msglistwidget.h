/*
 *   kfe - a squish base message editor
 *   Copyright (C) 1998  Michael Espey
 *
 *
 */

#ifndef _MSGLISTWIDGET_H
#define _MSGLISTWIDGET_H

#include <ktablistbox.h>
#include <qstring.h>

#include "ksmapi.h"

class msgListWidget : public KTabListBox
{
    Q_OBJECT

public:
    msgListWidget(QWidget* parent=0);
    ~msgListWidget();


public slots:
    void rescanContent(smapiArea* newarea);

private slots:
    void msgSelected(int);

signals:
    void newSelection(int);
};
#endif
