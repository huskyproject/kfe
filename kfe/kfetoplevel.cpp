#include "kfetoplevel.h"
#include "qmessagebox.h"
#include "kiconloader.h"



KkfeTopLevel::KkfeTopLevel()
    : KTMainWindow()
{
    setMinimumSize(500, 350);

    //init SMAPI
    m.req_version = 0;
    m.def_zone = 2;
    if (MsgOpenApi(&m) != 0) {
        printf("MsgApiOpen Error");
        // *** make error box here !
        exit(1);
    }


    hPanner = new KNewPanner(this, "HoizontalPanner",
                             KNewPanner::Horizontal, KNewPanner::Absolute);
    hPanner->resize(size());
    setView(hPanner);

    vPanner = new KNewPanner(hPanner, "VerticalPanner",
                             KNewPanner::Vertical);

    msg = new msgWidget(vPanner, "test");

    mList = new msgListWidget(hPanner);
    connect(mList, SIGNAL(newSelection(f_message*)), msg, SLOT(showMsg(f_message*)));

    aList = new areaListWidget(vPanner, "areaList");
    connect(aList, SIGNAL(newSelection(f_area*)), this, SLOT(cmRescanMessages(f_area*)));

    

    hPanner->activate(mList, vPanner);
    vPanner->activate(aList, msg);
    
    hPanner->setAbsSeperatorPos(100);
    vPanner->setAbsSeperatorPos(100);

    setupMenuBar();
    setupStatusBar();
    setupToolBar();
}


void KkfeTopLevel::setupMenuBar()
{
    menubar = new KMenuBar(this);
    setMenu(menubar);

    // File Menu
    mFile = new QPopupMenu();
    
    ID_FILE_QUIT = mFile->insertItem(i18n("&Quit"));
    mFile->connectItem(ID_FILE_QUIT, kapp, SLOT(quit()));

    menubar->insertItem(i18n("&File"), mFile);

    // Message Menu
    mMessage = new QPopupMenu;

    ID_MESSAGE_NEXT = mMessage->insertItem(i18n("next"));
    ID_MESSAGE_PREV = mMessage->insertItem(i18n("previous"));

    menubar->insertItem(i18n("&Message"), mMessage);
    
    // Help Menu
    mHelp = kapp->getHelpMenu(true,
                              i18n("kfe - kde fido editor\n\n"
                                   "(c) 1998 Michael Espey\n"
                                   "a KDE Squish Editor"));
    menubar->insertItem(i18n("&Help"), mHelp);

}


void KkfeTopLevel::setupToolBar()
{
    KIconLoader iconLoader;
    toolbar = new KToolBar(this);

    addToolBar(toolbar);

    toolbar->insertButton(iconLoader.loadIcon("filenew.xpm"), ID_MESSAGE_NEW, SIGNAL(clicked()),
                          kapp, SLOT(slotNextMessage()), TRUE, i18n("New Message"));
    toolbar->insertButton(iconLoader.loadIcon("start.xpm"), 1, SIGNAL(clicked()),
                          this, SLOT(slotNextMessage()), TRUE, i18n("First Message"));
    toolbar->insertButton(iconLoader.loadIcon("prev.xpm"), 2, SIGNAL(clicked()),
                          kapp, SLOT(slotNextMessage()), TRUE, i18n("Previous Message"));
    toolbar->insertButton(iconLoader.loadIcon("next.xpm"), 3, SIGNAL(clicked()),
                          kapp, SLOT(slotNextMessage()), TRUE, i18n("Next Message"));
    toolbar->insertButton(iconLoader.loadIcon("finish.xpm"), 4, SIGNAL(clicked()),
                          kapp, SLOT(slotNextMessage()), TRUE, i18n("Last Message"));
    toolbar->insertSeparator();
    toolbar->insertButton(iconLoader.loadIcon("help.xpm"),ID_HELP_CONTENTS,SIGNAL(pressed()),
                          kapp, SLOT(appHelpActivated()), TRUE, i18n("Help Contents"));

    toolbar->setBarPos(KToolBar::Top);
//    toolbar->show();
    //    connect(toolbar, SIGNAL(clicked(int)), this, SLOT(menuCallback(int)));
}


void KkfeTopLevel::setupStatusBar()
{
    statusbar = new KStatusBar(this);
    statusbar->insertItem("StatusText", 1);
        
//    statusbar->show();
    setStatusBar(statusbar);
}

void KkfeTopLevel::cmFileQuit()
{

}


void KkfeTopLevel::cmViewAreas()
{

}


void KkfeTopLevel::cmViewMessages()
{

}


void KkfeTopLevel::cmViewStatusbar()
{
    showStatusbar = !showStatusbar;
    mView->setItemChecked(mView->idAt(3), showStatusbar);
    if (statusbar) {
        enableStatusBar(KStatusBar::Show);
    } else {
        enableStatusBar(KStatusBar::Hide);
    }
}


void KkfeTopLevel::cmViewToolbar()
{
    showToolbar = !showToolbar;
    mView->setItemChecked(mView->idAt(4), showToolbar);
    if (toolbar) {
        enableToolBar(KToolBar::Show, 0);
    } else {
        enableToolBar(KToolBar::Hide, 0);
    }
}


// misc slots
void KkfeTopLevel::cmRescanMessages(f_area* sel)
{
    printf("RescanMessages\n");
    mList->rescan(sel);
}
