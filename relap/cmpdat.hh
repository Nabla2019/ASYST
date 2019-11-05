*mlist
!  Component data common to all components and data for time dependent
!  components.
!
!  Cognizant engineer: rjw.
!
!  Definitions common to all components.
       integer ncmps(l_),cmpnum(l_),cmptyp(l_),cmplen(l_),
     & nvc(l_),nvcn(l_),nvco(l_),njc(l_),njcn(l_),njco(l_),cmpopt(l_)
       real cmpnam(l_)
       equivalence (ncmps(1),ia(1)),(cmpnum(1),ia(2)),
     & (cmpnam(1),fa(3)),(cmptyp(1),ia(4)),(cmplen(1),ia(5)),
     & (nvc(1),ia(6)),(nvcn(1),ia(7)),(nvco(1),ia(8)),
     & (njc(1),ia(9)),(njcn(1),ia(10)),(njco(1),ia(11)),
     & (cmpopt(1),ia(12))
!  Definitions for time dependent volumes and junctions.
       integer ncttrp(l_),ncttrx(l_),nctdpv(l_),
     & nctpc(l_),nctblt(l_),nctble(l_),nctbtn(l_),nctbtx(l_)
       real nctalf(l_),cmptbl(l_)
       equivalence (ncttrp(1),ia(13)),(ncttrx(1),ia(14)),
     & (nctalf(1),fa(15)),(nctdpv(1),ia(16)),(nctpc(1),ia(17)),
     & (nctblt(1),ia(19)),(nctble(1),ia(20)),(nctbtn(1),ia(21)),
     & (nctbtx(1),ia(22)),(cmptbl(1),fa(23))
c
c  ncmps   number of components.
c  cmpnum  component number.
c  cmpnam  component name (alphanumeric).
c  cmptyp  component type (defined in cmpalf.H).
c          1  = 'pipe'
c          2  = 'tmdpvol' = time dependent volume
c          3  = 'mtpljun' = multiple junction
c          4  = 'pump'
c          5  = 'branch'
c          6  = 'jetmixer'
c          7  = 'annulus'
c          8  = 'separatr' = separator
c          9  = 'tmdpjun'  = time dependent junction
c          10 = 'snglvol'  = single volume
c          11 = 'sngljun'  = single junction
c          12 = 'valve'
c          13 = 'accum' = accumulator
c          14 = 'turbine'
c          15 = 'eccmix'
c          16 = 'multid' = 3-D component
c          17 = 'prizer' = pressurizer
c  cmplen  length of component data.
c  nvc     number of volumes in component.
c  nvcn    position number of first volume of this component.
c  nvco    offset to first volume of this component in volume block.
c  njc     number of junctions in component.
c  njcn    position number of first junction of this component.
c  njco    offset to first junction of this component in junction block.
c  cmpopt  for all components, velocity/mass flow switch (1 bit).
c          for turbine component, drain flag (4 bit), stage type (16-8
c          bits.
c          for valve component,
c            Check valve: Bit 5=0/1 for initially open/closed.
c              If valve is:
c                           Static pressure controlled (no hysteresis)
c                                              Bit 4=1
c                           Include hyteresis; Bit 3=1
c                                   Static/dynamic pressure controlled;
c                                              Bit 4=1
c            Trip valve: uses Bit 4, 5
c            Inertial valve: uses Bit 1, 3, 4, 5, 6, 7
c              Bit 3 =0/1 no/yes if valve has ever been fully open or cl
c              Bit 4 =0/1 (input) option 1 latching not-allowed/allowed.
c              Bit 5 =0/1 (input) initial condition open/close flag.
c              Bit 6 =0/1 option 2 latching has not-occurred/occurred.
c              Bit 7 =0/1 (input) option 2 latching not-allowed/allowed.
c            Motor valve: Bit usage not researched.
c            Servo valve: Bit usage not researched.
c            Relief valve: uses Bit 5.
c          For accumulator component, new time accumulator no outflow
c          flag (4 bit), not used (8 bit), new time volume active flag
c          (16 bit), old time values of the previous three bits
c          (32, 64, and 128 bits), spherical accumulator (256 bit).
c          For pump component, pump stop flag (4 bit), pump stopped
c          flag (8 bit), shaft connected flag (16 bit), negative pump
c          velocity flag (32 bit), single phase referral flag (64 bit),
c          single phase referral satisfied flag (128 bit), head and
c          torque multiplier referral flag (256 bit), head and torque
c          multiplier referral satisfied flag (512 bit), two phase
c          referral flag (1024 bit), two phase referral satisfied flag
c          (2048 bit), motor torque referral flag (4096 bit), motor
c          torque referral satisfied flag (8192 bit), pump speed table
c          referral flag (16384 bit), pump speed referral satisfied
c          flag (32768 bit), dissipation message printed (65536 bit),
c          octant number (shifted left 24 bits).
c          for multid component, 3D flag (4 bit), geometry flag
c          (16 bit), flag to indicate a 360 deg. cylinder with
c          more than one sector (32 bit), nonzero inner radius
c          flag (64 bit), 360 deg. cylindrical flag (128 bit).
c  ncttrp  trip number
c  ncttrx  offset in trip block, then index to trip during
c          transient routines.
c  nctalf  alphanumeric part of variable request code.
c  nctdpv  numeric part of variable request code.
c  nctpc(1)  0 if common block, block number if dynamic block
c  nctpc(2)  offset, then index in transient routines
c  nctblt  table type
c  nctble  number of items/entry
c  nctbtn  total number of items
c  nctbtx  last index
c  cmptbl  table entries
