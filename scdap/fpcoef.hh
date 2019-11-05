*mlist
*comdeck fpcoef
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
       common /fpcoef/ ksurf, kchem, eqsrf, kpart, eqvap, kaggl, kdep,
     * mcme78
       real ksurf(maxsp,maxsrf), kchem(maxsp,maxsrf),
     * eqsrf(maxsp,maxsrf), kpart(maxbin,maxsp), eqvap(maxsp),
     * kaggl(maxbin,maxbin), kdep(maxbin,maxsrf)
       integer mcme78
*endif
