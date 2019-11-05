*mlist
!  Cognizant engineer: rjw.
!
!  Junction block.
       integer ijsk1
$if -def,hydrolod,1
       parameter (ijsk1=98)
$if def,hydrolod,1
       parameter (ijsk1=99)
       integer njuns(l_),ij1(l_),ij2(l_),jc(l_),junno(l_),
     & junftl(l_),ij1vn(l_),ij2vn(l_),ij1nx(l_),ij2nx(l_),jcnx1(l_),
     & jcnx2(l_),jcnx3(l_),jcnxd(l_),jcnxs(l_),jcex(l_),ijflg(l_),
     & jcnfnd(l_)
       real ajun(l_),athrot(l_),arat(l_),diamj(l_),velfj(l_),velfjo(l_),
     & velgj(l_),velgjo(l_),ufj(l_),ugj(l_),voidfj(l_),voidgj(l_),
     & qualaj(l_),rhofj(l_),rhogj(l_),vodfjr(l_),vodgjr(l_),fjunf(l_),
     & fjunr(l_),formfj(l_),formgj(l_),mflowj(l_),faaj(l_),fij(l_),
     & fijo(l_),jcatn(l_),jcato(l_),qualnj(l_),jdissc(l_),jdistp(l_),
     & betacc(l_),constc(l_),constm(l_),c0j(l_),c0jo(l_),xej(l_),
     & sonicj(l_),vodfjo(l_),vodgjo(l_),vdfjoo(l_),vdgjoo(l_),fxj(l_),
     & fxjo(l_),vgjj(l_),florgj(l_),iregj(l_),voidj(l_),jdissh(l_),
     & fjunfb(l_),fjunfc(l_),fjunrb(l_),fjunrc(l_),flenth(l_),
     & chokef(l_),fijos(l_),fxjos(l_),c0jos(l_),vlfjos(l_),vlgjos(l_),
     & mflwjo(l_),soncjo(l_),fwalfj(l_),fwalgj(l_),fjunft(l_),
$if -def,hydrolod,1
     & fjunrt(l_),guinval(l_),guinang(l_),mflowfj(l_),mflowgj(l_)
$if def,hydrolod
     & fjunrt(l_),guinval(l_),guinang(l_),mflowfj(l_),mflowgj(l_),
     & loado(l_)
$endif
       equivalence (njuns(1),ia(1)),(ij1(1),ia(2)),(ij2(1),ia(3)),
     & (jc(1),ia(4)),(ij1vn(1),ia(5)),(ij2vn(1),ia(6)),
     & (junftl(1),ia(7)), (ajun(1),fa(9)),(athrot(1),fa(10)),
     & (arat(1),fa(11)),(diamj(1),fa(13)),(velfj(1),fa(14)),
     & (velfjo(1),fa(15)),(velgj(1),fa(16)),(velgjo(1),fa(17)),
     & (ufj(1),fa(18)),(ugj(1),fa(19)),(voidfj(1),fa(20)),
     & (voidgj(1),fa(21)),(qualaj(1),fa(22)),(rhofj(1),fa(23)),
     & (rhogj(1),fa(24)),(vodfjr(1),fa(25)),(vodgjr(1),fa(26)),
     & (fjunf(1),fa(27)),(fjunr(1),fa(28)),(formfj(1),fa(29)),
     & (formgj(1),fa(30)),(mflowj(1),fa(31)),(faaj(1),fa(32)),
     & (fij(1),fa(33)),(fijo(1),fa(34)),(jcatn(1),fa(35)),
     & (jcato(1),fa(36)),(qualnj(1),fa(37))
       equivalence (ij1nx(1),ia(42)),(ij2nx(1),ia(43)),
     & (jcnx1(1),ia(44)),(jcnx2(1),ia(46)),(jcnx3(1),ia(48)),
     & (jcnxd(1),ia(50)),(jcnxs(1),ia(52)),(junno(1),ia(53)),
     & (jdissc(1),fa(54)),(jdistp(1),fa(55)),(jcex(1),ia(56)),
     & (betacc(1),fa(57)),(constc(1),fa(58)),(constm(1),fa(59))
       equivalence (c0j(1),fa(60)),(c0jo(1),fa(61)),(xej(1),fa(62)),
     & (sonicj(1),fa(63)),(vodfjo(1),fa(64)),(vodgjo(1),fa(65)),
     & (vdfjoo(1),fa(66)),(vdgjoo(1),fa(67)),(fxj(1),fa(68)),
     & (fxjo(1),fa(69)),(vgjj(1),fa(70)),(florgj(1),fa(71)),
     & (iregj(1),fa(72)),(voidj(1),fa(73)),(jdissh(1),fa(74)),
     & (ijflg(1),ia(75)),(fjunfb(1),fa(76)),(fjunfc(1),fa(77)),
     & (fjunrb(1),fa(78)),(fjunrc(1),fa(79)),(flenth(1),fa(80)),
     & (jcnfnd(1),ia(81)),(chokef(1),fa(82)),(fijos(1),fa(83)),
     & (fxjos(1),fa(84)),(c0jos(1),fa(85)),(vlfjos(1),fa(86)),
     & (vlgjos(1),fa(87)),(mflwjo(1),fa(88) ),(soncjo(1),fa(89)),
     & (fwalfj(1),fa(90)),(fwalgj(1),fa(91)),(fjunft(1),fa(92)),
     & (fjunrt(1),fa(93)),(guinval(1),fa(94)),(guinang(1),fa(96)),
