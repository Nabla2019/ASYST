*mlist
*comdeck fpvol
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
       common /fpvol/ vol, diam, brad, bang, vapvf, vapv, vapa, vapt,
     * vapp, vaprho, vapmu, vaptc, vapmfp, vapcp, surfar, surfda,
     * surft, surfmt, mcme83
       real vol, diam, brad, bang, vapvf, vapv, vapa, vapt, vapp,
     * vaprho, vapmu, vaptc, vapmfp, vapcp, surfar(maxsrf),
     * surfda(maxsrf), surft(maxsrf)
       integer surfmt(maxsrf), mcme83
*endif
