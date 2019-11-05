*mlist
*comdeck cdfinv
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc (ghb).
c
*if def,selap
       common /cdfinv/ dxcfri(ndax),epplas(ndax),etru(ndax),cfnck(ndax),
     * cfncn(ndax),ccwkf(ndax),ccwnf(ndax),caad(ndax),cacd(ndax),
     * card(ndax),cfcp(ndax),cfap(ndax),cfrp(ndax),cepp(ndax,3),
     * cep(ndax),ceps(ndax,3),depp(ndax,3),edot(ndax),hoopmx,rmin,carea,
     * cflux,cinwid,cladt0,rareai,fareai,hoopmn,blkey(ndax),
     * icall0,nbncl0,mcme14
       real dxcfri,epplas,etru,cfnck,cfncn,ccwkf,ccwnf,caad,cacd,card,
     * cfcp,cfap,cfrp,cepp,cep,ceps,depp,edot,hoopmx,rmin,carea,cflux,
     * cinwid,cladt0,rareai,fareai,hoopmn,blkey
       integer icall0,nbncl0,mcme14
*endif
