*mlist
c
c  Descriptive sentence for tblsp goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
       common /tblsp/ hfixf(2*ndcomp*ndax),hfixg(2*ndcomp*ndax),
     & rcrsto(ndax*ndcomp),aovcom(ndax,ndcomp),
     & qflux0(2*ndcomp*ndax),qfg0(2*ndcomp*ndax),htcf0(2*ndcomp*ndax),
     & htcg0(2*ndcomp*ndax),rcrsx0(ndax*ndcomp),qot,qoc,qor,qpr,
     & qos,qon,qoo,qoe,qst,
     & qsdt(ndcomp),qndt(ndcomp),qodt(ndcomp),qedt(ndcomp),
     & qstor(ndcomp),temp2d(ndrd+1,2*(ndax-1),ndcomp),
     & rathsa(ndax,ndcomp),dzfrcq(ndax,ndcomp),aflwgp(ndcomp,ndcomp),
     & aflwto(ndcomp),anrden(ndcomp),frmltu(ndax,ndcomp),
     & timarx(8,ndcomp,ndax),timvrx(8,ndcomp,ndax),
     & delarx(8,ndcomp,ndax),wagrub(ndax,ndcomp),delvrx(8,ndcomp,ndax),
     & wssrub(ndax,ndcomp),avols0(ndcomp,ndax),vs0(ndcomp,ndax),
     & tarxto,tvrxto,wuorub(ndax,ndcomp),wzorub(ndax,ndcomp),
     & powrub(ndax,ndcomp),ztprub(ndcomp),ztpcoh(ndcomp),
     & emltdb(ndax,ndcomp),zbtrub(ndcomp),zbtcoh(ndcomp),
     & frcpen(ndax,ndcomp),qdebcl(ndax,ndcomp),vgcore(ndax,ndcomp),
     & porcom(ndax,ndcomp),diacom(ndax,ndcomp),qstor0(ndcomp),qst0,
     & hwtnew,qlxorj(2*ndcomp*ndax),
     & damlev(ndax,ndcomp),timdeb(ndax,ndcomp),dmltax(ndax,ndcomp)
       common /tblsp/ dmltx0(ndax,ndcomp),frcspr(ndax,ndcomp),
     & frcsp0(ndax,ndcomp),wtotr(ndax),ardbmp(ndcomp),wtotb(ndcomp),
     & aradmp(ndax),qbps(ndax),qwgbps(ndax),qgmbps(ndax),
     # wtott(ndcomp),ardtmp(ndcomp),tcside(ndax),tcdome(ndcomp),
     # tcbotm(ndcomp),seside(ndax),suside(ndax),sedome(ndcomp),
     # tmbotm(ndcomp),sudome(ndcomp),tmside(ndax),tmdome(ndcomp),
     # sebotm(ndcomp),subotm(ndcomp),
     & porinp(ndax,ndcomp),diainp(ndax,ndcomp),wssdeb(ndax,ndcomp),
     & wzdeb(ndax,ndcomp),zbypss(ndax),qradpv(ndcomp,ndax,ndcomp),
     & htsht(2*ndcomp*ndax),htshff(2*ndcomp*ndax),htshft(2*ndcomp*ndax),
     & htshgg(2*ndcomp*ndax),htshgp(2*ndcomp*ndax),
     & htshgt(2*ndcomp*ndax),htsqst(2*ndcomp*ndax),
     & htsqsf(2*ndcomp*ndax),htsqsg(2*ndcomp*ndax),
     & htssmf(2*ndcomp*ndax),htssmg(2*ndcomp*ndax),
     & htsasv(2*ndcomp*ndax),dfx((ndrd+1)*ndax,8,ndcomp)
       common /tblsp/ nvhyd(2*ndcomp,ndax),nvad(2*ndcomp*ndax),icmp,
     & inaz,isgl,nx,ngpv(ndcomp,ndax),ngpc(ndcomp,ndcomp),igp,
     & icp(ndcomp),ngpflg,islbot(ndcomp),nsh,nsout(ndcomp),
     & nvhydf(2*ndcomp,ndax),irfld,
     & nflg(2*(ndax-1),ndcomp),icohpp(ndax,ndcomp),icoht(ndcomp),
     & icohb(ndcomp),nflg1(2*(ndax-1),ndcomp),node(ndax),
     & nsqarx(ndcomp,ndax),nsqvrx(ndcomp,ndax),nmaxrx,icrcb2,
     & irubpp(ndax,ndcomp),nhrdpn(ndcomp),idebcm(ndcomp),
     & lcrucb(ndax,ndcomp),irubqq(ndax,ndcomp),ienblk(ndax,ndcomp),
     & itopdb(ndax,ndcomp),idebqn(ndax,ndcomp),
     & jrtpol(ndax),kbtpol(ndcomp),numbtp,jnumbt(ndcomp),
     # knumbt(ndcomp),jnumtp(ndcomp),knumtp(ndcomp),ktppol(ndcomp),
     # numttp,
     & numrtp,jnumrt(ndax),knumrt(ndax),nblkrd(ndax,ndcomp),
     & nbypss,lbpsin(ndax),nplblk(ndcomp,ndax),nbublk(ndcomp,ndax),
     & nunblk(ndcomp,ndax),nunbl2(ndcomp,ndax),ncmpgp(ndcomp),mcme67
       real hfixf,hfixg,rcrsto,aovcom,qflux0,
     & qfg0,htcf0,htcg0,rcrsx0,qot,qoc,qor,qpr,
     & qos,qon,qoo,qoe,qst,qsdt,qndt,qodt,qedt,qstor,temp2d,rathsa,
     & dzfrcq,aflwgp,aflwto,anrden,frmltu,timarx,timvrx,delarx,wagrub,
     & delvrx,wssrub,avols0,vs0,tarxto,tvrxto,wuorub,wzorub,powrub,
     & ztprub,ztpcoh,emltdb,zbtrub,zbtcoh,frcpen,qdebcl,vgcore,porcom,
     & diacom,qstor0,qst0,hwtnew,qlxorj,damlev,timdeb,porinp,
     & diainp,wssdeb,wzdeb,zbypss,ardbmp,dmltax,dmltx0,frcspr,frcsp0,
     & wtotr,wtott,wtotb,aradmp,ardtmp,qbps,qwgbps,qgmbps,qradpv,
     # tcside,tcdome,tcbotm,seside,suside,tmbotm,sudome,tmside,
     # tmdome,sedome,sebotm,subotm,
     & htsht,htshff,htshft,htshgg,htshgp,htshgt,htsqst,htsqsf,htsqsg,
     & htssmf,htssmg,htsasv,dfx
       integer nvhyd,nvad,icmp,inaz,isgl,nx,ngpv,ngpc,igp,icp,
     & ngpflg,islbot,nsh,nsout,nvhydf,irfld,nflg,nflg1,
     & node,icohpp,icoht,icohb,nsqarx,nsqvrx,nmaxrx,icrcb2,
     & irubpp,nhrdpn,idebcm,lcrucb,irubqq,ienblk,itopdb,idebqn,
     & jrtpol,kbtpol,numbtp,jnumbt,knumbt,numrtp,jnumrt,knumrt,
     # jnumtp,knumtp,ktppol,numttp,
     & nblkrd, nbypss, lbpsin,
     & nplblk, nbublk, nunblk, nunbl2, ncmpgp, mcme67
