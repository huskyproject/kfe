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


class KkfeTopLevel : public KTMainWindow
{
    Q_OBJECT

public:
    KkfeTopLevel();

protected:
    void setupMenuBar();
    void setupStatusBar();
    void setupToolBar();

private slots:
    // menu slots
    void cmFileQuit();

    void cmViewAreas();
    void cmViewMessages();
    void cmViewStatusbar();
    void cmViewToolbar();


    // misc slots
    void cmRescanMessages(f_area*);

private:

    KMenuBar *menubar;
    KStatusBar *statusbar;
    KToolBar *toolbar;

    KNewPanner *vPanner, *hPanner;

    areaListWidget *aList;
    msgListWidget *mList;
    msgWidget *msg;

    QPopupMenu *mFile, *mView, *mMessage, *mOptions, *mHelp;

    int contentsID, aboutID, aboutKDEID, quitID;
    int ID_NEW, ID_OPEN, ID_HELP;

    int ID_FILE_QUIT;
    int ID_VIEW_AREALIST, ID_VIEW_MSGLIST, ID_VIEW_STATUSBAR, ID_VIEW_TOOLBAR;
    int ID_MESSAGE_NEW, ID_MESSAGE_NEXT, ID_MESSAGE_PREV, ID_MESSAGE_SELECT;;
    int ID_HELP_CONTENTS, ID_HELP_ABOUT_KFE, ID_ABOUT_KDE;
    
    bool showArealist, showMsglist, showStatusbar, showToolbar;

    struct _minf m;

    //    KDNDDropZone * dropZone;
};
#endif
