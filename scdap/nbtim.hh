*mlist
*comdeck nbtim
c
c
c  nbtim contains parameters for a separate debris bed
c  time step.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c
       common /nbtim/ timdb,deltdb,mcme46
       real timdb,deltdb
       integer mcme46
*endif
