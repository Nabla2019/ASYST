#
#	RLM Binary Kit makefile - Windows systems.
#
#	You should only have to edit the first definition (ISV) to
#	correspond to your ISV name.  If you have a demo version of
#	RLM, do not change the ISV line below.
#
#	If you have defined an ISV-defined license transfer module,
#	you need to define the object file name here as well.
#

#
#	Beginning of customer-edited definitions
#

ISV = demo

#
#	If you are not using ISV-defined license transfer, the above
#	definitions are the only ones you need to edit.  If you are
#	using ISV-defined transfer, there are more definitions below
#
#
#	Do NOT edit the next 5 lines
#
EXECS = rlmgenkeys.exe rlc.exe rlmclient.exe rlmclientd.exe rlmsign.exe \
	$(ISV).set $(ISV).exe rlmstat.exe \
	actpro_demo.exe rlmverify.exe roam_example.exe rlmgen.exe

all: $(EXECS) $(DLL) example.lic

#
#	If you want to support license transfer from another license
#	manager, put the definitions of the interface modules here.
#
#	Put your ISV-defined transfer module object/source/library file names
#	here, plus add any rules to compile/link them.
#
#	ISV_XFER_OBJ: the object for your isv transfer definitions.
#	ISV_XFER_SRC: source to the isv transfer defintions
#	ISV_XFER_LIBS: any libraries required for your ISV-transfer LM
#
ISV_XFER_SRC =
ISV_XFER_OBJ =
ISV_XFER_LIBS =
#$(ISV_XFER_OBJ):	$(ISV_XFER_SRC)
#	any special compile rules go here, if necessary

#
#	For example, to build the rlm-rlm example ISV transfer module,
#	set the above definitions as follows:
#
#	ISV_XFER_SRC = ..\examples\rlm_transfer.c
#	ISV_XFER_OBJ = rlm_transfer.o
#	ISV_XFER_LIBS =			# No libs needed, since it's all in
#					# the standard rlm libraries.  You
#					# will need the libraries from the
#					# other license manager here.
#	$(ISV_XFER_OBJ):	$(ISV_XFER_SRC)
#		cl $(CFLAGS) /MT /c $(ISV_XFER_SRC)
#

#
#	End of customer-edited definitions
#

PLATFORM = x86_w3

LD = link

LDFLAGS = /nologo /nodefaultlib /ignore:4089 /nxcompat

CFLAGS = /nologo /D_CRT_SECURE_NO_DEPRECATE

CLIENT_LIB = rlmclient.lib

SERVER_LIB = isv_server.lib

RLMID1LIBS = rlmid1.lib

!if "$(PLATFORM)" == "x86_w4" || "$(PLATFORM)" == "x64_w4"
XXTRALIB = libvcruntimed.lib libucrtd.lib
!else
XXTRALIB =
!endif

XTRALIB = $(RLMID1LIBS) ws2_32.lib Advapi32.lib Gdi32.lib \
			User32.lib netapi32.lib kernel32.lib oldnames.lib \
			shell32.lib wbemuuid.lib comsupp.lib comsuppw.lib \
			ole32.lib oleaut32.lib libcmt.lib winhttp.lib $(XXTRALIB)

OBJS = rlmclient.obj rlm_isv_config.obj roam_example.obj rehost_example.obj

KEYOBJS = rlm_privkey.obj rlm_pubkey.obj rlm_privkey_md.obj rlm_pubkey_md.obj 

RESOURCEFILE = rlm.res

VER = 1233

DLL = rlm$(VER).dll

DLLLIB = rlm$(VER).lib

!if "$(PLATFORM)" == "x64_w2" || "$(PLATFORM)" == "x64_w3" || "$(PLATFORM)" == "x64_w4"
MACHINE = x64
!else
MACHINE = x86
!endif

$(CLIENT_LIB):	..\src\rlm_privkey.c ..\src\rlm_pubkey.c rlm_isv_config.obj
	nmake /nologo $(KEYOBJS)
	lib /nologo $(CLIENT_LIB) rlm_pubkey.obj rlm_privkey.obj rlm_isv_config.obj
	lib /nologo rlmclient_md.lib rlm_pubkey_md.obj rlm_privkey_md.obj rlm_isv_config_md.obj
	lib /nologo rlmclient_mdd.lib rlm_pubkey_mdd.obj rlm_privkey_mdd.obj rlm_isv_config_mdd.obj
	lib /nologo rlmclient_mtd.lib rlm_pubkey_mtd.obj rlm_privkey_mtd.obj rlm_isv_config_mtd.obj

