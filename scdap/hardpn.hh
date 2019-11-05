*mlist
*comdeck hardpn
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
       common /hardpn/ thkhpn(ndcomp),tihdpn(ndcomp),achdpn(ndcomp),
     # bchdpn(ndcomp),cchdpn(ndcomp),fahdpn(ndcomp),qdhdpn(ndcomp),
     # tchdpn(ndcomp),rhohpn(ndcomp),cphdpn(ndcomp),cnhdpn(ndcomp),
     # hfhdpn(ndcomp),hchdpn(ndcomp),qgmhpn(ndcomp),qchdpn(ndcomp),
     # tmhdpn(ndcomp),tupool,wupool,wzpool,qdpool,wapool,wspool,
     # emltld,qhpool,hnpool(ndcomp),t0hdpn(ndcomp),thklay(ndcomp),
     * qcrthp(ndcomp),repool,vlpool,qgmhpu(ndcomp),qcvhpu(ndcomp),
     # tchdpu(ndcomp),tmpslg(ndcomp),dmaxcr,temrod(ndcomp),
     # qaxemr(ndcomp),thkcer(ndcomp),tmltuo,pipool,wtdome,
     & tcbotmn,tcsidmn,qdcaypl,
     # redome,eatadm,wmpool,wmpolz,mltprg,ncerhp(ndcomp),
     * ibhdpn(ndcomp),nshdpn(ndcomp),iswlay(ndcomp),nmetsw(ndcomp),
     * nceram(ndcomp),ifaluc(ndcomp),matmld,itjump(ndcomp),mcme37
       real thkhpn,tihdpn,achdpn,bchdpn,cchdpn,fahdpn,qdhdpn,tchdpn,
     * rhohpn,cphdpn,cnhdpn,hfhdpn,hchdpn,qgmhpn,qchdpn,tmhdpn,tupool,
     * wupool,wzpool,qdpool,wapool,wspool,emltld,qhpool,hnpool,t0hdpn,
     * thklay,qcrthp,repool,vlpool,qgmhpu,qcvhpu,tchdpu,tmpslg,
     * dmaxcr,thkcer,tmltuo,wmpool,wmpolz
       real temrod,qaxemr
       real pipool,wtdome,redome,eatadm
       real tcbotmn,tcsidmn,qdcaypl
       integer ncerhp,mltprg
       integer ibhdpn,nshdpn,iswlay,nmetsw,nceram,ifaluc,itjump,matmld,
     * mcme37
