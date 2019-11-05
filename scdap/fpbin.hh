*mlist
*comdeck fpbin
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
       common /fpbin/ pdiam, pvol, pdelv, pnum, low, fmass, mcme77
       real pdiam(maxbin), pvol(maxbin), pdelv(maxbin), pnum(maxbin),
     * low(maxbin,maxbin), fmass(maxbin,maxbin)
       integer mcme77
*endif
