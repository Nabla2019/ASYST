*mlist
c
c  Cognizant engineer: rjw.
c
       integer, parameter :: dmwrite=z'10'
       common /contrl/ dthy,dtht,dtn,dt,timehy,timeht,errmax,tmass,
     & tmasso,emass,emasso,countn,cpurem(5),stdtrn,gravcn,testda(20),
     & aflag,print,succes,done,ncount,nstsp,nrepet,help,nany,skipt,
     & iroute,ncase,fail,uniti,unito,chngno(90),iextra,pageno,iplotlen,
     & ihlppr(2),imdctl(2),
     & safe2
       real dthy,dtht,dtn,dt,timehy,timeht,errmax,tmass,tmasso,emass,
     & emasso,countn,cpurem,stdtrn,gravcn,testda,safe2
       integer print,succes,done,ncount,nstsp,nrepet,help,nany,iroute,
     & ncase,iextra,pageno,iplotlen,cpurei(5),ihlppr,imdctl
       logical aflag,skipt,fail,uniti,unito,chngno,nmechk
       equivalence (safe2,nmechk), (cpurem(1),cpurei(1))
