!
!  Cognizant engineer: rjw.
!
       common /rcompc/ ncomp,cmpsrc,cmpflg
       integer ncomp
       logical cmpsrc,cmpflg
!
       character :: cmpalf(17)*8=
     & (/'pipe','tmdpvol','mtpljun','pump','branch',
     & 'jetmixer','annulus','separatr','tmdpjun','snglvol',
     & 'sngljun','valve','accum','turbine','eccmix','multid',
     & 'prizer'/)
