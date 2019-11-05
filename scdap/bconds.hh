*mlist
*if def,selap
       common /bconds/ qradab(ndcomp,ndax),
     & echflx(ndax,ndcomp),
     & thkssm(ndax,ndcomp),thkpls(ndax,ndcomp),
     & qssrbk(ndax,ndcomp),
     & tkssm0(ndax,ndcomp),tkpls0(ndax,ndcomp),
     & qssrb0(ndax,ndcomp),qrfl(ndax,ndcomp),qwgrfl(ndax,ndcomp),
     & gamrfl(ndax,ndcomp),thkcol(ndax,ndcomp),thkcl0(ndax,ndcomp),
     & thkemb(ndax,ndcomp),thkem0(ndax,ndcomp),tcoluo(ndax,ndcomp),
     & mdtslp(ndcomp),mduslp(ndcomp),mdzslp(ndcomp),mdaslp(ndcomp),
     & mdsslp(ndcomp),entslp(ndcomp),qdpslp(ndcomp),mdmslp(ndcomp),
     & htcssr(ndcomp),timslp(ndcomp),dvspll(ndcomp),velslp(ndcomp),
     & ztpool,tmxlss,
     & wuocum,wzrcum,wzocum,wuohed,wzrhed,wzohed,
     & wuocumz,wzrcumz,wzocumz,wuohedz,wzrhedz,wzohedz,
     & qlpoolr,qcrustr,tslpot,tslpbt,zslpot,wdtslp,wdtslb,
     & frcbotn,frcradn,pexpool,zbpool,sedomer,sudomer,tcdomer,
     & radpool,tmzthrw,tmrthrw,tmzthr(ndcomp),tmrthr(ndcomp),
     & nssrht(ndax,ndcomp),mssrmc(ndax,ndcomp),mssrmx(ndax,ndcomp),
     & kbrssr(ndcomp),kbrsr0(ndcomp),
     & nssrh0(ndax,ndcomp),mssrm0(ndax,ndcomp),msrmx0(ndax,ndcomp),
     & nvechn(ndax,ndcomp),
     & khydch(ndax,ndcomp),nodech(ndcomp),npldrn(ndcomp),npldr0(ndcomp),
     & nplguo(ndcomp),nplguz(ndcomp),nblkrf(ndcomp),nblkr0(ndcomp),
cljs & ishdcr(ndcomp),mcme03
     & ishdcr(ndcomp),kmnins(ndcomp),kmxins(ndcomp),islpot,mcme03
       real qradab
       real wuocum,wzrcum,wzocum,wuohed,wzrhed,wzohed,
     & wuocumz,wzrcumz,wzocumz,wuohedz,wzrhedz,wzohedz
       real qlpoolr,qcrustr,tslpot,tslpbt,zslpot,wdtslp,wdtslb
       real frcbotn,frcradn,pexpool,zbpool,sedomer,sudomer,tcdomer,
     & radpool,tmzthrw,tmrthrw,tmzthr,tmrthr
       real thkssm,thkpls,qssrbk,tkssm0,tkpls0,qssrb0,
     & ztpool,htcssr,timslp,dvspll,velslp,mdtslp,qdpslp,mduslp,
     & mdzslp,mdaslp,mdsslp,entslp,qrfl,qwgrfl,gamrfl,thkcol,thkcl0,
     & thkemb,thkem0,tcoluo,tmxlss,mdmslp
       real echflx
       integer nssrht,mssrmc,mssrmx,nplguo
       integer nssrh0,mssrm0,msrmx0,npldr0,nplguz,
     & kbrssr,kbrsr0,nblkrf,nblkr0
       integer nvechn,khydch,nodech,npldrn,ishdcr
       integer kmnins,kmxins
       integer islpot
       integer mcme03
