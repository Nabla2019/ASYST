*mlist
c
c  Cognizant engineer: ewc.
c
c  Descriptive sentence for trnot1 goes here.
c
*if def,selap
       common/trnot1/ hcnvec(2*ndax*ndcomp),pcool,
     & hout(ndcomp*ndax),tcols(ndcomp*ndax),qouts(ndcomp*ndax),
     & ishrd(ndcomp),icrad(ndcomp),iempty(ndax,ndcomp),mcme69
       real hcnvec,pcool,hout,tcols,qouts
       integer ishrd,icrad,iempty,mcme69
*endif
