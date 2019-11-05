*mlist
*comdeck fpinsh
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c
       integer nelm
       parameter (nelm=3)
       real avogdr,bltzmn,celkel,rfact,tundef,ugc
       parameter (bltzmn=1.380622e-23)
       parameter (avogdr=6.022169e+26)
       parameter (ugc=bltzmn*avogdr)
c  parameter (ugc=8.3143e+03)
       parameter (celkel=273.15)
       parameter (rfact=1.0e+03)
       parameter (tundef=-celkel)
       integer izirc,isteel
       parameter (izirc=0, isteel=1)
       common /fpinsh/ aconfp,asteel,atwt,azirc,bcon,beq,ceq,cliqfp,
     & csolfp,dmol,mfr,rhofp,sol,tmelt,indx,list,nsp2,mcme81
       integer indx(maxsp),list(maxsp),nsp2,mcme81
       real aconfp(maxsp),asteel(maxsp),atwt(maxsp),azirc(maxsp),
     & bcon(maxsp),beq(maxsp),ceq(maxsp),cliqfp(maxsp,4),
     & csolfp(maxsp,3),
     & dmol(maxsp),mfr(maxsp,nelm),rhofp(maxsp),sol(maxsp),tmelt(maxsp)
*endif
