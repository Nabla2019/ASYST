*mlist
c
c  Descriptive sentence for oxcom4 goes here.
c
c  Cognizant engineer: rjw.
c
       common /oxcom4/ stmlmt(ndax,ndcomp),diflmt(ndax,ndcomp),
     & nolmt(ndax,ndcomp),mcme106
       real stmlmt,diflmt,nolmt
       integer mcme106
c All parameters in this common have units of
c kg/m2-s, and describe the oxidation rate limits.
c
c stmlmt is the limit based on steam availability
c diflmt is the limit based on mass diffusion
c nolmt is the oxidation rate if no limit were applied
