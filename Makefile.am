## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

update_indicatordocdir = ${prefix}/doc/update_indicator
update_indicatordoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(update_indicatordoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(update_indicatordocdir)


AM_VALAFLAGS = -g \
	--save-temps 
