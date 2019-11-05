*mlist
*comdeck conele
c
c  
c
c  Variables for a B4C control rod
c  
c
*if def,selap
c 
       real cwb4c, cwb2o3, cwb,cwc,wrbszi,wrbszo,wsscon
       integer  b4cox, gtox,oxinblo,nrcrm2,mcme110
       real oxdwci0,rnoxdi0,rnalfi0,oxdwci2,rnoxdi,rnalfi,wfrosri,
     & oxdso,dhmsszr,cooxd2,co2oxd2,ch4oxd2,cumco,cumco2,
     & cumch4,ratco,ratco2,ratch4,wb4ctot,wh2b4c,
     & h2oxb4c,b4cgs,gasflux,oxdhss,oxdhab,rosab,rabcn0,rabcn1,
     & cartot,rsscni1,rsscni0,wfroabi,surirat,reazs
       common /conele/  cwb4c(ndax,ndcomp),cwb2o3(ndax,ndcomp),
     &   cwb(ndax,ndcomp),cwc(ndax,ndcomp),wrbszi(ndax,ndcomp,12),
     &   wrbszo(ndax,ndcomp,12),wsscon(ndax,ndcomp,8),
     &   b4cox(ndax,ndcomp),gtox(ndax,ndcomp),oxinblo(ndax,ndcomp),
     &   surirat(ndax,ndcomp),reazs(ndax,ndcomp),nrcrm2(ndax,ndcomp)
       common /conele/ oxdwci0(ndax),rnoxdi0(ndax),rnalfi0(ndax),
     &  rnoxdi(ndax*ndcomp),rnalfi(ndax*ndcomp),
     &  wfrosri(ndax*ndcomp),oxdso(ndax*ndcomp),
     &  dhmsszr(ndax,ndcomp),oxdwci2(ndax,ndcomp), 
     &  cooxd2(ndax,ndcomp),co2oxd2(ndax,ndcomp),ch4oxd2(ndax,ndcomp),
     &  cumco(ndcomp),cumco2(ndcomp),cumch4(ndcomp),cartot(ndcomp),
     &  ratco(ndcomp),ratco2(ndcomp),ratch4(ndcomp),wb4ctot(ndcomp),
     &  wh2b4c(ndcomp),h2oxb4c(ndax,ndcomp),b4cgs(ndax,ndcomp,6),
     &  gasflux(ndax,ndcomp,9),oxdhss(ndax,ndcomp),oxdhab(ndax,ndcomp),
     &  rosab(ndax*ndcomp),rabcn0(ndax,ndcomp),rabcn1(ndax,ndcomp),
     &  rsscni1(ndax,ndcomp),rsscni0(ndax,ndcomp),wfroabi(ndax*ndcomp),
     &  mcme110
c
c
c  Where:
c    i = Axial node index
c    j = component number
c
c  Mass array            Definition
c  cwb4c(i,j)           mass of b4c in absorber rod
c  cwb2o3(i,j)         mass of b2o3 in absorber rod
c  these following two variables are no more used
c  cwb(i,j)               mass of b in absorber rod
c  cwc(i,j)               mass of c in absorber rod
c
c  wrbszi,wbszo(i,j,1-12)  mass of mixture of zr/ss/b4c
c  inside or outside of the guide tube
c                1           Fe in unreacted portion
c                2           Cr
c                3           Ni
c                4           FeO in oxide layer
c                5           Fe3O4
c                6           Cr2O3
c                7           NiO
c                8           Fe in oxide layer
c                9           Zr
c              10           ZrO2
c              11           B4C
c              12           B2O3
c
c
c  wsscon (i,  j,1-8)  SS consituents in absorber sheath
c                1           Fe in unreacted portion
c                2           Cr
c                3           Ni
c                4           FeO in oxide layer
c                5           Fe3O4
c                6           Cr2O3
c                7           NiO
c                8           Fe in oxide layer
c
c   b4cgs(i,j,1-5)    Generated gas by B4C oxidation
c
c                1           CO
c                2           CH4
c                3           CO2
c                4           B2O3 (g)
c                5           HBO2
c                
c               
c
c     b4cox(i,j)    0: B4c oxidation is not allowed
c                         1 :yes  2: Absorber is Relocated
c     oxinblo(i,j) flow blockage at inside of GT
c                        0: No  1: Yes
c     gtox(i,j)      possibility of guide tube oxidaion
c                        0: yes  1:No (ALL oxide layer)
c     roxss           inner radius of oxide SS layer (m)
c     oxdwci0      weight gain of Zr at inner side of GT (kg)
c     rnoxdi         radius of outer oxide layer of inner side of GT (m)
c     rnalfi           radius of alpha layer of inner side of GT (m)
c     wfrosri        mass of frozen SS at inner side of GT  (kg)
c     wfroabi       mass of absorber material at inner side of GT  (kg)
c     oxdso(i,j)         thickness of oxide layer of absorber sheath (m)
c     dhmsszr(i,j)     mixing heat of Zircaloy and Stainless steel (J)
c     cooxd2(i,j)       CO generation rate at ith axial node(kg/s)
c     co2oxd2(i,j)     CO2 generation rate at ith axial node(kg/s)
c     ch4xd2(i,j)       CH4 generation rate at ith axial node(kg/s)
c     ratco(j)          CO generation rate at jth component(mole/s)
c     ratco2(j)        CO2 generation rate at jth component(mole/s)
c     ratch4(j)        CH4 generation rate at jth component(mole/s)
c     cumco(j)        Total CO generation at jth component(mole)
c     cumco2(j)      Total CO2 generation at jth component(mole)
c     cumch4(j)      Total CH$ generation at jth component(mole)
c     wb4ctot(j)      Total mass of unrelocated B4C in the component (kg)
c     h2oxb4c(i,j)   Hydrogen production rate from B4C and SS (kg/s)
c     wh2b4c(j)      Total hydrogen production rate from B4C and SS (kg/s)
c     oxdhss(i,j)      Heat generation from absorber sheath (W/m)
c     oxdhab(i,j)     Heat generation from absorber material (W/m)
c     rabcn0(1) (i,j)   Radius of absorber material (m)
c     rsscni0(1) (i,j)   Thickness of liquefied inner side of absorber sheath (m)
c     surirat (i,j)     Ratio of flow pass cross-section inside of guide tube
c     nrcrm2(i,j)       Radial node number at the surface of absorber material


*endif
