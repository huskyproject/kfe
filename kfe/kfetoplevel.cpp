#include <qmessagebox.h>
#include <kiconloader.h>
#include "kfetoplevel.h"
#include "composewidget.h"



KkfeTopLevel::KkfeTopLevel()
    : KTMainWindow()
{
    readConfig();
    smapi = new Ksmapi(2); // *** make the def_zone configurable

    setupMenuBar();
    setupStatusBar();
    setupToolBar();

    attrbar = new attribBar(this, new msgattributes());
    addToolBar(attrbar);
    attrbar->setBarPos(KToolBar::Left);

    //    setMinimumSize(500, 350);
    resize(widgetwidth, widgetheight);

    // *** make use of layout later
    hPanner = new KNewPanner(this, "HoizontalPanner", KNewPanner::Horizontal, KNewPanner::Absolute);
    hPanner->resize(widgetwidth, widgetheight);
    setView(hPanner);

    vPanner = new KNewPanner(hPanner, "VerticalPanner", KNewPanner::Vertical);

    aList = new areaListWidget(vPanner, smapi);
    connect(aList, SIGNAL(selected(int, int)), this, SLOT(cmAreaListSelected(int, int)));

    mList = new msgListWidget(hPanner, smapi); // *** check below, use newSelection
    connect(mList, SIGNAL(selected(int, int)), this, SLOT(cmMsgListSelected(int, int)));

    msg = new msgWidget(vPanner, smapi);

    hPanner->activate(mList, vPanner);
    vPanner->activate(aList, msg);

    hPanner->setAbsSeperatorPos(hpannerseperatorpos);
    vPanner->setAbsSeperatorPos(vpannerseperatorpos);
		
    debug("vor cmAreaRescanList()");
    cmAreaRescanList();
    debug("nach cmAreaRescanList()");
}



KkfeTopLevel::~KkfeTopLevel()
{
    delete msg;
    delete aList;
    delete mList;
    delete smapi;

    debug("KkfeTopLevel finished. Oki!");
}



