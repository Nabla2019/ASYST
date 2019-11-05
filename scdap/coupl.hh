*mlist
*comdeck coupl
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c
       common /coupl/ afrdeb(maxcon,maxcpm), dtcoup(maxcpm),
     1  hgtdeb(maxcpm), pdmave(maxcpm), porave(maxcpm),
     2  powave(maxcpm), powdmx(maxcpm), pdbtot(maxcpm), stmass(maxcpm),
     3  tave(maxcpm),   timc(maxcpm), tmpdmx(maxcpm),
     4  tmpdav(maxcpm), twalav(maxcpm), twalmx(maxcpm), wtmdeb(maxcpm),
     5  ws(maxcon,maxcpm), wst(maxcon,maxcpm),
     *  pmufot(maxcpm), pmufdk(maxcpm), pmuadk(maxcpm),
     *  qfrspi(19,maxcpm),
     #  conhtc,icntmp,icnvol,icnlvl,icnvar,
     6  icoup(maxcpm),   invc(maxcpm),   itsc(maxcpm),
     7  mcostr(maxcpm), ncdtsl(maxcpm),  ncslp(maxcpm),
     8  ncpowi(maxcpm), ncvolc(maxcpm), npowdm(maxcpm),
     9  ntmpdm(maxcpm),   ntsc(maxcpm),
     #  ntwalm(maxcpm), nmcpwr, nrecno, kpr,
     #  mcme19
       real afrdeb, dtcoup, hgtdeb, pdmave, porave, powave, pdbtot,
     *      powdmx, stmass, tave, timc, tmpdmx, twalmx, wtmdeb, ws, wst
       real pmufot, pmufdk, pmuadk, qfrspi
       real tmpdav, twalav, conhtc
       integer icoup, invc, itsc, mcostr, ncdtsl, ncslp, ncvolc,
     #         ncpowi, kpr, icnvol,icnlvl,icnvar,icntmp,
     *         npowdm, ntmpdm, ntsc, ntwalm, nmcpwr, nrecno,  mcme19
*endif