$if -def,hydrolod,1
     & (mflowfj(1),fa(98)),(mflowgj(1),fa(99))
$if def,hydrolod,1
     & (mflowfj(1),fa(98)),(mflowgj(1),fa(99)),(loado(1),fa(100))
!  Note: guinval and guinang use two values each.
!  jc, jcnx1, jcnx2, jcnx3, and arat use two words each.
       integer ijsk2
$if -def,mmfld,1
       parameter (ijsk2=0)
$if def,mmfld
       parameter (ijsk2=20)
       real velmj(1),velmjo(1),umj(1),voidmj(1),rhomj(1),formmj(1),
     & cfmj(1),cgmj(1),ffmj(1),fgmj(1),ffmjo(1),fgmjo(1),qualmj(1),
     & velmjs(1),mmflwj(1)
       equivalence (velmj(1),fa(ijsk1+2)),(velmjo(1),fa(ijsk1+3)),
     & (umj(1),fa(ijsk1+4)),(voidmj(1),fa(ijsk1+5)),
     & (rhomj(1),fa(ijsk1+6)),(formmj(1),fa(ijsk1+7)),
     & (cfmj(1),fa(ijsk1+8)),(cgmj(1),fa(ijsk1+9)),
     & (ffmj(1),fa(ijsk1+10)),(fgmj(1),fa(ijsk1+11)),
     & (ffmjo(1),fa(ijsk1+12)),(fgmjo(1),fa(ijsk1+13)),
     & (qualmj(1),fa(ijsk1+14)),(velmjs(1),fa(ijsk1+20)),
     & (mmflwj(1),fa(ijsk1+21))
$endif
       integer ijsk3
       parameter (ijsk3=ijsk1+ijsk2)
       integer ijsk4
$if -def,selap,1
       parameter (ijsk4=0)
$if def,selap,1
       parameter (ijsk4=2)
$if def,selap
       real ajuno(l_),diamjo(l_)
       equivalence (ajuno(1),fa(ijsk3+2)),(diamjo(1),fa(ijsk3+3))
$endif
       integer ijsk5
       parameter (ijsk5=ijsk3+ijsk4)
       integer ijsk6
$if -def,extjun,1
       parameter (ijsk6=0)
