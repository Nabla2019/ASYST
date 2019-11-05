*mlist
c
c  Descriptive sentence for scdcom goes here.
c
c  Cognizant engineer: ewc.
c
c  Modified by H.Madokoro
c  Added rpeli
c	
*if def,selap
       common /scdcom/ acrst(ndax*ndcomp),actnid(ndcomp),
     & afuel(ndax*ndcomp),enrch(ndcomp),fulden(ndcomp),pgas(ndcomp),
     # trbun(ndcomp),trbunz(ndcomp),gs1bn(ndcomp),gs1bnz(ndcomp),
     # gs2bn(ndcomp),gs2bnz(ndcomp),gs3bn(ndcomp),gs3bnz(ndcomp),
     # gs4bn(ndcomp),gs4bnz(ndcomp),gs5bn(ndcomp),gs5bnz(ndcomp),
     # gs6bn(ndcomp),gs6bnz(ndcomp),
     & pllnth(ndcomp),qclad(ndax*ndcomp),qmat(ndmatr*ndax,ndcomp),
     & radmat((ndmatr+1)*ndax,ndcomp),rcii(ndcomp),rco(ndax*ndcomp),
     & rcoi(ndax*ndcomp),rdlnth(ndcomp),rpel(ndax*ndcomp),rcos(ndcomp),
c  hm begin
     & rpeli(ndax*ndcomp),	
c  hm end	
     & tclad(ndcomp),tcond0(ndax*ndrd*ndcomp),teff(ndax*ndcomp),
     & tfuel(ndcomp),vfvod(ndax*ndcomp),vfvodi(ndax*ndcomp),
     & vplen(ndcomp),vlplen(ndcomp),vpleni(ndcomp),wuobng(ndax*ndcomp),
     & wzobng(ndax*ndcomp),wzrbng(ndax*ndcomp),xcond(ndax*ndrd*ndcomp),
     & xcond0(ndax*ndrd*ndcomp),riss(ndax*ndcomp),rissi(ndcomp),
     & rossi(ndcomp),vfueli(ndcomp),wabbng(ndax,ndcomp),
     & wsrbng(ndax*ndcomp),fpivyi(ndcomp),unuca(ndax,ndcomp),
     & unucda(ndax,ndcomp),debent(ndax,ndcomp),debqen(ndax,ndcomp),
     & debtpi(ndax,ndcomp),voidfu(ndax*ndcomp),burnup(ndax*ndcomp),
     & acond(ndax*ndcomp),fcfulk(ndax*ndcomp), unucgm(ndax,ndcomp),
     & gdfrac(ndax,ndcomp),b4cthk(ndax,ndcomp),uo2den(ndax,ndcomp)
       common /scdcom/ uo2enr(ndax,ndcomp),thkgp2(ndax,ndcomp),
     & htcgap(ndax,ndcomp),kgpshi(ndax,ndcomp),ishgpi(ndax,ndcomp),
     & ishgpo(ndax,ndcomp),mshmt3(ndrd,ndax,ndcomp),
     & imater(ndmatr*ndax,ndcomp),nsimot(ndax,ndcomp),
     & iphase(ndax*ndcomp),ngeom(ndcomp),nmater(ndax*ndcomp),
     & nrcldi(ndax*ndcomp),numelm(ndax*ndcomp),icladf(ndcomp),
     & ncrust(ndcomp),ibrchz(ndcomp),igrdp0(ndax,ndcomp),modidx(10),
     & mcme61
        real acrst,actnid,afuel,enrch,fulden,pgas,pllnth,qclad,qmat,
     * radmat,rcii,rco,rcoi,rdlnth,rpel,rcos,tclad,tcond0,teff,tfuel,
     * vfvod,vfvodi,vplen,vlplen,vpleni,wuobng,wzobng,wzrbng,xcond,
     # xcond0,riss,rissi,rossi,vfueli,wabbng,wsrbng,fpivyi,unuca,
     # unucda,debent,debqen,debtpi,voidfu,burnup,acond,fcfulk,
     # unucgm,gdfrac,b4cthk,uo2den,uo2enr,thkgp2,htcgap,kgpshi,
     # rpeli
       real trbun,trbunz
       real gs1bn,gs1bnz,gs2bn,gs2bnz,gs3bn,gs3bnz,gs4bn,gs4bnz,
     # gs5bn,gs5bnz,gs6bn,gs6bnz
       integer imater,iphase,ngeom,nmater,nrcldi,numelm,icladf,ncrust,
     * ibrchz,igrdp0,ishgpi,ishgpo,mshmt3,nsimot,modidx,mcme61
