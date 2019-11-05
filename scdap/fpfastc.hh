*mlist
*comdeck fpfastc
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
c ***
c  Fission Product Fixed data block
c     fpinpo - offset to fission product input data
c     fpactv - fission product transport active flag
c     fpdbgr - fission product debug flag
c     fpnsys - number of fission product systems
c     fpsyso - offset to first fission product system
c     fpnbin - number of aerosol bins modeled
c     fpnsp - number of species tracked
c     fpsysk - fission product system data skip factor
c     fpvolk - fission product volume data skip factor
c     fpsrfk - fission product surface data skip factor
c     fpspvk - fission product species skip factor within volume data
c     fpspsk - fission product species skip factor within surface data
c     fprtol - relative convergence criteria
c     fpatol - absolute convergence criteria
c     fpsp - species names which are tracked
c ***
c     fpsysn - hydrodynamic system number (ordinal) of fp system
c     fpnvol - number of volumes in fission product system
c     fpvolo - offset to first volume in fission product system
c     fpsysm - species mass in system
c ***
c  Fission Product Volume data block.
c     fpvoln - hydrodynamic volume number of fission product volume
c     fpnsrf - number of surfaces in fission product volume
c     fpsrfo - offset to first surface in fission product volume
c     fpstep - last successful time step
c     fpsrc - species source rate in volume
c     fpvtm - species total mass in volume
c     fpstm - species total mass on all surfaces in volume
c     fpliq - species liquid mass in volume
c     fpvap - species vapor mass in volume
c     fpbin - species aerosol bin mass (each bin) in volume
c ***
c  Fission Product Surface data block.
c     fpsrfn - hydrodynamic surface number of fission product surface
c     fpsflr - left or right side volume indicator
c     fpsfmt - surface material type
c     fpsfto - offset to surface temperature data
c     fpsfar - surface area
c     fpsfan - surface angle
c     fpsfra - relative surface area
c     fpsfbs - decay heat due to beta on surface
c     fpsfgs - decay heat due to gamma on surface
c     fpsfbv - decay heat due to beta in volume (as a fraction of the
c              gamma decay heat)
c     fpsfmc - species condensate on surface
c     fpsfma - species absorbate on surface
c     fpsfmp - species precipitate on surface
