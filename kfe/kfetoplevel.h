#ifndef _TOPLEVEL_H_
#define _TOPLEVEL_H_

#include <kapp.h>
#include <ktopwidget.h>
#include <kmenubar.h>
#include <kstatusbar.h>
#include <ktoolbar.h>
#include <qpopmenu.h>
#include <qaccel.h>
#include <knewpanner.h>

#include "arealistwidget.h"
#include "msglistwidget.h"
#include "msgwidget.h"
#include "ksmapi.h"


class KkfeTopLevel : public KTMainWindow
{
    Q_OBJECT

public:
    KkfeTopLevel();
    ~KkfeTopLevel();

    
protected:
    void setupMenuBar();
    void setupStatusBar();
    void setupToolBar();


private slots:
    // menu slots
    void cmFileQuit();

    void cmRescanAreaList();
    void cmAreaFirst();
    void cmAreaNext();
    void cmAreaPrev();
    void cmAreaLast();

    void cmMessageFirst();
    void cmMessageNext();
    void cmMessagePrev();
    void cmMessageLast();
    
    // misc slots
    void cmAreaListSelected(int);
    void cmMsgListSelected(int);


private:
    Ksmapi* smapi;
    
    KMenuBar *menubar;
    KStatusBar *statusbar;
    KToolBar *toolbar;

    KNewPanner *vPanner, *hPanner;

    areaListWidget *aList;
    msgListWidget *mList;
    msgWidget *msg;

    QPopupMenu *mFile, *mArea, *mMessage, *mOptions, *mHelp;

    int ID_FILE_QUIT;
    int ID_AREA_RESCAN, ID_AREA_FIRST, ID_AREA_NEXT, ID_AREA_PREV, ID_AREA_LAST, ID_AREA_UNREAD;
    int ID_MESSAGE_NEW, ID_MESSAGE_FIRST, ID_MESSAGE_NEXT, ID_MESSAGE_PREV, ID_MESSAGE_LAST, ID_MESSAGE_SELECT;
    int ID_HELP_CONTENTS, ID_HELP_ABOUT_KFE, ID_ABOUT_KDE;
    
    bool showArealist, showMsglist, showStatusbar, showToolbar;

    void updateMsgList();
    void updateMsg();

    //    KDNDDropZone * dropZone;
};
#endif
