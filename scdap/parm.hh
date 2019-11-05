*mlist
*comdeck parm
*if def,selap
c
c
c  parm contains the couple mesh geometry.
c
c  Cognizant engineer: ewc.
      integer npar1
      parameter (npar1 = 53)
c  npar1 = number of couple reals in /parm/, excluding mcme54.
c
c      Note: Be sure and change npar1 if you change
c            the number of couple reals in /parm/.
c
      common /  parm /     alhir,  amult,   coni,   conj,  contr,
     1                     depth,     dh, dradin, dradis,  dtcpl,
     2                     dtold, emissm, ftempc, hed1(10), hed2(10),
     3                    height,   radc,   rlxn,   rlxo,  rtemp,
     4                      seti,   setj,   sigf, tempin,   time,
     5                      tvol,  uncon, atrhgt, depthp, cnpool,
     6                       rap,   rass,  zpbot,  zptop,  tpool,
     6                    tlqpol, mcme54
c
      real                 alhir,  amult,   coni,   conj,  contr,
     1                     depth,     dh, dradin, dradis,  dtcpl,
     2                     dtold, emissm, ftempc,   hed1,   hed2,
     3                    height,   radc,   rlxn,   rlxo,  rtemp,
     4                      seti,   setj,   sigf, tempin,   time,
     5                      tvol,  uncon, atrhgt, depthp, cnpool,
     6                       rap,   rass,  zpbot,  zptop,  tpool,
     #                    tlqpol
      integer mcme54
c
      real parm(npar1)
      equivalence (parm(1), alhir)
c
*endif
