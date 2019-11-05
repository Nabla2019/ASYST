*mlist
*comdeck dbacct
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c
       common /dbacct/ rgelv(ndrg),rghigt(ndrg),hit(ndrg),arear,siznr,
     * usrspr,usrslr(5),poros(ndrg),
     # zdrops(ndax,ndcomp),rdrops(ndax,ndcomp),zdrpsz(ndax,ndcomp),
     # tdrops(ndax,ndcomp),tdrpsz(ndax,ndcomp),
     # wdrop0(ndax,ndcomp),wdrop1(ndax,ndcomp),wdrpmx(ndax,ndcomp),
     # wdrspa(ndax,ndcomp),wdspa0(ndax,ndcomp),heffox(ndax,ndcomp),
     # wdspls(ndax,ndcomp),wdsps0(ndax,ndcomp),
     # qdrops(ndax,ndcomp),udrops(ndax,ndcomp),
     # udrpsz(ndax,ndcomp),qcdrps(ndax,ndcomp),qsdrps(ndax,ndcomp),
     # hgdrps(ndax,ndcomp),hgdrpz(ndax,ndcomp),
     # wzrdrp(ndax,ndcomp),wuodrp(ndax,ndcomp),
     # fadrop(ndax,ndcomp),fadrpz(ndax,ndcomp),
     # fafdrp(ndax,ndcomp),fafdpz(ndax,ndcomp),wslomx(ndax,ndcomp),
     # wslom2(ndax,ndcomp),
     # wgcoh(ndax,ndcomp), wgcohz(ndax,ndcomp),
     # wgcoht(ndax,ndcomp),wgchtz(ndax,ndcomp),
     # wgtop(ndax,ndcomp), wgtopz(ndax,ndcomp),
     # hefctp(ndax,ndcomp),hefctz(ndax,ndcomp),
     # hefcbt(ndax,ndcomp),
     # hefcbz(ndax,ndcomp),
     # wgbot(ndax,ndcomp), wgbotz(ndax,ndcomp),wgbott(ndax,ndcomp)
       common /dbacct/ ndrfz1(ndax,ndcomp),ndrfz2(ndax,ndcomp),
     # wdrfz1(ndax,ndcomp),wdrfz2(ndax,ndcomp),wfzsp1(ndax,ndcomp),
     # wfzsp2(ndax,ndcomp),wfzsa1(ndax,ndcomp),wfzsa2(ndax,ndcomp),
     # tnxdr1(ndax,ndcomp),pdrfz1(ndax,ndcomp),pdrfz2(ndax,ndcomp),
     # tnxdr2(ndax,ndcomp),fdrmn1(ndax,ndcomp),fdrmn2(ndax,ndcomp),
     # fudfz1(ndax,ndcomp),fudfz2(ndax,ndcomp),
     # wfzuo1(ndax,ndcomp),wfzuo2(ndax,ndcomp),
     # wfzzr1(ndax,ndcomp),wfzzr2(ndax,ndcomp),wdfzm1(ndax,ndcomp),
     # wdfzm2(ndax,ndcomp),hfzox1(ndax,ndcomp),hfzox2(ndax,ndcomp),
     # wuobc1(ndax,ndcomp),wzrbc1(ndax,ndcomp),woxbc1(ndax,ndcomp),
     # wuobc2(ndax,ndcomp),wzrbc2(ndax,ndcomp),woxbc2(ndax,ndcomp),
     # tnxsp1(ndax,ndcomp),tnxsp2(ndax,ndcomp),wtgnmx(ndax,ndcomp)
       common /dbacct/
     # wgbttz(ndax,ndcomp),wgrd(ndax,ndcomp),  wgrdz(ndax,ndcomp),
     # qcohst(ndax,ndcomp),
     # hgcohs(ndax,ndcomp),hgchsz(ndax,ndcomp),fudrop(ndax,ndcomp),
     # fudrpz(ndax,ndcomp),fucoht(ndax,ndcomp),fuchtz(ndax,ndcomp),
     # fucohb(ndax,ndcomp),fuchbz(ndax,ndcomp),
     # tzrdeb(ndax,ndcomp),wzrdeb(ndax,ndcomp),wgzrd0(ndax,ndcomp),
     # wgzrd1(ndax,ndcomp),tuodeb(ndax,ndcomp),wguod0(ndax,ndcomp),
     # wguod1(ndax,ndcomp),tzodeb(ndax,ndcomp),ddbeff(ndax,ndcomp),
     # qdebox(ndax,ndcomp),fuocld(ndax,ndcomp),wmxcld(ndax,ndcomp),
     # hefcld(ndax,ndcomp),wmxful(ndax,ndcomp),nzrdeb(ndax,ndcomp),
     # nuodeb(ndax,ndcomp),nzodeb(ndax,ndcomp),hgdeb(ndax,ndcomp),
     # qdboxm(ndax,ndcomp),hgdebm(ndax,ndcomp),tmlsol(ndax,ndcomp),
     # tmlliq(ndax,ndcomp),frcmcl(ndcomp,ndax),woxrub(ndax,ndcomp),
     # woxrb0(ndax,ndcomp),klsif0(ndax,ndcomp),klsif1(ndax,ndcomp),
     # klsir0(ndax,ndcomp),klsir1(ndax,ndcomp),dhydb0(ndax,ndcomp),
     # dhydb1(ndax,ndcomp),avold0(ndax,ndcomp),avold1(ndax,ndcomp),
     # klsof0(ndax,ndcomp),klsof1(ndax,ndcomp),klsor0(ndax,ndcomp),
     # klsor1(ndax,ndcomp),effoxw(ndax,ndcomp),effow0(ndax,ndcomp),
     # tmxful(ndax,ndcomp),tmxfl0(ndax,ndcomp),oxdhmx(ndax,ndcomp),
     & toxhmx(ndax,ndcomp) 
       common /dbacct/
     # ndrops(ndax,ndcomp),rsscn0(ndax,ndcomp),rsscn1(ndax,ndcomp),
     # rzrcn0(ndax,ndcomp),rzrcn1(ndax,ndcomp),powadz(ndax,ndcomp),
     & qgrdox(ndax,ndcomp),qoxcht(ndax,ndcomp),qoxchb(ndax,ndcomp),
     # unucaz(ndax,ndcomp),qsdrgs(ndax,ndcomp),fadrpg(ndax,ndcomp),
     # fafdrg(ndax,ndcomp),qcdrgs(ndax,ndcomp),windrp(ndax,ndcomp),
     # wzgdrp(ndax,ndcomp),zdrpgs(ndax,ndcomp),zdrgsz(ndax,ndcomp),
     # tdrpgs(ndax,ndcomp),tdrgsz(ndax,ndcomp),rdrpgs(ndax,ndcomp),
     # udrpgs(ndax,ndcomp),udrgsz(ndax,ndcomp),ndrpsz(ndax,ndcomp),
     # bgthqd,bgthqi,bgthi,kdrops(ndax,ndcomp),kdrpsz(ndax,ndcomp),
     # idrops(ndax,ndcomp),idrpsz(ndax,ndcomp),idrfz1(ndax,ndcomp),
     # idrfz2(ndax,ndcomp),
     # idrpgs(ndax,ndcomp),idrgsz(ndax,ndcomp),ndrpgs(ndax,ndcomp),
     # ndrgsz(ndax,ndcomp),kdrpgs(ndax,ndcomp),kdrgsz(ndax,ndcomp),
     # ishrem(ndax,ndcomp),ntotrg,idbndl(ndrg),mcme22
       real rgelv,rghigt,hit,arear,siznr,usrspr,usrslr,poros
       integer ntotrg,idbndl,ishrem,mcme22
       real zdrops,rdrops,ndrops,zdrpsz,tdrops,tdrpsz,wdrop0,
     # wdrop1,heffox,qdrops,udrops,udrpsz,qcdrps,qsdrps,ndrpsz,
     # hgdrps,hgdrpz,wgcoh,wgcohz,wgcoht,wgchtz,wgtop,
     # wgtopz,hefctp,hefctz,hefcbt,wgbot,wdrspa,wdspa0,
     # wgbotz,wgbott,wgbttz,wgrd,wgrdz,hefcbz,wzrdrp,wuodrp,
     # qcohst,hgcohs,hgchsz,fudrop,fudrpz,wdrpmx,wslomx,wslom2,
     # fadrop,fadrpz,fafdrp,fafdpz,fucoht,fuchtz,fucohb,fuchbz,
     # tzrdeb,wzrdeb,wgzrd0,wgzrd1,tuodeb,wguod0,wguod1,tzodeb,
     # ddbeff,qdebox,fuocld,wmxcld,hefcld,wmxful,nzrdeb,nuodeb,
     # nzodeb,hgdeb,hgdebm,qdboxm,bgthqd,bgthqi,bgthi,
     # rsscn0,rsscn1,rzrcn0,rzrcn1,powadz,unucaz,wdspls,wdsps0,
     # tmlsol,tmlliq,frcmcl,woxrub,woxrb0,klsif0,klsif1,klsir0,
     # klsir1,dhydb0,dhydb1,avold0,avold1,klsof0,klsof1,klsor0,
     # klsor1,ndrfz1,ndrfz2,wdrfz1,wdrfz2,wfzsp1,wfzsp2,wfzsa1,
     # wfzsa2,pdrfz1,pdrfz2,
     # tnxdr1,tnxdr2,fdrmn1,fdrmn2,fudfz1,fudfz2,wfzuo1,
     # wfzuo2,wfzzr1,wfzzr2,wdfzm1,wdfzm2,hfzox1,hfzox2,wuobc1,
     # wzrbc1,woxbc1,wuobc2,wzrbc2,woxbc2,tnxsp1,tnxsp2,wtgnmx,
     # effoxw,effow0,tmxful,tmxfl0,oxdhmx,toxhmx
       real qgrdox,qoxcht,qoxchb
       real qsdrgs,fadrpg,fafdrg,qcdrgs,windrp,wzgdrp,zdrpgs,
     # zdrgsz,tdrpgs,tdrgsz,rdrpgs,udrpgs,udrgsz,ndrpgs,ndrgsz
       integer kdrops,kdrpsz,idrops,idrpsz,idrfz1,idrfz2
       integer idrpgs,idrgsz,kdrpgs,kdrgsz
