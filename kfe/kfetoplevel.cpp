#include "kfetoplevel.h"
#include "qmessagebox.h"
#include "kiconloader.h"



KkfeTopLevel::KkfeTopLevel()
    : KTMainWindow()
{
    smapi = new Ksmapi(2); // *** make the def_zone configurable

    setMinimumSize(500, 350);

    hPanner = new KNewPanner(this, "HoizontalPanner",
                             KNewPanner::Horizontal, KNewPanner::Absolute);
    hPanner->resize(size());
    setView(hPanner);

    vPanner = new KNewPanner(hPanner, "VerticalPanner",
                             KNewPanner::Vertical);

    aList = new areaListWidget(vPanner, smapi);
    connect(aList, SIGNAL(newSelection(int)),
            this, SLOT(cmAreaListSelected(int)));

    mList = new msgListWidget(hPanner, smapi);
    connect(mList, SIGNAL(newSelection(int)),
            this, SLOT(cmMsgListSelected(int)));


    msg = new msgWidget(vPanner, smapi);
//    connect(mList, SIGNAL(updateMsg()),
//            msg, SLOT(updateMsg()));

    hPanner->activate(mList, vPanner);
    vPanner->activate(aList, msg);

    hPanner->setAbsSeperatorPos(100);
    vPanner->setAbsSeperatorPos(100);

    setupMenuBar();
    setupStatusBar();
    setupToolBar();

    cmRescanAreaList();
    smapi->setCurArea(0); // *** get from config

}



KkfeTopLevel::~KkfeTopLevel()
{
    delete msg;
    delete aList;
    delete mList;
    delete smapi;
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

    // Area Menu
    mArea = new QPopupMenu();

    ID_AREA_RESCAN = mArea->insertItem(i18n("&Rescan"));
    mArea->connectItem(ID_AREA_RESCAN, this, SLOT(cmRescanAreaList()));

    mArea->insertSeparator();
    
    ID_AREA_FIRST = mArea->insertItem(i18n("&First"));
    mArea->connectItem(ID_AREA_FIRST, this, SLOT(cmAreaFirst()));

    ID_AREA_PREV = mArea->insertItem(i18n("&Prev"));
    mArea->connectItem(ID_AREA_PREV, this, SLOT(cmAreaPrev()));

    ID_AREA_NEXT = mArea->insertItem(i18n("&Next"));
    mArea->connectItem(ID_AREA_NEXT, this, SLOT(cmAreaNext()));

    ID_AREA_LAST = mArea->insertItem(i18n("&Last"));
    mArea->connectItem(ID_AREA_LAST, this, SLOT(cmAreaLast()));

    menubar->insertItem(i18n("&Area"), mArea);
    
    // Message Menu
    mMessage = new QPopupMenu;

    ID_MESSAGE_FIRST = mMessage->insertItem(i18n("First"));
    mMessage->connectItem(ID_MESSAGE_FIRST, this, SLOT(cmMessageFirst()));

    ID_MESSAGE_PREV = mMessage->insertItem(i18n("Previous"));
    mMessage->connectItem(ID_MESSAGE_PREV, this, SLOT(cmMessagePrev()));

    ID_MESSAGE_NEXT = mMessage->insertItem(i18n("Next"));
    mMessage->connectItem(ID_MESSAGE_NEXT, this, SLOT(cmMessageNext()));

    ID_MESSAGE_LAST = mMessage->insertItem(i18n("Last"));
    mMessage->connectItem(ID_MESSAGE_LAST, this, SLOT(cmMessageLast()));

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
                          kapp, SLOT(cmMessageNew()), TRUE, i18n("New Message"));
    toolbar->insertButton(iconLoader.loadIcon("start.xpm"), 1, SIGNAL(clicked()),
                          this, SLOT(cmMessageFirst()), TRUE, i18n("First Message"));
    toolbar->insertButton(iconLoader.loadIcon("prev.xpm"), 2, SIGNAL(clicked()),
                          this, SLOT(cmMessagePrev()), TRUE, i18n("Previous Message"));
    toolbar->insertButton(iconLoader.loadIcon("next.xpm"), 3, SIGNAL(clicked()),
                          this, SLOT(cmMessageNext()), TRUE, i18n("Next Message"));
    toolbar->insertButton(iconLoader.loadIcon("finish.xpm"), 4, SIGNAL(clicked()),
                          this, SLOT(cmMessageLast()), TRUE, i18n("Last Message"));
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



