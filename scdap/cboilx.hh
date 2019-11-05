*mlist
*comdeck cboilx
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c  ****** Beginning of timestep variables for timestep repetition ******
      real            diab4z, drrcaz, fb4cmz, fccbrz, fwsssz, fwzrzz,
     1                hdzz  , hsmshz, hzmbhz, rhob4z,
     2                rhoclz, rocldz, rhosz , rhoszl, tcaniz,
     3                tcbiz , thkcbz, thkgaz, thkszi, thkszo,
     4                voidmz,
     5                xboxz , xboxcz, xbozzi,
     6                xbozzo, xcbdoz, xcbsz2, xcbsz3
c  ****** End of timestep variables for timestep repetition ************
      real            diab4c, drrcan, fb4cmx, fccbr , fwssss, fwzrzr,
     1                hdz   , hfssb , hfsszr, hfzirc, hsmshr, hzmbhr,
     2                rhob4c, rhocld, rocldl, rhoss , rhossl, tcani ,
     3                tcbi  , thkcb , thkgap, thkssi, thksso,
     4                teutec, tmelbx, tmelcb, tmelss, tmlszr, voidmx,
     5                xbox  , xboxcb, xboxzi,
     6                xboxzo, xcbdo , xcbss2, xcbss3
c  ****** Beginning of timestep variables for timestep repetition ******
      integer         iaxz  , imwboz, imwb4z, imwssz, iradrz,
     1                iscbz , iscnz , mw1z  , mw2z  ,
     2                nabroz, ndzz
c  ****** End of timestep variables for timestep repetition ************
      integer         iax   , imwbox, imwb4c, imwss , iradrx,
     1                iscb  , iscn  , mw1   , mw2   ,
     2                nabrod, ndz   , mcme89
c  ****** Beginning of timestep variables for timestep repetition ******
      common /cboilx/ diab4z(6),drrcaz(6),fb4cmz,fccbrz(2,6),fwsssz,
     1                fwzrzz, hdzz(ndax,6)    , hsmshz,
     2                hzmbhz, rhob4z,
     5                rhoclz,rocldz, rhosz , rhoszl, tcaniz(ndax)     ,
     6                tcbiz(ndax), thkcbz(6), thkgaz(6),
     7                thkszi(6), thkszo(6),
     8                voidmz,
     9                xboxz(6), xboxcz(6), xbozzi(6), xbozzo(6),
     a                xcbdoz(6), xcbsz2(6), xcbsz3(6)
c  ****** End of timestep variables for timestep repetition ************
      common /cboilx/ diab4c(6), drrcan(6), fb4cmx, fccbr(2,6), fwssss,
     1                fwzrzr, hdz(ndax,6)    , hfssb  , hfsszr, hfzirc,
     2                hsmshr, hzmbhr, rhob4c,
     5                rhocld,rocldl, rhoss , rhossl, tcani(ndax)     ,
     6                tcbi(ndax), thkcb(6), thkgap(6),
     7                thkssi(6), thksso(6), teutec, tmelbx, tmelcb,
     8                tmelss, tmlszr, voidmx,
     9                xbox(6), xboxcb(6), xboxzi(6), xboxzo(6),
     a                xcbdo(6), xcbss2(6), xcbss3(6)
c  ****** Beginning of timestep variables for timestep repetition ******
      common /cboilx/ iaxz  , imwboz, imwb4z, imwssz, iradrz,
     c                iscbz(ndax,6)    , iscnz(ndax,6)    ,
     d                mw1z  , mw2z  , nabroz(6), ndzz(6)
c  ****** End of timestep variables for timestep repetition ************
      common /cboilx/ iax   , imwbox, imwb4c, imwss , iradrx,
     c                iscb(ndax,6)    , iscn(ndax,6)    ,
     d                mw1   , mw2   , nabrod(6), ndz(6) , mcme89
*endif
