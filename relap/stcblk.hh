*mlist
!  Cognizant engineer: rjw.
!
       common  /stcblk/ nfluid,ndxstd
       integer  nfluid,ndxstd
!
!  nfluid  fluid number:
!           1 = light water
!           2 = heavy water
!           3 = hydrogen
!           4 = lithium
!           5 = potassium
!           6 = helium
!           7 = nitrogen
!           8 = sodium
!           9 = NaK
!          10 = lithium-lead
!          11 = ammonia
!          12 = new light water (based on internal energy and pressure)
!          13 = glycerol
!          14 = blood
!  ndxstd  pointer in fa array to first word of steam tables for fluid
!          with fluid number nfluid.
