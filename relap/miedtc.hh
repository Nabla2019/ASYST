*mlist
!  Contains equivalence blocks for minor edits.
!
!  Cognizant engineer: rjw.
!
!  Equivalence blocks for minor edits.
       integer nmiet(l_),mietab(l_)
       real mietaf(l_)
       equivalence (nmiet(1),ia(1)),(mietaf(1),fa(2)),(mietab(1),ia(2))
       integer mipck(l_),micode(l_)
       real miconv(l_),mihold(l_),milabl(l_)
       equivalence (mipck(1),ia(1)),(micode(1),ia(6)),
     & (miconv(1),fa(8)),(mihold(1),fa(6)),(milabl(1),fa(6))
!
!  nmiet  number of minor edit requests.
!  mietab (n)   integer part of minor edit request(card number)
!  mietaf (n+1) alphanumeric part of minor edit request
!  mietab (n+2) integer part of minor edit request
!  mipck  (n)   number of items to be saved per time step (12 bits max)
!         (n+1) increment, 1 if no conversion factors, 2 if conversion
!               factors (2 bits max)
!         (n+2) label pointer (18 bits max)
!         (n+3) save area pointer (18 bits max)
!         (n+4) number of time steps saved (6 bits max)
!  micode (n)   number of control block or if 0 then common(12 bits max)
!         (n+1) location offset in block (18 bits max)
