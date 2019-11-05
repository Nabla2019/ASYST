*mlist
*comdeck alcm
c
c
c  Cognizant engineer: ewc.
c
*if def,selap
c  array a is core storage for couple arrays.
       integer iamax
       parameter (iamax=90000)
       common /alcm/ a(0:iamax),mcme01
       real a
       integer iafp(0:iamax)
       equivalence (a(1),iafp(1))
       integer mcme01
*endif
