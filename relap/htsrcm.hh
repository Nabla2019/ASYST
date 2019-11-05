*mlist
!  Heat structures data.
!
!  Cognizant engineer: rjw.
!
!  Heat structures arrays block.
       integer htfixa,htgskp
       parameter (htfixa=115,htgskp=8)
!  For director array.
       integer nhtstr(l_),ihtptr(l_)
       equivalence (nhtstr(1),ia(1)),(ihtptr(1),ia(2))
!  For storage array.
       integer htstno(l_),htopt(l_),htxft(l_),htxit(l_),htgmr(l_),
     & htgom(l_),htsrt(l_),htbvc(l_),htbvo(l_),htbnt(l_),htbntr(l_),
     & htbnts(l_),htstyp(l_),htgap(l_),htnmpt(l_),htrflg(l_),htnaxl(l_),
     & htnusr(l_),htiscr(l_),imw(l_),htrfpt(l_)
       integer htivfc(l_),htivfo(l_),htivrc(l_),htivro(l_),pgopti(l_),
     & pgcall(l_)
       real htmod(l_),htfctr(l_),htsrfo(l_),htsrfn(l_),htrnro(l_),
     & htrnrn(l_),htrnso(l_),htrnsn(l_),htcffo(l_),htcffn(l_),
     & htftro(l_),htftrn(l_),htpowo(l_),htpown(l_),httots(l_),
     & htimeo(l_),htdt(l_),hthdmo(l_),hthdmn(l_),htchfo(l_),htchfn(l_),
     & htvatp(l_),htdtmo(l_),htdtmn(l_),htbcao(l_),htbcco(l_),
     & htbcan(l_),htbccn(l_),httmp(l_),chfmuo(l_),chfmun(l_),htrfno(l_),
     & htrfnn(l_),htrfoo(l_),htrfon(l_),htrgno(l_),htrgnn(l_),
     & htrgoo(l_),htrgon(l_),htcfgo(l_),htcfgn(l_),gprouf(l_),
     & gpudis(l_),htrado(l_),htradn(l_),htlnfo(l_),htlnfn(l_),
     & htlnro(l_),htlnrn(l_),grdzfo(l_),grdzfn(l_),grdzro(l_),
     & grdzrn(l_),grdkfo(l_),grdkfn(l_),grdkro(l_),grdkrn(l_),
     & apfaco(l_),apfacn(l_),oxti(l_),oxto(l_),oxtio(l_),oxtoo(l_),
     & h2gen(l_),h2geno(l_),gapwd(l_),cladex(l_),hetrat(l_),strnpl(l_)
       equivalence (htstno(1),ia(1)),(htopt(1),ia(2)),(htxft(1),ia(3)),
     & (htxit(1),ia(4)),(htgmr(1),ia(5)),(htgom(1),ia(6)),
     & (htsrt(1),ia(7)),(htbvc(1),ia(9)),(htbvo(1),ia(11)),
     & (htbnt(1),ia(13)),(htbntr(1),ia(15)),(htbnts(1),ia(17)),
     & (htstyp(1),ia(19)),(htmod(1),fa(19)),(htgap(1),ia(21)),
     & (htnmpt(1),ia(23)),(htrflg(1),ia(24)),(htnaxl(1),ia(26)),
     & (htnusr(1),ia(27)),(htfctr(1),fa(28)),(htsrfo(1),fa(29)),
     & (htsrfn(1),fa(30)),(htrnro(1),fa(31)),(htrnrn(1),fa(32)),
     & (htrnso(1),htcffo(1),fa(33)),(htrnsn(1),htcffn(1),fa(34)),
     & (htftro(1),fa(35)),(htftrn(1),fa(36)),
     & (htpowo(1),fa(37)),(htpown(1),fa(38)),(httots(1),fa(39)),
     & (htimeo(1),fa(40)),(htdt(1),fa(41)),(hthdmo(1),fa(42)),
     & (hthdmn(1),fa(43)),(htchfo(1),fa(44)),(htchfn(1),fa(45)),
     & (htvatp(1),fa(46)),(htdtmo(1),fa(47)),(htdtmn(1),fa(48))
       equivalence (htbcao(1),fa(49)),(htbcan(1),fa(50)),
     & (chfmuo(1),fa(51)),(chfmun(1),fa(52)),(htbcco(1),fa(53)),
     & (htbccn(1),fa(54)),(htrfno(1),fa(55)),(htrfnn(1),fa(56)),
     & (htrfoo(1),fa(57)),(htrfon(1),fa(58)),(htrgno(1),fa(59)),
     & (htrgnn(1),fa(60)),(htrgoo(1),htcfgo(1),fa(61)),
     & (htrgon(1),htcfgn(1),fa(62)),(gprouf(1),fa(63)),
     & (gpudis(1),fa(64)),(htrado(1),fa(65)),(htradn(1),fa(66)),
     & (htlnfo(1),fa(67)),(htlnfn(1),fa(68)),(htlnro(1),fa(69)),
     & (htlnrn(1),fa(70)),(grdzfo(1),fa(71)),(grdzfn(1),fa(72)),
     & (grdzro(1),fa(73)),(grdzrn(1),fa(74)),(grdkfo(1),fa(75)),
     & (grdkfn(1),fa(76)),(grdkro(1),fa(77)),(grdkrn(1),fa(78)),
     & (apfaco(1),fa(79)),(apfacn(1),fa(80)),(htiscr(1),ia(81)),
     & (oxti(1),fa(82)),(oxto(1),fa(83)),(oxtio(1),fa(84)),
     & (oxtoo(1),fa(85)),(h2gen(1),fa(86)),(h2geno(1),fa(87)),
     & (imw(1),fa(88)),(gapwd(1),fa(89)),(cladex(1),fa(90)),
     & (hetrat(1),fa(91)),(strnpl(1),fa(92))
       real stanto(l_),stantn(l_),peclo(l_),pecln(l_),htlncf(l_),
     & htpovd(l_),htfftr(l_)
       equivalence (stanto(1),fa(93)),(stantn(1),fa(94)),
     & (peclo(1),fa(95)),(pecln(1),fa(96)),(htlncf(1),fa(97)),
     & (htpovd(1),fa(99)),(htfftr(1),fa(101)),
     & (htivfc(1),ia(103)),(htivfo(1),ia(105)),
     & (htivrc(1),ia(107)),(htivro(1),ia(109)),
     & (pgopti(1),ia(111)),(pgcall(1),ia(113)),
     & (htrfpt(1),ia(115))
       equivalence (httmp(1),fa(1))
