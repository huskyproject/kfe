/****************************************************************************
** KkfeTopLevel meta object code from reading C++ file 'kfetoplevel.h'
**
** Created: Thu Dec 24 20:20:22 1998
**      by: The Qt Meta Object Compiler ($Revision$)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "kfetoplevel.h"
#include <qmetaobject.h>


const char *KkfeTopLevel::className() const
{
    return "KkfeTopLevel";
}

QMetaObject *KkfeTopLevel::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_KkfeTopLevel(&KkfeTopLevel::staticMetaObject);

#endif

void KkfeTopLevel::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(KTMainWindow::className(), "KTMainWindow") != 0 )
	badSuperclassWarning("KkfeTopLevel","KTMainWindow");

#if QT_VERSION >= 200
    staticMetaObject();
}

void KkfeTopLevel::staticMetaObject()
{
    if ( metaObj )
	return;
    KTMainWindow::staticMetaObject();
#else

    KTMainWindow::initMetaObject();
#endif

    typedef void(KkfeTopLevel::*m1_t0)();
    typedef void(KkfeTopLevel::*m1_t1)();
    typedef void(KkfeTopLevel::*m1_t2)();
    typedef void(KkfeTopLevel::*m1_t3)();
    typedef void(KkfeTopLevel::*m1_t4)();
    typedef void(KkfeTopLevel::*m1_t5)(f_area*);
    m1_t0 v1_0 = &KkfeTopLevel::cmFileQuit;
    m1_t1 v1_1 = &KkfeTopLevel::cmViewAreas;
    m1_t2 v1_2 = &KkfeTopLevel::cmViewMessages;
    m1_t3 v1_3 = &KkfeTopLevel::cmViewStatusbar;
    m1_t4 v1_4 = &KkfeTopLevel::cmViewToolbar;
    m1_t5 v1_5 = &KkfeTopLevel::cmRescanMessages;
    QMetaData *slot_tbl = new QMetaData[6];
    slot_tbl[0].name = "cmFileQuit()";
    slot_tbl[1].name = "cmViewAreas()";
    slot_tbl[2].name = "cmViewMessages()";
    slot_tbl[3].name = "cmViewStatusbar()";
    slot_tbl[4].name = "cmViewToolbar()";
    slot_tbl[5].name = "cmRescanMessages(f_area*)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    metaObj = new QMetaObject( "KkfeTopLevel", "KTMainWindow",
	slot_tbl, 6,
	0, 0 );
}
