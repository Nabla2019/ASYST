*mlist
*comdeck trnot1c
c
c
c  Cognizant engineer:
c
c  variable name  units  definition
c  _____________  _____  _______________________________________________
c  ishrd(i)     -     number of component that encloses i-th radiation
c                      enclosure.
c  tcols(ke)     K     sink temperature for convective heat transfer at
c                      outer surface (surface at location of radial node
c                      1) for axial node k of component j.
c                      The index ke is calculated by the equation:
c                      ke = (nsout(j)-1)*ndax + k.
c                      Note: in BWR control blade model in subroutine
c                      bwhtcn, the sink temperature corresponding with
c                      hfixf (convective h.t.c. for liquid phase) is the
c                      liquid temperature tempf(iv), where iv is index
c                      for RELAP5 volume interfacing location at which
c                      convective heat transfer is being calculated.
c                      (varibale tempf(iv) is defined more fully below.)
c                      Similarly, the sink temperaure corresponding with
c                      hfixg is tempg(iv).
