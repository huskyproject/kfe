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


    mList = new msgListWidget(hPanner);
    connect(mList, SIGNAL(newSelection(int)),
            this, SLOT(cmUpdateMsg(int)));

    aList = new areaListWidget(vPanner);
    connect(aList, SIGNAL(newSelection(int)),
            this, SLOT(cmUpdateMsgList(int)));

    msg = new msgWidget(vPanner);
//    connect(mList, SIGNAL(updateMsg()),
//            msg, SLOT(updateMsg()));


    hPanner->activate(mList, vPanner);
    vPanner->activate(aList, msg);

    hPanner->setAbsSeperatorPos(100);
    vPanner->setAbsSeperatorPos(100);

    setupMenuBar();
    setupStatusBar();
    setupToolBar();


    // get this from setup laten
//    smapi->setCurArea(0);
    cmUpdateAreaList();
//    cmUpdateMsgList(0);
}


KkfeTopLevel::~KkfeTopLevel()
{
    printf("KkfeTopLevel::~KkfeTopLevel\n");

    printf("delete msg\n");
    delete msg;
    printf("delete alist\n");
    delete aList;
    printf("delete mlist\n");
    delete mList;
    printf("delete smapi\n");
    delete smapi;
    printf("after delete smapi\n");

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
    mArea->connectItem(ID_AREA_RESCAN, this, SLOT(cmUpdateAreaList()));

    menubar->insertItem(i18n("&Area"), mArea);
    
    // Message Menu
    mMessage = new QPopupMenu;

    ID_MESSAGE_FIRST = mMessage->insertItem(i18n("First"));
    ID_MESSAGE_NEXT = mMessage->insertItem(i18n("Next"));
    ID_MESSAGE_PREV = mMessage->insertItem(i18n("Previous"));
    ID_MESSAGE_LAST = mMessage->insertItem(i18n("Last"));

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
                          this, SLOT(cmMessageFirst()), TRUE, i18n("First Message"));
    toolbar->insertButton(iconLoader.loadIcon("prev.xpm"), 2, SIGNAL(clicked()),
                          this, SLOT(cmMessageNext()), TRUE, i18n("Previous Message"));
    toolbar->insertButton(iconLoader.loadIcon("next.xpm"), 3, SIGNAL(clicked()),
                          this, SLOT(cmMessagePrev()), TRUE, i18n("Next Message"));
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


void KkfeTopLevel::cmAreaFirst()
{
    ;
}


void KkfeTopLevel::cmAreaNext()
{
    ;
}


void KkfeTopLevel::cmAreaPrev()
{
    ;
}


void KkfeTopLevel::cmAreaLast()
{
    ;
}


void KkfeTopLevel::cmMessageFirst()
{
    printf("KkfeTopLevel::cmMessageFirst()\n");
    smapi->getCurArea()->getFirstMsg();
    msg->updateMsg(smapi->getCurArea()->getCurMsg());
}


void KkfeTopLevel::cmMessageNext()
{
    printf("KkfeTopLevel::cmMessageNext()\n");
    smapi->getCurArea()->getNextMsg();
    msg->updateMsg(smapi->getCurArea()->getCurMsg());
}


void KkfeTopLevel::cmMessagePrev()
{
    printf("KkfeTopLevel::cmMessagePrev()\n");
    smapi->getCurArea()->getPrevMsg();
    msg->updateMsg(smapi->getCurArea()->getCurMsg());
}


void KkfeTopLevel::cmMessageLast()
{
    printf("KkfeTopLevel::cmMessageLst()\n");
    smapi->getCurArea()->getLastMsg();
    msg->updateMsg(smapi->getCurArea()->getCurMsg());
}
    







void KkfeTopLevel::cmUpdateAreaList()
{
    smapi->rescanAreas();
    aList->updateContent(smapi);
    cmUpdateMsgList(0);  // *** make this the lastread of the area
}


void KkfeTopLevel::cmUpdateMsgList(int newitem)
{
    printf("KkfeTopLevel::cmUpdateMsgList\n");
    smapi->setCurArea(newitem);
    smapi->rescanMsgs();
    mList->rescanContent(smapi->getCurArea());
    cmUpdateMsg(0); // ***check out the lastreadpointer here
}


void KkfeTopLevel::cmUpdateMsg(int newitem)
{
    printf("KkfeTopLevel::cmUpdateMsg()\n");
    smapi->getCurArea()->setCurMsg(newitem);
    msg->updateMsg(smapi->getCurArea()->getCurMsg());

    printf("Modify Statbar\n");
    char stattext[25];
    sprintf(stattext, "Msg x of %d (x left)", smapi->getCurArea()->getMsgNum());
    statusbar->changeItem(stattext, 1);

}
