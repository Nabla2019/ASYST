*mlist
*comdeck fpmas
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
       common /fpmass/ fpivm(ndcomp,ndax,16),ifplg(ndcomp),mcme32
       real fpivm
       integer ifplg,mcme32
*endif
