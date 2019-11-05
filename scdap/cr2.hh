*mlist
*comdeck cr2
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c  ****** Beginning of timestep variables for timestep repetition ******
      real            gonb4z, gonssz,
     1                smb4cz, sumssz, sumzzi, sumzz1, sumzz2,
     1                sumzz3, sumzz4, sumzz5, tssczi, tssczo, tsscbz,
     2                twcb1z, twcb2z, twcb3z, twscaz, twscbz, twzcaz,
     3                tzrcnz, wb2o3z, wbz   , wcz   , wb4cz , wfe2oz,
     4                wfe2iz, wfe3oz, wfe3iz, wsscaz, wsscnz, wsscz ,
     5                wssczb, wssczi, wzcaz , wzcazi, zxxxxz,
     6                tmlbuz, wssbuz, wzrbuz
       real wcrdbz, wcrdzs, wcrdzo, wplabz, wplazs, wplazo,
     &      wnozbc, wnozss, wnozso, wnozzr, wnozzo,
     &      enrcrz, enrplz, enrnoz
c  ****** End of timestep variables for timestep repetition ************
      real            gonb4c, gonss ,
     1                smb4ci, sumssi, sumzci, sumzc1, sumzc2,
     1                sumzc3, sumzc4, sumzc5,tsscni,tsscno,tsscbo,
     2                twcb1 , twcb2 , twcb3 , twscan, twscbb, twzcan,
     3               tzrcni, wb2o3 , wb    , wc    , wb4c  , wfe2o ,
     4                wfe2i , wfe3o , wfe3i , wsscan,wsscno, wsscb ,
     5                wsscbb, wsscbi, wzcan , wzcani, zxxxxx,
     6                tmlbun, wssbun, wzrbun
       real wcrdbc, wcrdss, wcrdso, wplabc, wplass, wplaso,
     &      wnosbc, wnosss, wnosso, wnoszr, wnoszo,
     &      enrcrd, enrpla, enrnos
c
      integer         mcme90
c  ****** Beginning of timestep variables for timestep repetition ******
      common /cr2/    gonb4z(6), gonssz(6) ,
     1                smb4cz(6), sumssz(6), sumzzi(6), sumzz1, sumzz2,
     1                sumzz3, sumzz4, sumzz5,
     1                tssczi(6),tssczo(6),tsscbz(6),
     2                twcb1z, twcb2z, twcb3z, twscaz(ndax,2,6),
     3          twscbz(ndax,2,6), twzcaz(2)     ,tzrcnz(6),
     4          wb2o3z(ndax,6)  , wbz(ndax,6)    , wcz(ndax,6)      ,
     5          wb4cz(ndax,6)   , wfe2oz(ndax,6) , wfe2iz(ndax,6)   ,
     6          wfe3oz(ndax,6)  , wfe3iz(ndax,6) ,
     7          wsscaz(ndax,2,6,11,2)   , wsscnz(ndax,6,11,2)    ,
     8          wsscz(ndax,6,7,2)       , wssczb(ndax,6,11,2)     ,
     9          wssczi(ndax,6,2)        , wzcaz(ndax,2,6,7)       ,
     a          wzcazi(ndax,2,6), zxxxxz(ndax,6)  , tmlbuz(ndax,2,6),
     b          wssbuz(ndax,2,6), wzrbuz(ndax,2,6),
     c      wcrdbz(6), wcrdzs(6), wcrdzo(6),
     &      wplabz(6), wplazs(6), wplazo(6),
     &      wnozbc(6), wnozss(6), wnozso(6), wnozzr(6), wnozzo(6),
     &      enrcrz(6), enrplz(6), enrnoz(6)
c  ****** End of timestep variables for timestep repetition ************
      common /cr2/    gonb4c(6), gonss(6) ,
     1                smb4ci(6), sumssi(6), sumzci(6), sumzc1, sumzc2,
     1                sumzc3, sumzc4, sumzc5,
     1                tsscni(6),tsscno(6),tsscbo(6),
     2                twcb1 , twcb2 , twcb3 , twscan(ndax,2,6),
     3          twscbb(ndax,2,6), twzcan(2)     ,tzrcni(6),
     4          wb2o3(ndax,6)   , wb(ndax,6)      , wc(ndax,6)      ,
     5          wb4c(ndax,6)    , wfe2o(ndax,6)   , wfe2i(ndax,6)   ,
     6          wfe3o(ndax,6)   , wfe3i(ndax,6)   ,
     7          wsscan(ndax,2,6,11,2)   , wsscno(ndax,6,11,2)    ,
     8          wsscb(ndax,6,7,2)       , wsscbb(ndax,6,11,2)     ,
     9          wsscbi(ndax,6,2)        , wzcan(ndax,2,6,7)       ,
     a          wzcani(ndax,2,6), zxxxxx(ndax,6)  , tmlbun(ndax,2,6),
     b          wssbun(ndax,2,6), wzrbun(ndax,2,6),
     c      wcrdbc(6), wcrdss(6), wcrdso(6),
     &      wplabc(6), wplass(6), wplaso(6),
     &      wnosbc(6), wnosss(6), wnosso(6), wnoszr(6), wnoszo(6),
     &      enrcrd(6), enrpla(6), enrnos(6), mcme90
