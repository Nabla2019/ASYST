*mlist
!  Descriptive sentence for radhtc goes here.
!
!  Cognizant engineer: rjw.
!
!  Definitions for radiation heat transfer.
       integer nrsskp,nrhskp
       parameter (nrsskp=9,nrhskp=7)
       integer nrh(l_)   , ivewof(l_), jrh(l_)   , jlr(l_)   ,
     &         setno(l_) , itemof(l_), iareof(l_), ialpof(l_),
     &         irhflx(l_), irhoff(l_), nrset(l_) , refset(l_)
       real    trmin(l_) , voidmn(l_), emis(l_)  , vfij(l_)  ,
     &         qrad(l_)  , qlrad(l_) , qrrad(l_) , timron(l_),
     &         timrof(l_)
       equivalence (nrset(1) , ia( 1)), (irhflx(1) , ia( 2)),
     &             (setno(1) , ia( 3)), (refset(1) , ia( 4)),
     &             (nrh(1)   , ia( 5)), (trmin(1)  , fa( 6)),
     &             (voidmn(1), fa( 7)), (timron(1) , fa( 8)),
     &             (timrof(1), fa( 9)), (irhoff(1) , ia(10)),
     &             (ivewof(1) , ia(11))
       equivalence (jrh(1)   , ia( 1)),
     &             (jlr(1)   , ia( 2)), (emis(1)   , fa( 3)),
     &             (itemof(1), ia( 4)), (iareof(1) , ia( 5)),
     &             (ialpof(1), ia( 6)), (qrad(1)   , fa( 7))
       equivalence (vfij(1)  , fa( 1)), (qlrad(1)  , fa( 1)),
     &             (qrrad(1) , fa( 2))
!
!  Definitions for radiation heat transfer.
!  nrset   number of sets of radiation surfaces
!  irhflx  offset to radiation heat fluxes which are for all heat str.
!     ------- above two words are 1st and second words in the file ---
!       ***nrsskp,nrhskp are parameters***
!  nrsskp  skip factor for radiation ht set variables
!  nrhskp  skip factor for radiation ht surface variables
!
!-the following block is repeated for each set of radiating surfaces
!-these blocks arranged sequentially in order of increasing set number.
!  setno   the set number.  may be negative during input processing
!  refset  the set number from which this set gets its view factors.
!          refset must always be less than setno.
!  nrh     number of radiation surfaces in the set
!  trmin   minimum surface temperature of surfaces.  if all surfaces
!          have temp less than trmin no radiation calculated for the set
!  voidmn  minimum vapor void fraction. if boundary volume void fraction
!          is less than voidmn no radiation calculated for the set
!  timron  last time radiation ht calculation began for a set
!           timron positive means radiation calc is off
!           timron negative means radiation calc is on
!  timrof last time radiation ht ended for a set
!  irhoff  offset to radiation ht surface data for a set
!  ivewof   offset to vfij matrix for a set
!
!    the following variables are repeated for each radiation surface
!
!  jrh     heat conductor surface number   (input)
!  jlr     0 = left surface     (input)
!          1 = right surface    (input)
!          in iradht routine jlr is changed to the sequence number of
!          radition surface so that it points to itemof location in the
!          heat structure dynamic file. this index is:
!          - for left surface
!          + for right surface
!  emis    emissivity of a surface
!  itemof     offset to surface temperature (pointer into heat str file)
!  ias     offset to surface area   (pointer into heat str file)
!  itg     offset to fluid temperature (pointer into volume file)
!  qrad    radiation heat flux for a surface
!
!
!    the following is set of view factor matrices.  there may be one
!    nrh by nrh view factor matrix for each set of radiating surfaces,
!    but there may be fewer since one set can refer to another set for
!    its view factors.
!    the first nrh elements in each matrix contains the view factors
!    from the 1st surface in the set to the nrh surfaces, etc.
!
!  vfij    view factors for first set   (nrh(1)**2 words)
!  vfij    view factors for next set..etc
!
!    the following two words are repeated nhtstr times, where nhtstr
!    is the total number of heat structures in the problem (as stored
!    in the heat structure file)
!  qlrad   left radiation heat flux to heat conductors
!          (not just radiative heat conductors)
!  qrrad   right radiation heat flux to heat conductors
!          (not just radiative heat conductors)
!
!
