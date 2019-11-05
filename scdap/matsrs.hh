*mlist
c
c  matsrs contains molten pool fission product material data.
c
c  Cognizant engineer: dth.
c
*if def,selap
       common /matsrs/ viscl,rholsd,zusten,mcme105
       real viscl,rholsd,zusten
       integer mcme105
*endif
