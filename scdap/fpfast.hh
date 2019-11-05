*mlist
*comdeck fpfast
c
c
c  fpfast is the fission product transport global common in dynamic
c  storage.
c
c  Cognizant engineer: ewc.
c
$if def,selap
c
c  a.k.a. "file 34" in the COMMON block "fast".
      integer fpinpo(1)
      logical fpactv(1), fpdbgr(1)
      integer fpnsys(1), fpsyso(1), fpnbin(1), fpnsp(1),
     &   fpsysk(1), fpvolk(1), fpsrfk(1), fpspvk(1), fpspsk(1)
      real fpsp(1), fprtol(1), fpatol(1)
      equivalence (fpinpo(1),ia(1)), (fpactv(1),ia(2)),
     &   (fpdbgr(1),ia(3)),
     &   (fpnsys(1),ia(4)), (fpsyso(1),ia(5)), (fpnbin(1),ia(6)),
     &   (fpnsp(1),ia(7)), (fpsysk(1),ia(8)), (fpvolk(1),ia(9)),
     &   (fpsrfk(1),ia(10)), (fpspvk(1),ia(11)), (fpspsk(1),ia(12))
      equivalence (fprtol(1),fa(13)), (fpatol(1),fa(14)),
     &   (fpsp(1),fa(15))
      integer fpsysn(1), fpnvol(1), fpvolo(1)
      real fpsysm(1)
      equivalence (fpsysn(1),ia(1)), (fpnvol(1),ia(2)),
     &   (fpvolo(1),ia(3))
      equivalence (fpsysm(1),fa(4))
      integer fpvoln(1), fpnsrf(1), fpsrfo(1)
      real fpstep(1)
      real fpsrc(1), fpvtm(1), fpstm(1), fpliq(1), fpvap(1), fpbin(1)
      equivalence (fpvoln(1),ia(1)), (fpnsrf(1),ia(2)),
     &   (fpsrfo(1),ia(3))
      equivalence (fpstep(1),fa(4))
      equivalence (fpsrc(1),fa(5)),
     &   (fpvtm(1),fa(6)), (fpstm(1),fa(7)),
     &   (fpliq(1),fa(8)), (fpvap(1),fa(9)), (fpbin(1),fa(10))
      integer fpsrfn(1), fpsflr(1), fpsfmt(1), fpsfto(1)
      real fpsfar(1), fpsfan(1), fpsfra(1)
      real fpsfbs(1), fpsfgs(1), fpsfbv(1)
      real fpsfmc(1), fpsfma(1), fpsfmp(1)
      equivalence (fpsrfn(1),ia(1)), (fpsflr(1),ia(2)),
     &   (fpsfmt(1),ia(3)), (fpsfto(1),ia(4))
      equivalence
     &   (fpsfar(1),fa(5)), (fpsfan(1),fa(6)), (fpsfra(1),fa(7)),
     &   (fpsfbs(1),fa(8)), (fpsfgs(1),fa(9)), (fpsfbv(1),fa(10)),
     &   (fpsfmc(1),fa(11)), (fpsfma(1),fa(12)), (fpsfmp(1),fa(13))
$endif
