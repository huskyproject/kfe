/****************************************************************************
** areaListWidget meta object code from reading C++ file 'arealistwidget.h'
**
** Created: Fri Jan 15 21:54:17 1999
**      by: The Qt Meta Object Compiler ($Revision$)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "arealistwidget.h"
#include <qmetaobject.h>


const char *areaListWidget::className() const
{
    return "areaListWidget";
}

QMetaObject *areaListWidget::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_areaListWidget(&areaListWidget::staticMetaObject);

#endif

void areaListWidget::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(KTabListBox::className(), "KTabListBox") != 0 )
	badSuperclassWarning("areaListWidget","KTabListBox");

#if QT_VERSION >= 200
    staticMetaObject();
}

void areaListWidget::staticMetaObject()
{
    if ( metaObj )
	return;
    KTabListBox::staticMetaObject();
#else

    KTabListBox::initMetaObject();
#endif

    typedef void(areaListWidget::*m1_t0)(int);
    typedef void(areaListWidget::*m1_t1)(Ksmapi*);
    m1_t0 v1_0 = &areaListWidget::areaSelected;
    m1_t1 v1_1 = &areaListWidget::updateContent;
    QMetaData *slot_tbl = new QMetaData[2];
    slot_tbl[0].name = "areaSelected(int)";
    slot_tbl[1].name = "updateContent(Ksmapi*)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    typedef void(areaListWidget::*m2_t0)(int);
    m2_t0 v2_0 = &areaListWidget::newSelection;
    QMetaData *signal_tbl = new QMetaData[1];
    signal_tbl[0].name = "newSelection(int)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = new QMetaObject( "areaListWidget", "KTabListBox",
	slot_tbl, 2,
	signal_tbl, 1 );
}

// SIGNAL newSelection
void areaListWidget::newSelection( int t0 )
{
    activate_signal( "newSelection(int)", t0 );
}
