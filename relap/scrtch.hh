*mlist
c  Scratch space used in advancement of hydrodynamics.
c
c  Cognizant engineer: rjw.
       integer scskp
!
       parameter (scskp=233)
c
c  The specification statements first, in alphabetic order.
c  Integers, logicals, reals.
c  The equivalences are second, in increasing slot number.
c  Within each group, there are three groups:
c     1. normal variables
c     2. under the control of $if def,mmfld
c     3. under the control of $if def,losuboil
c
       integer flomap(1),flompj(1),ihh1(1),ihh2(1),ihh3(1),ihld1(1),
     & ihld10(1),ihld2(1),ihld2a(1),ihld3(1),ihld4(1),ihld4a(1),
     & ihld5(1),ihld6(1),ihld7a(1),ihld8(1),ihld9(1),
     & ireg(1),isptr(1),ivert(1),ja(1),jb(1),
     & jhld1(1),jhld2(1),jhld3(1),jhld4(1),jhld5(1),jhld6(1),jhld7(1),
     & nix(1),nmapp(1),qsater(1),qter(1)
c  Specials from svh2x2.
$if -def,in32,1
       integer is23(1)
$if def,in32,1
       integer is23(2,1)
c  Note:  ihld10 is not used in statep, but is used (implicitly) in
c         thcond.
c
       logical badfw(1),lflag(1),lflag2(1),lgg1(1),ltest(1),ltest2(1),
     & ltest3(1),ltestt(1),nvalhi(1),nvalhx(1),xpack(1),stret(1),
     & tsater(1),tter(1)
