*mlist
!  Descriptive sentence goes here.
!
!  Cognizant engineer: ljs.
!
*if def,selap
!
       common /debout/ absms(3*ndax,ndcomp),stums(ndax*ndcomp),
     & uo2nm(ndax*ndcomp),uo2ms(ndax*ndcomp),zrms(ndax*ndcomp),
     & zro2ms(ndax*ndcomp),vfuel(2*ndax*ndcomp),wfrouo(ndax*ndcomp),
     & wfrozr(ndax*ndcomp),hoop(ndax*ndcomp),vladeb(ndax*ndcomp),
     & tfrag,ifrag(ndax*ndcomp),movesw(ndax*ndcomp),mcme24
       real absms,stums,uo2nm,uo2ms,zrms,zro2ms,vfuel,wfrouo,wfrozr,
     & hoop,vladeb,tfrag
       integer ifrag,movesw,mcme24
!
       real vfuel2(2*ndax,ndcomp)
       equivalence(vfuel2(1,1),vfuel(1))
       real hoop2(ndax,ndcomp)
       equivalence(hoop2(1,1),hoop(1))
!
!     tfrag  = core fragmentation temperature.
!
*endif
