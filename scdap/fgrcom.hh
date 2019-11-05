*mlist
!  Descriptive sentence goes here.
!
!  Cognizant engineer:ljs.
!
*if def,selap
       common /fgrcom/ fpivy(ndax*16,ndcomp),fpary(16,ndcomp),
     * fparyc(16,ndcomp),fpivrt(5*ndax,ndcomp),fgrj(5*ndax,ndcomp),
     * fgr(5,ndcomp), fpmasi(19,ndcomp), mcme31
c
c     fpmasi = initial mass of fission products in Scdap component
c
       real fpivy,fpary,fparyc,fpivrt,fgrj,fgr,fpmasi
       integer mcme31
       real fpivy3(ndax,16,ndcomp)
       equivalence (fpivy3(1,1,1),fpivy(1,1))
       real fpivrt3(5,ndax,ndcomp)
       equivalence (fpivrt3(1,1,1),fpivrt(1,1))
!
!  fgr(i1,i2)       Fractional release of fission gase i1 in component
!                   i2.
!  fgrj(i1,i2,i3)   Ratio of fission gas i1 released in axial level i2
!                   of component i3 to fission gas i1 generated in axial
!                   zone i2 of component i3.
*endif
