/***************************************************************************
                          msgline.cpp  -  description                              
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


#include "msgline.h"
#include <qapplication.h> // *** remove after testing

msgLine::msgLine(int newlinetype, int newquotelevel, QString newline)
{
    debug("msgLine::msgLine(int newlinetype, int newquotelevel, const char *newline)");
    linetype = newlinetype;
    quotelevel = newquotelevel;
    line = newline;
    char* foo = new char[100];
    sprintf(foo, line);
    debug("msgline: %s", foo);
}



msgLine::~msgLine()
{
}

	
	
int msgLine::getType()
{
    return linetype;
}



int msgLine::getQuoteLevel()
{
    return quotelevel;
}



QString msgLine::getLine()
{
    return line;
}






