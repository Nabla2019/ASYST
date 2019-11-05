*mlist
*comdeck cvals
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c  ****** Beginning of timestep variables for timestep repetition ******
      real           c9z    , hffz  , homz  , ssz   , tomz
c  ****** End of timestep variables for timestep repetition ************
      real           c9     , hff   , hom   , ss    , tom
c
      integer        mcme91
c  ****** Beginning of timestep variables for timestep repetition ******
      common /cvals/ c9z(99,6,5)    , hffz(99)      , homz(99,6)    ,
     1               ssz(99), tomz(99,6)
c  ****** End of timestep variables for timestep repetition ************
      common /cvals/ c9(99,6,5)     , hff(99)       , hom(99,6)     ,
     1               ss(99), tom(99,6) , mcme91
*endif
