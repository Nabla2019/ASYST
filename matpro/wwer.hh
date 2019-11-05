       common /wwer/ imodel,iwwer
       integer imodel,iwwer
!  imodel  Set to 0 or 1 by chngno(73) during input processing and
!  controls constants used in coxthkr and coxwtkr. If imodel equal 0,
!  then Cathcart-Pawel constants are used; if not equal 0, then Baker-
!  Just constants are used.
!  iwwer   Set to 0, 1, or 2 by chngno(71) and chngno(72) during input
!  processing and controls options in matpro routines modified by
!  Kurchatov Institute.
