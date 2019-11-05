*mlist
c
c  Cognizant engineer: ewc.
c
       common / slumpv / aflwr1, crucb, enrslp, fcntr1, fcntr2,
     &         gamslp, hcslmp, powslp, qinslp, qinv(ndcomp),
     &         thkcbr, timcbr, timqch,
     #         enthdb(200), powseq(200), timsle(200), timsls(200),
     #         porslp(maxcpm,maxstp),  powscm(maxcpm,maxstp),
     #         radslp(maxcpm,maxstp),  tmpslp(maxcpm,maxstp),
     #         tmescm(maxcpm,maxstp),  tmsscm(maxcpm,maxstp),
     #         pfrtoc(maxcpm),
     #         wagscm(maxcpm,maxstp),  wagseq(200),  wagslp,
     #         walscm(maxcpm,maxstp),  walseq     ,  walslp,
     #         wbcscm(maxcpm,maxstp),  wbcseq(200),  wbcslp,
     #         wcdscm(maxcpm,maxstp),  wcdseq     ,  wcdslp,
     #         wliscm(maxcpm,maxstp),  wliseq     ,  wlislp,
     #         wsiscm(maxcpm,maxstp),
     #         wssscm(maxcpm,maxstp),  wssseq(200),  wssslp,
     #         wuoscm(maxcpm,maxstp),  wuoseq(200),  wuoslp,
     #         wurscm(maxcpm,maxstp),  wurseq(200),  wurslp,
     #         wzoscm(maxcpm,maxstp),  wzoseq(200),  wzoslp,
     #         wzrscm(maxcpm,maxstp),  wzrseq(200),  wzrslp,
     #         wslxxx(19,maxcpm,maxstp), wslxdt(19,maxcpm,maxstp)
       common / slumpv / inv, ncntr1, ncntr2, ncvol,
     &         njundb, nqcycl, nsqslp,
     #         nobrok(maxcpm), nctcno(maxcpm), nctcof(maxcpm),
     #         ncmesh(maxcpm), nslphs(maxcpm), nslump(maxcpm),
     #         nstslp(maxcpm), ntsoil(maxcpm), ntpslp(maxcpm),
     #         ntstrk(maxcpm),
     #         nsptrk(maxcpm,maxstp), iksave(maxcpm),
     #         icmesh(6,maxcpm), ifpdb(19,maxcpm,maxstp),
     #         mcme65
c
       real wuoslp,wurslp,wzrslp,wzoslp,wbcslp,wssslp,wagslp,tmpslp,
     * pfrtoc,radslp,porslp,powslp,timsls,timsle,enthdb,gamslp,wuoseq,
     * wurseq,wzrseq,wzoseq,wbcseq,wssseq,wagseq,powseq,enrslp,qinslp,
     * walseq, walslp, wcdseq, wcdslp, wliseq, wlislp, crucb,
     * tmsscm, tmescm, wuoscm, wurscm, wzrscm, wzoscm,
     * wbcscm, wssscm, wagscm, walscm, wcdscm, wliscm, wsiscm, powscm,
     * thkcbr, timcbr, timqch, aflwr1, hcslmp, qinv, wslxxx, wslxdt,
     & fcntr1, fcntr2
       integer nslump,nstslp,nsqslp,nqcycl,ncvol,inv,
     #         nctcno, nctcof, ntsoil, ntpslp, ntstrk, iksave,
     *         nslphs, nsptrk, ifpdb, nobrok, ncmesh, icmesh,
     &         njundb, ncntr1, ncntr2, mcme65
