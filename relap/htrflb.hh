*mlist
!
!  Cognizant engineer:ras.
!
!  Reflood block.
       integer nhtga,nhtma,nscra1,nscra2
       parameter (nhtga=14,nhtma=13,nscra1=13,nscra2=5)
!  Heat structure-geometry dependent data.
       integer nrflht(l_),lhtrfl(l_),inxrfl(l_),iglrfl(l_),strgeo(l_)
       real fines(l_)
       real zbunht(l_),zqbot(l_),zqtop(l_),tchfqf(l_),trewet(l_)
       equivalence (nrflht(1),ia(1)),(lhtrfl(1),ia(2)),
     & (inxrfl(1),ia(3)),(iglrfl(1),ia(7)),
     & (zbunht(1),fa(9)),(zqbot(1),fa(10)),(zqtop(1),fa(11)),
     & (fines(1),fa(12)),(tchfqf(1),fa(13)),(trewet(1),fa(14)),
     & (strgeo(1),ia(15))
!  Heat structure dependent data.
       integer nmzht(l_)
       equivalence (nmzht(1),ia(1))
!  Axial mesh interval dependent data.
       real htdzlm(l_)
       equivalence (htdzlm(1),fa(1))
!  Temperature data.
       real tmprfo(l_),tmprfn(l_)
       equivalence (tmprfo(1),fa(1)),(tmprfn(1),fa(1))
!  Mesh point position data.
       real htlenz(l_)
       equivalence (htlenz(1),fa(1))
!  Surface temperature data.
       real tmpsfo(l_),tmpsfn(l_)
       equivalence (tmpsfo(1),fa(1)),(tmpsfn(1),fa(2))
!
!  nrflht  number of heat structure-geometries designated for reflood-
!          rezoning calculations.
!  lhtrfl  offset to ihtptr for first heat structure in a heat structure
!          designated  for reflood.
!  inxrfl(1)  offset/index to heat structure dependent data.
!  inxrfl(2)  offset/index to axial mesh point dependent data.
!  inxrfl(3)  offset/index to temperature data.
!  inxrfl(4)  offset/index to mesh point positioning data.
!  iglrfl(1)  maximum number of axial levels.
!  iglrfl(2)  current number of axial levels.
!  zbunht     height of reflood bundle.
!  zqbot      height of reflood bottom quenched region.
!  zqtop      height of reflood top quenched region.
!  fines      current number of axial nodes on a reflood heat structure.
!  tchfqf     temperature corresponding to qfchfn.
!  trewet     quench, Leidenfrost or rewet temperature.
!  strgeo     heat structure-geometry which reflood set belongs to
!             (on restart this word is set to 0 or negative if
!             the heat str is deleted or overlayed in rhtcmp)
!  tmprfo    old time temperature array.
!  tmprfn    new time temperature array.
!  htlenz    axial mesh points coordinate.
