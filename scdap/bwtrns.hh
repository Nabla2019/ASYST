*mlist
*comdeck bwtrns
c
c  bwtrns contains B4C rod melt relocation.
c
c  Cognizant engineer: ewc.
c
*if def,selap
       common /bwtrns/ wtgsdt(ndcomp*ndax),wtgbdt(ndcomp*ndax),
     #   qoxss(ndcomp*ndax), qoxbc(ndcomp*ndax),mbct(ndcomp*ndax),
     #   mbcs(ndcomp*ndax),mbcl(ndcomp*ndax), mbot(ndcomp*ndax),
     #   mbos(ndcomp*ndax),mbol(ndcomp*ndax),msst(ndcomp*ndax),
     #   msss(ndcomp*ndax), mssl(ndcomp*ndax),msot(ndcomp*ndax),
     #   msos(ndcomp*ndax),msol(ndcomp*ndax),m1t(ndcomp*ndax),
     #   m2t(ndcomp*ndax),mltbc(ndcomp*ndax),mltbo(ndcomp*ndax),
     #   mltss(ndcomp*ndax), mltso(ndcomp*ndax),mbclre(ndcomp*ndax),
     #   mbolre(ndcomp*ndax),msslre(ndcomp*ndax), msolre(ndcomp*ndax),
     #   mbclot(ndcomp),mbolot(ndcomp),msslot(ndcomp),msolot(ndcomp),
     #   ubclot(ndcomp),ubolot(ndcomp),usslot(ndcomp),usolot(ndcomp),
     #   t1(ndcomp*ndax), t2(ndcomp*ndax),t1o(ndcomp*ndax),
     #   t2o(ndcomp*ndax),ut2(ndcomp*ndax),ut1(ndcomp*ndax),
     #   ut1re(ndcomp*ndax),ut2re(ndcomp*ndax),ubc(ndcomp*ndax),
     #   ubo(ndcomp*ndax),uss(ndcomp*ndax), uso(ndcomp*ndax),mcme12
       real wtgsdt,wtgbdt,qoxss,qoxbc,mbct,mbcs,mbcl,mbot,mbos,mbol,
     * msst,msss,mssl,msot,msos,msol,m1t,m2t,mltbc,mltbo,mltss,mltso,
     * mbclre,mbolre,msslre,msolre,mbclot,mbolot,msslot,msolot,ubclot,
     * ubolot,usslot,usolot,t1,t2,t1o,t2o,ut2,ut1,ut1re,ut2re,ubc,ubo,
     * uss,uso
       integer mcme12
*endif
