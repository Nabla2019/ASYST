*mlist
*comdeck iparm
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
      integer nipar1, nipar2, nipar3
      parameter (nipar1 =140, nipar2 = 56)
      parameter (nipar3 = nipar1 + nipar2)
c  nipar1 = number of couple a array pointers.
c  nipar2 = number of couple non-pointer integers.
c
c      Note: Be sure and change nipar1 or nipar2 if you change
c            the number of pointers or non-pointers, resp.
c
      common / iparm /        i5,     i6,     i7,     i8,     i9,
     1       i10,    i20,    i21,    i22,    i27,    i28,    i29,
     2       i40,    i41,    i42,    i43,    i44,    i45,    i46,
     3       i47,    i48,    i49,    i50,    i51,    i60,    i61,
     4       i62,    i70,    i72,    i74,    i76,    i78,    i80,
     5       i82,    i84,    i86,    i88,    i90,    i99,   i100,
     6      i102,   i103,   i104,   i105,   i107,   i108,   i109,
     7      i110,   i111,   i112,   i113,   i114,   i115,
     8    icompt, idetop, igmcpt, igmopt, ihtcto, inetco,
     *    inodpt, inussn,  ipafp,  ipbfp, ipfrto,
     9            iptalf, iptars, iptcdf, iptsif, ipteij, iptfml,
     a     iptfp, iptfpv, iptgav, ipthfs, ipthtm, iptiel, iptihs,
     b    iptjel, iptkfr, iptkfz, iptlif, iptmdt, iptmet, iptmlt,
     c    iptspd, iptspl, ipttsm, iqcopt, iqfopt, iqolpt, iqotpt,
     d    iqwcpt,  ir5pt, itsink, ivcnpt, ivfspt, ivrapt, ivrdpt,
     e        m1,     m2,     m3,     m4,     m5,     m6,     m7,
     f        m8,     m9,    m10,    m12,    m13,    m14,    m15,
     g        n1,     n2,     n3,     n4,     n5,     n6,     n7,
     # n20,n100,n101,n102,n103,n132,n150,iptnbu,ipxfp
      common / iparm /    iptsmx, iratpo, iwalce, iwuoce, iwurce,
     *                    ipwxl2, ipexlm, iph2lm, ipoxth,
     *                    ilayer, inelms, ipttmo
c  end of couple a array pointers.
c
      common / iparm /       idf, idhint, iflagc, iflagr, iflagt,
     1                    ifluid,    iov,  istep,  itran,    itx,
     2                     ivsol, iupwnd,   last,  lhead,   line,
     3                    matflu,   maxe,   maxi,   maxj,  mband,
     4                     mcond,    mld,   mnpo,    mpp,    mud,
     5                      ncev, ncevr5, neltop,   nfnt,  nftot,
     6                     ngenm,  niter,  nline,   nmax,   nmtl,
     7                      nnli, npdtbi, npdtbo,    npp,   nrad,
     8             nslph, nspdeb,  nttem,  numel,  numhc, nummat,
     9                     numnp,  numrc,  numtc,  numvt, nunqsw,
     #             ncpow, natrop, ncrlay,  ncld, istcou,
     a                    mcme41
c  end of couple non-pointer integers.
c
      integer                 i5,     i6,     i7,     i8,     i9,
     1       i10,    i20,    i21,    i22,    i27,    i28,    i29,
     2       i40,    i41,    i42,    i43,    i44,    i45,    i46,
     3       i47,    i48,    i49,    i50,    i51,    i60,    i61,
     4       i62,    i70,    i72,    i74,    i76,    i78,    i80,
     5       i82,    i84,    i86,    i88,    i90,    i99,   i100,
     6      i102,   i103,   i104,   i105,   i107,   i108,   i109,
     7      i110,   i111,   i112,   i113,   i114,   i115,
     8    icompt, idetop, igmcpt, igmopt, ihtcto, inetco,
     *    inodpt, inussn,  ipafp,  ipbfp, ipfrto,
     9            iptalf, iptars, iptcdf, iptsif, ipteij, iptfml,
     a     iptfp, iptfpv, iptgav, ipthfs, ipthtm, iptiel, iptihs,
     b    iptjel, iptkfr, iptkfz, iptlif, iptmdt, iptmet, iptmlt,
     c    iptspd, iptspl, ipttsm, iqcopt, iqfopt, iqolpt, iqotpt,
     d    iqwcpt,  ir5pt, itsink, ivcnpt, ivfspt, ivrapt, ivrdpt,
     e        m1,     m2,     m3,     m4,     m5,     m6,     m7,
     f        m8,     m9,    m10,    m12,    m13,    m14,    m15,
     g        n1,     n2,     n3,     n4,     n5,     n6,     n7,
     # n20,n100,n101,n102,n103,n132,n150,iptnbu,ipxfp
      integer     iptsmx, iratpo, iwalce, iwuoce, iwurce,
     *            ipwxl2, ipexlm, iph2lm, ipoxth,
     *            ilayer, inelms, ipttmo
c
      integer                idf, idhint, iflagc, iflagr, iflagt,
     1                    ifluid,    iov,  istep,  itran,    itx,
     2                     ivsol, iupwnd,   last,  lhead,   line,
     3                    matflu,   maxe,   maxi,   maxj,  mband,
     4                     mcond,    mld,   mnpo,    mpp,    mud,
     5                      ncev, ncevr5, neltop,   nfnt,  nftot,
     6                     ngenm,  niter,  nline,   nmax,   nmtl,
     7                      nnli, npdtbi, npdtbo,    npp,   nrad,
     8                     nslph, nspdeb,  nttem,  numel,  numhc,
     9                    nummat,  numnp,  numrc,  numtc,  numvt,
     *                    nunqsw,  ncpow, natrop, ncrlay,   ncld,
     #                    istcou,
     a                    mcme41
c
      integer iparm(nipar3)
      equivalence (iparm(1), i5)
c
*endif
