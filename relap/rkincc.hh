*mlist
c
c  Cognizant engineer:
c
c ******************************
c  Point kinetics power option
c ******************************
c  rknum   number of reactor kinetics equations.
c  rknumd  number of delay groups.
c  rkopt   control for calculating cn functions (bits 1 and 2); number
c          of table coordinates (4, 8, and 16 bits); for point kinetics
c          separable/table feedback flag, for space kinetics 0=ramonma,
c          1=hwr or gen feedback option (32 bit); initialization flag
c          (64 bit); point/one-d (flag 128 bit); unable to initialize
c          flag (256 bit); for point kinetics alternate table
c          coordinates (512 bit), for space kinetics, gen option; for
c          space kinetics reference temperature units (1024, 2048 bits);
c          for space kinetics density variable (4096 bit); for space
c          kinetics structure temperature power flag (8192 bit; gmax
c          factor start flag (16384 bit).
c  rkoffd  offset for loop over delay groups (point).
c          offset/index to kinetics mesh information (one-d).
c  rkoffa  offset for loop over all kinetics equations (point),
c          last filndx(21) value to compute indexes.
c  rknsc   number of scram data entries.
c  rksptr  pointer to scram data.
c  rkdnpt  pointer to density reactivity data (point separable
c          feedback),
c          pointer to coordinate data (tabular feedback),
c          offset/index to composition data (oned).
c  rkdppt  pointer to doppler reactivity data (point separable
c          feedback),
c          pointer to tabular data (point tabular feedback),
c          offset/index to zone data (one-d).
c  rknvfb(1)  number of volumes in reactivity feedback.
c  rknvfb(2)  pointer to volume feedback data.
c  rknsfb(1)  number of heat structures in reactivity feedback.
c  rknsfb(2)  pointer to heat structure feedback data.
c  rkbol   delayed neutron fraction over generation time.
c  rkro    reactivity bias after initialzation.
c  rkrn    current reactivity.
c  rkomeg  current reciprical period.
c  rkslob  source divided by delayed neutron fraction over generation
c  rkdt    reactor kinetic time step.
c  rksum   holds delayed neutron summation.
c  rkqval  fraction of fission energy released at fission.
c  rkfu38  u239 production factor.
c  rkpsi   Fissions per initial fissile atom.
c  rkcapt  Reactor operating period initially, then current time value
c          (starting from zero) during decay heat initialization and
c          transient advancement.
c  rkpow   total reactor power, i.e., the sum of fission power and
c          gamma decay power.
c  rkpowa  actinide decay power.
c  rkpowf  power from fission.
c  rkpowg  power from gamma decay, i.e. the sum of fission product
c          decay power and actinide decay power.
c  rkpowk  fission product decay power.
c  rkdepv  dependent variables being advanced in time.
c  rkfi    delayed neutron and gamma yield fractions.
c  rklmda  decay constants for delayed neutrons and gamma decay.
c  rkcnh1,rkcnh2,rkcnh3  integration weights at half interval.
c  rkcnf1,rkcnf2,rkcnf3  integration weights at full interval.
c  rknscr(1)  general table number or control variable number.
c  rknscr(2)  offset or index to general table or control variable.
c  rkdeni(1)  number of quantities per set in density table.
c  rkdeni(2)  number of quantities in table.
c  rkdeni(3)  current position in table.
c  rkdenr  density reactivity table if separable, coordinates if table.
c  rkdopi(1, 2, and 3)  same as for rkdeni except for doppler table.
c  rkdopr  doppler reactivity table.
c  rkvoln(1)  volume number.
c  rkvoln(2)  offset or index to volume data.
c  rkvwf   density weight for volume feedback.
c  rkvta   volume temperature reactivity coeeficient.
c  rkhtno(1)  heat structure number.
c  rkhtno(2)  offset to heat structure data.
c  rkfwf   doppler weight for heat structure feedback.
c  rkfta   heat structure temperature reactivity coeeficient.
c  rktabl  table data.
c  rkfdcd  code to determine if new interpolating elements are needed.
c  rknden  coordinate subscripts.
c  rkcoef  interpolating elements.
c **************************************
c  Nodal kinetics power option
c **************************************
c  rkdt    kinetic time step advancement interval
c  rkfu38  number of u238 atoms produced per fission
c  rknum   number of kinetics equations
c  rknumd  number of delayed neutron groups
c  rkoa    Coefficients for cross sections.
c  rkoacf(1)  composition figure for axial mesh plane,
c  rkoacf(2) offset/index to composition figure for axial mesh plane
c  rkoalp  averaged void fractiona in volume region
c  rkoazf(1)  zone figure identifier for axial mesh plane,
c  rkoazf(2)  offset/index to zone fiqure for axial mesh plane
c  rkob    averaged poison density in volume region
c  rkocby  maximum order of Chebychev fission source extrapolation
c          polynomial
c  rkocfg(1)  conposition identifier in composition figure,
c  rkocfg(2)  offset/index to composition data
c  rkocfi  composition figure identifier
c  rkocid  material composition identifier
c  rkoden  average fluid density in volume region
c  rkodpc  Delayed neutron precursor inventories.
c  rkoegv  Eigenvalue.
c  rkoepk  eigenvalue convergence criterion
c  rkofbs  number of heat structures in heat structure region
c  rkofbv  Number of volumes in volume region.
c  rkofa   kinetics data array
c  rkofi   Decay heat group yields.
c  rkoiho  axial plane exterior boundary condition flag
c  rkoil2  inner iteration L 2 convergence criterion
c  rkoiot  maximum number of outer iterations per time step in
c          transient
c  rkoips  axial plane interior boundary condition flag
c  rkoizd  bottom boundary condition flag
c  rkoizu  top boundary condition flag
c  rkokit  maximum number od outer iterations per invocation of the
c          kinetics modules
c  rkolmd  Decay heat decay constants.
c  rkomcr  number of control rods associated with a kinetics node
c  rkomnd  height of top of each of kinetic mesh interval
c          from bottom of reactor core
c  rkonc   number of material compositions
c  rkoncf  number of composition figures
c  rkongt  number of thermal neutron energy groups
c  rkonhr  number of rings in hex geometry
c  rkonmg  number of decay heat equations
c  rkonn(1) offset/index to zone average property data
c  rkonn(2) offset/index to composition data
c  rkonn(3) offset/index to control rod insertion data
c  rkonn(4) offset/index to control fraction data
c  rkonn(5) offset/index to zone power data
c  rkonn(6) offset/index to kinetics mesh data
c  rkonn(7) offset/index to temporary decay heat powers and precursor
c            densities
c  rkonn(8) offset/index to zone figure data
c  rkonn(9) offset/index to composition figure data
c  rkonn(10) offset/index to control rod weight factor data
c  rkonn(11) offset/index to  decay heat yields and decay constants
c  rkonng  number of neutron energy groups
c  rkonnm  number of outer iteration between nodal expansion method
c          coupling coefficient computations
c  rkonnx  number of meshes in x direction on axial mesh plane
c  rkonny  number of meshes in y direction on axial mesh plane
c  rkonnz  number of axial mesh planes
c  rkonr   number of control rod groups
c  rkonsr  number of heat structure regions in a zone
c  rkonth  number of thermal scattering iterations
c  rkonvr  number of volume regions in a zone
c  rkonxy  number of solution nodes in an axial plane
c  rkonz   number of zones
c  rkonzf  number of zone figures
c  rkooli  outer iteration L infinity convergence criterion
c  rkool2  outer iteration L 2 convergence criterion
c  rkopt   reactor power control bits
c  rkoral  active length of control rod
c  rkorcf(1)  control rod control fraction on each axial plane for
c             active portion of rod
c  rkorcf(2)  control rod control fraction on each axial plane for
c             driver portion of rod
c  rkorcl(1)  identifier of control system variable which moves this
c             rod
c  rkorcl(2)  offset/index in control system data block where data
c             controlling this rod can be found
c  rkorf(1)   identifier of control rod associated with kinetics mesh
c  rkorf(2)   offset/index to control fraction data for this rod
c  rkorid  control rod identifier
c  rkorif  control rod insertion location flag(0=top,1=bottom)
c  rkorin(1)  insertion depth of control rod,
c  rkorin(2)  initial insertion depth of control rod
c  rkosn(1)heat structure identifier
c  rkosn(2)offset/index in heat structure database for data for this
c          heat structure
c  rkoswf  heat structure weight factor
c  rkosym  axail mesh plane symetry flag
c  rkotf   structure region average fuel temperature.
c  rkotm   volume region average moderator temperature.
c  rkovn(1)   volume identifier,
c  rkovn(2)   offset/index in volume database for
c          data for this volume
c  rkovwf  volume weight factors, (1) factor for average void fraction
c          or density, (2) factor for average fluid temperature, and
c          (3) factor for average poison density
c  rkozap  zone actinide decay power
c  rkozdv  depentent variables for zone decay heat model
c  rkozfi  zone figure identifier
c  rkozfg  zone figure
c  rkozfp  zone fission power
c  rkozgp  zone decay power
c  rkozid  zone identifier
c  rkozkp  zone fission product decay power
c  rkoztp  zone total power
c  rkpow   total reactor power
c  rkpowa  total actinide decay power
c  rkpowf  total fission power
c  rkpowg  total gamma decay power
c  rkpowk  total fission product decay power
c  rkqval  total energy per fission
