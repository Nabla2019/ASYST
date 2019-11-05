*mlist
c  Contains data for fission product release from pools.
c
c  Cognizant engineer: dlh.
c
*if def,selap
       common /bcons/ vrise(15),coal(15,15),mcme101
       real vrise,coal
       integer mcme101
*endif