c
c  nvad(kc)    = offset index for relap5 hydraulic arrays.
c                kc = (j-1)*ndax + k, where j is the component index
c                and k the axial level.  This offset + filndx(4)
c                yields the relpa5 volume index
c  nvhyd(j,k)  = digit relap5 volume number that overlays
c                component j at axial level k
c  ngpv(ic,k)  = offset index for relap5 hydraulic arrays for
c                flow channel ic at axial level k
c  ngpc(ic,j)  = global component number for relative component j
c                of flow channel ic
c  igp         = number of flow channels for SCDAP model of core
c  icp(ic)     = number of components in flow channel ic
c  ncmpgp(j)   = flow channel which contains right surface of component
c                j
c  rathsa(k,j) = ratio of effective surface area for convective
c                cooling to actual surface area for k-th axial node
c                of j-th component group. rathsa(k,j)=1.  for all
c                but ballooned fuel rods.
c  dzfrcq(k,i) = fraction of height of node k of component i filled
c                with cohesive debris.  dzfrcq equals dzfrcl,
c                which is defined in subroutine volrad.
c  icohsx(k,i) = switch to indicate whether axial node k of
c                component i turned into cohesive debris during
c                time step.
c  icohpp(k,i) = switch to indicate whether debris is currently
c                present at axial node k of component i.
c                0=no, 1=yes.
c  aflwgp(i,j) = as-fabricated flow area for j-th scdap component
c                in i-th enclosure (m**2).   flow area around
c                control rods is distributed among fuel rod groups.
c  aflwto(i) = as-fabricated total flow area for i-th enclosure.
c  anrden(i) = total number of fuel rods in i-th enclosure.
c  timarx(n,i,k) = time at which n-th change in area occurred in
c                  i-th enclosure with scdap components at k-th
c                  axial node (s)
c  dimensioning allows 8 changes, then first two values are lumped
c  into one value.
c  timvrx(n,i,k) = same as timarx, but applying to volume change.
c  delarx(n,i,k) = change in area for n-th change (m2)
c                da=a(t+dt)-a(t)
c  delvrx(n,i,k) = same as delarx, but applying to volume change.
c  nsqarx(i,k) = total number of area changes for i-th enclosure
c                at k-th axial node. nsqarx.le.8
c  nsqvrx(i,k) = same as nsqarx, but applying to volume change.
c  tarxto = total time for relaxation on area (s).
c  tvrxto = total time for relaxation on volume (s).
c  nmaxrx = maximum dimension for number of area changes (set
c         equal to 8).
c  avols0(i,k) = start of time step area with no relaxation
c  vs0(i,k) = start of time step volume with no relaxation
c  icrcb2 = start of time step value of crucb, the indicator of
c           whether the hardpan has breached.
c  irubpp(k,i) = indicator of whether transition from intact to
c              rubble geometry has occurred at axial node k of
c              component i. 0=no, 1=yes.
c  wuorub(k,i) = mass of uo2 per rod added to axial node by reloca-
c              tion in solid state (kg).
c  wzorub(k,i) = mass of zro2 per rod add to axial node by reloca-
c              tion in solid state. (kg).
c  idebcm(j) = indicator of whether any axial node of component j
c              is cohesive or rubble debris. 0=no, 1=yes.
c  powrub(k,i) = heat generation per component per axial node (w).
c              this variable is applied only when axial node is
c              debris.
c  emltdb(k,i) = thermal energy put into phase change of debris at
c              axial node k of component i. (j). this variable is
c              used in determination of when phase change is complete.
c  lcrucb(k,i) = indicator of whether circulating liquefied debris
c                is located at axial node k of component i. 0=no,
c                1=yes.
c  nhrdpn(j) = axial node containing hardpan in component j. this
c              variable is equal to 0 until hardpan forms.
c  ztprub(j) = top elevation of rubble debris for component j. (m).
c  ztpcoh(j) = top elevation of cohesive debris for component j (m).
c              cohesive debris is always between hardpan and rubble
c              debris.
c  zbtrub(j) = bottom elevation of rubble debris for component j.
c  zbtcoh(j) = bottom elevation of cohesive debris for component
c              j (m).
c  frcpen(k,j)=fraction of debris above molten pool at axial node
c              k of component j that has not slumped into molten
c              pool.
c  qdebcl(k,j) = heat transferred from rubble debris to coolant
c                for k-th axial node of j-th component (w/rod)
c                this variable is calculated in subroutine scdadv.
c  if quenching is not occurring, this variable is equal to zero.
c  vgcore(k,j)=void fraction of vapor for k-th axial node of
c             j-th component of scdap heat structures.
c  irubqq(k,j) = indicator of whether axial node k of com-
c                ponent j has fragmented due to quenching.
c                0=no; 1=yes. calculated in rubtrn.
c  ienblk(k,j) = indicator of relap5 upstream and downstream
c        junctions closed for relap5 volume containing this
c        location. 0=no; 1=yes.
c  if icohpp(k,j)=1 but user has specified minimum flow area
c      that is >2% of original flow area, then ienblk(k,j)=0.
c      otherwise, ienblk(k,j)=1 also.
c  itopdb(k,j)=first axial node above blockage region. if no
c              blockage, itopdb(k,j)=k.
c  idebqn(k,j) = indicator of whether k-th axial node of j-th
c                component is debris in process of quenching.
c                1=state of dryout; 0=quenching on-going;
c                -1=state of being completely quenched.
c  porcom(k,j) = porosity of debris in k-th axial node of j-th
c                component.
c  diacom(k,j) = diameter of particles of debris in k-th axial
c                node of j-th component (m).
c  aovcom(k,j) = ratio of surface area to volume of debris at
c                k-th axial node of j-th component. (1/m).
c  qcnrub(k,j) = heat conducted into rubble at k-th axial
c                node of j-th component (w/rod).
c  frmltu(k,j) = fraction of uo2 melted in rubble debris at
c                axial node k of component j.
c  qstor0 = stored energy at time 0 (j).
c  qst0   = total stored energy at time 0 for all scdap components.
c  hwtnew = weighting for new time step scdap heat transfer values.
c              (old time step weight = 1.0 - hwtnew)  (default = 0.1).
c  damlev(k,j) = level of damage at axial node k of component j;
c                0.0 = intact geometry
c                0.2 = rubble (fragmented)
c                0.4 = cohesive debris
c                1.0 = molten pool
c       for the following switches, 1 = yes; 0 = no = the default.
c  nblkrd(k,j) = indicator of blockage that causes reduction in flow
c                area at axial node k of component j.
c                0 = no blockage, 1 = blockage
c  nplblk(i,k) = indicator of planar blockage in flow channel i at
c                axial node k.
c                0 = no blockage, 1 = blockage
c  nbublk(i,k) = indicator of bulk blockage in flow channel i at
c                axial node k.
c                0 = never blocked, 1 = blocked,
c                2 = no longer blocked
c  nunblk(i,k) = indicator that metallic meltdown (planar) blockage
c                in flow channel i at axial node k has been removed.
c                0 = no, 1 = yes
c  nunbl2(k,j) = indicator that bulk blockage in flow channel i at
c                axial node k has been removed.
c                0 = no, 1 = yes, 2 = unblocking action is finished
c  nbypss = Number of volumes representing core bypass region
c  lbpsin = numbers of bypass volumes
c  zbypss = elevation of top of each RELAP5 bypass volume
c
c  dmltax(k,j) = fraction of axial node through which molten pool has
c                propagated (downward direction of propagation)
c                for node with axial node k, component group j.
c  dmltx0(k,j) = start of time step value of dmltax(k,j).
c  frcspr(k,j) = fraction of "radial" span of a node (axial node,
c                component number) that molten pool has propagated
c                through (propagation in radial direction).
c  frcsp0(k,j) = start of time step value of frcspr(k,j).
c  jrtpol(k) = component number of first fuel rod group to right of
c              molten pool for axial node k. If molten pool has
c              propagated to edge of core for an axial node,
c              jrtpol(k) = 100.
c  kbtpol(j) = bottom most axial node that is part of molten pool for
c              component j.
c  ktppol(j) = top most axial node that is part of molten pool for
c              component j.
c  numbtp = total number of component groups of fuel rods along
c              bottom of molten pool.
c  numttp = total number of component groups of fuel rods along
c              top of molten pool.
c  jnumbt(i) = number of i-th component that is part of bottom of
c              molten pool.
c  jnumtp(i) = number of i-th component that is part of top of
c              molten pool.
c  knumbt(i) = axial node number corresponding with jnumbt(i).
c  knumtp(i) = axial node number corresponding with jnumtp(i).
c  numrtp = number of axial nodes on right side of molten pool.
c  jnumrt(i) = component number of i-th node that is along right edge
c              of molten pool.  This component number is not part of
c              molten pool.
c  knumrt(i) = axial node corresponding with jnumrt(i).
c  wtotr(l) = heat flux in radial direction at l-th location that is
c             on side of molten pool. (W/m**2).
c  wtotb(l) = heat flux in axial direction at l-th location that is
c             part of bottom surface of molten pool (W/m**2).
c  wtott(l) = heat flux in axial direction at l-th location that is
c             part of top surface of molten pool (W/m**2).
c  aradmp(l) = surface area for heat transfer in radial direction of
c              l-th location on side of molten pool (m**2).
c  ardbmp(l) = surface area for heat transfer in axial direction of
c              l-th location on bottom of molten pool (m**2)
c  ardtmp(l) = surface area for heat transfer in axial direction of
c              l-th location on top of molten pool (m**2)
c  qbps(k) = heat input to RELAP5 volume adjacent to k-th axial node
c               at edge of molten pool (W).
c  qwgbps(k) = heat input to vapor corresponding with qbps(k). (W).
c  qgmbps(k) = volumetric vapor generation at k-th axial node in core
c              bypass region due to heat transfer from right edge of
c              molten pool (kg/m**3.s).
c  tcside(k) = crust thickness in side wise direction for molten
c              pool where crust is vertical and located k-th axial
c              node above bottom axial node of vertical wall. (m)
c  tcdome(j) = crust thickness in dome above crucible at j-th
c              fuel rod group number from center of core or bundle.
c              (m)
c  tcbotm(j) = crust  thickness in bottom crust that supports molten
c              pool at j-th fuel rod group number from center of
c              core or bundle (m).
c  seside(k) = effective stress at location corresponding with
c              tcside(k) (Pa).
c  suside(k) = ultimate strength at location corresponding with
c              tcside(k) (Pa).
c  sedome(j) = effective stress at location corresponding with
c              tcdome(j) (Pa).
c  sudome(j) = ultimate strength at location corresponding with
c              tcdome(j) (Pa).
c  sebotm(j) = effective stress at location corresponding with
c              tcbotm(j) (Pa).
c  subotm(j) = ultimate strength at location corresponding with
c              tcbotm(j) (Pa).
c  tmside(k) = temperature of outside surface of crust on molten
c              pool at location corresponding with tcside(k) (K).
c  tmdome(j) = temperature of outside surface of crust on molten
c              pool at location corresponding with tcdome(j) (K).
c  tmbotm(j) = temperature of outside surface of crust on molten
c              pool at location corresponding with tcbotm(j) (K).
*endif
