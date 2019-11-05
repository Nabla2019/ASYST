*mlist
$if def,makemap
c
c
c  Scratch block for stateq
c
c  Cognizant engineer: gam.
c
c  The specification statements first, in alphabetic order.
c  Integers, logicals, reals.
c  The equivalences are second, in increasing slot number.
c
       integer ihld1(1),ihld2(1),ihld2a(1),ihld4a(1),ihld9(1),qter(1)
c  Specials from svh2x2.
$if -def,in32,1
       integer is23(1)
$if def,in32,1
       integer is23(2,1)
c  Note:  ihld10 is not used in statep, but is used (implicitly) in
c         thcond.
c
       logical lflag(1),lflag2(1),tsater(1),tter(1)
c
       integer ihld10(1),itt(109)
c
       real beta(1),betaf(1),betafs(1),betag(1),betags(1)
       real cp(1),cpf(1),cpfs(1),cpg(1),cpgs(1),cps(1)
       real entfs(1),entgs(1),entpy(1),entpyf(1),entpyg(1)
       real hbar(1),hsubf(1),hsubfs(1),hsubg(1),hsubgs(1)
       real kapa(1),kapaf(1),kapaff(1),kapafs(1),kapag(1),kapagg(1),
     & kapags(1)
       real pres(1),ps(1),psat(1)
       real qual(1)
       real rhofs(1),rhogs(1)
       real tf(1),tsat(1),tt(109),ttg(1)
       real ubar(1),usubf(1),usubfs(1),usubg(1),usubgs(1)
       real vbar(1),vs(1),vsubf(1),vsubfs(1),vsubg(1),vsubgs(1)
c
       equivalence
     & (tt(1),tt(1)),(itt(1),tt(1)),
     & (pres(1),tt(2)),
     & (vbar(1),tt(3)),
     & (ubar(1),tt(4)),
     & (hbar(1),tt(5)),
     & (beta(1),tt(6)),
     & (kapa(1),tt(7)),
     & (cp(1),tt(8)),
     & (qual(1),tt(9)),
     & (psat(1),tt(10)),
     & (vsubf(1),tt(11)),
     & (vsubg(1),tt(12)),
     & (usubf(1),tt(13)),
     & (usubg(1),tt(14)),
     & (hsubf(1),tt(15)),
     & (hsubg(1),tt(16)),
     & (betaf(1),tt(17)),
     & (betag(1),tt(18)),
     & (kapaf(1),tt(19)),
     & (kapag(1),tt(20)),
     & (cpf(1),tt(21)),
     & (cpg(1),tt(22)),
     & (entpy(1),tt(24)),
     & (entpyf(1),tt(25)),
     & (entpyg(1),tt(26))
c  Specials from svh2x2.
$if -def,in32,1
       equivalence (is23(1),itt(23))
$if def,in32,1
       equivalence (is23(1,1),itt(23))
c
       equivalence
     & (tter(1),itt(32)),
     & (qter(1),itt(36)),
     & (lflag(1),itt(41)),
     & (ihld2(1),ia(43)),
     & (ihld10(1),itt(49)),
     & (tsat(1),tt(51)),
     & (ps(1),tt(52)),
     & (vs(1),tt(53)),
     & (cps(1),tt(58)),
     & (vsubfs(1),tt(61)),
     & (vsubgs(1),tt(62)),
     & (usubfs(1),tt(63)),
     & (usubgs(1),tt(64)),
     & (hsubfs(1),tt(65)),
     & (hsubgs(1),tt(66)),
     & (betafs(1),tt(67)),
     & (betags(1),tt(68)),
     & (kapafs(1),tt(69)),
     & (kapags(1),tt(70)),
     & (cpfs(1),tt(71)),
     & (cpgs(1),tt(72)),
     & (entfs(1),tt(75)),
     & (entgs(1),tt(76)),
     & (tsater(1),itt(82)),
     & (rhofs(1),tt(102)),
     & (rhogs(1),tt(103)),
     & (tf(1),tt(104)),
     & (ttg(1),tt(105)),
     & (kapaff(1),tt(106)),
     & (kapagg(1),tt(107)),
     & (ihld2a(1),itt(108)),
     & (ihld4a(1),itt(109))
$endif
