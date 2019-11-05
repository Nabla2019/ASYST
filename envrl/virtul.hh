!  Common to hold data for ftbin and ftbout commands.
!  Information is written to memory assuming paging will move the data
!  to disk when necessary.
$if def,in32,2
       common /virtul/ zzz
       real*8 zzz(100000)
