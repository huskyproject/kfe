/****************************************************************************
** msgListWidget meta object code from reading C++ file 'msglistwidget.h'
**
** Created: Fri Jan 15 21:54:23 1999
**      by: The Qt Meta Object Compiler ($Revision$)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "msglistwidget.h"
#include <qmetaobject.h>


const char *msgListWidget::className() const
{
    return "msgListWidget";
}

QMetaObject *msgListWidget::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_msgListWidget(&msgListWidget::staticMetaObject);

#endif

void msgListWidget::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(KTabListBox::className(), "KTabListBox") != 0 )
	badSuperclassWarning("msgListWidget","KTabListBox");

#if QT_VERSION >= 200
    staticMetaObject();
}

void msgListWidget::staticMetaObject()
{
    if ( metaObj )
	return;
    KTabListBox::staticMetaObject();
#else

    KTabListBox::initMetaObject();
#endif

    typedef void(msgListWidget::*m1_t0)(smapiArea*);
    typedef void(msgListWidget::*m1_t1)(int);
    m1_t0 v1_0 = &msgListWidget::rescanContent;
    m1_t1 v1_1 = &msgListWidget::msgSelected;
    QMetaData *slot_tbl = new QMetaData[2];
    slot_tbl[0].name = "rescanContent(smapiArea*)";
    slot_tbl[1].name = "msgSelected(int)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    typedef void(msgListWidget::*m2_t0)(int);
    m2_t0 v2_0 = &msgListWidget::newSelection;
    QMetaData *signal_tbl = new QMetaData[1];
    signal_tbl[0].name = "newSelection(int)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = new QMetaObject( "msgListWidget", "KTabListBox",
	slot_tbl, 2,
	signal_tbl, 1 );
}

// SIGNAL newSelection
void msgListWidget::newSelection( int t0 )
{
    activate_signal( "newSelection(int)", t0 );
}
