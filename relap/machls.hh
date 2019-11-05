*mlist
c
c  Cognizant engineer: rjw.
c
$if def,apollo,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,cray,2
       real xawxyz
       integer iawxyz,locf,locf4,locfi,locfi4
$if def,decrisc,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,decrisc2,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,decalpha,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,ifortc,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if -def,ifortc,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,hp,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,ibm,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,ibmrisc,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,laheyf77,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
$if def,sun,2
       integer locf,locf4,locfi,locfi4
       external locf,locf4,locfi,locfi4
