/****************************************************************************
** areaListWidget meta object code from reading C++ file 'arealistwidget.h'
**
** Created: Thu Dec 24 20:14:48 1998
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

    typedef void(areaListWidget::*m2_t0)(f_area*);
    m2_t0 v2_0 = &areaListWidget::newSelection;
    QMetaData *signal_tbl = new QMetaData[1];
    signal_tbl[0].name = "newSelection(f_area*)";
    signal_tbl[0].ptr = *((QMember*)&v2_0);
    metaObj = new QMetaObject( "areaListWidget", "KTabListBox",
	0, 0,
	signal_tbl, 1 );
}

#include <qobjectdefs.h>
#if QT_VERSION >= 141
// newer implementation
#include <qsignalslotimp.h>
#else
// for late-model 1.x header files
#if !defined(Q_MOC_CONNECTIONLIST_DECLARED)
#define Q_MOC_CONNECTIONLIST_DECLARED
#include <qlist.h>
Q_DECLARE(QListM,QConnection);
Q_DECLARE(QListIteratorM,QConnection);
#endif
#endif

// SIGNAL newSelection
void areaListWidget::newSelection( f_area* t0 )
{
    QConnectionList *clist = receivers("newSelection(f_area*)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef RT0 *PRT0;
    typedef void (QObject::*RT1)(f_area*);
    typedef RT1 *PRT1;
    RT0 r0;
    RT1 r1;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = *((PRT0)(c->member()));
		(object->*r0)();
		break;
	    case 1:
		r1 = *((PRT1)(c->member()));
		(object->*r1)(t0);
		break;
	}
    }
}
