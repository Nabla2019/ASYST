*mlist
*comdeck bwgeom
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
*if def,selap
       common /bwgeom/ rbc(ndax*ndcomp),rbo(ndax*ndcomp),
     # rss(ndax*ndcomp),rso(ndax*ndcomp), r1(ndax*ndcomp),
     # r2(ndax*ndcomp),r1bcs(ndax*ndcomp),r1bcl(ndax*ndcomp),
     # r1bos(ndax*ndcomp), r1bol(ndax*ndcomp),r2sss(ndax*ndcomp),
     # r2ssl(ndax*ndcomp),r2sos(ndax*ndcomp), r2sol(ndax*ndcomp),
     # vbc(ndax*ndcomp),vbo(ndax*ndcomp),vss(ndax*ndcomp),
     # vso(ndax*ndcomp),
     # nazb(ndcomp),nazs(ndcomp),nbwr,ibwrc(ndcomp),
     # nfshs(ndax*ndcomp), nfshb(ndax*ndcomp), mcme10
       real rbc,rbo,rss,rso,r1,r2,r1bcs,r1bcl,r1bos,r1bol,r2sss,r2ssl,
     * r2sos,r2sol,vbc,vbo,vss,vso
       integer nazb,nazs,nbwr,ibwrc,nfshs,nfshb,mcme10
*endif
