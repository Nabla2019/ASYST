*mlist
!  Space independent reactor kinetics block.
!
!  Cognizant engineer: rjw.
!
!  Space independent reactor kinetics block.
       integer rknum(l_),rknumd(l_),rkopt(l_),rkoffd(l_),rkoffa(l_),
     & rknsc(l_),rksptr(l_),rkdnpt(l_),rkdppt(l_),rknvfb(l_),rknsfb(l_),
     & rknscr(l_),rkdeni(l_),rkdopi(l_),rkvoln(l_),rkhtno(l_),
     & rkfdcd(l_),rknden(l_)
       real rkbol(l_),rkro(l_),rkrn(l_),rkomeg(l_),rkslob(l_),rkdt(l_),
     & rksum(l_),rkqval(l_),rkfu38(l_),rkpsi(l_),rkcapt(l_),rkpow(l_),
     & rkpowg(l_),rkpowf(l_),rkpowk(l_),rkpowa(l_),rkdepv(l_),
     & rkcnh1(l_),
     & rkcnh2(l_),rkcnh3(l_),rkcnf1(l_),rkcnf2(l_),rkcnf3(l_),rkfi(l_),
     & rklmda(l_),rkdenr(l_),rkdopr(l_),rkvwf(l_),rkvta(l_),rkvbf(l_),
     & rkfwf(l_),rkfta(l_),rktabl(l_),rkcoef(l_)
       equivalence (rknum(1),ia(1)),(rknumd(1),ia(2)),
     & (rkopt(1),ia(3)),(rkoffd(1),ia(4)),(rkoffa(1),ia(5)),
     & (rknsc(1),ia(6)),(rksptr(1),ia(7)),(rkdnpt(1),ia(8)),
     & (rkdppt(1),ia(9)),(rknvfb(1),ia(10)),(rknsfb(1),ia(12)),
     & (rkbol(1),fa(14)),(rkro(1),fa(15)),(rkrn(1),fa(16)),
     & (rkomeg(1),fa(17)),(rkslob(1),fa(18)),(rkdt(1),fa(19)),
     & (rksum(1),fa(20)),(rkqval(1),fa(21)),(rkfu38(1),fa(22)),
     & (rkpsi(1),fa(23)),(rkcapt(1),fa(24)),(rkpow(1),fa(25)),
     & (rkpowg(1),fa(26)),(rkpowf(1),fa(27)),(rkpowk(1),fa(28)),
     & (rkpowa(1),fa(29)),(rkdepv(1),fa(30)),(rkfi(1),fa(31)),
     & (rklmda(1),fa(32)),(rkcnh1(1),fa(33)),(rkcnh2(1),fa(34)),
     & (rkcnh3(1),fa(35)),(rkcnf1(1),fa(36)),(rkcnf2(1),fa(37)),
     & (rkcnf3(1),fa(38)),(rknscr(1),ia(1)),(rkdeni(1),ia(1)),
     & (rkdenr(1),fa(4)),(rkdopi(1),ia(1)),(rkdopr(1),fa(4)),
     & (rkvoln(1),ia(1)),(rkvwf(1),fa(3)),(rkvta(1),fa(4)),
     & (rkvbf(1),fa(5)),(rkhtno(1),ia(1)),(rkfwf(1),fa(3)),
     & (rkfta(1),fa(4)),(rktabl(1),fa(1)),(rkfdcd(1),ia(1)),
     & (rknden(1),ia(1)),(rkcoef(1),fa(1))
!
!  Nodal neutron kinetics data block.
!
!    Layout of integer data in fixed length data block.
       integer rkonnx(l_), rkonny(l_), rkonnz(l_), rkonhr(l_),
     & rkonng(l_), rkongt(l_), rkonmg(l_),rkonth(l_),  rkonz(l_),
     & rkonvr(l_), rkonsr(l_), rkonc(l_), rkonr(l_), rkorif(l_),
     & rkonn(l_), rkonzf(l_), rkoncf(l_), rkosym(l_), rkoiho(l_),
     & rkoips(l_), rkoizu(l_), rkoizd(l_), rkonnm(l_), rkocby(l_),
     & rkokit(l_), rkoiot(l_), rkonxy(l_)
       equivalence (rkonnx(1),ia(4)),(rkonny(1),ia(5)),
     & (rkonnz(1),ia(6)),(rkonhr(1),ia(7)),(rkonng(1),ia(8)),
     & (rkongt(1),ia(9)),(rkonth(1),ia(10)),(rkonz(1),ia(39)),
     & (rkonzf(1),ia(40)),(rkonvr(1),ia(41)),(rkonsr(1),ia(42)),
     & (rkonc(1),ia(43)),(rkoncf(1),ia(44)),(rkonr(1),ia(45)),
     & (rkorif(1),ia(46)),(rkonmg(1),ia(11)),(rkosym(1),ia(12)),
     & (rkoiho(1),ia(13)),(rkoips(1),ia(14)),(rkoizu(1),ia(15)),
     & (rkoizd(1),ia(16)),(rkonnm(1),ia(18)),(rkocby(1),ia(20)),
     & (rkokit(1),ia(31)),(rkoiot(1),ia(32)),(rkonxy(1),ia(33)),
     & (rkonn(1),ia(47))
