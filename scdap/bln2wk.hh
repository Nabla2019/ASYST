*mlist
*comdeck bln2wk
c
c  bln2wk contains cladding deformation stresses.
c
c  Cognizant engineer: dlh.
c
*if def,selap
c
       common /bln2wk/ acs(9,9),aas(9,9),ars(9,9),ace(9,9),aae(9,9),
     * are(9,9),dbyth(9,9),dbyz(9,9),stresf(9,9),tstres(9,9),disp(9,9),
     * deh(9),rstran(9,9),dea(9),rave(9),stresr(9),stresa(9),mcme04
       real acs,aas,ars,ace,aae,are,dbyth,dbyz,stresf,tstres,disp,deh,
     * rstran,dea,rave,stresr,stresa
       integer mcme04
*endif
