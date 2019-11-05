*mlist
c  radata contains radiation heat transfer parameters.
c
c  Cognizant engineer: ewc.
c
*if def,selap
       common /radata/ fviewg(ndcomp,ndcomp,ndcomp),
     & pathlg(ndcomp,ndcomp,ndcomp),
     & nsigvu(ndcomp),numenc,ngroup(ndcomp,ndcomp,2),
     & nrepfc(2*ndcomp,2*ndcomp),nensur(ndcomp,ndcomp),mcme58
       real fviewg,pathlg
       integer nsigvu,numenc,ngroup,mcme58
       integer nrepfc
       integer nensur
c      numenc        = number of radiation enclosures (0<numenc<16)
c      ngroup(i,j,k)   = number of the j-th component in the i-th
c                      radiation enclosure, k = 1 for component number,
c                      k = 2 for index to component.
c      fviewg(k,m,n) = view factor from m-th component to n-th
c                      component within k-th enclosure.
c      pathlg(k,m,n) = path length from m-th to n-th component
c                      within k-th enclosure.
c
c                    For definition of related variables NVAD, NGPV,
c                    NGPC, IGP, ICP, NENHYD, see comdeck TBLSP
c
c      nrepfc(i,j) = absolute flow channel number of flow channel j
c                    in enclosure i.
c      nensur(i,j) = radial node number for surface of component j
c                    in enclosure i.
*endif
