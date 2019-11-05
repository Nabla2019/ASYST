*mlist
!
!  Descriptive sentence for separ goes here.
!
!  Cognizant engineer: rjw.
!
!  separator designator
       integer isepst(l_),nsep(l_)
!
!  standard separator component block
       real  vover(l_),vunder(l_)
!
!  ge separator geometric quantiities
       real  gerr1(l_), geai(l_), gean(l_), gerh(l_),
     &       geang(l_), gerws(l_), gerrss(l_), geads(l_), gedds(l_),
     &       gehds(l_), gehsks(l_), gecks(l_), geefflds(l_), geaas(l_),
     &       gebbs(l_), cwfco(l_), cwgcu(l_)
!  ge separator performance quantities
       real  xim(l_), xco(l_), xcu(l_)
!
!  dryer quantities
       real vdryl(l_), vdryu(l_), deldim(l_)
!
       equivalence
     & (vover(1),fa(13)),   (vunder(1),fa(14)),
     & (gerr1(1),fa(15)),   (geai(1),fa(16)),
     & (gean(1),fa(17)),    (gerh(1),fa(18)),
     & (geang(1),fa(19)),   (gerws(1),fa(20)),
     & (gerrss(1),fa(23)),  (geads(1),fa(26)),
     & (gedds(1),fa(29)),   (gehds(1),fa(32)),
     & (gehsks(1),fa(35)),  (gecks(1),fa(38)),
     & (geefflds(1),fa(41)),(geaas(1),fa(44)),
     & (gebbs(1),fa(47)),
     & (vdryl(1),fa(50)),   (vdryu(1),fa(51)),
     & (deldim(1),fa(52)),  (isepst(1),ia(53)),
     & (nsep(1),ia(54)),    (xim(1),fa(55)),
     & (xco(1),fa(56)),     (xcu(1),fa(57)),
     & (cwfco(1),fa(58)),   (cwgcu(1),fa(59))
!  Moving effects data.
!
!  vover   Void limit for ideal vapor outflow
!  vunder  Void limit for ideal liquid fall back
!  sepmpr(1)  Motion effects flag, 0 if no table, component number where
!             table is located which may be this component.
!  sepmpr(2)  Offset within this block where table is located. This
!             word is zero if no table is being used.
!  seplra(1)  Last search argument for first independent variable.
!  seplra(2)  Last search argument for second independent variable.
!  sepvdf(1)  Last result for vover.
!  sepvdf(2)  Last result for vunder.
!  sepmtp  Table type, 1 if one dimensional, 2 if two dimensional.
!  sepmin(1)  Number of items in table
!  sepmin(2)  Number of items per set.
!  sepmin(3)  Last position for interpolation.
!  sepnp      Number of Phi angles
!  sepnt      Number of Theta angles
!  sepphi     Vector of Phi (polar or tilt) angles.  Length at most 10.
!  septht     Vector of Theta (azimuthal) angles.  Length at most 20.
!  septbl     Table values.
