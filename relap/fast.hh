*mlist
!  Storage pool for the ftb files in memory.
!
!  Cognizant engineer: rjw.
!
       integer, parameter :: lfsiz=6000000
       integer, parameter :: l_=5999800
       common /fast/ fa(lfsiz)
       real fa
       integer ia(lfsiz)
       equivalence (fa(1),ia(1))
