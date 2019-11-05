*mlist
c
c  Descriptive sentence for slpcom goes here.
c
c  Cognizant engineer: rjw.
c
c  Common block slpcom does not need to be written to restart file.
       common /slpcom/ wuoslc(ndcomp),wurslc(ndcomp),wzrslc(ndcomp),
     # wzoslc(ndcomp),wbcslc(ndcomp),wssslc(ndcomp),wagslc(ndcomp),
     # wcdslc(ndcomp),wlislc(ndcomp),engslc(ndcomp),powslc(ndcomp),
     # walslc(ndcomp)
c
      real wuoslc, wurslc, wzrslc, wzoslc, wbcslc, wssslc, wagslc,
     1     wcdslc, wlislc, engslc, powslc, walslc
c
c   wuoslc(j)=mass of uo2 that has slumped below bottom of component j
c             during current time step (kg).
c   wurslc(j)=metallic u.
c   wzrslc(j)=zr.
c   wzoslc(j)=zro2.
c   wbcslc(j)=b4c
c   wssslc(j)=stainless steel
c   wagslc(j)=silver.
c   wcdslc(j)=cadmium.
c   wlislc(j)=lithium.
c   walslc(ndcomp)=aluminum.
c   engslc(j)=internal energy in material that has slumped below
c             j-th component during current time step (joules).
c   powslc(j)=heat generation in material that slumped from j-th
c             component during current time step (w).
