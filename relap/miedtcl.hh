*mlist
c
c  Cognizant engineer: rjw.
c
c  nmiet  number of minor edit requests.
c  mietab (n)   integer part of minor edit request(card number)
c  mietaf (n+1) alphanumeric part of minor edit request
c  mietab (n+2) integer part of minor edit request
c  mipck  (n)   number of items to be saved per time step (12 bits max)
c         (n+1) increment, 1 if no conversion factors, 2 if conversion
c               factors (2 bits max)
c         (n+2) label pointer (18 bits max)
c         (n+3) save area pointer (18 bits max)
c         (n+4) number of time steps saved (6 bits max)
c  micode (n)   number of control block or if 0 then common(12 bits max)
c         (n+1) location offset in block (18 bits max)
