*mlist
*comdeck uoxcom
c
c
c  Cognizant engineer: ewc.
c
c  uoxcom contains uranium oxidation parameters (i indicates inner
c  surface, o indicates outer surface, and 0 indicates previous time
c  step)
c
*if def,selap
c
c     common block uoxcom carries uranium oxidation
c     parameters (i indicates inner surface, o indicates
c     outer surface, and 0 indicates previous time step)
       common /uoxcom/ uwgi(ndax,ndcomp),uwgi0(ndax,ndcomp),
     * h2uoxi(ndax,ndcomp),h2uoi0(ndax,ndcomp),quoxi(ndax,ndcomp),
     * quoxi0(ndax,ndcomp),sruoxi(ndax,ndcomp),uthick(ndax,ndcomp),
     * uwgo(ndax,ndcomp),uwgo0(ndax,ndcomp),h2uoxo(ndax,ndcomp),
     * h2uoo0(ndax,ndcomp),quoxo(ndax,ndcomp),quoxo0(ndax,ndcomp),
     * sruoxo(ndax,ndcomp),uoxfi(ndax,ndcomp),uoxfo(ndax,ndcomp),bgthu,
     +  bgthqu, bgtha,
     + h2aoxi(ndax,ndcomp),h2aoxo(ndax,ndcomp),sraoxi(ndax,ndcomp),
     + sraoxo(ndax,ndcomp),qaoxi(ndax,ndcomp),
     + qaoxo(ndax,ndcomp),
     + oxdwai(ndax,ndcomp),oxdai0(ndax,ndcomp),oxdwao(ndax,ndcomp),
     + oxdao0(ndax,ndcomp),mcme71
       real uwgi,uwgi0,h2uoxi,h2uoi0,quoxi,quoxi0,sruoxi,uthick,
     * uwgo,uwgo0,h2uoxo,h2uoo0,quoxo,quoxo0,sruoxo,uoxfi,uoxfo,bgthu,
     * bgthqu,bgtha,h2aoxi,h2aoxo,sraoxi,sraoxo,qaoxi,qaoxo,oxdwai,
     * oxdai0,oxdwao,oxdao0
       integer mcme71
*endif
