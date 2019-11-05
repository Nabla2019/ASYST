#
#	RLM Activation Pro Kit makefile - Windows systems.
#
#	You should only have to edit the first definition (ISV) to
#	correspond to your ISV name.  If you have a demo version of
#	RLM, do not change the ISV line below.
#

#
#	Beginning of customer-edited definitions
#

ISV = demo

#
#	Set this variable to your webserver htdocs location, if
#	you want this makefile to be able to install the activation
#	files on your webserver
#

#  Default location for windows
HTDOCS = "C:\xampp\htdocs"

#
#	If you are building a license generator that supports
#	ISV-defined hostids, edit the next 2 variables.
#
#	MYSQLDEV is the location of the MySQL Connector/C kit
#	ISV_DEF_HOSTID_OBJS is your object files that implement your
#		ISV-defined hostid.
#

MYSQLDEV = 
ISV_DEF_HOSTID_OBJS =

#
#	End of customer-edited definitions
#


all: install

LD = link

LDFLAGS = /nologo /nodefaultlib /ignore:4089

LIBRARY = rlmclient.lib

XTRALIB = ws2_32.lib Advapi32.lib Gdi32.lib User32.lib netapi32.lib \
	  kernel32.lib oldnames.lib shell32.lib Secur32.lib wbemuuid.lib \
	  comsupp.lib comsuppw.lib ole32.lib oleaut32.lib libcmt.lib

install:	$(ISV).gen setup
	if exist $(HTDOCS)\actpro_setup rmdir /s /q $(HTDOCS)\actpro_setup
	xcopy actpro_setup $(HTDOCS)\actpro_setup /s /i

setup:
	copy $(ISV).gen actpro_setup
	
$(LIBRARY):
	@echo ""
	@echo "If you want to build a license generator with an ISV-defined"
	@echo "hostid, you first need to copy the rlm library from your"
	@echo "rlm kit to this directory.  Be sure to copy the rlm library"
	@echo "from the correct architecture."
	@echo ""
	exit 1

$(ISV).gen:
	@echo ""
	@echo "Before you begin, you must copy your Generator"
	@echo "settings file from your rlm kit."
	@echo ""
	@echo "If you don't have a generator settings file, create it"
	@echo "using the following instructions (in an installed RLM kit "
	@echo "on any platform):"
	@echo ""
	@echo "    rlmsign -generator"
	@echo ""
	@echo "then copy it to this directory."
	@echo ""
	exit 1

$(ISV)_mklic.exe:	$(LIBRARY) $(ISV_DEF_HOSTID_OBJS)
	$(LD) $(LDFLAGS) /out:$(ISV)_mklic.exe rlm_actpro_mklic.obj \
		$(ISV_DEF_HOSTID_OBJS) rlm_act_doit.obj rlm_act_mysql.obj \
		$(LIBRARY) $(MYSQLDEV)/lib/mysqlclient.lib $(XTRALIB)
	@copy $(ISV)_mklic.exe actpro_setup\$(ISV)_mklic
	
clean:;	del $(ISV)_mklic.exe