$if def,extjun
$if def,extj20,1
       parameter (ijsk6=20)
       real*8 extj01(l_),extj02(l_),extj03(l_),extj04(l_),extj05(l_),
     &        extj06(l_),extj07(l_),extj08(l_),extj09(l_),extj10(l_),
     &        extj11(l_),extj12(l_),extj13(l_),extj14(l_),extj15(l_),
     &        extj16(l_),extj17(l_),extj18(l_),extj19(l_),extj20(l_)
       equivalence (extj01(1),fa(ijsk5+2)) ,(extj02(1),fa(ijsk5+3)),
     &             (extj03(1),fa(ijsk5+4)) ,(extj04(1),fa(ijsk5+5)),
     &             (extj05(1),fa(ijsk5+6)) ,(extj06(1),fa(ijsk5+7)),
     &             (extj07(1),fa(ijsk5+8)) ,(extj08(1),fa(ijsk5+9)),
     &             (extj09(1),fa(ijsk5+10)),(extj10(1),fa(ijsk5+11)),
     &             (extj11(1),fa(ijsk5+12)),(extj12(1),fa(ijsk5+13)),
     &             (extj13(1),fa(ijsk5+14)),(extj14(1),fa(ijsk5+15)),
     &             (extj15(1),fa(ijsk5+16)),(extj16(1),fa(ijsk5+17)),
     &             (extj17(1),fa(ijsk5+18)),(extj18(1),fa(ijsk5+19)),
     &             (extj19(1),fa(ijsk5+20)),(extj20(1),fa(ijsk5+21))
$endif
       integer ijskp
       parameter (ijskp=ijsk5+ijsk6)
