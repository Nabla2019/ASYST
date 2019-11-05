*mlist
*comdeck rupt
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
c
       integer nrlcmx,nrlhmx
       parameter (nrlcmx=9, nrlhmx=10)
c
       common /rupt/ timrcl,dcrepc(nrlcmx),pext,imat,incn,ncnvol,
     * nel(nrlcmx),nelem(11,nrlcmx),nrlc,dcreph(nrlhmx),prihs(nrlhmx),
     * prohs(nrlhmx),imaths(nrlhmx),nhs(nrlhmx),nhsord(nrlhmx),nrlh,
     * mcme60
       real timrcl,dcrepc,pext,dcreph,prihs,prohs
       integer imat,incn,ncnvol,nel,nelem,nrlc,imaths,nhs,nhsord,nrlh,
     * mcme60
c
c       nrlcmx = max. number of couple rupture calc. locations.
c       nrlhmx = max. number of heat structure rupture calc. locations.
c
c       timrcl = time at last rupture calculation.
c       dcrepc = creep damage term for couple wall locations.
c                the calculated value ranges from 0.0 to 1.0, where
c                0.0 means that no damage has occurred, and
c                1.0 means that the wall has ruptured.
c       pext   = couple wall outer pressure.
c       imat   = material index for couple wall -
c                   1 = a-508 class 2 carbon steel (default if no input)
c                   2 = 316 stainless steel
c                   3 = inconel 600.
c       incn   = index offset  for volume outside couple wall.
c       ncnvol = no. of volume outside couple wall.
c       nel(i) = number of couple elements specified for location i.
c       nelem(j,i) = elements specified for location i; j=1 to nel(i).
c       nrlc   = number of couple rupture calculation locations.
c       dcreph = creep damage term for heat structures.
c                same definition as for dcrepc above.
c       prihs  = heat structure inner pressure.
c       prohs  = heat structure outer pressure.
c       imaths = material indices for heat structures.
c                same values as for couple above.
c       nhs    = heat structure number.
c       nhsord = heat structure data storage order.
c       nrlh   = number of heat structure rupture calculation locations.
