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

msgWidget::msgWidget(QWidget *parent, Ksmapi* newSmapi = 0)
    : QMultiLineEdit(parent, "msgWidget")
{
    smapi = newSmapi;
    setReadOnly(TRUE);
}


msgWidget::~msgWidget()
{
    ;
}


void msgWidget::updateMsg()
{
    if (smapi->getCurArea()->getMsgNum() > 0) {
        setText(smapi->getCurMsg()->getBody());
    } else {
        setText(0);
    }
}
