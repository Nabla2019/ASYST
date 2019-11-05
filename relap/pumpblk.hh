*mlist
!
!  Cognizant engineer: rjw.
!
! pump block.
       real pmprsp(l_),pmpspr(l_),pmprfl(l_),pmprhd(l_),
     & pmprtk(l_),pmpint(l_),pmprho(l_),pmprmt(l_),pmptf1(l_),
     & pmptf2(l_),pmptf3(l_),pmptf4(l_),pmpold(l_),pmpmt(l_),pmpnrt(l_),
     & pmpthd(l_),pmpttk(l_),pmptrp(l_)
       real pmpstm(l_),pmpfsp(l_),pmpbsp(l_),pmptbl(l_),pmpvtl(l_)
       integer iputdi(l_),ipuhmi(l_),iputmi(l_),ipu2di(l_),ipuctr(l_),
     & ipumtk(l_),ipuspi(l_),iputrp(l_),ipurvi(l_),ipmtbl(l_),
     & ipmvtr(l_),ipmvnm(l_),ipmvpc(l_),ipmvtl(l_)
       real ipmval(l_)
       equivalence (pmpold(1),fa(13)), (pmprsp(1),fa(14)),
     & (pmpspr(1),fa(15)), (pmprfl(1),fa(16)), (pmprhd(1),fa(17)),
     & (pmprtk(1),fa(18)), (pmpint(1),fa(19)), (pmprho(1),fa(20)),
     & (pmprmt(1),fa(21)), (pmptf1(1),fa(22)), (pmptf2(1),fa(23)),
     & (pmptf3(1),fa(24)), (pmptf4(1),fa(25)), (pmpstm(1),fa(26)),
     & (pmpfsp(1),fa(27)), (pmpbsp(1),fa(28)), (iputrp(1),ia(29)),
     & (ipurvi(1),ia(31)), (iputdi(1),ia(32)), (ipuhmi(1),ia(35)),
     & (iputmi(1),ia(37)), (ipu2di(1),ia(39)), (ipumtk(1),ia(42)),
     & (ipuspi(1),ia(44)), (ipuctr(1),ia(46)), (pmpmt(1),fa(48)),
     & (pmpnrt(1),fa(49)), (pmpthd(1),fa(50)), (pmpttk(1),fa(51)),
     & (pmptrp(1),fa(52)),(pmptbl(1),fa(2)),
     & (ipmtbl(1),ipmvtr(1),ia(2)),(ipmval(1),fa(4)),
     & (ipmvnm(1),ia(5)),(ipmvpc(1),ia(6)),(ipmvtl(1),ia(8)),
     & (pmpvtl(1),fa(11))
!
!  pmpold  actual pump angular velocity
!  pmprsp  rated pump angular velocity
!  pmpspr  ratio of initial to rated pump velocity (input), old angular
!          velocity (during advancement).
!  pmprfl  rated pump flow
!  pmprhd  rated pump head
!  pmprtk  rated pump torque
!  pmpint  pump moment of inertia
!  pmprho  rated or initial density
!  pmprmt  rated pump motor torque
!  pmptf1,pmptf2,pmptf3,pmptfy  coefficients for frictional torque as a
!         cubic function of speed ratio
!  pmpstm  elapsed time of pump trip
!  pmpfsp  maximum foward speed for trip
!  pmpbsp  maximum reverse speed for trip
!  pmpmt   motor torque.
!  pmpnrt  calculated pump inertia.
!  pmpthd  pump head.
!  pmpttk  pump torque.
!  iputrp(1)  trip for pump motor power.
!  iputrp(2)  offset to trip during input, index during transient.
!  ipurvi  shaft component number.
!  ipuctr(1)  shaft disconnect trip number.
!  ipuctr(2)  offset to trip during input, index during transient.
!  iputdi(1)  offset from beginning of this component to single phase
!             homologous table octant offsets if no referral,
!             referred component number if referral.
!  iputdi(2)  offset from origin of component block to single phase
!             octant offsets.
!  iputdi(3)  offset to be added to octant offsets.
!  ipuhmi(1)  offset within this component to two phase head multiplier
!             if no referal, referred component number if referral.
!  ipuhmi(2)  offset from origin of component block to two phase head
!             multiplier table.
!  iputmi(1 and 2)  same as for ipuhmi(1 and 2) except for two phase
!                   torque multiplier table.
!  ipu2di(1, 2, and 3)  same as for iputdi(1, 2, and 3) except for
!                       two phase homologous tables.
!  ipumtk(1 and 2)  same as for ipuhmi(1 and 2) except for pump motor
!                   torque table.
!  ipuspi(1 and 2)  same as for ipuhmi(1 and 2) except for pump speed
!                   table data.
!  ipmvtr(1)  pump velocity table trip number.
!  ipmvtr(2)  offset to trip during input, index during transient.
!  ipmval  alphanumeric part of variable request code.
!  ipmvnm  numeric part of variable request code.
!  ipmvpc(1)  dynamic block number.
!  ipmvpc(2)  offset during input, index during transient.
!  ipmvtl(1)  number of items/entry.
!  ipmvtl(2)  total number of items.
!  ipmvtl(3)  current position in table.
!  pmpvtl  entries for pump velocity table.
