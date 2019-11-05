*mlist
*comdeck scdoutc
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc.
c
c  variable name  units  definition
c  _____________  _____  _______________________________________________
c  bgmct          K      Bundle maximum cladding temperature.
c  bgmat          K      Bundle maximum radially averaged temperature.
c  tcorav         K      Core averaged temperature.
c  dzcnd2(k,j)    m      length of axial node k of component j.
c  h2oxd2(k,j)    kg/s   rate of hydrogen production at axial node k of
c                        component j.
c  sroxd(kd)      kg/s   rate of steam removal at axial node m of
c                      component j  (kd defined same as for h2oxd
c  tcond3(i,k,j) K     temperature at radial node i of axial node k
c                      of component j.
c                      Note: Radial Node 1 corresponds with Lumped Mass
c                      No. 1, which represents the B4C and B2O3 parts of
c                      the control blade.  Radial Node 2 represents
c                      Lumped Mass No. 2, which represents the stainless
c                      steel and FeO part of the control blade.
c  zcond2(k,j)    m      height of center of axial node k above bottom
c                        of component j.
c                      Note: This should really be an array with one index
c                      since the radiation heat transfer model now requires
c                      that each axial node must have same height for
c                      all components. 
