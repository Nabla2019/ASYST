ISV = issrs

EXECS = rehost.exe rlmIF.exe disconn_rehost.exe Offline_Activation.exe

all: $(EXECS)

MACHINE = x86

LD = link
IF = ifort

LDFLAGS = /nologo /nodefaultlib /ignore:4089 /nxcompat
IFFLAGS = -nologo -debug:full -Od

CFLAGS = /nologo /D_CRT_SECURE_NO_DEPRECATE

CLIENT_LIB = rlmclient.lib

SERVER_LIB = isv_server.lib

XTRALIB = ws2_32.lib Advapi32.lib Gdi32.lib \
			User32.lib netapi32.lib kernel32.lib oldnames.lib \
			shell32.lib wbemuuid.lib comsupp.lib comsuppw.lib \
			ole32.lib oleaut32.lib libcmt.lib winhttp.lib


rehost.exe: rehost_example.obj $(CLIENT_LIB)
	$(LD) $(LDFLAGS) /out:rehost.exe rehost_example.obj \
		$(CLIENT_LIB) $(SERVER_LIB) $(XTRALIB)

rehost_example.obj: .\rehost_example.c
	cl $(CFLAGS) /MT /c .\rehost_example.c

rlmIF.exe: testF.obj rs35.obj $(CLIENT_LIB)
	$(IF) $(IFFLAGS) -o rlmIF.exe testF.obj rs35.obj \
		$(CLIENT_LIB) $(XTRALIB)

testF.obj: testF.f
	$(IF) $(IFFLAGS) -c testF.f

rs35.obj: rs35.c
	cl $(CFLAGS) /Z7 /MT /c rs35.c

disconn_rehost.exe: rehost_disconn.obj $(CLIENT_LIB)
	$(LD) $(LDFLAGS) /out:disconn_rehost.exe rehost_disconn.obj \
		$(CLIENT_LIB) $(SERVER_LIB) $(XTRALIB)

rehost_disconn.obj: .\rehost_disconn.c
	cl $(CFLAGS) /MT /c .\rehost_disconn.c

Offline_Activation.exe: rs35_offline.obj $(CLIENT_LIB)
	$(LD) $(LDFLAGS) /out:Offline_Activation.exe rs35_offline.obj \
		$(CLIENT_LIB) $(SERVER_LIB) $(XTRALIB)

rs35_offline.obj: .\rs35_offline.c
	cl $(CFLAGS) /MT /c .\rs35_offline.c

clean:
	if exist testC.obj del testC.obj
	if exist rlmC.exe del rlmC.exe
	if exist testF.obj del testF.obj
	if exist rlmIF.exe del rlmIF.exe
	if exist rs35.obj del rs35.obj
	if exist rs35ed.obj del rs35ed.obj
	if exist rs35.exe del rs35.exe
	if exist rs35ed.exe del rs35ed.exe
	if exist rlmDetached.obj del rlmDetached.obj
	if exist rlmDetached.exe del rlmDetached.exe
	if exist *.obj del *.obj 
	if exist *.ilk del *.ilk
	if exist *.pdb del *.pdb
	if exist *~ del *~
	if exist rehost_disconn.obj del rehost_disconn.obj
	if exist disconn_rehost.exe del disconn_rehost.exe
	if exist rs35_offline.obj del rs35_offline.obj
	if exist Offline_Activation.exe del Offline_Activation.exe

