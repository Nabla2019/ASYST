*mlist
*comdeck prdat
c
c
c  prdat contains relative plenum data.
c
c  Cognizant engineer: ewc.
c
*if def,selap
       common /prdat/ txmpf(10), fplt(10), ffvt(10), mt, mtmax, mcme56
       real txmpf,fplt,ffvt
       integer mt,mtmax,mcme56
*endif