c
       real a1(1),a11(1),a12(1),a14(1),a15(1),a2(1),a21(1),a22(1),
     & a23(1),a24(1),a25(1),a25s(1),a3(1),a31(1),a32(1),a33(1),a34(1),
     & a35(1),a35s(1),a4(1),a41(1),a41s(1),a42(1),a42s(1),a43(1),
     & a43s(1),a44(1),a44s(1),a45(1),a45s(1),
     & a5(1),a51(1),a51s(1),a52(1),a52s(1),a53(1),a53s(1),a54(1),
     & a54s(1),a55(1),a55s(1),afrf(1),afuf(1),agrg(1),agug(1),agxa(1),
     & angmm(1),areav(6),arhof(1),arhog(1),aterm(1),avelf(1),avelfg(1),
     & aviscf(1),aviscg(1),avisfs(1),avisgs(1),avkx(1),avlx(1),avrf(1),
     & avrfg(1),avrg(1),axvelf(1)
       real b1(1),b2(1),b3(1),b4(1),b5(1),bb5(1),beta(1),betaf(1),
     & betafs(1),betag(1),betags(1),borona(1),boronb(1),bterm(1),
     & bxvelg(1)
       real celvec(1),cflno(1),cond(1),
     & conm(1),conmf(1),conmg(1),convf(1),convfs(1),convg(1),convgs(1),
     & costhe(1),cp(1),cpf(1),cpfs(1),cpg(1),cpgs(1),cps(1),ctermx(1),
     & cvmrv(1)
       real dbodxj(1),dbodxv(1),dbodx1(1),dbodx2(1),
     & delpz(1),delpzk(1),delpzl(1),delv(1),delxa(1),difdpk(1),
     & difdpl(1),diff(1),difg(1),difold(1),difr(1),difvfx(1),difvgx(1),
     & dmvvec(1),dpdxfx(1),dpdxgx(1),dpstf(1),dpstfk(1),dpstfl(1),
     & drho(1),drivew(1),dstar(1),dstvec(1),dtcrnf(1),dtcrng(1),
     & dtsf(1),dtsfm(1),dtsfsb(1),dtsfsp(1),dtsg(1),
     & dtsgm(1),dtsgms(1),dvelfj(1),dvelgj(1),dx(1),dxk(1),dxkx(1),
     & dxl(1),dxlx(1),dxx(1)
       real entfs(1),entgs(1),entpy(1),entpyf(1),entpyg(1),errm(1)
       real f2(1),fal(1),fanms(1),ff(1),fgrw(1),fidxup(1),fifj(1),
     & figj(1),fjet(1),fluxm(1),fp(1),fracag(1),fracal(1),fricfj(1),
     & fricfk(1),fricfl(1),fricgj(1),fricgk(1),fricgl(1),frlmf1(1),
     & frlmf2(1),frlmg1(1),frlmg2(1),frtbf1(1),frtbf2(1),frtbg1(1),
     & frtbg2(1),frtrf1(1),frtrf2(1),frtrg1(1),frtrg2(1),fuf(1),fug(1),
     & fwf1(1),fwf2(1),fwfaf1(1),fwfag1(1),fwfxaf(1),fwfxag(1),fwg1(1),
     & fwg2(1),fxa(1),fxaa(1)
       real gal(1),gammsc(1),gammsw(1),gfwabs(1),gg(1),gp(1),gsum(6),
     & guf(1), gug(1),gxa(1),gxaa(1)
       real hbar(1),hfg(1),hgfc(1),hgfc1(1),hggff(1),hifc(1),
     & hifc1(1),hiff(1),hifh(1),hifhdt(1),higc(1),higc1(1),higg(1),
     & high(1),highdt(1),higsub(1),hlossf(1),hlossg(1),hsgf(1),
     & hsubfs(1),hsubgs(1),htcff(1),htcfg(1),htcfp(1),htcft(1),htcgf(1),
     & htcgg(1),htcgp(1),htcgt(1),htgcgf(1),htgcgg(1),htgcgp(1),
     & htgcgt(1),htgwff(1),htgwfg(1),htgwfp(1),htgwft(1),hydltf(1),
     & hydltg(1),hydltp(1),hydltt(1)
       real jetdf(1),jetdg(1),jetjdf(1),jetjdg(1),jetjsf(1),jetjsg(1),
     & jetsf(1),jetsg(1),jtcond(1),jtcons(1),jtdjdf(1),jtdjdg(1),
     & jtdjsf(1),jtdjsg(1)
       real kapa(1),kapaf(1),kapaff(1),kapafs(1),kapag(1),kapagg(1),
     & kapags(1)
       real lrhof(1),lrhog(1)
       real ncrosk(1),ncrosl(1)
       real paa(1),pbb(1),pfinrg(1),pk(1),pl(1),pmhig(1),pmpph(1),
     & pres(1),ps(1),psat(1),pshig(1),psld(1),pslope(1),psmf(1),
     & psmg(1),psumf(1),psumg(1),pumpv(1)
       real qual(1),qualem(1)
       real ratdpf(1),ratio(1),ratiof(1),ratiog(1),ravrf(1),ravrg(1),
     & reynf1(1),reynf2(1),reyng1(1),reyng2(1),
     & rfvfj(1),rfvfrc(1),rgvgj(1),rgvgrc(1),rhfg(1),rhocpf(1),rhofa(1),
     & rhofs(1),rhoga(1),rhogs(1),rvcrit(1)
       real sathfx(1),sathgx(1),scrchh(1),scrxch(1),scv1(1),scv10(1),
     & scv2(1),scv2n(5),scv3(1),scv4(1),scv5(1),scv6(1),scv7(1),scv8(1),
     & scv9(1),scvj1(11),scvj11(1),scvj12(1),scvj2(1),scvj22(1),
     & scvj3(1),scvj33(1),scvj4(1),scvj44(1),scvj5(1),scvj6(1),scvj7(1),
     & scvj8(1),scvjck(1),scvjn(5),scvtur(1),sinbt(1),snk(1),snl(1),
     & sora(1),sorp(1),soura(1),sourca(1),sourcf(1),sourcg(1),sourci(1),
     & sourcm(1),sourcn(1),sourcq(1),sourff(1),
     & sourgg(1),sourn(1),sumdpk(1),sumdpl(1),sumf(1),sumg(1),sumold(1),
     & sumvfx(1),sumvgx(1)
       real taa(1),tbb(1),tcouri(1),tf(1),timinv(1),tloc(1),tloc2(1),
     & tnmins(1),tnplus(1),tpdpdx(1),tquala(1),trmm(1),trmm1(1),tsat(1),
     & tt(1),ttg(1),tuf(1),tug(1),tvoidg(1)
       real ubar(1),ufnc(1),ugnc(1),us(1),usubf(1),usubfs(1),
     & usubg(1),usubgs(1)
       real vagrg(1),vbar(1),velfjs(1),velgjs(1),
     & velvcf(1),velvcg(1),vfa(1),vfdpk(1),
     & vfdpl(1),vga(1),vgdpk(1),vgdpl(1),vmgnx(1),vngen(1),vodmnc(1),
     & voidaa(1),voidfa(1),voidga(1),voidgd(1),voidgk(1),voidgl(1),
     & voidgu(1),vpgen(1),vpgnx(1),vrhof(6),vrhog(6),vruf(1),vrug(1),
     & vrxg(1),vrxgn(5),vs(1),vsubf(1),vsubfs(1),vsubg(1),vsubgs(1),
     & vvfx(6),vvgx(6)
       real xliqh(1),xncn(1),xvaph(1)
       real zambda(1),zzout(1)
