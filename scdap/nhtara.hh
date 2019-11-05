*mlist
*comdeck nhtara
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
       common /nhtara/ paxpz(2*ndax,maxpz,ndcomp),paxtim(maxpz,ndcomp),
     * pdaray(maxpp,2,ndcomp),pparay(maxpp,ndcomp),prdpr(ndrd,ndcomp),
     * xrdpr(ndrd,ndcomp),taray(maxpp,ndcomp),tshtdn(ndcomp),
     * kshapz(ndcomp),naxpz(ndcomp),nparay(ndcomp),nrdpr(ndcomp),
     * nshapz(ndcomp),mcme48
       real paxpz,paxtim,pdaray,pparay,prdpr,xrdpr,taray,tshtdn
       integer kshapz,naxpz,nparay,nrdpr,nshapz,mcme48
       real paxpz2(2,ndax,maxpz,ndcomp)
       equivalence (paxpz2(1,1,1,1),paxpz(1,1,1))
*endif
