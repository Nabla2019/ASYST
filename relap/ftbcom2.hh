*mlist
!
!  Cognizant engineer: rjw.
!
!      ftb common description
       common /ftb/ first,size,maxz,minz,nolink,nofils,link1,lasdes,
     & nexdes,ndsk2,reclim,ireclt,hilo,dlt,dly,dpn,szz
       integer first,size(7),maxz(7),minz(7),nolink,nofils,link1,lasdes,
     & nexdes,ndsk2,reclim,ireclt(5),szz(8)
       logical hilo,dlt,dly,dpn(4)
$if def,cray,2
       common /ftb/ ftbun(5)
       integer ftbun
