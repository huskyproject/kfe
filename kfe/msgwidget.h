#ifndef _MSGWIDGET_H
#define _MSGWIDGET_H

#include <qpopmenu.h>

#include <kfm.h>
#include <kapp.h>
#include <kurl.h>
#include <klocale.h>
#include <qmultilinedit.h>

#include "ksmapi.h"
#include "smapimsg.h"

class msgWidget : public QMultiLineEdit {
    Q_OBJECT

private:
    Ksmapi* smapi;
    
public:
    msgWidget(QWidget *parent=0);
    ~msgWidget();

public slots:
    void updateMsg(smapiMsg* newmsg);

protected:
    void initGeometry();
};

#endif
