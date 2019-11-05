*mlist
!  Common block fecom carries miscellaneous fuel element data.
!
!  Cognizant engineer:ljs.
!
*if def,selap
!
!     idbnd   = 1 then n-reactor fuel debonding is modeled
!     idfe    = fuel element or shroud id (nfe x nfa-1)
!     idsh    = shroud or fuel element id (nsh)
!     ifa     = fuel assembly id
!     nfa     = total number of fuel assemblies + 1
!     nfe     = total number of fuel elements per fuel assembly
!     iuoxd   = 1 then uranium oxidation is modeled
!     naxn    = axial node id
!     noss    = 1 then steam starvation is not modeled
!     oxdout  = outer surface zr oxidation power (w/m)
!     qraden  = radiant energy rate between fuel elements (w)
!     xsubb   = fraction of clad bonded to fuel
!
       common /fecom/ oxdout,qraden(60,ndax,ndcomp),xsubb,naxn,
     & idsh(ndcomp),iuoxd,noss,idbnd,idfe(ndcomp,60),nfa,nfe(60),ifa,
     & mcme29
       real oxdout,qraden,xsubb
       integer naxn,idsh,iuoxd,noss,idbnd,idfe,nfa,nfe,ifa,mcme29
*endif
