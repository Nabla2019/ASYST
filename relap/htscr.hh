*mlist
!  Scratch storage for heat conduction advancement.
!
!  Cognizant engineer: rjw.
!
       integer htscrp,htsxrp
       parameter (htscrp=14,htsxrp=27)
       real htgsmf(l_),htgsmg(l_),hthht(l_),hthhff(l_),hthhft(l_),
     & hthhgg(l_),hthhgt(l_),hthhgp(l_),htqosf(l_),htqosg(l_),
     & htqost(l_),qradlr(l_),hte(l_),htb(l_),htee(l_),htf(l_),httc(l_),
     & htvhc(l_)
       integer htflag(l_)
       equivalence (htgsmf(1),fa(1)),(htgsmg(1),fa(3)),
     & (hthht(1),fa(5)),(hthhff(1),fa(7)),(hthhft(1),fa(9)),
     & (hthhgg(1),fa(11)),(hthhgt(1),fa(13)),(hthhgp(1),fa(15)),
     & (htqosf(1),fa(17)),(htqosg(1),fa(19)),(htqost(1),fa(21)),
     & (qradlr(1),fa(23)),(htflag(1),ia(25)),(hte(1),fa(27)),
     & (htb(1),fa(28)),(htee(1),fa(29)),(htf(1),fa(30)),
     & (httc(1),fa(39)),(htvhc(1),fa(40))
!
!  htgsmf Factor to convert heat flux to interface mass transfer due to
!         flashing.
!  htgsmg Factor to convert heat flux to interface mass transfer due to
!         condensing.
!  hthht  Total heat transfer coefficient from wall to fluid.
!  hthhff Heat transfer coefficient from wall to liquid using liquid
!         temperature.
!  hthhft Heat transfer coefficient from wall to liquid using saturation
!         temperature corresponding to total pressure.
!  hthhgg Heat transfer coefficient from wall to vapor using vapor
!         temperature.
!  hthhgt Heat transfer coefficient from wall to vapor using saturation
!         temperature corresponding to total pressure.
!  hthhgp Heat transfer coefficient from wall to vapor using saturation
!         temperature corresponding to partial pressure.
!  htqosf Old time heat flux to liquid.
!  htqosg Old time heat flux to vapor.
!  htqost Old time total heat flux to fluid.
!  qradlr Radiation heat flux.
!  htb    Diagonal term of triangular matrix.
!  hte    Temporary storage for left part of tridiagonal matrix.
!  htee   Temporary storage for right part of tridiagonal matrix.
!  htf    Temporary storage for right hand side of heat conduct. eqs.
!  httc   Temporary storage for thermal conductivity.
!  htvhc  Temporary storage for volumetric heat capacity.
