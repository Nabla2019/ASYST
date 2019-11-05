*mlist
c  Cognizant engineer:ras.
c  Holds variables common to heat transfer correlation subroutines.
c
       common /htrcom/ axpf,beta,chf,chfmul,cps,dtsat,drod,delgrv,
     & fstrat,g,gabs,gamw,ggasa,gliqa,gridk,gridz,gcross,gcrosf,htlenc,
     & hcond,hd,hfg,htcf,htcg,htcnon,htcoef,htdiam,htgamf,htgamg,htzht,
     & htzhff,htzhft,htzhgg,htzhgt,htzhgp,htlen,htqof,htqog,htqot,htsa,
     & pitdia,qffo,qfgo,qfgox(2),qfluxo,tf,thcons,tw,
     & viscs,rey,pr,pvblk,rhos,alpf10,alpg10,hfgp,sathfp,qualep,enliq,
     & htopta,ibundl,incnd,irwt,iv,iv1,iv2,mode,ivindx,pgopta,pgflag,
     & idxtop
       real axpf,beta,chf,chfmul,cps,dtsat,delgrv,fstrat,g,gabs,gamw,
     & ggasa,gliqa,gridk,gridz,hcond,hd,hfg,htcf,htcg,htcnon,htcoef,
     & htdiam,htgamf,htgamg,htzht,htzhff,htzhft,htzhgg,htzhgt,htzhgp,
     & htlen,htqot,htqof,htqog,htsa,pvblk,qffo,qfgo,qfgox,qfluxo,
     & tf,thcons,tw,viscs,rey,pr,rhos,alpf10,alpg10,hfgp,sathfp,qualep,
     & enliq,gcross,gcrosf,htlenc,drod,pitdia
       integer htopta,ibundl,incnd,irwt,iv,iv1,iv2,mode,
     & ivindx,pgopta,pgflag,idxtop
c
c  In the comments below, input means that the value is set before
c  calling htrc1, computed means that it is set inside htrc1 and
c  is for communication to lower level routines, and output means
c  that the quantity is returned by htrc1.
c  axpf   Axial power peaking factor (used for chf) (input).
c  beta   Coefficient of thermal expasnsion of appropriate phase
c         (computed).
c  chf    Critical heat flux (output).
c  chfmul Critical heat flux table lookup multiplier (output).
c         or Critical heat flux ratio (used for pg chfr).
c  cps    Specific heat of appropriate phase (computed).
c  dtsat  Wall temperature minus saturation temperature (computed).
c  drod   Rod outer diameter.
c  enliq  Liquid enthalpy (computed)
c  fstrat Percent of liquid stratification (computed).
c  g      Total cell centered mass flux (input).
c  gabs   Absolute value of total centered mass flux (input).
c  gamw   Direct wall flashing or condensation (output).
c  ggasa  Cell centered vapor mass flux (input).
c  gliqa  Cell centered liquid mass flux (input).
c  gridz  Distance to grid spacer (used for chf) (input).
c         or Heated channel inlet equilibrium quality based on total
c         pressure (used for pg chfr).
c  gridk  Grid spacer pressure loss coefficient (used for chf) (input).
c         or Grid spacer factor (used for pg chfr).
c  hfg    Heat of vaporization (enthalpy difference between saturated
c         vapor and saturated liquid) (input).
c  hfgp   hfg based on total pressure (computed).
c  htcf   Heat transfer coefficient to liquid (output).
c  htcg   Heat transfer coefficient to vapor (output).
c  htcoef Total heat transfer coeffieient (output).
c  htdiam Heated equivalent diameter (input).
c  htgamf Factor to convert heat flux to interface mass transfer due to
c         flashing at wall.
c  htgamg Factor to convert heat flux to interface mass transfer due to
c         condensing at wall.
c  htzht  Total heat transfer coefficient from wall to fluid.
c  htzhff Heat transfer coefficient from wall to liquid using liquid
c         temperature.
c  htzhft Heat transfer coefficient from wall to liquid using saturation
c         temperature corresponding to total pressure.
c  htzhgg Heat transfer coefficient from wall to vapor using vapor
c         temperature.
c  htzhgt Heat transfer coefficient from wall to vapor using saturation
c         temperature corresponding to total pressure.
c  htzhgp Heat transfer coefficient from wall to vapor using saturation
c         temperature corresponding to partial pressure.
c  htlen  Heat transfer length from some position (used for chf)
c         (input).
c         or Reduced heat transfer length from some position
c            (used for pg chfr) (input).
c  htlenc Heat transfer length for natural convection (input).
c  htopta  Heat transfer package option number.
c  htqot  Old time total heat flux to fluid.
c  htqof  Old time heat flux to liquid.
c  htqog  Old time heat flux to vapor.
c  htsa   Heat transfer surface area (input).
c  ibundl Rod bundle flag (computed).
c  irwt   Vertical/horizontal flag (computed).
c  iv     Volume index (input).
c  mode   Mode of heat transfer (output).
c  pitdia Rod pitch/diameter. (input)
c  qffo   Heat flux to liquid (output).
c  qfgo   Heat flux to vapor (output).
c  qfgox  Left (1) and right (2) heat flux to vapor (output).
c  qfluxo Total heat flux (output).
c  qualep Equalibrium quality based on total pressure (computed)
c  sathfp Saturation liquid enthalpy based on total pessure (computed)
c  tf     Volume liquid temperature (computed).
c  thcons Thermal conductivity of appropriate phase (computed).
c  tsat   Saturation temperature corresponding to partial pressure of
c         fluid (input).
c  tw     Wall surface temperature (input).
c  viscs  Viscosity of appropriate phase (computed).