c
c      wuoslp = mass of uo2 that slumped into the couple mesh
c               during this time step (kg).
c      wurslp = metallic uranium.
c      wzrslp = zircaloy.
c      wzoslp = zro2.
c      wbcslp = boron carbide control rod material.
c      wssslp = stainless steel.
c       walslp = aluminum
c       wcdslp = cadmium
c       wlislp = lithium
c      wsiscm = soil
c      nslphs = couple debris source indicator -
c                         -1 = no slumping; mesh is full
c                          0 = lwr meltdown
c                          1 = user defined slumping
c                          2 = depends on components above mesh;
c                          3 = corium hydro model.
c      ntsoil = soil type for constituent 11 in Couple material 1.
c      tmpslp = temperature of material that slumped (k)
c      wslxxx(19) = mass of up to 19 fission products to be
c                   tracked in debris bed (input)  (kg)
c      wslxdt(19) = mass of fission product slumped in time step
c                     (calculated in sr slmpdt)
c      ifpdp(19)  = index pointer to which fission products are being
c                   tracked in this calculation (from input, sr slphis)
c      nsptrk     = number of fission product species to track (input)
c      nstslp = indicator of whether material that slumped was
c               liquid or solid. 0=solid, 1=liquid.
c      ntpslp = number of time periods for user defined slumping
c                (nslphs=1)
c      ntstrk = total number of different species tracked for user
c                defined slumping, with 1 or more slumping periods
c      iksave = memory of slumping period for user defined slumping
c                (nslphs=1)
c
c      if material is solid, then it is quenched during slumping.
c
c      radslp = average radius of particles of th e material that
c               slumped. (m)
c      pfrtoc = multiplier for Couple power density in material 1.
c      porslp = porosity of material that slumped.
c      powslp = total heat generation in material that slumped during
c               current time step (w).
c      crucb  = indicator of whether crucible in core region resulting
c               from meltdown of fuel rods had ever breached its lower
c               boundary; 0.0=no, 1.0=yes.
c               if breach has occurred, then core material that melts
c               during time step will drip without blockage into lower
c               vessel region.
c               (This variable was made a REAL to facilitate printing)
c      timsls(nsqslp) = time at which the nsqslp-th unique slumping
c                       occurred. (s)
c      timsle(nsqslp) = end time (s).
c      tmsscm = time at which slumping into given couple mesh started.
c      tmescm = time at which slumping into given couple mesh ended.
c      enthdb(nsqslp) = total energy in material from nsqslp-th
c                       slumping. (j).
c      nsqslp = sequence number of unique slumpings. until first
c               slumping, nsqslp=0. then 1,2,3.....etc.
c               it is incremented by one each new unique slumping.
c      gamslp = volumetric vapor generation from slumping during
c               current time step. (kg/m**3.s)
c      wuoseq(nsqslp) = total mass of uo2 that will slump into lower
c                       vessel region due to nsqslp-th unique slumping.
c                       (kg).
c      etc.
c      wuoscm = mass of uo2 that is to slump into the couple mesh.
c      etc.
c      powseq(nsqslp) = total heat generation in material from
c                       nsqslp-th slumping. (w)
c      powscm = total heat generation in material slumped into
c               given couple mesh for the time step (w).
c       enrslp = thermal energy stored in material that currently
c                slumped. it is sum of thermal energy in masses
c                wuoslp through wagslp. (j)
c      nqcycl = switch on whether debris has ever failed to quench
c               because of lack of water in lower vessel region.
c               0=no, 1=yes.
c      qinslp = total heat transferred from debris that slumped into
c               lower vessel region into water in this region.
c      ncvol  = number of volume to receive any slumped core material.
c      inv    = index offset of data for volume ncvol.
c      thkcbr = thickness at which breach occurs in hardpan in
c               core region that supports liquefied core.
c      timcbr = period of time over which massive core slumping
c               is spread.
c      timqch = period of time over which small core slumpings
c               are spread.
c      aflwr1 = minimum flow area per fuel rod in cohesive debris
c               in core region.
c      hcslmp = heat transfer coefficient at top of debris in
c               lower plenum after massive slumping.
c      qinv   = energy transferred by radiation from bottom of hardpan
c               region to volume in lower plenum (w).
c      nctcno = number of Relap5 gen. table of power density in
c                  Couple material 1
c      nctcof = offset to Relap5 gen. table of power density in
c                  Couple material 1
c      nobrok = flag for no breakup of couple debris (1 = never broken)
c      nslump = indicator of whether any material slumped into the
c               couple mesh during this time step (0=no; 1=yes).
c      ncmesh = number of scdap core components that couple mesh
c               is connected with.
c      icmesh = identification numbers of the scdap components
c               that couple mesh is connected with.
c
c      njundb = flag indicating whether junctions will be opened or
c               closed as damage progresses (0=yes, 1=no).
c
c      fcntr1 = factor applied to a model for core damage junction
c               opening and closing (not yet implemented).
c
c      fcntr2 = factor applied to a model for core damage junction
c               opening and closing (not yet implemented).
c
c      ncntr1 = switch to provide user control of core slumping for
c               no metallic core meltdown (not yet implemented).
c
c      ncntr2 = switch to provide user control of core slumping for
c               no metallic core meltdown (not yet implemented).
