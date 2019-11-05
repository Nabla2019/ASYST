*mlist
*comdeck bwprop
c
c  bwprop contains B4C properties.
c
c  Cognizant engineer: ewc.
*if def,selap
       common /bwprop/ denbc(ndcomp*ndax),denbo(ndcomp*ndax),
     #   denss(ndcomp*ndax),denso(ndcomp*ndax),cpbc(ndcomp*ndax),
     #   cpbo(ndcomp*ndax),cpss(ndcomp*ndax), cpso(ndcomp*ndax),
     #   cp1(ndcomp*ndax),cp2(ndcomp*ndax),cnkbc(ndcomp*ndax),
     #   cnkbo(ndcomp*ndax),cnkss(ndcomp*ndax),cnkso(ndcomp*ndax),
     #   cnk1(ndcomp*ndax),cnk2(ndcomp*ndax),visbc(ndcomp*ndax),
     #   visbo(ndcomp*ndax),visss(ndcomp*ndax),visso(ndcomp*ndax),
     #   cpbcm,cpbom,cpssm,cpsom,hfbc,hfbo,hfss,hfso,tmlbc,tmlbo,tmlss,
     #   tmlso,mcme11
       real denbc,denbo,denss,denso,cpbc,cpbo,cpss,cpso,cp1,cp2,cnkbc,
     * cnkbo,cnkss,cnkso,cnk1,cnk2,visbc,visbo,visss,visso,cpbcm,cpbom,
     * cpssm,cpsom,hfbc,hfbo,hfss,hfso,tmlbc,tmlbo,tmlss,tmlso
       integer mcme11
*endif
