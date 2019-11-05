*mlist
!  Descriptive sentence for przdat goes here.
!
!  Cognizant engineer: rjw.
!
       real przlvl(l_),pzhtcf(l_),pzhtcg(l_)
       integer przlln(l_),srgjun(l_),srgvol(l_),prznds(l_),przjnx(l_),
     & przvnx(l_)
       equivalence (przlvl(1),fa(13)),(pzhtcf(1),fa(14)),
     & (pzhtcg(1),fa(15)),(przlln(1),ia(16)),(srgjun(1),ia(17)),
     & (srgvol(1),ia(18)),(prznds(1),ia(19)),(przjnx(1),ia(20)),
     & (przvnx(1),ia(21))
!
!  przlvl  liquid level in pressurizer.
!  przlln  pressurizer liquid level node index.
!  srgjun  surge line junction index.
!  pzhtcf  user supplied interface heat transfer coefficient for liquid.
!  pzhtcg  user supplied interface heat transfer coefficient for vapor.
!  prznds  number of pressurizer volumes (and junctions including
!          the surge line junction).
!  przjnx  pressurizer junction indices starting from the top.
!  przvnx  pressurizer volume indices starting from the top.
!
