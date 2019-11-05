*mlist
c
c  Cognizant engineer:
c
c  the following variables needed to define boundary conditions:
c
c--------input b.c. for cart geometry
c
c--------lixw = #     : x-axis left
c--------lixe = #     : x-axis right
c--------liys = #     : y-axis top
c--------liyn = #     : y-axis bottom
c--------input b.c. for hexa & cart geometries
c
c--------lizu = #     : z-axis up
c--------lizd = #     : z-axis down
c
c
c---the values of # can be one of four choices:
c
c   # = 0  : zero current (reflective)
c   # = 1  : zero flux
c   # = 2  : non-reentrant current
c   # = 3  : cyclic (rotational)
c   # = 4  : not applicable
c
c
c  the following variables needed to define boundary conditions:
c--------input b.c. for hex geometry
c
c--------liho = #     : exterior b.c.
c--------lips = #     : interior b.c.
c
c---the values of # can be one of four choices:
c
c   # = 0  : zero current (reflective)
c   # = 1  : zero flux
c   # = 2  : non-reentrant current
c   # = 3  : cyclic (rotational)
c   # = 4  : not applicable
c
c ibypass : control parameter used to bypass the normalization of the
c flux to core average power of 1.00 activated when the the problem type
c is 2
c
c
c fislnn : l_1 norm of the fission source, used to claculate the
c          eigenvalue
c
c flamda : eigenvalue of the problem [ itype=1 ]
c
c sigmai :
c    for [itype=1] is the dominance ration of the iterative matrix
c    for [itype=2] is the spectral radius of the iterative matrix
c
c sigbar :
c    for [itype=1]  estimated dominance ration of the iterative matrix
c    for [itype=2]  estimated spectral radius of the iterative matrix
c
c erratn : l-2 norm of the fission source error (s(n)-s(n-1)), n: outer
c          itr. #
c
c erprod : the error reduction factor used to terminate cheby cycle.
c
c newcp  : new extrapolation cycle is indicated (newcp=1)
c
c nordcp : cehbyshev polynomial order
c
c icheby : steady-state chebychev acceleration control parameter
c           icheby = 0      [off]
c           icheby = 1      [on ]
c
c iupche : upper limit on chebyshev polynomial order
c
c
c nnew : control parameter for the cheby bootstrap flag
c     nnew = 1  bootstrap flag on
c     nnew = 0  bootstrap flag off
c
c nordcpn : control parameter for updating the coefficient matrix
c           activated only when [ icheby=0 ] i.e no st-st cheby
c
c         idrun
c         irstrt    indicates whether whether a restart file is to be
c                      read or not (1 or 0)
c         ibor      indicates whether a search (either criticality or
c                      power level) is to be performed (1 or 0)
c         iwhich    identifies the parameter to be varied during a
c                      search:  1 = power level
c                               2 = soluble boron concentration
c                               3 = inlet temperature
c                               4 = lead control-bank tip location
c         iburn     indicates whether the calculation contains depletion
c                      step(s)  (1 or 0)
c         npc       indicates whether whether printout will be detailed
c                      (1) or succinct (0)
c         al3       indicates whether echo of input will be long (1)
c                      or short (0)
c         crton     indicates whether output is to be written to the crt
c                      screen (1 or 0)
c         convrg    indicates whether converged ( 1 ) or not
c                      converged ( 0 )
c         nfdbk
c         s13
c         itran     indicates whether a transient (1) or steady-state
c                      (0) calculation is to be performed
c         itype     indicates whether an eigenvalue (1) or fixed-
c                      source (2) calculation is to be performed
c         nshap     indicates whether cartesian ( 1 ) or hexagonal ( 2 )
c                   geometry
c         isrch
c         irtype    indicates the type of reactor for which the
c                      calculation is to be performed ('pwr' or 'srs')
c
c
c    difkef : error in the k_eff value [ difference between two
c             consecutive values ], used in cheby.f as a convergence
c             criteria control.
c
c    diffis : fission source error :
c             [ l-2 norm of fission source error {s(l)-s(l-1)}]
c diffis =   ---------------------------------------------------
c             [ inner product of s(l) and s(l-1) {s(l),s(l-1)} ]
c     used in cheby.f as a convergence criteria control.
c
c
c    diflamnew : pointwise fission source difference.
c                [ l_inf norm {(s(l)-s(l-1))/s(l)} ]
c    diflamnew = ----------------------------------------------
c                           1  -  sigmai
c where :
c                    { spectral radius [fsp]
c            sigmai = |
c                    { dominance ratio [evp]
c
c   diflamnew used in cheby.f as a convergence criteria control
c
c
c   epsilkef : the error criteria in k_eff used for criticality search
c                    [ consecutive k_eff error ]
c               currently values set in routine outin.f
c
c   epsilpwr : the error criteria in core relative power [relpower] used
c                 for power level search.
c                      [ consecutive power fraction error ]
c                currently values set in routine outin.f
c
c  crit = k-eff value, calculated in routine cheby1.f
c
c   seff : effective fission source, used in the transient part
c            defined in outintr.f
c
c  sext : external source strength, read in the routine file_xsc.f
c
c
c
c flamdaold : previous eigen value, updated in cheby1.f
c
c inem :  a counter initialized whenever an nem update is performed
c         used for the convergence criteria, solution has to be
c         converged on an nem update. assigned in routine outin.f
c
c  the folowing common block contains the red-black [line sor] coloring
c  indices of the mesh nodes. for cartesian geometry
c
c    irpcnt  : total number of red colored nodes
c
c    ibpcnt  : total number of black colored node
c
c  the folowing common block contains the red-black [line sor] coloring
c  indices of the mesh nodes. for hexagonal geometry
c
c    irpcnt  : total number of red colored nodes
c
c    ibpcnt  : total number of black colored node
c     common /k3all/ delh
c
c     delh : hexagonal bundle pitch read in routine file_geo.f
c
c
c nsurfx : number of surfaces in the x-direction
c
c nsurfy : number of surfaces in the y-direction
c
c nsurfz : number of surfaces in the z-direction
c
c nsurfv : number of surfaces in the v-direction
c
c nsurfu : number of surfaces in the u-direction
c
c
c
c  ione : control parameter that control number of outers per time step
c
c....... ione = 1 : convergence criteria dependent
c....... ione = 2 : fixed number of outer iterations per time step
c
c
c iok : number of outers per time step
c        enabled only when ione=2
c
c this common block is for the convergence criteria set by the user
c           they all read in routine file_prf.f
c
c  kitr : maximum number of outer iteration permitted per run
c
c  epsin : outer iteration fission source l_inf convergence criteria
c
c  epsot : outer iteration fision source l_2 convergence criteria
c
c  epsk  : eigenvalue convergence criteria
c
c  epsdet: inner flux convergence criteria
c
c        nx        is the maximum number of nodes in the x-direction
c        ny        is the maximum number of nodes in the y-direction
c        nz        is the maximum number of nodes in the z-direction
c        ng        is the maximum number of energy groups
c        ngf       is the maximum number of fast energy groups
c        ngt       is the maximum number of thermal energy groups
c        nmg       is the maximum number of group-to-group scattering
c                     combinations
c
c the following parameters evaluated in routine relpower.f
c
c   pwrdn  : mesh dependent reactor power density
c
c   pwrdnp : mesh dependent prompt power density
c
c powerfrac: operating power fraction
c
c pwrdnold : mesh dependent previous time step power density
c
c  relpwr  : mesh dependent relative power density
c
c totpower : reactor core total power [summed over the fuel region]
c
c
c*** the following parameters read in routine file_xsc.f
c
c nprec  : number of precursor`s group
c
c alamda : precursors decay constants
c
c beta   : delayed neutron fraction
c
c xhid   : delayed neutron energy spectrum
c
c
c*** the following parameters are initialized in routine starter.f and
c      redefined in routine precr.f
c
c alxplamd : alamda * exp ( - alamda * deltat )
c        where deltat is the time step
c
c     the following two variables are internal parameters used in the
c      transient calculations of the  effective fision source
c
c        filamdt0(ng)
c        filamdt1(ng)
c
c ci  : precursor concentration
c
c***following routines defined in routine inital.f, and used in steady
c    state and fast transient solution
c
c  betat : sum of { beta(i) } over all precursors, defined in routine
c           inital.f
c
c  betatlam(ig) : sum of { beta(i)*xhid(ig,i) } over all precursors,
c  defined in routine inital.f,
c
c
c*** other vriables
c
c  explamdt : internal variable used to define the effective fission
c  source calculated in routines outintr.f nonplmh.f nonplmc.f
c
c effkinp : input k_eff value, enabled only when reading data from a
c  restart file, read in routine inital.f
c
c effkout : output k_eff value, enabled only when writing data to a
c           restart file, defined in routine cheby.f
c
c  ksst : steady-state outer iteration index, initialized in routine
c          steady.f and updated in routine outin.f
c
c  ccf  : scaling parameter used in the eignevalue problem to scale
c         the normalized flux to the target power level, defined in
c         routines steady.f and slowtran.f
c              ccf = pr*qt
c where pr : desired power level , read in routine file_cnt.f
c       qt : reactor core power density
c
c n_thrmitr : number of thermal iteration required to solve the problem
c              applicable only for ng=4 [ four energy groups ] read in
c              the routine file_prf.f
c
c the following variables represent the location of the maximum power
c  peak in the core, calculated in the routine errorn.f
c
c    j4x :  x-axes location
c    j4y :  y-axes location
c    j4z :  z-axes location
c
c
c  rt  : fast to thermal flux ratio guess read in file_xsc.f
c
c  qqt : core power density  [kw/litre] read in file_xsc.f
c
c  qt  : core power density [mev/sec-cm**3] defined in conver.f
c
c  pr  : core relative power fraction read in file_cnt.f
c
c
c nxstart.... the first node on a given y-line
c nxend  .... the last node on a given y-line
c nystart.... the first node on a given x-line
c nyend  .... the last node on a given x-line
c ndnum  .... the node's number
c nxskip .... the number of nodes skipped when moving in the x direction
c        .... (1 for cart and 2 for hex)
c
c nxytot .... total number of nodes (actual nodes + extra nodes added to
c        .... specify the type of boundary condition used.
c nbc    .... indicates the type of boundary condition used for
c         .... a particular node.
c
c nxyl = the total number of mesh nodes in the x-y plane
c
