*mlist
c
c  Cognizant engineer: rjw.
c
$if def,cray,4
       locf(xawxyz) = loc(xawxyz)
       locf4(xawxyz) = loc(xawxyz)
       locfi(iawxyz) = loc(iawxyz)
       locfi4(iawxyz) = loc(iawxyz)
$if def,vax,8
       locf(xawxyz) = ishft(%loc(xawxyz),-3)
       locfi(iawxyz) = ishft(%loc(iawxyz),-3)
$if -def,fourbyt,2
       locf4(xawxyz) = ishft(%loc(xawxyz),-3)
       locfi4(iawxyz) = ishft(%loc(iawxyz),-3)
$if def,fourbyt,2
       locf4(xawxyz) = ishft(%loc(xawxyz),-2)
       locfi4(iawxyz) = ishft(%loc(iawxyz),-2)