c
c  BWR control blade/channel box mass array locations:
c
c           Segment 2                  Segment 1
c
c  |--------------------------|--------------------------|
c  |    wsscan(i,2,j,1-11,1)  |    wsscan(i,1,j,1-11,1)  | Channel box
c  |  + wsscan(i,2,j,1-11,2)  |  + wsscan(i,1,j,1-11,2)  | crust
c  |  + wzcan (i,2,j,4-7 )    |  + wzcan (i,1,j,4-7 )    |
c  |--------------------------|--------------------------|
c  |                          |                          |
c  |    wzcan (i,2,j,1-3 )    |    wzcan (i,1,j,1-3 )    | Channel box
c  |                          |                          |
c  |--------------------------|--------------------------|
c  |                          |                          |
c  |    wsscno(i,  j,1-11,1)  |    wsscbb(i,  j,1-11,1)  | Control blade
c  |  + wsscno(i,  j,1-11,2)  |  + wsscbb(i,  j,1-11,2)  | crust
c  |                          |                          |
c  |                          |--------------------------|
c  |                          |    wsscb (i,  j,1-7, 1)  |
c  |                          |  + wfe3o (i,  j)         | Blade sheath
c  |                          |  + wfe3i (i,  j)         |
c  |                          |--------------------------|
c  |                          |    wsscb (i,  j,1-7, 2)  | Absorber
c  |                          |  + wfe2o (i,  j)         | rodlets
c  |                          |  + wfe2i (i,  j)         |
c  |                          |--------------------------|
c  |                          |    wb4c  (i,  j)         |
c  |                          |  + wb2o3 (i,  j)         | B4C absorber
c  |                          |  + wb    (i,  j)         |
c  |                          |  + wc    (i,  j)         |
c  |--------------------------|--------------------------|
c
c  Where:
c    i = Axial node index
c    j = BWR blade/box sequence index
c
c  Mass array            Definition
c  --------------------  -----------------------------------------------
c  wb4c  (i,  j)         B4C in absorber
c  wb2o3 (i,  j)         B2O3 in absorber
c  wb    (i,  j)         B in absorber
c  wc    (i,  j)         C in absorber
c  --------------------  -----------------------------------------------
c  wsscb (i,  j,1-7, 2)  SS constituents in absorber rodlets
c  wsscb (i,  j,1-7, 1)  SS constituents in blade sheath
c                1           Fe in unreacted portion
c                2           Cr
c                3           Ni
c                4           FeO
c                5           Fe3O4
c                6           Cr2O3
c                7           NiO
c  --------------------  -----------------------------------------------
c  wfe2o (i,  j)         Fe in reacted portion of abs. rodlets (outside)
c  wfe2i (i,  j)         Fe in reacted portion of abs. rodlets (inside)
c  wfe3o (i,  j)         Fe in reacted portion of blade sheath (outside)
c  wfe3i (i,  j)         Fe in reacted portion of blade sheath (inside)
c  --------------------  -----------------------------------------------
c  wsscbb(i,  j,1-11,1)  Molten SS constituents in blade crust (seg. 1)
c  wsscbb(i,  j,1-11,2)  Solid SS constituents in blade crust (seg. 1)
c  wsscno(i,  j,1-11,1)  Molten SS constituents in blade crust (seg. 2)
c  wsscno(i,  j,1-11,2)  Solid SS constituents in blade crust (seg. 2)
c                1           Fe
c                2           Cr
c                3           Ni
c                4           FeO
c                5           Fe3O4
c                6           Cr2O3
c                7           NiO
c                8           B4C
c                9           B2O3
c                10          B
c                11          C
c  --------------------  -----------------------------------------------
c  wzcan (i,1,j,1-3 )    Zircaloy constituents in channel box (seg. 1)
c  wzcan (i,2,j,1-3 )    Zircaloy constituents in channel box (seg. 2)
c                1           Solid Zr
c                2           Solid ZrO2
c                3           Molten Zr
c  --------------------  -----------------------------------------------
c  wzcan (i,1,j,4-7 )    Zircaloy constituents in box crust (seg. 1)
c  wzcan (i,2,j,4-7 )    Zircaloy constituents in box crust (seg. 2)
c                4           Solid Zr
c                5           Molten Zr
c                6           ZrO2 associated with solid Zr
c                7           ZrO2 associated with molten Zr
c  --------------------  -----------------------------------------------
c  wsscan(i,1,j,1-11,1)  Molten SS constituents in box crust (seg. 1)
c  wsscan(i,1,j,1-11,2)  Solid SS constituents in box crust (seg. 1)
c  wsscan(i,2,j,1-11,1)  Molten SS constituents in box crust (seg. 2)
c  wsscan(i,2,j,1-11,2)  Solid SS constituents in box crust (seg. 2)
c                1           Fe
c                2           Cr
c                3           Ni
c                4           FeO
c                5           Fe3O4
c                6           Cr2O3
c                7           NiO
c                8           B4C
c                9           B2O3
c                10          B
c                11          C
c  --------------------  -----------------------------------------------
c
*endif
