*mlist
*comdeck blkage
c
c  blkage contains control blade masses.
c
c  Cognizant engineer: ewc (fpg).
c
*if def,selap
c  ****** Beginning of timestep variables for timestep repetition ******
      real            ablz  , almz  , alppz , bblz  , fsszrz, sblksz,
     1                tblkz , tblkoz, wfz   , xsszzi, xsszzo
c  ****** End of timestep variables for timestep repetition ************
      real            abl   , alm   , alpp  , bbl   , fsszr , sblkss,
     1                tblk  , tblko , wf    , xsszri, xsszro
c  ****** Beginning of timestep variables for timestep repetition ******
      integer         nblz
c  ****** End of timestep variables for timestep repetition ************
      integer         nbl   , mcme88
c  ****** Beginning of timestep variables for timestep repetition ******
      common /blkage/ ablz(10,3,2,6) , almz(10,6)     , alppz(10,6) ,
     1                bblz(10,2,6)   , fsszrz(ndax,2,6) ,
     2                sblksz(2,6)   , tblkz(ndax,2,6,10)       ,
     3                tblkoz(ndax,2,6,10)      , wfz(5,6)       ,
     4                xsszzi(ndax,2,6), xsszzo(ndax,2,6)
c  ****** End of timestep variables for timestep repetition ************
      common /blkage/ abl(10,3,2,6) , alm(10,6)     , alpp(10,6) ,
     1                bbl(10,2,6)   , fsszr(ndax,2,6) ,
     2                sblkss(2,6)   , tblk(ndax,2,6,10)       ,
     3                tblko(ndax,2,6,10)      , wf(5,6)       ,
     4                xsszri(ndax,2,6), xsszro(ndax,2,6)
c  ****** Beginning of timestep variables for timestep repetition ******
      common /blkage/ nblz(ndax,2,6)
c  ****** End of timestep variables for timestep repetition ************
      common /blkage/ nbl(ndax,2,6)   , mcme88
*endif
