#include "kprogress.h"
#include "smapiarea.h"


smapiArea::smapiArea(char* newname, char* newpath, word mode, word type, address* newareaaddr)
{
		debug("smapiArea::smapiArea");

    name.sprintf(newname);
    path.sprintf(newpath);
    char* foo = (char*) malloc(255); // *** remove this, use QString. somehow
    strcpy(foo, path);
    
    harea = MsgOpenArea((unsigned char*)foo, mode, type);
    if (harea != 0) {
    		debug("area open");
        areaaddress = newareaaddr;
    } else {
	    	debug("area: %s", foo);
    		fatal("msgapierr:%d", msgapierr); // *** make this nice
				// #define MERR_NONE   0           /* No error  */
				//#define MERR_BADH   1           /* Invalid handle passed to function */
				//#define MERR_BADF   2           /* Invalid or corrupted file */
				//#define MERR_NOMEM  3           /* Not enough memory for specified operation */
				//#define MERR_NODS   4           /* Maybe not enough disk space for operation */
				//#define MERR_NOENT  5           /* File/message does not exist */
				//#define MERR_BADA   6           /* Bad argument passed to msgapi function */
				//#define MERR_EOPEN  7           /* Couldn't close - messages still open */
    }
}



smapiArea::~smapiArea()
{
    MsgCloseArea(harea);
}




QString smapiArea::getName()
{
    return QString(name);
}


QString smapiArea::getPath()
{
    return QString(path);
}



UMSGID smapiArea::msgNum2UmsgId(int num)
{
    debug("UMSGID smapiArea::MsgNum2UmsgId(int num):%d", num);
    return MsgMsgnToUid(harea, (dword)num);
}



int smapiArea::getLastRead()
{
    return lastread;
}



int smapiArea::getAreaSize()
{
		if (MsgGetNumMsg(harea) != (dword)-1) {
		    debug("MsgGetMsgNum: %d",(int)MsgGetNumMsg(harea));
				return (int)MsgGetNumMsg(harea);
		} else {
				return 0;
		}
}



address *smapiArea::getAddress()
{
    return areaaddress;
}



HAREA smapiArea::getHAREA()
{
    return harea;
}


void smapiArea::setLastRead(UMSGID newlastread)
{
    lastread = newlastread;
}

















