*mlist
*comdeck grscgr
c
c  grscgr is the paragrass common block.
c
c  Cognizant engineer: ewc.
*if def,selap
c
c  paragrass common block.
       common /grscgr/ ci(15*ndax*ndcomp),acae(ndax*ndcomp),
     * prf(ndax*ndcomp),gsg(5*ndax*ndcomp),gou(6*ndax*ndcomp),
     * dis(16*ndax*ndcomp),dlmo(4*ndax*ndcomp),grira(5*ndax*ndcomp),
     * tliqs(ndax*ndcomp),tcap(ndax*ndcomp),buk(ndax*ndcomp),
     * rxd(4*ndax*ndcomp),fgrmgo(ndax*ndcomp),sv(4*ndax*ndcomp),
     * hh(ndax*ndcomp), tkgs(ndax*ndcomp),vlm(ndax*ndcomp),
     * grain(ndax*ndrd*ndcomp),ato(4*ndax*ndcomp),cc(5*ndax*ndcomp),
     * iliq(ndax*ndcomp),kraph(ndcomp),ininv,mcme35
       real ci,acae,prf,gsg,gou,dis,dlmo,grira,tliqs,tcap,buk,rxd,
     * fgrmgo,sv,hh,tkgs,vlm,grain,ato,cc
       integer iliq,kraph,ininv,mcme35
*endif
