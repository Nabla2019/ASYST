*mlist
*comdeck oxsrv2
c
c
c  Descriptive sentence goes here.
c  Variables for oxidation of second surface (outside surface) of
c  shroud component stored in this common block.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c
c  variables used in modeling oxidation of second surface of shroud.  
       common /oxsrv2/ oxdeot(ndax,ndcomp),oxdwct(ndax,ndcomp),                
     & alfaot(ndax,ndcomp),oxdhct(ndax,ndcomp),
     & xnalft(ndax,ndcomp),xnoxdt(ndax,ndcomp),
     & oxdwctz(ndax,ndcomp),wtgnmx2(ndax,ndcomp),froxpl2(ndax,ndcomp),
     & xmetin(ndax,ndcomp),sroxd2(ndax,ndcomp),h2oxsho(ndax,ndcomp),
     & effshz2(ndax,ndcomp),effsh2(ndax,ndcomp),thkstm2(ndax,ndcomp),
     & oxdeotz(ndax,ndcomp),xnalftz(ndax,ndcomp),xnoxdtz(ndax,ndcomp),
     & stmlmt2(ndax,ndcomp),diflmt2(ndax,ndcomp),flstm2(ndax,ndcomp),
     & effoxdo(ndcomp,ndax),nolmto(ndax,ndcomp),rcoi2sh(ndax,ndcomp),
     & rco2sh(ndax,ndcomp),rcoish(ndax,ndcomp),rci2sh(ndax,ndcomp),
     & rnoxdsh(ndax,ndcomp),rnalfsh(ndax,ndcomp),
     & rnoxdshz(ndax,ndcomp),rnalfshz(ndax,ndcomp),
     & noxidet(ndax,ndcomp),noxidetz(ndax,ndcomp),
     & nsurox(ndcomp),
     & mcme109
c  define type for variables involved in oxidation of second surface
c  of component
      real oxdeot,oxdwct,alfaot,oxdhct,xnalft,xnoxdt,
     & oxdwctz,wtgnmx2,froxpl2,xmetin,sroxd2,h2oxsho,effshz2,
     & effsh2,thkstm2,oxdeotz,xnalftz,xnoxdtz,stmlmt2,diflmt2,
     & flstm2,effoxdo,nolmto,rcoi2sh,rco2sh,rcoish,rci2sh,
     & rnoxdsh,rnalfsh,rnoxdshz,rnalfshz
      integer nsurox,noxidet,noxidetz,      
     & mcme109
cljs *** need to define mcme109
c   variables involved in oxidation of second surface of shroud
c   in variable definitions below, k = axial node, j = component number
c   oxdeotk,j) = thickness of oxide of second surface of shroud
c                component with number j at axial node k (m)
c   oxdeotz(k,j) = same as oxdeot(k,j) but start of time step value (m)
c   oxdwct(k,j) = weight gain of Zircaloy in outside surface of
c                 shroud for axial node k of component j (kg/m2)
c   oxdwctz(k,j) = same as oxdwct(k,j) but for start of time step
c   alfaot(k,j) = alpha thickness at outer surface of shroud (m)
c   oxdhct(k,j) = heat generation due to oxidation at outer surface
c                 (W/m)
c   xnalft(k,j) = inner radius of alfa layer (m)
c   xnoxdt(k,j) = inner radius of oxide layer (m)
c   rnoxdsh(k,j) = inner radius of oxide layer modeled as if at
c                 maximum radial node so as to be compatible with
c                 subroutine oxidiz (m)
c   rnalfsh(k,j) = inner radius of alpha layer as if at maximum radial
c                 node
c   rci2sh(k,j) = inner radial coordinate for metallic layer on
c                 outer surface of shroud (radial node 1) (m)
c   xinsho(k,j) = as-fabricated inner radius of metallic layer on
c                 outside surface of shroud (m)
c   oxdwctz(k,j) = oxide weight gain at start of previous time step
c                  (kg/m2)
c   wtgnmx2(k,j) = weight gain for complete oxidation of outer metallic
c                  surface (kg/m2)
c   froxpl2(k,j) = fraction oxidation of outer metallic layer
c   xmetin(k,j) = x-coordinate of inside surface of metallic layer
c                 on outside surface of shroud (m)
c                 xmetin(k,j) is referenced in local coordinate system
c                 wherein x = 0.0 = outside surface of shroud 
c   sroxd2(k,j) = steam consumed by oxidation of outside surface of
c                 shroud (kg/s)
c   h2oxsho(k,j) = hydrogen produced due to oxidation at outside
c                  surface of shroud (kg/s) 
c   effshz2(k,j)  = oxide weight gain since last shattering (kg/m2)
c                   (start of time step value)
c                  shroud assumed to never shatter, so
c                  effsh2(k,j) = oxdwct(k,j)
c   effsh2(k,j)  = same as effshz2(k,j) but end of time step value
c   thkstm2(k,j) = thickness of oxide layer on oxide surface of shroud
c                  due to oxidation in steam (m)
c   stmlmt2(k,j) = steam flow rate at axial node k of component j
c                  (kg/m2.s)
c   diflmt2(k,j) = diffusion limit on steam for oxidation of outside
c                  surface (radial node 1) of shroud (kg/m2.s)
c   flstm2(k,j)  = steam flow rate (kg/s)
c   noxidet(k,j) = index indicating state of oxidation of metallaic
c                  layer; 0 = incomplete oxidation, 1 = completely
c                  oxidized.
c   nsurox(k,j) = index indicating whether outside surface of shroud
c                 has Zircaly cladding; 0 = no, 1 = yes.
*endif
