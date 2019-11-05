*mlist
*comdeck slbcom
c
c
c  Descriptive sentence for slbcom goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
       common /slbcom/ qslabt(20,ndcomp*ndax),qtime(20,ndcomp),
     # nqtim(ndcomp),mcme64
       real qslabt,qtime
       integer nqtim,mcme64
       real qslabt2(20,ndax,ndcomp)
       equivalence(qslabt2(1,1,1),qslabt(1,1))
*endif