c      Definition of variables in this common block.
c
c      thkssm(k,j)=distance in radial direction that melt front has
c                  propagated into AP-600 stainless steel reflector
c                  at axial node k for component j, where j is shroud
c                  component with embedded flow channel (m).
c      tkssm0(k,j)=start of time step value.
c      For variables described below, the indices k and j are as
c      defined for variable thkssm(k,j).
c      thkpls(k,j)=distance in radial direction that solidification
c                  front has spread into molten pool and outward from
c                  inner surface of reflector.
c      tkpls0(k,j)=start of time step value.
c      qssrbk(k,j)=heat input by convection to shroud due to contact
c                  flowing molten material in embedded flow channel,
c                  (W/axial node).
c      qssrb0(k,j)=start of time step value.
c      qrfl(k,j)=heat input to fluid in RELAP5 control volume at this
c              location (W).
c      qwgrfl(k,j)=heat input to vapor part of fluid in RELAP5 control
c                  volume at this point.
c      gamrfl(k,j)=volumetric vapor generation rate at RELAP5 control
c                  volume at this location (kg/m3.s).
c      thkcol(k,j)=thickness of annulus of solidified material in
c                  column of molten material in embedded flow channel
c                  in reflector (m).
c      thkcl0(k,j)=same as thkcol(k,j), but start of time step value.
c      thkemb(k,j)=thickness of annulus of melted reflector material
c                  around column of molten core material in embedded
c                  flow channel in reflector (m).
c      thkem0(k,j)=same as thkemb(k,j) but start of time step value.
c      tcoluo(k,j)=average temperature of column of molten core
c                  material in embedded flow channel in reflector (K).
c      htcssr(j)=heat transfer coefficient at wall in embedded flow
c                channel with molten material slumping through it,
c                (W/m2.K).
c      timslp(j)=time at which molten material has drained to elevation
c                of location of meltthrough in this section of reflector
c                (s).
c      dvspll(j)=volume of molten material that drains through reflector
c                in time span out to timslp(j) and that results in level
c                of molten pool decreasing to level of break through,
c                (m3).
c      velslp(j)=velocity of slumping material (m/s).
c      mdtslp(j)=mass flow rate of material slumping through bottom of
c                reflector to lower head (kg/s).
c      mduslp(j)=mass flow rate of UO2 slumping through bottom of
c                reflector to lower head (kg/s).
c      mdzslp(j)=mass flow rate of ZrO2.
c      mdmslp(j)=mass flow rate of metallic Zr.
c      mdaslp(j)=mass flow rate of silver.
c      mdsslp(j)=mass flow rate of stainless steel.
c      entslp(j)=internal energy of material slumping to lower head
c                (J/kg with baseline of saturation temperature).
c      qdpslp(j)=heat generation in material that slumps through
c                reflector to lower head (W/kg of molten material).
c      qrfl(j)=heat input to fluid in RELAP5 control volume at this
c              location (W).
c      ztpool=elevation of top of molten pool.
c    tmxlss=maximum thickness of layer of liquefied structural material
c            underlying crust of frozen molten pool material at surface
c            of structure interfacing molten pool at periphery of core,
c             (m) [defined by input].
c      qdpslp(j)=heat generation in material that slumps through
c                reflector to lower head (W).
c      nssrht(k,j)=switch to indicate whether inner surface of reflector
c                 contacts molten pool at axial node k, comp. # j.
c                 0=no, 1=yes. If set to yes, variable stays equal to
c                 yes.
c      nssrh0(k,j)=start of time step value.
c      mssrmc(k,j)=lowest numbered radial node in reflector component
c                  through which melt front has propagated at axial node
c      mssrm0(k,j)=start of time step value.
c      msrmx0(k,j)=start of time step value.
c      npldrn(j)=indicator of axial node at which reflector has melted
c                through to location of embedded flow channels and
c                molten material is currently flowing through embedded
c                 channels. If flow is not occurring, npldrn(j)=0.
c      npldr0(j)=start of time step value of npldrn(j).
c      nplguo(j)=indicator that molten core material flowing through
c                embedded flow channel froze and plugged channel at this
c                axial node.
c      nplguz(j)=same as nplguo(j) but for start of time step.
c      kbrssr(j)=highest axial node at which column of molten material
c                has entered embedded flow channel.
c      kbrsr0(j)=start of time step value of kbrssr(j).
c      nblkrf(j)=indicator of whether flow has been blocked in embedded
c                flow channel in this component; 0=no, 1=yes.
c      nblkr0(j)=same as nblkrf(j) but for start of time step.
c      ishdcr(j)=identifier of whether component interfaces with outer
c                edge of core
c               =0=shroud does not interface with core or interact with
c                  molten pool,
c               =1=yes
c      nvechn(ndax,ndcomp)=volume pointer for embedded flow channels
c      khydch(j,k)=volume number for embedded flow channels
c      nodech(k)=radial node embedded flow channel is linked to
c      echflx(j,k)=flux into embedded flow channel
c      kmnins(j) = unused vector                                   
c      kmxins(j) = unused vector                               
c      wuocum = cumulative mass of UO2 added to molten poo (kg)
c      wzrcum = cumulative mass of Zr added to molten pool (kg)
c      wzocum = cumulative mass of Zro2 added to molten pool (kg)
c      wuohed = cumulative mass of UO2 slumped to lower head from
c               molten pool (kg)
c      wzrhed = Zr (kg)
c      wzohed = ZrO2 (kg)
c      wuocumz = start of time step value, etc for Zr, ZrO2
c      qlpoolr = molten pool radial heat flux at edge of core (W/m2)
c      qcrustr = heat flux in outer crust in radial direction
c                for molten pool at periphery of core (W/m2)
c      tslpot = last time of slumping of molten pool from outer edge
c               of core to lower head (s)
c      tslpbt = last time of slumping of molten pool to lower head
c               from bottom of molten pool (s)
c      zslpot = elevation at which molten pool is slumping from outer
c               edge of core to lower head (m)
c      wdtslp = rate at which molten material was draining from
c               molten pool at outer edge of core at last draining
c               period (kg/s)
c      wdtslb = rate at which molten material was slumping through
c               bottom of molten pool to lower head (kg/s)
c      islpot = fuel rod component number at outer edge of core
c      frcbotn = fraction of penetration of molten pool into axial
c                node immediately below bottom of molten pool at outer
c                edge
c      frcradn = fraction of penetration in radial direction of molten
c                pool into node radially outward from upper and outer  
c                edge of molten pool
c      pexpool = pressure of fluid external to molten pool (Pa)
c      zbpool = elevation of axial node containing bottom of molten
c               pool (m)
c      sedomer = stress in upper crust of molten pool at its upper and
c                outer edge (Pa)
c      sudomer = ultimate stress of crust at upper and outer edge of
c                molten pool (Pa)
c      tcdomer = thickness of crust at upper and outer edge of molten
c                pool (m)
c      radpool = fraction radius of molten pool, 1.0 = spread to outer
c                edge of core, component numbers are assumed to
c                sequentially increase as location changes from center
c                of reactor core to radially outer part of core 
c      tmzthrw = maximum rate of propagtion of molten pool in axial
c                direction due to melting at leading edge (m/s)
c      tmrthrw = same as tmzthrw but radial direction (m/s)
*endif
