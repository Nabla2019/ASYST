*mlist
!  Inverted heat structure table block.
!  Cognizant engineer: rjw.
!
       integer invhkp
       parameter (invhkp=5)
       integer invhos(l_),inhcnt(l_),inhtno(l_),inhtns(l_),insrft(l_)
       real frphpw(l_),frahaw(l_)
       equivalence (invhos(1),ia(1)),(inhcnt(1),ia(2)),
     & (inhtno(1),ia(3)),(inhtns(1),ia(4)),(insrft(1),ia(5)),
     & (frphpw(1),fa(6)),(frahaw(1),fa(7))
!
!  invhkp  Skip factor for each heat structures block.
!  invhos  Offset used to compute indexes stored in insrft.
!  The following words (to the end) repeats for each volume.
!  inhcnt  Number of heat structures surfaces attached to this volume.
!    The following words (to the end) repeats for each heat structure
!    attached to a volume.
!  inhtno  Index to heat structure data.
!  inhtns  Index to heat structure data plus 0 or 1 for left or right
!          side.
!  insrft  Index to surface temperature.
!  frphpw  Ratio of volume hydraulic diameter to heat structure heated
!          hydraulic diameter.
!  frahaw  Ratio of heat structure surface area to total surface area
!          of all heat strutures attached to volume.
