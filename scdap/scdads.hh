*mlist
c
c  Descriptive sentence for scdads goes here.
c
c  Cognizant engineer: rjw.
c
       integer ntelm,ntgam
       parameter (ntelm=39,ntgam=20)
       common /scdads/ ai,ao,area,areard,
     & avol0,avold,avolmn,bgmcto,cghg,cghga,cghgu,cgnhg,delplq,
     & delprs,delpvp,deltmp,delvol,depdeb,dhrel,diamv0,dkcs,dkcsg,dki,
     & dkig,dkte,dkteg,dktime,dvdeb,dzfrc1,dzfrmx,elmfr,emiss,emsubn,
     & eqnch,flg,flg1,fncomp,fng1,frcbun,frch,fviewz,
     & gamfr,hadsum,htper,pathll,pcl,powdeb,powsum,qffcon,
     & qffhtr,qfgcon,qfghtr,qfrel,qftcon,qfthtr,qgamma,qnchsh,
     & qqnch,qrdsrt,qres,ratio,ratm,ratoln,rcrs2l,
     & refdbx,satbed,sbcon,slbwde,slbwdl,sumvw,tdown,telm,term,term1,
     & term2,tgam,thkhp0,ti,timfrc,to,tolare,tolvre,totm,
     & tsatlp,tsurhp,tvapbc,unuc,unucd,usum,utot,vmin,vol0,vold,
     & voldb1,volmax,volmin,volsum,w,worka,wt,wtot,wtpm,
     & icrcb0,idcmpl,idisrp,idoknt,iencl,ijcml,ipvt,jmloc,jnloc,kabov1,
     & kdymlo,kdyn,kdynlo,lreopn,liqmin,mhdpan,modrad,mrdbwr,nbundl,
     & ncomp1,ncxnaz,ndbprn,nhpx,nhrold,njunop,nrods,nsigll,nswblk,
     & nswcer,nswcht,nswhdp,nswliq,nswq,nswq2,nswqdt,nswrub,nswtop,
     & numdeb,newplb,newplu,mcme107
       real ai,ao,area,areard,avol0,avold,avolmn,bgmcto,cghg,cghga,
     & cghgu,cgnhg,delplq,delprs,delpvp,deltmp,delvol,depdeb,
     & dhrel,diamv0,dkcs,dkcsg,dki,dkig,dkte,dkteg,dktime,dvdeb,dzfrc1,
     & dzfrmx,elmfr(mxelm,ntelm),emiss,emsubn(ndcomp),
     & eqnch,flg,flg1,fncomp,fng1,frcbun,frch,
     & fviewz(ndax,ndcomp,ndcomp),gamfr(mxelm,ntgam),hadsum,htper,
     & pathll(ndax,ndcomp,ndcomp),pcl(ndax*ndcomp),powdeb,powsum,qffcon,
     & qffhtr,qfgcon,qfghtr,qfrel,qftcon,qfthtr,qgamma,qnchsh,
     & qqnch,qrdsrt(ndax),qres(ndax),ratio,ratm,ratoln,
     & rcrs2l(ndax,ndcomp),refdbx,satbed,sbcon,slbwde,slbwdl(ndcomp),
     & sumvw,tdown,telm(ntelm),term,term1,term2,tgam(ntgam),
     & thkhp0,ti,timfrc,to,tolare,tolvre,totm,
     & tsatlp,tsurhp,tvapbc,unuc(2*ndax),
     & unucd(ndax),usum(ndax),utot,vmin,vol0,vold,voldb1,volmax,volmin,
     & volsum,w,worka(ndcomp),wt(ndcomp),wtot(ndax),wtpm
       integer icrcb0,idcmpl(ndcomp),idisrp(ndax),idoknt,iencl,
     & ijcml(ndcomp),ipvt(ndcomp),jmloc,jnloc,kabov1,kdymlo,kdyn,kdynlo,
     & liqmin,lreopn,mhdpan,modrad,mrdbwr,nbundl,ncomp1,ncxnaz,ndbprn,
     & nhpx,nhrold,njunop,nrods,nsigll(ndcomp),nswblk,nswcer,nswcht,
     & nswhdp,nswliq,nswq,nswq2,nswqdt,nswrub,nswtop,numdeb
       logical newplb,newplu
       integer mcme107
