*mlist
*comdeck axtrns
c
c
c  Descriptive sentence for axtrns goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c  ****** Beginning of timestep variables for timestep repetition ******
      real            ai1z  , ao1z  , axz   , boxlz , cblz  , csaboz,
     1                csab4z, csaszi, csaszo, c1z   , c2z   , c3z   ,
     2                c4z   , c5z   , c6z   , c7z   , db2o3z, dcoz  ,
     3                dco2z , dch4z , dh2z  , emisbz, emiscz, emisvz,
     4                fboxmz, fbzmz , fcbmz , fcbzmz, ffeb4z, hsboz ,
     5                hsrcbz, qboxz , qbxazm, qbxazp, qbsavz, qcanz ,
     6                qcbazm, qcbazp, qcbsaz, qcb1z , qcb2z , qcb3z ,
     7                qradzb, qradzc, qsszrz, tfboxz, tfcbrz, tmwbxz,
     8                tboxz , tboxoz, wb4crz, wb4csz,
     8                wobozi, wobozo, xazbzi, xazbzo, xboxiz,
     9                xboxoz, xcb3oz, xcb3iz, xcb2oz, xcb2iz, xfeb4z
c  ****** End of timestep variables for timestep repetition ************
      real            ai1   , ao1   , ax    , boxl  , cbl   , csabox,
     1                csab4c, csassi, csasso, c1    , c2    , c3    ,
     2                c4    , c5    , c6    , c7    , db2o3 , dco   ,
     3                dco2  , dch4  , dh2   , emisbo, emiscb, emisvo,
     4                fboxm , fbzm  , fcbm  , fcbzm , ffeb4c, hsbo  ,
     5                hsrcb , qbox  , qbxaxm, qbxaxp, qbsav , qcan  ,
     6                qcbaxm, qcbaxp, qcbsav, qcb1  , qcb2  , qcb3  ,
     7                qradrb, qradrc, qsszrx, tfbox2, tfcbr , tmwbx ,
     8                tbox  , tboxo , wb4crx, wb4csv,
     8                woboxi, woboxo, xazbxi, xazbxo, xboxi ,
     9                xboxo , xcb3oo, xcb3io, xcb2oo, xcb2io, xfeb4c
c
      integer         mcme84
c  ****** Beginning of timestep variables for timestep repetition ******
      common /axtrns/ ai1z(2), ao1z(2), axz(2), boxlz(2,6), cblz(6),
     1                csaboz(2,6), csab4z(6), csaszi(6), csaszo(6), c1z,
     2                c2z   , c3z   , c4z   , c5z   , c6z   , c7z   ,
     3                db2o3z, dcoz  , dco2z , dch4z , dh2z  ,
     4            emisbz(ndax,2,6), emiscz(ndax,6)  , emisvz(ndax,2,6),
     5            fboxmz(ndax,2,6) , fbzmz , fcbmz(ndax,6)    , fcbzmz,
     6            ffeb4z(ndax,6)  , hsboz(2)       , hsrcbz,
     7                qboxz(2)       , qbxazm(2)     ,
     8                qbxazp(2)     , qbsavz(2) , qcanz(6) , qcbazm(3),
     9                qcbazp(3)     , qcbsaz(3), qcb1z , qcb2z , qcb3z,
     a            qradzb(2),qradzc, qsszrz(ndax,2,6), tfboxz(6),
     b            tfcbrz(6),tmwbxz(6),tboxz(ndax,2,6),tboxoz(ndax,2,6),
     b            wb4crz(ndax,6)  , wb4csz(ndax,6)  ,
     c            wobozi(ndax,2,6), wobozo(ndax,2,6), xazbzi(ndax,2,6),
     d            xazbzo(ndax,2,6), xboxiz(ndax,2,6), xboxoz(ndax,2,6),
     e            xcb3oz(ndax,6)  , xcb3iz(ndax,6)  , xcb2oz(ndax,6)  ,
     f            xcb2iz(ndax,6)  , xfeb4z(ndax,6)
c  ****** End of timestep variables for timestep repetition ************
      common /axtrns/ ai1(2), ao1(2), ax(2) , boxl(2,6)     , cbl(6),
     1                csabox(2,6), csab4c(6), csassi(6), csasso(6), c1,
     2                c2    , c3    , c4    , c5    , c6    , c7    ,
     3                db2o3 , dco   , dco2  , dch4  , dh2   ,
     4            emisbo(ndax,2,6), emiscb(ndax,6)  , emisvo(ndax,2,6),
     5            fboxm(ndax,2,6) , fbzm  , fcbm(ndax,6)    , fcbzm ,
     6            ffeb4c(ndax,6)  , hsbo(2)       , hsrcb ,
     7                qbox(2)       , qbxaxm(2)     ,
     8                qbxaxp(2)     , qbsav(2) , qcan(6)  , qcbaxm(3) ,
     9                qcbaxp(3)     , qcbsav(3), qcb1  , qcb2  , qcb3 ,
     a            qradrb(2),qradrc, qsszrx(ndax,2,6), tfbox2(6),
     b            tfcbr(6),tmwbx(6),tbox(ndax,2,6)  , tboxo(ndax,2,6) ,
     b            wb4crx(ndax,6)  , wb4csv(ndax,6)  ,
     c            woboxi(ndax,2,6), woboxo(ndax,2,6), xazbxi(ndax,2,6),
     d            xazbxo(ndax,2,6), xboxi(ndax,2,6) , xboxo(ndax,2,6) ,
     e            xcb3oo(ndax,6)  , xcb3io(ndax,6)  , xcb2oo(ndax,6)  ,
     f            xcb2io(ndax,6)  , xfeb4c(ndax,6)  , mcme84
*endif
