*mlist
*comdeck scdpow
c  SCDAP power common block
c
      common / scdpow / pwrtot, pwrfdk, pfrtot(ndcomp),
     #  powfdk(ndcomp), powtot(ndcomp),
     #  rcpvfi(ndcomp), stemav(ndax,ndcomp),
     #  poatot(ndcomp), iscoup(ndcomp),
     3  nspowi, nstcno, nstcof,
     4  mcme76
      real pwrtot,pwrfdk,pfrtot,powfdk,powtot,rcpvfi,stemav
      real poatot
      integer iscoup
      integer  nspowi, nstcno, nstcof, mcme76
c
c     pwrtot = total core power (w)
c     pwrfdk = total decay power (fission product + actinide) (w)
c     pfrtot = multiplier for power
c     powfdk = fission products decay power (w)
c     powtot = total power (w)
c     rcpvfi = 1.0 / total initial fuel volume
c     stemav = average fuel temperature
c     poatot = actual power (w); less than source power if slumping
c     iscoup = indicator for material slumped below component; 1 = yes
c     nspowi = power source indicator -
c               1 = Relap5 general table
c               2 = Relap5 control variable
c               3 = Relap5 reactor kinetics
c     nstcno = Relap5 gen. table number or control variable number
c                           (0 if neither is used)
c     nstcof = offset to Relap5 gen. table or control variable data
