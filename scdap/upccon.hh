*mlist
*comdeck upccon
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c------------------------------------------------c
c  common /upccon/                               c
c  initialization and user-specified constants   c
c------------------------------------------------c
c
c------------------------------------------------c
c  constants assigned during compilation         c
c------------------------------------------------c
c  wtfe    molecular weight of fe
c  wtcr    molecular weight of cr
c  wtni    molecular weight of ni
c  wtfeo   molecular weight of feo
c  wtf3o4  molecular weight of fe3o4
c  wtc2o3  molecular weight of cr2o3
c  wtnio   molecular weight of nio
c  wth2o   molecular weight of h2o
c  fmfe    mass fraction of fe in stainless steel
c  fmcr    mass fraction of cr in stainless steel
c  fmni    mass fraction of ni in stainless steel
c  fmfeo   mass fraction of feo from stainless steel
c  fmf3o4  mass fraction of fe3o4 from stainless steel
c  fmc2o3  mass fraction of cr2o3 from stainless steel
c  fmnio   mass fraction of nio from stainless steel
c  tmlups  melting temperature (k) of metal in upper plenum structures
c  dnmups  density (kg/m3) of metal at 298 k in upper plenum structures
c  dnlups  density (kg/m3) of liquid metal at melting temperature in
c          upper plenum structures
c  dnxups  density (kg/m3) of oxide at 298 k in upper plenum structures
c  hfuups  heat of fusion (j/kg) of metal in upper plenum structures
c  fxlups  mass fraction of oxides carried along with liquid metal
c          during melting of upper plenum structure nodes
c  thlups  minimum thickness (m) of liquid metal on upper plenum surface
c          nodes
c  ulups   downward velocity (m/s) of liquid metal on upper plenum
c          surface nodes
c  hlups   liquid metal heat transfer coefficient (w/(m2*k)) on upper
c          plenum surface nodes
c------------------------------------------------c
c  constants specified by user                   c
c------------------------------------------------c
c  isuser  contains user-defined upper plenum structure number
c  ntups   total number of upper plenum structures
c  ntupax  total number of upper plenum axial levels
c  ntupcn  total number of upper plenum conduction nodes.  includes
c          intact nodes plus 2 crust nodes
c  liups   initial length along conduction path (m) of upper plenum
c          structure nodes.  for the 2 crust nodes, this is the maximum
c          length along conduction path
c  saups   heat transfer surface area (m2) of upper plenum structure
c          nodes
c  isoups  flag that indicates suface orientation of upper plenum
c          structure nodes; 0=vertical, 1=horizontal surface that blocks
c          relocation on right surfaces only, 2=horizontal surface that
c          blocks relocation on both surfaces
c  hvups   height along vertical relocation path (m) of upper plenum
c          structure nodes
c  volupl  9-digit integer identifying RELAP5 volume adjacent to upper
c          plenum left surface nodes.  volupl must be >0 for each axial
c          level of each upper plenum structure
c  volupr  9-digit integer identifying RELAP5 volume adjacent to upper
c          plenum right surface nodes.  volupr must be >0 for each axial
c          level of each upper plenum structure
c------------------------------------------------c
c  constants calculated during initialization    c
c------------------------------------------------c
c  hhups   heated height (m) of upper plenum structure nodes.  for a
c          vertical surface, this is the height above the bottom of the
c          structure.  for a horizontal surface, this is the square root
c          of the surface area
c  hhtot   total heated height (m) of upper plenum structure.  this is
c          the height of the highest vertical surface above the bottom
c          of the structure
c  nvadul  offset index for the relap5 coolant condition arrays
c          corresponding to the upper plenum left surface nodes
c  nvadur  offset index for the relap5 coolant condition arrays
c          corresponding to the upper plenum right surface nodes
c  ntuvol  total number of upper plenum volumes
c  volusq  9-digit integer identifying RELAP5 volume adjacent to upper
c          plenum surfaces in sequential order
c  ntusur  total number of upper plenum surfaces within a volume
c  icups   combined index that represents current upper plenum structure
c          number, axial level number, and left or right surface.
c          icups=1000*is+iax with +/- values for left/right surfaces.
c          is=abs(icups)/1000 and iax=abs(icups)-is*1000
       real wtfe,   wtcr,   wtni,   wtfeo,  wtf3o4, wtc2o3, wtnio,
     &      wth2o,  fmfe,   fmcr,   fmni,   fmfeo,  fmf3o4, fmc2o3,
     &      fmnio,  tmlups, dnmups, dnlups, dnxups, hfuups, fxlups,
     &      thlups, ulups,  hlups,  liups,  saups,  hvups,  hhups,
     &      hhtot
       integer isuser, ntups,  ntupax, ntupcn, isoups, volupl, volupr,
     &         nvadul, nvadur, ntuvol, volusq, ntsur,  icups
       integer mcme34
       common /upccon/ wtfe,   wtcr,   wtni,   wtfeo,  wtf3o4, wtc2o3,
     &         wtnio,  wth2o,  fmfe,   fmcr,   fmni,   fmfeo,  fmf3o4,
     &         fmc2o3, fmnio,  tmlups, dnmups, dnlups, dnxups, hfuups,
     &         fxlups, thlups, ulups,  hlups,
     &         liups(nmupcn,nmupax,nmups),     saups(nmupax,nmups),
     &         hvups(nmupax,nmups),    hhups(nmupax,nmups),
     &         hhtot(nmups),   isuser(nmups),  ntups,
     &         ntupax(nmups),          ntupcn(nmupax,nmups),
     &         isoups(nmupax,nmups),   volupl(nmupax,nmups),
     &         volupr(nmupax,nmups),   nvadul(nmupax,nmups),
     &         nvadur(nmupax,nmups),   ntuvol, volusq(2*nmupax*nmups),
     &         ntsur(2*nmupax*nmups),  icups(2*nmups,2*nmupax*nmups),
     &         mcme34
*endif