c    ****************************************************************
c     definition of variables that apply to drops of relocating
c     material.
c     In definitions presented below, n = axial node at which
c     drops originated, j = component number of rod with drops.
c     zdrops(n,j)=elevation of drops of liquefied cladding material
c     that originated at axial node n of component j (m).
c     rdrops(n,j)=effective radius of drops (m).
c     zdrpsz(n,j)=same as zdrops(n,j), but start of time step.
c     tdrops(n,j)=temperature of drops (K).
c     tdrpsz(n,j)=same as tdrops(n,j), but start of time step.
c     wdrop0(n,j)=start of time step weight gain of drops (kg O2/m2).
c     wdrop1(n,j)=end of time step weight gain of drops.
c     wdrspa(n,j)=weight gain in drop since last spalling of oxide.
c     wdrspa0(n,j)=same as wdrspa(n,j) but for start of time step.
c     wdspls(n,j)=weight gain of drop at time of last spalling.
c     wdsps0(n,j)=same as wdspls but for start of time step.
c     wdrpmx(n,j)=weight gain for complete oxidation of drop (kg O2/m2)
c     heffox(n,j)=effective heat of reaction of drop (J/kg of oxidized
c                 Zr and UO2).
c     udrops(n,j)=velocity of drops (m/s).
c     udrpsz(n,j)=same as udrops(n,j) but for start of time step.
c     tnxdr1(n,j)=time at which next period of slumping begins for
c                 liquefied cladding material at axial node n of
c                 component at start of time step (s).
c     tnxdr1(n,j)=same as tnxdr1(k,j) but for start of time step.
c     pdrfz1(n,j)=nuclear heat generation in drops of relocating
c                 material at start of time step ( sum of all drops
c                 either frozen at node or for all moving drops
c                 where n is node of origin) (W).
c     pdrfz2(n,j)=same as pdrfz1(n,j) but for start of time step.
c     fdrmn1(n,j)=fraction of node height that has had liquefied
c                 cladding slump away from axial node n (value at
c                 start of time step).
c     fdrmn2(n,j)= same fdrmn1(k,j) but for end of time step.
c     qcdrps(k,j)=heat conducted into fuel rod at axial node k from
c     all drops that are located in axial node k, including those
c     in form of cohesive debris. (W/m).
c     If drops are solidified, then qcdrps(k,j) is the oxidation
c     heat generation in the drops.
c     qsdrps(k,j)=heat transferred to steam by drops at axial node k.
c                 (W).
c     qdrops(k,j)=heat generation due to oxidation of drops of
c                 relocated material (W/m per rod).
c     hgdrps(k,j)=hydrogen production due to oxidation
c                 of drops that are currently located at axial
c                 node k (kg/s). It is sum of hydrogen production
c                 due to drops that originated at several different
c                 locations and now are located at axial node k.
c     hgdrpz(n,j)=same as hgdrps but for start of time step.
c     qgrdox(n,j)=heat generation due to oxidation of Zr spacer grid,
c                 spread over height of axial node containing the 
c                 spacer grid (W/m)
c     qoxcht(n,j)=heat generation due to oxidation of top surface of
c                 cohesive debris at axial node n (W/m over axial node)
c     qoxchb(n,j)=same as qoxcht(n,j) but for bottom surface.
c     wzrdrp(n,j)=initial mass of Zr in drop (kg).
c     wuodrp(n,j)=initial mass of UO2 in drop.
c     fadrop(k,j)=fraction of surface area at axial node k that is
c                 covered with  frozen drops.
c     fadrpz(k,j)=same as fadrop(k,j) but for start of time step.
c     fafdrp(k,j)=fraction of surface area at axial node k that is
c                 covered with moving drops.
c     fafdpz(k,j)=same as fafdrp(k,j) but for start of time step.
c     fudrop(n,j)=mass fraction of UO2 in mixture of liquefied material
c                 that originated at axial node n.
c     fudrpz(n,j)=same as fudrop(n,j but for start of time step.
c     wslomx(n,j)=weight gain in slumped and frozen cladding that
c                 result in complete oxidation of the slumped cladding
c                 (kg o2)
c     wslom2(n,j) = end of time step value of wslomx(n,j)
c     ****************************************************************
c     Following variables apply to frozen drops that are collected and
c     represented as one drop (but many individual members)
c     idrfz1(k,j)=indicator of collective frozen drops at axial node k;
c                 0=no, 1=yes with all drops solid, 2 = yes with
c                 remelting of drops, 3 = complete oxidation of
c                 collective drops.
c     idrfz2(k,j)=same as idrfz1(k,j) but for end of time step.
c     ndrfz1(k,j)=number of frozen collective drops at axial node k of
c                 component j at start of time step.
c     ndrfz2(k,j)=same as ndrfz1(k,j) but for end of time step.
c     wdrfz1(k,j)=weight gain of collective drops at axial node k of
c                 component j at start of time step (kg/m**2).
c                 (weight gain for 1 m2 area of Zr)
c     wdfzm1(k,j)=weight gain for complete oxidation of collective
c                 frozen drops at start of time step (kg/m2).
c                 (weight gain that completely oxidizes 1 m2 area of Zr.
c     hfzox1(k,j)=heat of reaction of collective drops (J/kg of oxidized
c                 drop ) ( start of time step)
c     hfzox2(k,j)=same as hfzox1(k,j) but for start of time step.
c     wuobc1(k,j)=mass of dissolved UO2 at axial node k of component j
c                 at time that oxide shell is first breached (kg)
c                 (start of time step).
c     wuobc2(k,j)=same as wuobc1(k,j) but for end of time step.
c     wzrbc1(k,j)=mass of liquefied Zr at axial node k of component j
c                 at time that oxide shell is first breached (kg)
c                 (start of time step)
c     wzrbc2(k,j)=same as wzrbc1(k,j) but for end of time step.
c     woxbc1(k,j)=mass of oxygen at axial node k of component j
c                 at time that oxide shell is first breached (kg)
c                 (start of time step)
c     woxbc2(k,j)=same as woxbc1(k,j) but for end of time step.
c     wdfzm2(k,j)=weight gain for complete oxidation of collective
c                 frozen drops at end of time step (kg/m2).
c     wfzsp1(k,j)=weight gain at start of time step of collective
c                 frozen drops at time of last spalling of oxide shell
c                 (kg/m**2).
c     wfzsp2(k,j)=same as wfzsp1(k,j) but for end of time step.
c     wfzsa1(k,j)=weight gain of collective frozen drops since time of
c                 last spalling (kg/m**2) (start of time step value).
c     wfzsa1(k,j)=same as wfzsa1(k,j) but for end of time step.
c     wfzuo1(k,j)=mass of UO2 in individual collective drop of
c                 solidified slumped material (kg).
c     wfzuo2(k,j)=same as wfzuo1(k,j) but for end of time step.
c     wfzzr1(k,j)=mass of Zr in individual collective drop of
c                 solidified slumped material (kg).
c     wfzzr2(k,j)=same as wfzzr1(k,j) but for end of time step.
c     tnxsp1(k,j)=time for next spalling of oxide shell on intact shell
c                 at start of time step (s).
c     tnxsp2(k,j)=same as tnxsp1(k,j) but for end of time step.
c     wtgnmx(k,j)=weight gain of oxygen for total oxidation of
c                 cladding at axial node k of component j
c                 (kg O/m length)
c     effoxw(k,j)=weight gain in oxide of intact cladding since last
c                 shattering at end of time step (kg/m2).
c     effow0(k,j)= same as effoxw(k,j) but for start of time step.
c     tmxful(k,j)=maximum temperature in history of fuel at axial
c                 node k of component j (K).
c     tmxfl0(k,j)=same as tmxful(k,j) but start of time step value.
c     oxdhmx(k,j) = maximum oxidation heat generation rate (W/m).
c     toxhmx(k,j) = time of maximum local oxidation heat generation (s).
c     ****************************************************************
c     Following variables apply to cohesive debris at location of
c     spacer grids.  For these variables, the index k applies to axial
c     node that variables are located at, j is component number.
c     wgcoh(k,j)=current total weight gain of cohesive debris,
c                (kg O2/m2).
c     wgcohz(k,j)=same as wgcoh(k,j) but for start of time step.
c     wgcoht(k,j)=weight gain for complete oxidation of cohesive
c     debris (kg O2/m2).
c     wgchtz(k,J)=same as wgcoht(k,j) but for start of time step.
c     wgtop(k,j)=current weight gain in top most layer in cohesive
c                debris (kg O2/m2).
c     wgtopz(k,j)=same as wgtop(k,j) but for start of time step.
c     hefctp(k,j)=effective heat generation in cohesive debris at top
c     surface (J per Kg of oxidized Zr and UO2).
c     hefctz(k,j)=same as hefctp(k,j) but for start of time step.
c     hefcbt(k,j)=same as hefctp(k,j) but for bottom surface.
c     hefcbz(k,j)=same as hefcbt(k,j) but for start of time step.
c     wgbot(k,j)=current weight gain in bottom layer of cohesive
c                debris (kg O2/m2).
c     wgbotz(k,j)=same as wgbot(k,j) but for start of time step.
c     wgbott(k,j)=total weight gain for complete oxidation of
c     bottom layer of debris (kg O2/m2).
c     wgbttz(k,j)=same as wgbotz(k,j) but for start of time step.
c     wgrd(k,j)=weight gain in spacer grid (kg O2/m2).
c               Both surfaces of spacer grid are assumed to oxidize
c               equally.
c     wgrdz(k,j)=same as wgrd(k,j) but for start of time step.
c     qcohst(k,j)=(total heat generation due to oxidation of cohesive
c     debris + spacer grid))/
c     (height of axial node at which debris resides) (W/m)
c     hgcohs(k,j)=total hydrogen production due to oxidation of
c     cohesive debris (kg/s).
c     hgchsz(k,j) same as hgcohs(k,j) but for start of time step.
c     fucoht(k,j)=same as fudrop(n,j) but for top surface of
c                 cohesive debris.
c     fuchtz(k,j)=same as fudrpt(k,j) but for start of time step.
c     fucohb(k,j)=same as fucoht(k,j) but for bottom surface.
c     fuchbz(k,compj)=same as fucohb(k,j) but for start of time step.
c     ************************************************************
c     definition of integer variables for drops of relocating
c     material; index n = axial node at which drops originated,
c     index j = component number.
c     ndrops(n,j)=number of drops of material due to relocation of
c     liquefied cladding and dissolved UO2 that originated at axial
c     node n.
c     ndrpsz(n,j)=same as ndrops(n,j) but for start of time step.
c     kdrops(n,j)=axial node that drops that originated at axial node
c     n are currently located in.
c     kdrpsz(n,j) same as kdrops(n,j) but for start of time step.
c     idrops(n,j)=identifier of state of drops;
c                 0=drops have not originated,
c                 1=drops have originated and are in motion,
c                 2=drops have frozen,
c                 3=drops have impacted grid spacer or cohesive debris,
c                   and thus are no longer in existence.
c                 4=drops have completely oxidized,
c                 5=drops have slumped below bottom of core.
c     idrpsz(n,j)=same as idrops(n,j) but for start of time step.
c     variables qsdrgs(n,j) through udrgsz(n,j) have same meaning as
c     similar named variables for cladding meltdown but apply to
c     meltdown of Inconel spacer grid and its reaction with Zr cladding.
c     variables idrpgs(n,j) through kdrgsz(n,j) have same name meaning a
c    similar named variables for cladding meltdown but apply to
c    meltdown of Inconel spacer grid and its reaction with Zr cladding.
c *********************************************************************
c     definition of variables involved in modeling of oxidation of
c     rubble debris.
c     tzrdeb(k,j)=size of particles of Zr in rubble debris at axial
c                 node k of component j. The particles are assumed to
c                 be cubic in shape, so size is length of one side of
c                 cube (m).
c     wzrdeb(k,j)=mass of Zr at this location per rod (kg).
c     wgzrd0(k,j)=weight gain of oxide in Zr particles (kg O2/m2)
c                 at start of time step.
c     wgzrd1(k,j)=same as wgzrd0(k,j) but for end if time step.
c     tuodeb(k,j)=size of UO2 particles at this location (m)
c     wguod0(k,j)=weight gain of UO2 particles due to oxidation.
c                 (start of time step kg O2/m2)
c     wguod1(k,j)=same as wguod0(k,j) but for end of time step.
c     tzodeb(k,j)=size of particles of ZrO2 in rubble debris at this
c                 location (m).
c     ddbeff(k,j)=effective diamter of the mixture of particles at this
c                 location (m).
c     qdebox(k,j)=volumetric heat generation rate due to oxidation of
c                 particles of rubble debris at this location (W/m3).
c     fuocld(k,j)=fraction by weight of UO2 in cladding particles of
c                 rubble debris.
c     wmxcld(k,j)=weight gain for complete oxidation of particles of
c                 cladding in rubble debris (kg O2/m2).
c     hefcld(k,j)=effective heat of reaction from oxidation of particles
c                 of cladding with dissolved UO2 (J per kg of oxidized
c                 Zr and UO2).
c     wmxful(k,j)=weight gain for conversion of fuel particles from
c                 UO2 to (U3O8) due to oxidation.
c     nzrdeb(k,j)=number of particles of Zr in rubble debris at this
c                 location.
c     nuodeb(k,j)=number of particles of UO2 in rubble debris.
c     nzodeb(k,j)=number of particles of ZrO2 in rubble debris.
c     hgdeb(k,j)=hydrogen production due to oxidation of rubble
c                debris at this location (kg/s/rod).
c     hgdebm(k,j)=hydrogen production rate in debris using debris
c                 bed indexing (kg/m3.s)
c     qdboxm(k,j)=heat generation due to oxidation of Zr and UO2 in
c                 rubble debris (W/m3).
c     bgthqd = total heat generation in core due to oxidation of
c              debris (W).
c     bgthi = hydrogen production in core due to oxidation of intact
c             core (kg/s).
c     bgthqi = heat generation in core due to oxidation of intact part
c              of core (W).
c    rsscn0(k,j)=thickness of annulus of dissolved stainless steel
c                in PWR cladding due to chemical interaction with Zr
c                guide tube at axial node k of component j (m).
c    rsscn1(k,j)=same as rsscn0(k,j) but for end of time step.
c    rzrcn0(k,j)=thickness of annulus of dissolved zircaloy in guide tub
c                due to chemical interaction with stainless steel
c                in control rod cladding (m).
c    rzrcn1(k,j)=same as rzrcn0(k,j) but for end of time step.
c    powadz(k,j)=change in decay heat at axial node k of component j due
c                to material relocation at start of time step (W).
c                End of time step value is stored in array powadd in
c                common block /scdcom/.
c    unucaz(k,j)=startt of time step value of decay heat at axial node k
c                (W/m). End of time step value is in array unuca.
c    tmlsol(k,j)=solidus temperature of fuel rod considering all materia
c                at node (K)
c    tmlliq(k,j)=liquidus temperature of fuel rod considering all materi
c                at node (K)
c    frcmcl(ichn,k)=maximum historic value of fraction of way
c                   through melting due to heatup in flow channel ichn
c                   at axial node k.  ichn=ncmpgp(j), where j = componen
c                   number.
c    woxrub(k,j)=mass of oxygen in material at axial node k of comp.
c                no. j (kg).
c    woxrb0(k,j)=same as woxrub(k,j) but start of time step value.
c    klsif0(i,k)=forward loss coefficient at time of transition to debri
c                for inlet junction of i-th flow channel at axial node k
c    klsif1(i,k)=same as klssf0 but for current time.
c    klsir0(i,k)=same as klsif0 but for reverse direction.
c    klsir1(i,k)=same as klsir0(i,k) but for current time.
c    klsof0(i,k)=same as klsif0 but for outlet junction instead of inlet
c                junction.
c    klsof1(i,k)=same as klsof0(i,k) but for current time.
c    klsor0(i,k)=same as klsir0(i,k) but for outlet junction.
c    klsor1(i,k)= same as klsor0(i,k) but for current time.
c    dhydb0(i,k)=hydraulic diameter at time of transition to debris
c                for i-th flow channel at axial node k (m).
c    dhydb1(i,k)=same as dhydb0 but for current time.
c    avold0(i,k)=flow area at tiem of transition to debris configuration
c                for i-th flow channel at axial node k (m2).
c    avold1(i,k)=same as avold0 but for current time.
c    ishrem(k,j) = indicator of whether Zr in liner of shroud has
c                  slumped due to temperature exceeding slumping
c                  temperature (internal variable tmpfal).  
c                  (axial node k, component j)
*endif
