/***************************************************************************
                          address.cpp  -  description                              
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

#include <time.h>
#include "address.h"

address::address()
{
}



address::~address()
{
}



unsigned int address::getZone()
{
    return zone;
}
  	
  	
  	
unsigned int address::getNet()
{
    return net;
}
  	
  	
  	
unsigned int address::getNode()
{
    return node;
}
  	
  	
  	
unsigned int address::getPoint()
{
    return point;
}



QString address::getDomain()
{
    return domain;
}



void address::setZone(unsigned int newzone)
{
    zone = newzone;
}
  	
  	
  	
void address::setNet(unsigned int newnet)
{
    net = newnet;
}
  	
  	
  	
void address::setNode(unsigned int newnode)
{
    node = newnode;
}
  	
  	
  	
void address::setPoint(unsigned int newpoint)
{
    point = newpoint;
}



void address::setDomain(QString newdomain)
{
    domain = newdomain;
}



char* address::toMsgId()
{
    debug("char* address::toMSGID()");

    char* msgid = new char[32];
    CHECK_PTR(msgid);

    // generate a more accurate MSGID later ***
    if (point != 0) {
        sprintf(msgid, "%d:%d/%d.%d %08lx", zone, net, node, point, time(NULL));
		} else {
        sprintf(msgid, "%d:%d/%d %08lx", zone, net, node, time(NULL));
    }
    return msgid;
}