!
!    Layout of real data in fixed length data block.
       real rkoepk(l_),rkooli(l_),rkool2(l_),rkoil2(l_),rkoegv(l_)
       equivalence (rkoepk(1),fa(34)),(rkooli(1),fa(35)),
     & (rkool2(1),fa(36)),(rkoil2(1),fa(37)),(rkoegv(1),fa(38))
!
!    Layout of decay heat yields and decay constants.
       real rkofi(l_),rkolmd(l_),rkcoh1(l_),rkcoh2(l_),rkcoh3(l_),
     & rkcof1(l_),rkcof2(l_),rkcof3(1)
       equivalence (rkofi(1),fa(1)),(rkolmd(1),fa(2)),
     & (rkcoh1(1),fa(3)),(rkcoh2(1),fa(4)),(rkcoh3(1),fa(5)),
     & (rkcof1(1),fa(6)),(rkcof2(1),fa(7)),(rkcof3(1),fa(8))
!
!    Layout of axial kinetic mesh plane data.
       real rkomnd(1)
       integer rkoazf(1),rkoacf(1)
       equivalence ( rkomnd(1),fa(1)),(rkoazf(1),ia(2)),
     & (rkoacf(1),ia(4))
!
!    Layout of zone and composition figure data
       integer rkozfi(l_),rkozfg(l_),rkocfi(l_),rkocfg(1)
       equivalence ( rkozfi(1),ia(1)),(rkozfg(1),ia(2)),
     & (rkocfi(1),ia(1)),(rkocfg(1),ia(2))
!
!    Layout of zone average property data.
       integer rkozid(l_),rkofbv(l_),rkovn(l_),rkofbs(l_),rkosn(l_)
       real rkoalp(l_),rkoden(l_),rkotm(l_),rkob(l_),rkovwf(l_),
     & rkotf(l_),rkoswf(1)
       equivalence (rkozid(1),ia(1)),(rkoalp(1),fa(2)),
     & (rkoden(1),fa(2)),(rkotm(1),fa(3)),(rkob(1),fa(4)),
     & (rkofbv(1),ia(5)),(rkovn(1),ia(6)),(rkovwf(1),fa(8)),
     & (rkotf(1),fa(2)),(rkofbs(1),ia(3)),(rkosn(1),ia(4)),
     & (rkoswf(1),fa(6))
!
!    Layout of material composition data.
       integer rkocid(l_)
       real rkoa(l_)
       equivalence (rkocid(1),ia(1)),(rkoa(1),fa(2))
!
!    Layout of control rod position data.
       integer rkorid(l_), rkorcl(l_)
       real rkorin(l_),rkoral(l_)
       equivalence (rkorid(1),ia(1)),(rkorin(1),fa(2)),
     & (rkorcl(1),ia(4)),(rkoral(1),fa(6))
!
!    Layout of control rod weight data for the axial plane
       integer rkomcr(l_),rkorf(l_)
       equivalence (rkomcr(1),ia(1)),(rkorf(1),ia(2))
!
!    Layout of control fraction data for each axial plane
       real rkorcf(l_)
       equivalence (rkorcf(1),fa(1))
!
!    Layout of zone power data.
       real rkoztp(l_),rkozfp(l_),rkozgp(l_),rkozkp(l_),rkozap(l_),
     & rkozdv(l_)
       equivalence (rkoztp(1),fa(1)),(rkozgp(1),fa(2)),
     & (rkozfp(1),fa(3)),(rkozkp(1),fa(4)),(rkozap(1),fa(5)),
     & (rkozdv(1),fa(6))
