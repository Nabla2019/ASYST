*mlist
!
!  Cognizant engineer: rjw.
!
       integer mxnfld
       parameter (mxnfld = 14)
!
       common /mxnfbv/ wmoles(mxnfld)
       real wmoles
!
       common /mxnfcv/ tpfnam(mxnfld),fsymbl(mxnfld)
       character tpfnam*256,fsymbl*8
!
!  mxnfld  Maximum number of fluids available for use.
!  wmoles  Molecular weight of fluid.
!  tpfnam  Names of thermodynamic properties files from which steam
!          tables are to be obtained for needed fluids; file names
!          initialized in blkdta, can be overwritten by names from
!          command line.
!  fsymbl  Symbols for available fluids;  set in blkdta.
