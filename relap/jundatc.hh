*mlist
c
c  Coginzant engineer: rjw
c
c T Name    Definition
c i ijskp   Junction skip factor (parameter set at end of jundat.H)
c i njuns   Number of junctions.
c i ij1     From volume input code.
c i ij2     To volume input code.
c i jc      Junction control packed word.
c           Bits numbered 1-32 from right end.
c           1 (=1) choking flag
c           2 (=2) time dependent junction flag
c           3 (=4) reversed from volume connection flag
c           4 (=8) reversed to volume connection flag
c           5 (=16) no choking flag
c           6 (=32) old time choking flag
c           7 (=64) choking test flag for accumulator junction
c           8 (=128) input flag
c           9 (=256) abrupt area change flag
c           10 (=512) two velocity-one velocity flag
c           11 (=1024) separator flag
c           12 (=2048) stratified flow flag
c           13 (=4096) to momentum flux off option
c           14 (=8192) from momentum flux off option
c           15 (=16,384) momentum flux off flag
c           16 (=32,768) accumulator active flag
c           17 (=65,536) stratification flag
c           18-19 (=131,072-262,144) stratification input data
c           20-22 (=524,288-2,097,152) jet mixer flags
c           23-25 (=4,194,304-16,777,216) separator flags
c           26 (=33,554,432) jet junction flag
c           27 (=67,108,864) horiz-vert junction flag
c           28 (=134,217,728) up-down junction flag
c           29 (=268,435,456) valve flag
c           30 (=536,870,912) second turbine junction flag
c           31 Old value for time dependent junction flag (bit 2).
c i ij1vn   From volume ordinal number.
c i ij2vn   To volume ordinal number.
c i junftl(1)  From pointer in output form without sign.
c i junftl(2)  To pointer in output form without sign.
c r ajun    Area of junction.
c r athrot  Ratio of orifice area to junction area.
c r arat(1) Mixture volumetric flow rate for the junction divided by
c           the total mixture volumetric flow rate on that end of the
c           volume.  Mixture is obtained by using sum of absolute value
c           of phasic volumetric flow rates. 1 is for "from" volume.
c r arat(2) Same as arat(1), except 2 is for "to" volume.
c r diamj   Diameter of junction.
c  *******  Warning: the ordering of velfj, velfjo, velgj, velgjo, ufj,
c  *******  ugj, voidfj, voidgj, qualaj, rhofj, and rhogj must be
c  *******  maintained since vfinl assumes this order.
c r velfj   Liquid velocity.
c r velfjo  Liquid velocity previous time step.
c r velgj   Vapor velocity.
c r velgjo  Vapor velocity previous time step.
c r ufj     Junction liquid specific internal energy.
c r ugj     Junction vapor specific internal energy.
c r voidfj  Junction liquid void fraction.
c r voidgj  Junction vapor void fraction.
c r qualaj  Junction noncondensible quality.
c r rhofj   Junction liquid density.
c r rhogj   Junction vapor density.
c r vodfjr  ratio of junction liquid void to upstream volume liquid
c           void.
c r vodgjr  ratio of junction vapor void to upstream volume vapor
c           void.
c r fjunf   Constant term for form loss coefficient for irreversible
c           losses, foward.
c r fjunr   Constant term for form loss coefficient for irreversible
c           losses, reverse.
c r fjunfb  Multipler term for form loss coefficient for irreversible
c           losses, foward.
c r fjunfc  Exponent term for form loss coefficient for irreversible
c           losses, foward.
c r fjunrb  Multipler term for form loss coefficient for irreversible
c           losses, reverse.
c r fjunrc  Exponent term for form loss coefficient for irreversible
c           losses, reverse.
c r fjunft  Total form loss coefficient for irreversible losses,
c           foward.
c r fjunrt  Total form loss coefficient for irreversible losses,
c           reverse.
c r formfj  Liquid form loss term.
c r formgj  Vapor form loss term.
c r fwalfj  Non-dimensional liquid wall friction coefficient.
c r fwalgj  Non-dimensional vapor wall friction coefficient.
c r mflowj  Mass flow rate.
c r mflowfj Liquid mass flow rate.
c r mflowgj Vapor mass flow rate.
c r faaj    Virtual mass.
c r fij     Interphase friction.
c r fijo    Interphase friction previous time step.
c r jcatn   Density correction factor (sqrt of rhot/rhoj) applied to
c           the junction convective term in choking.
c r jcato   Density correction factor applied to the junction convective
c           term in choking previous time step.
c r qualnj(1)  First noncondensible junction mass fraction.
c r qualnj(2)  Second noncondensible junction mass fraction.
c r qualnj(3)  Third noncondensible junction mass fraction.
c r qualnj(4)  Fourth noncondensible junction mass fraction.
c r qualnj(5)  Fifth noncondensible junction mass fraction.
c i ij1nx   From volume index.
c i ij2nx   To volume index.
c i jcnx1   Index to scratch space for "from" volume.  next word is
c           same for "to" volume.
c i jcnx2   Index to diagonal matrix element for "from" volume.  next
c           word is same for "to" volume.
c i jcnx3   Index to off-diagonal matrix element for "from" volume. next
c           word is same for "to" volume.
c i jcnxd(1)  Diagonal index for sum momentum equation.
c i jcnxd(2)  Diagonal index for difference momentum equation.
c i jcnxs   Index to scratch space for junction.
c i junno   Junction number for output editing.
c r jdissc  Subcooled discharge coefficient.
c r jdistp  Two phase discharge coefficient.
c i jcex    Junction control extra packed word.
c           Bits numbered 1-32 from right end.
c           1 (=1) used in elevation checking
c           2 (=2) ccfl flag
c           3 (=4) input ccfl flag
c           4-9 (=8-256) junction flow regime number
c           10-12 (=512-2048) to face-1 bits
c           13-15 (=4096-16,384) from face-1 bits
c           16 (=32,768) input flag for donor pressure in PV work term
c           17 (=65,536) water packer junction flag
c           18 (=131,072) stretch junction flag
c           19-20 (=262,144-524,288) eccmix flags
c           21 (=1,048,576) debug print flag
c           22 (=2,097,152) water packing flag
c           23-24 (=4,194,304-8,388,608) godunov method flag
c           25-26 (16,777,216-33,554,432) used in initialization of HSE
c                 model and separator.
c           28 used in level model, first to designate junctions whose
c           velocities are affected by level movement between volumes
c           and level appearance in or disappearance from the volumes at
c           either end of a junction, then to designate that liquid is
c           continuous phase in the junction
c           29 used in level model to designate that vapor is the
c           continuous phase in the junction
c           30 turns off loss coefficient computation for abrupt
c           junction
c r betacc  Form of ccfl correlation.
c           0. = Wallis
c           1. = Kutateladze
c r constc  Gas intercept for ccfl correlation.
c r constm  Slope for ccfl correlation.
c r c0j     Junction distribution coefficient.
c r c0jo    Junction distribution coefficient previous time step.
c r xej     Junction equilibrium quality.
c           Based on extrapolated pressure & internal energy from jchoke
c r sonicj  Junction sound speed
c           divided by the junction density ratio (jcatn).
c r vodfjo  Junction liquid void fraction previous timestep.
c r vodgjo  Junction vapour void fraction previous timestep.
c r vdfjoo  Junction liquid void fraction previous timestep but one.
c r vdgjoo  Junction vapour void fraction previous timestep but one.
c r fxj     Wall friction interpolating factor.
c r fxjo    Wall friction interpolation factor previous time step.
c r vgjj    Vapor drift velocity.
c r florgj  Junction flow regime number in real format.
c           1.  CTB  high mixing bubbly
c           2.  CTT  high mixing bubbly/mist transition
c           3.  CTM  high mixing mist
c           4.  BBY  bubbly
c           5.  SLG  slug
c           6.  ANM  annular-mist
c           7.  MPR  mist-pre-CHF
c           8.  IAN  inverted annular
c           9.  ISL  inverted slug
c           10. MST  mist
c           11. MPO  mist-post-CHF
c           12. HST  horizontal stratified
c           13. VST  vertical stratified
c           14. MWY  ECC mixer wavy
c           15. MWA  ECC mixer wavy/annular-mist
c           16. MAM  ECC mixer annular-mist
c           17. MMS  ECC mixer mist
c           18. MWS  ECC mixer wavy/slug transition
c           19. MWP  ECC mixer wavy-plug-slug transition
c           20. MPL  ECC mixer plug
c           21. MPS  ECC mixer plug-slug transition
c           22. MSL  ECC mixer slug
c           23. MPB  ECC mixer plug-bubbly transition
c           24. MBB  ECC mixer bubbly
c r iregj   Vertical bubbly/slug flow junction flow regime number in
c           real format.
c r voidj   Junction vapor void fraction used in the interphase drag.
c r jdissh  Superheated discharge coefficient.
c i ijflg   Junction direction flag.
c           0 = 1D/1D or 1D/3D or 3D/1D
c           1 = 3D/3D direction 1
c           2 = 3D/3D direction 2
c           3 = 3D/3D direction 3
c r flenth  Total enthalpy flow in junction, includes both phases and
c           noncondensibles.
c i jcnfnd  index to component block for junction
c r chokef  Junction choking flag.
c           0 = flow not choked
c           1 = flow choked
c r fijos   saved beginning of advancement interfacial friction
c           coefficient for level model backup
c r fxjos   saved beginning of advancement interfacial friction
c           interpolation coefficient for level model backup
c r c0jos   saved beginning of advancement phasis distribution
c           coefficient for level model backup
c r vlfjos  saved beginning of advancement liquid velocity
c           for level model backup
c r vlgjos  saved beginning of advancement vapor velocity
c           for level model backup
c r mflwjo  mass flow rate previous time step
c r soncjo  junction sound speed previous time step
$if def,selap,2
c r ajuno   Old ajun.
c r diamjo  Old diamj.
$if def,extjun
c r extjnn  Extra junction data for programmer use, one per junction.
c           To activate, add extjun and extj20 to the define file.
$if def,extj20
c           nn goes from 01 to 20
$endif
$endif