void KkfeTopLevel::setupMenuBar()
{
    // The Keyboard Accellerator, make this a seperate Method later
    accel = new QAccel(this);        // create accels for myWindow

    menubar = new KMenuBar(this);
    setMenu(menubar);

    // File Menu
    mFile = new QPopupMenu();

    ID_FILE_NEWMSG = mFile->insertItem(i18n("&New Message..."));
    mFile->connectItem(ID_FILE_NEWMSG, this, SLOT(cmFileNewMsg()));

    ID_FILE_NEWREADER = mFile->insertItem(i18n("&New Reader..."));
    mFile->connectItem(ID_FILE_NEWREADER, this, SLOT(cmFileNewReader()));

    mFile->insertSeparator();

    ID_FILE_SAVEAS = mFile->insertItem(i18n("&Save as..."));
    mFile->connectItem(ID_FILE_SAVEAS, this, SLOT(cmFileSaveAs()));

    ID_FILE_PRINT = mFile->insertItem(i18n("&Print"));
    mFile->connectItem(ID_FILE_SAVEAS, this, SLOT(cmFilePrint()));

    ID_FILE_PRINTERSETUP = mFile->insertItem(i18n("&Printer Setup..."));
    mFile->connectItem(ID_FILE_PRINTERSETUP, this, SLOT(cmFilePrinterSetup()));

    mFile->insertSeparator();

    ID_FILE_QUIT = mFile->insertItem(i18n("&Quit"));
    mFile->connectItem(ID_FILE_QUIT, this, SLOT(cmFileQuit()));

    menubar->insertItem(i18n("&File"), mFile);

    // Area Menu
    mArea = new QPopupMenu();

    ID_AREA_RESCAN = mArea->insertItem(i18n("&Rescan"));
    mArea->connectItem(ID_AREA_RESCAN, this, SLOT(cmRescanAreaList()));

    mArea->insertSeparator();
    
    ID_AREA_FIRST = mArea->insertItem(i18n("&First\tALT-Home"));
    mArea->connectItem(ID_AREA_FIRST, this, SLOT(cmAreaFirst()));
    accel->connectItem(accel->insertItem(ALT + Key_Home),this,SLOT(cmAreaFirst()));

    ID_AREA_PREV = mArea->insertItem(i18n("&Prev\tALT-Left"));
    mArea->connectItem(ID_AREA_PREV, this, SLOT(cmAreaPrev()));
    accel->connectItem(accel->insertItem(ALT + Key_Left),this,SLOT(cmAreaPrev()));

    ID_AREA_NEXT = mArea->insertItem(i18n("&Next\tALT-Right"));
    mArea->connectItem(ID_AREA_NEXT, this, SLOT(cmAreaNext()));
    accel->connectItem(accel->insertItem(ALT + Key_Right),this,SLOT(cmAreaNext()));

    ID_AREA_LAST = mArea->insertItem(i18n("&Last\tALT-End"));
    mArea->connectItem(ID_AREA_LAST, this, SLOT(cmAreaLast()));
    accel->connectItem(accel->insertItem(ALT + Key_End),this,SLOT(cmAreaLast()));

    menubar->insertItem(i18n("&Area"), mArea);
    
    // Message Menu
    mMessage = new QPopupMenu;

    ID_MESSAGE_REPLY = mMessage->insertItem(i18n("Reply\tALT-R"));
		mMessage->connectItem(ID_MESSAGE_REPLY, this, SLOT(cmMessageReply()));
    accel->connectItem(accel->insertItem(ALT + Key_R),this,SLOT(cmMessageReply()));

    mMessage->insertSeparator();

    ID_MESSAGE_FIRST = mMessage->insertItem(i18n("First\tCTRL-Home"));
    mMessage->connectItem(ID_MESSAGE_FIRST, this, SLOT(cmMessageFirst()));
    accel->connectItem(accel->insertItem(CTRL + Key_Home),this,SLOT(cmMessageFirst()));

    ID_MESSAGE_PREV = mMessage->insertItem(i18n("Previous\tCTRL-Left"));
    mMessage->connectItem(ID_MESSAGE_PREV, this, SLOT(cmMessagePrev()));
    accel->connectItem(accel->insertItem(CTRL + Key_Left),this,SLOT(cmMessagePrev()));

    ID_MESSAGE_NEXT = mMessage->insertItem(i18n("Next\tCTRL-Right"));
    mMessage->connectItem(ID_MESSAGE_NEXT, this, SLOT(cmMessageNext()));
    accel->connectItem(accel->insertItem(CTRL + Key_Right),this,SLOT(cmMessageNext()));

    ID_MESSAGE_LAST = mMessage->insertItem(i18n("Last\tCTRL-End"));
    mMessage->connectItem(ID_MESSAGE_LAST, this, SLOT(cmMessageLast()));
    accel->connectItem(accel->insertItem(CTRL + Key_End),this,SLOT(cmMessageLast()));

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

    toolbar->insertButton(iconLoader.loadIcon("filenew.xpm"), ID_FILE_NEWMSG, SIGNAL(clicked()),
                          this, SLOT(cmFileNewMsg()), TRUE, i18n("New Message"));
    toolbar->insertButton(iconLoader.loadIcon("start.xpm"), 1, SIGNAL(clicked()),
                          this, SLOT(cmMessageFirst()), TRUE, i18n("First Message"));
    toolbar->insertButton(iconLoader.loadIcon("prev.xpm"), 2, SIGNAL(clicked()),
                          this, SLOT(cmMessagePrev()), TRUE, i18n("Previous Message"));
    toolbar->insertButton(iconLoader.loadIcon("next.xpm"), 3, SIGNAL(clicked()),
                          this, SLOT(cmMessageNext()), TRUE, i18n("Next Message"));
    toolbar->insertButton(iconLoader.loadIcon("finish.xpm"), 4, SIGNAL(clicked()),
                          this, SLOT(cmMessageLast()), TRUE, i18n("Last Message"));

    toolbar->setBarPos(KToolBar::Top);
}



void KkfeTopLevel::setupStatusBar()
{
    statusbar = new KStatusBar(this);
    statusbar->insertItem("StatusText", 1);
        
    //    statusbar->show();
    setStatusBar(statusbar);
}



void KkfeTopLevel::cmFileNewMsg()
{
    composeWidget* composewidget = new composeWidget(smapi);
    composewidget->show();
}



void KkfeTopLevel::cmFileNewReader()
{
    KkfeTopLevel* kfe = new KkfeTopLevel();
    kfe->show();
}



void KkfeTopLevel::cmFileQuit()
{
    writeConfig();
    // *** change this later
    kapp->quit();
}



void KkfeTopLevel::cmAreaListSelected(int index, int column = 0)
{
		smapi->setCurAreaNum(index);
    debug("vor set caption");
    CHECK_PTR(smapi->getCurArea());
    CHECK_PTR(smapi->getCurArea()->getName());

    setCaption("kfe - " + smapi->getCurArea()->getName());
    debug("vor cmMessageRescanList");
    cmMessageRescanList();
    debug("nach cmMessageRescanList");
}



