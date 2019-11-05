*mlist
c
c  Cognizant engineer:
c
c  pmpold  actual pump angular velocity
c  pmprsp  rated pump angular velocity
c  pmpspr  ratio of initial to rated pump velocity (input), old angular
c          velocity (during advancement).
c  pmprfl  rated pump flow
c  pmprhd  rated pump head
c  pmprtk  rated pump torque
c  pmpint  pump moment of inertia
c  pmprho  rated or initial density
c  pmprmt  rated pump motor torque
c  pmptf1,pmptf2,pmptf3,pmptfy  coefficients for frictional torque as a
c         cubic function of speed ratio
c  pmpstm  elapsed time of pump trip
c  pmpfsp  maximum foward speed for trip
c  pmpbsp  maximum reverse speed for trip
c  pmpmt   motor torque.
c  pmpnrt  calculated pump inertia.
c  pmpthd  pump head.
c  pmpttk  pump torque.
c  iputrp(1)  trip for pump motor power.
c  iputrp(2)  offset to trip during input, index during transient.
c  ipurvi  shaft component number.
c  ipuctr(1)  shaft disconnect trip number.
c  ipuctr(2)  offset to trip during input, index during transient.
c  iputdi(1)  offset from beginning of this component to single phase
c             homologous table octant offsets if no referral,
c             referred component number if referral.
c  iputdi(2)  offset from origin of component block to single phase
c             octant offsets.
c  iputdi(3)  offset to be added to octant offsets.
c  ipuhmi(1)  offset within this component to two phase head multiplier
c             if no referal, referred component number if referral.
c  ipuhmi(2)  offset from origin of component block to two phase head
c             multiplier table.
c  iputmi(1 and 2)  same as for ipuhmi(1 and 2) except for two phase
c                   torque multiplier table.
c  ipu2di(1, 2, and 3)  same as for iputdi(1, 2, and 3) except for
c                       two phase homologous tables.
c  ipumtk(1 and 2)  same as for ipuhmi(1 and 2) except for pump motor
c                   torque table.
c  ipuspi(1 and 2)  same as for ipuhmi(1 and 2) except for pump speed
c                   table data.
c  ipmvtr(1)  pump velocity table trip number.
c  ipmvtr(2)  offset to trip during input, index during transient.
c  ipmval  alphanumeric part of variable request code.
c  ipmvnm  numeric part of variable request code.
c  ipmvpc(1)  dynamic block number.
c  ipmvpc(2)  offset during input, index during transient.
c  ipmvtl(1)  number of items/entry.
c  ipmvtl(2)  total number of items.
c  ipmvtl(3)  current position in table.
c  pmpvtl  entries for pump velocity table.
