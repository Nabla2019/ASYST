*mlist
*comdeck fpctrl
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
       common /fpctrl/ spcrho,nsp,nsrf,nbin,nvolst,nsrfst,nst,
     * iliqfp, ivap, mcme79
       real spcrho(maxsp)
       integer nsp,nsrf,nbin,nvolst,nsrfst,nst,iliqfp,ivap,mcme79
*endif
