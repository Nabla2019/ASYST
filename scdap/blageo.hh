*mlist
*if def,selap
c
c  blageo is the bwr control blade/channel box geometric data comdeck.
c
c  Cognizant engineer: ewc.
c
c  ****** Beginning of timestep variables for timestep repetition ******
      real blawdz,dfasz1,dfasz2,fboxfz,flnrtz,mcfsz ,mcfspz,mctfz ,
     *     mctfzp,mssfz ,mssfzp,mzrfz ,mzrfzp,qrsegz,tkmszz,wpsuz1,
     *     wpsuz2
c  ****** End of timestep variables for timestep repetition ************
      real blawd ,dfasr1,dfasr2,fboxfs,flnrt ,mcfs  ,mcfsp ,mctfs ,
     *     mctfsp,mssfs ,mssfsp,mzrfs ,mzrfsp,qrseg2,tkmszr,wpsur1,
     *     wpsur2
c  ****** Beginning of timestep variables for timestep repetition ******
       integer cmpfsz,iblabz,iblfz ,iblfzp,icblaz,itimzc,itimzf,
     & nblabz
c  ****** End of timestep variables for timestep repetition ************
      integer cmpfs ,iblabx,iblfs ,iblfsp,icbla ,itimec,itimef,
     *        nblabx,ngps  ,ncmpgs,nraden,numfs ,mcme86
c  ****** Beginning of timestep variables for timestep repetition ******
      common /blageo/ blawdz(ndcomp),
     *  dfasz1(ndax*ndcomp)    ,dfasz2(ndax*ndcomp),
     *  fboxfz(2,ndcomp,ndcomp),flnrtz(2*ndax*ndcomp),
     *  mcfsz(ndax,ndcomp)     ,mcfspz(ndax,ndcomp),
     *  mctfz(ndax,ndcomp)     ,mctfzp(ndax,ndcomp),
     *  mssfz(ndax,ndcomp)     ,mssfzp(ndax,ndcomp),
     *  mzrfz(ndax,ndcomp)     ,mzrfzp(ndax,ndcomp),
     *  qrsegz(2*ndax*ndcomp)  ,tkmszz,
     *  wpsuz1(ndax*ndcomp)    ,wpsuz2(ndax*ndcomp)
c  ****** End of timestep variables for timestep repetition ************
      common /blageo/ blawd(ndcomp),
     *  dfasr1(ndax*ndcomp)    ,dfasr2(ndax*ndcomp),
     *  fboxfs(2,ndcomp,ndcomp),flnrt(2*ndax*ndcomp),
     *  mcfs(ndax,ndcomp)      ,mcfsp(ndax,ndcomp),
     *  mctfs(ndax,ndcomp)     ,mctfsp(ndax,ndcomp),
     *  mssfs(ndax,ndcomp)     ,mssfsp(ndax,ndcomp),
     *  mzrfs(ndax,ndcomp)     ,mzrfsp(ndax,ndcomp),
     *  qrseg2(2*ndax*ndcomp)  ,tkmszr,
     *  wpsur1(ndax*ndcomp)    ,wpsur2(ndax*ndcomp)
c  ****** Beginning of timestep variables for timestep repetition ******
      common /blageo/ cmpfsz(2,ndcomp,ndcomp),iblabz(ndcomp),
     *  iblfz(ndcomp) ,iblfzp(ndcomp),icblaz(6) ,itimzc(6),
     *  itimzf(ndcomp),nblabz
c  ****** End of timestep variables for timestep repetition ************
      common /blageo/ cmpfs(2,ndcomp,ndcomp) ,iblabx(ndcomp),
     *  iblfs(ndcomp) ,iblfsp(ndcomp),icbla(6) ,itimec(6),
     *  itimef(ndcomp),nblabx,ngps(ndcomp,ndcomp),
     *  ncmpgs(ndcomp),nraden(ndcomp),numfs(2,ndcomp),mcme86
c
c  ncmpgs(j)  Flow channel which contains left surface of component j.
*endif
