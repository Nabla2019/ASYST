*mlist
!
!  Cognizant engineer: ras.
!
!  Scrach storage for reflood calculation.
       real htvhc2(l_),httc2(l_),htpws(l_),aijr(l_),aijt(l_),tmpscr(l_)
       equivalence (htvhc2(1),fa(1)),(httc2(1),fa(2)),(htpws(1),fa(3)),
     & (aijt(1),fa(4)),(aijr(1),httc2(1)),(tmpscr(1),fa(5))
!
!  htvhc   1) Volumetric heat capacities for mesh intervals; 2) Volume
!          weighted volumetric heat capacities for mesh points.
!  aijr    1) Thermal conductivities for mesh intervals; 2) thermal
!          conductivities divided by two for mesh intervals;
!          3) mesh point temperatures during mesh renodalization;
!          4) Radial off-diagonal element.
!  htpws   Time dependent and volume weighted power term.
!  aijt    Axial off-diagonal element.
!  tmpscr  Mesh point temperatures during actual advancement.
