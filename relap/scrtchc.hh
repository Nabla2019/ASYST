*mlist
c  scrtch.H common block comments
c
c  Cognizant engineers: gam,rjw,rar.
c
c  scskp  stride for scratch space.
c
c  There are four Lists of comments for the scrtch.H block:
c  List 1: the variables are listed by increasing slot number.
c   This list indicates the type of variable: vol or jun.
c   It also indicates where the variable was finished being used
c   and set to a NaN.
c  List 2: the variables are listed in alphabetic order.
c  List 3: the variables used in each subroutine are listed by
c   increasing slot number.
c  List 4: the variables are listed by increasing slot number.
c   This list has >s between the subroutine names to indicate that
c   the variable has to survive from the previous subroutine to the
c   following subroutine.  This list is useful for determining if
c   a slot or variable is free to be used elsewhere.
c
c
c  List 1 <=======>
c
c  There are two $if def in this list, the mmfld case is second
c   and the losuboil case is last.  The list goes from 1-221 in
c   each case.
c
c  Within each group that are equivalenced to a given slot, the
c   names of the variables are arranged alphabetically.
c
c  The number of slots allocated is indicated in the subscript
c   after the variable name, e.g., (3) indicates 3 slots and
c   is used for the three dimensional variables.
c
c
c a51s(1)  ,fa(1)   vol local to vimplt
c                   Naned in vimplt
c b1(1)    ,fa(1)   vol local to eqfinl, eqfinm, pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c dbodxv(1),fa(1)   vol local to brntrn
c                   Naned in brntrn
c dpstf(1) ,fa(1)   vol set in phantj, survive to vexplt
c                   vol set in phantj, survive to vimplt
c drho(1)  ,fa(1)   vol local to state
c                   Naned in state
c dvelfj(1),fa(1)   jun local to vfinl
c                   Naned in vfinl
c scvjck(1),fa(1)   jun set in vexplt, survive to jchoke
c                   jun set in vimplt, survive to jchoke
c tt(1)    ,fa(1)   vol local to statep
c                   Naned in statep
c vvfx(6)  ,fa(1)   vol local to volvel, vlvela
c                   Naned in volvel, vlvela
c a52s(1)  ,fa(2)   vol local to vimplt
c                   Naned in vimplt
c b2(1)    ,fa(2)   vol local to eqfinl, eqfinm, pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c dvelgj(1),fa(2)   jun local to vfinl
c                   Naned in vfinl
c dxkx(1)  ,fa(2)   jun set in phantj
c                   survive to ccfl, jchoke, vexplt, vimplt
c                   Naned in hydro after 998 continue
c pres(1)  ,fa(2)   vol local to statep
c                   Naned in statep
c ratio(1) ,fa(2)   vol local to brntrn
c                   Naned in brntrn
c a53s(1)  ,fa(3)   vol local to vimplt
c                   Naned in vimplt
c b3(1)    ,fa(3)   vol local to eqfinl, eqfinm, pimplt
c                   conmf and b3 use same slot in eqfinl, eqfinm, pimplt
c                   conmf is used first, b3 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c cflno(1) ,fa(3)   vol local to brntrn
c                   Naned in brntrn
c conmf(1) ,fa(3)   jun local to eqfinl, eqfinm, pimplt
c                   conmf and b3 use same slot in eqfinl, eqfinm, pimplt
c                   conmf is used first, b3 is used later
c                   Naned in middle of eqfinl, eqfinm, pimplt
c dtcrnf(1),fa(3)   vol only used in courn1 (dtcrnt for liquid)
c dxlx(1)  ,fa(3)   jun set in phantj
c                   survive to ccfl, jchoke, vexplt, vimplt
c                   Naned in hydro after 998 continue
c errm(1)  ,fa(3)   vol local to state
c                   Naned in state
c vbar(1)  ,fa(3)   vol local to statep
c                   Naned in statep
c a54s(1)  ,fa(4)   vol local to vimplt
c                   Naned in vimplt
c b4(1)    ,fa(4)   vol local to eqfinl, eqfinm, pimplt
c                   conmg, b4, voidaa use same slot in eqfinl
c                   conmg is used first, b4 is used second, voidaa last
c                   conmg and b4 use same slot in eqfinm, pimplt
c                   conmg is used first, b4 is used later
c                   Naned in eqfinl, eqfinm, pimplt
c conmg(1) ,fa(4)   jun local to eqfinl, eqfinm, pimplt
c                   conmg, b4, voidaa use same slot in eqfinl
c                   conmg is used first, b4 is used second, voidaa last
c                   conmg and b4 use same slot in eqfinm, pimplt
c                   conmg is used first, b4 is used later
c                   Naned in middle of eqfinl, eqfinm, pimplt
c dbodxj(1),fa(4)   jun local to brntrn
c                   Naned in brntrn
c dtcrng(1),fa(4)   vol only used in courn1 (dtcrnt for gas)
c fwfaf1(1),fa(4)   vol local to fwdrag
c                   fwfaf1 and gfwabs same slot in fwdrag
c                   fwfaf1 is used first, gfwabs is used later
c                   Naned in middle of fwdrag
c gfwabs(1),fa(4)   vol local to fwdrag
c                   fwfaf1 and gfwabs same slot in fwdrag
c                   fwfaf1 is used first, gfwabs is used later
c                   Naned in fwdrag
c ihh1(1)  ,ia(4)   jun local to jprop, passed stdry
c                   Naned in jprop
c ubar(1)  ,fa(4)   vol local to statep
c                   Naned in statep
c voidaa(1),fa(4)   vol local to eqfinl
c                   conmg, b4, voidaa use same slot in eqfinl
c                   conmg is used first, b4 is used second, voidaa last
c                   Naned in eqfinl
c bb5(1)   ,fa(5)   vol local to pimplt (was b5 in version 3.1.3)
c                   cond and bb5 same slot in pimplt
c                   cond is used first, bb5 is used later
c                   Naned in pimplt
c borona(1),fa(5)   vol local to brntrn
c                   Naned in brntrn
c cond(1)  ,fa(5)   jun local to eqfinl, eqfinm
c                   jun local to pimplt
c                   cond and delxa use same slot in eqfinl, eqfinm
c                   cond is used first, delxa is used later
c                   cond and bb5 same slot in pimplt
c                   cond is used first, bb5 is used later
c                   Naned in middle of eqfinl, eqfinm, pimplt
c delxa(1) ,fa(5)   vol local to eqfinl, eqfinm, simplt
c                   cond and delxa use same slot in eqfinl, eqfinm
c                   cond is used first, delxa is used later
c                   Naned in eqfinl, simplt, eqfinm
c fwfag1(1),fa(5)   vol local to fwdrag
c                   Naned in middle of fwdrag
c hbar(1)  ,fa(5)   vol local to statep
c                   Naned in statep
c ihh3(1)  ,ia(5)   jun local to jprop
c                   Naned in jprop
c beta(1)  ,fa(6)   vol local to statep
c                   Naned in statep
c boronb(1),fa(6)   vol local to brntrn
c                   Naned in brntrn
c conm(1)  ,fa(6)   jun local to eqfinl, eqfinm, pimplt
c                   conm and ugnc same slot in eqfinl, eqfinm
c                   conm is used first, ugnc is used later
c                   Naned in middle of eqfinl, eqfinm, pimplt
c dpdxfx(1),fa(6)   vol local to fwdrag
c                   fwf1 and dpdxfx same slot in fwdrag
c                   fwf1 is used first, dpdxfx is used later
c                   Naned in fwdrag
c fwf1(1)  ,fa(6)   vol local to fwdrag
c                   fwf1 and dpdxfx same slot in fwdrag
c                   fwf1 is used first, dpdxfx is used later
c                   Naned in middle of fwdrag
c ihh2(1)  ,ia(6)   jun local to jprop, passed stdry
c                   Naned in jprop
c ugnc(1)  ,fa(6)   vol local to eqfinl, eqfinm
c                   conm and ugnc same slot in eqfinl, eqfinm
c                   conm is used first, ugnc is used later
c                   Naned in eqfinl, eqfinm
c dbodx1(1),fa(7)   vol local to brntrn
c                   Naned in brntrn
c dpdxgx(1),fa(7)   vol local to fwdrag
c                   fwg1 and dpdxfx same slot in fwdrag
c                   fwg1 is used first, dpdxfx is used later
c                   Naned in fwdrag
c fwg1(1)  ,fa(7)   vol local to fwdrag
c                   fwg1 and dpdxfx same slot in fwdrag
c                   fwg1 is used first, dpdxfx is used later
c                   Naned in middle of fwdrag
c ireg(1)  ,fa(7)   jun set in fidisj, used in phantj which calls it
c                   Naned in phantj
c kapa(1)  ,fa(7)   vol local to statep
c                   Naned in statep
c nix(1)   ,ia(7)   jun local to jprop
c                   Naned in jprop
c scv1(1)  ,fa(7)   jun local to eqfinl, eqfinm, pimplt
c                   scv1 and ufnc same slot in eqfinl, eqfinm
c                   scv1 is used first, ufnc is used later
c                   Naned in middle of eqfinl, eqfinm
c                   Naned in pimplt
c ufnc(1)  ,fa(7)   vol local to eqfinl, eqfinm
c                   scv1 and ufnc same slot in eqfinl, eqfinm
c                   scv1 is used first, ufnc is used later
c                   Naned in eqfinl, eqfinm
c vvgx(6)  ,fa(7)   vol local to volvel, vlvela
c                   Naned in volvel, vlvela
c cp(1)    ,fa(8)   vol local to statep
c                   Naned in statep
c dbodx2(1),fa(8)   vol local to brntrn
c                   Naned in brntrn
c lgg1(1)  ,ia(8)   jun local to jprop
c                   Naned in jprop
c ltest(1) ,ia(8)   vol local to eqfinl, eqfinm
c                   scv2 and ltest same slot in eqfinl, eqfinm
c                   scv2 is used first, ltest is used later
c                   Naned in eqfinl, eqfinm
c scv2(1)  ,fa(8)   jun local to eqfinl, eqfinm, pimplt
c                   scv2 and ltest same slot in eqfinl, eqfinm
c                   scv2 is used first, ltest is used later
c                   Naned in middle of eqfinl, eqfinm
c                   Naned in pimplt
c ltest2(1),ia(9)   vol local to eqfinl, eqfinm
c                   scv3 and ltest2 same slot in eqfinl, eqfinm
c                   scv3 is used first, ltest2 is used later
c                   Naned in eqfinl, eqfinm
c scv3(1)  ,fa(9)   jun local to eqfinl, eqfinm, pimplt
c                   scv3 and ltest2 same slot in eqfinl, eqfinm
c                   scv3 is used first, ltest2 is used later
c                   Naned in middle of eqfinl, eqfinm
c                   Naned in pimplt
c qual(1)  ,fa(9)   vol local to statep
c                   Naned in statep
c fwf2(1)  ,fa(10)  vol local to fwdrag
c                   Naned in middle of fwdrag
c ltest3(1),ia(10)  vol local to eqfinl, eqfinm
c                   scv4 and ltest3 same slot in eqfinl, eqfinm
c                   scv4 is used first, ltest3 is used later
c                   Naned in eqfinl, eqfinm
c psat(1)  ,fa(10)  vol local to statep
c                   Naned in statep
c rfvfrc(1),fa(10)  jun local to vimplt
c                   Naned in vimplt
c scv4(1)  ,fa(10)  jun local to eqfinl, eqfinm, pimplt
c                   scv4 and ltest3 same slot in eqfinl, eqfinm
c                   scv4 is used first, ltest3 is used later
c                   Naned in middle of eqfinl, eqfinm
c                   Naned in pimplt
c sinbt(1) ,fa(10)  jun set in phantj, used in fidisj which it calls
c                   Naned in phantj
c rgvgrc(1),fa(11)  jun local to vimplt
c                   Naned in vimplt
c scv5(1)  ,fa(11)  jun local to eqfinl, eqfinm, pimplt
c                   scv5 and xncn same slot in eqfinl
c                   scv5 is used first, xncn is used later
c                   Naned in middle of eqfinl
c                   Naned in eqfinm, pimplt
c voidgu(1),fa(11)  vol set in phantv, survive to phantj
c                   Naned in phantj
c vrxgn(5) ,fa(11)  vol local to simplt
c                   Naned in simplt
c vsubf(1) ,fa(11)  vol local to statep
c                   Naned in statep
c xncn(1)  ,fa(11)  vol local to eqfinl
c                   scv5 and xncn same slot in eqfinl
c                   scv5 is used first, xncn is used later
c                   Naned in eqfinl
c pslope(1),fa(12)  vol set in pump, used in vexplt, used in vimplt
c                   both of which call pump
c                   Naned in vexplt, vimplt
c scv6(1)  ,fa(12)  jun local to eqfinl, eqfinm, pimplt
c                   Naned in middle of eqfinl, eqfinm
c                   Naned in pimplt
c voidgd(1),fa(12)  vol set in phantv, survive to phantj
c                   Naned in phantj
c vsubg(1) ,fa(12)  vol local to statep
c                   Naned in statep
c angmm(1), fa(13)  jun set in pump, used in vexplt, vimplt
c                   tloc and angmm same slot in vexplt, vimplt
c                   tloc is used first, angmm is used later
c                   Naned in vexplt, vimplt
c fwg2(1)  ,fa(13)  vol local to fwdrag
c                   fwg2 and zambda same slot in fwdrag
c                   fwg2 is used first, zambda is used later
c                   Naned in middle of fwdrag
c scv7(1)  ,fa(13)  jun local to pimplt
c                   Naned in pimplt
c tloc(1),  fa(13)  vol local to vexplt, vimplt
c                   tloc and angmm same slot in vexplt, vimplt
c                   tloc is used first, angmm is used later
c                   Naned in middle of vexplt, vimplt
c                   Naned in vimplt
c usubf(1) ,fa(13)  vol local to statep
c                   Naned in statep
c vrhof(6) ,fa(13)  vol local to volvel, vlvela
c                   Naned in volvel, vlvela
c zambda(1),fa(13)  vol local to fwdrag
c                   fwg2 and zambda same slot in fwdrag
c                   fwg2 is used first, zambda is used later
c                   Naned in fwdrag
c fjet(1)  ,fa(14)  jun local to vexplt, vimplt
c                   tloc2 and fjet same slot in vexplt, vimplt
c                   tloc2 is used first, fjet is used later
c                   Naned in vexplt, vimplt
c reynf2(1),fa(14)  vol local to fwdrag
c                   reynf2 and tpdpdx same slot in fwdrag
c                   reynf2 is used first, tpdpdx is used later
c                   Naned in middle of fwdrag
c scv8(1)  ,fa(14)  jun local to pimplt
c                   Naned in pimplt
c scvj1(11),fa(14)  jun local to vfinl, packer, called from vfinl
c                   this variable is just a starting point, it goes
c                   10 locations beyond and 5 locations in front of
c                   this slot, so it goes from fa(9) to fa(24)
c                   Wow, what an abomination.  It needs to be fixed.
c                   Naned in vfinl from 9=>14
c tloc2(1) ,fa(14)  vol local to vexplt, vimplt
c                   tloc2 and fjet same slot in vexplt, vimplt
c                   tloc2 is used first, fjet is used later
c                   Naned in middle of vexplt
c                   Naned in vimplt
c tpdpdx(1),fa(14)  vol local to fwdrag
c                   reynf2 and tpdpdx same slot in fwdrag
c                   reynf2 is used first, tpdpdx is used later
c                   Naned in fwdrag
c usubg(1) ,fa(14)  vol local to statep
c                   Naned in statep
c ctermx(1),fa(15)  vol local to fwdrag
c                   reyng2 and ctermx same slot in fwdrag
c                   reyng2 is used first, ctermx is used later
c                   Naned in fwdrag
c pumpv(1) ,fa(15)  jun local to vimplt
c                   Naned in vimplt
c reyng2(1),fa(15)  vol local to fwdrag
c                   reyng2 and ctermx same slot in fwdrag
c                   reyng2 is used first, ctermx is used later
c                   Naned in middle of fwdrag
c scv9(1)  ,fa(15)  jun local to pimplt
c                   Naned in pimplt
c scvj2(1) ,fa(15)  jun local to vfinl
c                   Naned in vfinl
c vagrg(1) ,fa(15)  vol local to vexplt, vimplt
c                   Naned in vexplt, vimplt
c scv10(1) ,fa(16)  jun local to pimplt
c                   Naned in pimplt
c scvj3(1) ,fa(16)  jun set in packer, survive to vfinl
c                   Naned in vfinl
c scvtur(1),fa(16)  jun set in vexplt, survive to jchoke
c                   jun set in vimplt
c                   Naned in jchoke
c betaf(1) ,fa(17)  vol local to statep
c                   Naned in statep
c pmpph(1) ,fa(17)  jun set in vexplt, survive to jchoke
c                   jun set in vimplt
c                   Naned in jchoke
c scv2n(5) ,fa(17)  jun local to eqfinl, eqfinm, pimplt (noncondensibles
c                   Naned in eqfinl, pimplt, eqfinm
c scvj4(1) ,fa(17)  jun local to vfinl
c                   Naned in vfinl
c betag(1) ,fa(18)  vol local to statep
c                   Naned in statep
c pk(1)    ,fa(18)  jun local to vexplt,level
c kapaf(1) ,fa(19)  vol local to statep
c                   Naned in statep
c vrhog(6) ,fa(19)  vol local to volvel, vlvela
c                   Naned in volvel, vlvela
c voidgk(1),fa(19)  vol local to vexplt
c kapag(1) ,fa(20)  vol local to statep
c                   Naned in statep
c pl(1)    ,fa(20)  jun local to vexplt,level
c cpf(1)   ,fa(21)  vol local to statep
c                   Naned in statep
c voidgl(1),fa(21)  vol local to vexplt
c avrfg(1) ,fa(22)  vol local to vexplt
c cpg(1)   ,fa(22)  vol local to statep
c                   Naned in statep
c sourff(1),fa(22)  vol set in pimplt, survive to simplt
c                   Naned in simplt
c is23(1)  ,ia(23)  vol used and later set in stvrpx, svh2x2
c                   not sure where it is set initially
c sourgg(1),fa(23)  vol set in pimplt, survive to simplt
c                   Naned in simplt
c entpy(1) ,fa(24)  vol local to statep
c                   Naned in statep
c tuf(1)   ,fa(24)  vol set in pimplt, survive to simplt
c                   Naned in simplt
c a55s(1)  ,fa(25)  vol local to vimplt
c                   Naned in vimplt
c avkx(1)  ,fa(25)  jun set in phantj, survive to jchoke, vexplt, vimplt
c                   Naned in hydro after 998 continue
c b5(1)    ,fa(25)  vol local to eqfinl, eqfinm
c                   Naned in eqfinl, eqfinm
c entpyf(1),fa(25)  vol local to statep
c                   Naned in statep
c scvj12(1),fa(25)  jun local to vfinl
c                   Naned in vfinl
c tug(1)   ,fa(25)  vol set in pimplt, survive to simplt
c                   Naned in simplt
c avlx(1)  ,fa(26)  jun set in phantj, survive to jchoke, vexplt, vimplt
c                   Naned in hydro after 998 continue
c entpyg(1),fa(26)  vol local to statep
c                   Naned in statep
c sorp(1)  ,fa(26)  vol local to eqfinl, eqfinm, vimplt
c                   Naned in eqfinl, eqfinm, vimplt
c sumdpk(1),fa(27)  jun set in jchoke, used in vimplt
c                   survive to debug print in simplt
c                   vgdpk and sumdpk same slot in jchoke
c                   vgdpk is for semi-implicit, sumdpk is for nearly-imp
c                   only set in jchoke, ccfl for nearly-implicit case
c                   Naned in simplt
c vfdpk(1) ,fa(27)  jun set in accum, ccfl, jchoke, vexplt
c                   used in packer, preseq, prseqm, vfinl
c                   vgdpk and difdpk same slot in jchoke, ccfl
c                   vgdpk is for nearly-implicit, difdpk is for semi-imp
c                   only set in jchoke, ccfl for semi-implicit case
c                   Naned in vfinl
c difdpk(1),fa(28)  jun set in jchoke, ccfl, used in vimplt
c                   survive to debug print in simplt
c                   vgdpk and difdpk same slot in jchoke, ccfl
c                   vgdpk is for nearly-implicit, difdpk is for semi-imp
c                   only set in jchoke, ccfl for nearly-implicit case
c                   Naned in simplt
c vgdpk(1) ,fa(28)  jun set in accum, ccfl, jchoke, vexplt
c                   used in packer, preseq, prseqm, vfinl
c                   vgdpk and difdpk same slot in jchoke, ccfl
c                   vgdpk is for nearly-implicit, difdpk is for semi-imp
c                   only set in jchoke, ccfl for semi-implicit case
c                   Naned in vfinl
c hggff(1) ,fa(28)  vol local to phantv
c                   Naned in phantv
c sumdpl(1),fa(29)  jun set in jchoke, used in vimplt
c                   survive to debug print in simplt
c                   vgdpk and sumdpk same slot in jchoke
c                   vgdpk is for semi-implicit, sumdpk is for nearly-imp
c                   only set in jchoke, ccfl for nearly-implicit case
c                   Naned in simplt
c vfdpl(1) ,fa(29)  jun set in accum, ccfl, jchoke, vexplt
c                   used in packer, preseq, prseqm, vfinl
c                   vgdpk and difdpk same slot in jchoke, ccfl
c                   vgdpk is for nearly-implicit, difdpk is for semi-imp
c                   only set in jchoke, ccfl for semi-implicit case
c                   Naned in vfinl
c difdpl(1),fa(30)  jun set in jchoke, ccfl, used in vimplt
c                   survive to debug print in simplt
c                   vgdpk and difdpk same slot in jchoke, ccfl
c                   vgdpk is for nearly-implicit, difdpk is for semi-imp
c                   only set in jchoke, ccfl for nearly-implicit case
c                   Naned in simplt
c vgdpl(1) ,fa(30)  jun set in accum, ccfl, jchoke, vexplt
c                   used in packer, preseq, prseqm, vfinl
c                   vgdpk and difdpk same slot in jchoke, ccfl
c                   vgdpk is for nearly-implicit, difdpk is for semi-imp
c                   only set in jchoke, ccfl for semi-implicit case
c                   Naned in vfinl
c jhld1(1) ,ia(31)  vol local to phantv
c                   jun local to fwdrag
c                   Naned in phantv, fwdrag
c sourca(1),fa(31)  vol set in vexplt, survive to preseq, eqfinl
c                   survive to prseqm, eqfinm
c                   vol set in vimplt, survive to pimplt
c                   all of above survive to statep
c                   Naned in statep
c jhld2(1) ,ia(32)  vol local to phantv
c                   jun local to fwdrag
c                   Naned in phantv, fwdrag
c sourcg(1),fa(32)  vol set in vexplt, survive to accum, survive to pres
c                                      survive to eqfinl
c                   vol set in vimplt, survive to pimplt
c                   vol set in prseqm, survive to eqfinm
c                   Naned in eqfinl, eqfinm
c tter(1)  ,ia(32)  vol local to statep
c                   Naned in statep
c ja(1)    ,ia(33)  vol local to stvrpx, svh2x2
c                   Naned in stvrpx, svh2x2
c jhld3(1) ,ia(33)  vol local to phantv
c                   jun local to fwdrag
c                   Naned in phantv, fwdrag
c sourcf(1),fa(33)  vol set in vexplt, survive to accum, survive to pres
c                                      survive to eqfinl
c                   vol set in vimplt, survive to pimplt
c                   vol set in prseqm, survive to eqfinm
c                   Naned in eqfinl, eqfinm
c jb(1)    ,ia(34)  vol local to stvrpx, svh2x2
c                   Naned in stvrpx, svh2x2
c jhld4(1) ,ia(34)  vol local to phantv
c                   Naned in phantv
c sourcm(1),fa(34)  vol set in vexplt, survive to preseq, survive to eqf
c                   vol set in vimplt, survive to pimplt
c                   vol set in prseqm, survive to eqfinm
c                   all of above survive to statep
c                   Naned in statep
c jhld5(1) ,ia(35)  vol local to phantv
c                   Naned in phantv
c sourcn(1),fa(35)  vol set in vexplt, survive to eqfinl or eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, eqfinm
c jhld6(1) ,ia(36)  vol local to phantv
c                   Naned in phantv
c qter(1)  ,ia(36)  vol local to statep
c                   Naned in statep
c jhld7(1) ,ia(37)  vol local to phantv
c                   Naned in phantv
c hgfc(1)  ,fa(38)  vol local to phantv
c                   Naned in phantv
c hgfc1(1) ,fa(39)  vol local to phantv
c                   Naned in phantv
c dxk(1),   fa(40)  jun local to vexplt, vimplt
c                   dxk and fricfj same slot in vexplt
c                   dxk is used first, fricfj is used later
c                   can not Nan out in vimplt, they are in same do loop
c                   Naned in middle of vexplt
c fricfj(1),fa(40)  jun local to vexplt, vimplt
c                   dxk and fricfj same slot in vexplt
c                   dxk is used first, fricfj is used later
c                   Naned in vexplt, vimplt
c lflag2(1),ia(40)  vol local to statep
c                   Naned in statep
c dtsf(1)  ,fa(41)  vol set in phantv
c                   returned from hifbub (called from phantv)
c                   Naned in phantv
c dxl(1),   fa(41)  jun local to vexplt, vimplt
c                   dxl and fricgj same slot in vexplt
c                   dxl is used first, fricgj is used later
c                   Naned in middle of vexplt, vimplt
c fricgj(1),fa(41)  jun local to vexplt, vimplt
c                   dxl and fricgj same slot in vexplt
c                   dxl is used first, fricgj is used later
c                   Naned in vexplt, vimplt
c lflag(1) ,ia(41)  vol local to statep
c                   Naned in statep
c dtsg(1)  ,fa(42)  vol local to phantv
c                   Naned in phantv
c ihld1(1), ia(42)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol local to pimplt,simplt,statep
c                   jun local to vexplt, vimplt
c                   Naned in eqfinl, pimplt, simplt, statep
c                   Naned in vexplt, vimplt, eqfinm
c hfg(1)   ,fa(43)  vol set in phantv
c                   used in hifbub (called from phantv)
c                   Naned in phantv
c ihld2(1), ia(43)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol local to pimplt,simplt,statep
c                   jun local to vexplt, vimplt
c                   Naned in eqfinl, pimplt, simplt, statep
c                   Naned in vexplt, vimplt, eqfinm
c badfw(1) ,ia(44)  vol set in fwdrag
c                   Naned in fwdrag
c ihld3(1) ,ia(44)  vol local to vexplt, statep
c                   vol set preseq, survive to eqfinl
c                   vol set prseqm, survive to eqfinm
c                   Naned in vexplt, statep
c                   Naned in eqfinl, eqfinm
c pack(1)  ,ia(44)  vol local to packer
c                   Naned in packer
c rhfg(1)  ,fa(44)  vol set in phantv
c                   used in hifbub (called from phantv)
c                   Naned in phantv
c a11(1)   ,fa(45)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a11 and ncrosk use same slot in vimplt
c                   ncrosk is used first, a11 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c aterm(1) ,fa(45)  vol set in fwdrag
c                   Naned in middle of fwdrag
c avelf(1) ,fa(45)  vol set in phantv
c                   used in hifbub (called from phantv)
c                   Naned in phantv
c ncrosk(1),fa(45)  jun local to vexplt, vimplt
c                   a11 and ncrosk use same slot in vimplt
c                   ncrosk is used first, a11 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt, vimplt
c tnmins(1),fa(45)  jun local to simplt
c                   Naned in simplt
c a12(1)   ,fa(46)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a12 and ncrosl use same slot in vimplt
c                   ncrosl is used first, a12 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c bterm(1) ,fa(46)  vol set in fwdrag
c                   Naned in middle of fwdrag
c ihld5(1) ,ia(46)  vol local to statep
c                   Naned in statep
c ncrosl(1),fa(46)  jun local to vexplt, vimplt
c                   a12 and ncrosl use same slot in vimplt
c                   ncrosl is used first, a12 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt, vimplt
c rhocpf(1),fa(46)  vol set in phantv
c                   used in hifbub (called from phantv)
c                   Naned in phantv
c tnplus(1),fa(46)  jun local to simplt
c                   Naned in simplt
c axvelf(1),fa(47)  vol set in fwdrag
c                   Naned in fwdrag
c dxx(1)   ,fa(47)  jun local to vexplt, vimplt
c                   dxx and vpgnx same slot in vexplt
c                   dxx is used first, vpgnx is used later
c                   Naned in middle of vexplt, vimplt
c fracal(1),fa(47)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   Naned in eqfinl, eqfinm
c ihld6(1) ,ia(47)  vol local to statep
c                   Naned in statep
c vpgnx(1) ,fa(47)  jun local to vexplt
c                   dxx and vpgnx same slot in vexplt
c                   dxx is used first, vpgnx is used later
c                   Naned in vexplt
c xliqh(1) ,fa(47)  vol local to phantv
c                   Naned in phantv
c a14(1)   ,fa(48)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a14 and rhofa use same slot in vimplt
c                   rhofa is used first, a14 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c bxvelg(1),fa(48)  vol set in fwdrag
c                   Naned in fwdrag
c ihld9(1) ,ia(48)  vol set in svh2x2
c                   passed to statep from thcond
c                   Naned in statep, svh2x2
c rhofa(1) ,fa(48)  jun local to vexplt, vimplt
c                   a14 and rhofa use same slot in vimplt
c                   rhofa is used first, a14 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c xvaph(1) ,fa(48)  vol local to phantv
c                   Naned in phantv
c a15(1)   ,fa(49)  vol set in preseq, survive to eqfinl
c                   vol set in vimplt, survive to pimplt
c                   a15 and rhoga use same slot in vimplt
c                   rhoga is used first, a15 is used later
c                   Naned in eqfinl, pimplt
c ihld8(1) ,ia(49)  vol local to svh2x2
c                   Naned in svh2x2
c ihld10(1),ia(49)  vol local to statep
c                   not used in statep
c                   but is used (implicitly) in thcond
c                   Naned in statep
c rhoga(1) ,fa(49)  jun local to vexplt, vimplt
c                   a15 and rhoga use same slot in vimplt
c                   rhoga is used first, a15 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt, vimplt
c trmm(1)  ,fa(49)  vol local to phantv (was term)
c                   Naned in phantv
c a21(1)   ,fa(50)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a21 and vpgen use same slot in vimplt
c                   vpgen is used first, a21 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c ihld7a(1),ia(101) vol local to svh2x2
c                   Naned in svh2x2
c trmm1(1) ,fa(50)  vol local to phantv (was term1)
c                   Naned in phantv
c vpgen(1) ,fa(50)  jun local to vexplt, vimplt
c                   a21 and vpgen use same slot in vimplt
c                   vpgen is used first, a21 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c a22(1)   ,fa(51)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c higc(1)  ,fa(51)  vol local to phantv
c                   Naned in phantv
c tsat(1)  ,fa(51)  vol local to statep
c                   Naned in statep
c vrxg(1)  ,fa(51)  vol local to simplt
c                   Naned in simplt
c a23(1)   ,fa(52)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a23 and ravrf use same slot in vimplt
c                   ravrf is used first, a23 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c higc1(1) ,fa(52)  vol local to phantv
c                   Naned in phantv
c ps(1)    ,fa(52)  vol local to statep
c                   Naned in statep
c ravrf(1) ,fa(52)  vol local to vexplt and vimplt (1/avrf)
c                   a23 and ravrf use same slot in vimplt
c                   ravrf is used first, a23 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c a24(1)   ,fa(53)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a24 and ravrg use same slot in vimplt
c                   ravrg is used first, a24 is used later
c                   Naned in eqfinl, pimplt
c hifc(1)  ,fa(53)  vol set in phantv
c                   returned from hifbub (called from phantv)
c                   Naned in phantv
c ratiof(6),fa(53)  vol local to volvel
c                   Naned in volvel
c ravrg(1) ,fa(53)  vol local to vexplt, vimplt (1/avrg)
c                   a24 and ravrg use same slot in vimplt
c                   ravrg is used first, a24 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c rfvfj(1) ,fa(53)  jun local to vexplt, vimplt
c                   Naned in vexplt, vimplt
c vs(1)    ,fa(53)  vol local to statep
c                   Naned in statep
c a25(1)   ,fa(54)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a25 and rgvgj use same slot in vimplt
c                   rgvgj is used first, a25 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c hifc1(1) ,fa(54)  vol set in phantv
c                   returned from hifbub (called from phantv)
c                   Naned in phantv
c rgvgj(1) ,fa(54)  jun local to vexplt, vimplt
c                   a25 and rgvgj use same slot in vimplt
c                   rgvgj is used first, a25 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c us(1)    ,fa(54)  vol local to statep, in debug print only
c                   Naned in statep
c a31(1)   ,fa(55)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c frlmf1(1),fa(55)  vol set in fwdrag
c                   Naned in fwdrag
c higsub(1),fa(55)  vol local to phantv
c                   Naned in phantv
c a32(1)   ,fa(56)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c dtsfm(1) ,fa(56)  vol local to phantv
c                   Naned in phantv
c frlmg1(1),fa(56)  vol set in fwdrag
c                   Naned in fwdrag
c ltestt(1),ia(56)  jun local to vexplt
c                   Naned in vexplt
c a33(1)   ,fa(57)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a33 and fricfk use same slot in vimplt
c                   fricfk is used first, a33 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c cps(1)   ,fa(57)  vol local to statep
c                   Naned in statep
c dtsgms(1),fa(57)  vol local to phantv
c                   Naned in phantv
c fricfk(1),fa(57)  jun local to vexplt, vimplt
c                   a33 and fricfk use same slot in vimplt
c                   fricfk is used first, a33 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c frtrf1(1),fa(57)  vol set in fwdrag
c                   Naned in fwdrag
c a34(1)   ,fa(58)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a34 and fricfl use same slot in vimplt
c                   fricfl is used first, a34 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c dtsgm(1) ,fa(58)  vol local to phantv
c                   Naned in phantv
c fricfl(1),fa(58)  jun local to vexplt, vimplt
c                   a34 and fricfl use same slot in vimplt
c                   fricfl is used first, a34 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c frtrg1(1),fa(58)  vol set in fwdrag
c                   Naned in fwdrag
c a35(1)   ,fa(59)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a35 and fricgk use same slot in vimplt
c                   fricgk is used first, a35 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c dtsfsp(1),fa(59)  vol local to phantv
c                   Naned in phantv
c fricgk(1),fa(59)  jun local to vexplt, vimplt
c                   a35 and fricgk use same slot in vimplt
c                   fricgk is used first, a35 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c frtbf1(1),fa(59)  vol set in fwdrag
c                   Naned in fwdrag
c ratiog(6),fa(59)  vol local to volvel
c                   Naned in volvel
c a41(1)   ,fa(60)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a41 and fricgl use same slot in vimplt
c                   fricgl is used first, a41 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c dtsfsb(1),fa(60)  vol local to phantv
c                   Naned in phantv
c fricgl(1),fa(60)  jun local to vexplt, vimplt
c                   a41 and fricgl use same slot in vimplt
c                   fricgl is used first, a41 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c frtbg1(1),fa(60)  vol set in fwdrag
c                   Naned in fwdrag
c a42(1)   ,fa(61)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a42 and convf use same slot in vimplt
c                   convf is used first, a42 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c avelfg(1),fa(61)  vol local to phantv
c                   Naned in phantv
c convf(1) ,fa(61)  jun local to vexplt, vimplt
c                   jun set in coev3d, survive to vimplt, which calls it
c                   jun set in flux3d, survive to vexplt, which calls it
c                   a42 and convf use same slot in vimplt
c                   convf is used first, a42 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c frlmf2(1),fa(61)  vol set in fwdrag
c                   Naned in middle of fwdrag
c vsubfs(1),fa(61)  vol local to statep
c                   Naned in statep
c a43(1)   ,fa(62)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a43 and convg use same slot in vimplt
c                   convg is used first, a43 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c convg(1) ,fa(62)  jun local to vexplt, vimplt
c                   jun set in coev3d, survive to vimplt, which calls it
c                   jun set in flux3d, survive to vexplt, which calls it
c                   a43 and convg use same slot in vimplt
c                   convg is used first, a43 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c fluxm(1) ,fa(62)  vol local to phantv
c                   fluxm, f2 same slot in phantv
c                   fluxm is used first, f2 is used second
c                   Naned in phantv
c frlmg2(1),fa(62)  vol set in fwdrag
c                   Naned in middle of fwdrag
c vsubgs(1),fa(62)  vol local to statep
c                   Naned in statep
c a44(1)   ,fa(63)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a44 and convfs use same slot in vimplt
c                   convfs is used first, a44 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c convfs(1),fa(63)  jun local to vexplt, vimplt
c                   a44 and convfs use same slot in vimplt
c                   convfs is used first, a44 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c frtrf2(1),fa(63)  vol set in fwdrag
c                   Naned in middle of fwdrag
c scrchh(1),fa(63)  vol local to phantv (was scrach)
c                   Naned in phantv
c usubfs(1),fa(63)  vol local to statep
c                   Naned in statep
c a45(1)   ,fa(64)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a45 and convgs use same slot in vimplt
c                   convgs is used first, a45 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c celvec(1),fa(64)  vol local to phantv
c                   celvec, fpress same slot in phantv
c                   fpress is used first, celvec is used second
c                   Naned in phantv
c convgs(1),fa(64)  jun local to vexplt, vimplt
c                   a45 and convgs use same slot in vimplt
c                   convgs is used first, a45 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c f2(1)    ,fa(64)  vol local to phantv
c                   f2, celvec, fpress same slot in phantv
c                   fpress is used first, f2 is used second, celvec last
c                   Naned in phantv
c frtrg2(1),fa(64)  vol set in fwdrag
c                   Naned in middle of fwdrag
c usubgs(1),fa(64)  vol local to statep
c                   Naned in statep
c a51(1)   ,fa(65)  vol local to preseq
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a51 and snk(1) use same slot in vimplt
c                   snk(1) is used first, a51 is used later
c                   Naned in preseq, pimplt, eqfinm
c dmvvec(1),fa(65)  vol local to phantv
c                   flxtrn and dmvvec same slot in phantv
c                   flxtrn is used first, dmvvec is used later
c                   Naned in phantv
c frtbf2(1),fa(65)  vol set in fwdrag
c                   Naned in middle of fwdrag
c gsum(6)  ,fa(65)  vol local to volvel
c                   Naned in volvel
c hsubfs(1),fa(65)  vol local to statep
c                   Naned in statep
c snk(2)   ,fa(65)  jun local to vexplt, vimplt
c                   a51 and snk(1) use same slot in vimplt
c                   snk(1) is used first, a51 is used later
c                   a52 and snk(2) use same slot in vimplt
c                   snk(2) is used first, a52 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c a52(1)   ,fa(66)  vol local to preseq
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a52 and snk(2) use same slot in vimplt
c                   snk(2) is used first, a52 is used later
c                   Naned in preseq, pimplt, eqfinm
c frtbg2(1),fa(66)  vol set in fwdrag
c                   Naned in middle of fwdrag
c hsubgs(1),fa(66)  vol local to statep
c                   Naned in statep
c velvcf(1),fa(66)  vol local to phantv
c                   sbmlhf and velvcf same slot in phantv
c                   sbmlhf is used first, velvcf is used later
c                   Naned in phantv
c a53(1)   ,fa(67)  vol local to preseq
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a53 and snl(1) use same slot in vimplt
c                   snl(1) is used first, a53 is used later
c                   a54 and snl(2) use same slot in vimplt
c                   snl(2) is used first, a54 is used later
c                   Naned in preseq, pimplt, eqfinm
c betafs(1),fa(67)  vol local to statep
c                   Naned in statep
c ratdpf(1),fa(67)  vol set in fwdrag
c                   Naned in fwdrag
c snl(2)   ,fa(67)  jun local to vexplt, vimplt
c                   a53 and snl(1) use same slot in vimplt
c                   snl(1) is used first, a53 is used later
c                   a54 and snl(2) use same slot in vimplt
c                   snl(2) is used first, a54 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c velvcg(1),fa(67)  vol local to phantv
c                   sbmllf and velvcg same slot in phantv
c                   sbmllf is used first, velvcg is used later
c                   Naned in phantv
c a54(1)   ,fa(68)  vol local to preseq
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a54 and snl(2) use same slot in vimplt
c                   snl(2) is used first, a54 is used later
c                   Naned in preseq, pimplt, eqfinm
c betags(1),fa(68)  vol local to statep
c                   Naned in statep
c dstvec(1),fa(68)  vol local to phantv
c                   Naned in phantv
c a55(1)   ,fa(69)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a55 and vngen use same slot in vimplt
c                   vngen is used first, a55 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c kapafs(1),fa(69)  vol local to statep
c                   Naned in statep
c vngen(1) ,fa(69)  jun local to vexplt, vimplt
c                   a55 and vngen use same slot in vimplt
c                   vngen is used first, a55 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c a1(1)    ,fa(70)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a1 and psmf use same slot in vimplt
c                   psmf is used first, a1 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c kapags(1),fa(70)  vol local to statep
c                   Naned in statep
c psmf(1)  ,fa(70)  jun local to vexplt, vimplt
c                   a1 and psmf use same slot in vimplt
c                   psmf is used first, a1 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt, vimplt
c timinv(1),fa(70)  vol local to phantv
c                   Naned in phantv
c a2(1)    ,fa(71)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a2 and psmg use same slot in vimplt
c                   a2 is used first, psmg next, then a2 later
c                   Naned in eqfinl, pimplt, eqfinm
c areav(6) ,fa(71)  vol local to volvel, vlvela
c                   Naned in volvel, vlvelq
c cpfs(1)  ,fa(71)  vol local to statep
c                   Naned in statep
c psmg(1)  ,fa(71)  jun local to vexplt, vimplt
c                   a2 and psmg use same slot in vimplt
c                   a2 is used first, psmg next, then a2 later
c                   Naned in middle of vimplt
c                   Naned in vexplt, vimplt
c tcouri(1),fa(71)  vol local to phantv
c                   Naned in phantv
c a3(1)    ,fa(72)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   a3 and psld use same slot in vimplt
c                   psld is used first, a3 is used later
c                   Naned in eqfinl, pimplt, eqfinm
c cpgs(1)  ,fa(72)  vol local to statep
c                   Naned in statep
c nmapp(1) ,ia(72)  vol local to phantv (was nmap)
c                   Naned in phantv
c psld(1)  ,fa(72)  jun local to vexplt, vimplt
c                   a3 and psld use same slot in vimplt
c                   psld is used first, a3 is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c a4(1)    ,fa(73)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c ivert(1) ,ia(73)  vol local to phantv
c                   Naned in phantv
c sumf(1)  ,fa(73)  jun local to vexplt
c                   Naned in vexplt
c a5(1)    ,fa(74)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c nvalhi(1),ia(74)  vol local to phantv
c                   Naned in phantv
c sumg(1)  ,fa(74)  jun local to vexplt
c                   Naned in vexplt
c entfs(1) ,fa(75)  vol local to statep
c                   Naned in statep
c gxa(1)   ,fa(75)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   high and gxa same slot in preseq
c                   high is used first, gxa is used later in terms of hi
c                   Naned in eqfinl, eqfinm
c high(1)  ,fa(75)  vol set in preseq, prseqm
c                   vol set in vimplt, survive to pimplt
c                   high and gxa same slot in preseq
c                   high is used first, gxa is used later in terms of hi
c                   gxa needs to survive to eqfinl
c                   Naned in pimplt, eqfinm
c nvalhx(1),ia(75)  vol local to phantv
c                   Naned in phantv
c sumold(1),fa(75)  jun local to vexplt
c                   Naned in vexplt
c diff(1)  ,fa(76)  jun local to vexplt
c                   Naned in vexplt
c entgs(1) ,fa(76)  vol local to statep
c                   Naned in statep
c fxa(1)   ,fa(76)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   hifh and fxa same slot in preseq
c                   hifh is used first, fxa is used later in terms of hi
c                   Naned in eqfinl, eqfinm
c hifh(1)  ,fa(76)  vol set in preseq, prseqm
c                   vol set in vimplt, survive to pimplt
c                   hifh and fxa same slot in preseq
c                   hifh is used first, fxa is used later in terms of hi
c                   fxa needs to survive to eqfinl
c                   Naned in pimplt, eqfinm
c difg(1)  ,fa(77)  jun local to vexplt
c                   Naned in vexplt
c paa(1)   ,fa(77)  vol local to stvrpx, svh2x2 (was pa)
c                   Naned in stvrpx, svh2x2
c vfa(6)   ,fa(77)  vol local to volvel
c                   Naned in volvel
c difold(1),fa(78)  jun local to vexplt
c                   Naned in vexplt
c fanms(1), fa(78)  vol set in phantv, used in fwdrag
c                   Naned in fwdrag
c pbb(1)   ,fa(78)  vol local to stvrpx, svh2x2 (was pb)
c                   Naned in stvrpx, svh2x2
c agxa(1)  ,fa(79)  vol local to preseq, vimplt
c                   vol set in prseqm, survive to eqfinm
c                   agxa and figj use same slot in vimplt
c                   figj is used first, agxa is used later
c                   Naned in preseq, vimplt, eqfinm
c figj(1)  ,fa(79)  jun local to vexplt, vimplt
c                   agxa and figj use same slot in vimplt
c                   figj is used first, agxa is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c taa(1)   ,fa(79)  vol local to stvrpx, svh2x2 (was ta)
c                   Naned in stvrpx, svh2x2
c agrg(1)  ,fa(80)  vol local to eqfinl, eqfinm
c                   Naned in eqfinl, eqfinm
c dx(1)    ,fa(80)  jun local to vexplt, vimplt
c                   Naned in vexplt, vimplt
c tbb(1)   ,fa(80)  vol local to stvrpx, svh2x2 (was tb)
c                   Naned in stvrpx, svh2x2
c ff(1)    ,fa(81)  vol set vexplt, survive to preseq, eqfinl
c                   survive to prseqm, eqfinm
c                   vol local pimplt, vimplt
c                   Naned in eqfinl,pimplt,vimplt, eqfinm
c gg(1)    ,fa(82)  vol set vexplt, survive to preseq, eqfinl
c                   survive to prseqm, eqfinm
c                   vol local pimplt, vimplt
c                   Naned in eqfinl,pimplt,vimplt, eqfinm
c tsater(1),ia(82)  vol local to statep
c                   Naned in statep
c sathfx(1),fa(83)  vol set in vexplt, survive to preseq or prseqm
c                   vol local to vimplt
c                   Naned in vimplt
c                   Naned in vfinl because of multiple preseq calls in v
c vga(6)   ,fa(83)  vol local to volvel
c                   Naned in volvel
c sathgx(1),fa(84)  vol set in vexplt, survive to preseq or prseqm
c                   vol local to vimplt
c                   Naned in vimplt
c                   Naned in vfinl because of multiple preseq calls in v
c hsgf(1)  ,fa(85)  vol set in vexplt, survive to preseq or prseqm
c                   vol local to vimplt
c                   Naned in vimplt
c                   Naned in vfinl because of multiple preseq calls in v
c agug(1)  ,fa(86)  vol local to preseq, eqfinl, vimplt
c                   vol set in prseqm, survive to eqfinm
c                   agug and voidga use same slot in vimplt
c                   voidga is used first, agug is used later
c                   Naned in preseq, eqfinl, vimplt, eqfinm
c qsater(1),ia(86)  vol local to statep
c                   Naned in statep
c voidga(1),fa(86)  jun local to vexplt, vimplt
c                   agug and voidga use same slot in vimplt
c                   voidga is used first, agug is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c afuf(1)  ,fa(87)  vol local to preseq, eqfinl, vimplt
c                   vol set in prseqm, survive to eqfinm
c                   afuf and fifj use same slot in vimplt
c                   fifj is used first, afuf is used later
c                   Naned in preseq, eqfinl, vimplt, eqfinm
c fifj(1)  ,fa(87)  jun local to vexplt, vimplt
c                   afuf and fifj use same slot in vimplt
c                   fifj is used first, afuf is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c afrf(1)  ,fa(88)  vol local to eqfinl, eqfinm
c                   Naned in eqfinl, eqfinm
c voidfa(1),fa(88)  jun local to vexplt, vimplt
c                   agug is defined and used
c                   Naned in vexplt, vimplt
c arhof(1) ,fa(89)  vol local to volvel, vlvela
c                   Naned in volvel, vlvelq
c fal(1)   ,fa(89)  vol local to vexplt
c                   vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, vexplt, pimplt, eqfinm
c gal(1)   ,fa(90)  vol local to vexplt
c                   vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, vexplt, pimplt, eqfinm
c fgrw(1)  ,fa(91)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   Naned in eqfinl, eqfinm
c psumf(1) ,fa(91)  jun local to vexplt
c                   Naned in vexplt
c reynf1(1),fa(91)  vol set in fwdrag
c                   Naned in fwdrag
c highdt(1),fa(92)  vol local to eqfinl, eqfinm
c                   Naned in eqfinl, eqfinm
c psumg(1) ,fa(92)  jun local to vexplt
c                   Naned in vexplt
c reyng1(1),fa(92)  vol set in fwdrag
c                   Naned in fwdrag
c hifhdt(1),fa(93)  vol local to eqfinl, eqfinm
c                   Naned in eqfinl, eqfinm
c vmgnx(1) ,fa(93)  jun local to vexplt
c                   Naned in vexplt
c qualem(1),fa(94)  vol local to preseq, prseqm
c                   Naned in preseq, prseqm
c scrxch(1),fa(94)  jun local to vexplt
c                   Naned in vexplt
c sourci(1),fa(94)  vol local to eqfinl, eqfinm
c                   Naned in eqfinl, eqfinm
c arhog(1) ,fa(95)  vol local to volvel, vlvela
c                   Naned in volvel, vlvelq
c difr(1)  ,fa(95)  jun local to vexplt
c                   Naned in vexplt
c fp(1)    ,fa(95)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c delv(1)  ,fa(96)  vol local to vexplt, vimplt
c                   delv and gp use same slot in vimplt
c                   delv is used first, gp is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c gp(1)    ,fa(96)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   delv and gp use same slot in vimplt
c                   delv is used first, gp is used later
c                   Naned in eqfinl, pimplt, eqfinm
c cvmrv(1) ,fa(97)  jun local to vexplt
c                   Naned in vexplt
c gug(1)   ,fa(97)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c fracag(1),fa(98)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   Naned in eqfinl, eqfinm
c hlossf(1),fa(98)  jun local to vexplt, vimplt
c                   Naned in middle of vimplt
c                   Naned in vexplt
c fug(1)   ,fa(99)  vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   fug and hlossg use same slot in vimplt
c                   hlossg is used first, fug is used later
c                   Naned in eqfinl, pimplt, eqfinm
c hlossg(1),fa(99)  jun local to vexplt, vimplt
c                   fug and hlossg use same slot in vimplt
c                   hlossg is used first, fug is used later
c                   Naned in middle of vimplt
c                   Naned in vexplt
c fuf(1)   ,fa(100) vol set in preseq, survive to eqfinl
c                   vol set in prseqm, survive to eqfinm
c                   vol set in vimplt, survive to pimplt
c                   Naned in eqfinl, pimplt, eqfinm
c rhofs(1) ,fa(102) vol local to statep
c                   Naned in statep
c velfjs(1),fa(102) vol local to vfinl
c                   Naned in vfinl
c rhogs(1) ,fa(103) vol local to statep
c                   Naned in statep
c velgjs(1),fa(103) vol local to vfinl
c                   Naned in vfinl
c tf(1)    ,fa(104) vol local to statep
c                   Naned in statep
c ttg(1)   ,fa(105) vol local to statep
c                   Naned in statep
c kapaff(1),fa(106) vol local to statep, state
c                   Naned in statep, state
c kapagg(1),fa(107) vol local to statep, state
c                   Naned in statep, state
c ihld2a(1),ia(108) vol local to statep
c                   Naned in statep
c ihld4a(1),ia(109) vol local to statep
c                   Naned in statep
c sourcq(1),fa(111) vol set in vimplt, survive to pimplt
c                   Naned in pimplt
c soura(1) ,fa(112) vol set in vimplt, survive to simplt
c                   Naned in simplt
c sourn(5) ,fa(113) vol set in vimplt, survive to simplt
c                   Naned in simplt
c isptr(1) ,ia(116) vol local to vimplt
c                   Naned in vimplt
c b6(1)    ,fa(132) vol local to eqfinm
c                   Naned in eqfinm
c b7(1)    ,fa(133) vol local to eqfinm
c                   Naned in eqfinm
c aviscf(1),fa(141) jun local to vimplt
c                   Naned in vimplt
c vrug(1)  ,fa(141) vol local to simplt
c                   Naned in simplt
c aviscg(1),fa(142) jun local to vimplt
c                   Naned in vimplt
c vruf(1)  ,fa(142) vol local to simplt
c                   Naned in simplt
c gxaa(1)  ,fa(144) vol set in vimplt, survive to pimplt
c                   Naned in pimplt
c fxaa(1)  ,fa(145) vol set in vimplt, survive to pimplt
c                   Naned in pimplt
c tquala(1),fa(147) vol set in pimplt, survive to simplt
c                   Naned in simplt
c avisfs(1),fa(149) jun local to vimplt
c                   Naned in vimplt
c lrhog(1) ,fa(149) vol local to simplt
c                   Naned in simplt
c avisgs(1),fa(150) jun local to vimplt
c                   Naned in vimplt
c lrhof(1) ,fa(150) vol local to simplt
c                   Naned in simplt
c pmhig(1) ,fa(151) vol set in vexplt, survive to preseq
c                   vol local to vimplt
c                   Naned in hydro after 998 continue because of go to 2
c                   Naned in vimplt
c pshig(1) ,fa(152) vol set in vexplt, survive to preseq
c                   vol local to vimplt
c                   Naned in hydro after 998 continue because of go to 2
c                   Naned in vimplt
c avrf(1)  ,fa(153) jun local to vexplt, vimplt
c                   Naned in vexplt, vimplt
c avrg(1)  ,fa(154) jun local to vexplt, vimplt
c                   Naned in vexplt, vimplt
c stret(1) ,ia(155) vol local to packer
c                   Naned in packer
c fidxup(1),fa(160) vol set in hydro, phantv, hloss;
c                   used in jchoke, phantj, vexplt, vimplt
c                   Naned in hydro after 998 continue
c fwfxaf(3),fa(163) vol set in phantv, eccmxv, vexplt, used in fwdrag, c
c                   Naned in hydro after 998 continue
c scvjn(5) ,fa(163) jun local to vimplt
c                   Naned in vimplt
c fwfxag(3),fa(166) vol set in phantv, eccmxv, vexplt, used in fwdrag, c
c                   Naned in hydro after 998 continue
c pfinrg(1),fa(169) vol set in phantv, eccmxv, vexplt, used in fwdrag, c
c                   Naned in hydro after 998 continue
c drivew(1),ia(172) jun local to vimplt
c                   Naned in vimplt
c flomap(1),ia(172) vol local to phantv, set in eccmxv
c                   Naned in phantv
c flompj(1),ia(172) jun set in phantj
c                   jun set and returned from eccmxj to phantj
c                   Naned in phantj
c jtdjsg(1),ia(173) jun local to vimplt
c                   Naned in vimplt
c jtdjsf(1),ia(174) jun local to vimplt
c                   Naned in vimplt
c jtdjdg(1),ia(175) jun local to vimplt
c                   Naned in vimplt
c rvcrit(1),fa(175) vol local to phantv
c                   Naned in phantv
c jtdjdf(1),ia(176) jun local to vimplt
c                   Naned in vimplt
c jetjsg(1),ia(177) jun local to vimplt
c                   Naned in vimplt
c dstar(1) ,fa(178) vol set in phantv, survive to phantj
c                   Naned in phantj
c jetjsf(1),ia(178) jun local to vimplt
c                   Naned in vimplt
c jetjdg(1),ia(179) jun local to vimplt
c                   Naned in vimplt
c jetjdf(1),ia(180) jun local to vimplt
c                   Naned in vimplt
c costhe(1),fa(181) vol set phantv, survive to phantj
c                   Naned in phantj
c jetsg(1) ,ia(181) jun local to vimplt
c                   Naned in vimplt
c jetsf(1) ,ia(182) jun local to vimplt
c                   Naned in vimplt
c jetdg(1) ,ia(183) jun local to vimplt
c                   Naned in vimplt
c hiff(1)  ,fa(184) vol local to phantv
c                   Naned in phantv
c jetdf(1) ,ia(184) jun local to vimplt
c                   Naned in vimplt
c jtcons(1),fa(185) jun local to vimplt
c                   Naned in vimplt
c jtcond(1),fa(186) jun local to vimplt
c                   Naned in vimplt
c higg(1)  ,fa(187) vol local to phantv
c                   Naned in phantv
c scvj11(1),fa(187) jun local to vimplt
c                   Naned in vimplt
c scvj22(1),fa(188) jun local to vimplt
c                   Naned in vimplt
c scvj33(1),fa(189) jun local to vimplt
c                   Naned in vimplt
c scvj44(1),fa(190) jun local to vimplt
c                   Naned in vimplt
c sumvfx(3),fa(190) vol set in volvel survive to fwdrag
c                   Naned in hydro after 998 continue
c scvj5(1) ,fa(191) jun local to vimplt
c                   Naned in vimplt
c scvj6(1) ,fa(192) jun local to vimplt
c                   Naned in vimplt
c scvj7(1) ,fa(193) jun local to vimplt
c                   Naned in vimplt
c sumvgx(3),fa(193) vol set in volvel survive to fwdrag
c                   Naned in hydro after 998 continue
c scvj8(1) ,fa(194) jun local to vimplt
c                   Naned in vimplt
c difvfx(3),fa(196) vol set in volvel survive to vexplt
c                   Naned in hydro after 998 continue
c difvgx(3),fa(199) vol set in volvel survive to vexplt
c                   Naned in hydro after 998 continue
c htcfg(1) ,fa(202) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   used in vimplt, pimplt, preseq, prseqm
c                   Naned in hydro after 998 continue
c htcft(1) ,fa(203) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   used in vimplt, pimplt, preseq, prseqm
c                   Naned in hydro after 998 continue
c htcgf(1) ,fa(204) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   used in vimplt, pimplt, preseq, prseqm
c                   Naned in hydro after 998 continue
c htcgt(1) ,fa(205) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   used in vimplt, pimplt, preseq, prseqm
c                   Naned in hydro after 998 continue
c hydltf(1),fa(206) vol set in eqfinl, pimplt, survive to htfinl
c                   Naned in htfinl
c hydltg(1),fa(207) vol set in eqfinl, pimplt, survive to htfinl
c                   Naned in htfinl
c hydltt(1),fa(208) vol set in eqfinl, pimplt, survive to htfinl
c                   Naned in htfinl
c hydltp(1),fa(209) vol set in eqfinl, pimplt, survive to htfinl
c                   Naned in htfinl
c htgwff(1),fa(210) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt
c                   Naned in hydro after 998 continue
c htgwfg(1),fa(211) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt
c                   Naned in hydro after 998 continue
c htgwft(1),fa(212) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt
c                   Naned in hydro after 998 continue
c htgcgf(1),fa(213) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt
c                   Naned in hydro after 998 continue
c htgcgg(1),fa(214) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt
c                   Naned in hydro after 998 continue
c htgcgp(1),fa(215) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt
c                   Naned in hydro after 998 continue
c htgcgt(1),fa(216) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt
c                   Naned in hydro after 998 continue
c htcgp(1) ,fa(217) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt, prseqm
c                   Naned in hydro after 998 continue
c htcgg(1) ,fa(218) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt, prseqm
c                   Naned in hydro after 998 continue
c htcff(1) ,fa(219) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt, prseqm
c                   Naned in hydro after 998 continue
c htcfp(1) ,fa(220) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt, prseqm
c                   Naned in hydro after 998 continue
c htgwfp(1),fa(221) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   vol set 0 in phantv
c                   used in eqfinl, pimplt, preseq, vimplt
c                   Naned in hydro after 998 continue
c gammsw(1),fa(222) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   or simplt
c                   vol set 0 in phantv
c                   used in accum eqfinl fidisj htadv katokj phantv
c                   pimplt preseq prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) vol set 0 in tran, accum in htadv, survive to eqfinl
c                   or simplt
c                   vol set 0 in phantv
c                   used in accum eqfinl fidisj htadv phantv pimplt
c                   preseq prseqm tran vexplt vimplt zfslgj
c
c The scrtch variables that are under the control of $if def flags
c are in this section
c
$if def,mmfld
c a47s(1)  ,fa(1)   vol local to prseqm
c                   Naned in prseqm
c a57s(1)  ,fa(2)   vol local to prseqm
c                   Naned in prseqm
c a67s(1)  ,fa(3)   vol local to prseqm
c                   Naned in prseqm
c vmx(2)   ,fa(27)  vol local to volvel, vlvela
c                   Naned in volvel, vlvela
c vrhom(2) ,fa(29)  vol local to volvel, vlvela
c                   Naned in volvel, vlvela
c arhom(1) ,fa(31)  jun local to volvel, vlvela
c                   Naned in volvel, vlvela
c vma(2)   ,fa(32)  vol local to volvel
c                   Naned in volvel
c ratiom(2),fa(34)  vol local to volvel
c                   Naned in volvel
c difvmx(1),fa(101) vol set in volvel, survive to vexplt
c                   Naned in hydro after 998 continue
c ihld7(1) ,ia(101) vol local to statep
c                   Naned in statep
c ihld7a(1),ia(101) vol local to svh2x2
c                   Naned in svh2x2
c guf(1),ia(101)    vol set in preseq, survive to eqfinl
c                   Naned in eqfinl
c sumvmx(1),fa(102) vol set in volvel but never used anywhere
c                   Naned in volvel
c sorcmm(1),fa(103) vol set in vexplt, survive to eqfinm
c                   used in prseqm
c                   Naned in eqfinm
c sorcme(1),fa(104) vol set in vexplt, survive to eqfinm
c                   used in prseqm
c                   Naned in eqfinm
c sorcmn(1),fa(105) vol set in vexplt, survive to eqfinm
c                   Naned in eqfinm
c vmdpk(1) ,fa(111) jun set in vexplt, used in vfinl, prseqm
c                   Naned in vfinl
c vmdpl(1) ,fa(112) jun set in vexplt, used in vfinl, prseqm
c                   Naned in vfinl
c ihld4(1) ,ia(113) vol local to statep, eqfinm, prseqm
c                   Naned in statep, eqfinm
c vamrm(1) ,fa(113) jun local to vexplt
c                   Naned in vexplt
c a77(1)   ,fa(114) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c voidma(1),fa(114) jun local to phantj, vexplt
c                   Naned in phantj, vexplt
c a76(1)   ,fa(115) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c rhoma(1) ,fa(115) jun local to phantj, vexplt
c                   Naned in phantj, vexplt
c a67(1)   ,fa(116) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c avrm(1)  ,fa(116) jun local to vexplt
c                   Naned in vexplt
c a66(1)   ,fa(117) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c ravrm(1) ,fa(117) jun local to vexplt
c                   Naned in vexplt
c a37(1)   ,fa(118) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm, eqfinm
c rmvmj(1) ,fa(118) jun local to vexplt
c                   Naned in vexplt
c a27(1)   ,fa(119) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c fricmk(1),fa(119) jun local to vexplt
c                   Naned in vexplt
c a17(1)   ,fa(120) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c fricml(1),fa(120) jun local to vexplt
c                   Naned in vexplt
c amrm(1)  ,fa(121) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c convm(1) ,fa(121) jun local to vexplt
c                   Naned in vexplt
c amum(1)  ,fa(122) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c smk(1)   ,fa(122) jun local to vexplt
c                   Naned in vexplt
c conmm(1) ,fa(123) vol local to eqfinm
c                   Naned in eqfinm
c sml(1)   ,fa(123) jun local to vexplt
c                   Naned in vexplt
c dvelmj(1),fa(123) jun local to vfinl
c                   Naned in vfinl
c smv1(1)  ,fa(124) vol local to eqfinm
c                   Naned in eqfinm
c smvj1(1) ,fa(124) jun local to vfinl
c                   Naned in vfinl
c vmgen(1) ,fa(124) jun local to vexplt
c                   Naned in vexplt
c psmm(1)  ,fa(125) jun local to vexplt
c                   Naned in vexplt
c smv2(1)  ,fa(125) vol local to eqfinm
c                   Naned in eqfinm
c smvj2(1) ,fa(125) jun local to vfinl
c                   Naned in vfinl
c pmld(1)  ,fa(126) jun local to vexplt
c                   Naned in vexplt
c smv3(1)  ,fa(126) vol local to eqfinm
c                   Naned in eqfinm
c smvj3(1) ,fa(126) jun local to vfinl
c                   Naned in vfinl
c summ(1)  ,fa(127) jun local to vexplt
c                   Naned in vexplt
c smvj4(1) ,fa(127) jun local to vfinl
c                   Naned in vfinl
c difm(1)  ,fa(128) jun local to vexplt
c                   Naned in vexplt
c smvj5(1) ,fa(128) jun local to vfinl
c                   Naned in vfinl
c metf(1)  ,fa(129) jun local to vexplt
c                   Naned in vexplt
c smvj6(6) ,fa(129) jun local to vfinl
c                   Naned in vfinl
c metg(1)  ,fa(130) jun local to vexplt
c                   Naned in vexplt
c metm(1)  ,fa(131) jun local to vexplt
c                   Naned in vexplt
c b6(1)    ,fa(132) vol local to eqfinm
c                   Naned in eqfinm
c b7(1)    ,fa(133) vol local to eqfinm
c                   Naned in eqfinm
c metold(1),fa(132) jun local to vexplt
c                   Naned in vexplt
c amrmn(1) ,fa(134) vol local to eqfinm
c                   Naned in eqfinm
c dpstm(1) ,fa(134) jun set in phantj, survive to vexplt
c                   Naned in vexplt
c smvj7(1) ,fa(135) jun local to vfinl
c                   Naned in vfinl
c umnc(1)  ,fa(135) vol local to eqfinm
c                   Naned in eqfinm
c avrgms(1),fa(136) jun local to vexplt
c                   Naned in vexplt
c vodmnc(1),fa(136) vol local to eqfinm
c                   Naned in eqfinm
c avrfms(1),fa(137) jun local to vexplt
c                   Naned in vexplt
c avrgmp(1),fa(138) jun local to vexplt
c                   Naned in vexplt
c a27s(1)  ,fa(139) vol local to prseqm
c                   Naned in prseqm
c avrfmp(1),fa(139) jun local to vexplt
c                   Naned in vexplt
c a65(1)   ,fa(140) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c convms(1),fa(140) jun local to vexplt
c                   Naned in vexplt
c a36(1)   ,fa(141) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a71(1)   ,fa(146) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a61(1)   ,fa(147) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a64(1)   ,fa(148) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a63(1)   ,fa(149) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a46(1)   ,fa(150) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a75(1)   ,fa(151) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a74(1)   ,fa(152) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a73(1)   ,fa(153) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a72(1)   ,fa(154) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a57(1)   ,fa(156) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a56(1)   ,fa(157) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a47(1)   ,fa(158) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
c a62(1)   ,fa(159) vol set in prseqm, survive to eqfinm
c                   Naned in eqfinm
$endif
c
c
c  List 2 <=======>
c
c  This list is sorted alphabetically.
c  The subroutine names where the variable is referenced is shown
c   on the right.
c
c
c a1(1)    ,fa(70)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a11(1)   ,fa(45)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a12(1)   ,fa(46)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a14(1)   ,fa(48)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a15(1)   ,fa(49)  preseq eqfinl vimplt pimplt
c a17(1)   ,fa(120) mmfld  prseqm eqfinm
c a2(1)    ,fa(71)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a21(1)   ,fa(50)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a22(1)   ,fa(51)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a23(1)   ,fa(52)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a24(1)   ,fa(53)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a25(1)   ,fa(54)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a27(1)   ,fa(119) mmfld  prseqm eqfinm
c a27s(1)  ,fa(139) mmfld  prseqm
c a3(1)    ,fa(72)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a31(1)   ,fa(55)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a32(1)   ,fa(56)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a33(1)   ,fa(57)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a34(1)   ,fa(58)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a35(1)   ,fa(59)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a36(1)   ,fa(141) mmfld prseqm eqfinm
c a37(1)   ,fa(118) mmfld prseqm eqfinm
c a4(1)    ,fa(73)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a41(1)   ,fa(60)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a42(1)   ,fa(61)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a43(1)   ,fa(62)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a44(1)   ,fa(63)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a45(1)   ,fa(64)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a46(1)   ,fa(150) mmfld prseqm eqfinm
c a47(1)   ,fa(158) mmfld prseqm eqfinm
c a47s(1)  ,fa(1)   mmfld prseqm
c a5(1)    ,fa(74)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a51(1)   ,fa(65)  preseq prseqm eqfinm vimplt pimplt
c a51s(1)  ,fa(1)   vimplt
c a52(1)   ,fa(66)  preseq prseqm eqfinm vimplt pimplt
c a52s(1)  ,fa(2)   vimplt
c a53(1)   ,fa(67)  preseq prseqm eqfinm vimplt pimplt
c a53s(1)  ,fa(3)   vimplt
c a54(1)   ,fa(68)  preseq prseqm eqfinm vimplt pimplt
c a54s(1)  ,fa(4)   vimplt
c a55(1)   ,fa(69)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a55s(1)  ,fa(25)  vimplt
c a56(1)   ,fa(157) mmfld prseqm eqfinm
c a57(1)   ,fa(156) mmfld prseqm eqfinm
c a57s(1)  ,fa(2)   mmfld prseqm
c a61(1)   ,fa(147) mmfld prseqm eqfinm
c a62(1)   ,fa(159) mmfld prseqm eqfinm
c a63(1)   ,fa(149) mmfld prseqm eqfinm
c a64(1)   ,fa(148) mmfld prseqm eqfinm
c a65(1)   ,fa(140) mmfld prseqm eqfinm
c a66(1)   ,fa(117) mmfld prseqm eqfinm
c a67(1)   ,fa(116) mmfld prseqm eqfinm
c a67s(1)  ,fa(3)   mmfld prseqm
c a71(1)   ,fa(146) mmfld prseqm eqfinm
c a72(1)   ,fa(154) mmfld prseqm eqfinm
c a73(1)   ,fa(153) mmfld prseqm eqfinm
c a74(1)   ,fa(152) mmfld prseqm eqfinm
c a75(1)   ,fa(151) mmfld prseqm eqfinm
c a76(1)   ,fa(115) mmfld prseqm eqfinm
c a77(1)   ,fa(114) mmfld prseqm eqfinm
c afrf(1)  ,fa(88)  eqfinl eqfinm
c afuf(1)  ,fa(87)  preseq eqfinl vimplt prseqm eqfinm
c agrg(1)  ,fa(80)  eqfinl eqfinm
c agug(1)  ,fa(86)  preseq eqfinl vimplt prseqm eqfinm
c agxa(1)  ,fa(79)  preseq vimplt prseqm eqfinm
c amrm(1)  ,fa(121) mmfld prseqm eqfinm
c amrmn(1) ,fa(134) mmfld eqfinm
c amum(1)  ,fa(122) mmfld prseqm eqfinm
c angmm(1), fa(13)  pump vexplt vimplt
c areav(6) ,fa(71)  volvel vlvela
c arhof(1) ,fa(89)  volvel vlvela
c arhog(1) ,fa(95)  volvel vlvela
c arhom(1) ,fa(31)  mmfld volvel vlvela
c aterm(1) ,fa(45)  fwdrag
c avelf(1) ,fa(45)  phantv hifbub
c avelfg(1),fa(61)  phantv
c aviscf(1),fa(141) vimplt
c aviscg(1),fa(142) vimplt
c avisfs(1),fa(149) vimplt
c avisgs(1),fa(150) vimplt
c avkx(1)  ,fa(25)  phantj jchoke vexplt vimplt
c avlx(1)  ,fa(26)  phantj jchoke vexplt vimplt
c avrf(1)  ,fa(153) vexplt vimplt
c avrfg(1) ,fa(22)  vexplt
c avrfmp(1),fa(139) mmfld vexplt
c avrfms(1),fa(137) mmfld vexplt
c avrg(1)  ,fa(154) vexplt vimplt
c avrgmp(1),fa(138) mmfld vexplt
c avrgms(1),fa(136) mmfld vexplt
c avrm(1)  ,fa(116) mmfld vexplt
c axvelf(1),fa(47)  fwdrag
c b1(1)    ,fa(1)   eqfinl eqfinm pimplt
c b2(1)    ,fa(2)   eqfinl eqfinm pimplt
c b3(1)    ,fa(3)   eqfinl eqfinm pimplt
c b4(1)    ,fa(4)   eqfinl eqfinm pimplt
c b5(1)    ,fa(25)  eqfinl eqfinm
c b6(1)    ,fa(132) eqfinm
c b6(1)    ,fa(132) mmfld eqfinm
c b7(1)    ,fa(133) eqfinm
c b7(1)    ,fa(133) mmfld eqfinm
c badfw(1) ,ia(44)  fwdrag
c bb5(1)   ,fa(5)   pimplt
c beta(1)  ,fa(6)   statep
c betaf(1) ,fa(17)  statep
c betafs(1),fa(67)  statep
c betag(1) ,fa(18)  statep
c betags(1),fa(68)  statep
c borona(1),fa(5)   brntrn
c boronb(1),fa(6)   brntrn
c bterm(1) ,fa(46)  fwdrag
c bxvelg(1),fa(48)  fwdrag
c celvec(1),fa(64)  phantv
c cflno(1) ,fa(3)   brntrn
c cond(1)  ,fa(5)   eqfinl eqfinm pimplt
c conm(1)  ,fa(6)   eqfinl eqfinm pimplt
c conmf(1) ,fa(3)   eqfinl eqfinm pimplt
c conmg(1) ,fa(4)   eqfinl eqfinm pimplt
c conmm(1) ,fa(123) mmfld eqfinm
c convf(1) ,fa(61)  coev3d vexplt vimplt flux3d
c convfs(1),fa(63)  vexplt vimplt
c convg(1) ,fa(62)  coev3d vexplt vimplt flux3d
c convgs(1),fa(64)  vexplt vimplt
c convm(1) ,fa(121) mmfld vexplt
c convms(1),fa(140) mmfld vexplt
c costhe(1),fa(181) phantv phantj
c cp(1)    ,fa(8)   statep
c cpf(1)   ,fa(21)  statep
c cpfs(1)  ,fa(71)  statep
c cpg(1)   ,fa(22)  statep
c cpgs(1)  ,fa(72)  statep
c cps(1)   ,fa(57)  statep
c ctermx(1),fa(15)  fwdrag
c cvmrv(1) ,fa(97)  vexplt
c dbodxj(1),fa(4)   brntrn
c dbodxv(1),fa(1)   brntrn
c dbodx1(1),fa(7)   brntrn
c dbodx2(1),fa(8)   brntrn
c delv(1)  ,fa(96)  vexplt vimplt
c delxa(1) ,fa(5)   eqfinl eqfinm simplt
c difdpk(1),fa(28)  vimplt jchoke ccfl simplt
c difdpl(1),fa(30)  vimplt jchoke ccfl simplt
c diff(1)  ,fa(76)  vexplt
c difg(1)  ,fa(77)  vexplt
c difm(1)  ,fa(128) mmfld vexplt
c difold(1),fa(78)  vexplt
c difr(1)  ,fa(95)  vexplt
c difvfx(3),fa(196) volvel vexplt
c difvgx(3),fa(199) volvel vexplt
c difvmx(1),fa(101) mmfld volvel vexplt
c dmvvec(1),fa(65)  phantv
c dpdxfx(1),fa(6)   fwdrag
c dpdxgx(1),fa(7)   fwdrag
c dpstf(1) ,fa(1)   phantj vexplt vimplt
c dpstm(1) ,fa(134) mmfld phantj vexplt
c drho(1)  ,fa(1)   state
c drivew(1),ia(172) vimplt
c dstar(1) ,fa(178) phantv phantj
c dstvec(1),fa(68)  phantv
c dtcrnf(1),fa(3)   courn1
c dtcrng(1),fa(4)   courn1
c dtsf(1)  ,fa(41)  phantv hifbub
c dtsfm(1) ,fa(56)  phantv
c dtsfsb(1),fa(60)  phantv
c dtsfsp(1),fa(59)  phantv
c dtsg(1)  ,fa(42)  phantv
c dtsgm(1) ,fa(58)  phantv
c dtsgms(1),fa(57)  phantv
c dvelfj(1),fa(1)   vfinl
c dvelgj(1),fa(2)   vfinl
c dvelmj(1),fa(123) mmfld vfinl
c dx(1)    ,fa(80)  vexplt vimplt
c dxk(1),   fa(40)  vexplt vimplt
c dxkx(1)  ,fa(2)   phantj ccfl jchoke vexplt vimplt
c dxl(1),   fa(41)  vexplt vimplt
c dxlx(1)  ,fa(3)   phantj ccfl jchoke vexplt vimplt
c dxx(1)   ,fa(47)  vexplt vimplt
c entfs(1) ,fa(75)  statep
c entgs(1) ,fa(76)  statep
c entpy(1) ,fa(24)  statep
c entpyf(1),fa(25)  statep
c entpyg(1),fa(26)  statep
c errm(1)  ,fa(3)   state
c f2(1)    ,fa(62)  phantv
c fal(1)   ,fa(89)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c fanms(1) ,fa(78)  phantv>fwdrag
c ff(1)    ,fa(81)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c fgrw(1)  ,fa(91)  preseq eqfinl prseqm eqfinm
c fidxup(1),fa(160) hydro phantv hloss jchoke phantj vexplt vimplt
c fifj(1)  ,fa(87)  vexplt vimplt
c figj(1)  ,fa(79)  vexplt vimplt
c fjet(1)  ,fa(14)  vexplt vimplt
c flomap(1),ia(172) phantv eccmxv
c flompj(1),ia(172) phantj eccmxj
c fluxm(1) ,fa(62)  phantv
c flxtrn(1),fa(65)  losubboil phantv
c fp(1)    ,fa(95)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fpress(1),fa(64)  losubboil phantv
c fracag(1),fa(98)  preseq eqfinl prseqm eqfinm
c fracal(1),fa(47)  preseq eqfinl prseqm eqfinm
c fricfj(1),fa(40)  vexplt vimplt
c fricfk(1),fa(57)  vexplt vimplt
c fricfl(1),fa(58)  vexplt vimplt
c fricgj(1),fa(41)  vexplt vimplt
c fricgk(1),fa(59)  vexplt vimplt
c fricgl(1),fa(60)  vexplt vimplt
c fricmk(1),fa(119) mmfld vexplt
c fricml(1),fa(120) mmfld vexplt
c frlmf1(1),fa(55)  fwdrag
c frlmf2(1),fa(61)  fwdrag
c frlmg1(1),fa(56)  fwdrag
c frlmg2(1),fa(62)  fwdrag
c frtbf1(1),fa(59)  fwdrag
c frtbf2(1),fa(65)  fwdrag
c frtbg1(1),fa(60)  fwdrag
c frtbg2(1),fa(66)  fwdrag
c frtrf1(1),fa(57)  fwdrag
c frtrf2(1),fa(63)  fwdrag
c frtrg1(1),fa(58)  fwdrag
c frtrg2(1),fa(64)  fwdrag
c fuf(1)   ,fa(100) preseq eqfinl prseqm eqfinm vimplt pimplt
c fug(1)   ,fa(99)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fwf1(1)  ,fa(6)   fwdrag
c fwf2(1)  ,fa(10)  fwdrag
c fwfaf1(1),fa(4)   fwdrag
c fwfag1(1),fa(5)   fwdrag
c fwfxaf(3),fa(163) phantv eccmxv vexplt fwdrag ccfl
c fwfxag(3),fa(166) phantv eccmxv vexplt fwdrag ccfl
c fwg1(1)  ,fa(7)   fwdrag
c fwg2(1)  ,fa(13)  fwdrag
c fxa(1)   ,fa(76)  preseq eqfinl prseqm eqfinm
c fxaa(1)  ,fa(145) vimplt pimplt
c gal(1)   ,fa(90)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c gammsc(1),fa(223) accum eqfinl fidisj htadv phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
c gammsw(1),fa(222) accum eqfinl fidisj htadv katokj phantv pimplt
c                   preseq prseqm tran vexplt vimplt zfslgj
c gfwabs(1),fa(4)   fwdrag
c gg(1)    ,fa(82)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c gp(1)    ,fa(96)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gsum(6)  ,fa(65)  volvel
c guf(1)   ,fa(101) preseq eqfinl
c gug(1)   ,fa(97)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gxa(1)   ,fa(75)  preseq eqfinl prseqm eqfinm
c gxaa(1)  ,fa(144) vimplt pimplt
c hbar(1)  ,fa(5)   statep
c hfg(1)   ,fa(43)  phantv hifbub
c hgfc(1)  ,fa(38)  phantv
c hgfc1(1) ,fa(39)  phantv
c hggff(1) ,fa(28)  phantv
c hifc(1)  ,fa(53)  phantv hifbub
c hifc1(1) ,fa(54)  phantv hifbub
c hiff(1)  ,fa(184) phantv
c hifh(1)  ,fa(76)  preseq prseqm vimplt pimplt
c hifhdt(1),fa(93)  eqfinl eqfinm
c higc(1)  ,fa(51)  phantv
c higc1(1) ,fa(52)  phantv
c higg(1)  ,fa(187) phantv
c high(1)  ,fa(75)  preseq prseqm vimplt pimplt
c highdt(1),fa(92)  eqfinl eqfinm
c higsub(1),fa(55)  phantv
c hlossf(1),fa(98)  vexplt vimplt
c hlossg(1),fa(99)  vexplt vimplt
c hsgf(1)  ,fa(85)  vexplt preseq prseqm vimplt
c hsubfs(1),fa(65)  statep
c hsubgs(1),fa(66)  statep
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfg(1) ,fa(202) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcft(1) ,fa(203) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgf(1) ,fa(204) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgt(1) ,fa(205) tran htadv eqfinl vimplt pimplt preseq prseqm
c htgcgf(1),fa(213) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgg(1),fa(214) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgp(1),fa(215) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgt(1),fa(216) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwff(1),fa(210) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfg(1),fa(211) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfp(1),fa(221) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwft(1),fa(212) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c hydltf(1),fa(206) eqfinl pimplt htfinl
c hydltg(1),fa(207) eqfinl pimplt htfinl
c hydltp(1),fa(209) eqfinl pimplt htfinl
c hydltt(1),fa(208) eqfinl pimplt htfinl
c ihh1(1)  ,ia(4)   jprop stdry
c ihh2(1)  ,ia(6)   jprop stdry
c ihh3(1)  ,ia(5)   jprop
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld10(1),ia(49)  statep thcond
c ihld2(1), ia(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2a(1),ia(108) statep
c ihld3(1) ,ia(44)  vexplt statep preseq eqfinl prseqm eqfinm
c ihld4(1) ,ia(113) mmfld statep eqfinm prseqm
c ihld4a(1),ia(109) statep
c ihld5(1) ,ia(46)  statep
c ihld6(1) ,ia(47)  statep
c ihld7(1) ,ia(101) mmfld statep
c ihld7a(1),ia(101) svh2x2
c ihld8(1) ,ia(49)  svh2x2
c ihld9(1) ,ia(48)  svh2x2 statep thcond
c ireg(1)  ,fa(7)   fidisj phantj
c is23(1)  ,ia(23)  stvrpx svh2x2
c isptr(1) ,ia(116) vimplt
c ivert(1) ,ia(73)  phantv
c ja(1)    ,ia(33)  stvrpx svh2x2
c jb(1)    ,ia(34)  stvrpx svh2x2
c jetdf(1) ,ia(184) vimplt
c jetdg(1) ,ia(183) vimplt
c jetjdf(1),ia(180) vimplt
c jetjdg(1),ia(179) vimplt
c jetjsf(1),ia(178) vimplt
c jetjsg(1),ia(177) vimplt
c jetsf(1) ,ia(182) vimplt
c jetsg(1) ,ia(181) vimplt
c jhld1(1) ,ia(31)  phantv fwdrag
c jhld2(1) ,ia(32)  phantv fwdrag
c jhld3(1) ,ia(33)  phantv fwdrag
c jhld4(1) ,ia(34)  phantv
c jhld5(1) ,ia(35)  phantv
c jhld6(1) ,ia(36)  phantv
c jhld7(1) ,ia(37)  phantv
c jtcond(1),fa(186) vimplt
c jtcons(1),fa(185) vimplt
c jtdjdf(1),ia(176) vimplt
c jtdjdg(1),ia(175) vimplt
c jtdjsf(1),ia(174) vimplt
c jtdjsg(1),ia(173) vimplt
c kapa(1)  ,fa(7)   statep
c kapaf(1) ,fa(19)  statep
c kapaff(1),fa(106) statep state
c kapafs(1),fa(69)  statep
c kapag(1) ,fa(20)  statep
c kapagg(1),fa(107) statep state
c kapags(1),fa(70)  statep
c lflag(1) ,ia(41)  statep
c lflag2(1),ia(40)  statep
c lgg1(1)  ,ia(8)   jprop
c lrhof(1) ,fa(150) simplt
c lrhog(1) ,fa(149) simplt
c ltest(1) ,ia(8)   eqfinl eqfinm
c ltest2(1),ia(9)   eqfinl eqfinm
c ltest3(1),ia(10)  eqfinl eqfinm
c ltestt(1),ia(56)  vexplt
c metf(1)  ,fa(129) mmfld vexplt
c metg(1)  ,fa(130) mmfld vexplt
c metm(1)  ,fa(131) mmfld vexplt
c metold(1),fa(132) mmfld vexplt
c ncrosk(1),fa(45)  vexplt vimplt
c ncrosl(1),fa(46)  vexplt vimplt
c nix(1)   ,ia(7)   jprop
c nmapp(1) ,ia(72)  phantv
c nvalhi(1),ia(74)  phantv
c nvalhx(1),ia(75)  phantv
c paa(1)   ,fa(77)  stvrpx svh2x2
c pack(1)  ,ia(44)  packer
c pbb(1)   ,fa(78)  stvrpx svh2x2
c pfinrg(1),fa(169) phantv eccmxv vexplt fwdrag ccfl
c pk(1)    ,fa(18)  vexplt level
c pl(1)    ,fa(20)  vexplt level
c pmhig(1) ,fa(151) vexplt preseq vimplt
c pmld(1)  ,fa(126) mmfld vexplt
c pmpph(1) ,fa(17)  vexplt jchoke vimplt
c pres(1)  ,fa(2)   statep
c ps(1)    ,fa(52)  statep
c psat(1)  ,fa(10)  statep
c pshig(1) ,fa(152) vexplt    preseq vimplt
c psld(1)  ,fa(72)  vexplt vimplt
c pslope(1),fa(12)  pump vexplt vimplt
c psmf(1)  ,fa(70)  vexplt vimplt
c psmg(1)  ,fa(71)  vexplt vimplt
c psmm(1)  ,fa(125) mmfld vexplt
c psumf(1) ,fa(91)  vexplt
c psumg(1) ,fa(92)  vexplt
c pumpv(1) ,fa(15)  vimplt
c qsater(1),ia(86)  statep
c qter(1)  ,ia(36)  statep
c qual(1)  ,fa(9)   statep
c qualem(1),fa(94)  preseq prseqm
c ratdpf(1),fa(67)  fwdrag
c ratio(1) ,fa(2)   brntrn
c ratiof(6),fa(53)  volvel
c ratiog(6),fa(59)  volvel
c ratiom(2),fa(34)  mmfld volvel
c ravrf(1) ,fa(52)  vexplt vimplt
c ravrg(1) ,fa(53)  vexplt vimplt
c ravrm(1) ,fa(117) mmfld vexplt
c reynf1(1),fa(91)  fwdrag
c reynf2(1),fa(14)  fwdrag
c reyng1(1),fa(92)  fwdrag
c reyng2(1),fa(15)  fwdrag
c rfvfj(1) ,fa(53)  vexplt vimplt
c rfvfrc(1),fa(10)  vimplt
c rgvgj(1) ,fa(54)  vexplt vimplt
c rgvgrc(1),fa(11)  vimplt
c rhfg(1)  ,fa(44)  phantv hifbub
c rhocpf(1),fa(46)  phantv hifbub
c rhofa(1) ,fa(48)  vexplt vimplt
c rhofs(1) ,fa(102) statep
c rhoga(1) ,fa(49)  vexplt vimplt
c rhogs(1) ,fa(103) statep
c rhoma(1) ,fa(115) mmfld phantj vexplt
c rmvmj(1) ,fa(118) mmfld vexplt
c rvcrit(1),fa(175) phantv
c sathfx(1),fa(83)  vexplt preseq prseqm vimplt
c sathgx(1),fa(84)  vexplt preseq prseqm vimplt
c sbmlhf(1),fa(66)  losubboil phantv
c sbmllf(1),fa(67)  losubboil phantv
c scrchh(1),fa(63)  phantv
c scrxch(1),fa(94)  vexplt
c scv1(1)  ,fa(7)   eqfinl eqfinm pimplt
c scv10(1) ,fa(16)  pimplt
c scv2(1)  ,fa(8)   eqfinl eqfinm pimplt
c scv2n(5) ,fa(17)  eqfinl eqfinm pimplt
c scv3(1)  ,fa(9)   eqfinl eqfinm pimplt
c scv4(1)  ,fa(10)  eqfinl eqfinm, pimplt
c scv5(1)  ,fa(11)  eqfinl eqfinm pimplt
c scv6(1)  ,fa(12)  eqfinl eqfinm pimplt
c scv7(1)  ,fa(13)  pimplt
c scv8(1)  ,fa(14)  pimplt
c scv9(1)  ,fa(15)  pimplt
c scvj1(11),fa(14)  vfinl packer
c scvj11(1),fa(187) vimplt
c scvj12(1),fa(25)  vfinl
c scvj2(1) ,fa(15)  vfinl
c scvj22(1),fa(188) vimplt
c scvj3(1) ,fa(16)  packer vfinl
c scvj33(1),fa(189) vimplt
c scvj4(1) ,fa(17)  vfinl
c scvj44(1),fa(190) vimplt
c scvj5(1) ,fa(191) vimplt
c scvj6(1) ,fa(192) vimplt
c scvj7(1) ,fa(193) vimplt
c scvj8(1) ,fa(194) vimplt
c scvjck(1),fa(1)   vexplt jchoke vimplt
c scvjn(5) ,fa(163) vimplt
c scvtur(1),fa(16)  vexplt jchoke vimplt
c sinbt(1) ,fa(10)  phantj fidisj
c smk(1)   ,fa(122) mmfld vexplt
c sml(1)   ,fa(123) mmfld vexplt
c smv1(1)  ,fa(124) mmfld eqfinm
c smv2(1)  ,fa(125) mmfld eqfinm
c smv3(1)  ,fa(126) mmfld eqfinm
c smvj1(1) ,fa(124) mmfld vfinl
c smvj2(1) ,fa(125) mmfld vfinl
c smvj3(1) ,fa(126) mmfld vfinl
c smvj4(1) ,fa(127) mmfld vfinl
c smvj5(1) ,fa(128) mmfld vfinl
c smvj6(6) ,fa(129) mmfld vfinl
c smvj7(1) ,fa(135) mmfld vfinl
c snk(2)   ,fa(65)  vexplt vimplt
c snl(2)   ,fa(67)  vexplt vimplt
c sorcme(1),fa(104) mmfld vexplt eqfinm prseqm
c sorcmm(1),fa(103) mmfld vexplt eqfinm prseqm
c sorcmn(1),fa(105) mmfld vexplt eqfinm
c sorp(1)  ,fa(26)  eqfinl eqfinm
c soura(1) ,fa(112) vimplt simplt
c sourca(1),fa(31)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourci(1),fa(94)  eqfinl eqfinm
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c sourcn(1),fa(35)  vexplt eqfinl eqfinm vimplt pimplt
c sourcq(1),fa(111) vimplt pimplt
c sourff(1),fa(22)  pimplt simplt
c sourgg(1),fa(23)  pimplt simplt
c sourn(5) ,fa(113) vimplt simplt
c stret(1) ,ia(155) packer
c sumdpk(1),fa(27)  vimplt jchoke simplt
c sumdpl(1),fa(29)  vimpltjchoke simplt
c sumf(1)  ,fa(73)  vexplt
c sumg(1)  ,fa(74)  vexplt
c summ(1)  ,fa(127) mmfld vexplt
c sumold(1),fa(75)  vexplt
c sumvfx(3),fa(190) volvel fwdrag
c sumvgx(3),fa(193) volvel fwdrag
c sumvmx(1),fa(102) mmfld volvel
c taa(1)   ,fa(79)  stvrpx svh2x2
c tbb(1)   ,fa(80)  stvrpx svh2x2
c tcouri(1),fa(71)  phantv
c tf(1)    ,fa(104) statep
c timinv(1),fa(70)  phantv
c tloc(1),  fa(13)  vexplt vimplt
c tloc2(1) ,fa(14)  vexplt vimplt
c tnmins(1),fa(45)  simplt
c tnplus(1),fa(46)  simplt
c tpdpdx(1),fa(14)  fwdrag
c tquala(1),fa(147) pimplt simplt
c trmm(1)  ,fa(49)  phantv
c trmm1(1) ,fa(50)  phantv
c tsat(1)  ,fa(51)  statep
c tsater(1),ia(82)  statep
c tt(1)    ,fa(1)   statep
c tter(1)  ,ia(32)  statep
c ttg(1)   ,fa(105) statep
c tuf(1)   ,fa(24)  pimplt simplt
c tug(1)   ,fa(25)  pimplt simplt
c ubar(1)  ,fa(4)   statep
c ufnc(1)  ,fa(7)   eqfinl eqfinm
c ugnc(1)  ,fa(6)   eqfinl eqfinm
c umnc(1)  ,fa(135) mmfld eqfinm
c us(1)    ,fa(54)  statep
c usubf(1) ,fa(13)  statep
c usubfs(1),fa(63)  statep
c usubg(1) ,fa(14)  statep
c usubgs(1),fa(64)  statep
c vagrg(1) ,fa(15)  vexplt vimplt
c vamrm(1) ,fa(113) mmfld vexplt
c vbar(1)  ,fa(3)   statep
c velfjs(1),fa(102) vfinl
c velgjs(1),fa(103) vfinl
c velvcf(1),fa(66)  phantv
c velvcg(1),fa(67)  phantv
c vfa(6)   ,fa(77)  volvel
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vga(6)   ,fa(83)  volvel
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vma(2)   ,fa(32)  mmfld volvel
c vmdpk(1) ,fa(111) mmfld vexplt vfinl prseqm
c vmdpl(1) ,fa(112) mmfld vexplt vfinl prseqm
c vmgen(1) ,fa(124) mmfld vexplt
c vmgnx(1) ,fa(93)  vexplt
c vmx(2)   ,fa(27)  mmfld volvel vlvela
c vngen(1) ,fa(69)  vexplt vimplt
c vodmnc(1),fa(136) mmfld eqfinm
c voidaa(1),fa(4)   eqfinl
c voidfa(1),fa(88)  vexplt vimplt
c voidga(1),fa(86)  vexplt vimplt
c voidgd(1),fa(12)  phantv phantj
c voidgk(1),fa(19)  vexplt
c voidgl(1),fa(21)  vexplt
c voidgu(1),fa(11)  phantv phantj
c voidma(1),fa(114) mmfld phantj vexplt
c vpgen(1) ,fa(50)  vexplt vimplt
c vpgnx(1) ,fa(47)  vexplt
c vrhof(6) ,fa(13)  volvel vlvela
c vrhog(6) ,fa(19)  volvel vlvela
c vrhom(2) ,fa(29)  mmfld volvel vlvela
c vruf(1)  ,fa(142) simplt
c vrug(1)  ,fa(141) simplt
c vrxg(1)  ,fa(51)  simplt
c vrxgn(5) ,fa(11)  simplt
c vs(1)    ,fa(53)  statep
c vsubf(1) ,fa(11)  statep
c vsubfs(1),fa(61)  statep
c vsubg(1) ,fa(12)  statep
c vsubgs(1),fa(62)  statep
c vvfx(6)  ,fa(1)   volvel vlvela
c vvgx(6)  ,fa(7)   volvel vlvela
c xliqh(1) ,fa(47)  phantv
c xncn(1)  ,fa(11)  eqfinl
c xvaph(1) ,fa(48)  phantv
c
c
c  List 3 <=======>
c
c  This is a list of the various subroutines that use the scrtch
c    variables.  Under each subroutine name, the variables that
c    are used are arranged according to increasing slot number.
c
c  The subroutine names where the variable is referenced is shown
c   on the right.
c
c
ccccc
ccccc scrtch.H variables used in accum.F
ccccc
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c gammsc(1),fa(223) eqfinl fidisj htadv phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
c gammsw(1),fa(222) eqfinl fidisj htadv katokj phantv pimplt
c                   preseq prseqm tran vexplt vimplt zfslgj
ccccc
ccccc scrtch.H variables used in brntrn.F
ccccc
c dbodxv(1),fa(1)   brntrn
c ratio(1) ,fa(2)   brntrn
c cflno(1) ,fa(3)   brntrn
c dbodxj(1),fa(4)   brntrn
c borona(1),fa(5)   brntrn
c boronb(1),fa(6)   brntrn
c dbodx1(1),fa(7)   brntrn
c dbodx2(1),fa(8)   brntrn
ccccc
ccccc scrtch.H variables used in ccfl.F
ccccc
c dxkx(1)  ,fa(2)   phantj ccfl jchoke vexplt vimplt
c dxlx(1)  ,fa(3)   phantj ccfl jchoke vexplt vimplt
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c difdpk(1),fa(28)  vimplt jchoke ccfl simplt
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c difdpl(1),fa(30)  vimplt jchoke ccfl simplt
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c fwfxaf(3),fa(163) phantv eccmxv vexplt fwdrag ccfl
c fwfxag(3),fa(166) phantv eccmxv vexplt fwdrag ccfl
c pfinrg(1),fa(169) phantv eccmxv vexplt fwdrag ccfl
ccccc
ccccc scrtch.H variables used in coev3d.F
ccccc
c convf(1) ,fa(61)  coev3d vexplt vimplt flux3d
c convg(1) ,fa(62)  coev3d vexplt vimplt flux3d
ccccc
ccccc scrtch.H variables used in courn1.F
ccccc
c dtcrnf(1),fa(3)   courn1
c dtcrng(1),fa(4)   courn1
ccccc
ccccc scrtch.H variables used in eccmxj.F
ccccc
c flompj(1),ia(172) phantj eccmxj
ccccc
ccccc scrtch.H variables used in eccmxv.F
ccccc
c fwfxaf(3),fa(163) phantv eccmxv vexplt fwdrag ccfl
c fwfxag(3),fa(166) phantv eccmxv vexplt fwdrag ccfl
c pfinrg(1),fa(169) phantv eccmxv vexplt fwdrag ccfl
c flomap(1),ia(172) phantv eccmxv
ccccc
ccccc scrtch.H variables used in eqfinl.F
ccccc
c b1(1)    ,fa(1)   eqfinl eqfinm pimplt
c b2(1)    ,fa(2)   eqfinl eqfinm pimplt
c b3(1)    ,fa(3)   eqfinl eqfinm pimplt
c conmf(1) ,fa(3)   eqfinl eqfinm pimplt
c b4(1)    ,fa(4)   eqfinl eqfinm pimplt
c conmg(1) ,fa(4)   eqfinl eqfinm pimplt
c voidaa(1),fa(4)   eqfinl
c cond(1)  ,fa(5)   eqfinl eqfinm pimplt
c delxa(1) ,fa(5)   eqfinl eqfinm simplt
c conm(1)  ,fa(6)   eqfinl eqfinm pimplt
c ugnc(1)  ,fa(6)   eqfinl eqfinm
c scv1(1)  ,fa(7)   eqfinl eqfinm pimplt
c ufnc(1)  ,fa(7)   eqfinl eqfinm
c ltest(1) ,ia(8)   eqfinl eqfinm
c scv2(1)  ,fa(8)   eqfinl eqfinm pimplt
c ltest2(1),ia(9)   eqfinl eqfinm
c scv3(1)  ,fa(9)   eqfinl eqfinm pimplt
c ltest3(1),ia(10)  eqfinl eqfinm
c scv4(1)  ,fa(10)  eqfinl eqfinm, pimplt
c scv5(1)  ,fa(11)  eqfinl eqfinm pimplt
c xncn(1)  ,fa(11)  eqfinl
c scv6(1)  ,fa(12)  eqfinl eqfinm pimplt
c scv2n(5) ,fa(17)  eqfinl eqfinm pimplt
c b5(1)    ,fa(25)  eqfinl eqfinm
c sorp(1)  ,fa(26)  eqfinl eqfinm
c sourca(1),fa(31)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c sourcn(1),fa(35)  vexplt eqfinl eqfinm vimplt pimplt
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), ia(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld3(1) ,ia(44)  vexplt statep preseq eqfinl prseqm eqfinm
c a11(1)   ,fa(45)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a12(1)   ,fa(46)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fracal(1),fa(47)  preseq eqfinl prseqm eqfinm
c a14(1)   ,fa(48)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a15(1)   ,fa(49)  preseq eqfinl vimplt pimplt
c a21(1)   ,fa(50)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a22(1)   ,fa(51)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a23(1)   ,fa(52)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a24(1)   ,fa(53)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a25(1)   ,fa(54)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a31(1)   ,fa(55)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a32(1)   ,fa(56)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a33(1)   ,fa(57)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a34(1)   ,fa(58)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a35(1)   ,fa(59)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a41(1)   ,fa(60)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a42(1)   ,fa(61)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a43(1)   ,fa(62)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a44(1)   ,fa(63)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a45(1)   ,fa(64)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a55(1)   ,fa(69)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a1(1)    ,fa(70)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a2(1)    ,fa(71)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a3(1)    ,fa(72)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a4(1)    ,fa(73)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a5(1)    ,fa(74)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gxa(1)   ,fa(75)  preseq eqfinl prseqm eqfinm
c fxa(1)   ,fa(76)  preseq eqfinl prseqm eqfinm
c agrg(1)  ,fa(80)  eqfinl eqfinm
c ff(1)    ,fa(81)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c gg(1)    ,fa(82)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c agug(1)  ,fa(86)  preseq eqfinl vimplt prseqm eqfinm
c afuf(1)  ,fa(87)  preseq eqfinl vimplt prseqm eqfinm
c afrf(1)  ,fa(88)  eqfinl eqfinm
c fal(1)   ,fa(89)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c gal(1)   ,fa(90)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c fgrw(1)  ,fa(91)  preseq eqfinl prseqm eqfinm
c highdt(1),fa(92)  eqfinl eqfinm
c hifhdt(1),fa(93)  eqfinl eqfinm
c sourci(1),fa(94)  eqfinl eqfinm
c fp(1)    ,fa(95)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gp(1)    ,fa(96)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gug(1)   ,fa(97)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fracag(1),fa(98)  preseq eqfinl prseqm eqfinm
c fug(1)   ,fa(99)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fuf(1)   ,fa(100) preseq eqfinl prseqm eqfinm vimplt pimplt
c guf(1)   ,fa(101) preseq eqfinl
c htcfg(1) ,fa(202) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcft(1) ,fa(203) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgf(1) ,fa(204) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgt(1) ,fa(205) tran htadv eqfinl vimplt pimplt preseq prseqm
c hydltf(1),fa(206) eqfinl pimplt htfinl
c hydltg(1),fa(207) eqfinl pimplt htfinl
c hydltt(1),fa(208) eqfinl pimplt htfinl
c hydltp(1),fa(209) eqfinl pimplt htfinl
c htgwff(1),fa(210) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfg(1),fa(211) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwft(1),fa(212) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgf(1),fa(213) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgg(1),fa(214) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgp(1),fa(215) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgt(1),fa(216) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfp(1),fa(221) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c gammsw(1),fa(222) accum fidisj htadv katokj phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum fidisj htadv phantv pimplt preseq prseqm
c                   tran vexplt vimplt zfslgj
ccccc
ccccc scrtch.H variables used in eqfinm.F
ccccc
c b1(1)    ,fa(1)   eqfinl eqfinm pimplt
c b2(1)    ,fa(2)   eqfinl eqfinm pimplt
c b3(1)    ,fa(3)   eqfinl eqfinm pimplt
c conmf(1) ,fa(3)   eqfinl eqfinm pimplt
c b4(1)    ,fa(4)   eqfinl eqfinm pimplt
c conmg(1) ,fa(4)   eqfinl eqfinm pimplt
c cond(1)  ,fa(5)   eqfinl eqfinm pimplt
c delxa(1) ,fa(5)   eqfinl eqfinm simplt
c conm(1)  ,fa(6)   eqfinl eqfinm pimplt
c ugnc(1)  ,fa(6)   eqfinl eqfinm
c scv1(1)  ,fa(7)   eqfinl eqfinm pimplt
c ufnc(1)  ,fa(7)   eqfinl eqfinm
c ltest(1) ,ia(8)   eqfinl eqfinm
c scv2(1)  ,fa(8)   eqfinl eqfinm pimplt
c ltest2(1),ia(9)   eqfinl eqfinm
c scv3(1)  ,fa(9)   eqfinl eqfinm pimplt
c ltest3(1),ia(10)  eqfinl eqfinm
c scv4(1)  ,fa(10)  eqfinl eqfinm, pimplt
c scv5(1)  ,fa(11)  eqfinl eqfinm pimplt
c scv6(1)  ,fa(12)  eqfinl eqfinm pimplt
c scv2n(5) ,fa(17)  eqfinl eqfinm pimplt
c b5(1)    ,fa(25)  eqfinl eqfinm
c sorp(1)  ,fa(26)  eqfinl eqfinm
c sourca(1),fa(31)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c sourcn(1),fa(35)  vexplt eqfinl eqfinm vimplt pimplt
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), ia(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld3(1) ,ia(44)  vexplt statep preseq eqfinl prseqm eqfinm
c a11(1)   ,fa(45)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a12(1)   ,fa(46)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fracal(1),fa(47)  preseq eqfinl prseqm eqfinm
c a14(1)   ,fa(48)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a21(1)   ,fa(50)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a22(1)   ,fa(51)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a23(1)   ,fa(52)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a24(1)   ,fa(53)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a25(1)   ,fa(54)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a31(1)   ,fa(55)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a32(1)   ,fa(56)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a33(1)   ,fa(57)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a34(1)   ,fa(58)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a35(1)   ,fa(59)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a41(1)   ,fa(60)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a42(1)   ,fa(61)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a43(1)   ,fa(62)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a44(1)   ,fa(63)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a45(1)   ,fa(64)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a51(1)   ,fa(65)  preseq prseqm eqfinm vimplt pimplt
c a52(1)   ,fa(66)  preseq prseqm eqfinm vimplt pimplt
c a53(1)   ,fa(67)  preseq prseqm eqfinm vimplt pimplt
c a54(1)   ,fa(68)  preseq prseqm eqfinm vimplt pimplt
c a55(1)   ,fa(69)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a1(1)    ,fa(70)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a2(1)    ,fa(71)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a3(1)    ,fa(72)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a4(1)    ,fa(73)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a5(1)    ,fa(74)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gxa(1)   ,fa(75)  preseq eqfinl prseqm eqfinm
c fxa(1)   ,fa(76)  preseq eqfinl prseqm eqfinm
c agxa(1)  ,fa(79)  preseq vimplt prseqm eqfinm
c agrg(1)  ,fa(80)  eqfinl eqfinm
c ff(1)    ,fa(81)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c gg(1)    ,fa(82)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c agug(1)  ,fa(86)  preseq eqfinl vimplt prseqm eqfinm
c afuf(1)  ,fa(87)  preseq eqfinl vimplt prseqm eqfinm
c afrf(1)  ,fa(88)  eqfinl eqfinm
c fal(1)   ,fa(89)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c gal(1)   ,fa(90)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c fgrw(1)  ,fa(91)  preseq eqfinl prseqm eqfinm
c highdt(1),fa(92)  eqfinl eqfinm
c hifhdt(1),fa(93)  eqfinl eqfinm
c sourci(1),fa(94)  eqfinl eqfinm
c fp(1)    ,fa(95)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gp(1)    ,fa(96)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gug(1)   ,fa(97)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fracag(1),fa(98)  preseq eqfinl prseqm eqfinm
c fug(1)   ,fa(99)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fuf(1)   ,fa(100) preseq eqfinl prseqm eqfinm vimplt pimplt
c sorcmm(1),fa(103) mmfld vexplt eqfinm prseqm
c sorcme(1),fa(104) mmfld vexplt eqfinm prseqm
c sorcmn(1),fa(105) mmfld vexplt eqfinm
c ihld4(1) ,ia(113) mmfld statep eqfinm prseqm
c a77(1)   ,fa(114) mmfld prseqm eqfinm
c a76(1)   ,fa(115) mmfld prseqm eqfinm
c a67(1)   ,fa(116) mmfld prseqm eqfinm
c a66(1)   ,fa(117) mmfld prseqm eqfinm
c a37(1)   ,fa(118) mmfld prseqm eqfinm
c a27(1)   ,fa(119) mmfld prseqm eqfinm
c a17(1)   ,fa(120) mmfld prseqm eqfinm
c amrm(1)  ,fa(121) mmfld prseqm eqfinm
c amum(1)  ,fa(122) mmfld prseqm eqfinm
c conmm(1) ,fa(123) mmfld eqfinm
c smv1(1)  ,fa(124) mmfld eqfinm
c smv2(1)  ,fa(125) mmfld eqfinm
c smv3(1)  ,fa(126) mmfld eqfinm
c b6(1)    ,fa(132) mmfld eqfinm
c b7(1)    ,fa(133) mmfld eqfinm
c amrmn(1) ,fa(134) mmfld eqfinm
c umnc(1)  ,fa(135) mmfld eqfinm
c vodmnc(1),fa(136) mmfld eqfinm
c a65(1)   ,fa(140) mmfld prseqm eqfinm
c a36(1)   ,fa(141) mmfld prseqm eqfinm
c a71(1)   ,fa(146) mmfld prseqm eqfinm
c a61(1)   ,fa(147) mmfld prseqm eqfinm
c a64(1)   ,fa(148) mmfld prseqm eqfinm
c a63(1)   ,fa(149) mmfld prseqm eqfinm
c a46(1)   ,fa(150) mmfld prseqm eqfinm
c a75(1)   ,fa(151) mmfld prseqm eqfinm
c a74(1)   ,fa(152) mmfld prseqm eqfinm
c a73(1)   ,fa(153) mmfld prseqm eqfinm
c a72(1)   ,fa(154) mmfld prseqm eqfinm
c a57(1)   ,fa(156) mmfld prseqm eqfinm
c a56(1)   ,fa(157) mmfld prseqm eqfinm
c a47(1)   ,fa(158) mmfld prseqm eqfinm
c a62(1)   ,fa(159) mmfld prseqm eqfinm
ccccc
ccccc scrtch.H variables used in fidisj.F
ccccc
c gammsw(1),fa(222) accum eqfinl htadv katokj phantv pimplt
c                   preseq prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl htadv phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
c ireg(1)  ,fa(7)   fidisj phantj
c sinbt(1) ,fa(10)  phantj fidisj
ccccc
ccccc scrtch.H variables used in flux3d.F
ccccc
c convf(1) ,fa(61)  coev3d vexplt vimplt flux3d
c convg(1) ,fa(62)  coev3d vexplt vimplt flux3d
ccccc
ccccc scrtch.H variables used in fwdrag.F
ccccc
c fwfaf1(1),fa(4)   fwdrag
c gfwabs(1),fa(4)   fwdrag
c fwfag1(1),fa(5)   fwdrag
c dpdxfx(1),fa(6)   fwdrag
c fwf1(1)  ,fa(6)   fwdrag
c dpdxgx(1),fa(7)   fwdrag
c fwg1(1)  ,fa(7)   fwdrag
c fwf2(1)  ,fa(10)  fwdrag
c fwg2(1)  ,fa(13)  fwdrag
c reynf2(1),fa(14)  fwdrag
c tpdpdx(1),fa(14)  fwdrag
c ctermx(1),fa(15)  fwdrag
c reyng2(1),fa(15)  fwdrag
c jhld1(1) ,ia(31)  phantv fwdrag
c jhld2(1) ,ia(32)  phantv fwdrag
c jhld3(1) ,ia(33)  phantv fwdrag
c badfw(1) ,ia(44)  fwdrag
c aterm(1) ,fa(45)  fwdrag
c bterm(1) ,fa(46)  fwdrag
c axvelf(1),fa(47)  fwdrag
c bxvelg(1),fa(48)  fwdrag
c frlmf1(1),fa(55)  fwdrag
c frlmg1(1),fa(56)  fwdrag
c frtrf1(1),fa(57)  fwdrag
c frtrg1(1),fa(58)  fwdrag
c frtbf1(1),fa(59)  fwdrag
c frtbg1(1),fa(60)  fwdrag
c frlmf2(1),fa(61)  fwdrag
c frlmg2(1),fa(62)  fwdrag
c frtrf2(1),fa(63)  fwdrag
c frtrg2(1),fa(64)  fwdrag
c frtbf2(1),fa(65)  fwdrag
c frtbg2(1),fa(66)  fwdrag
c ratdpf(1),fa(67)  fwdrag
c fanms(1) ,fa(78)  phantv>fwdrag
c reynf1(1),fa(91)  fwdrag
c reyng1(1),fa(92)  fwdrag
c fwfxaf(3),fa(163) phantv eccmxv vexplt fwdrag ccfl
c fwfxag(3),fa(166) phantv eccmxv vexplt fwdrag ccfl
c pfinrg(1),fa(169) phantv eccmxv vexplt fwdrag ccfl
c sumvfx(3),fa(190) volvel fwdrag
c sumvgx(3),fa(193) volvel fwdrag
ccccc
ccccc scrtch.H variables used in hifbub.F
ccccc
c dtsf(1)  ,fa(41)  phantv hifbub
c hfg(1)   ,fa(43)  phantv hifbub
c rhfg(1)  ,fa(44)  phantv hifbub
c avelf(1) ,fa(45)  phantv hifbub
c rhocpf(1),fa(46)  phantv hifbub
c hifc(1)  ,fa(53)  phantv hifbub
c hifc1(1) ,fa(54)  phantv hifbub
ccccc
ccccc scrtch.H variables used in hloss.F
ccccc
c hlossf(1),fa(98)  vexplt vimplt
c hlossg(1),fa(99)  vexplt vimplt
c fidxup(1),fa(160) hydro phantv hloss jchoke phantj vexplt vimplt
ccccc
ccccc scrtch.H variables used in htadv.F
ccccc
c gammsw(1),fa(222) accum eqfinl fidisj katokj phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl fidisj phantv pimplt preseq prseqm
c                   tran vexplt vimplt zfslgj
c htcfg(1) ,fa(202) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcft(1) ,fa(203) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgf(1) ,fa(204) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgt(1) ,fa(205) tran htadv eqfinl vimplt pimplt preseq prseqm
c htgwff(1),fa(210) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfg(1),fa(211) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwft(1),fa(212) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgf(1),fa(213) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgg(1),fa(214) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgp(1),fa(215) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgt(1),fa(216) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfp(1),fa(221) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
ccccc
ccccc scrtch.H variables used in htfinl.F
ccccc
c hydltf(1),fa(206) eqfinl pimplt htfinl
c hydltg(1),fa(207) eqfinl pimplt htfinl
c hydltt(1),fa(208) eqfinl pimplt htfinl
c hydltp(1),fa(209) eqfinl pimplt htfinl
ccccc
ccccc scrtch.H variables used in hydro.F
ccccc
c fidxup(1),fa(160) hydro phantv hloss jchoke phantj vexplt vimplt
ccccc
ccccc scrtch.H variables used in jchoke.F
ccccc
c scvjck(1),fa(1)   vexplt jchoke vimplt
c dxkx(1)  ,fa(2)   phantj ccfl jchoke vexplt vimplt
c dxlx(1)  ,fa(3)   phantj ccfl jchoke vexplt vimplt
c scvtur(1),fa(16)  vexplt jchoke vimplt
c pmpph(1) ,fa(17)  vexplt jchoke vimplt
c avkx(1)  ,fa(25)  phantj jchoke vexplt vimplt
c avlx(1)  ,fa(26)  phantj jchoke vexplt vimplt
c sumdpk(1),fa(27)  vimplt jchoke simplt
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c difdpk(1),fa(28)  vimplt jchoke ccfl simplt
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c sumdpl(1),fa(29)  vimpltjchoke simplt
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c difdpl(1),fa(30)  vimplt jchoke ccfl simplt
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c fidxup(1),fa(160) hydro phantv hloss jchoke phantj vexplt vimplt
ccccc
ccccc scrtch.H variables used in jprop.F
ccccc
c ihh1(1)  ,ia(4)   jprop stdry
c ihh3(1)  ,ia(5)   jprop
c ihh2(1)  ,ia(6)   jprop stdry
c nix(1)   ,ia(7)   jprop
c lgg1(1)  ,ia(8)   jprop
ccccc
ccccc scrtch,H variables used in katokj.F
ccccc
c gammsw(1),fa(222) accum eqfinl fidisj htadv phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
ccccc
ccccc scrtch.H variables used in level.F
ccccc
c pk(1)    ,fa(18) level vexplt
c pl(1)    ,fa(20) level vexplt
ccccc
ccccc scrtch.H variables used in packer.F
ccccc
c scvj1(11),fa(14)  vfinl packer
c scvj3(1) ,fa(16)  packer vfinl
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c pack(1)  ,ia(44)  packer
c stret(1) ,ia(155) packer
ccccc
ccccc scrtch.H variables used in phantj.F
ccccc
c dpstf(1) ,fa(1)   phantj vexplt vimplt
c dxkx(1)  ,fa(2)   phantj ccfl jchoke vexplt vimplt
c dxlx(1)  ,fa(3)   phantj ccfl jchoke vexplt vimplt
c ireg(1)  ,fa(7)   fidisj phantj
c sinbt(1) ,fa(10)  phantj fidisj
c voidgu(1),fa(11)  phantv phantj
c voidgd(1),fa(12)  phantv phantj
c avkx(1)  ,fa(25)  phantj jchoke vexplt vimplt
c avlx(1)  ,fa(26)  phantj jchoke vexplt vimplt
c voidma(1),fa(114) mmfld phantj vexplt
c rhoma(1) ,fa(115) mmfld phantj vexplt
c dpstm(1) ,fa(134) mmfld phantj vexplt
c fidxup(1),fa(160) hydro phantv hloss jchoke phantj vexplt vimplt
c flompj(1),ia(172) phantj eccmxj
c dstar(1) ,fa(178) phantv phantj
c costhe(1),fa(181) phantv phantj
ccccc
ccccc scrtch.H variables used in phantv.F
ccccc
c voidgu(1),fa(11)  phantv phantj
c voidgd(1),fa(12)  phantv phantj
c hggff(1) ,fa(28)  phantv
c jhld1(1) ,ia(31)  phantv fwdrag
c jhld2(1) ,ia(32)  phantv fwdrag
c jhld3(1) ,ia(33)  phantv fwdrag
c jhld4(1) ,ia(34)  phantv
c jhld5(1) ,ia(35)  phantv
c jhld6(1) ,ia(36)  phantv
c jhld7(1) ,ia(37)  phantv
c hgfc(1)  ,fa(38)  phantv
c hgfc1(1) ,fa(39)  phantv
c dtsf(1)  ,fa(41)  phantv hifbub
c dtsg(1)  ,fa(42)  phantv
c hfg(1)   ,fa(43)  phantv hifbub
c rhfg(1)  ,fa(44)  phantv hifbub
c avelf(1) ,fa(45)  phantv hifbub
c rhocpf(1),fa(46)  phantv hifbub
c xliqh(1) ,fa(47)  phantv
c xvaph(1) ,fa(48)  phantv
c trmm(1)  ,fa(49)  phantv
c trmm1(1) ,fa(50)  phantv
c higc(1)  ,fa(51)  phantv
c higc1(1) ,fa(52)  phantv
c hifc(1)  ,fa(53)  phantv hifbub
c hifc1(1) ,fa(54)  phantv hifbub
c higsub(1),fa(55)  phantv
c dtsfm(1) ,fa(56)  phantv
c dtsgms(1),fa(57)  phantv
c dtsgm(1) ,fa(58)  phantv
c dtsfsp(1),fa(59)  phantv
c dtsfsb(1),fa(60)  phantv
c avelfg(1),fa(61)  phantv
c fluxm(1) ,fa(62)  phantv
c f2(1)    ,fa(62)  phantv
c scrchh(1),fa(63)  phantv
c celvec(1),fa(64)  phantv
c fpress(1),fa(64)  losubboil phantv
c dmvvec(1),fa(65)  phantv
c flxtrn(1),fa(65)  losubboil phantv
c sbmlhf(1),fa(66)  losubboil phantv
c velvcf(1),fa(66)  phantv
c sbmllf(1),fa(67)  losubboil phantv
c velvcg(1),fa(67)  phantv
c dstvec(1),fa(68)  phantv
c timinv(1),fa(70)  phantv
c tcouri(1),fa(71)  phantv
c nmapp(1) ,ia(72)  phantv
c ivert(1) ,ia(73)  phantv
c nvalhi(1),ia(74)  phantv
c nvalhx(1),ia(75)  phantv
c fanms(1) ,fa(78)  phantv>fwdrag
c fidxup(1),fa(160) hydro phantv hloss jchoke phantj vexplt vimplt
c fwfxaf(3),fa(163) phantv eccmxv vexplt fwdrag ccfl
c fwfxag(3),fa(166) phantv eccmxv vexplt fwdrag ccfl
c pfinrg(1),fa(169) phantv eccmxv vexplt fwdrag ccfl
c flomap(1),ia(172) phantv eccmxv
c rvcrit(1),fa(175) phantv
c dstar(1) ,fa(178) phantv phantj
c costhe(1),fa(181) phantv phantj
c hiff(1)  ,fa(184) phantv
c higg(1)  ,fa(187) phantv
c htgwff(1),fa(210) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfg(1),fa(211) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwft(1),fa(212) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgf(1),fa(213) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgg(1),fa(214) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgp(1),fa(215) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgt(1),fa(216) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfp(1),fa(221) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
ccccc
ccccc scrtch.H variables used in pimplt.F
ccccc
c b1(1)    ,fa(1)   eqfinl eqfinm pimplt
c b2(1)    ,fa(2)   eqfinl eqfinm pimplt
c b3(1)    ,fa(3)   eqfinl eqfinm pimplt
c conmf(1) ,fa(3)   eqfinl eqfinm pimplt
c b4(1)    ,fa(4)   eqfinl eqfinm pimplt
c conmg(1) ,fa(4)   eqfinl eqfinm pimplt
c bb5(1)   ,fa(5)   pimplt
c cond(1)  ,fa(5)   eqfinl eqfinm pimplt
c conm(1)  ,fa(6)   eqfinl eqfinm pimplt
c scv1(1)  ,fa(7)   eqfinl eqfinm pimplt
c scv2(1)  ,fa(8)   eqfinl eqfinm pimplt
c scv3(1)  ,fa(9)   eqfinl eqfinm pimplt
c scv4(1)  ,fa(10)  eqfinl eqfinm, pimplt
c scv5(1)  ,fa(11)  eqfinl eqfinm pimplt
c scv6(1)  ,fa(12)  eqfinl eqfinm pimplt
c scv7(1)  ,fa(13)  pimplt
c scv8(1)  ,fa(14)  pimplt
c scv9(1)  ,fa(15)  pimplt
c scv10(1) ,fa(16)  pimplt
c scv2n(5) ,fa(17)  eqfinl eqfinm pimplt
c sourff(1),fa(22)  pimplt simplt
c sourgg(1),fa(23)  pimplt simplt
c tuf(1)   ,fa(24)  pimplt simplt
c tug(1)   ,fa(25)  pimplt simplt
c sourca(1),fa(31)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c sourcn(1),fa(35)  vexplt eqfinl eqfinm vimplt pimplt
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), ia(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c a11(1)   ,fa(45)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a12(1)   ,fa(46)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a14(1)   ,fa(48)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a15(1)   ,fa(49)  preseq eqfinl vimplt pimplt
c a21(1)   ,fa(50)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a22(1)   ,fa(51)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a23(1)   ,fa(52)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a24(1)   ,fa(53)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a25(1)   ,fa(54)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a31(1)   ,fa(55)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a32(1)   ,fa(56)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a33(1)   ,fa(57)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a34(1)   ,fa(58)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a35(1)   ,fa(59)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a41(1)   ,fa(60)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a42(1)   ,fa(61)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a43(1)   ,fa(62)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a44(1)   ,fa(63)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a45(1)   ,fa(64)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a51(1)   ,fa(65)  preseq prseqm eqfinm vimplt pimplt
c a52(1)   ,fa(66)  preseq prseqm eqfinm vimplt pimplt
c a53(1)   ,fa(67)  preseq prseqm eqfinm vimplt pimplt
c a54(1)   ,fa(68)  preseq prseqm eqfinm vimplt pimplt
c a55(1)   ,fa(69)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a1(1)    ,fa(70)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a2(1)    ,fa(71)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a3(1)    ,fa(72)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a4(1)    ,fa(73)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a5(1)    ,fa(74)  preseq eqfinl prseqm eqfinm vimplt pimplt
c high(1)  ,fa(75)  preseq prseqm vimplt pimplt
c hifh(1)  ,fa(76)  preseq prseqm vimplt pimplt
c ff(1)    ,fa(81)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c gg(1)    ,fa(82)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c fal(1)   ,fa(89)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c gal(1)   ,fa(90)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c fp(1)    ,fa(95)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gp(1)    ,fa(96)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gug(1)   ,fa(97)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fug(1)   ,fa(99)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fuf(1)   ,fa(100) preseq eqfinl prseqm eqfinm vimplt pimplt
c sourcq(1),fa(111) vimplt pimplt
c gxaa(1)  ,fa(144) vimplt pimplt
c fxaa(1)  ,fa(145) vimplt pimplt
c tquala(1),fa(147) pimplt simplt
c htcfg(1) ,fa(202) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcft(1) ,fa(203) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgf(1) ,fa(204) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgt(1) ,fa(205) tran htadv eqfinl vimplt pimplt preseq prseqm
c hydltf(1),fa(206) eqfinl pimplt htfinl
c hydltg(1),fa(207) eqfinl pimplt htfinl
c hydltt(1),fa(208) eqfinl pimplt htfinl
c hydltp(1),fa(209) eqfinl pimplt htfinl
c htgwff(1),fa(210) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfg(1),fa(211) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwft(1),fa(212) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgf(1),fa(213) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgg(1),fa(214) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgp(1),fa(215) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgt(1),fa(216) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfp(1),fa(221) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c gammsw(1),fa(222) accum eqfinl fidisj htadv katokj pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl fidisj htadv pimplt preseq prseqm
c                   tran vexplt vimplt zfslgj
ccccc
ccccc scrtch.H variables used in preseq.F
ccccc
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c sourca(1),fa(31)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), ia(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld3(1) ,ia(44)  vexplt statep preseq eqfinl prseqm eqfinm
c a11(1)   ,fa(45)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a12(1)   ,fa(46)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fracal(1),fa(47)  preseq eqfinl prseqm eqfinm
c a14(1)   ,fa(48)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a15(1)   ,fa(49)  preseq eqfinl vimplt pimplt
c a21(1)   ,fa(50)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a22(1)   ,fa(51)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a23(1)   ,fa(52)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a24(1)   ,fa(53)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a25(1)   ,fa(54)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a31(1)   ,fa(55)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a32(1)   ,fa(56)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a33(1)   ,fa(57)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a34(1)   ,fa(58)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a35(1)   ,fa(59)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a41(1)   ,fa(60)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a42(1)   ,fa(61)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a43(1)   ,fa(62)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a44(1)   ,fa(63)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a45(1)   ,fa(64)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a51(1)   ,fa(65)  preseq prseqm eqfinm vimplt pimplt
c a52(1)   ,fa(66)  preseq prseqm eqfinm vimplt pimplt
c a53(1)   ,fa(67)  preseq prseqm eqfinm vimplt pimplt
c a54(1)   ,fa(68)  preseq prseqm eqfinm vimplt pimplt
c a55(1)   ,fa(69)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a1(1)    ,fa(70)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a2(1)    ,fa(71)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a3(1)    ,fa(72)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a4(1)    ,fa(73)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a5(1)    ,fa(74)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gxa(1)   ,fa(75)  preseq eqfinl prseqm eqfinm
c high(1)  ,fa(75)  preseq prseqm vimplt pimplt
c fxa(1)   ,fa(76)  preseq eqfinl prseqm eqfinm
c hifh(1)  ,fa(76)  preseq prseqm vimplt pimplt
c agxa(1)  ,fa(79)  preseq vimplt prseqm eqfinm
c ff(1)    ,fa(81)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c gg(1)    ,fa(82)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c sathfx(1),fa(83)  vexplt preseq prseqm vimplt
c sathgx(1),fa(84)  vexplt preseq prseqm vimplt
c hsgf(1)  ,fa(85)  vexplt preseq prseqm vimplt
c agug(1)  ,fa(86)  preseq eqfinl vimplt prseqm eqfinm
c afuf(1)  ,fa(87)  preseq eqfinl vimplt prseqm eqfinm
c fal(1)   ,fa(89)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c gal(1)   ,fa(90)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c fgrw(1)  ,fa(91)  preseq eqfinl prseqm eqfinm
c qualem(1),fa(94)  preseq prseqm
c fp(1)    ,fa(95)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gp(1)    ,fa(96)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gug(1)   ,fa(97)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fracag(1),fa(98)  preseq eqfinl prseqm eqfinm
c fug(1)   ,fa(99)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fuf(1)   ,fa(100) preseq eqfinl prseqm eqfinm vimplt pimplt
c guf(1)   ,fa(101) preseq eqfinl
c pmhig(1) ,fa(151) vexplt preseq vimplt
c pshig(1) ,fa(152) vexplt    preseq vimplt
c htcfg(1) ,fa(202) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcft(1) ,fa(203) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgf(1) ,fa(204) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgt(1) ,fa(205) tran htadv eqfinl vimplt pimplt preseq prseqm
c htgwff(1),fa(210) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfg(1),fa(211) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwft(1),fa(212) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgf(1),fa(213) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgg(1),fa(214) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgp(1),fa(215) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgt(1),fa(216) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfp(1),fa(221) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c gammsw(1),fa(222) accum eqfinl fidisj htadv katokj phantv pimplt
c                   prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl fidisj htadv phantv pimplt prseqm
c                   tran vexplt vimplt zfslgj
ccccc
ccccc scrtch.H variables used in prseqm.F
ccccc
c a47s(1)  ,fa(1)   mmfld prseqm
c a57s(1)  ,fa(2)   mmfld prseqm
c a67s(1)  ,fa(3)   mmfld prseqm
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c sourca(1),fa(31)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), ia(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld3(1) ,ia(44)  vexplt statep preseq eqfinl prseqm eqfinm
c a11(1)   ,fa(45)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a12(1)   ,fa(46)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fracal(1),fa(47)  preseq eqfinl prseqm eqfinm
c a14(1)   ,fa(48)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a21(1)   ,fa(50)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a22(1)   ,fa(51)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a23(1)   ,fa(52)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a24(1)   ,fa(53)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a25(1)   ,fa(54)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a31(1)   ,fa(55)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a32(1)   ,fa(56)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a33(1)   ,fa(57)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a34(1)   ,fa(58)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a35(1)   ,fa(59)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a41(1)   ,fa(60)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a42(1)   ,fa(61)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a43(1)   ,fa(62)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a44(1)   ,fa(63)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a45(1)   ,fa(64)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a51(1)   ,fa(65)  preseq prseqm eqfinm vimplt pimplt
c a52(1)   ,fa(66)  preseq prseqm eqfinm vimplt pimplt
c a53(1)   ,fa(67)  preseq prseqm eqfinm vimplt pimplt
c a54(1)   ,fa(68)  preseq prseqm eqfinm vimplt pimplt
c a55(1)   ,fa(69)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a1(1)    ,fa(70)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a2(1)    ,fa(71)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a3(1)    ,fa(72)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a4(1)    ,fa(73)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a5(1)    ,fa(74)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gxa(1)   ,fa(75)  preseq eqfinl prseqm eqfinm
c high(1)  ,fa(75)  preseq prseqm vimplt pimplt
c fxa(1)   ,fa(76)  preseq eqfinl prseqm eqfinm
c hifh(1)  ,fa(76)  preseq prseqm vimplt pimplt
c agxa(1)  ,fa(79)  preseq vimplt prseqm eqfinm
c ff(1)    ,fa(81)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c gg(1)    ,fa(82)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c sathfx(1),fa(83)  vexplt preseq prseqm vimplt
c sathgx(1),fa(84)  vexplt preseq prseqm vimplt
c hsgf(1)  ,fa(85)  vexplt preseq prseqm vimplt
c agug(1)  ,fa(86)  preseq eqfinl vimplt prseqm eqfinm
c afuf(1)  ,fa(87)  preseq eqfinl vimplt prseqm eqfinm
c fal(1)   ,fa(89)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c gal(1)   ,fa(90)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c fgrw(1)  ,fa(91)  preseq eqfinl prseqm eqfinm
c qualem(1),fa(94)  preseq prseqm
c fp(1)    ,fa(95)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gp(1)    ,fa(96)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gug(1)   ,fa(97)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fracag(1),fa(98)  preseq eqfinl prseqm eqfinm
c fug(1)   ,fa(99)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fuf(1)   ,fa(100) preseq eqfinl prseqm eqfinm vimplt pimplt
c sorcmm(1),fa(103) mmfld vexplt eqfinm prseqm
c sorcme(1),fa(104) mmfld vexplt eqfinm prseqm
c vmdpk(1) ,fa(111) mmfld vexplt vfinl prseqm
c vmdpl(1) ,fa(112) mmfld vexplt vfinl prseqm
c ihld4(1) ,ia(113) mmfld statep eqfinm prseqm
c a77(1)   ,fa(114) mmfld prseqm eqfinm
c a76(1)   ,fa(115) mmfld prseqm eqfinm
c a67(1)   ,fa(116) mmfld prseqm eqfinm
c a66(1)   ,fa(117) mmfld prseqm eqfinm
c a37(1)   ,fa(118) mmfld prseqm eqfinm
c a27(1)   ,fa(119) mmfld prseqm eqfinm
c a17(1)   ,fa(120) mmfld prseqm eqfinm
c amrm(1)  ,fa(121) mmfld prseqm eqfinm
c amum(1)  ,fa(122) mmfld prseqm eqfinm
c a27s(1)  ,fa(139) mmfld prseqm
c a65(1)   ,fa(140) mmfld prseqm eqfinm
c a36(1)   ,fa(141) mmfld prseqm eqfinm
c a71(1)   ,fa(146) mmfld prseqm eqfinm
c a61(1)   ,fa(147) mmfld prseqm eqfinm
c a64(1)   ,fa(148) mmfld prseqm eqfinm
c a63(1)   ,fa(149) mmfld prseqm eqfinm
c a46(1)   ,fa(150) mmfld prseqm eqfinm
c a75(1)   ,fa(151) mmfld prseqm eqfinm
c a74(1)   ,fa(152) mmfld prseqm eqfinm
c a73(1)   ,fa(153) mmfld prseqm eqfinm
c a72(1)   ,fa(154) mmfld prseqm eqfinm
c a57(1)   ,fa(156) mmfld prseqm eqfinm
c a56(1)   ,fa(157) mmfld prseqm eqfinm
c a62(1)   ,fa(159) mmfld prseqm eqfinm
c a47(1)   ,fa(158) mmfld prseqm eqfinm
c htcfg(1) ,fa(202) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcft(1) ,fa(203) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgf(1) ,fa(204) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgt(1) ,fa(205) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c gammsw(1),fa(222) accum eqfinl fidisj htadv katokj phantv pimplt
c                   preseq tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl fidisj htadv phantv pimplt preseq
c                   tran vexplt vimplt zfslgj
ccccc
ccccc scrtch.H variables used in pump.F
ccccc
c pslope(1),fa(12)  pump vexplt vimplt
c angmm(1), fa(13)  pump vexplt vimplt
c pumpv(1) ,fa(15)  vimplt
ccccc
ccccc scrtch.H variables used in simplt.F
ccccc
c delxa(1) ,fa(5)   eqfinl eqfinm simplt
c vrxgn(5) ,fa(11)  simplt
c sourff(1),fa(22)  pimplt simplt
c sourgg(1),fa(23)  pimplt simplt
c tuf(1)   ,fa(24)  pimplt simplt
c tug(1)   ,fa(25)  pimplt simplt
c sumdpk(1),fa(27)  vimplt jchoke simplt
c difdpk(1),fa(28)  vimplt jchoke ccfl simplt
c sumdpl(1),fa(29)  vimpltjchoke simplt
c difdpl(1),fa(30)  vimplt jchoke ccfl simplt
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), ia(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c tnmins(1),fa(45)  simplt
c tnplus(1),fa(46)  simplt
c vrxg(1)  ,fa(51)  simplt
c soura(1) ,fa(112) vimplt simplt
c sourn(5) ,fa(113) vimplt simplt
c vrug(1)  ,fa(141) simplt
c vruf(1)  ,fa(142) simplt
c tquala(1),fa(147) pimplt simplt
c lrhog(1) ,fa(149) simplt
c lrhof(1) ,fa(150) simplt
ccccc
ccccc scrtch.H variables used in state.F
ccccc
c drho(1)  ,fa(1)   state
c errm(1)  ,fa(3)   state
c kapaff(1),fa(106) statep state
c kapagg(1),fa(107) statep state
ccccc
ccccc scrtch.H variables used in statep.F
ccccc
c tt(1)    ,fa(1)   statep
c pres(1)  ,fa(2)   statep
c vbar(1)  ,fa(3)   statep
c ubar(1)  ,fa(4)   statep
c hbar(1)  ,fa(5)   statep
c beta(1)  ,fa(6)   statep
c kapa(1)  ,fa(7)   statep
c cp(1)    ,fa(8)   statep
c qual(1)  ,fa(9)   statep
c psat(1)  ,fa(10)  statep
c vsubf(1) ,fa(11)  statep
c vsubg(1) ,fa(12)  statep
c usubf(1) ,fa(13)  statep
c usubg(1) ,fa(14)  statep
c betaf(1) ,fa(17)  statep
c betag(1) ,fa(18)  statep
c kapaf(1) ,fa(19)  statep
c kapag(1) ,fa(20)  statep
c cpf(1)   ,fa(21)  statep
c cpg(1)   ,fa(22)  statep
c entpy(1) ,fa(24)  statep
c entpyf(1),fa(25)  statep
c entpyg(1),fa(26)  statep
c tter(1)  ,ia(32)  statep
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c qter(1)  ,ia(36)  statep
c lflag2(1),ia(40)  statep
c lflag(1) ,ia(41)  statep
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), ia(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld3(1) ,ia(44)  vexplt statep preseq eqfinl prseqm eqfinm
c ihld5(1) ,ia(46)  statep
c ihld6(1) ,ia(47)  statep
c ihld9(1) ,ia(48)  svh2x2 statep thcond
c ihld10(1),ia(49)  statep thcond
c tsat(1)  ,fa(51)  statep
c ps(1)    ,fa(52)  statep
c vs(1)    ,fa(53)  statep
c us(1)    ,fa(54)  statep
c cps(1)   ,fa(57)  statep
c vsubfs(1),fa(61)  statep
c vsubgs(1),fa(62)  statep
c usubfs(1),fa(63)  statep
c usubgs(1),fa(64)  statep
c hsubfs(1),fa(65)  statep
c hsubgs(1),fa(66)  statep
c betafs(1),fa(67)  statep
c betags(1),fa(68)  statep
c kapafs(1),fa(69)  statep
c kapags(1),fa(70)  statep
c cpfs(1)  ,fa(71)  statep
c cpgs(1)  ,fa(72)  statep
c entfs(1) ,fa(75)  statep
c entgs(1) ,fa(76)  statep
c tsater(1),ia(82)  statep
c qsater(1),ia(86)  statep
c ihld7(1) ,ia(101) mmfld statep
c rhofs(1) ,fa(102) statep
c rhogs(1) ,fa(103) statep
c tf(1)    ,fa(104) statep
c ttg(1)   ,fa(105) statep
c kapaff(1),fa(106) statep state
c kapagg(1),fa(107) statep state
c ihld2a(1),ia(108) statep
c ihld4a(1),ia(109) statep
c ihld4(1) ,ia(113) mmfld statep eqfinm prseqm
ccccc
ccccc scrtch.H variables used in stdry.F
ccccc
c ihh1(1)  ,ia(4)   jprop stdry
c ihh2(1)  ,ia(6)   jprop stdry
ccccc
ccccc scrtch.H variables used in stvrpx.F
ccccc
c is23(1)  ,ia(23)  stvrpx svh2x2
c ja(1)    ,ia(33)  stvrpx svh2x2
c jb(1)    ,ia(34)  stvrpx svh2x2
c paa(1)   ,fa(77)  stvrpx svh2x2
c pbb(1)   ,fa(78)  stvrpx svh2x2
c taa(1)   ,fa(79)  stvrpx svh2x2
c tbb(1)   ,fa(80)  stvrpx svh2x2
ccccc
ccccc scrtch.H variables used in svh2x2.F
ccccc
c is23(1)  ,ia(23)  stvrpx svh2x2
c ja(1)    ,ia(33)  stvrpx svh2x2
c jb(1)    ,ia(34)  stvrpx svh2x2
c ihld9(1) ,ia(48)  svh2x2 statep thcond
c ihld8(1) ,ia(49)  svh2x2
c paa(1)   ,fa(77)  stvrpx svh2x2
c pbb(1)   ,fa(78)  stvrpx svh2x2
c taa(1)   ,fa(79)  stvrpx svh2x2
c tbb(1)   ,fa(80)  stvrpx svh2x2
c ihld7a(1),ia(101) svh2x2
ccccc
ccccc scrtch.H variables used in tran.F
ccccc
c htcfg(1) ,fa(202) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcft(1) ,fa(203) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgf(1) ,fa(204) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgt(1) ,fa(205) tran htadv eqfinl vimplt pimplt preseq prseqm
c htgwff(1),fa(210) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfg(1),fa(211) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwft(1),fa(212) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgf(1),fa(213) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgg(1),fa(214) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgp(1),fa(215) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgt(1),fa(216) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfp(1),fa(221) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c gammsw(1),fa(222) accum eqfinl fidisj htadv katokj phantv pimplt
c                   preseq prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl fidisj htadv phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslg
ccccc
ccccc scrtch.H variables used in vexplt.F
ccccc
c dpstf(1) ,fa(1)   phantj vexplt vimplt
c scvjck(1),fa(1)   vexplt jchoke vimplt
c dxkx(1)  ,fa(2)   phantj ccfl jchoke vexplt vimplt
c dxlx(1)  ,fa(3)   phantj ccfl jchoke vexplt vimplt
c pslope(1),fa(12)  pump vexplt vimplt
c angmm(1), fa(13)  pump vexplt vimplt
c tloc(1),  fa(13)  vexplt vimplt
c fjet(1)  ,fa(14)  vexplt vimplt
c tloc2(1) ,fa(14)  vexplt vimplt
c vagrg(1) ,fa(15)  vexplt vimplt
c scvtur(1),fa(16)  vexplt jchoke vimplt
c pmpph(1) ,fa(17)  vexplt jchoke vimplt
c pk(1)    ,fa(18)  vexplt
c voidgk(1),fa(19)  vexplt
c pl(1)    ,fa(20)  vexplt
c voidgl(1),fa(21)  vexplt
c avrfg(1) ,fa(22)  vexplt
c avkx(1)  ,fa(25)  phantj jchoke vexplt vimplt
c avlx(1)  ,fa(26)  phantj jchoke vexplt vimplt
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c sourca(1),fa(31)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c sourcn(1),fa(35)  vexplt eqfinl eqfinm vimplt pimplt
c dxk(1),   fa(40)  vexplt vimplt
c fricfj(1),fa(40)  vexplt vimplt
c dxl(1),   fa(41)  vexplt vimplt
c fricgj(1),fa(41)  vexplt vimplt
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), fa(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld3(1) ,ia(44)  vexplt statep preseq eqfinl prseqm eqfinm
c ncrosk(1),fa(45)  vexplt vimplt
c ncrosl(1),fa(46)  vexplt vimplt
c dxx(1)   ,fa(47)  vexplt vimplt
c vpgnx(1) ,fa(47)  vexplt
c rhofa(1) ,fa(48)  vexplt vimplt
c rhoga(1) ,fa(49)  vexplt vimplt
c vpgen(1) ,fa(50)  vexplt vimplt
c ravrf(1) ,fa(52)  vexplt vimplt
c ravrg(1) ,fa(53)  vexplt vimplt
c rfvfj(1) ,fa(53)  vexplt vimplt
c rgvgj(1) ,fa(54)  vexplt vimplt
c ltestt(1),ia(56)  vexplt
c fricfk(1),fa(57)  vexplt vimplt
c fricfl(1),fa(58)  vexplt vimplt
c fricgk(1),fa(59)  vexplt vimplt
c fricgl(1),fa(60)  vexplt vimplt
c convf(1) ,fa(61)  coev3d vexplt vimplt flux3d
c convg(1) ,fa(62)  coev3d vexplt vimplt flux3d
c convfs(1),fa(63)  vexplt vimplt
c convgs(1),fa(64)  vexplt vimplt
c snk(2)   ,fa(65)  vexplt vimplt
c snl(2)   ,fa(67)  vexplt vimplt
c vngen(1) ,fa(69)  vexplt vimplt
c psmf(1)  ,fa(70)  vexplt vimplt
c psmg(1)  ,fa(71)  vexplt vimplt
c psld(1)  ,fa(72)  vexplt vimplt
c sumf(1)  ,fa(73)  vexplt
c sumg(1)  ,fa(74)  vexplt
c sumold(1),fa(75)  vexplt
c diff(1)  ,fa(76)  vexplt
c difg(1)  ,fa(77)  vexplt
c difold(1),fa(78)  vexplt
c figj(1)  ,fa(79)  vexplt vimplt
c dx(1)    ,fa(80)  vexplt vimplt
c ff(1)    ,fa(81)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c gg(1)    ,fa(82)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c sathfx(1),fa(83)  vexplt preseq prseqm vimplt
c sathgx(1),fa(84)  vexplt preseq prseqm vimplt
c hsgf(1)  ,fa(85)  vexplt preseq prseqm vimplt
c voidga(1),fa(86)  vexplt vimplt
c fifj(1)  ,fa(87)  vexplt vimplt
c voidfa(1),fa(88)  vexplt vimplt
c fal(1)   ,fa(89)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c gal(1)   ,fa(90)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c psumf(1) ,fa(91)  vexplt
c psumg(1) ,fa(92)  vexplt
c vmgnx(1) ,fa(93)  vexplt
c scrxch(1),fa(94)  vexplt
c difr(1)  ,fa(95)  vexplt
c delv(1)  ,fa(96)  vexplt vimplt
c cvmrv(1) ,fa(97)  vexplt
c hlossf(1),fa(98)  vexplt vimplt
c hlossg(1),fa(99)  vexplt vimplt
c difvmx(1),fa(101) mmfld volvel vexplt
c sorcmm(1),fa(103) mmfld vexplt eqfinm prseqm
c sorcme(1),fa(104) mmfld vexplt eqfinm prseqm
c sorcmn(1),fa(105) mmfld vexplt eqfinm
c vmdpk(1) ,fa(111) mmfld vexplt vfinl prseqm
c vmdpl(1) ,fa(112) mmfld vexplt vfinl prseqm
c vamrm(1) ,fa(113) mmfld vexplt
c voidma(1),fa(114) mmfld phantj vexplt
c rhoma(1) ,fa(115) mmfld phantj vexplt
c avrm(1)  ,fa(116) mmfld vexplt
c ravrm(1) ,fa(117) mmfld vexplt
c rmvmj(1) ,fa(118) mmfld vexplt
c fricmk(1),fa(119) mmfld vexplt
c fricml(1),fa(120) mmfld vexplt
c convm(1) ,fa(121) mmfld vexplt
c smk(1)   ,fa(122) mmfld vexplt
c sml(1)   ,fa(123) mmfld vexplt
c vmgen(1) ,fa(124) mmfld vexplt
c psmm(1)  ,fa(125) mmfld vexplt
c pmld(1)  ,fa(126) mmfld vexplt
c summ(1)  ,fa(127) mmfld vexplt
c difm(1)  ,fa(128) mmfld vexplt
c metf(1)  ,fa(129) mmfld vexplt
c metg(1)  ,fa(130) mmfld vexplt
c metm(1)  ,fa(131) mmfld vexplt
c metold(1),fa(132) mmfld vexplt
c dpstm(1) ,fa(134) mmfld phantj vexplt
c avrgms(1),fa(136) mmfld vexplt
c avrfms(1),fa(137) mmfld vexplt
c avrgmp(1),fa(138) mmfld vexplt
c avrfmp(1),fa(139) mmfld vexplt
c convms(1),fa(140) mmfld vexplt
c pmhig(1) ,fa(151) vexplt preseq vimplt
c pshig(1) ,fa(152) vexplt    preseq vimplt
c avrf(1)  ,fa(153) vexplt vimplt
c avrg(1)  ,fa(154) vexplt vimplt
c fidxup(1),fa(160) hydro phantv hloss jchoke phantj vexplt vimplt
c fwfxaf(3),fa(163) phantv eccmxv vexplt fwdrag ccfl
c fwfxag(3),fa(166) phantv eccmxv vexplt fwdrag ccfl
c pfinrg(1),fa(169) phantv eccmxv vexplt fwdrag ccfl
c difvfx(3),fa(196) volvel vexplt
c difvgx(3),fa(199) volvel vexplt
c gammsw(1),fa(222) accum eqfinl fidisj htadv katokj phantv pimplt
c                   preseq prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl fidisj htadv phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
ccccc
ccccc scrtch.H variables used in vfinl.F
ccccc
c dvelfj(1),fa(1)   vfinl
c dvelgj(1),fa(2)   vfinl
c scvj1(11),fa(14)  vfinl packer
c scvj2(1) ,fa(15)  vfinl
c scvj3(1) ,fa(16)  packer vfinl
c scvj4(1) ,fa(17)  vfinl
c scvj12(1),fa(25)  vfinl
c vfdpk(1) ,fa(27)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpk(1) ,fa(28)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vfdpl(1) ,fa(29)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c vgdpl(1) ,fa(30)  accum ccfl jchoke packer vexplt preseq prseqm vfinl
c velfjs(1),fa(102) vfinl
c velgjs(1),fa(103) vfinl
c vmdpk(1) ,fa(111) mmfld vexplt vfinl prseqm
c vmdpl(1) ,fa(112) mmfld vexplt vfinl prseqm
c dvelmj(1),fa(123) mmfld vfinl
c smvj1(1) ,fa(124) mmfld vfinl
c smvj2(1) ,fa(125) mmfld vfinl
c smvj3(1) ,fa(126) mmfld vfinl
c smvj4(1) ,fa(127) mmfld vfinl
c smvj5(1) ,fa(128) mmfld vfinl
c smvj6(6) ,fa(129) mmfld vfinl
c smvj7(1) ,fa(135) mmfld vfinl
ccccc
ccccc scrtch.H variables used in vimplt.F
ccccc
c a51s(1)  ,fa(1)   vimplt
c dpstf(1) ,fa(1)   phantj vexplt vimplt
c scvjck(1),fa(1)   vexplt jchoke vimplt
c a52s(1)  ,fa(2)   vimplt
c dxkx(1)  ,fa(2)   phantj ccfl jchoke vexplt vimplt
c a53s(1)  ,fa(3)   vimplt
c dxlx(1)  ,fa(3)   phantj ccfl jchoke vexplt vimplt
c a54s(1)  ,fa(4)   vimplt
c rfvfrc(1),fa(10)  vimplt
c rgvgrc(1),fa(11)  vimplt
c pslope(1),fa(12)  pump vexplt vimplt
c angmm(1), fa(13)  pump vexplt vimplt
c tloc(1),  fa(13)  vexplt vimplt
c fjet(1)  ,fa(14)  vexplt vimplt
c tloc2(1) ,fa(14)  vexplt vimplt
c pumpv(1) ,fa(15)  vimplt
c vagrg(1) ,fa(15)  vexplt vimplt
c scvtur(1),fa(16)  vexplt jchoke vimplt
c pmpph(1) ,fa(17)  vexplt jchoke vimplt
c a55s(1)  ,fa(25)  vimplt
c avkx(1)  ,fa(25)  phantj jchoke vexplt vimplt
c avlx(1)  ,fa(26)  phantj jchoke vexplt vimplt
c sorp(1)  ,fa(26)  vimplt
c sumdpk(1),fa(27)  vimplt jchoke simplt
c difdpk(1),fa(28)  vimplt jchoke ccfl simplt
c sumdpl(1),fa(29)  vimpltjchoke simplt
c difdpl(1),fa(30)  vimplt jchoke ccfl simplt
c sourca(1),fa(31)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm
c sourcg(1),fa(32)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcf(1),fa(33)  vexplt accum preseq eqfinl vimplt pimplt prseqm eqfi
c sourcm(1),fa(34)  vexplt preseq eqfinl vimplt pimplt prseqm eqfinm sta
c sourcn(1),fa(35)  vexplt eqfinl eqfinm vimplt pimplt
c dxk(1),   fa(40)  vexplt vimplt
c fricfj(1),fa(40)  vexplt vimplt
c dxl(1),   fa(41)  vexplt vimplt
c fricgj(1),fa(41)  vexplt vimplt
c ihld1(1), ia(42)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c ihld2(1), fa(43)  preseq eqfinl prseqm eqfinm pimplt simplt statep vex
c a11(1)   ,fa(45)  preseq eqfinl prseqm eqfinm vimplt pimplt
c ncrosk(1),fa(45)  vexplt vimplt
c a12(1)   ,fa(46)  preseq eqfinl prseqm eqfinm vimplt pimplt
c ncrosl(1),fa(46)  vexplt vimplt
c dxx(1)   ,fa(47)  vexplt vimplt
c a14(1)   ,fa(48)  preseq eqfinl prseqm eqfinm vimplt pimplt
c rhofa(1) ,fa(48)  vexplt vimplt
c a15(1)   ,fa(49)  preseq eqfinl vimplt pimplt
c rhoga(1) ,fa(49)  vexplt vimplt
c a21(1)   ,fa(50)  preseq eqfinl prseqm eqfinm vimplt pimplt
c vpgen(1) ,fa(50)  vexplt vimplt
c a22(1)   ,fa(51)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a23(1)   ,fa(52)  preseq eqfinl prseqm eqfinm vimplt pimplt
c ravrf(1) ,fa(52)  vexplt vimplt
c a24(1)   ,fa(53)  preseq eqfinl prseqm eqfinm vimplt pimplt
c ravrg(1) ,fa(53)  vexplt vimplt
c rfvfj(1) ,fa(53)  vexplt vimplt
c a25(1)   ,fa(54)  preseq eqfinl prseqm eqfinm vimplt pimplt
c rgvgj(1) ,fa(54)  vexplt vimplt
c a31(1)   ,fa(55)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a32(1)   ,fa(56)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a33(1)   ,fa(57)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fricfk(1),fa(57)  vexplt vimplt
c a34(1)   ,fa(58)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fricfl(1),fa(58)  vexplt vimplt
c a35(1)   ,fa(59)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fricgk(1),fa(59)  vexplt vimplt
c a41(1)   ,fa(60)  preseq eqfinl prseqm eqfinm vimplt pimplt
c fricgl(1),fa(60)  vexplt vimplt
c a42(1)   ,fa(61)  preseq eqfinl prseqm eqfinm vimplt pimplt
c convf(1) ,fa(61)  coev3d vexplt vimplt flux3d
c a43(1)   ,fa(62)  preseq eqfinl prseqm eqfinm vimplt pimplt
c convg(1) ,fa(62)  coev3d vexplt vimplt flux3d
c a44(1)   ,fa(63)  preseq eqfinl prseqm eqfinm vimplt pimplt
c convfs(1),fa(63)  vexplt vimplt
c a45(1)   ,fa(64)  preseq eqfinl prseqm eqfinm vimplt pimplt
c convgs(1),fa(64)  vexplt vimplt
c a51(1)   ,fa(65)  preseq prseqm eqfinm vimplt pimplt
c snk(2)   ,fa(65)  vexplt vimplt
c a52(1)   ,fa(66)  preseq prseqm eqfinm vimplt pimplt
c a53(1)   ,fa(67)  preseq prseqm eqfinm vimplt pimplt
c snl(2)   ,fa(67)  vexplt vimplt
c a54(1)   ,fa(68)  preseq prseqm eqfinm vimplt pimplt
c a55(1)   ,fa(69)  preseq eqfinl prseqm eqfinm vimplt pimplt
c vngen(1) ,fa(69)  vexplt vimplt
c a1(1)    ,fa(70)  preseq eqfinl prseqm eqfinm vimplt pimplt
c psmf(1)  ,fa(70)  vexplt vimplt
c a2(1)    ,fa(71)  preseq eqfinl prseqm eqfinm vimplt pimplt
c psmg(1)  ,fa(71)  vexplt vimplt
c a3(1)    ,fa(72)  preseq eqfinl prseqm eqfinm vimplt pimplt
c psld(1)  ,fa(72)  vexplt vimplt
c a4(1)    ,fa(73)  preseq eqfinl prseqm eqfinm vimplt pimplt
c a5(1)    ,fa(74)  preseq eqfinl prseqm eqfinm vimplt pimplt
c high(1)  ,fa(75)  preseq prseqm vimplt pimplt
c hifh(1)  ,fa(76)  preseq prseqm vimplt pimplt
c agxa(1)  ,fa(79)  preseq vimplt prseqm eqfinm
c figj(1)  ,fa(79)  vexplt vimplt
c dx(1)    ,fa(80)  vexplt vimplt
c ff(1)    ,fa(81)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c gg(1)    ,fa(82)  vexplt preseq eqfinl prseqm eqfinm pimplt vimplt
c sathfx(1),fa(83)  vexplt preseq prseqm vimplt
c sathgx(1),fa(84)  vexplt preseq prseqm vimplt
c hsgf(1)  ,fa(85)  vexplt preseq prseqm vimplt
c agug(1)  ,fa(86)  preseq eqfinl vimplt prseqm eqfinm
c voidga(1),fa(86)  vexplt vimplt
c afuf(1)  ,fa(87)  preseq eqfinl vimplt prseqm eqfinm
c fifj(1)  ,fa(87)  vexplt vimplt
c voidfa(1),fa(88)  vexplt vimplt
c fal(1)   ,fa(89)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c gal(1)   ,fa(90)  vexplt preseq eqfinl prseqm eqfinm vimplt pimplt
c fp(1)    ,fa(95)  preseq eqfinl prseqm eqfinm vimplt pimplt
c delv(1)  ,fa(96)  vexplt vimplt
c gp(1)    ,fa(96)  preseq eqfinl prseqm eqfinm vimplt pimplt
c gug(1)   ,fa(97)  preseq eqfinl prseqm eqfinm vimplt pimplt
c hlossf(1),fa(98)  vexplt vimplt
c fug(1)   ,fa(99)  preseq eqfinl prseqm eqfinm vimplt pimplt
c hlossg(1),fa(99)  vexplt vimplt
c fuf(1)   ,fa(100) preseq eqfinl prseqm eqfinm vimplt pimplt
c sourcq(1),fa(111) vimplt pimplt
c soura(1) ,fa(112) vimplt simplt
c sourn(5) ,fa(113) vimplt simplt
c isptr(1) ,ia(116) vimplt
c aviscf(1),fa(141) vimplt
c aviscg(1),fa(142) vimplt
c gxaa(1)  ,fa(144) vimplt pimplt
c fxaa(1)  ,fa(145) vimplt pimplt
c avisfs(1),fa(149) vimplt
c avisgs(1),fa(150) vimplt
c pmhig(1) ,fa(151) vexplt preseq vimplt
c pshig(1) ,fa(152) vexplt    preseq vimplt
c avrf(1)  ,fa(153) vexplt vimplt
c avrg(1)  ,fa(154) vexplt vimplt
c fidxup(1),fa(160) hydro phantv hloss jchoke phantj vexplt vimplt
c scvjn(5) ,fa(163) vimplt
c drivew(1),ia(172) vimplt
c jtdjsg(1),ia(173) vimplt
c jtdjsf(1),ia(174) vimplt
c jtdjdg(1),ia(175) vimplt
c jtdjdf(1),ia(176) vimplt
c jetjsg(1),ia(177) vimplt
c jetjsf(1),ia(178) vimplt
c jetjdg(1),ia(179) vimplt
c jetjdf(1),ia(180) vimplt
c jetsg(1) ,ia(181) vimplt
c jetsf(1) ,ia(182) vimplt
c jetdg(1) ,ia(183) vimplt
c jetdf(1) ,ia(184) vimplt
c jtcons(1),fa(185) vimplt
c jtcond(1),fa(186) vimplt
c scvj11(1),fa(187) vimplt
c scvj22(1),fa(188) vimplt
c scvj33(1),fa(189) vimplt
c scvj44(1),fa(190) vimplt
c scvj5(1) ,fa(191) vimplt
c scvj6(1) ,fa(192) vimplt
c scvj7(1) ,fa(193) vimplt
c scvj8(1) ,fa(194) vimplt
c htcfg(1) ,fa(202) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcft(1) ,fa(203) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgf(1) ,fa(204) tran htadv eqfinl vimplt pimplt preseq prseqm
c htcgt(1) ,fa(205) tran htadv eqfinl vimplt pimplt preseq prseqm
c htgwff(1),fa(210) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfg(1),fa(211) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwft(1),fa(212) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgf(1),fa(213) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgg(1),fa(214) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgp(1),fa(215) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgcgt(1),fa(216) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgp(1) ,fa(217) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcgg(1) ,fa(218) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcff(1) ,fa(219) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htcfp(1) ,fa(220) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c htgwfp(1),fa(221) tran htadv eqfinl phantv eqfinl pimplt preseq vimplt
c gammsw(1),fa(222) accum eqfinl fidisj htadv katokj phantv pimplt
c                   preseq prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl fidisj htadv phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
ccccc
ccccc scrtch.H variables used in vlvela.F
ccccc
c vvfx(6)  ,fa(1)   volvel vlvela
c vvgx(6)  ,fa(7)   volvel vlvela
c vrhof(6) ,fa(13)  volvel vlvela
c vrhog(6) ,fa(19)  volvel vlvela
c vmx(2)   ,fa(27)  mmfld volvel vlvela
c vrhom(2) ,fa(29)  mmfld volvel vlvela
c arhom(1) ,fa(31)  mmfld volvel vlvela
c areav(6) ,fa(71)  volvel vlvela
c arhof(1) ,fa(89)  volvel vlvela
c arhog(1) ,fa(95)  volvel vlvela
ccccc
ccccc scrtch.H variables used in volvel.F
ccccc
c vvfx(6)  ,fa(1)   volvel vlvela
c vvgx(6)  ,fa(7)   volvel vlvela
c vrhof(6) ,fa(13)  volvel vlvela
c vrhog(6) ,fa(19)  volvel vlvela
c vmx(2)   ,fa(27)  mmfld volvel vlvela
c vrhom(2) ,fa(29)  mmfld volvel vlvela
c arhom(1) ,fa(31)  mmfld volvel vlvela
c vma(2)   ,fa(32)  mmfld volvel
c ratiom(2),fa(34)  mmfld volvel
c ratiof(6),fa(53)  volvel
c ratiog(6),fa(59)  volvel
c gsum(6)  ,fa(65)  volvel
c areav(6) ,fa(71)  volvel vlvela
c vfa(6)   ,fa(77)  volvel
c vga(6)   ,fa(83)  volvel
c arhof(1) ,fa(89)  volvel vlvela
c arhog(1) ,fa(95)  volvel vlvela
c difvmx(1),fa(101) mmfld volvel vexplt
c sumvmx(1),fa(102) mmfld volvel
c sumvfx(3),fa(190) volvel fwdrag
c sumvgx(3),fa(193) volvel fwdrag
c difvfx(3),fa(196) volvel vexplt
c difvgx(3),fa(199) volvel vexplt
ccccc
ccccc scrtch.H variables used in zfslgj.F
ccccc
c gammsw(1),fa(222) accum eqfinl fidisj htadv katokj phantv pimplt
c                   preseq prseqm tran vexplt vimplt zfslgj
c gammsc(1),fa(223) accum eqfinl fidisj htadv phantv pimplt preseq
c                   prseqm tran vexplt vimplt zfslgj
c
c
c  List 4 <=======>
c
c  This list is sorted by slot number and for each slot number,
c   it is alphabetic.
c  The subroutine names where the variable is referenced are shown
c   on the right. mmfld and losuboil are '$if def's and are also
c   shown on the right.
c  The > indicates that the variable has to survive from a previous
c   subroutine, i.e., it is defined in an earlier subroutine and
c   used in the subroutine following the >.
c  A subroutine name by itself indicates that the variable is local
c   to that routine, i.e., it is defined and used in the subroutine
c   and does not have to survive after the subroutine finishes.
c  A repeat of the variable name with the subroutine names indented
c   is just a continuation of the previous line.
c
c
c a47s(1)  ,fa(  1) mmfld prseqm
c a51s(1)  ,fa(  1) vimplt
c b1(1)    ,fa(  1) eqfinl eqfinm pimplt
c dbodxv(1),fa(  1) brntrn
c dpstf(1) ,fa(  1) phantj>vexplt phantj>vimplt
c drho(1)  ,fa(  1) state
c dvelfj(1),fa(  1) vfinl
c scvjck(1),fa(  1) vexplt>jchoke vimplt>jchoke
c tt(1)    ,fa(  1) statep
c vvfx(6)  ,fa(  1) volvel vlvela
c a52s(1)  ,fa(  2) vimplt
c a57s(1)  ,fa(  2) mmfld prseqm
c b2(1)    ,fa(  2) eqfinl eqfinm pimplt
c dvelgj(1),fa(  2) vfinl
c dxkx(1)  ,fa(  2) phantj>ccfl>jchoke>vexplt>vimplt
c pres(1)  ,fa(  2) statep
c ratio(1) ,fa(  2) brntrn
c a53s(1)  ,fa(  3) vimplt
c a67s(1)  ,fa(  3) mmfld prseqm
c b3(1)    ,fa(  3) eqfinl eqfinm pimplt
c cflno(1) ,fa(  3) brntrn
c conmf(1) ,fa(  3) eqfinl eqfinm pimplt
c dxlx(1)  ,fa(  3) phantj>ccfl>jchoke>vexplt>vimplt
c errm(1)  ,fa(  3) state
c dtcrnf(1),fa(  3) courn1
c vbar(1)  ,fa(  3) statep
c a54s(1)  ,fa(  4) vimplt
c b4(1)    ,fa(  4) eqfinl eqfinm pimplt
c conmg(1) ,fa(  4) eqfinl eqfinm pimplt
c dbodxj(1),fa(  4) brntrn
c dtcrng(1),fa(  4) courn1
c fwfaf1(1),fa(  4) fwdrag
c gfwabs(1),fa(  4) fwdrag
c ihh1(1)  ,ia(  4) jprop stdry
c ubar(1)  ,fa(  4) statep
c voidaa(1),fa(  4) eqfinl
c bb5(1)   ,fa(  5) pimplt
c borona(1),fa(  5) brntrn
c cond(1)  ,fa(  5) eqfinl eqfinm pimplt
c delxa(1) ,fa(  5) eqfinl eqfinm simplt
c fwfag1(1),fa(  5) fwdrag
c hbar(1)  ,fa(  5) statep
c ihh3(1)  ,ia(  5) jprop
c beta(1)  ,fa(  6) statep
c boronb(1),fa(  6) brntrn
c conm(1)  ,fa(  6) eqfinl eqfinm pimplt
c dpdxfx(1),fa(  6) fwdrag
c fwf1(1)  ,fa(  6) fwdrag
c ihh2(1)  ,ia(  6) jprop stdry
c ugnc(1)  ,fa(  6) eqfinl eqfinm
c dbodx1(1),fa(  7) brntrn
c dpdxgx(1),fa(  7) fwdrag
c fwg1(1)  ,fa(  7) fwdrag
c ireg(1)  ,fa(  7) fidisj>phantj
c kapa(1)  ,fa(  7) statep
c nix(1)   ,ia(  7) jprop
c scv1(1)  ,fa(  7) eqfinl eqfinm pimplt
c ufnc(1)  ,fa(  7) eqfinl eqfinm
c vvgx(6)  ,fa(  7) volvel vlvela
c cp(1)    ,fa(  8) statep
c dbodx2(1),fa(  8) brntrn
c lgg1(1)  ,ia(  8) jprop
c ltest(1) ,ia(  8) eqfinl eqfinm
c scv2(1)  ,fa(  8) eqfinl eqfinm pimplt
c ltest2(1),ia(  9) eqfinl eqfinm
c qual(1)  ,fa(  9) statep
c scv3(1)  ,fa(  9) eqfinl eqfinm pimplt
c fwf2(1)  ,fa( 10) fwdrag
c ltest3(1),ia( 10) eqfinl eqfinm
c psat(1)  ,fa( 10) statep
c rfvfrc(1),fa( 10) vimplt
c scv4(1)  ,fa( 10) eqfinl eqfinm, pimplt
c sinbt(1) ,fa( 10) phantj>fidisj
c rgvgrc(1),fa( 11) vimplt
c scv5(1)  ,fa( 11) eqfinl eqfinm pimplt
c voidgu(1),fa( 11) phantv>phantj
c vrxgn(5) ,fa( 11) simplt
c vsubf(1) ,fa( 11) statep
c xncn(1)  ,fa( 11) eqfinl
c pslope(1),fa( 12) pump>vexplt>vimplt
c scv6(1)  ,fa( 12) eqfinl eqfinm pimplt
c voidgd(1),fa( 12) phantv>phantj
c vsubg(1) ,fa( 12) statep
c angmm(1) ,fa( 13) pump>vexplt>vimplt
c fwg2(1)  ,fa( 13) fwdrag
c scv7(1)  ,fa( 13) pimplt
c tloc(1)  ,fa( 13) vexplt vimplt
c usubf(1) ,fa( 13) statep
c vrhof(6) ,fa( 13) volvel vlvela
c fjet(1)  ,fa( 14) vexplt vimplt
c reynf2(1),fa( 14) fwdrag
c scv8(1)  ,fa( 14) pimplt
c scvj1(11),fa( 14) vfinl packer
c tloc2(1) ,fa( 14) vexplt vimplt
c tpdpdx(1),fa( 14) fwdrag
c usubg(1) ,fa( 14) statep
c ctermx(1),fa( 15) fwdrag
c pumpv(1) ,fa( 15) vimplt
c reyng2(1),fa( 15) fwdrag
c scv9(1)  ,fa( 15) pimplt
c scvj2(1) ,fa( 15) vfinl
c vagrg(1) ,fa( 15) vexplt vimplt
c scv10(1) ,fa( 16) pimplt
c scvj3(1) ,fa( 16) packer>vfinl
c scvtur(1),fa( 16) vexplt>jchoke vimplt
c betaf(1) ,fa( 17) statep
c pmpph(1) ,fa( 17) vexplt jchoke vimplt
c scv2n(5) ,fa( 17) eqfinl eqfinm pimplt
c scvj4(1) ,fa( 17) vfinl
c betag(1) ,fa( 18) statep
c pk(1)    ,fa( 18) vexplt
c kapaf(1) ,fa( 19) statep
c voidgk(1),fa( 19) vexplt
c vrhog(6) ,fa( 19) volvel vlvela
c kapag(1) ,fa( 20) statep
c pl(1)    ,fa( 20) vexplt
c cpf(1)   ,fa( 21) statep
c voidgl(1),fa( 21) vexplt
c avrfg(1) ,fa( 22) vexplt
c cpg(1)   ,fa( 22) statep
c sourff(1),fa( 22) pimplt>simplt
c is23(1)  ,ia( 23) stvrpx svh2x2
c sourgg(1),fa( 23) pimplt>simplt
c entpy(1) ,fa( 24) statep
c tuf(1)   ,fa( 24) pimplt>simplt
c a55s(1)  ,fa( 25) vimplt
c avkx(1)  ,fa( 25) phantj>jchoke>vexplt>vimplt
c b5(1)    ,fa( 25) eqfinl eqfinm
c entpyf(1),fa( 25) statep
c scvj12(1),fa( 25) vfinl
c tug(1)   ,fa( 25) pimplt>simplt
c avlx(1)  ,fa( 26) phantj>jchoke>vexplt>vimplt
c entpyg(1),fa( 26) statep
c sorp(1)  ,fa( 26) eqfinl eqfinm vimplt
c sumdpk(1),fa( 27) jchoke>vimplt>simplt
c vfdpk(1) ,fa( 27) accum>ccfl>jchoke>packer>vexplt>preseq>prseqm>vfinl
c vmx(2)   ,fa( 27) mmfld volvel vlvela
c difdpk(1),fa( 28) jchoke>ccfl>vimplt>simplt
c hggff(1) ,fa( 28) phantv
c vgdpk(1) ,fa( 28) accum>ccfl>jchoke>packer>vexplt>preseq>prseqm>vfinl
c sumdpl(1),fa( 29) jchoke>vimplt>simplt
c vfdpl(1) ,fa( 29) accum>ccfl>jchoke>packer>vexplt>preseq>prseqm>vfinl
c vrhom(2) ,fa( 29) mmfld volvel vlvela
c difdpl(1),fa( 30) jchoke>ccfl>vimplt>simplt
c vgdpl(1) ,fa( 30) accum>ccfl>jchoke>packer>vexplt>preseq>prseqm>vfinl
c arhom(1) ,fa( 31) mmfld volvel vlvela
c jhld1(1) ,ia( 31) phantv fwdrag
c sourca(1),fa( 31) vexplt>preseq>eqfinl>prseqm>eqfinm vimplt>pimplt
c jhld2(1) ,ia( 32) phantv fwdrag
c sourcg(1),fa( 32) vexplt>accum>preseq>eqfinl vimplt>pimplt
c sourcg(1),fa( 32)   prseqm>eqfinm
c tter(1)  ,ia( 32) statep
c vma(2)   ,fa( 32) mmfld volvel
c ja(1)    ,ia( 33) stvrpx svh2x2
c jhld3(1) ,ia( 33) phantv fwdrag
c sourcf(1),fa( 33) vexplt>accum>preseq>eqfinl vimplt>pimplt
c sourcf(1),fa( 33)   prseqm>eqfinm
c jb(1)    ,ia( 34) stvrpx svh2x2
c jhld4(1) ,ia( 34) phantv
c ratiom(2),fa( 34) mmfld volvel
c sourcm(1),fa( 34) vexplt>preseq>eqfinl>vimplt>pimplt
c sourcm(1),fa( 34)   >prseqm>eqfinm>statep
c jhld5(1) ,ia( 35) phantv
c sourcn(1),fa( 35) vexplt>eqfinl>eqfinm vimplt>pimplt
c jhld6(1) ,ia( 36) phantv
c qter(1)  ,ia( 36) statep
c jhld7(1) ,ia( 37) phantv
c hgfc(1)  ,fa( 38) phantv
c hgfc1(1) ,fa( 38) phantv
c dxk(1)   ,fa( 40) vexplt vimplt
c fricfj(1),fa( 40) vexplt vimplt
c lflag2(1),ia( 40) statep
c dtsf(1)  ,fa( 41) phantv hifbub
c dxl(1)   ,fa( 41) vexplt vimplt
c fricgj(1),fa( 41) vexplt vimplt
c lflag(1) ,ia( 41) statep
c dtsg(1)  ,fa( 42) phantv
c ihld1(1) ,ia( 42) preseq>eqfinl prseqm>eqfinm
c ihld1(1) ,ia( 42)   pimplt simplt statep vexplt vimplt
c hfg(1)   ,fa( 43) phantv hifbub
c ihld2(1) ,ia( 43) preseq>eqfinl prseqm>eqfinm pimplt>simplt
c ihld2(1) ,ia( 43)   statep vexplt vimplt
c badfw(1) ,ia( 44) fwdrag
c ihld3(1) ,ia( 44) vexplt statep preseq>eqfinl prseqm>eqfinm
c pack(1)  ,ia( 44) packer
c rhfg(1)  ,fa( 44) phantv hifbub
c a11(1)   ,fa( 45) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c aterm(1) ,fa( 45) fwdrag
c avelf(1) ,fa( 45) phantv hifbub
c ncrosk(1),fa( 45) vexplt vimplt
c tnmins(1),fa( 45) simplt
c a12(1)   ,fa( 46) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c bterm(1) ,fa( 46) fwdrag
c ihld5(1) ,ia( 46) statep
c ncrosl(1),fa( 46) vexplt vimplt
c rhocpf(1),fa( 46) phantv hifbub
c tnplus(1),fa( 46) simplt
c axvelf(1),fa( 47) fwdrag
c dxx(1)   ,fa( 47) vexplt vimplt
c fracal(1),fa( 47) preseq>eqfinl prseqm>eqfinm
c ihld6(1) ,ia( 47) statep
c vpgnx(1) ,fa( 47) vexplt
c xliqh(1) ,fa( 47) phantv
c a14(1)   ,fa( 48) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c bxvelg(1),fa( 48) fwdrag
c ihld9(1) ,ia( 48) svh2x2 statep thcond
c rhofa(1) ,fa( 48) vexplt vimplt
c xvaph(1) ,fa( 48) phantv
c a15(1)   ,fa( 49) preseq>eqfinl vimplt>pimplt
c ihld10(1),ia( 49) statep thcond
c ihld8(1) ,ia( 49) svh2x2
c rhoga(1) ,fa( 49) vexplt vimplt
c trmm(1)  ,fa( 49) phantv
c a21(1)   ,fa( 50) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c trmm1(1) ,fa( 50) phantv
c vpgen(1) ,fa( 50) vexplt vimplt
c a22(1)   ,fa( 51) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c higc(1)  ,fa( 51) phantv
c tsat(1)  ,fa( 51) statep
c vrxg(1)  ,fa( 51) simplt
c a23(1)   ,fa( 52) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c higc1(1) ,fa( 52) phantv
c ps(1)    ,fa( 52) statep
c ravrf(1) ,fa( 52) vexplt vimplt
c a24(1)   ,fa( 53) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c hifc(1)  ,fa( 53) phantv hifbub
c ratiof(6),fa( 53) volvel
c ravrg(1) ,fa( 53) vexplt vimplt
c rfvfj(1) ,fa( 53) vexplt vimplt
c vs(1)    ,fa( 53) statep
c a25(1)   ,fa( 54) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c hifc1(1) ,fa( 54) phantv hifbub
c rgvgj(1) ,fa( 54) vexplt vimplt
c us(1)    ,fa( 54) statep
c a31(1)   ,fa( 55) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c frlmf1(1),fa( 55) fwdrag
c higsub(1),fa( 55) phantv
c a32(1)   ,fa( 56) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c dtsfm(1) ,fa( 56) phantv
c frlmg1(1),fa( 56) fwdrag
c ltestt(1),ia( 56) vexplt
c a33(1)   ,fa( 57) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c cps(1)   ,fa( 57) statep
c dtsgms(1),fa( 57) phantv
c fricfk(1),fa( 57) vexplt vimplt
c frtrf1(1),fa( 57) fwdrag
c a34(1)   ,fa( 58) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c dtsgm(1) ,fa( 58) phantv
c fricfl(1),fa( 58) vexplt vimplt
c frtrg1(1),fa( 58) fwdrag
c a35(1)   ,fa( 59) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c dtsfsp(1),fa( 59) phantv
c fricgk(1),fa( 59) vexplt vimplt
c frtbf1(1),fa( 59) fwdrag
c ratiog(6),fa( 59) volvel
c a41(1)   ,fa( 60) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c dtsfsb(1),fa( 60) phantv
c fricgl(1),fa( 60) vexplt vimplt
c frtbg1(1),fa( 60) fwdrag
c a42(1)   ,fa( 61) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c avelfg(1),fa( 61) phantv
c convf(1) ,fa( 61) coev3d>vimplt flux3d>vexplt
c frlmf2(1),fa( 61) fwdrag
c vsubfs(1),fa( 61) statep
c a43(1)   ,fa( 62) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c convg(1) ,fa( 62) coev3d>vimplt flux3d>vexplt
c f2(1)    ,fa( 62) phantv
c fluxm(1) ,fa( 62) phantv
c frlmg2(1),fa( 62) fwdrag
c vsubgs(1),fa( 62) statep
c a44(1)   ,fa( 63) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c convfs(1),fa( 63) vexplt vimplt
c frtrf2(1),fa( 63) fwdrag
c scrchh(1),fa( 63) phantv
c usubfs(1),fa( 63) statep
c a45(1)   ,fa( 64) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c celvec(1),fa( 64) phantv
c convgs(1),fa( 64) vexplt vimplt
c fpress(1),fa( 64) losubboil phantv
c frtrg2(1),fa( 64) fwdrag
c usubgs(1),fa( 64) statep
c a51(1)   ,fa( 65) preseq prseqm>eqfinm vimplt>pimplt
c dmvvec(1),fa( 65) phantv
c flxtrn(1),fa( 65) losubboil phantv
c frtbf2(1),fa( 65) fwdrag
c gsum(6)  ,fa( 65) volvel
c hsubfs(1),fa( 65) statep
c snk(2)   ,fa( 65) vexplt vimplt
c a52(1)   ,fa( 66) preseq prseqm>eqfinm vimplt>pimplt
c frtbg2(1),fa( 66) fwdrag
c hsubgs(1),fa( 66) statep
c sbmlhf(1),fa( 66) losubboil phantv
c velvcf(1),fa( 66) phantv
c a53(1)   ,fa( 67) preseq prseqm>eqfinm vimplt>pimplt
c betafs(1),fa( 67) statep
c ratdpf(1),fa( 67) fwdrag
c sbmllf(1),fa( 67) losubboil phantv
c snl(2)   ,fa( 67) vexplt vimplt
c velvcg(1),fa( 67) phantv
c a54(1)   ,fa( 68) preseq prseqm>eqfinm vimplt>pimplt
c betags(1),fa( 68) statep
c dstvec(1),fa( 68) phantv
c a55(1)   ,fa( 69) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c kapafs(1),fa( 69) statep
c vngen(1) ,fa( 69) vexplt vimplt
c a1(1)    ,fa( 70) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c kapags(1),fa( 70) statep
c psmf(1)  ,fa( 70) vexplt vimplt
c timinv(1),fa( 70) phantv
c a2(1)    ,fa( 71) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c areav(6) ,fa( 71) volvel vlvela
c cpfs(1)  ,fa( 71) statep
c psmg(1)  ,fa( 71) vexplt vimplt
c tcouri(1),fa( 71) phantv
c a3(1)    ,fa( 72) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c cpgs(1)  ,fa( 72) statep
c nmapp(1) ,ia( 72) phantv
c psld(1)  ,fa( 72) vexplt vimplt
c a4(1)    ,fa( 73) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c ivert(1) ,ia( 73) phantv
c sumf(1)  ,fa( 73) vexplt
c a5(1)    ,fa( 74) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c nvalhi(1),ia( 74) phantv
c sumg(1)  ,fa( 74) vexplt
c entfs(1) ,fa( 75) statep
c gxa(1)   ,fa( 75) preseq>eqfinl prseqm>eqfinm
c high(1)  ,fa( 75) preseq>prseqm vimplt>pimplt
c nvalhx(1),ia( 75) phantv
c sumold(1),fa( 75) vexplt
c diff(1)  ,fa( 76) vexplt
c entgs(1) ,fa( 76) statep
c fxa(1)   ,fa( 76) preseq>eqfinl prseqm>eqfinm
c hifh(1)  ,fa( 76) preseq prseqm vimplt>pimplt
c difg(1)  ,fa( 77) vexplt
c paa(1)   ,fa( 77) stvrpx svh2x2
c vfa(6)   ,fa( 77) volvel
c difold(1),fa( 78) vexplt
c fanms(1) ,fa( 78) phantv>fwdrag
c pbb(1)   ,fa( 78) stvrpx svh2x2
c agxa(1)  ,fa( 79) preseq vimplt prseqm>eqfinm
c figj(1)  ,fa( 79) vexplt vimplt
c taa(1)   ,fa( 79) stvrpx svh2x2
c agrg(1)  ,fa( 80) eqfinl eqfinm
c dx(1)    ,fa( 80) vexplt vimplt
c tbb(1)   ,fa( 80) stvrpx svh2x2
c ff(1)    ,fa( 81) vexplt>preseq>eqfinl>prseqm>eqfinm pimplt vimplt
c gg(1)    ,fa( 82) vexplt>preseq>eqfinl>prseqm>eqfinm pimplt vimplt
c tsater(1),ia( 82) statep
c sathfx(1),fa( 83) vexplt>preseq>prseqm vimplt
c vga(6)   ,fa( 83) volvel
c sathgx(1),fa( 84) vexplt>preseq>prseqm vimplt
c hsgf(1)  ,fa( 85) vexplt>preseq>prseqm vimplt
c agug(1)  ,fa( 86) preseq eqfinl vimplt prseqm>eqfinm
c qsater(1),ia( 86) statep
c voidga(1),fa( 86) vexplt vimplt
c afuf(1)  ,fa( 87) preseq eqfinl vimplt prseqm eqfinm
c fifj(1)  ,fa( 87) vexplt vimplt
c afrf(1)  ,fa( 88) eqfinl eqfinm
c voidfa(1),fa( 88) vexplt vimplt
c arhof(1) ,fa( 89) volvel vlvela
c fal(1)   ,fa( 89) vexplt preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c gal(1)   ,fa( 90) vexplt preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c fgrw(1)  ,fa( 91) preseq>eqfinl prseqm>eqfinm
c psumf(1) ,fa( 91) vexplt
c reynf1(1),fa( 91) fwdrag
c highdt(1),fa( 92) eqfinl eqfinm
c psumg(1) ,fa( 92) vexplt
c reyng1(1),fa( 92) fwdrag
c hifhdt(1),fa( 93) eqfinl eqfinm
c vmgnx(1) ,fa( 93) vexplt
c qualem(1),fa( 94) preseq prseqm
c scrxch(1),fa( 94) vexplt
c sourci(1),fa( 94) eqfinl eqfinm
c arhog(1) ,fa( 95) volvel vlvela
c difr(1)  ,fa( 95) vexplt
c fp(1)    ,fa( 95) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c delv(1)  ,fa( 96) vexplt vimplt
c gp(1)    ,fa( 96) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c cvmrv(1) ,fa( 97) vexplt
c gug(1)   ,fa( 97) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c fracag(1),fa( 98) preseq>eqfinl prseqm>eqfinm
c hlossf(1),fa( 98) vexplt vimplt
c fug(1)   ,fa( 99) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c hlossg(1),fa( 99) vexplt vimplt
c fuf(1)   ,fa(100) preseq>eqfinl prseqm>eqfinm vimplt>pimplt
c difvmx(1),fa(101) mmfld volvel>vexplt
c guf(1)   ,fa(101) preseq>eqfinl
c ihld7(1) ,ia(101) mmfld statep
c ihld7a(1),ia(101) svh2x2
c rhofs(1) ,fa(102) statep
c sumvmx(1),fa(102) mmfld volvel
c velfjs(1),fa(102) vfinl
c rhogs(1) ,fa(103) statep
c sorcmm(1),fa(103) mmfld vexplt>eqfinm>prseqm
c velgjs(1),fa(103) vfinl
c sorcme(1),fa(104) mmfld vexplt>eqfinm>prseqm
c tf(1)    ,fa(104) statep
c sorcmn(1),fa(105) mmfld vexplt>eqfinm
c ttg(1)   ,fa(105) statep
c kapaff(1),fa(106) statep state
c kapagg(1),fa(107) statep state
c ihld2a(1),ia(108) statep
c ihld4a(1),ia(109) statep
c sourcq(1),fa(111) vimplt>pimplt
c vmdpk(1) ,fa(111) mmfld vexplt>vfinl>prseqm
c soura(1) ,fa(112) vimplt>simplt
c vmdpl(1) ,fa(112) mmfld vexplt>vfinl>prseqm
c ihld4(1) ,ia(113) mmfld statep eqfinm prseqm
c sourn(5) ,fa(113) vimplt>simplt
c vamrm(1) ,fa(113) mmfld vexplt
c a77(1)   ,fa(114) mmfld prseqm>eqfinm
c voidma(1),fa(114) mmfld phantj vexplt
c a76(1)   ,fa(115) mmfld prseqm>eqfinm
c rhoma(1) ,fa(115) mmfld phantj vexplt
c a67(1)   ,fa(116) mmfld prseqm>eqfinm
c avrm(1)  ,fa(116) mmfld vexplt
c isptr(1) ,ia(116) vimplt
c a66(1)   ,fa(117) mmfld prseqm>eqfinm
c ravrm(1) ,fa(117) mmfld vexplt
c a37(1)   ,fa(118) mmfld prseqm>eqfinm
c rmvmj(1) ,fa(118) mmfld vexplt
c a27(1)   ,fa(119) mmfld prseqm>eqfinm
c fricmk(1),fa(119) mmfld vexplt
c a17(1)   ,fa(120) mmfld prseqm>eqfinm
c fricml(1),fa(120) mmfld vexplt
c amrm(1)  ,fa(121) mmfld prseqm>eqfinm
c convm(1) ,fa(121) mmfld vexplt
c amum(1)  ,fa(122) mmfld prseqm>eqfinm
c smk(1)   ,fa(122) mmfld vexplt
c conmm(1) ,fa(123) mmfld eqfinm
c dvelmj(1),fa(123) mmfld vfinl
c sml(1)   ,fa(123) mmfld vexplt
c smv1(1)  ,fa(124) mmfld eqfinm
c smvj1(1) ,fa(124) mmfld vfinl
c vmgen(1) ,fa(124) mmfld vexplt
c psmm(1)  ,fa(125) mmfld vexplt
c smv2(1)  ,fa(125) mmfld eqfinm
c smvj2(1) ,fa(125) mmfld vfinl
c pmld(1)  ,fa(126) mmfld vexplt
c smv3(1)  ,fa(126) mmfld eqfinm
c smvj3(1) ,fa(126) mmfld vfinl
c smvj4(1) ,fa(127) mmfld vfinl
c summ(1)  ,fa(127) mmfld vexplt
c difm(1)  ,fa(128) mmfld vexplt
c smvj5(1) ,fa(128) mmfld vfinl
c metf(1)  ,fa(129) mmfld vexplt
c smvj6(6) ,fa(129) mmfld vfinl
c metg(1)  ,fa(130) mmfld vexplt
c metm(1)  ,fa(131) mmfld vexplt
c b6(1)    ,fa(132) mmfld eqfinm
c metold(1),fa(132) mmfld vexplt
c b7(1)    ,fa(133) mmfld eqfinm
c amrmn(1) ,fa(134) mmfld eqfinm
c dpstm(1) ,fa(134) mmfld phantj>vexplt
c smvj7(1) ,fa(135) mmfld vfinl
c umnc(1)  ,fa(135) mmfld eqfinm
c avrgms(1),fa(136) mmfld vexplt
c vodmnc(1),fa(136) mmfld eqfinm
c avrfms(1),fa(137) mmfld vexplt
c avrgmp(1),fa(138) mmfld vexplt
c a27s(1)  ,fa(139) mmfld prseqm
c avrfmp(1),fa(139) mmfld vexplt
c a65(1)   ,fa(140) mmfld prseqm>eqfinm
c convms(1),fa(140) mmfld vexplt
c a36(1)   ,fa(141) mmfld prseqm>eqfinm
c aviscf(1),fa(141) vimplt
c vrug(1)  ,fa(141) simplt
c aviscg(1),fa(142) vimplt
c vruf(1)  ,fa(142) simplt
c gxaa(1)  ,fa(144) vimplt>pimplt
c fxaa(1)  ,fa(145) vimplt>pimplt
c a71(1)   ,fa(146) mmfld prseqm>eqfinm
c a61(1)   ,fa(147) mmfld prseqm>eqfinm
c tquala(1),fa(147) pimplt>simplt
c a64(1)   ,fa(148) mmfld prseqm>eqfinm
c a63(1)   ,fa(149) mmfld prseqm>eqfinm
c avisfs(1),fa(149) vimplt
c lrhog(1) ,fa(149) simplt
c a46(1)   ,fa(150) mmfld prseqm>eqfinm
c avisgs(1),fa(150) vimplt
c lrhof(1) ,fa(150) simplt
c a75(1)   ,fa(151) mmfld prseqm>eqfinm
c pmhig(1) ,fa(151) vexplt>preseq vimplt
c a74(1)   ,fa(152) mmfld prseqm>eqfinm
c pshig(1) ,fa(152) vexplt>preseq vimplt
c a73(1)   ,fa(153) mmfld prseqm>eqfinm
c avrf(1)  ,fa(153) vexplt vimplt
c a72(1)   ,fa(154) mmfld prseqm>eqfinm
c avrg(1)  ,fa(154) vexplt vimplt
c stret(1) ,ia(155) packer
c a57(1)   ,fa(156) mmfld prseqm>eqfinm
c a56(1)   ,fa(157) mmfld prseqm>eqfinm
c a47(1)   ,fa(158) mmfld prseqm>eqfinm
c a62(1)   ,fa(159) mmfld prseqm>eqfinm
c fidxup(1),fa(160) hydro>phantv>hloss>jchoke>phantj>vexplt>vimplt
c fwfxaf(3),fa(163) phantv>eccmxv>vexplt>fwdrag>ccfl
c scvjn(5) ,fa(163) vimplt
c fwfxag(3),fa(166) phantv>eccmxv>vexplt>fwdrag>ccfl
c pfinrg(1),fa(169) phantv>eccmxv>vexplt>fwdrag>ccfl
c drivew(1),ia(172) vimplt
c flomap(1),ia(172) eccmxv>phantv
c flompj(1),ia(172) eccmxj>phantj
c jtdjsg(1),ia(173) vimplt
c jtdjsf(1),ia(174) vimplt
c jtdjdg(1),ia(175) vimplt
c rvcrit(1),fa(175) phantv
c jtdjdf(1),ia(176) vimplt
c jetjsg(1),ia(177) vimplt
c dstar(1) ,fa(178) phantv>phantj
c jetjsf(1),ia(178) vimplt
c jetjdg(1),ia(179) vimplt
c jetjdf(1),ia(180) vimplt
c costhe(1),fa(181) phantv>phantj
c jetsg(1) ,ia(181) vimplt
c jetsf(1) ,ia(182) vimplt
c jetdg(1) ,ia(183) vimplt
c hiff(1)  ,fa(184) phantv
c jetdf(1) ,ia(184) vimplt
c jtcons(1),fa(185) vimplt
c jtcond(1),fa(186) vimplt
c higg(1)  ,fa(187) phantv
c scvj11(1),fa(187) vimplt
c scvj22(1),fa(188) vimplt
c scvj33(1),fa(189) vimplt
c scvj44(1),fa(190) vimplt
c sumvfx(3),fa(190) volvel>fwdrag
c scvj5(1) ,fa(191) vimplt
c scvj6(1) ,fa(192) vimplt
c scvj7(1) ,fa(193) vimplt
c sumvgx(3),fa(193) volvel>fwdrag
c scvj8(1) ,fa(194) vimplt
c difvfx(3),fa(196) volvel>vexplt
c difvgx(3),fa(199) volvel>vexplt
c htcfg(1) ,fa(202) tran>htadv>eqfinl>vimplt>pimplt>preseq>prseqm
c htcft(1) ,fa(203) tran>htadv>eqfinl>vimplt>pimplt>preseq>prseqm
c htcgf(1) ,fa(204) tran>htadv>eqfinl>vimplt>pimplt>preseq>prseqm
c htcgt(1) ,fa(205) tran>htadv>eqfinl>vimplt>pimplt>preseq>prseqm
c hydltf(1),fa(206) eqfinl>pimplt>htfinl
c hydltg(1),fa(207) eqfinl>pimplt>htfinl
c hydltt(1),fa(208) eqfinl>pimplt>htfinl
c hydltp(1),fa(209) eqfinl>pimplt>htfinl
c htgwff(1),fa(210) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htgwfg(1),fa(211) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htgwft(1),fa(212) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htgcgf(1),fa(213) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htgcgg(1),fa(214) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htgcgp(1),fa(215) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htgcgt(1),fa(216) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htcgp(1) ,fa(217) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htcgg(1) ,fa(218) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htcff(1) ,fa(219) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htcfp(1) ,fa(220) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c htgwfp(1),fa(221) tran>htadv>eqfinl>phantv>eqfinl>pimplt>preseq>vimplt
c gammsw(1),fa(222) tran>htadv>eqfinl;simplt
c gammsc(1),fa(223) tran>htadv>eqfinl;simplt