!  Definitions for scratch space.
       integer htcmp(l_)
       real areao(l_),arean(l_),htsrc(l_),htavwt(l_),htcmpf(l_),
     & htsrwt(l_),htrvwt(l_),htlvwt(l_),gpintp(l_),gprinc(l_)
       equivalence (areao(1),fa(1)),(arean(1),fa(2)),(gpintp(1),fa(3)),
     & (gprinc(1),fa(4)),(htsrc(1),fa(5)),(htavwt(1),fa(6)),
     & (htcmp(1),ia(7)),(htcmpf(1),fa(7)),(htsrwt(1),fa(9)),
     & (htrvwt(1),fa(10)),(htlvwt(1),fa(11))
!
!  htfixa  number of mesh size independent words for each heat
!          structure.
!  htgskp  skip factor for geometry data.
!  nhtstr  number of heat structures.
!  ihtptr  offset to heat structure.
!  The following are for each structure.
!  htstno  heat structure number.
!  htopt   steady state flag during input and reflood rezoning
!          indicator during transient (1 bit); input error flag (2 bit);
!          initialization flag (4 bit); geometry referral flag (8 bit);
!          geometry satisfied flag (16 bit); temperature referral flag
!          (32 bit); temperature referral satisfied flag (64 bit);
!          left extra boundary condition card entered (128 bit); right
!          extra boundary condition card entered (256 bit); reflood
!          side, 0 = left, 1 = right (512 bit); right boundary condition
!          type, 1 if convective heat transfer to a hydrodynamic volume,
!          0 otherwise (1024 bit); left boundary condition type (2048
!          bit); geometry type shifted left 24 bits.
!  htxft   offset to end of time step temperatures.
!  htxit   offset to beginning of time step temperatures.
!  htgmr   heat structure-geometry referral number.
!  htgom   offset to heat structure geometry data.
!  htsrt(1)  heat source type.
!  htsrt(2)  heat source offset for general table or control system
!            power source; heat structure-geometry referral number for
!            initial temperatures.
!  For htbvc, htbvo, htbnt, htbntr, htbnts, htstyp, and htmod,
!  quantity(1) is for left side, quantity(2) is for right side.
!  htbvc   boundary volume input code.
!  htbvo   boundary volume offset during input, index during transient
!          or general table offset.
!  htbnt   boundary type input.
!  htbntr  reduced boundary type.
!  htbnts  coordinate code or coordinate offset (bit pos. 13-16); bit
!          indicating coordinate code (1) or offset (0) (bit pos. 12);
!          subroutine number (bit pos. 8-11); option number (bit pos.
!          (1-7); or table ordinal from boundary type.
!  htstyp  heat transfer surface type during input.
!  htmod   heat transfer mode number during transient.  This quantity
!          and the preceeding quantity occupy the same location.
!  htgap(1)  gap deformation model reference volume number.
!  htgap(2)  gap deformation model reference volume offset.
!  htnmpt  number of mesh points.
!  htrflg(1)  reflood flag.
!  htrflg(2)  offset for trip when trip number in htrflg(1).
!  htnaxl  axial rezoning limit number.
!  htnusr  number of heat structures with this geometry.
!  htfctr  source multiplier
!  htsrfo area at left boundary.
!  htsrfn area at right boundary.
!  htrnro heat transfer rate at left boundary (new).
!  htrnrn heat transfer rate at right boundary (new).
!  htrnso heat transfer rate at left boundary (old).
!  htrnsn heat transfer rate at right boundary (old).
!  htcffo heat transfer coefficient to liquid at left boundary.
!  htcffn heat transfer coefficient to liquid at right boundary.
!  htftro left direct source factor.
!  htftrn right direct source factor.
!  htpowo old power value.
!  htpown new power value.
!  httots integral of the source distribution over space.
!  htimeo time at beginning of advancement.
!  htdt   time increment.
!  hthdmo left side heated equivalent diameter.
!  hthdmn right side heated equivalent diameter.
!  htchfo left side critical heat flux.
!  htchfn right side critical heat flux.
!  htvatp volume averaged temperature.
!  htdtmo  left side old (twall - twater).
!  htdtmn  right side old (twall - twater).
!  htbcao  left boundary condition value, usually heat transfer
!          coefficient.
!  htbcan  right boundary condition value, usually heat transfer
!          coefficient.
!  htbcco  left boundary condition value, usually sink temperature
!          related quantity or heat flux.
!  htbccn  right boundary condition value, usually sink temperature
!          related quantity or heat flux.
!  gprouf  fuel surface roughness + cladding surface roughness
!  gpudis  cladding creepdown radial displacement - radial
!          displacement due to fission gas induced fuel swelling
!          and densification
!  htrado  radius at left boundary.
!  htradn  radius at right boundary.
!  htiscr  index for scratch space during transient advancement.
!  The following are for each mesh point or mesh interval.
!  httmp   temperature in heat structure.
!  areao   surface weight at left boundary.
!  arean   surface weight at right boundary.
!  htsrc   space dependent source factor times volume weights at each
!          mesh point.
!  htcmp(1)  composition number.
!  htcmp(2)  composition offset.
!  htavwt  volume weights for average volume temperature calculation
!          at each mesh point.
!  htsrwt  surface weights at each mesh interval.
!  htrvwt  right volume weights at each mesh interval.
!  htlvwt  left volume weights at each mesh interval.
!  gpintp  gap initial pressure at input, initial presuure /temperature
!          of reference volume (top of the core) after initialization
!  gprinc  radial interval width up to the gap plus inner and outer
!          radii of cladding
!  chfmuo  critical heat flux multiplier, left-hand side
!  chfmun  critical heat flux multiplier, right-hand side
!  htlnfo  forward direction heated length from inlet, left-hand side
!          or for pg chfr
!  htlnfo  forward direction reduced heated length from inlet.
!  htlnfn  forward direction heated length from inlet, right-hand side
!          or for pg chfr
!  htlnfn  forward direction reduced heated length from inlet.
!  htlnro  reverse direction heated length from inlet, left-hand side
!          or for pg chfr
!  htlnro  reverse direction reduced heated length from inlet.
!  htlnrn  reverse direction heated length from inlet, right-hand side
!          or for pg chfr
!  htlnrn  reverse direction reduced heated length from inlet.
!  grdzfo  forward direction length from grid spacer, left-hand side
!          or for pg chfr
!  grdzfo  forward direction grid spacer factor, left-hand side
!  grdzfn  forward direction length from grid spacer, right-hand side
!          or for pg chfr
!  grdzfn  forward direction grid spacer factor, right-hand side
!  grdzro  reverse direction length from grid spacer, left-hand side
!          or for pg chfr
!  grdzro  reverse direction grid spacer factor, left-hand side
!  grdzrn  reverse direction length from grid spacer, right-hand side
!          or for pg chfr
!  grdzrn  reverse direction grid spacer factor, right-hand side
!  grdkfo  grid spacer forward form loss coefficient, left-hand side
!  grdkfn  grid spacer forward form loss coefficient, right-hand side
!  grdkro  grid spacer reverse form loss coefficient, left-hand side
!  grdkrn  grid spacer reverse form loss coefficient, right-hand side
!  apfaco  axial power peaking factor, left-hand side of heat structure
!          (local flux/average flux from start of boiling to local
!          point)
!  apfacn  axial power peaking factor, right-hand side of heat structure
!
!  The following are for metal-water reaction.
!  oxti    new oxide thickness on inside  of cladding (m)
!  oxto    new oxide thickness on outside of cladding (m)
!  h2gen   new hydrogen generated (kg)
!  oxtio   old value of inside  oxide thickness (m)
!  oxtoo   old value of outside oxide thickness (m)
!          (can be input as w2 on the 1cccg003 card in rhtcmp)
!  h2geno  old value of hydrogen generated (kg)
!  imw     packed word, clad ruptured flag, metal-water correlation
!                       used, and node number of inside clad mesh pt.
!        right 9 bits = radial mesh pt number of inside of clad.
!            512 bit  = on if rupture has occurred
!           1024 bit  = on if loss coefficients have been changed
!           2048 bit  = on if plastic strain to be calculated (input)
!           4096 bit  = on if loss coef to be altered at rupture (input)
!           8192 bit  = on if mwr being calculated on inner surface
!          16384 bit  = on if mwr being calculated ( set by input )
!
!  The following are for clad balloning and rupture.
!  gapwd  gap width for the gap conductance and ballooning case
!  cladex clad expanded outer radius (negative if it has burst)
!  hetrat is the cladding heatup rate.
!  strnpl is the maximum plastic strain.
!
!  stanto,stantn  left, right side Stanton numbers.
!  peclo,pecln    left, right side Peclet numbers.
!  htlncf(2)  left(1) and right(2) forward natural convection length
!             from entrance.
!  htpovd(2)  left(1) and right(2) rod bundle pitch to diameter ratio.
!   The following are for the pg chfr input.
!  htivfc(2)  left(1) and right(2) forward direction boundary volume
!             input code to define equilibrium quality based on total
!             pressure at the inlet to heated channel
!  htivfo(2)  left(1) and right(2) forward direction boundary volume
!             offset, index during transient to define equilibrium
!             quality based on total pressure at the inlet to heated
!             channel
!  htivrc(2)  left(1) and right(2) reverse direction boundary volume
!             input code to define equilibrium quality based on total
!             pressure at the inlet to heated channel
!  htivro(2)  left(1) and right(2) reverse direction boundary volume
!             offset, index during transient to define equilibrium
!             quality based on total pressure at the inlet to heated
!             channel
!  pgopti(2)  left(1) and right(2) chf correlation option
!  pgcall(2)  left(1) and right(2) chf correlation call flag
