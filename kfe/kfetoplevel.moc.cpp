/****************************************************************************
** KkfeTopLevel meta object code from reading C++ file 'kfetoplevel.h'
**
** Created: Mon Jan 25 23:16:16 1999
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
    typedef void(KkfeTopLevel::*m1_t5)();
    typedef void(KkfeTopLevel::*m1_t6)();
    typedef void(KkfeTopLevel::*m1_t7)();
    typedef void(KkfeTopLevel::*m1_t8)();
    typedef void(KkfeTopLevel::*m1_t9)();
    typedef void(KkfeTopLevel::*m1_t10)(int);
    typedef void(KkfeTopLevel::*m1_t11)(int);
    typedef void(KkfeTopLevel::*m1_t12)();
    typedef void(KkfeTopLevel::*m1_t13)();
    m1_t0 v1_0 = &KkfeTopLevel::cmFileQuit;
    m1_t1 v1_1 = &KkfeTopLevel::cmAreaFirst;
    m1_t2 v1_2 = &KkfeTopLevel::cmAreaNext;
    m1_t3 v1_3 = &KkfeTopLevel::cmAreaPrev;
    m1_t4 v1_4 = &KkfeTopLevel::cmAreaLast;
    m1_t5 v1_5 = &KkfeTopLevel::cmMessageFirst;
    m1_t6 v1_6 = &KkfeTopLevel::cmMessageNext;
    m1_t7 v1_7 = &KkfeTopLevel::cmMessagePrev;
    m1_t8 v1_8 = &KkfeTopLevel::cmMessageLast;
    m1_t9 v1_9 = &KkfeTopLevel::cmUpdateAreaList;
    m1_t10 v1_10 = &KkfeTopLevel::cmUpdateMsgList;
    m1_t11 v1_11 = &KkfeTopLevel::cmUpdateMsg;
    m1_t12 v1_12 = &KkfeTopLevel::readConfig;
    m1_t13 v1_13 = &KkfeTopLevel::writeConfig;
    QMetaData *slot_tbl = new QMetaData[14];
    slot_tbl[0].name = "cmFileQuit()";
    slot_tbl[1].name = "cmAreaFirst()";
    slot_tbl[2].name = "cmAreaNext()";
    slot_tbl[3].name = "cmAreaPrev()";
    slot_tbl[4].name = "cmAreaLast()";
    slot_tbl[5].name = "cmMessageFirst()";
    slot_tbl[6].name = "cmMessageNext()";
    slot_tbl[7].name = "cmMessagePrev()";
    slot_tbl[8].name = "cmMessageLast()";
    slot_tbl[9].name = "cmUpdateAreaList()";
    slot_tbl[10].name = "cmUpdateMsgList(int)";
    slot_tbl[11].name = "cmUpdateMsg(int)";
    slot_tbl[12].name = "readConfig()";
    slot_tbl[13].name = "writeConfig()";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    slot_tbl[1].ptr = *((QMember*)&v1_1);
    slot_tbl[2].ptr = *((QMember*)&v1_2);
    slot_tbl[3].ptr = *((QMember*)&v1_3);
    slot_tbl[4].ptr = *((QMember*)&v1_4);
    slot_tbl[5].ptr = *((QMember*)&v1_5);
    slot_tbl[6].ptr = *((QMember*)&v1_6);
    slot_tbl[7].ptr = *((QMember*)&v1_7);
    slot_tbl[8].ptr = *((QMember*)&v1_8);
    slot_tbl[9].ptr = *((QMember*)&v1_9);
    slot_tbl[10].ptr = *((QMember*)&v1_10);
    slot_tbl[11].ptr = *((QMember*)&v1_11);
    slot_tbl[12].ptr = *((QMember*)&v1_12);
    slot_tbl[13].ptr = *((QMember*)&v1_13);
    metaObj = new QMetaObject( "KkfeTopLevel", "KTMainWindow",
	slot_tbl, 14,
	0, 0 );
}
