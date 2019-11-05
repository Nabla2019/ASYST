*mlist
!  Holds data for built-in material data for heat structures.
!
!  Cognizant engineer: rjw.
*in32 m1a
*in32 m2a
*in32 m3a
*in32 m4a
*in32 m5a
*in32end
!
!  Holds data for built-in material data for heat structures.
       common /rmadac/ m1af,m1b,m1c,m2af,m2b,m2c,m3af,m3b,m3c,
     & m4af,m4b,m4c,m5af,m5b,m5c
       real m1af(4),m2af(4),m3af(4),m4af(4),m5af(4)
       real m1b(1),m1c(1),m2b(1),m2c(1),m3b(4),m3c(18)
       real m4b(40),m4c(32),m5b(22),m5c(10)
       integer m1a(4),m2a(4),m3a(4),m4a(4),m5a(4)
       equivalence (m1af(1),m1a(1)),(m2af(1),m2a(1)),
     & (m3af(1),m3a(1)),(m4af(1),m4a(1)),(m5af(1),m5a(1))
