*mlist
*comdeck farays
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c
       integer nvfprs,ntfprs
       parameter (nvfprs=10, ntfprs=10)
       common /farays/ ftemp(81,ndcomp), strnl(81,ndcomp),
     & strnr(81,ndcomp), strna(81,ndcomp), strnc(81,ndcomp),
     & rad(81,ndcomp), twall(81,ndcomp), ctemp(81,ndcomp),
     & delz(81,ndcomp), fcp(81,ndcomp), frp(81,ndcomp), fap(81,ndcomp),
     & acd(81,ndcomp),aad(81,ndcomp),ard(81,ndcomp),fnck,
     * nvinp(ndcomp),ntinp(ndcomp),vols(nvfprs,ndcomp),
     * tcvols(nvfprs,ntfprs,ndcomp),tsvols(ntfprs,ndcomp),
     * tkvol(nvfprs,ndcomp),erupt,ebal2,elim,
     * fncn,cwkf,cwnf,dz0,npsw,mcme28
       integer nvinp,ntinp,npsw
       real vols,tcvols,tsvols,tkvol,erupt,ebal2,elim
       real ftemp,strnl,strnr,strna,strnc,rad,twall,ctemp,delz,fcp,frp,
     * fap,acd,aad,ard,fnck,fncn,cwkf,cwnf,dz0
       integer mcme28
*endif
