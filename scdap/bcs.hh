*mlist
*comdeck bcs
c
c
c  bcs contains control blade model geometry data.
c
c  Cognizant engineer: ewc (fpg).
c
*if def,selap
c  ****** Beginning of timestep variables for timestep repetition ******
      real            dwhz  , dwhbxz, dwhoz , dwhobz, dwhocz, dwsz  ,
     1                dwsbxz, dwsoz , dwsobz, dwsocz
c  ****** End of timestep variables for timestep repetition ************
      real            dwh   , dwhbx , dwho  , dwhobx, dwhocb, dws   ,
     1                dwsbx , dwso  , dwsobx, dwsocb,
     2                hwboxi, hwboxo, hwcb  , qrdrbx,
     3                tsinki, tsinko, voidi , voido , wari  , waroo ,
     4                whi   , whoo  , wsi   , wsoo
c
      integer         mcme85
c  ****** Beginning of timestep variables for timestep repetition ******
      common /bcs/  dwhz(ndax)    , dwhbxz(ndax,2), dwhoz(ndax)     ,
     1              dwhobz(ndax,2), dwhocz(ndax)  , dwsz(ndax)      ,
     2              dwsbxz(ndax,2), dwsoz(ndax)   , dwsobz(ndax,2)  ,
     3              dwsocz(ndax)
c  ****** End of timestep variables for timestep repetition ************
      common /bcs/  dwh(ndax)     , dwhbx(ndax,2) , dwho(ndax)      ,
     1              dwhobx(ndax,2), dwhocb(ndax)  , dws(ndax)       ,
     2              dwsbx(ndax,2) , dwso(ndax)    , dwsobx(ndax,2)  ,
     3              dwsocb(ndax)  ,
     4              hwboxi(ndax)  , hwboxo(ndax)  , hwcb(ndax)      ,
     5              qrdrbx(ndax,2) ,
     6              tsinki(ndax)  , tsinko(ndax)  , voidi(ndax)     ,
     7              voido(ndax)   , wari(ndax)    , waroo(ndax)     ,
     8              whi(ndax)     , whoo(ndax)    , wsi(ndax)       ,
     9              wsoo(ndax)    , mcme85
*endif
