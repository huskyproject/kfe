####### kdevelop will overwrite this part!!! (begin)##########
CXXFLAGS = -O0 -g1 -Wall 
LDFLAGS = 
kfe_SOURCES = msgattributes.cpp attribbar.cpp address.cpp composewidget.cpp composeview.cpp arealistwidget.cpp smapimsg.cpp ksmapi.cpp smapiarea.cpp kfetoplevel.cpp msglistwidget.cpp msgwidget.cpp main.cpp 
kfe_LDADD   = -lfidoconfig  -lsmapilnx  -lkfile -lkfm -lkdeui -lkdecore -lqt -lXext -lX11 $(LIBSOCKET)

SUBDIRS = docs 

EXTRA_DIST = main.cpp resource.h kfe.kdelnk kfe.xpm mini-kfe.xpm kfetoplevel.h arealistwidget.h ksmapi.h smapimsg.h smapiarea.h msglistwidget.h msgwidget.h msgwidget.cpp msglistwidget.cpp kfetoplevel.cpp smapiarea.cpp ksmapi.cpp smapimsg.cpp arealistwidget.cpp composeview.h composeview.cpp composewidget.h composewidget.cpp address.cpp address.h attribbar.cpp attribbar.h msgattributes.cpp msgattributes.h 

install-data-local:
	$(mkinstalldirs) $(kde_appsdir)/Applications/
	$(INSTALL_DATA) kfe.kdelnk $(kde_appsdir)/Applications/kfe.kdelnk
	$(mkinstalldirs) $(kde_icondir)/
	$(INSTALL_DATA) kfe.xpm $(kde_icondir)/kfe.xpm
	$(mkinstalldirs) $(kde_minidir)/
	$(INSTALL_DATA) mini-kfe.xpm $(kde_minidir)/kfe.xpm

uninstall-local:
	-rm -f $(kde_appsdir)/Applications/kfe.kdelnk
	-rm -f $(kde_icondir)/kfe.xpm
	-rm -f $(kde_minidir)/kfe.xpm

####### kdevelop will overwrite this part!!! (end)############
# this 10 paths are KDE specific. Use them:
# kde_htmldir       Where your docs should go to. (contains lang subdirs)
# kde_appsdir       Where your application file (.kdelnk) should go to. 
# kde_icondir       Where your icon should go to.
# kde_minidir       Where your mini icon should go to.
# kde_datadir       Where you install application data. (Use a subdir)
# kde_locale        Where translation files should go to.(contains lang subdirs)
# kde_cgidir        Where cgi-bin executables should go to.
# kde_confdir       Where config files should go to.
# kde_mimedir       Where mimetypes should go to.
# kde_toolbardir    Where general toolbar icons should go to.
# kde_wallpaperdir  Where general wallpapers should go to.

# set the include path for X, qt and KDE
INCLUDES= $(all_includes)
# claim, which subdirectories you want to install
# you can add here more. This one gets installed 
bin_PROGRAMS = kfe 

kfe_METASOURCES = USE_AUTOMOC

# the library search path. 
kfe_LDFLAGS = $(all_libraries) $(KDE_RPATH)

# them while "make clean", use CLEANFILES
DISTCLEANFILES = $(kfe_METASOURCES)

# make messages.po. Move this one to ../po/ and "make merge" in po
# the -x is for skipping messages already translated in kdelibs
messages:
	$(XGETTEXT) -C -ki18n -x $(includedir)/kde.pot $(kfe_SOURCES) && mv messages.po ../po/kfe.pot