void KkfeTopLevel::cmRescanAreaList()
{
    int selected = 0;
    smapi->rescanAreas();
    smapi->setCurArea(selected);
    aList->updateContent(selected);
}



void KkfeTopLevel::cmAreaFirst()
{
    debug("KkfeTopLevel::cmAreaFirst()");
    smapi->getFirstArea();
    aList->setCurrentItem(0);
    updateMsgList();
}



void KkfeTopLevel::cmAreaPrev()
{
    debug("KkfeTopLevel::cmAreaPrev()");
    int cur = aList->currentItem();
    if (cur > 0) {
        smapi->getPrevArea();
        aList->setCurrentItem(--cur);
        updateMsgList();
    }
}



void KkfeTopLevel::cmAreaNext()
{
    debug("KkfeTopLevel::cmAreaNext()");
    int cur = aList->currentItem();
    if (cur + 1 < aList->numRows()) {
        smapi->getNextArea();
        aList->setCurrentItem(++cur);
        updateMsgList();
    }
}



void KkfeTopLevel::cmAreaLast()
{
    debug("KkfeTopLevel::cmAreaLast()");
    smapi->getLastArea();
    aList->setCurrentItem(aList->numRows() - 1);
    updateMsgList();
}



void KkfeTopLevel::cmMessageFirst()
{
    printf("KkfeTopLevel::cmMessageFirst()\n");
    smapi->getFirstMsg();
    mList->setCurrentItem(0);
    updateMsg();
}



void KkfeTopLevel::cmMessagePrev()
{
    printf("KkfeTopLevel::cmMessagePrev()\n");
    int cur = mList->currentItem();
    if (cur > 0) {
        smapi->getPrevMsg();
        mList->setCurrentItem(--cur);
        updateMsg();
    }
}



void KkfeTopLevel::cmMessageNext()
{
    printf("KkfeTopLevel::cmMessageNext()\n");
    int cur = mList->currentItem();
    if (cur + 1 < mList->numRows()) {
        smapi->getNextMsg();
        mList->setCurrentItem(++cur);
        updateMsg();
    }
}



void KkfeTopLevel::cmMessageLast()
{
    printf("KkfeTopLevel::cmMessageLst()\n");
    smapi->getLastMsg();
    mList->setCurrentItem(mList->numRows() - 1);
    updateMsg();
}



void KkfeTopLevel::cmAreaListSelected(int newItem)
{
    debug("KkfeTopLevel::cmUpdateAreaList()");
    smapi->setCurArea(newItem);
    updateMsgList();
}



void KkfeTopLevel::cmMsgListSelected(int newItem)
{
    printf("KkfeTopLevel::cmUpdateMsgList\n");
    smapi->setCurMsg(newItem);
    updateMsg();
}



void KkfeTopLevel::updateMsgList()
{
    debug("KkfeTopLevel::UpdateMsgList()");
    debug("1");
    smapi->rescanMsgs();
    debug("2");
    mList->rescanContent();
    debug("3");
    smapi->setCurMsg(0); //*** get the Lastread pointer
    mList->setCurrentItem(0);
    debug("4");
    updateMsg();
}



void KkfeTopLevel::updateMsg()
{
    printf("KkfeTopLevel::cmUpdateMsg()\n");
    msg->updateMsg();

    printf("Modify Statbar\n");
    char stattext[25];
    sprintf(stattext, "Msg x of %d (x left)", smapi->getCurArea()->getMsgNum());
    statusbar->changeItem(stattext, 1);
}
