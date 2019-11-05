*mlist
!  accumulator component dynamic block
!
! Cognizant engineer: kec.
!
      real dialn(l_),lnelv(l_),thick(l_),lnlen(l_),ttank(l_),ttanko(l_),
     & thcnd(l_),htcap(l_),rhot(l_),htxr(l_),qtank(l_),vdm(l_),vdmo(l_),
     & vliq(l_),vliqo(l_),rhon(l_),rhono(l_),tvapo(l_),cvnit(l_),
     & vtank(l_),betav(l_),dpd(l_),dpddp(l_),ahfgtf(l_),ahfgtg(l_),
     & avgtg(l_),avfgtf(l_),ahftg(l_),acpgtg(l_),acvgtg(l_),aviscn(l_),
     & acpnit(l_),atank(l_),diamtk(l_),ahgtf(l_),dztank(l_), qtanko(l_),
     & dmgdt(l_),claptf(l_),gasln(l_),gaslno(l_),tklen(l_),dvliq(l_)
       integer acctrp(l_)
       equivalence (dialn(1),fa(13)),(lnelv(1),fa(14)),
     & (thick(1),fa(15)),
     & (lnlen(1),fa(16)), (ttank(1),fa(17)), (ttanko(1),fa(18)),
     & (thcnd(1),fa(19)), (htcap(1),fa(20)), (rhot(1),fa(21)),
     & (htxr(1),fa(22)), (qtank(1),fa(23)), (vdm(1),fa(24)),
     & (vdmo(1),fa(25)), (vliq(1),fa(26)), (vliqo(1),fa(27)),
     & (rhon(1),fa(28)), (rhono(1),fa(29)), (tvapo(1),fa(30)),
     & (cvnit(1),fa(31)), (vtank(1),fa(32)), (betav(1),fa(33)),
     & (dpd(1),fa(34)), (dpddp(1),fa(35)),
     & (ahfgtf(1),fa(36)), (ahfgtg(1),fa(37)), (avgtg(1),fa(38)),
     & (avfgtf(1),fa(39)), (ahftg(1),fa(40)), (acpgtg(1),fa(41)),
     & (acvgtg(1),fa(42)), (aviscn(1),fa(43)), (acpnit(1),fa(44)),
     & (atank(1), fa(45)), (diamtk(1),fa(46)), (ahgtf(1), fa(47)),
     & (dztank(1),fa(48)), (qtanko(1),fa(49)), (dmgdt(1),fa(50)),
     & (claptf(1),fa(51)), (acctrp(1),ia(52)),
     & (gasln(1),fa(54)), (gaslno(1),fa(55)), (tklen(1),fa(56)),
     & (dvliq(1),fa(57))
!
!  dialn   surge line diameter.
!  lnelv   surge line elevation drop.
!  thick   tank wall thickness.
!  lnlen   surge line length.
!  ttank   tank wall temperature.
!  ttanko  tank wall temperature, old time.
!  thcnd   noncondensible thermal conductivity.
!  htcap   tank wall specific heat capacity.
!  rhot    tank wall density.
!  htxr    heat transfer flag.
!  qtank   heat transport to noncondensible from all sources.
!  vdm     dome volume (noncondensible)
!  vdmo    dome volume (noncondensible), old time.
!  vliq    liquid volume (tank and surge line)
!  vliqo   liquid volume (tank and surge line), old time.
!  rhon    noncondensible density.
!  rhono   noncondensible density, old time.
!  tvapo   noncondensible temperature, old time (tempg is new time)
!  cvnit   noncondensible specific heat capacity, cv.
!  vtank   tank volume.
!  betav   steam saturation coefficient of expansion.
!  dpd     variable used in solution matrix (right hand side).
!  dpddp   variable used in solution matrix (left hand side).
!  ahfgtf  heat of vaporization at the liq temp
!  ahfgtg  heat of vaporization at the vap temp
!  avgtg   vap specific vol at the vap temp
!  avfgtf  vg - vf at the liq temp
!  ahftg   liq enthalpy at the vap temp
!  acpgtg  vapor specific heat, cp, at the vap temp
!  acvgtg  vapor specific heat, cv, at the vap temp
!  aviscn  noncondensible viscosity
!  acpnit  noncondensible specific heat, cp, at the vap temp
!  atank   tank cross sectional area
!  diamtk  tank diameter
!  ahgtf   vap enthalpy at the liq temp
!  dztank  tank elevation change
!  qtanko  heat transport to noncondensible from all sources (old time)
!  dmgdt   time rate of change in dome vapor mass (equilibrium model)
!  claptf  clapyron coefficient at the liq temp
!  acctrp(1)  accumulator trip number
!  acctrp(2)  trip offset during input, index during transient.
!  gasln   length of gas above the surge line
!  gaslno  length of gas above the surge line, old time
!  tklen   length of the tank above the surge line
!  dvliq   change in liquid volume over last time step