$if def,mmfld
       integer ihld7(1)
       real a17(1),a27(1),a27s(1),a36(1),a37(1),a46(1),a47(1),a47s(1),
     & a56(1),a57(1),a57s(1),a61(1),a62(1),a63(1),a64(1),a65(1),a66(1),
     & a67(1),a67s(1),a71(1),a72(1),a73(1),a74(1),a75(1),a76(1),a77(1),
     & amrm(1),amrmn(1),amum(1),arhom(1),avrfmp(1),avrfms(1),avrgmp(1),
     & avrgms(1),avrm(1)
       real b6(1),b7(1),conmm(1),convm(1),convms(1),difm(1),
     & difvmx(1),dpstm(1),dvelmj(1),fricmk(1),fricml(1),metf(1),metg(1),
     & metm(1),metold(1),pmld(1),psmm(1),ratiom(2),ravrm(1),rhoma(1),
     & rmvmj(1)
       real smk(1),sml(1),smv1(1),smv2(1),smv3(1),smvj1(1),smvj2(1),
     & smvj3(1),smvj4(1),smvj5(1),smvj6(6),smvj7(1),sorcme(1),sorcmm(1),
     & sorcmn(6),summ(1),sumvmx(1),umnc(1)
       real vamrm(1),vma(2),vmdpk(1),vmdpl(1),vmgen(1),vmx(2),
     & voidma(1),vrhom(2)
$endif
c
       equivalence (a25s(1),a51s(1),b1(1),fa(1)),
     & (dbodxv(1),dpstf(1),drho(1),dvelfj(1),fa(1)),
     & (scvjck(1),tt(1),vvfx(1),fa(1)),
     & (a35s(1),a52s(1),b2(1),dvelgj(1),fa(2)),
     & (dxkx(1),pres(1),ratio(1),fa(2)),
     & (a53s(1),b3(1),conmf(1),cflno(1),dtcrnf(1),fa(3)),
     & (dxlx(1),errm(1),vbar(1),fa(3)),(ihh1(1),ia(4)),
     & (a54s(1),b4(1),conmg(1),dbodxj(1),dtcrng(1),fwfaf1(1),fa(4)),
     & (gfwabs(1),ubar(1),voidaa(1),fa(4)),(ihh3(1),ia(5)),
     & (bb5(1),borona(1),cond(1),delxa(1),fwfag1(1),hbar(1),fa(5))
       equivalence (ihh2(1),ia(6)),(beta(1),boronb(1),conm(1),dpdxfx(1),
     & fwf1(1),fa(6)),(ugnc(1),fa(6)),(nix(1),ia(7)),
     & (dpdxgx(1),ireg(1),fwg1(1),kapa(1),fa(7)),
     & (dbodx1(1),scv1(1),ufnc(1),vvgx(1),fa(7)),
     & (lgg1(1),ltest(1),ia(8)),(cp(1),dbodx2(1),scv2(1),fa(8)),
     & (ltest2(1),qual(1),scv3(1),fa(9)),
     & (fwf2(1),ltest3(1),psat(1),rfvfrc(1),fa(10)),
     & (scv4(1),sinbt(1),fa(10)),
     & (rgvgrc(1),scv5(1),voidgu(1),vrxgn(1),vsubf(1),fa(11)),
     & (xncn(1),fa(11)),(pslope(1),scv6(1),voidgd(1),vsubg(1),fa(12)),
     & (angmm(1),fwg2(1),scv7(1),tloc(1),usubf(1),fa(13)),
     & (vrhof(1),zambda(1),fa(13)),
     & (fjet(1),reynf2(1),scvj1(1),scv8(1),tloc2(1),fa(14)),
     & (tpdpdx(1),usubg(1),fa(14)),
     & (ctermx(1),pumpv(1),reyng2(1),scvj2(1),scv9(1),fa(15)),
     & (vagrg(1),fa(15))
       equivalence (scvj3(1),scvtur(1),scv10(1),fa(16)),
     & (betaf(1),pmpph(1),scvj4(1),scv2n(1),fa(17)),
     & (betag(1),pk(1),fa(18)),(kapaf(1),voidgk(1),vrhog(1),fa(19)),
     & (kapag(1),pl(1),fa(20)),
     & (cpf(1),voidgl(1),fa(21)),(avrfg(1),cpg(1),sourff(1),fa(22)),
     & (sourgg(1),fa(23)),(entpy(1),tuf(1),fa(24)),
     & (avkx(1),a55s(1),b5(1),entpyf(1),scvj12(1),tug(1),fa(25)),
     & (avlx(1),entpyg(1),sorp(1),fa(26)),
     & (vfdpk(1),sumdpk(1),fa(27)),(difdpk(1),vgdpk(1),hggff(1),fa(28)),
     & (sumdpl(1),vfdpl(1),fa(29)),(difdpl(1),vgdpl(1),fa(30))
