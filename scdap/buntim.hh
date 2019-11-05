*mlist
*comdeck buntim
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
c
       common /buntim/ deltb,oxtkdb,
     * brchv(ndax,ndcomp),irubnh(ndax,ndcomp),kaxndb,mcme08
       real deltb,oxtkdb,brchv
       integer kaxndb,irubnh
       integer mcme08
c
c      variables kaxndb thru oxtkdb are used for debugging.
c      kaxndb = current axial node
c      oxtkdb = start of time step oxide thickness.
c      brchv(i,j) = indicator of breach due to ballooning at i-th
c                   axial node of j-th component. 0=no breach, 1=yes.
c      irubnh(k,j) = irubpp(k,j) that is in tblsp common block.
c                    it is used in nheat.
*endif
