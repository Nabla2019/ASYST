*mlist
!  Cognizant engineer: rjw.
!
!  Volume block.
       integer ivsk1
$if -def,hydrolod,1
       parameter (ivsk1=237)
$if def,hydrolod,1
       parameter (ivsk1=243)
       integer nvols(l_),vctrl(l_),volno(l_),imap(l_),vctrln(l_),
     & vctrld(l_),vctrls(l_),volmat(l_),sth2xv(l_),invfnd(l_),
     & vcnfnd(l_),jjet(l_),inhcnt(l_),invcnt(l_)
       real v(l_),recipv(l_),avol(l_),dl(l_),diamv(l_),roughv(l_),
     & recrit(l_),p(l_),po(l_),uf(l_),ufo(l_),ug(l_),ugo(l_),voidf(l_),
     & voidg(l_),voidgo(l_),quala(l_),qualao(l_),boron(l_),borono(l_),
     & quals(l_),quale(l_),rho(l_),rhom(l_),rhoo(l_),rhof(l_),rhog(l_),
     & satt(l_),tempf(l_),tempg(l_),velf(l_),velg(l_),sounde(l_),
     & hsteam(l_),sathf(l_),sathg(l_),betaff(l_),betagg(l_),csubpf(l_),
     & csubpg(l_),viscf(l_),viscg(l_),sigma(l_),thconf(l_),thcong(l_),
     & pps(l_),dotm(l_),vapgno(l_),hif(l_),hig(l_),gammaw(l_),
     & gammac(l_),q(l_),qwf(l_),qwg(l_),drfdp(l_),drfduf(l_),drgdp(l_),
     & drgdug(l_),drgdxa(l_),dtfdp(l_),dtfduf(l_),dtgdp(l_),dtgdug(l_),
     & dtgdxa(l_),dtdp(l_),dtdug(l_),dtdxa(l_),dttdp(l_),floreg(l_),
     & hifo(l_),higo(l_),qualan(l_),enthn(l_),gaman(l_),enths(l_),
     & gamas(l_),vo(l_),qualno(l_),rhogo(l_),ppso(l_),ustm(l_),
     & ustmo(l_),ggas(l_),
     & gliq(l_),velfo(l_),velgo(l_),velfoo(l_),velgoo(l_),
$if -def,hydrolod,1
     & fstrt(l_),fwalf(l_),fwalg(l_)