c  Specials from svh2x2.
$if -def,in32,1
       equivalence (is23(1),ia(23))
$if def,in32,1
       equivalence (is23(1,1),ia(23))
c
       equivalence (jhld1(1),ia(31)),(sourca(1),fa(31)),
     & (jhld2(1),tter(1),ia(32)),(sourcg(1),fa(32)),
     & (ja(1),jhld3(1),ia(33)),(sourcf(1),fa(33)),
     & (jb(1),jhld4(1),ia(34)),(sourcm(1),fa(34)),(jhld5(1),ia(35)),
     & (sourcn(1),fa(35)),(jhld6(1),qter(1),ia(36)),(jhld7(1),ia(37)),
     & (hgfc(1),fa(38)),(hgfc1(1),fa(39)),
     & (lflag2(1),ia(40)),(dxk(1),fricfj(1),fa(40))
       equivalence (lflag(1),ia(41)),(fricgj(1),dtsf(1),dxl(1),fa(41)),
     & (ihld1(1),ia(42)),(dtsg(1),fa(42)),(ihld2(1),ia(43)),
     & (hfg(1),fa(43)),(badfw(1),ihld3(1),xpack(1),ia(44)),
     & (rhfg(1),fa(44)),(aterm(1),avelf(1),a11(1),ncrosk(1),tnmins(1),
     & fa(45)),(ihld5(1),ia(46)),
     & (a12(1),bterm(1),ncrosl(1),rhocpf(1),tnplus(1),fa(46)),
     & (ihld6(1),ia(47)),(axvelf(1),dxx(1),fracal(1),vpgnx(1),xliqh(1),
     & fa(47)),(ihld9(1),ia(48)),
     & (a14(1),bxvelg(1),rhofa(1),xvaph(1),fa(48)),
     & (ihld8(1),ihld10(1),ia(49)),(a15(1),rhoga(1),trmm(1),fa(49))
       equivalence (ihld7a(1),ia(50)),(a21(1),trmm1(1),vpgen(1),fa(50)),
     & (a22(1),higc(1),tsat(1),vrxg(1),fa(51)),
     & (a23(1),higc1(1),ps(1),ravrf(1),fa(52)),
     & (a24(1),hifc(1),ratiof(1),ravrg(1),vs(1),fa(53)),
     & (a25(1),hifc1(1),rfvfj(1),us(1),fa(54)),
     & (a31(1),frlmf1(1),higsub(1),rgvgj(1),fa(55)),
     & (ltestt(1),ia(56)),(a32(1),dtsfm(1),frlmg1(1),fa(56)),
     & (a33(1),dtsgms(1),fricfk(1),frtrf1(1),fa(57)),
     & (a34(1),cps(1),dtsgm(1),fricfl(1),frtrg1(1),fa(58)),
     & (a35(1),dtsfsp(1),fricgk(1),frtbf1(1),ratiog(1),fa(59))
       equivalence (a41(1),dtsfsb(1),fricgl(1),frtbg1(1),fa(60)),
     & (avelfg(1),a42(1),convf(1),frlmf2(1),vsubfs(1),fa(61)),
     & (a43(1),convg(1),fluxm(1),frlmg2(1),vsubgs(1),f2(1),fa(62)),
     & (a44(1),convfs(1),frtrf2(1),scrchh(1),usubfs(1),fa(63)),
     & (a45(1),celvec(1),convgs(1),frtrg2(1),usubgs(1),fa(64)),
     & (a51(1),dmvvec(1),frtbf2(1),gsum(1),fa(65)),
     & (hsubfs(1),snk(1),fa(65)),
     & (a52(1),frtbg2(1),hsubgs(1),velvcf(1),fa(66)),
     & (a53(1),betafs(1),ratdpf(1),fa(67)),
     & (snl(1),velvcg(1),fa(67)),(a54(1),betags(1),dstvec(1),fa(68)),
     & (a55(1),kapafs(1),vngen(1),fa(69))
       equivalence (a1(1),kapags(1),psmf(1),timinv(1),fa(70)),
     & (areav(1),a2(1),cpfs(1),psmg(1),tcouri(1),fa(71)),
     & (nmapp(1),ia(72)),(a3(1),cpgs(1),psld(1),fa(72)),
     & (ivert(1),ia(73)),(a4(1),sumf(1),fa(73)),(nvalhi(1),ia(74)),
     & (a5(1),sumg(1),fa(74)),(nvalhx(1),ia(75)),
     & (entfs(1),gxa(1),high(1),sumold(1),fa(75)),
     & (diff(1),entgs(1),fxa(1),hifh(1),fa(76)),
     & (difg(1),paa(1),vfa(1),fa(77)),
     & (difold(1),fanms(1),pbb(1),fa(78)),
     & (agxa(1),figj(1),taa(1),fa(79))
       equivalence (agrg(1),dx(1),tbb(1),fa(80)),
     & (ff(1),fa(81)),(tsater(1),ia(82)),(gg(1),fa(82)),
     & (sathfx(1),vga(1),fa(83)),(sathgx(1),fa(84)),(hsgf(1),fa(85)),
     & (qsater(1),ia(86)),(agug(1),voidga(1),fa(86)),
     & (afuf(1),fifj(1),fa(87)),(afrf(1),voidfa(1),fa(88)),
     & (arhof(1),fal(1),fa(89))
       equivalence (gal(1),fa(90)),(fgrw(1),psumf(1),reynf1(1),fa(91)),
     & (highdt(1),psumg(1),reyng1(1),fa(92)),
     & (hifhdt(1),vmgnx(1),fa(93)),
     & (scrxch(1),sourci(1),qualem(1),fa(94)),
     & (arhog(1),difr(1),fp(1),fa(95)),(delv(1),gp(1),fa(96)),
     & (cvmrv(1),gug(1),fa(97)),(fracag(1),hlossf(1),fa(98)),
     & (fug(1),hlossg(1),fa(99))
       equivalence (fuf(1),zzout(1),fa(100)),
     & (guf(1),fa(101)),
     & (rhofs(1),velfjs(1),fa(102)),(rhogs(1),velgjs(1),fa(103)),
     & (tf(1),fa(104)),(ttg(1),fa(105)),
     & (kapaff(1),fa(106)),(kapagg(1),fa(107)),(ihld2a(1),ia(108)),
     & (ihld4a(1),ia(109))
       equivalence (sourcq(1),fa(111)),(soura(1),fa(112)),
     & (ihld4(1),ia(113)),(sourn(1),fa(113)),(isptr(1),ia(118))
       equivalence (aviscf(1),vrug(1),fa(141)),
     & (aviscg(1),vruf(1),fa(142)),(gxaa(1),fa(144)),(fxaa(1),fa(145)),
     & (delpz(1),fa(146)),(tquala(1),fa(147)),(tvoidg(1),fa(148)),
     & (avisfs(1),lrhog(1),fa(149))
       equivalence (avisgs(1),lrhof(1),fa(150)),(pmhig(1),fa(151)),
     & (pshig(1),fa(152)),(avrf(1),fa(153)),(avrg(1),fa(154)),
     & (stret(1),ia(155))
