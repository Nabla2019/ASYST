*mlist
!  Cognizant engineer: rjw.
!
       integer  lstcom
$if -def,in32,1
       parameter (lstcom = 19)
$if def,in32,1
       parameter (lstcom = 15)
!  Note:  if the length of /stcom/ is changed, the value of lstcom
!  must be changed accordingly (lstcom = real word length).
!
       common  /stcom/ ttrip,ptrip,umult,tcrit,pcrit,vcrit,tmin,pmin,
     & tmax,pmult,nu,np,nst,nsp,nprpt3,nprpt4,it2p,it3p,it4p
!  Note:  this common block should agree with the common block of the
!  same name on the Environmental Library.
       real ttrip,ptrip,umult,tcrit,pcrit,vcrit,tmin,pmin,tmax,pmult
       integer nu,np,nst,nsp,nprpt3,nprpt4,it2p,it3p,it4p