$if def,hydrolod,2
     & fstrt(l_),fwalf(l_),fwalg(l_),loadc(l_),hyldfc(0:2),loada(l_),
     & loadb(l_)
       equivalence (nvols(1),ia(1)),(vctrl(1),ia(2)),
     & (volmat(1),ia(3)),(volno(1),ia(4)),(imap(1),ia(5)),
     & (v(1),fa(8)),(recipv(1),fa(9)),(avol(1),fa(10)),
     & (dl(1),fa(13)),(diamv(1),fa(16)),(roughv(1),fa(19)),
     & (recrit(1),fa(22)),(p(1),fa(25)),(po(1),fa(26)),(uf(1),fa(27)),
     & (ufo(1),fa(28)),(ug(1),fa(29)),(ugo(1),fa(30)),(voidf(1),fa(31)),
     & (voidg(1),fa(32)),(voidgo(1),fa(33)),(quala(1),fa(34)),
     & (qualao(1),fa(35)),(boron(1),fa(36)),(borono(1),fa(37)),
     & (quals(1),fa(38)),(quale(1),fa(39)),(rho(1),fa(40)),
     & (rhom(1),fa(41)),(rhoo(1),fa(42)),(rhof(1),fa(43)),
     & (rhog(1),fa(44)),(satt(1),fa(45)),(tempf(1),fa(46)),
     & (tempg(1),fa(47)),(velf(1),fa(48)),(velg(1),fa(51)),
     & (sounde(1),fa(54)),(hsteam(1),fa(55)),(sathf(1),fa(56)),
     & (sathg(1),fa(57)),(betaff(1),fa(58)),(betagg(1),fa(59))
       equivalence (csubpf(1),fa(60)),(csubpg(1),fa(61)),
     & (viscf(1),fa(62)),(viscg(1),fa(63)),(sigma(1),fa(64)),
     & (thconf(1),fa(65)),(thcong(1),fa(66)),(pps(1),fa(67)),
     & (dotm(1),fa(68)),(vapgno(1),fa(69)),(hif(1),fa(70)),
     & (hig(1),fa(71)),(gammaw(1),fa(72)),(gammac(1),fa(73)),
     & (q(1),fa(74)),(qwf(1),fa(75)),(qwg(1),fa(76)),(drfdp(1),fa(77)),
     & (drfduf(1),fa(78)),(drgdp(1),fa(79)),(drgdug(1),fa(80)),
     & (drgdxa(1),fa(81)),(dtfdp(1),fa(82)),(dtfduf(1),fa(83)),
     & (dtgdp(1),fa(84)),(dtgdug(1),fa(85)),(dtgdxa(1),fa(86)),
     & (dtdp(1),fa(87)),(dtdug(1),fa(88)),(dtdxa(1),fa(89)),
     & (dttdp(1),fa(90)),(floreg(1),fa(91)),(hifo(1),fa(92)),
     & (higo(1),fa(93)),(qualan(1),fa(94)),(gaman(1),fa(99)),
     & (enthn(1),fa(104)),(gamas(1),fa(109)),(enths(1),fa(110)),
     & (vo(1),fa(111)),(qualno(1),fa(112)),(rhogo(1),fa(117))
       equivalence (ppso(1),fa(118)),(ustm(1),fa(119)),
     & (ustmo(1),fa(120)),(ggas(1),fa(121)),(gliq(1),fa(124)),
     & (velfo(1),fa(127)),(velgo(1),fa(128)),(velfoo(1),fa(129)),
     & (velgoo(1),fa(130)),(fstrt(1),fa(131)),(fwalf(1),fa(132)),
     & (fwalg(1),fa(135)),(vctrln(1),ia(138)),(vctrld(1),ia(139)),
     & (vctrls(1),ia(140)),(sth2xv(1),ia(141)),(invfnd(1),ia(142))
       integer invhtf(l_),vctrlx(l_)
       real sinb(l_),hvmix(l_),ptans(l_),span(l_),pecltv(l_),fshape(l_),
     & fmurex(l_),tsatt(l_),hyarf(l_),hyarg(l_),hyaruf(l_),hyarug(l_),
     & hgf(l_),frica(l_),fricb(l_),fricc(l_),hydxc(l_),hydyc(l_),
     & hydzc(l_),hyposv(l_),gravv(l_),dlev(l_),dlevo(l_),voidla(l_),
     & voidao(l_),voidlb(l_),voidbo(l_),vlev(l_),vollev(l_),temp(l_),
     & dfront(l_),dfrnto(l_),vfront(l_),ufla(l_),ufao(l_),uflb(l_),
     & ufbo(l_),vodgoo(l_),tintf(l_),htsens(l_),srcamn(l_),tmassv(l_),
     & tiengv(l_),hyanpr(1,3,3),vapgen(l_),hgfo(l_),dplev(l_),vlevo(l_),
     & higos(l_),hifos(l_),hgfos(l_),rhofo(l_)
       equivalence (sinb(1),fa(143)),(hvmix(1),fa(146)),
     & (ptans(1),fa(147)),(span(1),fa(148)),(pecltv(1),fa(149)),
     & (fshape(1),fa(150)),(fmurex(1),fa(153)),(tsatt(1),fa(156)),
     & (hyarf(1),fa(157)),(hyarg(1),fa(158)),(hyaruf(1),fa(159)),
     & (hyarug(1),fa(160)),(hgf(1),fa(161)),(invcnt(1),ia(162)),
     & (frica(1),fa(163)),(fricb(1),fa(166)),(fricc(1),fa(169)),
     & (invhtf(1),ia(172)),(hydxc(1),fa(173)),(hydyc(1),fa(179)),
     & (hydzc(1),fa(185)),(hyposv(1),fa(191)),(gravv(1),fa(194)),
     & (voidla(1),fa(197)),(voidao(1),fa(198)),(voidlb(1),fa(199)),
     & (voidbo(1),fa(200)),(dlev(1),fa(201)),(dlevo(1),fa(202)),
     & (vlev(1),fa(203)),(vollev(1),fa(204)),(dfront(1),fa(205)),
     & (dfrnto(1),fa(206)),(vfront(1),fa(207)),(ufla(1),fa(208)),
     & (ufao(1),fa(209)),(uflb(1),fa(210)),(ufbo(1),fa(211)),
     & (vodgoo(1),fa(212)),(tintf(1),fa(213)),(htsens(1),fa(214)),
     & (srcamn(1),fa(215)),(vctrlx(1),ia(216)),(tmassv(1),fa(217)),
     & (tiengv(1),fa(218)),(hyanpr(1,1,1),fa(219)),(vapgen(1),fa(228)),
     & (hgfo(1),fa(229)),(vcnfnd(1),ia(230)),(dplev(1),fa(231)),
     & (vlevo(1),fa(232)),(higos(1),fa(233)),(hifos(1),fa(234)),
     & (hgfos(1),fa(235)),(jjet(1),ia(236)),(rhofo(1),fa(237)),
$if -def,hydrolod,1
     & (inhcnt(1),ia(238))
$if def,hydrolod
     & (inhcnt(1),ia(238)),(loadc(1),ia(239)),(hyldfc(1),ia(240)),
     & (loada(1),ia(243)),(loadb(1),ia(244))
