*mlist
*comdeck plndat
c
c
c  plndat contains intact component plenum data.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c
        common /plndat/ qchlbn(ndax,ndcomp),wdtqlp(ndcomp),z2phas,
     #  nsigl1,mcme55
        real qchlbn,wdtqlp,z2phas
        integer nsigl1,mcme55
*endif
