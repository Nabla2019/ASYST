*mlist
!
!  Cognizant engineer: rjw.
!
!  inverted junction table block.
       integer invskp
       parameter (invskp=3)
       integer invofs(l_),invcnt(l_),invjun(l_),invvno(l_),invvnx(l_)
       equivalence (invofs(1),ia(1)),(invcnt(1),ia(2)),
     & (invjun(1),ia(3)),(invvno(1),ia(4)),(invvnx(1),ia(5))
!
!  invofs  Offset used to compute indexes stored in invvnx.
!  The following occur for each volume.
!  invcnt  Number of junctions connected to each volume.
!          The following three words follow for each junction
!          connected to a volume.
!  invjun  Reverse coordinate direction flag, 0 if normal, 1 if reverse
!          (1 bit); connection flag, 0 if inlet, 1 if outlet (2 bit);
!          from/to flag, 0 if from, 1 if to (4 bit); momentum flux off
!          flag, 0 if momentum flux on, 1 if momentum flux off (8 bit).
!  invvno  Position number of junction in junction block.
!  invvnx  Index of junction.