$endif
       equivalence (temp(1),satt(1))
       integer ivsk2
$if -def,mmfld,1
       parameter (ivsk2=0)
$if def,mmfld
       parameter (ivsk2=54)
       real um(1),umo(1),voidm(1),voidmo(1),rhomt(1),qualm(1),qualmo(1),
     & tempmt(1),velmt(1),gammam(1),qwmt(1),qmtg(1),qmtf(1),drmdum(1),
     & fwalm(1),gamamt(6),enthmt(6),powmt(6),htcofm(1),hmf(1),hmg(1),
     & hwm(1),dtmdp(1),dtmdum(1),drmdp(1),csubpm(1),voidms(1)
       equivalence (um(1),fa(ivsk1+2)),(umo(1),fa(ivsk1+3)),
     & (voidm(1),fa(ivsk1+4)),(voidmo(1),fa(ivsk1+5)),
     & (rhomt(1),fa(ivsk1+6)),(qualm(1),fa(ivsk1+7)),
     & (qualmo(1),fa(ivsk1+13)),(tempmt(1),fa(ivsk1+19)),
     & (velmt(1),fa(ivsk1+20)),(gammam(1),fa(ivsk1+23)),
     & (qwmt(1),fa(ivsk1+24)),(qmtg(1),fa(ivsk1+25)),
     & (qmtf(1),fa(ivsk1+26)),(drmdum(1),fa(ivsk1+27)),
     & (fwalm(1),fa(ivsk1+28)),(gamamt(1),fa(ivsk1+29)),
     & (enthmt(1),fa(ivsk1+35)),(powmt(1),fa(ivsk1+41)),
     & (htcofm(1),fa(ivsk1+47)),(hmf(1),fa(ivsk1+48)),
     & (hmg(1),fa(ivsk1+49)),(hwm(1),fa(ivsk1+50)),
     & (dtmdp(1),fa(ivsk1+51)),(dtmdum(1),fa(ivsk1+52)),
     & (drmdp(1),fa(ivsk1+53)),(csubpm(1),fa(ivsk1+54)),
     & (voidms(1),fa(ivsk1+55))
$endif
       integer ivsk3
       parameter (ivsk3=ivsk1+ivsk2)
       integer ivsk4
$if -def,selap,1
       parameter (ivsk4=0)
$if def,selap
       parameter (ivsk4=10)
       integer idbvol(l_),mdbvol(l_),ndbvol(l_)
       real avolo(l_),diamvo(l_),oxyftr(l_)
       equivalence (idbvol(1),ia(ivsk3+2)),(mdbvol(1),ia(ivsk3+3)),
     & (ndbvol(1),ia(ivsk3+4)),(avolo(1),fa(ivsk3+5)),
     & (diamvo(1),fa(ivsk3+8)),(oxyftr(1),fa(ivsk3+11))
$endif
       integer ivsk5
       parameter (ivsk5=ivsk3+ivsk4)
       integer ivsk6
       parameter (ivsk6=0)
       integer ivsk7
       parameter (ivsk7=ivsk5+ivsk6)
       integer ivsk8
$if -def,extvol,1
       parameter (ivsk8=0)
$if def,extvol
$if def,extv20,1
       parameter (ivsk8=20)
$if def,extv100,1
       parameter (ivsk8=100)
       real extv01(l_), extv02(l_), extv03(l_), extv04(l_), extv05(l_),
     &      extv06(l_), extv07(l_), extv08(l_), extv09(l_), extv10(l_),
     &      extv11(l_), extv12(l_), extv13(l_), extv14(l_), extv15(l_),
     &      extv16(l_), extv17(l_), extv18(l_), extv19(l_), extv20(l_)
       equivalence (extv01(1),fa(ivsk7+2)) ,(extv02(1),fa(ivsk7+3)),
     &             (extv03(1),fa(ivsk7+4)) ,(extv04(1),fa(ivsk7+5)),
     &             (extv05(1),fa(ivsk7+6)) ,(extv06(1),fa(ivsk7+7)),
     &             (extv07(1),fa(ivsk7+8)) ,(extv08(1),fa(ivsk7+9)),
     &             (extv09(1),fa(ivsk7+10)),(extv10(1),fa(ivsk7+11)),
     &             (extv11(1),fa(ivsk7+12)),(extv12(1),fa(ivsk7+13)),
     &             (extv13(1),fa(ivsk7+14)),(extv14(1),fa(ivsk7+15)),
     &             (extv15(1),fa(ivsk7+16)),(extv16(1),fa(ivsk7+17)),
     &             (extv17(1),fa(ivsk7+18)),(extv18(1),fa(ivsk7+19)),
     &             (extv19(1),fa(ivsk7+20)),(extv20(1),fa(ivsk7+21))