void KkfeTopLevel::cmAreaRescanList()
{
		debug("vor upDateConten");
    aList->updateContent();
    debug("nach upDateContent");
    cmAreaListSelected(aList->currentItem());
}



void KkfeTopLevel::cmAreaFirst()
{
		cmAreaListSelected(0);
}



void KkfeTopLevel::cmAreaPrev()
{
    if (aList->currentItem() > 0) {
        aList->setCurrentItem(aList->currentItem() - 1);
        cmAreaListSelected(aList->currentItem());
    }
}



void KkfeTopLevel::cmAreaNext()
{
    if (aList->currentItem() + 1 < aList->numRows()) {
        aList->setCurrentItem(aList->currentItem() + 1);
        cmAreaListSelected(aList->currentItem());
    }
}



void KkfeTopLevel::cmAreaLast()
{
    aList->setCurrentItem(aList->numRows() - 1);
    cmAreaListSelected(aList->currentItem());
}



void KkfeTopLevel::cmMessageRescanList()
{
		debug("KkfeTopLevel::cmMessageRescanList()");
		debug("vor rescan()");
    mList->rescan();
    debug("vor cmMsgListSelected()");
    cmMsgListSelected(mList->currentItem());
 		debug("/KkfeTopLevel::cmMessageRescanList()");
}



void KkfeTopLevel::cmMsgListSelected(int newItem, int colum =0)
{
		debug("void KkfeTopLevel::cmMsgListSelected(int newItem, int colum =0)");
    updateMsg();
}



void KkfeTopLevel::cmMessageFirst()
{
    mList->setCurrentItem(0);
    cmMsgListSelected(mList->currentItem());
}



void KkfeTopLevel::cmMessagePrev()
{
    if (mList->currentItem() > 0) {
        mList->setCurrentItem(mList->currentItem() - 1);
        cmMsgListSelected(mList->currentItem());
    }
}



void KkfeTopLevel::cmMessageNext()
{
    if (mList->currentItem() + 1 < mList->numRows()) {
        mList->setCurrentItem(mList->currentItem() + 1);
        cmMsgListSelected(mList->currentItem());
    }
}



void KkfeTopLevel::cmMessageLast()
{
    mList->setCurrentItem(mList->numRows());
    cmMsgListSelected(mList->currentItem());
}



void KkfeTopLevel::updateMsg()
{
		debug("void KkfeTopLevel::updateMsg()");
    msg->updateMsg();
    debug("nach msg->updateMsg();");
/*
    if (smapi->getCurArea() != 0) {
        attrbar->upDate(smapi->getCurMsg()->getAttr());
    }
*/
//    smapi->getCurArea()->setLastRead(smapi->getCurArea()->msgNum2UmsgId(mList->currentItem()));

    char stattext[25];
/*    sprintf(stattext, "Msg %d of %d (%d left)",
            smapi->getCurMsgNum(), smapi->getCurArea()->getMsgNum(),
            smapi->getCurArea()->getMsgNum()-smapi->getCurMsgNum());
    statusbar->changeItem(stattext, 1);
*/
}



void KkfeTopLevel::readConfig()
{
    kdeConfig = kapp->getConfig();

    kdeConfig->setGroup("general");

    widgetwidth = kdeConfig->readNumEntry("Width", 500);
    widgetheight = kdeConfig->readNumEntry("Height", 350);
    hpannerseperatorpos = kdeConfig->readNumEntry("hPannerSeperator", 100);
    vpannerseperatorpos = kdeConfig->readNumEntry("vPannerSeperator", 100);
}



void KkfeTopLevel::writeConfig()
{
    kdeConfig = kapp->getConfig();

    // general items, window positions etc
    kdeConfig->setGroup("general");
    kdeConfig->writeEntry("Width", this->width());
    kdeConfig->writeEntry("Height", this->height());
    kdeConfig->writeEntry("hPannerSeperator", hPanner->absSeperatorPos());
    kdeConfig->writeEntry("vPannerSeperator", vPanner->absSeperatorPos());

    // the arealistbox
    kdeConfig->setGroup("arealist");
    kdeConfig->writeEntry("Area", 10);
    kdeConfig->writeEntry("New", 10);
    kdeConfig->writeEntry("Total", 10);

    kdeConfig->sync();
}                                        

































































