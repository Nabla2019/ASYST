*mlist
c
c  Cognizant engineer:ras.
c
c  nrflht  number of heat structure-geometries designated for reflood-
c          rezoning calculations.
c  lhtrfl  offset to ihtptr for first heat structure in a heat structure
c          designated  for reflood.
c  inxrfl(1)  offset/index to heat structure dependent data.
c  inxrfl(2)  offset/index to axial mesh point dependent data.
c  inxrfl(3)  offset/index to temperature data.
c  inxrfl(4)  offset/index to mesh point positioning data.
c  iglrfl(1)  maximum number of axial levels.
c  iglrfl(2)  current number of axial levels.
c  zbunht     height of reflood bundle.
c  zqbot      height of reflood bottom quenched region.
c  zqtop      height of reflood top quenched region.
c  fines      current number of axial nodes on a reflood heat structure.
c  tchfqf     temperature corresponding to qfchfn.
c  trewet     quench, Leidenfrost or rewet temperature.
c  strgeo     heat structure-geometry which reflood set belongs to
c             (on restart this word is set to 0 or negative if
c             the heat str is deleted or overlayed in rhtcmp)
c  tmprfo    old time temperature array.
c  tmprfn    new time temperature array.
c  htlenz    axial mesh points coordinate.
