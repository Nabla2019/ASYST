*mlist
c
c  Cognizant engineer: rjw.
c
c  htfixa  number of mesh size independent words for each heat
c          structure.
c  htgskp  skip factor for geometry data.
c  nhtstr  number of heat structures.
c  ihtptr  offset to heat structure.
c  The following are for each structure.
c  htstno  heat structure number.
c  htopt   steady state flag during input and reflood rezoning
c          indicator during transient (1 bit); input error flag (2 bit);
c          initialization flag (4 bit); geometry referral flag (8 bit);
c          geometry satisfied flag (16 bit); temperature referral flag
c          (32 bit); temperature referral satisfied flag (64 bit);
c          left extra boundary condition card entered (128 bit); right
c          extra boundary condition card entered (256 bit); reflood
c          side, 0 = left, 1 = right (512 bit); right boundary condition
c          type, 1 if convective heat transfer to a hydrodynamic volume,
c          0 otherwise (1024 bit); left boundary condition type (2048
c          bit); geometry type shifted left 24 bits.
c  htxft   offset to end of time step temperatures.
c  htxit   offset to beginning of time step temperatures.
c  htgmr   heat structure-geometry referral number.
c  htgom   offset to heat structure geometry data.
c  htsrt(1)  heat source type.
c  htsrt(2)  heat source offset for general table or control system
c            power source; heat structure-geometry referral number for
c            initial temperatures.
c  For htbvc, htbvo, htbnt, htbntr, htbnts, htstyp, and htmod,
c  quantity(1) is for left side, quantity(2) is for right side.
c  htbvc   boundary volume input code.
c  htbvo   boundary volume offset during input, index during transient
c          or general table offset.
c  htbnt   boundary type input.
c  htbntr  reduced boundary type.
c  htbnts  coordinate code or coordinate offset (bit pos. 13-16); bit
c          indicating coordinate code (1) or offset (0) (bit pos. 12);
c          subroutine number (bit pos. 8-11); option number (bit pos.
c          (1-7); or table ordinal from boundary type.
c  htstyp  heat transfer surface type during input.
c  htmod   heat transfer mode number during transient.  This quantity
c          and the preceeding quantity occupy the same location.
c  htgap(1)  gap deformation model reference volume number.
c  htgap(2)  gap deformation model reference volume offset.
c  htnmpt  number of mesh points.
c  htrflg(1)  reflood flag.
c  htrflg(2)  offset for trip when trip number in htrflg(1).
c  htnaxl  axial rezoning limit number.
c  htnusr  number of heat structures with this geometry.
c  htfctr  source multiplier
c  htsrfo area at left boundary.
c  htsrfn area at right boundary.
c  htrnro heat transfer rate at left boundary (new).
c  htrnrn heat transfer rate at right boundary (new).
c  htrnso heat transfer rate at left boundary (old).
c  htrnsn heat transfer rate at right boundary (old).
c  htcffo heat transfer coefficient to liquid at left boundary.
c  htcffn heat transfer coefficient to liquid at right boundary.
c  htftro left direct source factor.
c  htftrn right direct source factor.
c  htpowo old power value.
c  htpown new power value.
c  httots integral of the source distribution over space.
c  htimeo time at beginning of advancement.
c  htdt   time increment.
c  hthdmo left side heated equivalent diameter.
c  hthdmn right side heated equivalent diameter.
c  htchfo left side critical heat flux.
c  htchfn right side critical heat flux.
c  htvatp volume averaged temperature.
c  htdtmo  left side old (twall - twater).
c  htdtmn  right side old (twall - twater).
c  htbcao  left boundary condition value, usually heat transfer
c          coefficient.
c  htbcan  right boundary condition value, usually heat transfer
c          coefficient.
c  htbcco  left boundary condition value, usually sink temperature
c          related quantity or heat flux.
c  htbccn  right boundary condition value, usually sink temperature
c          related quantity or heat flux.
c  gprouf  fuel surface roughness + cladding surface roughness
c  gpudis  cladding creepdown radial displacement - radial
c          displacement due to fission gas induced fuel swelling
c          and densification
c  htrado  radius at left boundary.
c  htradn  radius at right boundary.
c  htiscr  index for scratch space during transient advancement.
c  The following are for each mesh point or mesh interval.
c  httmp   temperature in heat structure.
c  areao   surface weight at left boundary.
c  arean   surface weight at right boundary.
c  htsrc   space dependent source factor times volume weights at each
c          mesh point.
c  htcmp(1)  composition number.
c  htcmp(2)  composition offset.
c  htavwt  volume weights for average volume temperature calculation
c          at each mesh point.
c  htsrwt  surface weights at each mesh interval.
c  htrvwt  right volume weights at each mesh interval.
c  htlvwt  left volume weights at each mesh interval.
c  gpintp  gap initial pressure at input, initial presuure /temperature
c          of reference volume (top of the core) after initialization
c  gprinc  radial interval width up to the gap plus inner and outer
c          radii of cladding
c  chfmuo  critical heat flux multiplier, left-hand side
c  chfmun  critical heat flux multiplier, right-hand side
c  htlnfo  forward direction heated length from inlet, left-hand side
c          or for pg chfr
c  htlnfo  forward direction reduced heated length from inlet.
c  htlnfn  forward direction heated length from inlet, right-hand side
c          or for pg chfr
c  htlnfn  forward direction reduced heated length from inlet.
c  htlnro  reverse direction heated length from inlet, left-hand side
c          or for pg chfr
c  htlnro  reverse direction reduced heated length from inlet.
c  htlnrn  reverse direction heated length from inlet, right-hand side
c          or for pg chfr
c  htlnrn  reverse direction reduced heated length from inlet.
c  grdzfo  forward direction length from grid spacer, left-hand side
c          or for pg chfr
c  grdzfo  forward direction grid spacer factor, left-hand side
c  grdzfn  forward direction length from grid spacer, right-hand side
c          or for pg chfr
c  grdzfn  forward direction grid spacer factor, right-hand side
c  grdzro  reverse direction length from grid spacer, left-hand side
c          or for pg chfr
c  grdzro  reverse direction grid spacer factor, left-hand side
c  grdzrn  reverse direction length from grid spacer, right-hand side
c          or for pg chfr
c  grdzrn  reverse direction grid spacer factor, right-hand side
c  grdkfo  grid spacer forward form loss coefficient, left-hand side
c  grdkfn  grid spacer forward form loss coefficient, right-hand side
c  grdkro  grid spacer reverse form loss coefficient, left-hand side
c  grdkrn  grid spacer reverse form loss coefficient, right-hand side
c  apfaco  axial power peaking factor, left-hand side of heat structure
c          (local flux/average flux from start of boiling to local
c          point)
c  apfacn  axial power peaking factor, right-hand side of heat structure
c
c  The following are for metal-water reaction.
c  oxti    new oxide thickness on inside  of cladding (m)
c  oxto    new oxide thickness on outside of cladding (m)
c  h2gen   new hydrogen generated (kg)
c  oxtio   old value of inside  oxide thickness (m)
c  oxtoo   old value of outside oxide thickness (m)
c          (can be input as w2 on the 1cccg003 card in rhtcmp)
c  h2geno  old value of hydrogen generated (kg)
c  imw     packed word, clad ruptured flag, metal-water correlation
c                       used, and node number of inside clad mesh pt.
c        right 9 bits = radial mesh pt number of inside of clad.
c            512 bit  = on if rupture has occurred
c           1024 bit  = on if loss coefficients have been changed
c           2048 bit  = on if plastic strain to be calculated (input)
c           4096 bit  = on if loss coef to be altered at rupture (input)
c           8192 bit  = on if mwr being calculated on inner surface
c          16384 bit  = on if mwr being calculated ( set by input )
c
c  The following are for clad balloning and rupture.
c  gapwd  gap width for the gap conductance and ballooning case
c  cladex clad expanded outer radius (negative if it has burst)
c  hetrat is the cladding heatup rate.
c  strnpl is the maximum plastic strain.
c
c  stanto,stantn  left, right side Stanton numbers.
c  peclo,pecln    left, right side Peclet numbers.
c  htlncf(2)  left(1) and right(2) forward natural convection length
c             from entrance.
c  htpovd(2)  left(1) and right(2) rod bundle pitch to diameter ratio.
c   The following are for the pg chfr input.
c  htivfc(2)  left(1) and right(2) forward direction boundary volume
c             input code to define equilibrium quality based on total
c             pressure at the inlet to heated channel
c  htivfo(2)  left(1) and right(2) forward direction boundary volume
c             offset, index during transient to define equilibrium
c             quality based on total pressure at the inlet to heated
c             channel
c  htivrc(2)  left(1) and right(2) reverse direction boundary volume
c             input code to define equilibrium quality based on total
c             pressure at the inlet to heated channel
c  htivro(2)  left(1) and right(2) reverse direction boundary volume
c             offset, index during transient to define equilibrium
c             quality based on total pressure at the inlet to heated
c             channel
c  pgopti(2)  left(1) and right(2) chf correlation option
c  pgcall(2)  left(1) and right(2) chf correlation call flag
