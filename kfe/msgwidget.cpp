/*
 *   kfe - a fido message editor
 *   Copyright (C) 1998  Michael Espey
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <qfile.h> 
#include <qwidget.h>
#include <qfontmet.h> 
#include <stdlib.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qkeycode.h>
#include <qmsgbox.h> 
#include <kapp.h>

#include "msgwidget.h"

msgWidget::msgWidget(QWidget *parent, const char *name)
    : QWidget(parent, name)
{

    QColor col;
    col.setHsv(0, 0, 255);
    
    lfrom = new QLabel("From:", this);
    lfrom->setGeometry(1, 1, 30, 20);
    lfrom->setAlignment(AlignRight);
    from = new QLabel("Testname", this);
    from->setGeometry(50, 0, 170, 20);
//    lfrom->setPen(col);
    
    lto = new QLabel("To:", this);
    lto->setGeometry(5, 25, 40, 20);
    lto->setAlignment(AlignRight);
    to = new QLabel("Testto", this);
    to->setGeometry(50, 25, 170, 20);

    lsubject = new QLabel("Subject:", this);
    lsubject->setGeometry(5, 45, 40, 20);
    lsubject->setAlignment(AlignRight);
    subject = new QLabel("Subject:", this);
    subject->setGeometry(50, 45, 300, 20);

    body = new QMultiLineEdit(this, "test");
    body->setGeometry(0, 60, parent->width(), (parent->height()-110));
    body->setText("test\ntest2\rtest3");

    
}


msgWidget::~msgWidget()
{
/*    delete dispFont;
    delete pixmap;
    delete metrics;
    delete scrollV;
    delete scrollH;
    */
}





void msgWidget::showMsg(f_message* item)
{
        
    from->setText(item->getFrom());
    to->setText(item->getTo());
    subject->setText(item->getSubject());
    body->setText(item->getBody());
}



/*
 void HexFile::keyPressEvent (QKeyEvent* e) {
 int ox=curx;
 int oy=cury;
 int ol=lineoffset;
 bool changed = false;
 int or=relcur;
 int key = e->ascii();
 if (sideEdit == LEFT) {
 if ((key>='a' && key<='f') ||
 (key>='A' && key<='F') ||
 (key>='0' && key<='9')) {

 int r =(unsigned char)hexdata[cury*16+curx+lineoffset];

 if (relcur)
 hexdata[cury*16+curx+lineoffset] = r & 0xf0 | hexvalue(key);
 else
 hexdata[cury*16+curx+lineoffset] = r & 0x0f | hexvalue(key) << 4;

 relcur++;
 if (relcur==2) {
 relcur = 0;
 curx++;
 }
 } else
	    relcur = 0;
    } else if (key && e->key()<0x100) {
	hexdata[cury*16+curx+lineoffset] = key;
	modified = changed = true;

	curx++;
    }
    key = e->key();
    switch (key) {
    case Key_Right:
	curx++;
	break;
    case Key_Left:
	curx--;
	break;
    case Key_Up:
	cury--;
	break;
    case Key_Down:
	cury++;
	break;
    case Key_Next:
	scrollV->addPage();
	break;
    case Key_Prior:
	scrollV->subtractPage();
	break;
    case Key_Tab:
    case Key_Backtab:
	changed=true;
	break;
    }
    if (curx<0) {
	if (lineoffset+cury>0) {
	    curx=15;
	    cury--;
	} else 
	    curx=0;
    }
    if (curx>15) {
	curx=0;
	cury++;
    }
    if (cury<0) {
	cury=0;
	if (lineoffset>=16) {
	    lineoffset-=16;
	}
    }
    
    if ((unsigned)(curx + lineoffset + cury *16) >= hexdata.size()) {
	curx = ox;
	cury = oy;
	lineoffset = ol;
	relcur = or;
    }
    if (curx != ox || cury != oy || changed || or!=relcur) {
	fillPixmap();
	repaint( false );
	return;
    }
    
    e->ignore();
    }
    

    */

