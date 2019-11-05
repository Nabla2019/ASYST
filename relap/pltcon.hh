*mlist
c
c  plot header and control dynamic storage - filid(15).
c
c  Cognizant engineer: rjw.
c
c  Plot header and control dynamic storage ... filid(15).
       integer n2dplt(1),n2dskp(1),ncptbl(1),genops(1),maxpar(1),
     & maxxar(1),maxcmp(1),maxsiz(1),hdlins(1)
       real gensiz(3),gwidth(1),ghight(1),gmagnf(1),plthdr(1),chkplt(1)
       equivalence (gwidth(1),gensiz(1)),(ghight(1),gensiz(2)),
     & (gmagnf(1),gensiz(3))
       equivalence (n2dplt(1),ia(1)),(n2dskp(1),ia(2)),
     & (ncptbl(1),ia(3)),(genops(1),ia(4)),(gensiz(1),fa(5)),
     & (maxpar(1),ia(8)),(maxxar(1),ia(9)),(maxcmp(1),ia(10)),
     & (maxsiz(1),ia(11)),(hdlins(1),ia(12)),(plthdr(1),fa(13)),
     & (chkplt(1),fa(43))
c  Note........ plthdr contains 30 alpha-numeric words.
c  2d plot request and specification dynamic storage ... filid(22).
       integer numplt(1),len2dp(1),numpar(1),numxar(1),
     & ncmprf(1),titlex(1),titley(1),axspec(1),pltops(1),parnum(1),
     & xarnum(1),crpnum(1),parptr(1),xarptr(1),crvnam(1),curvsp(1),
     & comprf(1)
       real parnam(1),convty(1),xarnam(1),xartim(1),convtx(1),pltitl(1),
     & xminsp(1),xmaxsp(1),yminsp(1),ymaxsp(1),fwidth(1),fhight(1),
     & fmagnf(1)
       equivalence (numplt(1),ia(1)),(len2dp(1),ia(2)),
     & (parnam(1),fa(3)),(numpar(1),ia(4)),(convty(1),fa(5)),
     & (xarnam(1),fa(6)),(xartim(1),fa(7)),(convtx(1),fa(8)),
     & (numxar(1),ia(9)),(ncmprf(1),ia(10)),(pltitl(1),fa(11)),
     & (titlex(1),ia(21)),(titley(1),ia(31)),(xminsp(1),fa(41)),
     & (xmaxsp(1),fa(42)),(yminsp(1),fa(43)),(ymaxsp(1),fa(44)),
     & (axspec(1),ia(45)),(pltops(1),ia(46)),(fwidth(1),fa(47)),
     & (fhight(1),fa(48)),(fmagnf(1),fa(49)),(parnum(1),ia(50)),
     & (xarnum(1),ia(51)),(crpnum(1),ia(52)),(parptr(1),ia(53)),
     & (xarptr(1),ia(54)),(crvnam(1),ia(55)),(curvsp(1),ia(57)),
     & (comprf(1),ia(58))
c  2d plot comparison data table dynamic storage ... filid(23).
       integer ctblno(1),lentbl(1),datnam(1),datasp(1),npairs(1)
       real yname(1),ymintb(1),ymaxtb(1),xname(1),xmintb(1),xmaxtb(1),
     & xdata(1)
       equivalence (ctblno(1),ia(1)),(lentbl(1),ia(2)),
     & (yname(1),fa(3)),(ymintb(1),fa(4)),(ymaxtb(1),fa(5)),
     & (xname(1),fa(6)),(xmintb(1),fa(7)),(xmaxtb(1),fa(8)),
     & (datnam(1),ia(9)),(datasp(1),ia(11)),(npairs(1),ia(12)),
     & (xdata(1),fa(13))
