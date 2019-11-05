*mlist
*comdeck parmm
c
c
c  parmm contains real storage space for couple meshes.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c
      common / parmm / parmm(npar1,maxcpm), mcme75
      real parmm
      integer mcme75
c
c     parmm  = /parm/ real storage space for up to maxcpm couple meshes.
c
*endif
