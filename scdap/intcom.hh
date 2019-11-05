*mlist
*if def,selap
c
c
c  intcom contains the oxidation and melt relocation data.
c
c  Cognizant engineer: ewc.
c
       common /intcom/ alfai(ndax*ndcomp),alfao(ndax*ndcomp),
     * effcpf(ndax*ndcomp),effqf(ndax*ndcomp),oxdei(ndax*ndcomp),
     * oxdeo(ndax*ndcomp),oxdwc(ndax*ndcomp),oxdwf(ndax*ndcomp),
     * oxdws(ndax*ndcomp),dzfrac(2*ndax*ndcomp),rocrmx(ndax*ndcomp),
     * ruliq(ndax*ndcomp),volcrs(ndax*ndcomp),wbotuo(ndcomp),
     * wbotox(ndcomp),wbotzr(ndcomp),wuomlt(ndax*ndcomp),
     * ruomlt(ndax*ndcomp),wremuo(ndax*ndcomp),wremzr(ndax*ndcomp),
     * wuorem(ndax*ndcomp),wremzo(ndax*ndcomp),ggivy(17,ndcomp),
     * rnalf(ndax*ndcomp),rnoxd(ndax*ndcomp),dzfrcl(ndax*ndcomp),
     * stozro(ndax*ndcomp),timzo2(ndax,ndcomp),wbotab(ndcomp),
     * wbotsr(ndcomp),wfroab(ndax*ndcomp),wfrosr(ndax*ndcomp),
     * wremab(ndax*ndcomp),wincl(ndax,ndcomp),thincl(ndax,ndcomp),
     * winrem(ndax,ndcomp),winfro(ndax,ndcomp),winliq(ndax,ndcomp)
       common /intcom/ wremsr(ndax*ndcomp),wzrinc(ndax,ndcomp),
     & wzrgfz(ndax,ndcomp),dzrinf(ndax,ndcomp),dinzrf(ndax,ndcomp),
     & daxdis(ndax,ndcomp),thkgpl(ndax,ndcomp), retabg(ndax,ndcomp),
     & daxgrd(ndax,ndcomp),drgrdm(ndax,ndcomp),dia1gr(ndax,ndcomp),
     & dza1gr(ndax,ndcomp),oxdhcc(ndax,ndcomp),oxdhfc(ndax,ndcomp),
     & oxdhc0(ndax,ndcomp),
     & thetgr(ndax,ndcomp),idsrup(ndcomp),ioxerr(ndax*ndcomp),
     & ltrans(ndax*ndcomp),ndisrp(ndax*ndcomp),noxerr(ndcomp),
     & noxide(ndax*ndcomp),ncrum(ndax*ndcomp),nfi(ndax*ndcomp),
     & nfrslg(ndax*ndcomp),ibrch(ndcomp),ndbris,igrinc(ndax,ndcomp),
     & mcme39
       real alfai,alfao,effcpf,effqf,oxdei,oxdeo,oxdwc,oxdwf,oxdws,
     * dzfrac,rocrmx,ruliq,volcrs,wbotuo,wbotox,wbotzr,wincl,thincl,
     * winrem,winfro,winliq,wuomlt,ruomlt,wremuo,wremzr,wuorem,wremzo,
     * ggivy,rnalf,rnoxd,dzfrcl,stozro,timzo2,wbotab,wbotsr,wfroab,
     * wfrosr,wremab,wremsr,wzrinc,wzrgfz,
     # dzrinf,dinzrf,daxdis,thkgpl,retabg,daxgrd,thetgr,drgrdm,
     * oxdhcc,oxdhfc,dia1gr,dza1gr
       real oxdhc0
       integer ibrch,idsrup,ioxerr,ndisrp,noxerr,noxide,ncrum,nfi,
     * nfrslg,ndbris,igrinc,mcme39
       logical ltrans
c  local 2-d variable oxd2d(ndax,ndcomp) equiv to oxdeo(ndax*ndcomp)
       real oxd2d(ndax,ndcomp)
       equivalence (oxd2d(1,1),oxdeo(1))
       real oxdeo2(ndax,ndcomp),oxdwc2(ndax,ndcomp)
       equivalence (oxdeo2(1,1),oxdeo(1)),(oxdwc2(1,1),oxdwc(1))
       integer noxide2(ndax,ndcomp)
       equivalence (noxide2(1,1),noxide(1))
*endif
