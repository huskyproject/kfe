#include <kapp.h>
#include <ktopwidget.h>

#include "kfetoplevel.h"


int main(int argc, char *argv[])
{
  KApplication app(argc, argv);

  KkfeTopLevel *toplevel=0;

  if (app.isRestored())
    RESTORE(KkfeTopLevel)
  else {
    // no session management: just create one window
    toplevel = new KkfeTopLevel();
    toplevel->show();
  }
  toplevel->show();

  return app.exec();
}