*mlist
*comdeck fpdkht
c
c
c  fpdkht is the fission product decay heat common block.
c
c  Cognizant engineer: ewc.
c
$if def,selap
c
      integer mxelm
      parameter (mxelm=3)
      integer mxpar, lgamma, lbeta
      parameter (mxpar=2, lgamma=1, lbeta=2)
c     dkhtfr - decay heat fraction of the elements contributing to
c     the decay heat model for each of gamma and beta particles
      real dkhtfr(mxelm,mxpar)
      integer mcme80
      common /fpdkht/ dkhtfr, mcme80
$endif
