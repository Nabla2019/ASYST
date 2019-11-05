*mlist
c
c  Contains the intact component heat conduction parameters.
c
c  Cognizant engineer: ewc.
*if def,selap
c
c  Modified by H.Madokoro
c  Added nrcondi and nrheat
c	
       common /ndxara/naz,nrodes(ndax*ndcomp),
     &      nrcon1(ndax*ndcomp), nrcond(ndax*ndcomp), idcomp(ndcomp),
     &      nsigl(ndcomp),
     &      nrcondi(ndax*ndcomp), nrheat(ndax*ndcomp),mcme47
       integer naz, nrodes, nrcon1, nrcond, idcomp, nsigl, mcme47
       integer nrcondi, nrheat
       integer nrods2(ndax,ndcomp)
       integer nrcond2(ndax,ndcomp)
       integer nrcondi2(ndax,ndcomp)
       integer nrheat2(ndax,ndcomp)
       equivalence(nrcond2(1,1),nrcond(1))
       equivalence (nrods2(1,1),nrodes(1))
       equivalence(nrcondi2(1,1),nrcondi(1))
       equivalence(nrheat2(1,1),nrheat(1))
c
c     nrcon1 - radial node number where fuel starts
c     nrcond - number of radial heat conduction nodes in the
c                         absorber material
!  idcomp  0 = fuel rod; 1 = control rod; 2 = shroud; 3 = BWR control
!              rod; 4 = ATR fuel element; 5 = not used; 6 = electrical
!              heater rod; 7 = not used; 8 = BWR control blade and
!              channel box.
*endif
