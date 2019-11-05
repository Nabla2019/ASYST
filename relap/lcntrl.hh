*mlist
!  Control array for loops.
!
!  Cognizant engineer: rjw.
!
       integer vlpndx(l_)
       equivalence (vlpndx(1),ia(1))
!
!  vlpndx  used to hold volume number and position data during
!          hydrodynamic system sorting.  holds component indexes to
!          allow printing of component, volume, and junction information
!          in numerical order.
