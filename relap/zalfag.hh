*mlist
!  Common inline formula to calculate void from quality, vapor specific
!  volume, and liquid specific volume.
!
!  Cognizant engineer: rjw.
!
!  alfag = voidg
!  qxx   = quality
!  vxxg  = vapor sp. volume
!  vxxf  = liquid sp. volume
       alfag(qxx,vxxg,vxxf) = max(0.0, min(1.0, (qxx*vxxg/
     & (vxxf + qxx*(vxxg - vxxf)))))
