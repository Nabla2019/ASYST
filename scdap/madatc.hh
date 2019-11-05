*mlist
c
c  madatc contains control rod material data.
c
c  Cognizant engineer: ewc.
c
*if def,selap
       common /madatc/ ttempc,tcpc,troc,tkc,mrkc,mrkmxc,imxc,mcme43
       real ttempc(10),tcpc(10,10),troc(10,10),tkc(10,10)
       integer mrkc,mrkmxc,imxc,mcme43
*endif
