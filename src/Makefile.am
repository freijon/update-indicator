## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(datadir)/update_indicator/ui
ui_DATA = UpdateIndicator.glade


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(UPDATE_INDICATOR_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

VALAFLAGS =  \
	--pkg gtk+-3.0 --pkg gconf-2.0 --pkg appindicator3-0.1 --pkg gmodule-2.0 --pkg libnotify

bin_PROGRAMS = update_indicator

update_indicator_SOURCES = \
	config.vapi Indicate.vala GConfInterface.vala main.vala Preferences.vala UpdateChecker.vala

update_indicator_LDFLAGS = \
	-Wl,--export-dynamic

update_indicator_LDADD = $(UPDATE_INDICATOR_LIBS)


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/update_indicator
