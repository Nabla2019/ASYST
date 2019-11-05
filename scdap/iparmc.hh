*mlist
*comdeck iparmc
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c    *** the following are pointers to the indicated arrays
c            within the large Couple a array -
c
c     i5     = properties for the nummat materials defined (8*nummat)
c     i6     = radii of nodes (numnp)
c     i7     = z coordiates of nodes (numnp)
c     i8     = i,j,k,l, and mtl for nodes (5*numel)
c     i9     = input angles beta; always 0.0 (numel)
c     i10    = flags for material in region (numel)
c     i20    = function controls (3*nfnt)
c     i21    = function tables (2*no. of tables)
c     i22    = initial temps. (numnp*amult)
c     i27    = power densities (W/m3) (numnp)
c     i28    = vol. heat generation rates (numnp)
c     i29    = tables for vol. heat gen. (numnp)
c     i40    = convection heat transfer node numbers (ncev)
c     i41    = convection heat transfer coeffs. or mults. (ncev)
c     i42    = convection heat transfer coeff. tables (ncev)
c     i43    = convection heat transfer temps. or mults. (ncev)
c     i44    = convection heat transfer temp. tables (ncev)
c     i45    = radiation heat transfer node numbers (nrad)
c     i46    = radiation heat transfer coeffs. or mults. (nrad)
c     i47    = radiation heat transfer coeff. tables (nrad)
c     i48    = radiation heat transfer temps. or mults. (nrad)
c     i49    = radiation heat transfer temp. tables (nrad)
c     i50    = radiation heat transfer surface areas (nrad)
c     i51    = convection heat transfer surface areas (ncev)
c     i60    = tempset node numbers (nttem)
c     i61    = constrained temps. or mults. (nttem)
c     i62    = constrained temp. tables (nttem)
c     i70    = porosities (numel)
c     i72    = particle diameters (numel)
c     i74    = zircaloy atomic fractions              (numel)
c     i76    = uranium atomic fractions               (numel)
c     i78    = stainless steel atomic fractions       (numel)
c     i80    = silver atomic fractions                (numel)
c     i82    = boron carbide atomic fractions         (numel)
c     i84    = uranium dioxide steel atomic fractions (numel)
c     i86    = zirconium dioxide atomic fractions     (numel)
c     i88    = indicator of material type in elem n   (numel)
c                0.0  = no material
c                0.05 = mixture of material
c                0.1  = mostly aluminum
c                0.2  = mostly B4C
c                0.3  = mostly silver
c                0.4  = mostly stainless steel
c                0.5  = mostly zr
c               >0.5  = mostly UO2 and ZrO2
c     i90    = power density of debris in elem n      (numel)
c     i99    = node point volumes (numnp)
c     i100   = element volumes (numel)
c     i102   = material volumes without pores (numel)
c     i103   = material volumes in elements (numel)
c     i104   = indicators for inital debris (0) (imtl)
c     i105   = indicators for debris in elements (numel)
c                 (0 = none, 1 = partly full, 2 = full)
c     i107   = power (4*numel)
c     i108   = debris volumes (4*numel)
c     i109   = densities * specific heats (4*numel)
c     i110   = energies (4*numel)
c     i111   = indicators for elements full of debris (numel)
c     i112   = temperatures for subr. etemp (not used) (numnp)
c     i113   = array for subr. etemp (not used) (4*numel)
c     i114   = array for subr. etemp (not used) (numnp)
c     i115   = array for subr. etemp (not used) (4*numel)
c     icompt = components to which couple nodes radiate (nrad)
c     idetop = top elements through which debris bed passes (maxi-1)
c     igmcpt = volumetric heat generations (ncev)
c     igmopt = past time step volumetric vapor generations (ncev)
c     ihtcto = total heat transfer coefficients (ncev)
c     inetco = offset to Relap5 general table of power density (numnp)
c     inodpt = numbers of couple mesh node that corresponds with
c                i-th node in convection set (ncev)
c     inussn = rayleigh number of molten debris element (numel)
c     ipafp  = amount of gas (aerosol) released from couple element
c                in time step (kg) (numel*max(1,nspdeb))
c     ipbfp  = mass of ith aerosol in kth bubble size at start/end
c                of time step (kg) for each element (allow for 15
c                bubble sizes) (numel*max(1,nspdeb)*15)
c     ipxfp  = mass of ith species vapor or non-condensible gas
c              in kth bubble size released from the volume element
c              during the time increment (max(1,nspdeb)*15)
c     ipfrto = multiplier for Relap5 general table power density (numnp)
c     iptalf = aluminum atomic fractions              (numel)
c     iptars = original values of areac array (ncev)
c     iptcdf = cadmium atomic fractions               (numel)
c     iptsif = soil atomic fractions                  (numel)
c     ipteij = element number corresponding with i,j coordinates
c                for lower left corner (maxj*maxi)
cljs
cljs  iptfml = fraction of element melted (numel)
cljs  iptfml = thickness of crust of frozen material (m)
c     iptfp  = total mass of ith aerosol at start/end of time step
c              for each element (kg) (numel*max(1,nspdeb))
c     iptfpv = offsets for identifying relap5 volume numbers adjacent
c              to convective nodes of debris bed for condensible
c              aerosols (add to fpsrc term) (ncevr5)
c     iptgav = offsets for identifying relap5 volume numbers adjacent
c              to convective nodes of debris bed for noncondensible
c              aerosols (add to gaman term) (ncevr5)
c     ipthfs = rate of release of heat of fusion (numel)
c     ipthtm = input specified h.t.c. for convective nodes
c                that model gap resistance (ncev)
c     iptiel = i coordinate of element n (numel)
c     iptihs = original values of ih array (ncev)
c     iptjel = j coordinate of element n (numel)
c     iptkfr = effective thermal conductivity, radial direction (numel)
c     iptkfz = effective thermal conductivity, axial direction (numel)
c     iptlif = lithium atomic fractions               (numel)
c     iptmdt = rate of melting, fraction/sec  (numel)
cljs         = now set to thickness of crust at start of time step (m)
c     iptmet = indicator whether convection to water or internal
c                liquefied debris  (ncev)
c     iptmlt = melting temperature of element (numel)
c     iptspd = inventory (kg) of each fission product species
c                for each element (numel*max(1,nspdeb))
c     iptspl = fission product species to be tracked (max(1,nspdeb))
c     ipttsm = sink temperature for convective corium heat
c                transfer (ncev)
c     iqcopt = total heat inputs to r5 volumes from
c                 i-th couple nodes in convection set (ncev)
c     iqfopt = past time step heat fluxes input to vapor (ncev)
c     iqolpt = past time step convection heat fluxes (ncev)
c     iqotpt = current convective heat fluxes (ncev)
c     iqwcpt = total heat inputs to vapor phase (ncev)
c     ir5pt  = relap5 vols. connected to couple convective nodes (ncev)
c     itsink = sink temperatures (ncev)
c     ivcnpt = relap5 volume offset indices for
c                 i-th convection nodes (ncev)
c     ivfspt = relap5 offset to fission product arrays (ncev)
c     ivrapt = relap5 offset for vols. connected to i-th nodes
c                 in radiation sets (nrad)
c     ivrdpt = relap5 volumes interfacing with couple
c                 nodes that radiate (nrad)
c     m1     = array used by fluid sol. (nftot)
c     m2     = array used by fluid sol. (nftot)
c     m3     = array used by fluid sol. (nftot)
c     m4     = array used by fluid sol. (nftot)
c     m5     = array used by fluid sol. (nftot)
c     m6     = array used by fluid sol. (nftot)
c     m7     = a(m2)*a(m6) (numnp)
c     m8     = array used by fluid sol. (numel)
c     m9     = array used by fluid sol. (numel)
c     m10    = array used by fluid sol. (2*numel)
c     m12    = array used by fluid sol. (4*numel)
c     m13    = array used by fluid sol. (numnp)
c     m14    = array used by fluid sol. (numnp)
c     m15    = array used by fluid sol. (numnp)
c     n1     = minimum j node numbers (maxi)
c     n2     = maximum j node numbers (maxi)
c     n3     = minimum i node numbers (maxj)
c     n4     = maximum i node numbers (maxj)
c     n5     = r values (nmax)
c     n6     = z values (nmax)
c     n7     = indicators for valid node at given i,j's (1=yes) (nmax)
c     n20    = indices of materials with no internal gen. (ngenm+1)
c     n100   = temperatures at last time step (numnp)
c     n101   = temperatures at current time step (numnp)
c     n102   = power (numnp)
c     n103   = power generating volumes assoc. with node points (numnp)
c     n132   = constrained temperatures (nttem)
c     n150   = constrained temperatures (nttem)
c   iptnbu=pointer to number of bubbles in each size range in each
c          element
c     iratpo = ratio of power density to average power density (this
c                is currently set to 1.0)          (numel)
c     iwalce = mass of aluminum in elements        (numel)
c     iwuoce = mass of uranium dioxide in elements (numel)
c     iwurce = mass of uranium in elements         (numel)
c     ipwxl2 = pointer, oxidized aluminum (kg/m2)
c     ipexlm = pointer, heat generation due to aluminum oxidation (w)
c     iph2lm = pointer, rate of hydrogen production due to aluminum
c              oxidation (kg/s)
c     ipoxth = pointer, aluminum oxidation thickness (m)
c     ilayer = matrix for user-defined layers of elements for
c              ATR configuration (25*25)
c     inelms = vector to keep track of the number of elements in
c              each layer in ilayer above (25)
c
c    *** end of couple a array pointers.
c
c     idf    = default values flag for skipping couple input (1 = yes)
c     idhint = flag to turn off convective heat transfer at nodes in
c              fluid field until material relocation (1 = yes)
c     iflagc = flag for use of convection heat trans. model (1 = yes)
c     iflagr = flag for use of radiation heat trans. model (1 = yes)
c     iflagt = flag for use of input tempsets
c     ifluid = flag for use of fluid solution model
c     iov    = fluid in/out boundaries
c     istep  = counter for number of times couple has been called
c     itran  = indiator if ave. element temp. is ok (1 = yes)
c     itx    = couple input error flag (1 = error)
c     ivsol  = fluid velocity solution flag
c     iupwnd = fluid upwind flag
c     last   = last used location in a array, + 1
c     lhead  = spherical lower head modeling flag (1 = yes; 0 = no)
c     line   = line counter for printout of couple input
c     matflu = material index of the coolant
c     maxe   = mesh plotting regions parameter
c     maxi   = maximum number of nodes in horizontal direction
c     maxj   = maximum number of nodes in vertical direction
c     mband  = couple bandwidth
c     mcond  = space needed for couple conduction solution
c     mld    = number of lower codiagonals in conduction equations
c     mnpo   = always 0
c     mpp    = mesh plotting parameter
c     mud    = number of upper codiagonals in conduction equations
c     ncev   = number of nodes in convective set * amult
c     ncevr5 = number of nodes in convective set
c     neltop = number of elements through which top of debris passes
c     nfnt   = total number of function tables
c     nftot  = numvt * amult
c     ngenm  = number of materials with no internal generation
c     niter  = number of iterations used for couple conduction sol.
c     nline  = input indicator for reading 2 cards (-1 = yes)
c     nmax   = maxi * maxj
c     nmtl   = number of material blocks
c     nnli   = maximum number of iterations in couple solution
c     npdtbi = number of Relap5 power density general tables -
c                 0 = none, 1 = 1, 2 = more than 1
c     npdtbo = offset to Relap5 power density general table if only 1
c     npp    = geometric code (0 =r,z; 1=x,y)
c     nrad   = number of nodes in radiation set * amult
c     nslph  = nslphs(mcp) from common / slumpv /
c     nspdeb = input number of fission product species to be
c                 tracked in debris bed
c     nttem  = number of tempsets * amult
c     numel  = number of elements in couple mesh
c     numhc  = number of nodes in convective set
c     nummat = number of different materials to be defined
c     numnp  = number of node points in couple mesh
c     numrc  = number of nodes in radiation sets
c     numtc  = number of nodes in tempsets
c     numvt  = fluid in/out nodes
c     nunqsw = indicator for doing unquench calculation (1 = yes)
c     ncpow  = indicator for type of power source -
c                    (same as ncpowi in /coupl/)
c     natrop = indicator for ATR configuration option
c     ncrlay = number of the current layer when using ATR config.
c     ncld   = switch to tune on/off natural convection in
c              liquified debris and modified conductance
c              ncld = 0, use modified K and natural convection
c              ncld = 1, turn off modified K (subroutine kpool)
c              ncld = 2, turn off modified K and nat convection
c                        model (subroutine dhcoef)
c
*endif
