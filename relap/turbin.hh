*mlist
!  Turbine component block.
!
!  Cognizant engineer: rjw.
!
       real turvel(l_),turint(l_),turfr(l_),turpow(l_),turtrq(l_),
     & tureff(l_),turrds(l_),turdef(l_),turx(l_),turfru(l_),pideal(l_)
       integer turscm(l_),turctr(l_),turupj(l_)
       equivalence (turscm(1),ia(13)),(turctr(1),ia(14)),
     & (turupj(1),ia(16)),(turvel(1),fa(17)),(turint(1),fa(18)),
     & (turfr (1),fa(19)),(turpow(1),fa(20)),(turtrq(1),fa(21)),
     & (tureff(1),fa(22)),(turrds(1),fa(23)),(turdef(1),fa(24)),
     & (turx(1),fa(25)),(turfru(1),fa(26)),(pideal(1),fa(27))
!
!  turscm     Shaft component number.
!  turctr(1)  Turbine disconnect trip number.
!  turctr(2)  Offset for above during input, index during transient.
!  turupj     Junction number upstream of stage.
!  turvel     Turbine rotational velocity.
!  turint     Turbine moment of inertia.
!  turfr      Turbine friction factor.
!  turpow     Power developed by turbine.
!  turtrq     Torque developed by turbine.
!  tureff     Turbine efficiency.
!  turrds     Mean stage blade radius.
!  turdef     Max. stage efficiency.
!  turx       Stage reaction ratio.
!  turfru     Rate of enery added to fluid energy from friction in 
!             turbine stage.
!  pideal     Mechanical power from turbine if 100% efficiency.
