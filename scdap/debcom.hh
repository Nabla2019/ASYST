*mlist
*comdeck debcom
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c
       common /debcom/ qbtdeb(nxdbrg),porvol(ndax,nxdbrg),
     * ddbvol(ndax,nxdbrg),aovrdb(ndax,nxdbrg),tmpdeb(ndax,nxdbrg),
     * qfgdeb(ndax,nxdbrg),gmwdeb(ndax,nxdbrg),qnchdb(ndax,nxdbrg),
     * powdbl(ndax,nxdbrg),voldeb(ndax,nxdbrg),aradeb(ndax,nxdbrg),
     * tvapbt(nxdbrg),dbentn(ndax,nxdbrg),dbqenn(ndax,nxdbrg),vollh0,
     * qinvtp(ndcomp),invtp,ndbreg,nvoldb(nxdbrg),numdbv(ndax,nxdbrg),
     * nqndbl(ndax,nxdbrg),ndebup(nxdbrg),ndebbt(nxdbrg),idbcom(nxdbrg),
     * iruben(ndcomp,ndax),iencln(ndcomp,ndax,ndcomp),ktopdb(ndcomp),
     * nvoltp,vollh(ndcomp),voluh(ndcomp),lhvol(ndcomp),uhvol(ndcomp),
     # lbypss(ndax),
     # mcme23
       real qbtdeb,porvol,ddbvol,aovrdb,tmpdeb,qfgdeb,
     # gmwdeb,qnchdb,powdbl,voldeb,aradeb,tvapbt,dbentn,dbqenn,qinvtp
       real vollh0
       integer ndbreg,nvoldb,numdbv,nqndbl,ndebup,
     * ndebbt,idbcom,iruben,iencln,ktopdb,nvoltp,invtp,mcme23,
     # vollh,voluh,lhvol,uhvol,lbypss
c  variable definitions:
c  ndbreg = number of debris regions
c  nvoldb(n) = number of relap5 volumes in n-th debris region.
c              volumes are stacked one on top of other.
c  numdbv(m,n) = index of m-th relap5 volume in n-th debris region.
c                the first volume is at bottom of bed and the
c                nvoldb(n)-th volume is at top of bed. for example,
c                p(numdbv(m,n)) = coolant pressure in m-th volume of
c                n-th debris region.
c  qbtdeb(n) = heat flux into bottom of debris bed (w/m2).
c  porvol(m,n) = porosity of debris in m-th volume of n-th debris
c                region.
c  ddbvol(m,n) = diameter of debris particles in m-th volume of n-th
c                debris region (m).
c  aovrdb(m,n) = surface area of debris per unit volume for m-th vol-
c                ume of n-th debris region. (1/m). total surface
c                area of debris = aovrdb(m,n)*voldeb(m,n).
c  tmpdeb(m,n) = surface temperature of debris in m-th volume of n-th
c                debris region (k).
c  qfgdeb(m,n) = heat from debris surface of m-th volume of n-th
c                region into vapor phase (w).
c  gmwdeb(m,n) = volumetric vapor generation rate in m-th volume of
c                n-th debris region (kg/m**3.s)
c  qnchdb(m,n) = heat removed from debris in m-th volume of n-th
c                debris region (w).  qnchdb(m,n)*(delta-t) = total
c                heat removed from debris during time step.
c  powdbl(m,n) = power density of debris in m-th volume of n-th debris
c                region (w/m**3).  Total power in bed volume divided
c                by bed volume.
c  nqndbl(m,n) = indicator of whether debris in m-th volume of n-th
c                debris region is in state of dryout or quenched.
c                -1 = completely quenched, 0 = in process of being
c                quenched, 1 = state of dryout.
c  qfldeb(n) = mass flux of liquid at bottom of debris bed (kg/m**2.s).
c  ndebup(n) = maximum axial node number of debris in n-th debris
c              region.
c  ndebbt(n) = minimum axial node number of debris in n-th region.
c  idbcom(i,n) = component number of the i-th component in n-th debris
c              region.
c  iruben(i,k) = number of component groups that are debris in i-th en-
c                closure at k-th axial node. if no component is debris,
c                iruben(i,k)=0.
c  iencln(i,k,j) = component number of j-th component group that is
c                  debris at k-th axial node of i-th enclosure.
c  ktopdb(j) = top axial node for j-th component that has been
c              identified as being debris. this variable is local.
c  voldeb(m,n) = volume of debris at m-th level of n-th debris region
c                (m**3).
c  aradeb(m,n) =cross-sectional area of debris at m-th level of n-th
c               debris region (m**2).
c  tvapbt(n)=vapor temperature at bottom of debris bed (k).
c  nvoltp   = number of volume at top center of core.
c  invtp    = index offset of data for volume nvoltp.
c  dbentn(m,n)=stored thermal energy at start of quenching of debris
c              at location m,n (j).
c  dbqenn(m,n)=accumulated amount of stored energy removed from
c              debris at location m,n during quenching process (j).
c  qinvtp     = energy transferred from surface of debris bed that is
c               at top of core, to relap5 control volume that
c               interfaces with top of core (w).
c  vollh0 = volume at start of transient of RELAP5 control volume
c           representing lower head of reactor vessel.
c  vollh(m) = relap5 volume number of volume just below core component m
c  voluh(m) = relap5 volume number of volume just above core component m
c  uhvol(m) = offset to volume just above core component m
c  lhvol(m) = offset to volume just below core component m
c  lbypss(k) = offset index for RELAP5 volume at edge of core for k-th
c              volume from bottom of stack.
*endif
