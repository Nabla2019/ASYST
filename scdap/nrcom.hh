*mlist
*comdeck nrcom
c
c
c
c  nrcom contains N-Reactor geometry data.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c
      common /nrcom/ rclio(ndax,ndcomp),rcoo(ndax,ndcomp),
     + oxdeoo(ndax,ndcomp),alfaoo(ndax,ndcomp),oxdwco(ndax,ndcomp),
     + h2oxdo(ndax,ndcomp),sroxdo(ndax,ndcomp),rnoxdo(ndax,ndcomp),
     + rnalfo(ndax,ndcomp),oxdhco(ndax,ndcomp),alfoo0(ndax,ndcomp),
     + h2odo0(ndax,ndcomp),oxdoo0(ndax,ndcomp),oxwco0(ndax,ndcomp),
     + rcoo0(ndax,ndcomp),rnafa0(ndax,ndcomp),rnodo0(ndax,ndcomp),
     + oxdco0(ndax,ndcomp),cldtho(ndax,ndcomp),cldthi(ndax,ndcomp),
     + dro(ndax,ndcomp),dri(ndax,ndcomp),mascao(ndax,ndcomp),
     + mascoo(ndax,ndcomp),mascai(ndax,ndcomp),mascoi(ndax,ndcomp),
     + masfa(ndax,ndcomp),masfao(ndax,ndcomp),masfu(ndax,ndcomp),
     + masfuo(ndax,ndcomp),mascdo(ndax,ndcomp),mascdi(ndax,ndcomp),
     + masful(ndax,ndcomp),mscamo(ndax,ndcomp),mscomo(ndax,ndcomp),
     + mscami(ndax,ndcomp),mscomi(ndax,ndcomp),msfam(ndax,ndcomp),
     + msfaom(ndax,ndcomp),msfum(ndax,ndcomp),msfuom(ndax,ndcomp),
     + mscdmo(ndax,ndcomp),mscdmi(ndax,ndcomp),msfulm(ndax,ndcomp),
     + wcoblw(ndcomp),wciblw(ndcomp),wfblw(ndcomp),tcldm,tfulm,hfscld,
     + hfsful,viscal,viscul,rhoal,rhoao,rhou,rhouo,rhoual,fract,
     + timlti(ndax,ndcomp),timlto(ndax,ndcomp),timltf(ndax,ndcomp),
     + totmas(ndax,ndcomp),cdomas(ndax,ndcomp),cdimas(ndax,ndcomp),
     + fulmas(ndax,ndcomp)
      common /nrcom/ noxido(ndax,ndcomp),noxdo0(ndax,ndcomp),
     + imelt(ndax,ndcomp),naz1(ndcomp),lflag(ndcomp),mcme49
       real rclio,rcoo,oxdeoo,alfaoo,oxdwco,h2oxdo,sroxdo,rnoxdo,rnalfo,
     * oxdhco,alfoo0,h2odo0,oxdoo0,oxwco0,rcoo0,rnafa0,rnodo0,oxdco0,
     * cldtho,cldthi,dro,dri,mascao,mascoo,mascai,mascoi,masfa,
     * masfao,masfu,masfuo,mascdo,mascdi,masful,mscamo,mscomo,mscami,
     * mscomi,msfam,msfaom,msfum,msfuom,mscdmo,mscdmi,msfulm,wcoblw,
     * wciblw,wfblw,tcldm,tfulm,hfscld,hfsful,viscal,viscul,rhoal,rhoao,
     * rhou,rhouo,rhoual,fract
       real timlti,timlto,timltf,totmas,cdomas,cdimas,fulmas
       integer noxido,noxdo0,imelt,naz1,lflag,mcme49
c
c     fuel element outer surface zr oxidation parameters
c     oxdeoo is the zr oxide layer thickness (m)
c     alfaoo is the alpha layer thickness (m)
c     oxdwco is the cladding oxide weight gain (kg/m2)
c     h2oxdo is the hydrogen generation rate (kg/s)
c     sroxdo is the steam removal rate (kg/s)
c     rnoxdo is the inner radius of oxide layer (m)
c     rnalfo is the inner radius of alpha layer (m)
c     noxido is the flag to notify that all zr is oxidized
c     oxdhco is the heat generation rate (w/m)
*endif
