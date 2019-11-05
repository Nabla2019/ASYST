*mlist
$if def,makemap
c
c  Cognizant engineer: gam.
c
       common /makmap/ targmp,targcn,target
       integer targmp,targcn,target
c
c  values for setting this common block are input on card 89
c  see rmap.F which is called by rnewp.F
c
c  targmp = 1 for phantj map
c         = 2 for phantv map
c         = 3 for htadv map
c         = 0 as the default
c  targcn = ncount for making the map
c  target = junction number for phantj map
c         = volume number for phantv map
c         = heat structure number for htadv map
c
$endif
