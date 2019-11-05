*mlist
!  Block for statistics during advancement, statc.h common block.
!
!  Cognizant engineer:
!
! T Name    Definition
! i stccf1  number of times junction used ccfl correlation in entire
! i         problem.
! i stccf2  number of times junction used ccfl correlation in this major
! i         print interval.
! i stjck1  number of times junction choked in entire problem.
! i stjck2  number of times junction choked in this major print
! i         interval.
! i stjskp  parameter set in statc.h, currently = 6
! i stlte1  number of times volume had largest mass error in entire
! i         problem.
! i stlte2  number of times volume had largest mass error in this major
! i         print interval.
! i strap1  number of time step repeats due to air appearance in this
! i         volume in entire problem.
! i strap2  number of time step repeats due to air appearance in this
! i         volume in this major print interval.
! i strcl1  number of times courant limit for this volume caused reduced
! i         time step in entire problem.
! i strcl2  number of times courant limit for this volume caused reduced
! i         time step in this major print interval.
! i strdc1  number of repeated time steps in entire problem.
! i strdc2  number of repeated time steps in this major print interval.
! i strdp1  number of time step repeats due to pressure change in this
! i         volume in entire problem
! i strdp2  number of time step repeats due to pressure change in this
! i         volume in this major print interval
! i strex1  number of times state extrapolation in volume caused reduced
! i         time steps in entire problem.
! i strex2  number of times state extrapolation in volume caused reduced
! i         time steps in this major print interval.
! i strpe1  number of times water property error in volume caused
! i         reduced time steps in entire problem.
! i strpe2  number of times water property error in volume caused
! i         reduced time steps during this major print interval.
! i strte1  number of times mass error in volume caused reduced time
! i         steps in entire problem.
! i strte2  number of times mass error in volume caused reduced time
! i         steps during this major print interval.
! i strxl1  number of times quality adjustment in volume caused reduced
! i         time steps in entire problem.
! i strxl2  number of times quality adjustment in volume caused reduced
! i         time steps in this major print interval.
! i stsatp  total number of advancements.
! i stscl1  number of times volume had smallest courant limit in entire
! i         problem.
! i stscl2  number of times volume had smallest courant limit in this
! i         major print interval.
! r stscpu  cpu time required.
! r stsdta  sum of time steps for averge over edit.
! r stsdtn  minimum time step during edit.
! r stsdtx  maximum time step during edit.
! i stsjpt  pointer to junction array.
! i stslen  parameter set in statc.h, currently = 9
! i stsreq  total number of requested advancements.
! i stsskp  parameter set in statc.h, currently = 20
