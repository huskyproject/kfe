
#ifndef _MSGWIDGET_H
#define _MSGWIDGET_H

#include <qpopmenu.h>

#include <kfm.h>
#include <kapp.h>
#include <kurl.h>
#include <klocale.h>
#include <qmultilinedit.h>

#include "f_message.h"

class msgWidget : public QMultiLineEdit {
    Q_OBJECT
    
public:
    msgWidget(QWidget *parent=0, const char *name=0 );
    ~msgWidget();

    void update(int msgnum);

public slots:
    void showMsg(f_message* item);

protected:
    //void paintEvent(QPaintEvent *pa);
//    void closeEvent ( QCloseEvent *e);
    void initGeometry();
};

#endif
