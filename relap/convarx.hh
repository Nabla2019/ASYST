*mlist
c
c  Cognizant engineer: rjw.
c
c  cnvnum  number of components.
c  cnvopt  units (1 bit), flag for maximum number of components
c          possible (2 bit), generator present flag (4 bit).
c  cnvpnm  component number.
c  cnvtyp  control component type.
c  cnvnam  control component alphanumeric name.
c  cnvnpa  number of terms or factors.
c  cnvlen  number of words in component.
c  cnvnop  initialization flag (1 bit), initialization type,(2 bit),
c          minimum flag (4 bit), maximum flag (8 bit), generator flag
c          (16 bit), units (32 bit), trip complement (64 bit), standard
c          function type (shifted left 24 bits).
c  cnvmin  minimum value permitted component.
c  cnvmax  maximum value permitted component.
c  cnvarn  new value of control variable.
c  cnvaro  Units conversion factor.
c  cnvscl  scale factor.
c  cnvalf  alphanumeric part of variable request code.
c  cnvint  integer part of variable request code.
c  cnvpck(1)  block number.
c  cnvpck(2)  offset within block during input processisng, index during
c             transient.
c  cnvsan  "a" factor in sum or pid control components.
c  cnvold  old values needed in differen or pid component blocks.
c  cnvtrp(1)  trip number.
c  cnvtrp(2)  offset within block to trip during input processing, index
c             during transient.
c  cnvgen(1)  table number input.
c  cnvgen(2)  offset during input processing, index during transient.
c  cnvdla  delay time.
c  cnvdli  delay time divided by number of hold values.
c  cnvdft  slope for delay interpolation.
c  cnvdct(1)  last entered table posistion.
c  cnvdct(2)  number of table positions.
c  cnvdct(3)  delay table position.
c  cnvnxt  time to store next value.
c  cnvtbl  delay table values.
c  cnvsin  inertia for shaft component.
c  cnvsfr  friction factor for shaft component.
c  cnvsct(1)  control variable number for torque.
c  cnvsct(2)  offset during input processing, index during transient.
c  cnvscp(1)  connected component type.
c  cnvscp(2)  connected component number.
c  cnvscp(3)  block number.
c  cnvscp(4)  offset during input processisng, index during transient.
c  gentrp(1)  generator trip number.
c  gentrp(2)  offset during input processing, index during transient.
c  gendtr(1)  generator disconnect trip number.
c  gendtr(2)  offset during input processing, index during transient.
c  genvel  generator rotational velocity.
c  gensvl  generator synchronous rotational velocity.
c  genint  generator inertia.
c  genfr   generator friction factor.
c  gentrq  generator torque.
c  genpow  generator power input.
