*mlist
*comdeck uphdpn
c
c  Cognizant engineer: ewc.
c
c  Descriptive sentence for uphdpn goes here.
c
*if def,selap
       common /uphdpn/ thkupn(ndcomp),auppan(ndcomp),buppan(ndcomp),
     * cuppan(ndcomp),tiupan(ndcomp),t0upan(ndcomp),cnupan(ndcomp),
     * rhupan(ndcomp),cpupan(ndcomp),qdupan(ndcomp),faupan(ndcomp),
     * hcupan(ndcomp),tmupan(ndcomp),hnupan(ndcomp),afpool(11),
     * wuslpu,wzslpu,waslpu,wsslpu,tmslpu,qdslpu,vcrucb,
     * nsupan(ndcomp),mcme72
       real thkupn,auppan,buppan,cuppan,tiupan,t0upan,cnupan,rhupan,
     * cpupan,qdupan,faupan,hcupan,tmupan,hnupan,afpool,wuslpu,
     * wzslpu,waslpu,wsslpu,tmslpu,qdslpu,vcrucb
       integer nsupan,mcme72
c  thkupn(j)=thickness of crust on top of molten pool (m).
c            calculated in sub. tmpupn. j=component number.
c  auppan(j)=the "a" coefficient in polynomial describing temperature
c            distribution through crust as function of distance from
c            top of crust downward.
c  buppan(j)= the "b" coefficient.
c  cuppan(j)=the "c" coefficient.
c  tiupan(j)=temperature of upper crust in side interfacing with
c            molten pool (z=thkupn(j)) (k).
c  nsupan(j)=indicator of whether temperature solution through upper
c            crust has begun. 0=no,1=yes.
c            nsupan(j)=0 on first time step that crust comes into
c            existence.
c  t0upan(j)=temperature of upper crust when nsupan(j)=0. (temp-
c            erature when crust first formed.)
c  cnupan(j)=thermal conductivity of upper crust (w/m.k)
c  rhupan(j)=density of upper crust (kg/m**3)
c  cpupan(j)=heat capacity of upper crust (j/kg.k)
c  qdupan(j)=heat generation in upper crust (w/m**3).
c  faupan(j)=configuration factor on radiation for upper crust.
c  hcupan(j)=h.t.c. due to convection at top surface of upper crust.
c  tmupan(j)=melting temperature of upper crust (k).
c  hnupan(j)=natural convection h.t.c. of pool at its upper crust
c            (w/m**2.k)
c  afpool(7)=molar fractions of constituents of molten pool.
c  afpool(1)=0.0 always
c  afpool(2)=0.0 always
c  afpool(3)=molar fraction of stainless steel in pool.
c  afpool(4)=molar fractions of silver on pool.
c  afpool(5)=0.0 always.
c  afpool(6)=molar fraction of uo2 in pool.
c  afpool(7)=molar fraction of zro2 in pool.
c  wuslpu=mass of uo2 that slumped into lower head by failure of
c         upper crust (kg)
c  wzslpu=mass of zro2 (kg).
c  waslpu=mass of silver (kg).
c  wsslpu=mass of stainless steel (kg).
c  tmslpu=temperature of material that slumped (k).
c  qdslpu=decay heat in material that slumped (w/m**3).
c  vcrucb=maximum volume of molten material that can be contained by
c         bottom crust in damaged region of core (m**3).
*endif
