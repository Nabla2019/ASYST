*mlist
*comdeck cdfinc
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc (ghb).
c
*if def,selap
c
       common /cdfinc/ dxcfrc(ndax,ndcomp),eplasc(ndax,ndcomp),
     * etruc(ndax,ndcomp),cfnckc(ndax,ndcomp),cfncnc(ndax,ndcomp),
     * ccwnfc(ndax,ndcomp),caadc(ndax,ndcomp),
     # cacdc(ndax,ndcomp),cardc(ndax,ndcomp),cfcpc(ndax,ndcomp),
     * cfapc(ndax,ndcomp),cfrpc(ndax,ndcomp),ceppc(ndax,3,ndcomp),
     * cepc(ndax,ndcomp),cepsc(ndax,3,ndcomp),deppc(ndax,3,ndcomp),
     * edotc(ndax,ndcomp),hopmxc(ndcomp),rminc(ndcomp),careac(ndcomp),
     * cfluxc(ndcomp),cinwdc(ndcomp),cldt0c(ndcomp),
     * raraic(ndcomp),faraic(ndcomp),hopmnc(ndcomp),blkeyc(ndax,ndcomp),
     * ical0c(ndcomp),nbnclc(ndcomp),mcme13
       real dxcfrc,eplasc,etruc,cfnckc,cfncnc,ccwnfc,caadc,cacdc,cardc,
     * cfcpc,cfapc,cfrpc,ceppc,cepc,cepsc,deppc,edotc,hopmxc,rminc,
     * careac,cfluxc,cinwdc,cldt0c,raraic,faraic,hopmnc,blkeyc
       integer ical0c,nbnclc,mcme13
*endif
