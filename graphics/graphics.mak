L = graphics.lib

SRCS = \
 scigraph.ff sgadmin.ff sgdata.ff sgdraw.ff sglowlvl.ff sgplot.ff

OBJS = $(SRCS:.ff=.obj)

!if exist($L)
REPL=$L
!else
REPL=
!endif
FL = -automatic -traceback -fltconsistency -fpconstant

#  Suffix Rules
.SUFFIXES :


.SUFFIXES : .obj .mod .ff


.ff.obj	:
	copy ..\auxx\definem+$*.ff ..\f1
	..\auxx\select <..\f1 >$*.f90
	f90 -nologo -c $(FFLAGS) $(FL) $*.f90

#  Explicit Targets

$L:  $(OBJS)
	lib -nologo $(REPL) $? -out:$L

#  Module Targets
scigraph.mod : scigraph.obj
sgadmin.mod : sgadmin.obj
sgdata.mod : sgdata.obj
sgdraw.mod : sgdraw.obj
sglowlvl.mod : sglowlvl.obj
sgplot.mod : sgplot.obj

.PRECIOUS: $L


.IGNORE:


Clean	:
	del $(OBJS)
	del *.mod
	del *.lib

#  Dependency Definitions
scigraph.obj : sgadmin.mod
sglowlvl.obj : sgdata.mod
sgadmin.obj sgplot.obj : sgdraw.mod
sgdraw.obj : sglowlvl.mod
scigraph.obj : sgplot.mod
