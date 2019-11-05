*mlist
!
!  Cognizant engineer: rjw.
!
!  definitions for valve component
       integer vlvnm(l_)
       real pcv(l_),aleak(l_),atlast(l_),vlstm(l_)
!  definitions for trip valve
       integer vlvtrp(l_)
!  definitions for inertial valve
       real theta(l_),thetao(l_),mintht(l_),maxtht(l_),moment(l_),
     &      omega(l_),omegao(l_),lngvlv(l_),rdsvlv(l_),vlfmas(l_),
     &      aflapr(l_)
!  definitions for motor and servo valves.
       integer opntrp(l_),clstrp(l_),tblnum(l_),ncvtbl(l_)
       real vlvslp(l_),vlstmo(l_),vlvcon(l_),cvtbl(l_)
!  definitions for relief valve
       real adisk(l_),abelan(l_),abelin(l_),arings(l_),pbellw(l_),
     & bdamp(l_),sprcon(l_),velvl(l_),velvlo(l_),vlsetp(l_),vlstmx(l_),
     & adann(l_),dseat(l_),drings(l_),hring1(l_),hring2(l_),areaxx(l_)
       equivalence (vlvnm(1),ia(13)),(atlast(1),fa(14)),
     & (vlstm(1),fa(15)),(vlstmo(1),moment(1),fa(16))
       equivalence (pcv(1),pbellw(1),fa(17)),
     & (aleak(1),areaxx(1),fa(18))
       equivalence (vlvtrp(1),ia(19))
       equivalence (theta(1),fa(19)),(thetao(1),fa(20)),
     & (mintht(1),fa(21)),(maxtht(1),fa(22)),(omega(1),fa(23)),
     & (omegao(1),fa(24)),(lngvlv(1),fa(25)),(vlfmas(1),fa(26)),
     & (rdsvlv(1),fa(27)),(aflapr(1),fa(28))
       equivalence (opntrp(1),ia(17)),(clstrp(1),ia(19)),
     & (tblnum(1),ia(21)),(vlvslp(1),fa(23)),(vlvcon(1),fa(24)),
     & (ncvtbl(1),ia(25)),(cvtbl(1),fa(28))
       equivalence (dseat(1),fa(21)),(drings(1),fa(22)),
     & (bdamp(1),fa(23)),(sprcon(1),fa(24)),(vlsetp(1),fa(25)),
     & (velvl(1),fa(27)),(velvlo(1),fa(28)),(vlstmx(1),fa(29)),
     & (adisk(1),fa(30)),(abelan(1),fa(31)),(abelin(1),fa(32)),
     & (arings(1),fa(33)),(adann(1),fa(34)),(hring1(1),fa(35)),
     & (hring2(1),fa(36))
!
!  definitions to all valves:
!  vlvnm   valve type.
!  atlast  normalized full open valve area.
!  definitions to check valves:
!  pcv     back pressure to close valve.
!  aleak   normalized area of valve leakage.
!
!  definitions to trip valves:
!  vlvtrp  trip number.
!  definitions to inertial valve:
!  pvc     valve hinge cracking dp used for coulomb damping torque.
!  theta   valve disk angular position.
!  thetao  valve disk angular position, old time.
!  mintht  minimum valve disk angular position.
!  maxtht  maximum valve disk angular position.
!  moment  mass moment of inertia of valve disk.
!  omega   valve disk angular velocity.
!  omegao  valve disk angular velocity, old time.
!  lngvlv  length of valve disk moment arm.
!  rdsvlv  valve disk radius.
!  aflapr  valve disk area.
!
!  definitions to motor valve:
!  opntrp  open trip number.
!  clstrp  close trip number.
!  vlvslp  rate of change of normalized stem position.
!  vlstm   normalized stem position.
!  vlstmo  normalized stem position, old time.
!  vlvtbl  table number of "normarea" table.
!  vlvcon  multiplier for converting csubv to form loss.
!  ncvtbl  variable used for table interpolation as follows:
!          unused (15 bits), number of items/entry (15 bits),
!          total number of items (15 bits), current subscript
!          (15 bits).
!  cvtbl   table enteries (sets of three starting with
!          normalized stem position, fjunf, fjunr).
!
!  definitions to servo valve:
!  opntrp  control variable number.
!  clstrp  used for control variable information.
!  vlstm   normalized stem position, controlled by control
!          variable.
!  vlvtbl  table number of "normarea" table.
