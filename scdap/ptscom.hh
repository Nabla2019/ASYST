*mlist
c
c  ptscom is the past time step variables common block.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c     past time step variables common block
       common /ptscom/ alfai0(ndax),alfao0(ndax),effcp0(ndax),
     & effgn0(ndax),oxdei0(ndax),oxdeo0(ndax),oxdwc0(ndax),
     & oxdwf0(ndax),qclad0(ndax),qout0(ndax),rci0(ndax),
     & rco0(ndax),rnalf0(ndax),rnoxd0(ndax),tcolc0(ndax),tsur0(ndax),
     & vfuel0(ndax),vfvod0(ndax),paxpz0(2,ndax,maxpz),h2oxd0(ndax),
     & ruliq0(ndax),acrst0(ndax),afuel0(ndax),oxdws0(ndax),ggivy0(17),
     & ggrel0(18),fpivy0(ndax,16),fpvrt0(ndax),fpryc0(16),fgrj0(ndax),
     & rpel0(ndax),rcrmx0(ndax),rcrst0(ndax),
     & volcr0(ndax),wbtuo0,wbtzr0,wbtab0,wbtss0,wfruo0(ndax),
     & wfrzr0(ndax),wfrab0(ndax),wfrsr0(ndax),wrmuo0(ndax),wrmzr0(ndax),
     & wrmab0(ndax),wrmsr0(ndax),wuorm0(ndax),wrmzo0(ndax),wumlt0(ndax),
     & rumlt0(ndax),wbtox0,dzfrc0(ndax),rcoi0(ndax),fpary0(16),
     & ioxer0(ndax),ltrns0(ndax),nfrsl0(ndax),noxer0,noxid0(ndax),
     & ncrum0(ndax),ncrst0,nfi0(ndax),iphas0(ndax),icldf0,mcme57
       real alfai0,alfao0,effcp0,effgn0,oxdei0,oxdeo0,oxdwc0,oxdwf0,
     & qclad0,qout0,rci0,rco0,rnalf0,rnoxd0,tcolc0,tsur0,vfuel0,
     & vfvod0,paxpz0,h2oxd0,ruliq0,acrst0,afuel0,oxdws0,ggivy0,ggrel0,
     & fpivy0,fpvrt0,fpryc0,fgrj0,rpel0,rcrmx0,rcrst0,volcr0,wbtuo0,
     & wbtzr0,wbtab0,wbtss0,wfruo0,wfrzr0,wfrab0,wfrsr0,wrmuo0,wrmzr0,
     & wrmab0,wrmsr0,wuorm0,wrmzo0,wumlt0,rumlt0,wbtox0,dzfrc0,rcoi0,
     & fpary0
       integer ncrum0,ioxer0,nfrsl0,noxer0,noxid0,nfi0,icldf0,
     & iphas0,ncrst0,mcme57
       logical ltrns0
*endif
