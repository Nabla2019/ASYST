*mlist
c
c T Name    Definition
c i ivskp   Volume skip factor (parameter set at end of voldat.H).
c i nvols   Number of volumes.
c i vctrl   Volume control packed word.
c           Bits numbered 1-32 from right end
c           1 (=1) time dependent volume flag
c           2 (=2) equilibrium flag
c           3 (=4) thermal front flag
c           4 (=8) input flag
c           5 (=16) vapor disappearance flag
c           6 (=32) accumulator flag
c           7 (=64) pump flag
c           8 (=128) input water packer flag
c           9-19 (=256=>262,144) new status flags,
c                      initialization type during input
c           20-30 (=524,288=>536,870,912) old status flags
c           31 (=1,073,741,824) input bundle flag
c           Status flags:
c           9, 20 (=256,=524,288)  negative pressure
c           10, 21 (=512,=1,048,576) mass error
c           11, 22 (=1024,=2,097,152) extrapolation error
c           12, 23 (=2048,=4,194,304) quality overrun
c           13, 24 (=4096,=8,388,608) largest mass error
c           14, 25 (=8192,=16,777,216) error in vapor phase
c           15, 26 (=16,384,=33,554,432) error in liquid phase
c           16, 27 (=32,768,=67,108,864) error in two phase call
c           17, 28 (=65,536,=134,217,728) non-convergence in iterations
c           18, 29 (=131,072,=268,435,456) negative sonic velocity
c           19, 30 (=262,144,=536,870,912) negative derived quantities
c i vctrlx  Status flags packed word (bits numbered 1-32 from right end)
c           1 (=1) debug print flag
c           2 (=2) air appearance repeat
c           3 (=4) pressure change repeat on air appearance
c           4 (=8) water packing statistics flag
c           5-6 (=16=>32) flags used for godunov method
c           7 (=64) flag used in level model
c           8 (=128) level in volume current time step
c           9 (=256) level in volume previous time step
c           10 (=512) saved level flag in current time step ( used
c             for backup )
c           11 (=1024)saved level flag in previous time step ( used
c             for backup )
c           12 (=2048) Bit on indicates to skip mass error check for
c                      this volume.
c           13 (=4096) Bit on indicates volume has been blocked (only
c              Scdap models block and reopen a volume).
c i volmat  Fluid type in volume.
c i volno   Volume number for editing.
c i imap    Map, regime, and flag packed word.
c           (bits numbered 1-32 from right end)
c           Three quantities, one per coordinate.
c           1-6 (=1=>32) Flow regime map infomation
c           7 (=64) non-condensable gas appearance flag
c           8 (=128) horizontal stratification flag
c           9 (=256) stretch flag
c           10 (=512) input vertical stratification flag
c           11,12 (=1024-2048) vertical stratification flags
c           13 (4096) experimental friction being used
c           14 (8192) wall friction input flag
c           15 (=16,384) flag for coordinate direction being used
c           16 (=32,768) unused
c           17 (=65,536) bundle input flag
c           18 (=131,072) volume in multid component
c           19-24 (=262,144-8,388,608) flow regime number
c           25-26 (=16,777,216-33,554,432) metal appearance flags
c           27 (=67,108,864) laminar friction factor, 64 if 0, 96 if 1
c           28 (=134,217,728) ans input flag
c           29 (=268,435,456) level tracking input flag
c           30 (=536,870,912) reflood flag
c           31 (=1,073,741,824) water packer volume flag
c r v       Volume.
c r recipv  Reciprocal of volume (v), zero if v is zero.
c r avol    Area of volume, three quantities, one per coordinate.
c r dl      Volume length, three quantities, one per coordinate.
c r diamv   Equivalent flow diameter.
c           Three quantities, one per coordinate.
c r roughv  Wall roughness factor for direction 1, as input.
c           Reset in icmpn1 to colebrook full turb friction fac.
c r recrit  Critical reynolds number.
c           Three quantities, one per coordinate.
c           Fric fac = const; see roughv.
c r p       Average pressure.
c r po      Average pressure previous time step.
c r uf      Liquid specific internal energy.
c r ufo     Liquid specific internal energy previous time step.
c r ug      Vapor specific internal energy.
c r ugo     Vapor specific internal energy previous time step.
c r voidf   Liquid void fraction.
c r voidg   Vapor void fraction.
c r voidgo  Vapor void fraction previous time step (n).
c r vodgoo  Vapor void fraction at old old time step (n-1).
c r quala   Noncondensible quality..
c r qualao  Noncondensible quality previous time step.
c r boron   Boron density (mass of boron per cell volume).
c r borono  Boron density previous time step.
c r quals   Static quality.
c r quale   Equilibrium quality.
c r rho     Total density.
c r rhom    Total density for mass error check.
c r rhoo    Total density previous time step.
c  *******  Warning: the ordering of rhof and rhog must be maintained
c  *******  since fidis assumes this order.
c r rhof    Liquid density.
c r rhog    Vapor density.
c r satt    Saturation temperature based on the steam partial pressure.
c r temp    Used in r level subroutines and is usually the same as satt.
c r tempf   Liquid temperature.
c r tempg   Vapor temperature.
c r velf    Average liquid velocity in a volume.
c           Three quantities, one per coordinate.
c r velg    Average vapor velocity in a volume.
c           Three quantities, one per coordinate.
c r sounde  Homogeneous equilibrium sound speed.
c           Also, used for scratch in hydro.
c r hsteam  Steam specific enthalpy at bulk conditions using partial
c           pressure of steam.
c r sathf   Liquid specific enthalpy at saturation conditions.
c r sathg   Vapor specific enthalpy at saturation conditions.
c r betaff  Liquid isobaric coefficient of thermal expansion at bulk
c           conditions.
c r betagg  Vapor isobaric coefficient of thermal expansion at bulk
c           conditions.
c r csubpf  Liquid specific heat capacity at constant pressure at bulk
c           conditions.
c r csubpg  Vapor specific heat capacity at constant pressure at bulk
c           conditions.
c r viscf   Liquid viscosity.
c r viscg   Vapor viscosity.
c r sigma   Surface tension.
c r thconf  Liquid thermal conductivity.
c r thcong  Vapor thermal conductivity.
c r pps     Vapor partial pressure.
c r dotm    Bulk vapor generation rate per unit volume.
c r vapgno  Vapor generation rate per unit volume previous time step.
c r hif     Liquid side interfacial heat transfer coefficient per unit
c           volume.
c r hig     Vapor side interfacial heat transfer coefficient per unit
c           volume.
c r gammaw  Vapor generation rate per unit volume associated with wall
c           heat transfer.
c r gammac  Condensation rate per unit volume associated with wall heat
c           transfer.
c r q       Total heat transfer rate from wall to fluid.
c r qwf     Heat transfer rate from wall to liquid.
c r qwg     Heat transfer rate from wall to vapor.
c r drfdp   Partial derivative of rhof w/r to pressure.
c r drfduf  Partial derivative of rhof w/r to liquid specific internal
c           energy.
c r drgdp   Partial derivative of rhog w/r to pressure.
c r drgdug  Partial derivative of rhog w/r to vapor specific internal
c           energy.
c r drgdxa  Partial derivative of rhog w/r to noncondensible quality.
c r dtfdp   Partial derivative of tempf w/r to pressure.
c r dtfduf  Partial derivative of tempf w/r to liquid specific internal
c           energy.
c r dtgdp   Partial derivative of tempg w/r to pressure.
c r dtgdug  Partial derivative of tempg w/r to vapor specific internal
c           energy.
c r dtgdxa  Partial derivative of tempg w/r to noncondensible quality.
c r dtdp    Partial derivative of satt w/r to pressure.
c r dtdug   Partial derivative of satt w/r to vapor specific internal
c           energy.
c r dtdxa   Partial derivative of satt w/r to noncondensible quality.
c r floreg  Flow regime number in real format.
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
c r hifo    Liquid side interfacial heat transfer coefficient per unit
c           volume previous timestep.
c r higo    Vapor side interfacial heat transfer coefficient per unit
c           volume previous timestep.
c r qualan  Noncondensible mass fraction.
c           Five quantities, one per species.
c r gaman   Noncondensible generation rate per unit volume.
c           Five quantities, one per species.
c r enthn   Enthalpy of noncondensible source.
c           Five quantities, one per species.
c r gamas   Solute generation rate per unit volume.
c r enths   Enthalpy of the solute source.
c r vo      Volume previous time step.
c r qualno  Noncondensible mass fraction previous time step.
c           Five quantities, one per species.
c r rhofo   Liquid density previous time step.
c r rhogo   Vapor density previous time step.
c r ppso    Vapor partial pressure (old time).
c r ustm    Vapor specific internal energy at pps and tempg with non-
c           condensable present.
c r ustmo   Vapor specific internal energy at pps and tempg with non-
c           condensable present (old time).
c r ggas    Cell centered gas mass flux.
c           Three quantities, one per coordinate.
c r gliq    Cell centered liquid mass flux.
c           Three quantities, one per coordinate.
c r velfo   Volume average liquid velocity previous timestep.
c           x direction only.
c r velgo   Volume average vapor velocity previous timestep.
c           x direction only.
c r velfoo  Volume average liquid velocity previous timestep but one.
c           x direction only.
c r velgoo  Volume average vapor velocity previous timestep but one.
c           x direction only.
c r fstrt   Horizontal stratification interpolating factor.
c r fwalf   Liquid wall friction coefficient.
c           Three quantities, one per coordinate.
c r fwalg   Vapor wall friction coefficient.
c           Three quantities, one per coordinate.
c r vctrln  Position of volume in volume block.
c i vctrld  Index to diagonal matrix element.
c i vctrls  Index to volume scratch space.
c i sth2xv  Index data for sth2x water property subroutines.
c i invfnd  Index to inverted junction table.
c r sinb    Sine function of volume vertical angle.
c           Three quantities, one per coordinate.
c r hvmix   Volume mixture enthalpy.
c r ptans   Pitch between fuel plates (ans).
c r span    Length of fuel plates  (ans).
c r pecltv  Volume Peclet number.
c r tsatt   Saturation temperature based on the total pressure.
c r fshape  Wall friction shape factor (one per coordinate).
c r fmurex  Viscosity ratio for wall friction (one per coordinate).
c r hyarf   Liquid void fraction times density.
c r hyarg   Vapor void fraction times density.
c r hyaruf  Product of liquid void fraction, density, and internal
c           energy.
c r hyarug  Product of vapor void fraction, density, and internal
c           energy.
c r hgf     Direct heating heat transfer coefficient per unit volume.
c r frica   Constant term in experimental friction correlation.
c           Three quantities, one per coordinate.
c r fricb   Multiplier term in experimental friction correlation.
c           Three quantities, one per coordinate.
c r fricc   Power term in experimental friction correlation.
c           Three quantities, one per coordinate.
c i invhtf  Index to inverted heat structure table.
c r hydxc(1)  Change along inertial x axis due to moving from face 1
c             to center of volume along local x coordinate.
c r hydxc(2)  Change along inertial x axis due to moving from center of
c             volume to face 2 along local x coordinate.
c r hydxc(3)  Change along inertial x axis due to moving from face 3
c             to center of volume along local y coordinate.
c r hydxc(4)  Change along inertial x axis due to moving from center of
c             volume to face 4 along local y coordinate.
c r hydxc(5)  Change along inertial x axis due to moving from face 5
c             to center of volume along local z coordinate.
c r hydxc(6)  Change along inertial x axis due to moving from center of
c             volume to face 6 along local z coordinate.
c r hydyc(1)  Change along inertial y axis due to moving from face 1
c             to center of volume along local x coordinate.
c r hydyc(2)  Change along inertial y axis due to moving from center of
c             volume to face 2 along local x coordinate.
c r hydyc(3)  Change along inertial y axis due to moving from face 3
c             to center of volume along local y coordinate.
c r hydyc(4)  Change along inertial y axis due to moving from center of
c             volume to face 4 along local y coordinate.
c r hydyc(5)  Change along inertial y axis due to moving from face 5
c             to center of volume along local z coordinate.
c r hydyc(6)  Change along inertial y axis due to moving from center of
c             volume to face 6 along local z coordinate.
c r hydzc(1)  Change along inertial z axis due to moving from face 1
c             to center of volume along local x coordinate.
c r hydzc(2)  Change along inertial z axis due to moving from center of
c             volume to face 2 along local x coordinate.
c r hydzc(3)  Change along inertial z axis due to moving from face 3
c             to center of volume along local y coordinate.
c r hydzc(4)  Change along inertial z axis due to moving from center of
c             volume to face 4 along local y coordinate.
c r hydzc(5)  Change along inertial z axis due to moving from face 5
c             to center of volume along local z coordinate.
c r hydzc(6)  Change along inertial z axis due to moving from center of
c             volume to face 6 along local z coordinate.
c r hyposv(1) Coordinate along x inertial axis of vector from center
c             of rotation to center of volume.
c r hyposv(2) Coordinate along y inertial axis of vector from center
c             of rotation to center of volume.
c r hyposv(3) Coordinate along z inertial axis of vector from center
c             of rotation to center of volume.
c r gravv(1)  Coordinate of gravity along inertial x coordinate.
c r gravv(2)  Coordinate of gravity along inertial y coordinate.
c r gravv(3)  Coordinate of gravity along inertial z coordinate.
c r tintf   Interface temperature when noncondensible is present,
c           saturation temperature at total pressure otherwise.
c r htsens  Heat transfer coefficient for sensible heat transfer
c           between vapor/gas mixture and liquid.
c r srcamn  ????????????
c r tmassv  Total mass in volume, includes both phases and
c           noncondensibles.
c r tiengv  Total internal energy in volume, Includes both phases and
c           noncondensibles.
c r hyanpr  Rotation matrix used to convert from local coordinates to
c           fixed coordinates.
c r vapgen  Total vapor generation, sum of bulk vapor generation and
c           vapor generation from flashing and condensation.
c           vapgen = dotm + gammaw + gammac.
c r hgfo    Direct heating heat transfer coefficient per unit volume
c           previous time step.
$if def,selap
c i idbvol  Indicator of whether l-th index of relap5 volume contains
c           debris region
c           0 = no
c           1 = yes.
c i mdbvol  Value for l-th relap5 volume index of index m for
c           referencing arrays in common block debcom.
c i ndbvol  Value for l-th relap5 volume index of index n for
c           referencing arrays in common block debcom.
c r avolo   Old value of avol.
c r diamvo  Old value of diamv.
$endif
c r dlev    Location of two-phase mixture level
c r dlevo   Location of two-phase mixture level (old time)
c r vlev    Velocity of two-phase level movement
c r vollev  Position of level within volume.
c r voidla  Void fraction above the mixture level
c r voidao  Void fraction above the mixture level (old time)
c r voidlb  Void fraction below the mixture level
c r voidbo  Void fraction below the mixture level (old time)
c r dfront  Location of thermal front
c r dfrnto  Location of thermal front (old time)
c r vfront  Velocity of thermal front
c r ufla    Liquid internal energy above the thermal front
c r ufao    Liquid internal energy aaove the thermal front (old time)
c r uflb    Liquid internal energy below the thermal front
c r ufbo    Liquid internal energy below the thermal front (old time)
c i vcnfnd  Index to component for volume.
c r dplev   difference in pressure between level position and volume
c           center
c r higos   saved beginning of advancement vapor side interfacial
c           heat transfer coefficient for level model backup
c r hifos   saved beginning of advancement liquid side interfacial
c           heat transfer coefficient for level model backup
c r hgfos   saved beginning of advancement direct noncondensible
c           gas - liquid heat transfer coefficient for level model
c           backup
c i jjet    address in the junction block of the jet junction for this v
$if def,extravol
c r extvnn  Extra volume data for programmer use, one for each volume.
c           To activate, add extvol and either extv20 or extv100
c           to the define file
$if def,extv20,1
c           nn goes from 01 to 20
$if def,extv100,1
c           nn goes from 01 to 100
$endif
c r ttempi  interfacial temperature
c r dtidug  interfacial temperature partial derivative wrt Ug
c r dtiduf  interfacial temperature partial derivative wrt Uf
c r dtidp   interfacial temperature partial derivative wrt P
c r dtidxn  interfacial temperature partial derivative wrt quala
