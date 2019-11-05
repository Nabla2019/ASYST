*mlist
!  rknatb is the table for interpolation for the ans79 neutron
!  absoprtion effect in decay heating calculations.
!
       common /rknatb/ rkntbl(2,48),rkntbx,rkilk
       real rkntbl,rkntbx
       integer rkilk
!
!  rkntbl  Table of neutron absorption 'g factor' as a function of
!          shutdown time.
!  rkntbl  Current interpolation factor.
!  rkilk   Current position in table.
