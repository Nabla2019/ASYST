*mlist
!
!  Cognizant engineer: rjw.
!
       integer lvskp
       parameter (lvskp=17)
       integer lvaccm(l_),lvpump(l_),lvsepr(l_),lvvalv(l_),lvturb(l_),
     & lvjtmx(l_),lvrvol(l_),lvtvol(l_),lvjusr(l_),lvabrp(l_),
     & lvhzfl(l_),lvwifr(l_),lvnofr(l_),lv3d(l_),lvprz(l_),
     & lvptr(l_),lvajun(l_),lvavol(l_),lvscr(l_)
       equivalence (lvaccm(1),ia(1)),(lvpump(1),ia(2)),
     & (lvsepr(1),ia(3)),(lvvalv(1),ia(4)),(lvturb(1),ia(5)),
     & (lvjtmx(1),ia(6)),(lvrvol(1),ia(7)),(lvtvol(1),ia(8)),
     & (lvjusr(1),ia(9)),(lvabrp(1),ia(10)),(lvhzfl(1),ia(11)),
     & (lvwifr(1),ia(12)),(lvnofr(1),ia(13)),(lv3d(1),ia(14)),
     & (lvprz(1),ia(15)),(lvajun(1),ia(16)),(lvavol(1),ia(17)),
     & (lvscr(1),ia(18)),(lvptr(1),ia(1))
!
!  These vector lists are initialized in trnset
!
!  lvaccm  pointer to accumulator list.
!  lvpump  pointer to pump list.
!  lvsepr  pointer to separator list.
!  lvvalv  pointer to valve list.
!  lvturb  pointer to turbine list.
!  lvjtmx  pointer to jetmixer list.
!  lvrvol  pointer to real volume list.
!  lvtvol  pointer to time dependent volume list.
!  lvjusr  pointer to junction-source list.
!  lvabrp
!  lvhzfl
!  lvwifr  pointer to volumes with wall friction list
!  lvnofr  pointer to volumes without wall friction list
!  lv3d    pointer to multidimensional components.
!  lvprz   pointer to pressurizer component junction list.
!  lvajun  pointer to list of all junctions
!  lvavol  pointer to list of all volumes
!  lvscr   pointer to scratch list
!  lvptr   list values.
!
!  if any lv... pointer is 0, then the list vector is empty
!  when a lv... pointer is >0, then the list vector (lvptr) contains
!      number of volumes, junctions, etc.
!      index to the 1st volume, junction, etc.
!      index to the 2nd volume, junction, etc.
!       ...
!
!  The list vector (lvjusr) for the junction-source list is different
!  when lvjusr > 0, then the list vector (lvptr) contains
!      number of vector loops that can be run
!      number of junctions in the 1st vector loop
!      index to the 1st junction in the 1st vector loop
!      index to the 2nd junction in the 1st vector loop
!       ...
!      number of junctions in the 2st vector loop
!      index to the 1st junction in the 2nd vector loop
!      index to the 2nd junction in the 2nd vector loop
!       ...
!      ...  ...
!      number of junctions in the scalar block
!        these junctions can not be vectorized
!         or there are 5 junctions or less junctions in the vector loop
!      index to the 1st junction in the scalar set
!      index to the 2nd junction in the scalar set
