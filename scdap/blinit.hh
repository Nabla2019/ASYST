*mlist
*comdeck blinit
c
c
c  blinit contains data for the B4C control blade geometry.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c
c  BWR control blade/channel box temperature array locations:
c
c           Segment 2                  Segment 1
c
c  |--------------------------|--------------------------|
c  |    twscan(i,2,j)         |    twscan(i,1,j)         | Channel box
c  |    tblk  (i,2,j,6)       |    tblk  (i,1,j,6)       | crust
c  |    tblko (i,2,j,6)       |    tblko (i,1,j,6)       |
c  |--------------------------|--------------------------|
c  |    tbox  (i,2,j)         |    tbox  (i,1,j)         |
c  |    tboxo (i,2,j)         |    tboxo (i,1,j)         | Channel box
c  |    tblk  (i,2,j,5)       |    tblk  (i,1,j,5)       |
c  |    tblko (i,2,j,5)       |    tblko (i,1,j,5)       |
c  |--------------------------|--------------------------|
c  |    twscbb(i,2,j)         |    twscbb(i,1,j)         | Control blade
c  |    tblk  (i,2,j,4)       |    tblk  (i,1,j,4)       | crust
c  |    tblko (i,2,j,4)       |    tblko (i,1,j,4)       |
c  |..........................|--------------------------|
c  |                          |    tcb3  (i,  j)         |
c  |                          |    tcb3o (i,  j)         | Blade sheath
c  |    tblk  (i,2,j,3)       |    tblk  (i,1,j,3)       |
c  |    tblko (i,2,j,3)       |    tblko (i,1,j,3)       |
c  |..........................|--------------------------|
c  |                          |    tcb2  (i,  j)         |
c  |                          |    tcb2o (i,  j)         | Absorber
c  |    tblk  (i,2,j,2)       |    tblk  (i,1,j,2)       | rodlets
c  |    tblko (i,2,j,2)       |    tblko (i,1,j,2)       |
c  |..........................|--------------------------|
c  |                          |    tcb1  (i,  j)         |
c  |                          |    tcb1o (i,  j)         | B4C absorber
c  |    tblk  (i,2,j,1)       |    tblk  (i,1,j,1)       |
c  |    tblko (i,2,j,1)       |    tblko (i,1,j,1)       |
c  |--------------------------|--------------------------|
c
c  Where:
c    i = Axial node index
c    j = BWR blade/box sequence index
c
c  Notes:
c    All temperatures have units of degrees F
c    tcb1, tcb2, tcb3, tbox are temperatures of intact structures at
c      current time
c    twscbb, twscan are temperatures of any molten material relocating
c      downward at current time
c    tblk contains unique temperatures only at a location where an
c      interstitial blockage exists (iblkcb=2); otherwise tblk contains
c      temperatures of adjacent intact structures
c    tcb1o, tcb2o, tcb3o, tboxo, tblko are temperatures at old time and
c      are assigned values at end of timestep in subroutine baxial
c
c  ****** Beginning of timestep variables for timestep repetition ******
      real            boxtz , cellcz,celcbz, csacz , csaczo,
     1                csafz , csafzo, fbxz  , fcb1z , fcb23z,
     1                qblaz1, qblaz3, scbz  ,
     2                scnz  , tbxmxz, tcb1z , tcb2z , tcb3z , tcb1oz,
     3                tcb2oz, tcb3oz, tfb4cz, tmwcz1, tmwcz3
c  ****** End of timestep variables for timestep repetition ************
      real            boxt  , cellca,celcba, csacb , csacbo,
     1                csafu , csafuo, fbx   , fcb1  , fcb23,
     1                qblad1, qblad3, scb   ,
     2                scn   , tbxmx , tcb1  , tcb2  , tcb3  , tcb1o ,
     3                tcb2o , tcb3o , tfb4cr, tmwcb1, tmwcb3
c  ****** Beginning of timestep variables for timestep repetition ******
      integer         iblkz , iblkzb, icbz  , mprt5z, mprt6z, mtot5z
c  ****** End of timestep variables for timestep repetition ************
      integer         iblkc , iblkcb, icb   , mprt5 , mprt6 , mtot56,
     1                mcme87
c  ****** Beginning of timestep variables for timestep repetition ******
      common /blinit/ boxtz(6)  , cellcz(2,6)     , celcbz(2,6)    ,
     1      csacz(ndax,6),csaczo(ndax,6),csafz(ndax,6),csafzo(ndax,6),
     1      fbxz(ndax,2,6)   , fcb1z(ndax,6)    , fcb23z(ndax,6),
     2                qblaz1(6)     , qblaz3(6),
     4      scbz(ndax,6)     , scnz(ndax,2,6)   ,
     5      tbxmxz(ndax,2,6) , tcb1z(ndax,6)    , tcb2z(ndax,6)    ,
     6      tcb3z(ndax,6)    , tcb1oz(ndax,6)   , tcb2oz(ndax,6)   ,
     7      tcb3oz(ndax,6)   , tfb4cz(6), tmwcz1(6), tmwcz3(6)
c  ****** End of timestep variables for timestep repetition ************
      common /blinit/ boxt(6)  , cellca(2,6)     , celcba(2,6)    ,
     1      csacb(ndax,6),csacbo(ndax,6),csafu(ndax,6),csafuo(ndax,6),
     1      fbx(ndax,2,6)   , fcb1(ndax,6)    , fcb23(ndax,6),
     2                qblad1(6)     , qblad3(6),
     4      scb(ndax,6)     , scn(ndax,2,6)   ,
     5      tbxmx(ndax,2,6) , tcb1(ndax,6)    , tcb2(ndax,6)    ,
     6      tcb3(ndax,6)    , tcb1o(ndax,6)   , tcb2o(ndax,6)   ,
     7      tcb3o(ndax,6)   , tfb4cr(6), tmwcb1(6), tmwcb3(6)
c  ****** Beginning of timestep variables for timestep repetition ******
      common /blinit/ iblkz(ndax,2,6) , iblkzb(ndax,2,6),
     1                icbz(ndax,3,6)  , mprt5z(6), mprt6z(6), mtot5z(6)
c  ****** End of timestep variables for timestep repetition ************
      common /blinit/ iblkc(ndax,2,6) , iblkcb(ndax,2,6),
     1                icb(ndax,3,6)   , mprt5(6) , mprt6(6) , mtot56(6),
     2                mcme87
*endif
