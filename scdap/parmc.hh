*mlist
*comdeck parmc
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c     alhir  = inner radius of lower head in vessel
c     amult  = a multiplier for some storage space requirements;
c              set to 2.0 in subr. step.
c     atrhgt = height of debris used for ATR configuration, saved
c              in mupdat from one call to the next
c     cnpool = thermal conductivity of molten pool (w/m.k)
c     coni   = used in mesh generation; always 0.0
c     conj   = used in mesh generation; always 0.0
c     contr  = convergence parameter in couple numerical solution
c     depth  = depth of localized molten pool in debris bed for
c              use as characteristic length in rayleigh number
c     depthp = depth of plane(thickness) for case of plane geometry
c     dh     = thickness of lower head of vessel
c     dradin = inner radius of slumped material(axisymmetric geometry)
c                 or depth of plane(plane geometry)
c     dradis = outer radius of region in mesh that can fill with debris
c     dtcpl  = current couple time step
c     dtold  = last couple time step
c     emissm = emissivity for internal radiation in material with id 1.
c     ftempc = fixed input temperature for tempsets
c     hed1   = first couple title line
c     hed2   = second couple title line
c     height = height of debris bed, including dh
c     radc   = input radiation temperature
c     rlxn   = relaxation parameter in couple numerical solution
c     rlxo   = 1.0 - rlxn
c     rtemp  = input radiation reference temperature
c     seti   = used in mesh generation; always 0.0
c     setj   = used in mesh generation; always 0.0
c     sigf   = input radiation heat trans. coeff.
c     tempin = initial temperature of couple mesh
c     time   = problem time, same as timehy
c     rap    = rayleigh number for debris bed molten pool
c              (used for calculating transient natural convection
c     rass   = Rayleigh number used for steady state natural convection
c              heat transfer in molten pool.
c     tpool  = average temperature for debris bed molten pool (K).
c    tlqpol  = liquidus temperature of molten pool (K).
c     tvol   = total volume of debris
c     uncon  = multiplier for dimensions that are input
c      zpbot = bottom elevation of molten pool (m)
c      zptop = top elevation of molten pool (zpbot + depth) (m)
c
*endif
