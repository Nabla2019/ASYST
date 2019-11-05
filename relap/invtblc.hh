*mlist
c
c  Cognizant engineer: rjw.
c
c  invofs  Offset used to compute indexes stored in invvnx.
c  The following occur for each volume.
c  invcnt  Number of junctions connected to each volume.
c          The following three words follow for each junction
c          connected to a volume.
c  invjun  Reverse coordinate direction flag, 0 if normal, 1 if reverse
c          (1 bit); connection flag, 0 if inlet, 1 if outlet (2 bit);
c          from/to flag, 0 if from, 1 if to (4 bit); momentum flux off
c          flag, 0 if momentum flux on, 1 if momentum flux off (8 bit).
c  invvno  Position number of junction in junction block.
c  invvnx  Index of junction.
