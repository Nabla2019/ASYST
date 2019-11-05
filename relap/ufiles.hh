*mlist
!
!  Cognizant engineer: rjw.
!
       common /ufiles/ input,output,rstplt,stripf,plotfl,sth2xt,tty,
     & eoin,jbinfo,coupfl,inpout
       integer input,output,rstplt,stripf,plotfl,sth2xt,tty,eoin,jbinfo
       integer coupfl,inpout
!
!  input   input file.
!  output  printed output file.
!  rstplt  restart-plot file.
!  stripf  strip file.
!  plotfl  scratch file for internal plot capability.
!  sth2xt  used for all thermodynamic property files.
!  tty     online screen file.
!  jbinfo  user file to be copied to job output file.
!  filsch  holds file names used in open statements (except for
!          thermodynamic properties files);  default values set by data
!          statements in blkdta;  user supplied values can be optionally
!          entered in some machine versions.
