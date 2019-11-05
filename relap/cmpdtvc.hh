*mlist
c
c  Cognizant engineer: rjw.
c
c  definitions to all valves:
c  vlvnm   valve type.
c  atlast  normalized full open valve area.
c  definitions to check valves:
c  pcv     back pressure to close valve.
c  aleak   normalized area of valve leakage.
c
c  definitions to trip valves:
c  vlvtrp  trip number.
c  definitions to inertial valve:
c  pvc     valve hinge cracking dp used for coulomb damping torque.
c  theta   valve disk angular position.
c  thetao  valve disk angular position, old time.
c  mintht  minimum valve disk angular position.
c  maxtht  maximum valve disk angular position.
c  moment  mass moment of inertia of valve disk.
c  omega   valve disk angular velocity.
c  omegao  valve disk angular velocity, old time.
c  lngvlv  length of valve disk moment arm.
c  rdsvlv  valve disk radius.
c  aflapr  valve disk area.
c
c  definitions to motor valve:
c  opntrp  open trip number.
c  clstrp  close trip number.
c  vlvslp  rate of change of normalized stem position.
c  vlstm   normalized stem position.
c  vlstmo  normalized stem position, old time.
c  vlvtbl  table number of "normarea" table.
c  vlvcon  multiplier for converting csubv to form loss.
c  ncvtbl  variable used for table interpolation as follows:
c          unused (15 bits), number of items/entry (15 bits),
c          total number of items (15 bits), current subscript
c          (15 bits).
c  cvtbl   table enteries (sets of three starting with
c          normalized stem position, fjunf, fjunr).
c
c  definitions to servo valve:
c  opntrp  control variable number.
c  clstrp  used for control variable information.
c  vlstm   normalized stem position, controlled by control
c          variable.
c  vlvtbl  table number of "normarea" table.
