/***************************************************************************
                          address.h  -  description                              
                             -------------------                                         
    begin                : Sat Apr 3 1999                                           
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


#ifndef ADDRESS_H
#define ADDRESS_H

#include <qstring.h>

/**
  *@author Michael Espey
  */

class address {

public: 
  	address();
	  ~address();
	
  	unsigned int getZone();
  	unsigned int getNet();
  	unsigned int getNode();
  	unsigned int getPoint();
    QString getDomain();

    void setZone(unsigned int newzone);
  	void setNet(unsigned int newnet);
  	void setNode(unsigned int newnode);
  	void setPoint(unsigned int newpoint);
    void setDomain(QString newdomain);

    char* toMsgId();
    char* toString();

private:
    unsigned int zone;
    unsigned int net;
    unsigned int node;
    unsigned int point;
    QString domain;
};

#endif

