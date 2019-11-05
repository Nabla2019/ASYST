*mlist
c
c  miscon contains miscelaneous SCDAP constants.
c
c  Cognizant engineer: ewc.
c
*if def,selap
       common /miscon/ puliq,fmix,fracgm,epsox2,tmpfal,faxial(ndax),
     & rftemp,tmpmel(ndgrid),zzero(ndax),
     & dtfail,frcoxf,vdrop,effoxd(ndcomp,ndax),flmpmn,
     & fovlap,fmnrfl,fredmn,ttmpbk,dtspll,fathrs,tshmax,
     & fbafll,fbtrn1,fbtrn2,
     & tsfrez,tdrslp,fmdiff,nvirn,nwet,
     & ndkset,nzero(ndax),trpfal,icode,iox(ndcomp),
     & ioxlm(ndax,ndcomp),shtflg(ndax,ndcomp),
     # nsmgeo,nsmdif,crm(ndcomp),mcme45
       real puliq,fmix,fracgm,tmpfal,faxial,rftemp,tmpmel,
     & zzero,dtfail,frcoxf,epsox2,vdrop,effoxd,tsfrez,
     & tdrslp,fmdiff,flmpmn,
     & fovlap,fmnrfl,fredmn,ttmpbk,dtspll,fathrs,tshmax
       real fbafll,fbtrn1,fbtrn2
       integer nvirn,nwet,ndkset,nzero,trpfal,icode,ioxlm,shtflg,
     & iox,nsmdif,nsmgeo,crm,mcme45
c
c  frcoxf = fraction of cladding oxidized beyond which liquefied
c           metallic cladding cannot dissolve and fail oxide
c           shell containing the metallic zr.
c  tmpfal = minimum temperature that oxide shell must attain
c           before liquefied metallic zr can dissolve and fail
c           oxide shell (k).
c  trpfal = relap5 boolean trip, which when true will
c           shatter all oxide in the core.
c  icode  = packed code for trip trpfal
c  tmpmel = melting temperature of grid spacers.
c  fracgm = fraction of total heat generation in the form of
c           gamma rays directly input to the coolant.
c  epsox2 = threshold for cladding hoop strain after which
c           double-sided oxidation commences.
c  vdrop =  velocity of drops of cladding material slumping
c           down outside surface of fuel (m/s).
c  effoxd = effective oxide layer thickness from reflood shattering
c           model
c  ioxlm  = integer flag indicating whether or not the limit on
c           steam diffusion through hydrogen should be imposed.
c           =0 if limit not imposed, =1 if limit is imposed.
c  shtflg = integer flag indicating whether or not the clad oxide
c           has been shattered.
c           =0 if not shattered, =1 if shattered.
c  tsfrez = maximum temperature of cladding surface that still
c           results in enough cooling of drops of slumping cladding
c           material that they freeze at that location (K).
c  tdrslp = threshold value of fraction of surface area covered with
c           drops that results in blockage that stops local
c           oxidation.
c  fmdiff = factor on fuel rod diameter that results in minimum
c           thickness
c           that crust must have to support and seal molten pool.
c  flmpmn = minimum fractional flow area of flow channel
c           at periphery of core after outermost group of fuel rods
c           have become molten.
c  nsmdif = index to select cladding oxide failure model.
c           0 oxide failure at either double- or single-side
c             oxidation
c           1 oxide failure only where double-sided oxidation
c  fovlap = factor of overlap of slumped drops of cladding;
c           the more the overlap, the greater the flow blockage,
c           (unitless)
c  fmnrfl = minimum fraction of reduction of oxidation of relocated
c           cladding due to blockage during reflood (unitless)
c  fredmn = minimum fraction of reduction of oxidation of relocated
c           cladding due to flow blockage before reflood.
c  ttmpbk = temperature at which oxidation of relocated cladding stops
c           due to blockage or other factors.
c  dtspll = incremental increase in weight gain before another spalling
c           of oxide layer can occur during reflood (kg/m2).
c  fathrs = threshold fraction of fill up of flow area at axial node 
c           results in beginning of reduction on oxidation of slumped
c           cladding (unitless)
c  tshmax = maximum temperature for shattering of oxide layer on
c           slumped cladding (K)
c  fbafll = value for fraction of surface of axial node covered with
c           slumped cladding resulting in complete blockage of oxidation,
c           even during reflood.
c  fbtrn1 = value of fraction of cladding surface covered with slumped
c           cladding resulting in start of reduction in oxidation for
c           non-reflood conditions.
c  fbtrn2 = value of fraction of cladding surface covered with slumped
c           cladding resulting in complete blockage of oxidation
c           before reflood.
*endif