..\src\rlm_privkey.c:
	@echo ""
	@echo "******************************************************"
	@echo "Your public/private key pair does not exist in ../src"
	@echo "We will generate them for you now..."
	@echo ""
	@echo "If you have previously generated these key files,"
	@echo "place them in ../src now and re-run this make"
	@echo "******************************************************"
	@echo ""
	cd ..\src 
	..\$(PLATFORM)\rlmgenkeys
	cd ..\$(PLATFORM)
	nmake /nologo rlm_pubkey.obj
	nmake /nologo rlm_privkey.obj

hosted_activation_demo_keys:
	if exist ..\src\rlm_pubkey.c del rlm_pubkey.c
	if exist ..\src\rlm_privkey.c del rlm_privkey.c
	copy ..\examples\hosted_demo_pubkey.c ..\src\rlm_pubkey.c
	copy ..\examples\hosted_demo_privkey.c ..\src\rlm_privkey.c

rehost_example.obj:	..\examples\rehost_example.c
	cl $(CFLAGS) /MT /I..\src /c ..\examples\rehost_example.c

rlm_pubkey.obj:	..\src\rlm_pubkey.c
	cl $(CFLAGS) /MT /c ..\src\rlm_pubkey.c
	cl $(CFLAGS) /MD /c /Forlm_pubkey_md.obj ..\src\rlm_pubkey.c
	cl $(CFLAGS) /MDd /c /Forlm_pubkey_mdd.obj ..\src\rlm_pubkey.c
	cl $(CFLAGS) /MTd /c /Forlm_pubkey_mtd.obj ..\src\rlm_pubkey.c

rlm_privkey.obj:	..\src\rlm_privkey.c
	cl $(CFLAGS) /MT /c ..\src\rlm_privkey.c
	cl $(CFLAGS) /MD /c /Forlm_privkey_md.obj ..\src\rlm_privkey.c
	cl $(CFLAGS) /MDd /c /Forlm_privkey_mdd.obj ..\src\rlm_privkey.c
	cl $(CFLAGS) /MTd /c /Forlm_privkey_mtd.obj ..\src\rlm_privkey.c

rlm_isv_config.obj:	..\src\rlm_isv_config.c ..\src\license_to_run.h
	cl $(CFLAGS) /MT /c ..\src\rlm_isv_config.c
	cl $(CFLAGS) /MD /c /Forlm_isv_config_md.obj ..\src\rlm_isv_config.c
	cl $(CFLAGS) /MDd /c /Forlm_isv_config_mdd.obj ..\src\rlm_isv_config.c
	cl $(CFLAGS) /MTd /c /Forlm_isv_config_mtd.obj ..\src\rlm_isv_config.c

rlmclient.obj:	..\examples\rlmclient.c
	cl $(CFLAGS) /MT /I..\src /c ..\examples\rlmclient.c

roam_example.obj:	..\examples\roam_example.c
	cl $(CFLAGS) /MT /I..\src /c ..\examples\roam_example.c

#
# Note: No dependency on $(CLIENT_LIB) for rlmgenkeys so that we
#	can get the key pair source files created first.
#
rlmgenkeys.exe:
	$(LD) $(LDFLAGS) /out:rlmgenkeys.exe rlmgenkeys.obj \
		$(CLIENT_LIB) $(XTRALIB) $(RESOURCEFILE)

rlc.exe:	$(CLIENT_LIB)  $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:rlc.exe rlc.obj rlmact.obj rlm_genlic.obj \
				$(CLIENT_LIB) $(XTRALIB)  $(RESOURCEFILE)
	
rlmgen.exe:	$(CLIENT_LIB)  $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:rlmgen.exe rlc.obj rlmgen.obj rlm_genlic.obj \
				$(CLIENT_LIB) $(XTRALIB)  $(RESOURCEFILE)
	
actpro_demo.exe:	actpro_demo.obj $(CLIENT_LIB) $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:actpro_demo.exe actpro_demo.obj \
		$(CLIENT_LIB) $(SERVER_LIB) $(XTRALIB) $(RESOURCEFILE)

actpro_demo.obj:     ..\examples\actpro_demo.c
	cl $(CFLAGS) /MT /I..\src /c ..\examples\actpro_demo.c

rehost_example.exe:	rehost_example.obj $(CLIENT_LIB) $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:rehost_example.exe rehost_example.obj \
		$(CLIENT_LIB) $(XTRALIB) $(RESOURCEFILE)

