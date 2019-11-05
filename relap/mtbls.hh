*mlist
!  Thermal property equivalence block.
!
!  Cognizant engineer: rjw.
!
!  Thermal property equivalence block.
       integer nmtbls(l_),mtbptr(l_),mtbnum(l_),mtblen(l_),mtbl(l_)
       real mtblr(l_)
       equivalence (nmtbls(1),ia(1)),(mtbptr(1),ia(1)),
     & (mtbnum(1),ia(1)),(mtblen(1),ia(2)),(mtbl(1),ia(3)),
     & (mtblr(1),fa(3))
!
!  nmtbls  number of materials
!  mtbptr  offset to material data.
!  mtbnum  composition or material number.
!  mtblen  length of data for material.
!  mtbl    used for integer information in table.
!  mtblr   used for real (floating point) information in table.
