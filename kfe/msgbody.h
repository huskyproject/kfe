/***************************************************************************
                          msgbody.h  -  description                              
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


#ifndef MSGBODY_H
#define MSGBODY_H

#include <qlist.h>
#include "msgline.h"


/**
  *@author Michael Espey
  */

class msgBody
{
public: 
  	msgBody();
	  ~msgBody();
	
	  void append(msgLine *newmsgline);

private:
    QList<msgLine> bodylist;
};

#endif


