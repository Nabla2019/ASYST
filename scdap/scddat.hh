*define erf
*define f90
*define fourbyt
*define gui
*define impnon
*define in32
*define ma28
*define msnt
*define plots
*define selap
*define unix
*if def,selap
cljs  Note: When indices ndax and ndcomp are changed, then
cljs        arrays qradpvx and ncmpch in module scdmod must have
cljs        dimensions changed to same values. If ndcomp = 64 and
cljs        ndax = 40, then in module scdmod dimension qradpvx and 
cljs        ncmpch as follows:
cljs        real qradpvx(64,40,64)
cljs        integer ncmpch(64,64)
*if def,scdapext
       integer,parameter :: maxpp=20,maxpz=5,ndax=40,ndcomp=64,
*endif
*if -def,scdapext
       integer,parameter :: maxpp=20,maxpz=5,ndax=20,ndcomp=15,
*endif
cljs & ndgrid=11,ndmatr=10,ndrd=20,ndrg=10,ndtime=10,
     & ndgrid=15,ndmatr=10,ndrd=30,ndrg=10,ndtime=10,
     & nxdbrg=60,nmups=10,nmupax=15,nmupcn=8
       integer,parameter :: ndrgndax=max(ndrg,ndax)
c
cljs   common /scddat/ icomp,ncomp,ngrid,mcme62
       common /scddat/ qradpvx(ndcomp,ndax,ndcomp),
     &                 ncmpch(ndcomp,ndcomp),
     &                 icomp,ncomp,ngrid,mcme62
       real qradpvx
       integer ncmpch
       integer icomp,ncomp,ngrid,mcme62
*endif
