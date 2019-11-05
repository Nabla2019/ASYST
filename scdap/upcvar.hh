*mlist
*comdeck upcvar
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c------------------------------------------------c
c  common /upcvar/                               c
c  variables (include in timestep repetition)    c
c------------------------------------------------c
c  iupls   contains current upper plenum conduction node number of left
c          surfaces.  1 <= iupls <= iuprs if structure is intact or
c          iupls = 0 if structure is gone
c  iuprs   contains current upper plenum conduction node number of right
c          surfaces.  iupls <= iuprs <= ntupcn if structure is intact or
c          iuprs = 0 if structure is gone
c  tups    current temperature (k) of upper plenum structure nodes
c  mmups   current mass (kg) of metal in upper plenum structure nodes
c  mmgupl  current mass (kg) of metal gained in upper plenum left
c          surface nodes.  this is used only to determine when new left
c          surface nodes should be added
c  mmgupr  current mass (kg) of metal gained in upper plenum right
c          surface nodes.  this is used only to determine when new right
c          surface nodes should be added
c  mxupls  current mass (kg) of oxides in upper plenum left surface
c          nodes.  oxide species are:
c            1 = total oxide mass
c            2 = fe (unreacted)
c            3 = ni (unreacted)
c            4 = feo
c            5 = fe3o4
c            6 = cr2o3
c            7 = nio
c  mxuprs  current mass (kg) of oxides in upper plenum right surface
c          nodes.  oxide species are same as mxupls
c  lups    current length along conduction path (m) of upper plenum
c          structure nodes.  these include thickness of oxides in left
c          and right surface nodes and are calculated from current mass
c          of nodes
c  lxupls  current thickness (m) of oxides in upper plenum left surface
c          nodes
c  lxuprs  current thickness (m) of oxides in upper plenum right surface
c          nodes
c  mlupl   current mass (kg) of liquid metal on upper plenum left
c          surface nodes.  axial level 0 represents mass below structure
c  mlupr   current mass (kg) of liquid metal on upper plenum right
c          surface nodes.  axial level 0 represents mass below structure
c  mxlupl  current mass (kg) of oxides associated with liquid metal on
c          upper plenum left surface nodes.  axial level 0 represents
c          mass below structure.  oxide species are same as mxupls
c  mxlupr  current mass (kg) of oxides associated with liquid metal on
c          upper plenum right surface nodes.  axial level 0 represents
c          mass below structure.  oxide species are same as mxupls
c  mluph   current mass below structure (kg) of liquid metal from
c          horizontal surfaces
c  mxluph  current mass below structure (kg) of oxides associated with
c          liquid metal from horizontal surfaces.  oxide species are
c          same as mxupls
c  qrupls  current heat transfer rate (w) from radiation to upper plenum
c          left surface nodes
c  qruprs  current heat transfer rate (w) from radiation to upper plenum
c          right surface nodes
c  qoupls  current heat transfer rate (w) from oxidation to upper plenum
c          left surface nodes
c  qouprs  current heat transfer rate (w) from oxidation to upper plenum
c          right surface nodes
c  qsupls  current heat transfer rate (w) from solidification to upper
c          plenum left surface nodes
c  qsuprs  current heat transfer rate (w) from solidification to upper
c          plenum right surface nodes
c  etlupl  current top elevation (m) of liquid metal on upper plenum
c          left surface nodes.  etlupl = -1.0 if no liquid metal
c  eblupl  current bottom elevation (m) of liquid metal on upper plenum
c          left surface nodes.  eblupl = -1.0 if no liquid metal
c  etlupr  current top elevation (m) of liquid metal on upper plenum
c          right surface nodes.  etlupr = -1.0 if no liquid metal
c  eblupr  current bottom elevation (m) of liquid metal on upper plenum
c          right surface nodes.  eblupr = -1.0 if no liquid metal
c  fstmul  current flow rate (kg/s) of steam for upper plenum left
c          surface nodes
c  fstmur  current flow rate (kg/s) of steam for upper plenum right
c          surface nodes
c  htcful  liquid phase convective heat transfer coefficient (w/(m2*k))
c          multiplied by fraction of surface area in contact with liquid
c          for upper plenum left surface nodes
c  htcfur  similar to htcful but for upper plenum right surface nodes
c  htcgul  vapor phase convective heat transfer coefficient (w/(m2*k))
c          multiplied by fraction of surface area in contact with vapor
c          for upper plenum left surface nodes
c  htcgur  similar to htcgul but for upper plenum right surface nodes
c  htctul  total convective heat transfer coefficient (w/(m2*k)) for
c          upper plenum left surface nodes
c  htctur  similar to htctul but for upper plenum right surface nodes
c  tsnkul  sink temperature (k) of fluid (liquid + vapor) for upper
c          plenum left surface nodes
c  tsnkur  similar to tsnkul but for upper plenum right surface nodes
c  qupl    total heat transfer rate (w) to fluid (liquid + vapor) from
c          wall for uppper plenum left surface nodes
c  qupr    total heat transfer rate (w) to fluid (liquid + vapor) from
c          wall for uppper plenum right surface nodes
c  qwgupl  heat transfer rate (w) to vapor from wall for uppper plenum
c          left surface nodes
c  qwgupr  heat transfer rate (w) to vapor from wall for uppper plenum
c          right surface nodes
c  gamupl  vapor generation rate per unit volume (kg/(s*m3)) at wall for
c          uppper plenum left surface nodes
c  gamupr  vapor generation rate per unit volume (kg/(s*m3)) at wall for
c          uppper plenum right surface nodes
       real tups,   mmups,  lups,   mmgupl, mmgupr, mxupls, mxuprs,
     &      lxupls, lxuprs, mlupl,  mlupr,  mxlupl, mxlupr, mluph,
     &      mxluph, qrupls, qruprs, qoupls, qouprs, qsupls, qsuprs,
     &      etlupl, eblupl, etlupr, eblupr, fstmul, fstmur, htcful,
     &      htcfur, htcgul, htcgur, htctul, htctur, tsnkul, tsnkur,
     &      qupl,   qupr,   qwgupl, qwgupr, gamupl, gamupr
       real tzps,   mmzps,  lzps,   mmgzpl, mmgzpr, mxzpls, mxzprs,
     &      lxzpls, lxzprs, mlzpl,  mlzpr,  mxlzpl, mxlzpr, mlzph,
     &      mxlzph, qrzpls, qrzprs, qozpls, qozprs, qszpls, qszprs,
     &      etlzpl, eblzpl, etlzpr, eblzpr, fstmzl, fstmzr, htcfzl,
     &      htcfzr, htcgzl, htcgzr, htctzl, htctzr, tsnkzl, tsnkzr,
     &      qzpl,   qzpr,   qwgzpl, qwgzpr, gamzpl, gamzpr
       integer iupls, iuprs
       integer izpls, izprs
       integer mcme42
       common /upcvar/ tups(nmupcn,nmupax,nmups),
     &         mmups(nmupcn,nmupax,nmups),  lups(nmupcn,nmupax,nmups),
     &         mmgupl(nmupax,nmups),        mmgupr(nmupax,nmups),
     &         mxupls(7,nmupax,nmups),      mxuprs(7,nmupax,nmups),
     &         lxupls(nmupax,nmups),        lxuprs(nmupax,nmups),
     &         mlupl(0:nmupax,nmups),       mlupr(0:nmupax,nmups),
     &         mxlupl(7,0:nmupax,nmups),    mxlupr(7,0:nmupax,nmups),
     &         mluph(nmups),                mxluph(7,nmups),
     &         qrupls(nmupax,nmups),        qruprs(nmupax,nmups),
     &         qoupls(nmupax,nmups),        qouprs(nmupax,nmups),
     &         qsupls(nmupax,nmups),        qsuprs(nmupax,nmups),
     &         etlupl(nmupax,nmups),        eblupl(nmupax,nmups),
     &         etlupr(nmupax,nmups),        eblupr(nmupax,nmups),
     &         fstmul(nmupax,nmups),        fstmur(nmupax,nmups)
       common /upcvar/ htcful(nmupax,nmups), htcfur(nmupax,nmups),
     &         htcgul(nmupax,nmups),        htcgur(nmupax,nmups),
     &         htctul(nmupax,nmups),        htctur(nmupax,nmups),
     &         tsnkul(nmupax,nmups),        tsnkur(nmupax,nmups),
     &         qupl(nmupax,nmups),          qupr(nmupax,nmups),
     &         qwgupl(nmupax,nmups),        qwgupr(nmupax,nmups),
     &         gamupl(nmupax,nmups),        gamupr(nmupax,nmups)
       common /upcvar/ tzps(nmupcn,nmupax,nmups),
     &         mmzps(nmupcn,nmupax,nmups),  lzps(nmupcn,nmupax,nmups),
     &         mmgzpl(nmupax,nmups),        mmgzpr(nmupax,nmups),
     &         mxzpls(7,nmupax,nmups),      mxzprs(7,nmupax,nmups),
     &         lxzpls(nmupax,nmups),        lxzprs(nmupax,nmups),
     &         mlzpl(0:nmupax,nmups),       mlzpr(0:nmupax,nmups),
     &         mxlzpl(7,0:nmupax,nmups),    mxlzpr(7,0:nmupax,nmups),
     &         mlzph(nmups),                mxlzph(7,nmups),
     &         qrzpls(nmupax,nmups),        qrzprs(nmupax,nmups),
     &         qozpls(nmupax,nmups),        qozprs(nmupax,nmups),
     &         qszpls(nmupax,nmups),        qszprs(nmupax,nmups),
     &         etlzpl(nmupax,nmups),        eblzpl(nmupax,nmups),
     &         etlzpr(nmupax,nmups),        eblzpr(nmupax,nmups),
     &         fstmzl(nmupax,nmups),        fstmzr(nmupax,nmups)
       common /upcvar/ htcfzl(nmupax,nmups), htcfzr(nmupax,nmups),
     &         htcgzl(nmupax,nmups),        htcgzr(nmupax,nmups),
     &         htctzl(nmupax,nmups),        htctzr(nmupax,nmups),
     &         tsnkzl(nmupax,nmups),        tsnkzr(nmupax,nmups),
     &         qzpl(nmupax,nmups),          qzpr(nmupax,nmups),
     &         qwgzpl(nmupax,nmups),        qwgzpr(nmupax,nmups),
     &         gamzpl(nmupax,nmups),        gamzpr(nmupax,nmups)
       common /upcvar/ iupls(nmupax,nmups), iuprs(nmupax,nmups)
       common /upcvar/ izpls(nmupax,nmups), izprs(nmupax,nmups),
     &         mcme42
*endif