c  No 161, 162
       equivalence (fidxup(1),fa(160)),(fwfxaf(1),scvjn(1),fa(163)),
     & (fwfxag(1),fa(166)),(pfinrg(1),fa(169))
c  No 170, 171.
       equivalence (drivew(1),flomap(1),flompj(1),ia(172)),
     & (jtdjsg(1),fa(173)),(jtdjsf(1),fa(174)),
     & (jtdjdg(1),rvcrit(1),fa(175)),(jtdjdf(1),fa(176)),
     & (jetjsg(1),fa(177)),(dstar(1),jetjsf(1),fa(178)),
     & (jetjdg(1),fa(179))
       equivalence (jetjdf(1),fa(180)),(costhe(1),jetsg(1),fa(181)),
     & (jetsf(1),fa(182)),(jetdg(1),fa(183)),(hiff(1),jetdf(1),fa(184)),
     & (jtcons(1),fa(185)),(jtcond(1),fa(186)),
     & (higg(1),scvj11(1),fa(187)),(scvj22(1),fa(188)),
     & (scvj33(1),fa(189))
c  No 195
       equivalence (scvj44(1),sumvfx(1),fa(190)),(scvj5(1),fa(191)),
     & (scvj6(1),fa(192)),(scvj7(1),sumvgx(1),fa(193)),
     & (scvj8(1),fa(194)),(difvfx(1),fa(196)),(difvgx(1),fa(199))
       equivalence (htcfg(1),fa(202)),(htcft(1),fa(203)),
     & (htcgf(1),fa(204)),(htcgt(1),fa(205)),(hydltf(1),fa(206)),
     & (hydltg(1),fa(207)),(hydltt(1),fa(208)),(hydltp(1),fa(209)),
     & (htgwff(1),fa(210)),(htgwfg(1),fa(211)),(htgwft(1),fa(212)),
     & (htgcgf(1),fa(213)),(htgcgg(1),fa(214)),(htgcgp(1),fa(215)),
     & (htgcgt(1),fa(216)),(htcgp(1),fa(217)),(htcgg(1),fa(218)),
     & (htcff(1),fa(219)),(htcfp(1),fa(220)),(htgwfp(1),fa(221)),
     & (gammsw(1),fa(222)),(gammsc(1),fa(223))
       equivalence (a41s(1),fa(224)),(a42s(1),fa(225)),
     & (a43s(1),fa(226)),(a44s(1),fa(227)),(a45s(1),fa(228)),
     & (sora(1),fa(229)),(delpzk(1),fa(230)),(delpzl(1),fa(231)),
     & (dpstfk(1),fa(232)),(dpstfl(1),fa(233))
