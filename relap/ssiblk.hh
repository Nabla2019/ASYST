*mlist
!
!  Cognizant engineer: rjw.
!
!  steady-state self initialization block for redundant checking.
       integer ssiskp
       parameter (ssiskp=9)
       integer npumps(l_),nstctl(l_),nfeeds(l_),
     & compid(l_),contid(l_),cvrtno(l_),cmptno(l_),cmpvno(l_),
     & cmptrp(l_),cmpiii(l_)
       real cmpvnm(l_),pzpres(l_)
       equivalence (ia(1),npumps(1)),(ia(2),nstctl(1)),
     & (ia(3),nfeeds(1)),
     & (ia(4),compid(1)),(ia(5),contid(1)),(ia(6),cvrtno(1)),
     & (ia(7),cmptno(1)),(fa(8),cmpvnm(1)),(ia(9),cmpvno(1)),
     & (ia(10),cmptrp(1)),(fa(11),pzpres(1)),(ia(12),cmpiii(1))
!
!     ssiskp = skip factor, the number of words from compid to cmpiii
!     npumps = no. of pump component, controller pairs
!     nstctl = no. of steam component, controller pairs
!     nfeeds = no. of feed component, controller pairs
!     compid = component no. of regulated component
!     contid = controller no. regulating compid
!     cvrtno = controller type no.
!     cvrtnm = controller type name
!     cmptno = component type no.
!     cmptnm = component type name
!     cmpvnm = component search or control variable name
!     cmpvno = component search or control variable no.
!     cmptrp = component controlling trip no.
!     cmpxxx = dummy real variable
!     cmpiii = time dependent data table type
!     pcmpid = component no. of pressurizer component
!     pcnnec = component no. of pressurizer connection
!     pcntno = connection component type no.
!     pcntnm = connection component type name
!     pcmtno = pressurizer component type no.
!     pcmtnm = pressurizer component type name
!     pcmvnm = pressurizer component search variable name
!     pcmvno = pressurizer component search variable number
!     pcmtrp = pressurizer component trip no.
!     pzpres = pressurizer pressure
!     pzityp = pressurizer component time dependent table type no.
!
!     total file length = 4 + ssiskp*(npumps + nstctl + nfeeds)
!                           + ssiskp (if card 147 is input)
!     since the max value of npumps, nstctl, and nfeeds is 6 each,
!     then the largest file size for this file is 213 words.
