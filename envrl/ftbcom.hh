*comdeck ftbcom
c
c  ftb common description
       integer lfsiz
       parameter (lfsiz=4000000)
       common /fast/ a(lfsiz)
$if -def,in32
       real a
$if def,lcm,2
       common /ftblcm/ b
       level 2, /ftblcm/
       real b(lfsiz)
$if -def,lcm,1
       equivalence (a(1),b(1))
       integer ia(lfsiz)
       equivalence (a(1),ia(1))
$endif
$if def,in32,3
       real*8 a,b(lfsiz)
       integer ia(2,lfsiz)
       equivalence (a(1),ia(1,1),b(1))
       common /ftb/ first,size,maxz,minz,nolink,nofils,link1,lasdes,
     * nexdes,ndsk2,reclim,ireclt,hilo,dlt,dly,dpn,szz
       integer first,size(7),maxz(7),minz(7),nolink,nofils,link1,lasdes,
     * nexdes,ndsk2,reclim,ireclt(5),szz(8)
$if def,cray,2
       common /ftb/ ftbun(5)
       integer ftbun
       logical hilo,dlt,dly,dpn(4)
       save /fast/,/ftb/