$if def,mmfld
       equivalence (a47s(1),fa(1)),(a57s(1),fa(2)),
     & (a67s(1),fa(3)),(vmx(1),fa(27)),(vrhom(1),fa(29)),
     & (arhom(1),fa(31)),(vma(1),fa(32)),(ratiom(1),fa(34))
       equivalence (ihld7(1),ia(101)),(difvmx(1),fa(101)),
     & (sumvmx(1),fa(102)),(sorcmm(1),fa(103)),(sorcme(1),fa(104)),
     & (sorcmn(1),fa(105)),(vmdpk(1),fa(111)),(vmdpl(1),fa(112)),
     & (vamrm(1),fa(113)),(a77(1),voidma(1),fa(114)),
     & (a76(1),rhoma(1),fa(115)),(a67(1),avrm(1),fa(116)),
     & (a66(1),ravrm(1),fa(117)),(a37(1),rmvmj(1),fa(118)),
     & (a27(1),fricmk(1),fa(119))
       equivalence (a17(1),fricml(1),fa(120)),
     & (amrm(1),convm(1),fa(121)),(amum(1),smk(1),fa(122)),
     & (conmm(1),dvelmj(1),sml(1),fa(123)),
     & (smv1(1),smvj1(1),vmgen(1),fa(124)),
     & (psmm(1),smv2(1),smvj2(1),fa(125)),
     & (pmld(1),smv3(1),smvj3(1),fa(126)),
     & (smvj4(1),summ(1),fa(127)),(difm(1),smvj5(1),fa(128)),
     & (metf(1),smvj6(1),fa(129))
       equivalence (metg(1),fa(130)),(metm(1),fa(131)),
     & (b6(1),metold(1),fa(132)),(b7(1),fa(133)),
     & (amrmn(1),dpstm(1),fa(134)),(smvj7(1),umnc(1),fa(135)),
     & (avrgms(1),vodmnc(1),fa(136)),(avrfms(1),fa(137)),
     & (avrgmp(1),fa(138)),(a27s(1),avrfmp(1),fa(139))
       equivalence (a65(1),convms(1),fa(140)),(a36(1),fa(141)),
     & (a71(1),fa(146)),(a61(1),fa(147)),(a64(1),fa(148)),
     & (a63(1),fa(149))
       equivalence (a46(1),fa(150)),(a75(1),fa(151)),(a74(1),fa(152)),
     & (a73(1),fa(153)),(a72(1),fa(154)),(a57(1),fa(156)),
     & (a56(1),fa(157)),(a47(1),fa(158)),(a62(1),fa(159))
$endif