c
       real radmt3((ndmatr+1),ndax,ndcomp)
       equivalence (radmt3(1,1,1), radmat(1,1))
       integer imatr3(ndmatr,ndax,ndcomp)
       equivalence (imatr3(1,1,1), imater(1,1))
       integer nrcldi2(ndax,ndcomp)
       equivalence (nrcldi2(1,1),nrcldi(1))
       real fcfulk2(ndax,ndcomp)
       equivalence (fcfulk2(1,1),fcfulk(1))
       real burnup2(ndax,ndcomp)
       equivalence(burnup(1),burnup2(1,1))
       integer nmater2(ndax,ndcomp)
       equivalence(nmater2(1,1),nmater(1))
       integer numelm2(ndax,ndcomp)
       equivalence(numelm2(1,1),numelm(1))
       real vfvodi2(ndax,ndcomp)
       equivalence(vfvodi2(1,1),vfvodi(1))
       real vfvod2(ndax,ndcomp)
       equivalence(vfvod2(1,1),vfvod(1))
       real afuel2(ndax,ndcomp)
       equivalence(afuel2(1,1),afuel(1))
       real wsrbng2(ndax,ndcomp)
       equivalence(wsrbng2(1,1),wsrbng(1))
       real wzrbng2(ndax,ndcomp)
       equivalence(wzrbng2(1,1),wzrbng(1))
       real wzobng2(ndax,ndcomp)
       equivalence(wzobng2(1,1),wzobng(1))
       real wuobng2(ndax,ndcomp)
       equivalence(wuobng2(1,1),wuobng(1))
       real qclad2(ndax,ndcomp)
       equivalence(qclad2(1,1),qclad(1))
       real riss2(ndax,ndcomp)
       equivalence (riss2(1,1),riss(1))
       real teff2(ndax,ndcomp)
       equivalence (teff2(1,1),teff(1))
       real tcnd03(ndrd,ndax,ndcomp)
       equivalence (tcnd03(1,1,1),tcond0(1))
       real xcond3(ndrd,ndax,ndcomp)
       equivalence (xcond3(1,1,1),xcond(1))
       real acond2(ndax,ndcomp)
       equivalence(acond2(1,1),acond(1))
       real rco2(ndax,ndcomp),rpel2(ndax,ndcomp)
       real qmat3(ndmatr,ndax,ndcomp),rcoi2(ndax,ndcomp)
       equivalence (rco2(1,1),rco(1))
       equivalence (rpel2(1,1),rpel(1))
       equivalence (rcoi2(1,1),rcoi(1))
       equivalence (qmat3(1,1,1),qmat(1,1))
c  hm begin
       real rpeli2(ndax,ndcomp)
       equivalence (rpeli2(1,1),rpeli(1))
c  hm end	
c
c     unuca(k,j) = linear nuclear heat generation at axial node k of
c                  component j (w/m).
c      unucda(k,j) = nuclear heat generation if all volatile fission
c                    products removed instantly (w/m).
c      debent(k,j)=stored thermal energy of debris at start of
c                  quenching for axial node k of component j (j).
c      debqen(k,j)=accumulated amount of stored energy removed from
c                  axial node k of component j by quenching (j).
c      debtpi(k,j)=temperature of debris at axial node k of component
c                  j at start of quenching (k).
c      voidfu(k,j)=relative void volume of fuel at axial node k of
c                  component j.  If unchanged from as-fabricated volume,
c                  then voidfu(k,j)=1.
c      burnup(k,j)=amount of fuel burnup at axial node k of component j
c                  (mw-s/kg u)
c      acond(k,j) =burnup-dependent correction factor for fuel thermal
c                  conductivity at axial node k of component j.
c      unucgm(k,j)=gamma heat generation deposited directly into coolant
c                  at axial node k of component j. (w/m)
c      gdfrac(k,j)=fraction of Gd mass per UO2 mass at axial node k of
c                  component j.
c      b4cthk(k,j)=thickness of layer of B4C on surface of pellet at
c                  axial node k of component j.
c      uo2den(k,j)=density of UO2 as fraction of theoretical density at
c                  axial node k of component j.
c      uo3enr(k,j)=percent enrichment of UO2 at axial node k of
c                  component j.
c      thkgp2(k,j)=thickness of fuel-cladding gap for fuel with no
c                  relocation (m)
c      htcgap(k,j)=gap conductance of fuel-cladding gap for fuel with
c                  no relocation (W/m2.K)
c      kgpshi(k,j)=effective thermal conductivity of inner most mesh
c                  in void region in shroud (W/m.K)
c      ishgpi(k,j)=inner most radial mesh number overlaying void in
c                  shroud component
c      ishgpo(k,j)=outer most radial mesh number overlaying void in
c                  shroud component
c      mshmt3(n,k,j)=material index of n-th radial mesh of k-th axial node
c                    of icomp-th component
c      nsimot(k,j) = outer most mesh with heater element material for
c                    simulator rods.
c      modidx(n) = index controlling application of up to ten different
c                  models; modidx(n)=1=model applied, otherwise not.
c                  modidx(1) = model for gap conductance in fuel rods 
c                              with fuel that does not relocate and
c                              for simulator rods
c                  modidx(2) = model for radiation heat transfer across
c                              gaps in shroud
c                  modidx(3) = correction on thermal expansion of heat
c                              element in simulator rods
c
c  nrcldi(kc)    -     radial node number on inside surface of cladding
c                      for component j at axial node k.
c        iphase         flag indicating that material out of array
c                       imater which is melting (negative) or freezing
c                         (positive)
c                       iphase=0: no phase-change problem
c        ngeom          geometry index for heat conduction
c        nmater         number of material layers between component
c                         center and component surface
c        imatr3         indicators of materials for nmater material
c                         layers in radial direction - equivalent to
c                         imater
c        numelm         number of elements for heat conduction solution
c        qmat3          average linear heat generations in nmater
c                       material layers ( w/m )
c        radmt3         radii of material layers ( m ) radmt3(1):
c                       component center, radmt3(nmater+1):
c                       component surface - equivalent to radmat
*endif
