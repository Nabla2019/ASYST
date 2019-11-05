*mlist
!  statec is the common block for state properties.
!
!  Cognizant engineer: rjw.
!
!  Common block for state properties.
       common /statec/ advn(5),wmolea(5),rax(5),dcvax(5),cvaox(5),
     & uaox(5),tref(5),visao(5),thca(5),thcb(5),nctype(5),qn(5),
     & dconst(5),tao,noncn,nonmf
$if def,mmfld,1
       common /statec/ qnm(6),mma0(6),mma1(6),mma2(6),mmu0(6),mctype(6)
       common /statec/ nonhe,nonhy,nonni,nonkr,nonxe,nonair,nonar,
     & nonsf6,nonoxy,nonco2,noncom,safe4
       real advn,wmolea,rax,dcvax,cvaox,uaox,tref,visao,thca,thcb,
     & qn,dconst,tao,safe4
       integer(8) nctype
       integer noncn,nonmf,nonhe,nonhy,nonni,nonkr,nonxe,nonair,nonar,
     & nonsf6,nonoxy,nonco2,noncom
$if def,mmfld,1
       real qnm,mma0,mma1,mma2,mmu0
       integer(8) mctype
!
!  wmolea  molecular mass of non-condensible gas.
!
!  rax     gas constant of non-condensible gas.
!  dcvax   same as above.
!  cvaox   same as above.
!  uaox    term in u = uao + integral (cv*dt) where u is internal
!          energy.
!  tao     term in cv = cvao + dcva*(t - tao) where cv is heat capacity
!          and t is temperature.
!  dconst  Diffusion coefficient at reference conditions for non-
!          condensible gasses and steam.
!  noncn   number of non-condensible gasses.
!  nonmf   Number of molten metal species when mmfld option is defined;
!          also extra integer to maintain 8 byte boundary for 32 bit
!          machines when mmfld is not defined.
!  prop    array for sth2x calls, also used for scratch.
!  s       same as above.
