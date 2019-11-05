*mlist
c
c  Dynamic file for radiation heat transfer is file 38.
c
c  Cognizant engineer:
c
c   definitions for radiation heat transfer
c  nrset   number of sets of radiation surfaces
c  irhflx  offset to radiation heat fluxes which are for all heat str.
c     ------- above two words are 1st and second words in the file ---
c       ***nrsskp,nrhskp are parameters***
c  nrsskp  skip factor for radiation ht set variables
c  nrhskp  skip factor for radiation ht surface variables
c
c-the following block is repeated for each set of radiating surfaces
c-these blocks arranged sequentially in order of increasing set number.
c  setno   the set number.  may be negative during input processing
c  refset  the set number from which this set gets its view factors.
c          refset must always be less than setno.
c  nrh     number of radiation surfaces in the set
c  trmin   minimum surface temperature of surfaces.  if all surfaces
c          have temp less than trmin no radiation calculated for the set
c  voidmn  minimum vapor void fraction. if boundary volume void fraction
c          is less than voidmn no radiation calculated for the set
c  timron  last time radiation ht calculation began for a set
c           timron positive means radiation calc is off
c           timron negative means radiation calc is on
c  timrof last time radiation ht ended for a set
c  irhoff  offset to radiation ht surface data for a set
c  ivewof   offset to vfij matrix for a set
c
c    the following variables are repeated for each radiation surface
c
c  jrh     heat conductor surface number   (input)
c  jlr     0 = left surface     (input)
c          1 = right surface    (input)
c          in iradht routine jlr is changed to the sequence number of
c          radition surface so that it points to itemof location in the
c          heat structure dynamic file. this index is:
c          - for left surface
c          + for right surface
c  emis    emissivity of a surface
c  itemof     offset to surface temperature (pointer into heat str file)
c  ias     offset to surface area   (pointer into heat str file)
c  itg     offset to fluid temperature (pointer into volume file)
c  qrad    radiation heat flux for a surface
c
c
c    the following is set of view factor matrices.  there may be one
c    nrh by nrh view factor matrix for each set of radiating surfaces,
c    but there may be fewer since one set can refer to another set for
c    its view factors.
c    the first nrh elements in each matrix contains the view factors
c    from the 1st surface in the set to the nrh surfaces, etc.
c
c  vfij    view factors for first set   (nrh(1)**2 words)
c  vfij    view factors for next set..etc
c
c    the following two words are repeated nhtstr times, where nhtstr
c    is the total number of heat structures in the problem (as stored
c    in the heat structure file)
c  qlrad   left radiation heat flux to heat conductors
c          (not just radiative heat conductors)
c  qrrad   right radiation heat flux to heat conductors
c          (not just radiative heat conductors)
c
c
