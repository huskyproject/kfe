/***************************************************************************
                          msgline.h  -  description                              
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


#ifndef MSGLINE_H
#define MSGLINE_H

#include <qstring.h>


/**
  *@author Michael Espey
  */

class msgLine
{
public: 
  	msgLine(int newlinetype, int newquotelevel, QString newline);
	  ~msgLine();
	
	  int getType();
	  int getQuoteLevel();
	  QString getLine();
	
	  enum LineType {BODY, QUOTE, PATH, SEENY};

private:
    int linetype;
    int quotelevel;
    QString line;
};

#endif

