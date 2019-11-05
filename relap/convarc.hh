*mlist
!  Control component data.
!
!  Cognizant engineer: rjw.
!
!  Control variable block.
       integer cnvnum(l_),cnvopt(l_),cnvpnm(l_),cnvtyp(l_),
     & cnvnpa(l_),cnvlen(l_),cnvnop(l_),cnvint(l_),cnvpck(l_),
     & cnvtrp(l_),cnvgen(l_),cnvdct(l_),cnvsct(l_),cnvscp(l_)
       real cnvnam(l_),cnvalf(l_)
       real cnvmin(l_),cnvmax(l_),cnvarn(l_),cnvaro(l_),cnvscl(l_),
     & cnvsin(l_),cnvsfr(l_),cnvsan(l_),cnvold(l_),cnvdla(l_),
     & cnvdli(l_),cnvdft(l_),cnvnxt(l_),cnvtbl(l_)
       equivalence (cnvnum(1),ia(1)),(cnvopt(1),ia(2)),
     & (cnvpnm(1),ia(3)),(cnvtyp(1),ia(4)),(cnvnam(1),fa(5)),
     & (cnvnpa(1),ia(6)),(cnvlen(1),ia(7)),(cnvnop(1),ia(8)),
     & (cnvmin(1),fa(9)),(cnvmax(1),fa(10)),(cnvarn(1),fa(11)),
     & (cnvaro(1),fa(12)),(cnvscl(1),cnvsin(1),fa(13)),
     & (cnvtrp(1),ia(14)),(cnvalf(1),cnvsfr(1),fa(14)),
     & (cnvint(1),cnvsct(1),ia(15)),(cnvpck(1),ia(16)),
     & (cnvscp(1),ia(17)),(cnvgen(1),ia(18)),
     & (cnvold(1),cnvsan(1),cnvdla(1),fa(18)),
     & (cnvdli(1),fa(19)),(cnvdft(1),fa(20)),(cnvdct(1),ia(21)),
     & (cnvnxt(1),fa(24)),(cnvtbl(1),fa(25))
       integer gentrp(l_),gendtr(l_)
       real genvel(l_),gensvl(l_),genint(l_),genfr(l_),gentrq(l_),
     & genpow(l_)
       equivalence (gentrp(1),ia(17)), (gendtr(1),ia(19)),
     & (genvel(1),fa(21)), (gensvl(1),fa(22)), (genint(1),fa(23)),
     & (genfr(1),fa(24)), (gentrq(1),fa(25)), (genpow(1),fa(26))
!
!  cnvnum  number of components.
!  cnvopt  units (1 bit), flag for maximum number of components
!          possible (2 bit), generator present flag (4 bit).
!  cnvpnm  component number.
!  cnvtyp  control component type.
!  cnvnam  control component alphanumeric name.
!  cnvnpa  number of terms or factors.
!  cnvlen  number of words in component.
!  cnvnop  initialization flag (1 bit), initialization type,(2 bit),
!          minimum flag (4 bit), maximum flag (8 bit), generator flag
!          (16 bit), units (32 bit), trip complement (64 bit), standard
!          function type (shifted left 24 bits).
!  cnvmin  minimum value permitted component.
!  cnvmax  maximum value permitted component.
!  cnvarn  new value of control variable.
!  cnvaro  Units conversion factor.
!  cnvscl  scale factor.
!  cnvalf  alphanumeric part of variable request code.
!  cnvint  integer part of variable request code.
!  cnvpck(1)  block number.
!  cnvpck(2)  offset within block during input processisng, index during
!             transient.
!  cnvsan  "a" factor in sum or pid control components.
!  cnvold  old values needed in differen or pid component blocks.
!  cnvtrp(1)  trip number.
!  cnvtrp(2)  offset within block to trip during input processing, index
!             during transient.
!  cnvgen(1)  table number input.
!  cnvgen(2)  offset during input processing, index during transient.
!  cnvdla  delay time.
!  cnvdli  delay time divided by number of hold values.
!  cnvdft  slope for delay interpolation.
!  cnvdct(1)  last entered table posistion.
!  cnvdct(2)  number of table positions.
!  cnvdct(3)  delay table position.
!  cnvnxt  time to store next value.
!  cnvtbl  delay table values.
!  cnvsin  inertia for shaft component.
!  cnvsfr  friction factor for shaft component.
!  cnvsct(1)  control variable number for torque.
!  cnvsct(2)  offset during input processing, index during transient.
!  cnvscp(1)  connected component type.
!  cnvscp(2)  connected component number.
!  cnvscp(3)  block number.
!  cnvscp(4)  offset during input processisng, index during transient.
!  gentrp(1)  generator trip number.
!  gentrp(2)  offset during input processing, index during transient.
!  gendtr(1)  generator disconnect trip number.
!  gendtr(2)  offset during input processing, index during transient.
!  genvel  generator rotational velocity.
!  gensvl  generator synchronous rotational velocity.
!  genint  generator inertia.
!  genfr   generator friction factor.
!  gentrq  generator torque.
!  genpow  generator power input.
