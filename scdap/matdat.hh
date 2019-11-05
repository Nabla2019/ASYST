*mlist
!  Contains fuel rod and shroud material data.
!
!  Cognizant engineer: ewc.
!
*if def,selap
       integer, parameter :: imax=14,mxmatd=10
!  imax     maximum number of user defined materials.
!  mxmatd   maximum number of data points for materials.
       common /matdat/ ttemp,tcp,tro,tk,teps,texp,epsz,facmot,fotmtl,
     & fraden,flux,coldw,tfshrd,zfshrd,fmshrd,cmshrd,markmx,imshrd,
     & ifshrd,umgntno,umgntni,shcpflg,mcme44
       real ttemp(mxmatd,imax),tcp(mxmatd,imax),tro(mxmatd,imax),
     & tk(mxmatd,imax),teps(mxmatd,imax),texp(mxmatd,imax),epsz,facmot,
     & fotmtl,fraden,flux,coldw,tfshrd,zfshrd,fmshrd,cmshrd
       integer markmx(imax),imshrd,ifshrd,umgntno(3,imax),
     & umgntni(3,imax),mcme44
       logical shcpflg
!  ttemp   temperature array for thermal properties of user defined
!          materials.
!  tcp     specific heat for user defined material.
!  tro     density for user defined material.
!  tk      conductivity for user defined material.
!  teps    material emissivity.
!  texp    material thermal expansion.
!  markmx  number of data points for user defined material.
!
!  imshrd  material indicator for shroud insulation.
!  tfshrd  time at which shroud fails (s).
!  zfshrd  elevation above which shroud fails (m)
!  fmshrd  multiplier on conductivity of failed shroud.
!  cmshrd  multiplier on heat capacity of failed shroud.
!  ifshrd  switch indicating whether shroud has failed or not: 0 = no,
!          1 = yes.
!  umgntno Holds general table numbers for user supplied materials:
!          first subscript is 1:3 to indicate specific heat, density, or
!          thermal conductivity, second subscript is index in tables.
!  umgntni Index to general table: first subscript is for type of 
!          property, second subscript is for material number.
!  shcp    shroud heat capacity flag: true when a multiplier is entered 
!          in the input deck W5 in card 40CC5000
*endif
