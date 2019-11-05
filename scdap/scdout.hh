*mlist
*if def,selap
c
c  Descriptive sentence for scdout goes here.
c
c  Cognizant engineer: ewc.
c
       common /scdout/ dzcond(ndax*ndcomp),tcond(ndax*ndrd*ndcomp),
     * zcond(ndax*ndcomp),zgrid(ndgrid,ndcomp),pitch(ndcomp),
     * rocrst(ndax*ndcomp),
     * bgth,bgnhg,bgmct,bgtfrs,bgtfrn,bgmat,tcorav,
     & bgmcth,tmaxhs,
     # shqin,shqout,bgthq,
     * dkgrel(ndcomp),dksrel(ndcomp),ggrel(18,ndcomp),ggrelh(ndcomp),
     * ggrelr(ndcomp),gsrelh(ndcomp),h2oxd(ndax*ndcomp),
     * hadd(ndax*ndcomp),sroxd(ndax*ndcomp),gsrelr(ndcomp),
     * rci(ndax*ndcomp),rl(ndcomp),slbwd(ndcomp),
     * flstm0(2*ndax*ndcomp),flwh20(2*ndax*ndcomp),
     * tsur1(2*ndax*ndcomp),haddod(ndax,ndcomp),
     * powadd(ndax,ndcomp),haddnw(ndax,ndcomp),
cljs add
     & frdkvl(ndax,ndcomp),frdknv(ndax,ndcomp),frdkpw(ndax,ndcomp),
     & fgstot0(ndax,ndcomp),fgstot(ndax,ndcomp),
     & effgn1(ndrd,ndcomp),effk1(ndrd,ndcomp),effcp1(ndrd,ndcomp),
     & timrubs,timliqs,tmprubs,tmpliqs,
     * igrdsp(ndax,ndcomp),kfail1(ndax,ndcomp),kfail2(ndax,ndcomp),
     # ii(ndcomp),imaxtp,jmaxtp,jshq,jmaxhs,kmaxhs,        
     & kaxrubs,jcprubs,kaxliqs,jcpliqs,mcme63
      integer igrdsp
       integer kfail1,kfail2
       real dzcond,tcond,zcond,zgrid,pitch,rocrst,bgth,bgnhg,bgmct,
     * bgtfrs,bgtfrn,shqin,shqout,bgthq,dkgrel,dksrel,ggrel,ggrelh,
     * ggrelr,gsrelh,h2oxd,hadd,sroxd,gsrelr,rci,rl,slbwd,
     * flstm0,flwh20,tsur1,haddod,powadd,haddnw,bgmat,tcorav
       real effgn1,effk1,effcp1
cljs
       real frdkvl,frdknv,fgstot0,fgstot,frdkpw
       integer ii,imaxtp,jmaxtp,jshq,mcme63
       real bgmcth,tmaxhs
       integer jmaxhs,kmaxhs
       real timrubs,timliqs,tmprubs,tmpliqs
       integer kaxrubs,jcprubs,kaxliqs,jcpliqs
c      haddnw(k,j)=thermal energy added to axial node k of component
c              j by material relocation during current time step (j).
c      haddod(k,j)=thermal energy added during previous time step (j).
c      powadd(k,j)=additional nuclear heat added to axial node k of
cljs
c      frdkvl(k,j)=fractional reduction in decay power due to release
c                  of volatile fission products, k=axial node, j=comp.
c                  number
c      frdknv(k,j)=fraction of decay power due to non-volatile fission
c                  products at axial node k for component j.
c      frdkpw(k,j) = fractional reduction decay heat due to release
c                    of volatile fission products, axial node k,
c                    component j
c      fgstot0(k,j) = initial inventory of volatile fission gases at   
c                     axial node k of component j (kg)
c      fgstot(k,j) = current inventory of volatile fission gases at
c                    axial node k of component j (kg).
c      effgn1(m,j) = volumetric heat generation rate at m-th radial mesh
c                    and mid-plane axial node of component j (W/m3)
c      effk1(m,j)  = thermal conductivity at m-th radial mesh and
c                    mid-plane axial node of compoent j (W/m.k)
c      effcp1(m,j) = volumetric heat capacity m-th radial mesh and
c                     mid-plane axial node of component j (J/m3.K)
c                  component j by fuel slumping into node (w).
c      timrubs = time of first location in core degrading to rubble
c                debris (s)
c      timliqs = time of first location in core degrading to liquefied
c                molten pool (s)
c      tmprubs = temperature at time first location became rubble (K)
c      tmpliqs = temperature at time first location became liquid (K)
c      kaxrubs = axial node of first location becoming rubble
c      jcprubs = component number of first location becoming rubble
c      kaxliqs = axial node of first location becoming liquid
c      jcpliqs = component number of first location becoming liquid
c      jshq       = index of shroud with largest perimeter.
c      igrdsp(k,j)= indicator of grid spacer at axial node k of
c                   component j
c                   0 = no grid spacer
c                   1 = intact grid spacer at this node
c                   2 = grid spacer has melted this time step
c                   3 = grid spacer has slumped away
c      kfail1(k,j)=indication that oxide shell has breached at some
c                  point at axial node k of component j; 0=no, 1=yes.
c      kfail2(i,j)=same as kfail1 but for start of time step.
c      bgmcth = maximum historical temperature (K)
c      tmaxhs = time of maximun historical temperature (s)
c      jmaxhs = component number with maximum temperature
c      kmaxhs = axial node with maximum temperature
       real tcond3(ndrd,ndax,ndcomp)
       real h2oxd2(ndax,ndcomp)
       equivalence (tcond3(1,1,1),tcond(1))
       equivalence (h2oxd2(1,1),h2oxd(1))
       real rci2(ndax,ndcomp),rcrst2(ndax,ndcomp)
       equivalence (rci2(1,1),rci(1))
       equivalence (rcrst2(1,1),rocrst(1))
       real dzcnd2(ndax,ndcomp),zcond2(ndax,ndcomp)
       equivalence (dzcnd2(1,1) ,dzcond(1))
       equivalence (zcond2(1,1),zcond(1))
       real tsur2(2*ndax,ndcomp)
       equivalence (tsur2(1,1),tsur1(1))
       real flstm02(2*ndax,ndcomp)
       equivalence (flstm02(1,1),flstm0(1))
*endif
