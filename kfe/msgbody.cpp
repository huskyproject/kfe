/***************************************************************************
                          msgbody.cpp  -  description                              
                             -------------------                                         
    begin                : Sat Apr 10 1999                                           
    copyright            : (C) 1999 by Michael Espey                         
    email                : tracer@camouflage.hh.uunet.de                                     
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   * 
 *                                                                         *
 ***************************************************************************/


#include "msgbody.h"

#include <qapplication.h>

msgBody::msgBody()
{
;
}



msgBody::~msgBody()
{
}

	
void msgBody::append(msgLine *newmsgline)
{
    debug("void msgBody::append(msgLine *newmsgline)");
    bodylist.append(newmsgline);
    debug("/void msgBody::append(msgLine *newmsgline)");
}








