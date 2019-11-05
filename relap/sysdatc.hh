*mlist
!
!  Cognizant engineer: rjw.
       integer isyskp
       parameter (isyskp=12)
       integer nusys(l_),sysvol(l_),sysmat(l_),sysopt(l_)
       integer(8) tpfnha(l_),sysmaf(l_),sysnam(l_)
       real sysel(l_)
       equivalence (nusys(1),ia(1)),(sysvol(1),ia(2)),(sysel(1),fa(3)),
     & (sysmaf(1),fa(6)),(sysmat(1),ia(6)),(sysnam(1),fa(7)),
     & (sysopt(1),ia(8)),(tpfnha(1),fa(9))
!
!  isyskp  skip factor for sysdatc variable processing.
!  nusys   number of hydrodynamic systems.
!  sysvol  reference volume of system.
!  sysel   elevation of system reference volume.
!  sysmaf  material in system.
!  sysmat  material number in system.  This and the previous word
!          occupy the same location.
!  sysnam  name for system.
!  sysopt  system options flags; 1=no noncondensibles, 2=no molten
!          material.
!  tpfnha  thermodynamic properties file name (5 Hollerith words) for
!          sysmat, as read from 120-129 input cards.
