*mlist
c  Information on dynamic storage and reading/writing of restart blocks.
c
c  Cognizant engineer: rjw.
c
       integer ncoms,nfiles
       parameter (ncoms=110, nfiles=50)
       common /comctl/ comdat(ncoms),comdln(ncoms),filid(nfiles),
     & filsiz(nfiles),filndx(0:nfiles),filflg(ncoms+1),safe1
       real filid,safe1
       integer comdat,comdln,filsiz,filndx,filflg
       logical newrst
       equivalence (safe1,newrst)
