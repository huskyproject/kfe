/****************************************************************************
** msgWidget meta object code from reading C++ file 'msgwidget.h'
**
** Created: Fri Dec 25 21:21:53 1998
**      by: The Qt Meta Object Compiler ($Revision$)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 2
#elif Q_MOC_OUTPUT_REVISION != 2
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "msgwidget.h"
#include <qmetaobject.h>


const char *msgWidget::className() const
{
    return "msgWidget";
}

QMetaObject *msgWidget::metaObj = 0;


#if QT_VERSION >= 200
static QMetaObjectInit init_msgWidget(&msgWidget::staticMetaObject);

#endif

void msgWidget::initMetaObject()
{
    if ( metaObj )
	return;
    if ( strcmp(QMultiLineEdit::className(), "QMultiLineEdit") != 0 )
	badSuperclassWarning("msgWidget","QMultiLineEdit");

#if QT_VERSION >= 200
    staticMetaObject();
}

void msgWidget::staticMetaObject()
{
    if ( metaObj )
	return;
    QMultiLineEdit::staticMetaObject();
#else

    QMultiLineEdit::initMetaObject();
#endif

    typedef void(msgWidget::*m1_t0)(f_message*);
    m1_t0 v1_0 = &msgWidget::showMsg;
    QMetaData *slot_tbl = new QMetaData[1];
    slot_tbl[0].name = "showMsg(f_message*)";
    slot_tbl[0].ptr = *((QMember*)&v1_0);
    metaObj = new QMetaObject( "msgWidget", "QMultiLineEdit",
	slot_tbl, 1,
	0, 0 );
}
