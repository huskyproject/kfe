/***************************************************************************
                          main.cpp  -  description                              
                             -------------------                                         
    begin                : Sat Mar 13 07:00:53 GMT 1999
                                           
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


#include "kfetoplevel.h"
 
int main(int argc, char* argv[])
{
    KApplication app(argc,argv,"kfe");
 
    if (app.isRestored()) {
        RESTORE(KkfeTopLevel);
    } else {
        KkfeTopLevel* kfe = new KkfeTopLevel();
        kfe->show();
    }  
    return app.exec();
}  