!
! ******************************
!  Point kinetics power option
! ******************************
!  rknum   number of reactor kinetics equations.
!  rknumd  number of delay groups.
!  rkopt   control for calculating cn functions (bits 1 and 2); number
!          of table coordinates (4, 8, and 16 bits); for point kinetics
!          separable/table feedback flag, for space kinetics 0=ramonma,
!          1=hwr or gen feedback option (32 bit); initialization flag
!          (64 bit); point/one-d (flag 128 bit); unable to initialize
!          flag (256 bit); for point kinetics alternate table
!          coordinates (512 bit), for space kinetics, gen option; for
!          space kinetics reference temperature units (1024, 2048 bits);
!          for space kinetics density variable (4096 bit); for space
!          kinetics structure temperature power flag (8192 bit; gmax
!          factor start flag (16384 bit).
!  rkoffd  offset for loop over delay groups (point).
!          offset/index to kinetics mesh information (one-d).
!  rkoffa  offset for loop over all kinetics equations (point),
!          last filndx(21) value to compute indexes.
!  rknsc   number of scram data entries.
!  rksptr  pointer to scram data.
!  rkdnpt  pointer to density reactivity data (point separable
!          feedback),
!          pointer to coordinate data (tabular feedback),
!          offset/index to composition data (oned).
!  rkdppt  pointer to doppler reactivity data (point separable
!          feedback),
!          pointer to tabular data (point tabular feedback),
!          offset/index to zone data (one-d).
!  rknvfb(1)  number of volumes in reactivity feedback.
!  rknvfb(2)  pointer to volume feedback data.
!  rknsfb(1)  number of heat structures in reactivity feedback.
!  rknsfb(2)  pointer to heat structure feedback data.
!  rkbol   delayed neutron fraction over generation time.
!  rkro    reactivity bias after initialzation.
!  rkrn    current reactivity.
!  rkomeg  current reciprical period.
!  rkslob  source divided by delayed neutron fraction over generation
!  rkdt    reactor kinetic time step.
!  rksum   holds delayed neutron summation.
!  rkqval  fraction of fission energy released at fission.
!  rkfu38  u239 production factor.
!  rkpsi   Fissions per initial fissile atom.
!  rkcapt  Reactor operating period initially, then current time value
!          (starting from zero) during decay heat initialization and
!          transient advancement.
!  rkpow   total reactor power, i.e., the sum of fission power and
!          gamma decay power.
!  rkpowa  actinide decay power.
!  rkpowf  power from fission.
!  rkpowg  power from gamma decay, i.e. the sum of fission product
!          decay power and actinide decay power.
!  rkpowk  fission product decay power.
!  rkdepv  dependent variables being advanced in time.
!  rkfi    delayed neutron and gamma yield fractions.
!  rklmda  decay constants for delayed neutrons and gamma decay.
!  rkcnh1,rkcnh2,rkcnh3  integration weights at half interval.
!  rkcnf1,rkcnf2,rkcnf3  integration weights at full interval.
!  rknscr(1)  general table number or control variable number.
!  rknscr(2)  offset or index to general table or control variable.
!  rkdeni(1)  number of quantities per set in density table.
!  rkdeni(2)  number of quantities in table.
!  rkdeni(3)  current position in table.
!  rkdenr  density reactivity table if separable, coordinates if table.
!  rkdopi(1, 2, and 3)  same as for rkdeni except for doppler table.
!  rkdopr  doppler reactivity table.
!  rkvoln(1)  volume number.
!  rkvoln(2)  offset or index to volume data.
!  rkvwf   density weight for volume feedback.
!  rkvta   volume temperature reactivity coeeficient.
!  rkhtno(1)  heat structure number.
!  rkhtno(2)  offset to heat structure data.
!  rkfwf   doppler weight for heat structure feedback.
!  rkfta   heat structure temperature reactivity coeeficient.
!  rktabl  table data.
!  rkfdcd  code to determine if new interpolating elements are needed.
!  rknden  coordinate subscripts.
!  rkcoef  interpolating elements.
! **************************************
!  Nodal kinetics power option
! **************************************
!  rkdt    kinetic time step advancement interval
!  rkfu38  number of u238 atoms produced per fission
!  rknum   number of kinetics equations
!  rknumd  number of delayed neutron groups
!  rkoa    Coefficients for cross sections.
!  rkoacf(1)  composition figure for axial mesh plane,
!  rkoacf(2) offset/index to composition figure for axial mesh plane
!  rkoalp  averaged void fractiona in volume region
!  rkoazf(1)  zone figure identifier for axial mesh plane,
!  rkoazf(2)  offset/index to zone fiqure for axial mesh plane
!  rkob    averaged poison density in volume region
!  rkocby  maximum order of Chebychev fission source extrapolation
!          polynomial
!  rkocfg(1)  conposition identifier in composition figure,
!  rkocfg(2)  offset/index to composition data
!  rkocfi  composition figure identifier
!  rkocid  material composition identifier
!  rkoden  average fluid density in volume region
!  rkodpc  Delayed neutron precursor inventories.
!  rkoegv  Eigenvalue.
!  rkoepk  eigenvalue convergence criterion
!  rkofbs  number of heat structures in heat structure region
!  rkofbv  Number of volumes in volume region.
!  rkofa   kinetics data array
!  rkofi   Decay heat group yields.
!  rkoiho  axial plane exterior boundary condition flag
!  rkoil2  inner iteration L 2 convergence criterion
!  rkoiot  maximum number of outer iterations per time step in
!          transient
!  rkoips  axial plane interior boundary condition flag
!  rkoizd  bottom boundary condition flag
!  rkoizu  top boundary condition flag
!  rkokit  maximum number od outer iterations per invocation of the
!          kinetics modules
!  rkolmd  Decay heat decay constants.
!  rkomcr  number of control rods associated with a kinetics node
!  rkomnd  height of top of each of kinetic mesh interval
!          from bottom of reactor core
!  rkonc   number of material compositions
!  rkoncf  number of composition figures
!  rkongt  number of thermal neutron energy groups
!  rkonhr  number of rings in hex geometry
!  rkonmg  number of decay heat equations
!  rkonn(1) offset/index to zone average property data
!  rkonn(2) offset/index to composition data
!  rkonn(3) offset/index to control rod insertion data
!  rkonn(4) offset/index to control fraction data
!  rkonn(5) offset/index to zone power data
!  rkonn(6) offset/index to kinetics mesh data
!  rkonn(7) offset/index to temporary decay heat powers and precursor
!            densities
!  rkonn(8) offset/index to zone figure data
!  rkonn(9) offset/index to composition figure data
!  rkonn(10) offset/index to control rod weight factor data
!  rkonn(11) offset/index to  decay heat yields and decay constants
!  rkonng  number of neutron energy groups
!  rkonnm  number of outer iteration between nodal expansion method
!          coupling coefficient computations
!  rkonnx  number of meshes in x direction on axial mesh plane
!  rkonny  number of meshes in y direction on axial mesh plane
!  rkonnz  number of axial mesh planes
!  rkonr   number of control rod groups
!  rkonsr  number of heat structure regions in a zone
!  rkonth  number of thermal scattering iterations
!  rkonvr  number of volume regions in a zone
!  rkonxy  number of solution nodes in an axial plane
!  rkonz   number of zones
!  rkonzf  number of zone figures
!  rkooli  outer iteration L infinity convergence criterion
!  rkool2  outer iteration L 2 convergence criterion
!  rkopt   reactor power control bits
!  rkoral  active length of control rod
!  rkorcf(1)  control rod control fraction on each axial plane for
!             active portion of rod
!  rkorcf(2)  control rod control fraction on each axial plane for
!             driver portion of rod
!  rkorcl(1)  identifier of control system variable which moves this
!             rod
!  rkorcl(2)  offset/index in control system data block where data
!             controlling this rod can be found
!  rkorf(1)   identifier of control rod associated with kinetics mesh
!  rkorf(2)   offset/index to control fraction data for this rod
!  rkorid  control rod identifier
!  rkorif  control rod insertion location flag(0=top,1=bottom)
!  rkorin(1)  insertion depth of control rod,
!  rkorin(2)  initial insertion depth of control rod
!  rkosn(1)heat structure identifier
!  rkosn(2)offset/index in heat structure database for data for this
!          heat structure
!  rkoswf  heat structure weight factor
!  rkosym  axail mesh plane symetry flag
!  rkotf   structure region average fuel temperature.
!  rkotm   volume region average moderator temperature.
!  rkovn(1)   volume identifier,
!  rkovn(2)   offset/index in volume database for
!          data for this volume
!  rkovwf  volume weight factors, (1) factor for average void fraction
!          or density, (2) factor for average fluid temperature, and
!          (3) factor for average poison density
!  rkozap  zone actinide decay power
!  rkozdv  depentent variables for zone decay heat model
!  rkozfi  zone figure identifier
!  rkozfg  zone figure
!  rkozfp  zone fission power
!  rkozgp  zone decay power
!  rkozid  zone identifier
!  rkozkp  zone fission product decay power
!  rkoztp  zone total power
!  rkpow   total reactor power
!  rkpowa  total actinide decay power
!  rkpowf  total fission power
!  rkpowg  total gamma decay power
!  rkpowk  total fission product decay power
!  rkqval  total energy per fission
