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
#include <kconfig.h>

#include "arealistwidget.h"
#include "msglistwidget.h"
#include "msgwidget.h"
#include "ksmapi.h"
#include "attribbar.h"


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
    void cmFileNewMsg();
    void cmFileNewReader();

    void cmAreaRescanList();
    void cmAreaFirst();
    void cmAreaNext();
    void cmAreaPrev();
    void cmAreaLast();

    void cmMessageRescanList();
    void cmMessageFirst();
    void cmMessageNext();
    void cmMessagePrev();
    void cmMessageLast();
    
    // misc slots
    void cmAreaListSelected(int row, int colum = 0);
    void cmMsgListSelected(int row, int colum = 0);


private:
    void updateMsg();

    void readConfig();
    void writeConfig();
    
    Ksmapi* smapi;
    KConfig* kdeConfig;
    
    KMenuBar *menubar;
    QAccel *accel;
    KStatusBar *statusbar;
    KToolBar *toolbar;
    attribBar* attrbar;

    KNewPanner *vPanner, *hPanner;

    areaListWidget *aList;
    msgListWidget *mList;
    msgWidget *msg;

    QPopupMenu *mFile, *mArea, *mMessage, *mOptions, *mHelp;

    int ID_FILE_NEWMSG, ID_FILE_NEWREADER, ID_FILE_SAVEAS, ID_FILE_PRINT, ID_FILE_PRINTERSETUP, ID_FILE_QUIT;
    int ID_AREA_RESCAN, ID_AREA_FIRST, ID_AREA_NEXT, ID_AREA_PREV, ID_AREA_LAST, ID_AREA_UNREAD;
    int ID_MESSAGE_REPLY, ID_MESSAGE_FIRST, ID_MESSAGE_NEXT, ID_MESSAGE_PREV, ID_MESSAGE_LAST, ID_MESSAGE_SELECT;
    int ID_HELP_CONTENTS, ID_HELP_ABOUT_KFE, ID_ABOUT_KDE;
    
    bool showArealist, showMsglist, showStatusbar, showToolbar;

    //    KDNDDropZone * dropZone;

    // KDE Config stuff
    int widgetwidth;
    int widgetheight;
    int vpannerseperatorpos;
    int hpannerseperatorpos;    
};
#endif



















