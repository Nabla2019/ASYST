*mlist
c
c  Volume information for moving system.
       integer irvoff,irvskp
       parameter (irvoff=49,irvskp=30)
       integer angltp(l_)
       real rring1(l_),rring2(l_),rring3(l_),rrids1(l_),rrids2(l_),
     & rrids3(l_),rrangl(l_),rrangw(l_),rranga(l_),rrdisp(l_),
     & rrdisv(l_),rrdisa(l_),rromeg(l_),rrdmeg(l_)
       equivalence (angltp(1),ia(1)),(rring1(1),fa(2)),
     & (rring2(1),fa(7)),(rring3(1),fa(12)),(rrids1(1),fa(17)),
     & (rrids2(1),fa(20)),(rrids3(1),fa(23)),(rrangl(1),fa(26)),
     & (rrangw(1),fa(29)),(rranga(1),fa(32)),(rrdisp(1),fa(35)),
     & (rrdisv(1),fa(38)),(rrdisa(1),fa(41)),(rromeg(1),fa(44)),
     & (rrdmeg(1),fa(47))
       real hxdxc(l_),hxdyc(l_),hxdzc(l_),hxposv(l_),hxanpr(1,3,3)
       equivalence (hxdxc(1),fa(irvoff+1)),
     & (hxdyc(1),fa(irvoff+7)),(hxdzc(1),fa(irvoff+13)),
     & (hxposv(1),fa(irvoff+19)),(hxanpr(1,1,1),fa(irvoff+22))