!
! T Name    Definition
! i ijskp   Junction skip factor (parameter set at end of jundat.H)
! i njuns   Number of junctions.
! i ij1     From volume input code.
! i ij2     To volume input code.
! i jc      Junction control packed word.
!           Bits numbered 1-32 from right end.
!           1 (=1) choking flag
!           2 (=2) time dependent junction flag
!           3 (=4) reversed from volume connection flag
!           4 (=8) reversed to volume connection flag
!           5 (=16) no choking flag
!           6 (=32) old time choking flag
!           7 (=64) choking test flag for accumulator junction
!           8 (=128) input flag
!           9 (=256) abrupt area change flag
!           10 (=512) two velocity-one velocity flag
!           11 (=1024) separator flag
!           12 (=2048) stratified flow flag
!           13 (=4096) to momentum flux off option
!           14 (=8192) from momentum flux off option
!           15 (=16,384) momentum flux off flag
!           16 (=32,768) accumulator active flag
!           17 (=65,536) stratification flag
!           18-19 (=131,072-262,144) stratification input data
!           20-22 (=524,288-2,097,152) jet mixer flags
!           23-25 (=4,194,304-16,777,216) separator flags
!           26 (=33,554,432) jet junction flag
!           27 (=67,108,864) horiz-vert junction flag
!           28 (=134,217,728) up-down junction flag
!           29 (=268,435,456) valve flag
!           30 (=536,870,912) second turbine junction flag
!           31 Old value for time dependent junction flag (bit 2).
! i ij1vn   From volume ordinal number.
! i ij2vn   To volume ordinal number.
! i junftl(1)  From pointer in output form without sign.
! i junftl(2)  To pointer in output form without sign.
! r ajun    Area of junction.
! r athrot  Ratio of orifice area to junction area.
! r arat(1) Mixture volumetric flow rate for the junction divided by
!           the total mixture volumetric flow rate on that end of the
!           volume.  Mixture is obtained by using sum of absolute value
!           of phasic volumetric flow rates. 1 is for "from" volume.
! r arat(2) Same as arat(1), except 2 is for "to" volume.
! r diamj   Diameter of junction.
!  *******  Warning: the ordering of velfj, velfjo, velgj, velgjo, ufj,
!  *******  ugj, voidfj, voidgj, qualaj, rhofj, and rhogj must be
!  *******  maintained since vfinl assumes this order.
! r velfj   Liquid velocity.
! r velfjo  Liquid velocity previous time step.
! r velgj   Vapor velocity.
! r velgjo  Vapor velocity previous time step.
! r ufj     Junction liquid specific internal energy.
! r ugj     Junction vapor specific internal energy.
! r voidfj  Junction liquid void fraction.
! r voidgj  Junction vapor void fraction.
! r qualaj  Junction noncondensible quality.
! r rhofj   Junction liquid density.
! r rhogj   Junction vapor density.
! r vodfjr  ratio of junction liquid void to upstream volume liquid
!           void.
! r vodgjr  ratio of junction vapor void to upstream volume vapor
!           void.
! r fjunf   Constant term for form loss coefficient for irreversible
!           losses, foward.
! r fjunr   Constant term for form loss coefficient for irreversible
!           losses, reverse.
! r fjunfb  Multipler term for form loss coefficient for irreversible
!           losses, foward.
! r fjunfc  Exponent term for form loss coefficient for irreversible
!           losses, foward.
! r fjunrb  Multipler term for form loss coefficient for irreversible
!           losses, reverse.
! r fjunrc  Exponent term for form loss coefficient for irreversible
!           losses, reverse.
! r fjunft  Total form loss coefficient for irreversible losses,
!           foward.
! r fjunrt  Total form loss coefficient for irreversible losses,
!           reverse.
! r formfj  Liquid form loss term.
! r formgj  Vapor form loss term.
! r fwalfj  Non-dimensional liquid wall friction coefficient.
! r fwalgj  Non-dimensional vapor wall friction coefficient.
! r mflowj  Mass flow rate.
! r mflowfj Liquid mass flow rate.
! r mflowgj Vapor mass flow rate.
! r faaj    Virtual mass.
! r fij     Interphase friction.
! r fijo    Interphase friction previous time step.
! r jcatn   Density correction factor (sqrt of rhot/rhoj) applied to
!           the junction convective term in choking.
! r jcato   Density correction factor applied to the junction convective
!           term in choking previous time step.
! r qualnj(1)  First noncondensible junction mass fraction.
! r qualnj(2)  Second noncondensible junction mass fraction.
! r qualnj(3)  Third noncondensible junction mass fraction.
! r qualnj(4)  Fourth noncondensible junction mass fraction.
! r qualnj(5)  Fifth noncondensible junction mass fraction.
! i ij1nx   From volume index.
! i ij2nx   To volume index.
! i jcnx1   Index to scratch space for "from" volume.  next word is
!           same for "to" volume.
! i jcnx2   Index to diagonal matrix element for "from" volume.  next
!           word is same for "to" volume.
! i jcnx3   Index to off-diagonal matrix element for "from" volume. next
!           word is same for "to" volume.
! i jcnxd(1)  Diagonal index for sum momentum equation.
! i jcnxd(2)  Diagonal index for difference momentum equation.
! i jcnxs   Index to scratch space for junction.
! i junno   Junction number for output editing.
! r jdissc  Subcooled discharge coefficient.
! r jdistp  Two phase discharge coefficient.
! i jcex    Junction control extra packed word.
!           Bits numbered 1-32 from right end.
!           1 (=1) used in elevation checking
!           2 (=2) ccfl flag
!           3 (=4) input ccfl flag
!           4-9 (=8-256) junction flow regime number
!           10-12 (=512-2048) to face-1 bits
!           13-15 (=4096-16,384) from face-1 bits
!           16 (=32,768) input flag for donor pressure in PV work term
!           17 (=65,536) water packer junction flag
!           18 (=131,072) stretch junction flag
!           19-20 (=262,144-524,288) eccmix flags
!           21 (=1,048,576) debug print flag
!           22 (=2,097,152) water packing flag
!           23-24 (=4,194,304-8,388,608) godunov method flag
!           25-26 (16,777,216-33,554,432) used in initialization of HSE
!                 model and separator.
!           28 used in level model, first to designate junctions whose
!           velocities are affected by level movement between volumes
!           and level appearance in or disappearance from the volumes at
!           either end of a junction, then to designate that liquid is
!           continuous phase in the junction
!           29 used in level model to designate that vapor is the
!           continuous phase in the junction
!           30 turns off loss coefficient computation for abrupt
!           junction
! r betacc  Form of ccfl correlation.
!           0. = Wallis
!           1. = Kutateladze
! r constc  Gas intercept for ccfl correlation.
! r constm  Slope for ccfl correlation.
! r c0j     Junction distribution coefficient.
! r c0jo    Junction distribution coefficient previous time step.
! r xej     Junction equilibrium quality.
!           Based on extrapolated pressure & internal energy from jchoke
! r sonicj  Junction sound speed
!           divided by the junction density ratio (jcatn).
! r vodfjo  Junction liquid void fraction previous timestep.
! r vodgjo  Junction vapour void fraction previous timestep.
! r vdfjoo  Junction liquid void fraction previous timestep but one.
! r vdgjoo  Junction vapour void fraction previous timestep but one.
! r fxj     Wall friction interpolating factor.
! r fxjo    Wall friction interpolation factor previous time step.
! r vgjj    Vapor drift velocity.
! r florgj  Junction flow regime number in real format.
!           1.  CTB  high mixing bubbly
!           2.  CTT  high mixing bubbly/mist transition
!           3.  CTM  high mixing mist
!           4.  BBY  bubbly
!           5.  SLG  slug
!           6.  ANM  annular-mist
!           7.  MPR  mist-pre-CHF
!           8.  IAN  inverted annular
!           9.  ISL  inverted slug
!           10. MST  mist
!           11. MPO  mist-post-CHF
!           12. HST  horizontal stratified
!           13. VST  vertical stratified
!           14. MWY  ECC mixer wavy
!           15. MWA  ECC mixer wavy/annular-mist
!           16. MAM  ECC mixer annular-mist
!           17. MMS  ECC mixer mist
!           18. MWS  ECC mixer wavy/slug transition
!           19. MWP  ECC mixer wavy-plug-slug transition
!           20. MPL  ECC mixer plug
!           21. MPS  ECC mixer plug-slug transition
!           22. MSL  ECC mixer slug
!           23. MPB  ECC mixer plug-bubbly transition
!           24. MBB  ECC mixer bubbly
! r iregj   Vertical bubbly/slug flow junction flow regime number in
!           real format.
! r voidj   Junction vapor void fraction used in the interphase drag.
! r jdissh  Superheated discharge coefficient.
! i ijflg   Junction direction flag.
!           0 = 1D/1D or 1D/3D or 3D/1D
!           1 = 3D/3D direction 1
!           2 = 3D/3D direction 2
!           3 = 3D/3D direction 3
! r flenth  Total enthalpy flow in junction, includes both phases and
!           noncondensibles.
! i jcnfnd  index to component block for junction
! r chokef  Junction choking flag.
!           0 = flow not choked
!           1 = flow choked
! r fijos   saved beginning of advancement interfacial friction
!           coefficient for level model backup
! r fxjos   saved beginning of advancement interfacial friction
!           interpolation coefficient for level model backup
! r c0jos   saved beginning of advancement phasis distribution
!           coefficient for level model backup
! r vlfjos  saved beginning of advancement liquid velocity
!           for level model backup
! r vlgjos  saved beginning of advancement vapor velocity
!           for level model backup
! r mflwjo  mass flow rate previous time step
! r soncjo  junction sound speed previous time step
$if def,selap,2
! r ajuno   Old ajun.
! r diamjo  Old diamj.
$if def,extjun
! r extjnn  Extra junction data for programmer use, one per junction.
!           To activate, add extjun and extj20 to the define file.
$if def,extj20
!           nn goes from 01 to 20
$endif
$endif
