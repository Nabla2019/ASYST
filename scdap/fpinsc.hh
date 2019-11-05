*mlist
*comdeck fpinsc
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ljs.
c
*if def,selap
       integer maxmt
       parameter (maxmt=1)
       common /fpinsc/ spsym,srftyp,mnam
       character spsym(maxsp)*4,srftyp(0:maxmt)*8,mnam*8
*endif