$if def,extv100
       real extv21(l_), extv22(l_), extv23(l_), extv24(l_), extv25(l_),
     &      extv26(l_), extv27(l_), extv28(l_), extv29(l_), extv30(l_),
     &      extv31(l_), extv32(l_), extv33(l_), extv34(l_), extv35(l_),
     &      extv36(l_), extv37(l_), extv38(l_), extv39(l_), extv40(l_),
     &      extv41(l_), extv42(l_), extv43(l_), extv44(l_), extv45(l_),
     &      extv46(l_), extv47(l_), extv48(l_), extv49(l_), extv50(l_),
     &      extv51(l_), extv52(l_), extv53(l_), extv54(l_), extv55(l_),
     &      extv56(l_), extv57(l_), extv58(l_), extv59(l_), extv60(l_),
     &      extv61(l_), extv62(l_), extv63(l_), extv64(l_), extv65(l_),
     &      extv66(l_), extv67(l_), extv68(l_), extv69(l_), extv70(l_),
     &      extv71(l_), extv72(l_), extv73(l_), extv74(l_), extv75(l_),
     &      extv76(l_), extv77(l_), extv78(l_), extv79(l_), extv80(l_),
     &      extv81(l_), extv82(l_), extv83(l_), extv84(l_), extv85(l_),
     &      extv86(l_), extv87(l_), extv88(l_), extv89(l_), extv90(l_),
     &      extv91(l_), extv92(l_), extv93(l_), extv94(l_), extv95(l_),
     &      extv96(l_), extv97(l_), extv98(l_), extv99(l_), extv100(1)
       equivalence (extv21(1),fa(ivsk7+22)),(extv22(1),fa(ivsk7+23)),
     &             (extv23(1),fa(ivsk7+24)),(extv24(1),fa(ivsk7+25)),
     &             (extv25(1),fa(ivsk7+26)),(extv26(1),fa(ivsk7+27)),
     &             (extv27(1),fa(ivsk7+28)),(extv28(1),fa(ivsk7+29)),
     &             (extv29(1),fa(ivsk7+30)),(extv30(1),fa(ivsk7+31)),
     &             (extv31(1),fa(ivsk7+32)),(extv32(1),fa(ivsk7+33)),
     &             (extv33(1),fa(ivsk7+34)),(extv34(1),fa(ivsk7+35)),
     &             (extv35(1),fa(ivsk7+36)),(extv36(1),fa(ivsk7+37)),
     &             (extv37(1),fa(ivsk7+38)),(extv38(1),fa(ivsk7+39)),
     &             (extv39(1),fa(ivsk7+40)),(extv40(1),fa(ivsk7+41)),
     &             (extv41(1),fa(ivsk7+42)),(extv42(1),fa(ivsk7+43)),
     &             (extv43(1),fa(ivsk7+44)),(extv44(1),fa(ivsk7+45)),
     &             (extv45(1),fa(ivsk7+46)),(extv46(1),fa(ivsk7+47)),
     &             (extv47(1),fa(ivsk7+48)),(extv48(1),fa(ivsk7+49)),
     &             (extv49(1),fa(ivsk7+50)),(extv50(1),fa(ivsk7+51)),
     &             (extv51(1),fa(ivsk7+52)),(extv52(1),fa(ivsk7+53)),
     &             (extv53(1),fa(ivsk7+54)),(extv54(1),fa(ivsk7+55)),
     &             (extv55(1),fa(ivsk7+56)),(extv56(1),fa(ivsk7+57)),
     &             (extv57(1),fa(ivsk7+58)),(extv58(1),fa(ivsk7+59)),
     &             (extv59(1),fa(ivsk7+60)),(extv60(1),fa(ivsk7+61))
       equivalence (extv61(1),fa(ivsk7+62)),(extv62(1),fa(ivsk7+63)),
     &             (extv63(1),fa(ivsk7+64)),(extv64(1),fa(ivsk7+65)),
     &             (extv65(1),fa(ivsk7+66)),(extv66(1),fa(ivsk7+67)),
     &             (extv67(1),fa(ivsk7+68)),(extv68(1),fa(ivsk7+69)),
     &             (extv69(1),fa(ivsk7+70)),(extv70(1),fa(ivsk7+71)),
     &             (extv71(1),fa(ivsk7+72)),(extv72(1),fa(ivsk7+73)),
     &             (extv73(1),fa(ivsk7+74)),(extv74(1),fa(ivsk7+75)),
     &             (extv75(1),fa(ivsk7+76)),(extv76(1),fa(ivsk7+77)),
     &             (extv77(1),fa(ivsk7+78)),(extv78(1),fa(ivsk7+79)),
     &             (extv79(1),fa(ivsk7+80)),(extv80(1),fa(ivsk7+81)),
     &             (extv81(1),fa(ivsk7+82)),(extv82(1),fa(ivsk7+83)),
     &             (extv83(1),fa(ivsk7+84)),(extv84(1),fa(ivsk7+85)),
     &             (extv85(1),fa(ivsk7+86)),(extv86(1),fa(ivsk7+87)),
     &             (extv87(1),fa(ivsk7+88)),(extv88(1),fa(ivsk7+89)),
     &             (extv89(1),fa(ivsk7+90)),(extv90(1),fa(ivsk7+91)),
     &             (extv91(1),fa(ivsk7+92)),(extv92(1),fa(ivsk7+93)),
     &             (extv93(1),fa(ivsk7+94)),(extv94(1),fa(ivsk7+95)),
     &             (extv95(1),fa(ivsk7+96)),(extv96(1),fa(ivsk7+97)),
     &             (extv97(1),fa(ivsk7+98)),(extv98(1),fa(ivsk7+99)),
     &             (extv99(1),fa(ivsk7+100)),(extv100(1),fa(ivsk7+101))
