*mlist
!  Descriptive sentence for r5pvmcp goes here.
!
*if def,pvmcoupl
!
       integer nr5ccp(l_),nr5cin(l_),nr5cnm(l_),nr5ctb(l_),nr5cmt(l_)
       real fr5cfq(l_),ar5ctb(l_),ar5cnm(l_)
       equivalence (nr5ccp(1),ia(1)),
     & (ar5cnm(1),fa(4)),(fr5cfq(1),fa(9)),
     & (nr5cnm(1),ia(12)),(ar5ctb(1),fa(13)),(nr5ctb(1),ia(14)),
     & (nr5cmt(1),ia(19)),(nr5cin(1),ia(20))
*endif
