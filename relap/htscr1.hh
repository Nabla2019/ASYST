*mlist
!
!  Cognizant engineer: ras.
!
!  Scrach storage for reflood calculation.
       integer indzhs(l_)
       real htb2(l_),htc2(l_),htf2(l_),htts2(l_),httr2(l_),htdz(l_),
     & htbc2(l_),htbd2(l_),htv1(l_),htv2(l_)
       equivalence (htdz(1),fa(1)),(httr2(1),fa(2)),(htb2(1),fa(3)),
     & (htc2(1),fa(4)),(htf2(1),fa(5)),(htts2(1),fa(6)),
     & (htbc2(1),fa(7)),(htbd2(1),fa(8)),(htv1(1),fa(9)),
     & (htv2(1),fa(10)),(indzhs(1),ia(11))
