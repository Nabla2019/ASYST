*comdeck stcom
c
c
c  Descriptive sentence for stcom goes here.
c
c
c  Cognizant engineer: rjw.
c
       integer  lstcom
$if -def,in32,1
       parameter  ( lstcom = 19 )
$if def,in32,1
       parameter  ( lstcom = 15 )
c      Note:  if the length of /stcom/ is changed, the value of lstcom
c             must be changed accordingly (lstcom = real word length)
c
       common /stcom/ ttrip,ptrip,vtrip,tcrit,pcrit,vcrit,tmin,pmin,
     & tmax,pmax,nt,np,nst,nsp,it3bp,it4bp,it5bp,nprpnt,it3p0
c  Note:  This common block should agree with the common block of the
c  same name on the Environmental Library.
       real ttrip,ptrip,vtrip,tcrit,pcrit,vcrit,tmin,pmin,tmax,pmax
       integer nt,np,nst,nsp,it3bp,it4bp,it5bp,nprpnt,it3p0