rlmclient.exe:	rlmclient.obj $(CLIENT_LIB) $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:rlmclient.exe rlmclient.obj \
		$(CLIENT_LIB) $(XTRALIB) $(RESOURCEFILE)

roam_example.exe:	roam_example.obj $(CLIENT_LIB) $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:roam_example.exe roam_example.obj \
		$(CLIENT_LIB) $(XTRALIB) $(RESOURCEFILE)

rlmclientd.exe:	rlmclient.obj $(DLL) $(RESOURCEFILE)
	$(LD) /nologo /ignore:4089 /out:rlmclientd.exe rlmclient.obj $(DLLLIB) \
		$(RESOURCEFILE)

rlmsign.exe:	$(CLIENT_LIB) $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:rlmsign.exe rlmsign.obj $(CLIENT_LIB) $(XTRALIB) \
		$(RESOURCEFILE)
			
$(ISV).set:	$(CLIENT_LIB) rlmsign.exe
	rlmsign -settings
	
$(ISV).exe:	$(CLIENT_LIB) $(ISV_XFER_OBJ) $(ISV_XFER_LIBS) $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:$(ISV).exe isv_main.obj $(ISV_XFER_OBJ) \
		$(ISV_XFER_LIBS) $(CLIENT_LIB) $(SERVER_LIB) $(XTRALIB) \
		$(RESOURCEFILE)
	
rlmverify.exe:	$(CLIENT_LIB) $(RESOURCEFILE)
	$(LD) $(LDFLAGS) /out:rlmverify.exe rlmverify.obj \
		$(CLIENT_LIB) $(SERVER_LIB) $(XTRALIB) $(RESOURCEFILE)
	
example.lic:	rlm_pubkey.obj rlm_privkey.obj
	rlmsign example.lic

$(DLL):	rlmclient.lib $(RESOURCEFILE)
	copy rlmclient.lib rlmclienttemp.lib
	lib /nologo /remove:rlm_sign_lf.obj rlmclienttemp.lib
	lib /nologo /remove:rlm_sign_license.obj rlmclienttemp.lib
	lib /nologo /remove:rlm_privkey.obj rlmclienttemp.lib
	link /nologo /ignore:4001 /ignore:4068 /machine:$(MACHINE) /dll \
		/out:$(DLL) /def:rlm.def rlmclienttemp.lib \
		/nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib $(XTRALIB) \
		$(RESOURCEFILE)
	del rlmclienttemp.lib
	
$(OBJS):	..\src\license.h

rlm_pubkey.obj:		..\src\rlm_pubkey.c

rlm_privkey.obj:	..\src\rlm_privkey.c

rlmstat.exe:
	nmake /nologo links

links:
	copy rlmutil.exe rlmdebug.exe
	copy rlmutil.exe rlmdown.exe
	copy rlmutil.exe rlmhostid.exe
	copy rlmutil.exe rlmnewlog.exe
	copy rlmutil.exe rlmremove.exe
	copy rlmutil.exe rlmreread.exe
	copy rlmutil.exe rlmstat.exe
	copy rlmutil.exe rlmswitch.exe
	copy rlmutil.exe rlmswitchr.exe

clean:
	if exist $(ISV).exe del $(ISV).exe
	if exist $(ISV).set del $(ISV).set
	if exist actpro_demo.obj del actpro_demo.obj
	if exist rlmclient.obj del rlmclient.obj
	if exist rlmclientd.obj del rlmclientd.obj
	if exist rlm_pubkey.obj del rlm_pubkey*.obj
	if exist rlm_privkey.obj del rlm_privkey*.obj
	if exist rlm_isv_config.obj del rlm_isv_config*.obj
	if exist rlmgenkeys.exe del rlmgenkeys.exe
	if exist rlmclient.exe del rlmclient.exe
	if exist rlmclientd.exe del rlmclientd.exe
	if exist rlmsign.exe del rlmsign.exe
	if exist rlmdebug.exe del rlmdebug.exe
	if exist rlmdown.exe del rlmdown.exe
	if exist rlmhostid.exe del rlmhostid.exe
	if exist rlmnewlog.exe del rlmnewlog.exe
	if exist rlmremove.exe del rlmremove.exe
	if exist rlmreread.exe del rlmreread.exe
	if exist rlmstat.exe del rlmstat.exe
	if exist rlmswitch.exe del rlmswitch.exe
	if exist rlmswitchr.exe del rlmswitchr.exe
	if exist $(DLL) del $(DLL)
	if exist rlm.exp del rlm.exp
	if exist rlm.lib del rlm.lib
