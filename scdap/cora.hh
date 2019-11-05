*mlist
!  Modified by H.Madokoro
!  Add rmelec,rmheat
*if def,selap
!  Simulator rod data.
!
!  Cognizant engineer: ljs.
!
       common /cora/ rhwire(ndax,ndcomp),
     & rtungs,relec,
     & rmheat(ndcomp),rmelec(ndcomp),
     & flxwid(ndcomp),mhsim(ndax,ndcomp),mhwire(ndax,ndcomp),
     & ielec,iuorho,icrmod,nbtcof(2,ndcomp),
     & rmcmp(2),rmtab(2),imtab(2),
     & cora,rmflg,mcme18
       real rhwire,flxwid
       real rtungs,relec
       real rmheat,rmelec
       integer mhwire,mhsim,rmcmp,rmtab,imtab
       integer icrmod,iuorho,ielec,nbtcof,mcme18
       logical cora,rmflg
!
!  flxwid(ndcomp) heater external resistance (ohm per rod) of 
!                 flexible cables. Set separately in each component.
!  iuorho   flag that includes effect of uo2 resistivity in electric
!           power calculation; omit=0, include=nonzero.
!  icrmod   flag for heater model:
!             0 = ineel model
!             1 = cora-lwr
!             2 = cora-vvr
!             3 = quench.
!  rhwire(k,icomp) = radius of heater element at axial node k
!                    of component icomp (m).
!  mhwire(k,icomp) = material index for heater element.
!  mhsim(k,icomp) = material index for fuel or simulator
!                   material surrounding heater element.
!  rmcmp(2) component number in which the experimental electrical 
!           resistance data is used.
!  rmtab(2) table number in which the experimental electrical 
!           resistance data is given.
!  imtab(2) holds the index table in the list of tables.
!  rmheat(icomp) electrical resistance of heater part (ohm per rod)
!  rmelec(icomp) electrical resistance of electrode part (ohm per rod)
*endif
