*mlist
*comdeck cpmdat
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: rjw.
c
*if def,selap
c
      integer maxcon, maxcpm, maxstp
      parameter (maxcon=11, maxcpm=1, maxstp=25)
c     maxcon = maximum number of constituents in couple material 1.
c     maxcpm = maximum number of couple meshes.
c     maxstp = maximum number of time periods for user defined
c              slumping (nslphs=1)
c
      common / cpmdat / mcp, mmcond, ncpmsh, nslph0, mcme73
      integer mcp, mmcond, ncpmsh, nslph0, mcme73
c
c     mcp    = index of current couple mesh.
c     mmcond = maximum mcond = space needed for couple conduction sol.
c     ncpmsh = number of couple meshes in problem.
c     nslph0 = number of the couple mesh with nslphs = 0 (0 if none).
c
*endif
