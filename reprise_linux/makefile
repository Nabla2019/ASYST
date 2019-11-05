ISV = issrs

EXECS = rlmIF rlmC rlmDetached

all: $(EXECS)

IF = ifort

CC = cc

LD = $(CC)

CFLAGS = -g -I../src -pthread -Wall -m32 -Dx86_l2 -fPIC

LIBRARY = ./x86_l2/rlm.a

#XTRALIB = -lpthread -ldl -lrt ./x86_l2/rlmid1.a

testF.o: testF.f
	$(IF) -c testF.f

testC.o: testC.c
	$(CC) $(CFLAGS) -c testC.c

rlmclient.o: rlmclient.c
	$(CC) $(CFLAGS) -c rlmclient.c

detached_demo.o: detached_demo.c
	$(CC) $(CFLAGS) -c detached_demo.c

# test reprise with FORTRAN program; 
rlmIF: testF.o rlmclient.o $(LIBRARY)
	$(IF) -o rlmIF testF.o rlmclient.o \
		$(LIBRARY) $(XTRALIB)

# test reprise with C program; C calls C
rlmC: testC.o rlmclient.o $(LIBRARY)
	$(LD) -m32 -o rlmC testC.o rlmclient.o \
		$(LIBRARY) $(XTRALIB)

# test reprise detached-demo with FORTRAN program; 
rlmDetached: testF.o detached_demo.o $(LIBRARY)
	$(IF) -o rlmDetached testF.o detached_demo.o \
		$(LIBRARY) $(XTRALIB)

clean:
	if [ -a testC.o ]; then rm testC.o; fi
	if [ -a rlmC ]; then rm rlmC; fi
	if [ -a testF.o ]; then rm testF.o; fi
	if [ -a rlmIF ]; then rm rlmIF; fi
	if [ -a rlmclient.o ]; then rm rlmclient.o; fi
	if [ -a rlmcliented.o ]; then rm rlmcliented.o; fi
	if [ -a rlmclient ]; then rm rlmclient; fi
	if [ -a rlmcliented ]; then rm rlmcliented; fi
	if [ -a rlmDetached.o ]; then rm rlmDetached.o; fi
	if [ -a rlmDetached ]; then rm rlmDetached; fi
	if [ -a detached_demo ]; then rm detached_demo; fi
	rm *.obj
	rm *~