$endif
$endif
!wdg-b
        integer ivsk9
        parameter (ivsk9=ivsk7+ivsk8)
        integer ivsk10
        parameter (ivsk10=5)
        real ttempi(l_),dtidug(l_),dtiduf(l_),dtidp(l_),dtidxn(l_)
       equivalence (ttempi(1),fa(ivsk9+2)),(dtidug(1),fa(ivsk9+3)),
     &             (dtiduf(1),fa(ivsk9+4)),(dtidp(1),fa(ivsk9+5)),
     &             (dtidxn(1),fa(ivsk9+6))
       integer ivskp
       parameter (ivskp=ivsk9+ivsk10)
!wdg-e
c
c T Name    Definition
c i ivskp   Volume skip factor (parameter set at end of voldat.H).
c i nvols   Number of volumes.
c i vctrl   Volume control packed word.
c           Bits numbered 1-32 from right end
c           1 (=1) time dependent volume flag
c           2 (=2) equilibrium flag
c           3 (=4) thermal front flag
c           4 (=8) input flag
c           5 (=16) vapor disappearance flag
c           6 (=32) accumulator flag
c           7 (=64) pump flag
c           8 (=128) input water packer flag
c           9-19 (=256=>262,144) new status flags,
c                      initialization type during input
c           20-30 (=524,288=>536,870,912) old status flags
c           31 (=1,073,741,824) input bundle flag
c           Status flags:
c           9, 20 (=256,=524,288)  negative pressure
c           10, 21 (=512,=1,048,576) mass error
c           11, 22 (=1024,=2,097,152) extrapolation error
c           12, 23 (=2048,=4,194,304) quality overrun
c           13, 24 (=4096,=8,388,608) largest mass error
c           14, 25 (=8192,=16,777,216) error in vapor phase
c           15, 26 (=16,384,=33,554,432) error in liquid phase
c           16, 27 (=32,768,=67,108,864) error in two phase call
c           17, 28 (=65,536,=134,217,728) non-convergence in iterations
c           18, 29 (=131,072,=268,435,456) negative sonic velocity
c           19, 30 (=262,144,=536,870,912) negative derived quantities
c i vctrlx  Status flags packed word (bits numbered 1-32 from right end)
c           1 (=1) debug print flag
c           2 (=2) air appearance repeat
c           3 (=4) pressure change repeat on air appearance
c           4 (=8) water packing statistics flag
c           5-6 (=16=>32) flags used for godunov method
c           7 (=64) flag used in level model
c           8 (=128) level in volume current time step
c           9 (=256) level in volume previous time step
c           10 (=512) saved level flag in current time step ( used
c             for backup )
c           11 (=1024)saved level flag in previous time step ( used
c             for backup )
c           12 (=2048) Bit on indicates to skip mass error check for
c                      this volume.
c           13 (=4096) Bit on indicates volume has been blocked (only
c              Scdap models block and reopen a volume).
c i volmat  Fluid type in volume.
c i volno   Volume number for editing.
c i imap    Map, regime, and flag packed word.
c           (bits numbered 1-32 from right end)
c           Three quantities, one per coordinate.
c           1-6 (=1=>32) Flow regime map infomation
c           7 (=64) non-condensable gas appearance flag
c           8 (=128) horizontal stratification flag
c           9 (=256) stretch flag
c           10 (=512) input vertical stratification flag
c           11,12 (=1024-2048) vertical stratification flags
c           13 (4096) experimental friction being used
c           14 (8192) wall friction input flag
c           15 (=16,384) flag for coordinate direction being used
c           16 (=32,768) unused
c           17 (=65,536) bundle input flag
c           18 (=131,072) volume in multid component
c           19-24 (=262,144-8,388,608) flow regime number
c           25-26 (=16,777,216-33,554,432) metal appearance flags
c           27 (=67,108,864) laminar friction factor, 64 if 0, 96 if 1
c           28 (=134,217,728) ans input flag
c           29 (=268,435,456) level tracking input flag
c           30 (=536,870,912) reflood flag
c           31 (=1,073,741,824) water packer volume flag
c r v       Volume.
c r recipv  Reciprocal of volume (v), zero if v is zero.
c r avol    Area of volume, three quantities, one per coordinate.
c r dl      Volume length, three quantities, one per coordinate.
c r diamv   Equivalent flow diameter.
c           Three quantities, one per coordinate.
c r roughv  Wall roughness factor for direction 1, as input.
c           Reset in icmpn1 to colebrook full turb friction fac.
c r recrit  Critical reynolds number.
c           Three quantities, one per coordinate.
c           Fric fac = const; see roughv.
c r p       Average pressure.
c r po      Average pressure previous time step.
c r uf      Liquid specific internal energy.
c r ufo     Liquid specific internal energy previous time step.
c r ug      Vapor specific internal energy.
c r ugo     Vapor specific internal energy previous time step.
c r voidf   Liquid void fraction.
c r voidg   Vapor void fraction.
c r voidgo  Vapor void fraction previous time step (n).
c r vodgoo  Vapor void fraction at old old time step (n-1).
c r quala   Noncondensible quality..
c r qualao  Noncondensible quality previous time step.
c r boron   Boron density (mass of boron per cell volume).
c r borono  Boron density previous time step.
c r quals   Static quality.
c r quale   Equilibrium quality.
c r rho     Total density.
c r rhom    Total density for mass error check.
c r rhoo    Total density previous time step.
c  *******  Warning: the ordering of rhof and rhog must be maintained
c  *******  since fidis assumes this order.
c r rhof    Liquid density.
c r rhog    Vapor density.
c r satt    Saturation temperature based on the steam partial pressure.
c r temp    Used in r level subroutines and is usually the same as satt.
c r tempf   Liquid temperature.
c r tempg   Vapor temperature.
c r velf    Average liquid velocity in a volume.
c           Three quantities, one per coordinate.
c r velg    Average vapor velocity in a volume.
c           Three quantities, one per coordinate.
c r sounde  Homogeneous equilibrium sound speed.
c           Also, used for scratch in hydro.
c r hsteam  Steam specific enthalpy at bulk conditions using partial
c           pressure of steam.
c r sathf   Liquid specific enthalpy at saturation conditions.
c r sathg   Vapor specific enthalpy at saturation conditions.
c r betaff  Liquid isobaric coefficient of thermal expansion at bulk
c           conditions.
c r betagg  Vapor isobaric coefficient of thermal expansion at bulk
c           conditions.
c r csubpf  Liquid specific heat capacity at constant pressure at bulk
c           conditions.
c r csubpg  Vapor specific heat capacity at constant pressure at bulk
c           conditions.
c r viscf   Liquid viscosity.
c r viscg   Vapor viscosity.
c r sigma   Surface tension.
c r thconf  Liquid thermal conductivity.
c r thcong  Vapor thermal conductivity.
c r pps     Vapor partial pressure.
c r dotm    Bulk vapor generation rate per unit volume.
c r vapgno  Vapor generation rate per unit volume previous time step.
c r hif     Liquid side interfacial heat transfer coefficient per unit
c           volume.
c r hig     Vapor side interfacial heat transfer coefficient per unit
c           volume.
c r gammaw  Vapor generation rate per unit volume associated with wall
c           heat transfer.
c r gammac  Condensation rate per unit volume associated with wall heat
c           transfer.
c r q       Total heat transfer rate from wall to fluid.
c r qwf     Heat transfer rate from wall to liquid.
c r qwg     Heat transfer rate from wall to vapor.
c r drfdp   Partial derivative of rhof w/r to pressure.
c r drfduf  Partial derivative of rhof w/r to liquid specific internal
c           energy.
c r drgdp   Partial derivative of rhog w/r to pressure.
c r drgdug  Partial derivative of rhog w/r to vapor specific internal
c           energy.
c r drgdxa  Partial derivative of rhog w/r to noncondensible quality.
c r dtfdp   Partial derivative of tempf w/r to pressure.
c r dtfduf  Partial derivative of tempf w/r to liquid specific internal
c           energy.
c r dtgdp   Partial derivative of tempg w/r to pressure.
c r dtgdug  Partial derivative of tempg w/r to vapor specific internal
c           energy.
c r dtgdxa  Partial derivative of tempg w/r to noncondensible quality.
c r dtdp    Partial derivative of satt w/r to pressure.
c r dtdug   Partial derivative of satt w/r to vapor specific internal
c           energy.
c r dtdxa   Partial derivative of satt w/r to noncondensible quality.
c r floreg  Flow regime number in real format.
c           1.  CTB  high mixing bubbly
c           2.  CTT  high mixing bubbly/mist transition
c           3.  CTM  high mixing mist
c           4.  BBY  bubbly
c           5.  SLG  slug
c           6.  ANM  annular-mist
c           7.  MPR  mist-pre-CHF
c           8.  IAN  inverted annular
c           9.  ISL  inverted slug
c           10. MST  mist
c           11. MPO  mist-post-CHF
c           12. HST  horizontal stratified
c           13. VST  vertical stratified
c           14. MWY  ECC mixer wavy
c           15. MWA  ECC mixer wavy/annular-mist
c           16. MAM  ECC mixer annular-mist
c           17. MMS  ECC mixer mist
c           18. MWS  ECC mixer wavy/slug transition
c           19. MWP  ECC mixer wavy-plug-slug transition
c           20. MPL  ECC mixer plug
c           21. MPS  ECC mixer plug-slug transition
c           22. MSL  ECC mixer slug
c           23. MPB  ECC mixer plug-bubbly transition
c           24. MBB  ECC mixer bubbly
c r hifo    Liquid side interfacial heat transfer coefficient per unit
c           volume previous timestep.
c r higo    Vapor side interfacial heat transfer coefficient per unit
c           volume previous timestep.
c r qualan  Noncondensible mass fraction.
c           Five quantities, one per species.
c r gaman   Noncondensible generation rate per unit volume.
c           Five quantities, one per species.
c r enthn   Enthalpy of noncondensible source.
c           Five quantities, one per species.
c r gamas   Solute generation rate per unit volume.
c r enths   Enthalpy of the solute source.
c r vo      Volume previous time step.
c r qualno  Noncondensible mass fraction previous time step.
c           Five quantities, one per species.
c r rhofo   Liquid density previous time step.
c r rhogo   Vapor density previous time step.
c r ppso    Vapor partial pressure (old time).
c r ustm    Vapor specific internal energy at pps and tempg with non-
c           condensable present.
c r ustmo   Vapor specific internal energy at pps and tempg with non-
c           condensable present (old time).
c r ggas    Cell centered gas mass flux.
c           Three quantities, one per coordinate.
c r gliq    Cell centered liquid mass flux.
c           Three quantities, one per coordinate.
c r velfo   Volume average liquid velocity previous timestep.
c           x direction only.
c r velgo   Volume average vapor velocity previous timestep.
c           x direction only.
c r velfoo  Volume average liquid velocity previous timestep but one.
c           x direction only.
c r velgoo  Volume average vapor velocity previous timestep but one.
c           x direction only.
c r fstrt   Horizontal stratification interpolating factor.
c r fwalf   Liquid wall friction coefficient.
c           Three quantities, one per coordinate.
c r fwalg   Vapor wall friction coefficient.
c           Three quantities, one per coordinate.
c r vctrln  Position of volume in volume block.
c i vctrld  Index to diagonal matrix element.
c i vctrls  Index to volume scratch space.
c i sth2xv  Index data for sth2x water property subroutines.
c i invfnd  Index to inverted junction table.
c r sinb    Sine function of volume vertical angle.
c           Three quantities, one per coordinate.
c r hvmix   Volume mixture enthalpy.
c r ptans   Pitch between fuel plates (ans).
c r span    Length of fuel plates  (ans).
c r pecltv  Volume Peclet number.
c r tsatt   Saturation temperature based on the total pressure.
c r fshape  Wall friction shape factor (one per coordinate).
c r fmurex  Viscosity ratio for wall friction (one per coordinate).
c r hyarf   Liquid void fraction times density.
c r hyarg   Vapor void fraction times density.
c r hyaruf  Product of liquid void fraction, density, and internal
c           energy.
c r hyarug  Product of vapor void fraction, density, and internal
c           energy.
c r hgf     Direct heating heat transfer coefficient per unit volume.
c r frica   Constant term in experimental friction correlation.
c           Three quantities, one per coordinate.
c r fricb   Multiplier term in experimental friction correlation.
c           Three quantities, one per coordinate.
c r fricc   Power term in experimental friction correlation.
c           Three quantities, one per coordinate.
c i invhtf  Index to inverted heat structure table.
c r hydxc(1)  Change along inertial x axis due to moving from face 1
c             to center of volume along local x coordinate.
c r hydxc(2)  Change along inertial x axis due to moving from center of
c             volume to face 2 along local x coordinate.
c r hydxc(3)  Change along inertial x axis due to moving from face 3
c             to center of volume along local y coordinate.
c r hydxc(4)  Change along inertial x axis due to moving from center of
c             volume to face 4 along local y coordinate.
c r hydxc(5)  Change along inertial x axis due to moving from face 5
c             to center of volume along local z coordinate.
c r hydxc(6)  Change along inertial x axis due to moving from center of
c             volume to face 6 along local z coordinate.
c r hydyc(1)  Change along inertial y axis due to moving from face 1
c             to center of volume along local x coordinate.
c r hydyc(2)  Change along inertial y axis due to moving from center of
c             volume to face 2 along local x coordinate.
c r hydyc(3)  Change along inertial y axis due to moving from face 3
c             to center of volume along local y coordinate.
c r hydyc(4)  Change along inertial y axis due to moving from center of
c             volume to face 4 along local y coordinate.
c r hydyc(5)  Change along inertial y axis due to moving from face 5
c             to center of volume along local z coordinate.
c r hydyc(6)  Change along inertial y axis due to moving from center of
c             volume to face 6 along local z coordinate.
c r hydzc(1)  Change along inertial z axis due to moving from face 1
c             to center of volume along local x coordinate.
c r hydzc(2)  Change along inertial z axis due to moving from center of
c             volume to face 2 along local x coordinate.
c r hydzc(3)  Change along inertial z axis due to moving from face 3
c             to center of volume along local y coordinate.
c r hydzc(4)  Change along inertial z axis due to moving from center of
c             volume to face 4 along local y coordinate.
c r hydzc(5)  Change along inertial z axis due to moving from face 5
c             to center of volume along local z coordinate.
c r hydzc(6)  Change along inertial z axis due to moving from center of
c             volume to face 6 along local z coordinate.
c r hyposv(1) Coordinate along x inertial axis of vector from center
c             of rotation to center of volume.
c r hyposv(2) Coordinate along y inertial axis of vector from center
c             of rotation to center of volume.
c r hyposv(3) Coordinate along z inertial axis of vector from center
c             of rotation to center of volume.
c r gravv(1)  Coordinate of gravity along inertial x coordinate.
c r gravv(2)  Coordinate of gravity along inertial y coordinate.
c r gravv(3)  Coordinate of gravity along inertial z coordinate.
c r tintf   Interface temperature when noncondensible is present,
c           saturation temperature at total pressure otherwise.
c r htsens  Heat transfer coefficient for sensible heat transfer
c           between vapor/gas mixture and liquid.
c r srcamn  ????????????
c r tmassv  Total mass in volume, includes both phases and
c           noncondensibles.
c r tiengv  Total internal energy in volume, Includes both phases and
c           noncondensibles.
c r hyanpr  Rotation matrix used to convert from local coordinates to
c           fixed coordinates.
c r vapgen  Total vapor generation, sum of bulk vapor generation and
c           vapor generation from flashing and condensation.
c           vapgen = dotm + gammaw + gammac.
c r hgfo    Direct heating heat transfer coefficient per unit volume
c           previous time step.
$if def,selap
c i idbvol  Indicator of whether l-th index of relap5 volume contains
c           debris region
c           0 = no
c           1 = yes.
c i mdbvol  Value for l-th relap5 volume index of index m for
c           referencing arrays in common block debcom.
c i ndbvol  Value for l-th relap5 volume index of index n for
c           referencing arrays in common block debcom.
c r avolo   Old value of avol.
c r diamvo  Old value of diamv.
$endif
c r dlev    Location of two-phase mixture level
c r dlevo   Location of two-phase mixture level (old time)
c r vlev    Velocity of two-phase level movement
c r vollev  Position of level within volume.
c r voidla  Void fraction above the mixture level
c r voidao  Void fraction above the mixture level (old time)
c r voidlb  Void fraction below the mixture level
c r voidbo  Void fraction below the mixture level (old time)
c r dfront  Location of thermal front
c r dfrnto  Location of thermal front (old time)
c r vfront  Velocity of thermal front
c r ufla    Liquid internal energy above the thermal front
c r ufao    Liquid internal energy aaove the thermal front (old time)
c r uflb    Liquid internal energy below the thermal front
c r ufbo    Liquid internal energy below the thermal front (old time)
c i vcnfnd  Index to component for volume.
c r dplev   difference in pressure between level position and volume
c           center
c r higos   saved beginning of advancement vapor side interfacial
c           heat transfer coefficient for level model backup
c r hifos   saved beginning of advancement liquid side interfacial
c           heat transfer coefficient for level model backup
c r hgfos   saved beginning of advancement direct noncondensible
c           gas - liquid heat transfer coefficient for level model
c           backup
c i jjet    address in the junction block of the jet junction for this v
$if def,extravol
c r extvnn  Extra volume data for programmer use, one for each volume.
c           To activate, add extvol and either extv20 or extv100
c           to the define file
$if def,extv20,1
c           nn goes from 01 to 20
$if def,extv100,1
c           nn goes from 01 to 100
$endif
c r ttempi  interfacial temperature
c r dtidug  interfacial temperature partial derivative wrt Ug
c r dtiduf  interfacial temperature partial derivative wrt Uf
c r dtidp   interfacial temperature partial derivative wrt P
c r dtidxn  interfacial temperature partial derivative wrt quala
