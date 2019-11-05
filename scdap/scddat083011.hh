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
       integer,parameter :: maxpp=20,maxpz=5,ndax=40,ndcomp=16,
cljs & ndgrid=11,ndmatr=10,ndrd=20,ndrg=10,ndtime=10,
     & ndgrid=11,ndmatr=10,ndrd=30,ndrg=10,ndtime=10,
     & nxdbrg=25,nmups=10,nmupax=15,nmupcn=8
       integer,parameter :: ndrgndax=max(ndrg,ndax)
c
       common /scddat/ icomp,ncomp,ngrid,mcme62
       integer icomp,ncomp,ngrid,mcme62
*endif
