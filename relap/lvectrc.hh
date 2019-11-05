*mlist
c
c  These vector lists are initialized in trnset
c
c  Cognizant engineer: rjw.
c
c  lvaccm  pointer to accumulator list.
c  lvpump  pointer to pump list.
c  lvsepr  pointer to separator list.
c  lvvalv  pointer to valve list.
c  lvturb  pointer to turbine list.
c  lvjtmx  pointer to jetmixer list.
c  lvrvol  pointer to real volume list.
c  lvtvol  pointer to time dependent volume list.
c  lvjusr  pointer to junction-source list.
c  lvabrp
c  lvhzfl
c  lvwifr  pointer to volumes with wall friction list
c  lvnofr  pointer to volumes without wall friction list
c  lv3d    pointer to multidimensional components.
c  lvprz   pointer to pressurizer component junction list.
c  lvajun  pointer to list of all junctions
c  lvavol  pointer to list of all volumes
c  lvscr   pointer to scratch list
c  lvptr   list values.
c
c  if any lv... pointer is 0, then the list vector is empty
c  when a lv... pointer is >0, then the list vector (lvptr) contains
c      number of volumes, junctions, etc.
c      index to the 1st volume, junction, etc.
c      index to the 2nd volume, junction, etc.
c       ...
c
c  The list vector (lvjusr) for the junction-source list is different
c  when lvjusr > 0, then the list vector (lvptr) contains
c      number of vector loops that can be run
c      number of junctions in the 1st vector loop
c      index to the 1st junction in the 1st vector loop
c      index to the 2nd junction in the 1st vector loop
c       ...
c      number of junctions in the 2st vector loop
c      index to the 1st junction in the 2nd vector loop
c      index to the 2nd junction in the 2nd vector loop
c       ...
c      ...  ...
c      number of junctions in the scalar block
c        these junctions can not be vectorized
c         or there are 5 junctions or less junctions in the vector loop
c      index to the 1st junction in the scalar set
c      index to the 2nd junction in the scalar set
c       ...
c
