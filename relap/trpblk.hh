*mlist
!  trpblk is the trip block.
!
!  Cognizant engineer: rjw.
!
!  trip block
       integer ntvskp,ntlskp
       parameter (ntvskp=12,ntlskp=7)
       integer ntrpnv(l_),ntrpnl(l_),ntrpof(l_),ntrps1(l_),ntrps2(l_),
     & ntrpff(l_)
       integer ntrpno(l_),ntrpop(l_),ntrnv1(l_),ntrpc1(l_),
     & ntrnv2(l_),ntrpc2(l_)
       real ntrcv1(l_),ntrcv2(l_)
       integer ntrtr1(l_),ntrtr2(l_)
       real trptim(l_),trpcon(l_),trptm(l_)
       equivalence (ntrpnv(1),ia(1)),(ntrpnl(1),ia(2)),
     & (ntrpof(1),ia(3)),(ntrps1(1),ia(4)),(ntrps2(1),ia(6)),
     & (ntrpff(1),ia(8)),
     & (trptim(1),fa(9)),(ntrpno(1),ia(10)),(ntrpop(1),ia(11)),
     & (ntrcv1(1),fa(12)),(ntrnv1(1),ia(13)),(ntrpc1(1),ia(14)),
     & (ntrcv2(1),fa(16)),(ntrnv2(1),ia(17)),(ntrpc2(1),ia(18)),
     & (trpcon(1),fa(20))
       equivalence (ntrtr1(1),ia(12)),(ntrtr2(1),ia(14))
       equivalence (trptm(1),fa(1))
!
! T Name    Definition
! i ntvskp  variable trip skip factor (parameter set to 12 in trpblk.H)
! i ntlskp  logical trip skip factor (parameter set to 7 in trpblk.H)
! i ntrpnv  number of variable trips.
! i ntrpnl  number of logical trips.
! i ntrpof  offset to logical trips.
! i ntrps1(1)  first trip number to terminate advancement.
! i ntrps1(2)  offset to first trip during input processing,
!              index to first trip during transient.
! i ntrps2(1)  second trip number to terminate advancement.
! i ntrps2(2)  offset to second trip during input processing,
!              index to second trip during transient.
!
!  following block is repeated ntrpnv times (once for each variable trip
!  block is ntrpnv (12) words long
!
! T Name    Definition
! r trptim  time trip was set, also used used as trip switch.
!           negative if trip not set or false,
!           positive if set or true and the value is the time the trip
!            was set.
! r trptm   same variable as trptim but used with different subcripts.
!           trptim used in loops over all trips.
!           trptm used when subscripting obtained from itrscn subroutine
!            is used.
! i ntrpno  trip number
! i ntrpop  trip operation packed word,
!           Bits numbered 1-32 from right end
!           1 (=1) initialization flag (1 bit),
!           2 (=2) latch code (2 bit),
!           3 (=4) timeof flag left variable (4 bit),
!           4 (=8) timeof flag right variable (8 bit),
!           5 (=16) sign bit on left trip number (16 bit),
!           6 (=32) sign bit on right trip number (32 bit),
!           25 (=16,777,216) operation code (shifted left 24 bits).
! c ntrcv1  variable code, left side.
! i ntrnv1  number part of variable code, left side.
! i ntrpc1(1)  block number of left variable.
! i ntrpc1(2)  offset to left variable during input,
!              index to left variable during transient.
! c ntrcv2  variable code, right side.
! i ntrnv2  number part of variable code, right side.
! i ntrpc2(1)  block number of right variable.
! i ntrpc2(2)  offset to right variable during input,
!              index to right variable during transient.
! r trpcon  constant on right side.
!
!  following block is repeated ntrpnl times (once for each logical trip)
!  block is ntrpnl (7) words long
!
! r trptim  time trip was set, also used used as trip switch.
!           negative if trip not set or false,
!           positive if set or true and the value is the time the trip
!            was set.
! r trptm   same variable as trptim but used with different subcripts.
!           trptim used in loops over all trips.
!           trptm used when subscripting obtained from itrscn subroutine
!            is used.
! i ntrpno  trip number
! i ntrpop  trip operation packed word,
!           Bits numbered 1-32 from right end
!           1 (=1) initialization flag (1 bit),
!           2 (=2) latch code (2 bit),
!           3 (=4) timeof flag left variable (4 bit),
!           4 (=8) timeof flag right variable (8 bit),
!           5 (=16) sign bit on left trip number (16 bit),
!           6 (=32) sign bit on right trip number (32 bit),
!           25 (=16,777,216) operation code (shifted left 24 bits).
! i ntrtr1(1)  left operand trip number.
! i ntrtr1(2)  offset to left trip time during input processing,
!              index to left trip time during transient.
! i ntrtr2(1)  right operand trip number.
! i ntrtr2(2)  offset to right trip time during input processing,
!              index to right trip time during transient.
