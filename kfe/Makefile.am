# this 10 paths are KDE specific. Use them:
# kde_htmldir       Where your docs should go to. (contains lang subdirs)
# kde_appsdir       Where your application file (.kdelnk) should go to. 
# kde_icondir       Where your icon should go to.
# kde_sounddir      Where system sounds should go to.
# kde_datadir       Where you install application data. (Use a subdir)
# kde_locale        Where translation files should go to.(contains lang subdirs)
# kde_cgidir        Where cgi-bin executables should go to.
# kde_confdir       Where config files should go to.
# kde_mimedir       Where mimetypes should go to.
# kde_toolbardir    Where general toolbar icons should go to.
# kde_wallpaperdir  Where general wallpapers should go to.

APPSDIR = $(kde_appsdir)/Utilities
INCLUDES= $(all_includes)

# SUBDIRS = 

bin_PROGRAMS = kfe

kfe_SOURCES = msglistwidget.cpp arealistwidget.cpp msgwidget.cpp \
smapiarea.cpp smapimsg.cpp ksmapi.cpp kfetoplevel.cpp main.cpp

kfe_METASOURCES = USE_AUTOMOC
kfe_LDFLAGS = $(all_libraries) $(KDE_RPATH)

kfe_LDADD   = -lkfm -lkdeui -lkdecore -lqt -lXext -lX11 $(LIBSOCKET)

DISTCLEANFILES = $()

install-data-local: 
	$(mkinstalldirs) $(APPSDIR)
	$(INSTALL_DATA) kfe.kdelnk $(APPSDIR)

uninstall-local:
	-rm -f $(APPSDIR)/kfe.kdelnk

