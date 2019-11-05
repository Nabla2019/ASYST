*mlist
c
c  Description
c
c  Holds variables common to reflood ht subroutines.
c  onrefl =1 if reflood logic is currently active.
c         =0 if reflood logic is currently inactive.
c  itrchf Iteration counter for finding twchf.
c  refbun = 1 if heat structure is a bundle and reflood may exist.
c         = 0 otherwise.
c  zqf    = height of the node above the bottom quench front.
c  zqftop = distance of the node from the top quench front.
c  zbun   = bundle length.
c  wetbot = height of bottom quench region.
c  wettop = length of top quench region.
       common /flood/ hmac,hmic,twchf,twqf,twnvg,wetbot,wettop,
     & zbun,zqf,zqftop,itrchf,onrefl,refbun
       real hmac,hmic,twchf,twqf,twnvg,wetbot,wettop,zbun,zqf,zqftop
       integer itrchf,onrefl,refbun