c
c  achdpn(j)  = the constant a in 2nd order polynomial of temperature
c               distribution for component j
c  bchdpn(j)  = the constant b
c  cchdpn(j)  = the constant c
c  cnhdpn(j)  = thermal conductivity of hardpan (w/m.k)
c  cphdpn(j)  = heat capacity of hardpan (j/kg.k)
c  dmaxcr     = total rate of heat transfer out of molten pool (W)
!  qdcaypl    = total decay heat generation in molten pool (W)
!  tcbotmn    = minimum thickness crust at bottom of molten pool (m)
!  tcsidmn    = minimum thickness crust at side of molten pool (m)
c  emltld     = accumulated input of energy to overcome phase
c               change. (j)
c  fahdpn(j)  = configuration factor on radiation from outer surface
c               for component j.
c  hchdpn(j)  = h.t.c. from convection at bottom surface of
c               hardpan. (w/m**2.k)
c  hfhdpn(j)  = heat of fusion of hardpan(j/kg)
c  hnpool(j)  = h.t.c. between liquefied core debris and hardpan.  If
c               tupool<tmltuo, then hnpool equals heat transfer coef-
c               ficient between coolant and upper surface of hardpan.
c  ibhdpn(j)  = indicator of breach in hardpan for component j
c               0=no, 1=yes.
c  ifaluc(j)  = indicator of failure of crust above molten pool
c               due to meltthrough; 0=no failure, 1=failure.
c               This variable is calculated in subroutine heatld and
c               used in subroutine crucbr.
c  iswlay(j)  = indicator of new layer of zr added to top of
c               hardpan during time step, 0=no, 1=yes.
c  matmld     = material number of material melting
c  nceram(j)  = flag indicating whether new rubble debris region formed
c               during time step. Flag is switched on in sub. rubtrn.
c               0=no; >0=lowest axial node with new debris.
c  nmetsw(j)  = flag indicating whether hardpan is metallic or
c               ceramic. 0=no hardpan; 1=metallic; 2=ceramic.
c  nshdpn(j)  = switch indicating whether temperature solution through
c               crust has begun for component j
c               0=no, 1=yes.
c  qchdpn(j)  = heat convected to relap5 volume from bottom of
c               hardpan (w)
c  qcrthp(j)  = critical heat flux at bottom of hardpan under
c               component j debris (w/m**2).
c  qcvhpu(j)  = heat transferred from upper crust of molten
c               debris into coolant (w)  calculated in heatld .
c  qdhdpn(j)  = heat generation in hardpan (w/m**3)
c  qdpool     = total heat generation due to decay heat in pool
c               of liquefied debris (w).
c  qgmhpn(j)  = heat for volumetric vapor generation rate in lower
c               plenum volume from radiation from bottom of hardpan (w)
c  qgmhpu(j)  = heat which is transfered from upper crust of
c               molten debris into coolant and generates vapor (w).
c               This variable is calculated in heatld.
c***            This variable is not used in scdadv.
c  qhpool     = total heat transferred out of liquefied debris (w).
c  repool     = effective spherical radius of liquefied debris (m).
c  rhohpn(j)  = density of hardpan (kg/m**3)
c  t0hdpn(j)  = hardpan temperature when nshdpn(j)=0
c  tchdpn(j)  = temperature of coolant next to bottom of hardpan
c               underneath component j (k).
c  tchdpu(j)  = coolant vapor temperature at top of molten pool (k).
c               Calculated in scdadv.
c  thkhpn(j)  = thickness of hardpan in component j (m)
c  thklay(j)  = thickness of new layer added to top of hardpan
c               during time step (m).
c  tihdpn(j)  = temperature of inner surface of hardpan (k)
c  tmhdpn(j)  = melting temperature of hardpan (k)
c  temrod(j) = temperature of component j that is embedded in crust (K)
c  qaxemr(j) = heat transfer from embedded component to uncovered
c              portion of component (W) (heat transfer by conduction
c              in axial direction)
c  tmpslg     = temperature of slug of material trapped at grid spacer
c               or on top of existing cohesive debris bed.
c  tupool     = temperature of pool of liquefied core debris in
c               core region (k)
c  vlpool     = volume of liquid in molten pool (m**3).
c  wapool     = mass of ag-in-cd in molten pool (kg)
c  wspool     = mass of stainless steel in molten pool (kg)
c  wupool     = mass of uo2 in pool of liquefied debris (kg).
c  wzpool     = mass of zro2 in pool of liquefied debris (kg).
c  wmpool     = mass of metallic Zr in molten pool (kg).
c  wmpolz     = same as wmpool, but for start of time step.
c  tmltuo     = liquefaction temperature of material in molten pool (K).
c  ncerhp(j)  = 0 no ceramic crust supporting molten pool within
c               component j;
c             = k = axial node with this ceramic crust.
c  thkcer(j) = thickness of ceramic crust (m).
c  pipool = coolant pressure at time that crucible became closed (Pa)
c  wtdome = total weight of dome and material on top of dome (N).
c  redome = radius in horizontal plane of bottom of dome on top of
c           molten pool (m).
c  eatadm = height of top center of crust on top of molten pool above
c           points in crust at its periphery (m).
c  mltprg = flag indicating whether new molten pool downward propagation
c           model is to be used; 0=no, 1=yes.
*endif
