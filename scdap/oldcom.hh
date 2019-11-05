*mlist
c
c  Cognizant engineer: ewc.
c 
*if def,selap
       common /oldcom/acrstz(ndax*ndcomp),afuelz(ndax*ndcomp),
     & pgasz(ndcomp),alfaiz(ndax*ndcomp),alfaoz(ndax*ndcomp),
     & tcondz(ndrd,ndax,ndcomp),vfvodz(ndax*ndcomp),
     & xcondz(ndrd,ndax,ndcomp),
     & flwh2z(2*ndax*ndcomp), 
     & flstmz(2*ndax*ndcomp),vfuelz(2*ndax*ndcomp),
     & effcfz(ndax*ndcomp),effqfz(ndax*ndcomp),oxdeiz(ndax*ndcomp),
     & oxdeoz(ndax*ndcomp),oxdwcz(ndax*ndcomp),oxdwfz(ndax*ndcomp),
     & odwcoz(ndax,ndcomp),rciz(ndax*ndcomp),rcrstz(ndax*ndcomp),
     & rissz(ndax*ndcomp),oxdwsz(ndax*ndcomp),dzfrcz(2*ndax*ndcomp),
     & rcrmxz(ndax*ndcomp),qflx0z(2*ndax*ndcomp),hfixfz(2*ndax*ndcomp),
     & qcladz(ndax*ndcomp),hfixgz(2*ndax*ndcomp),ruliqz(ndax*ndcomp),
     & vlcrsz(ndax*ndcomp),wbtuoz(ndcomp),rosabz(ndax*ndcomp),
     & wbtoxz(ndcomp),wbtzrz(ndcomp),wumltz(ndax*ndcomp),
     & tkhpnz(ndcomp),ahdpnz(ndcomp),bhdpnz(ndcomp),chdpnz(ndcomp),
     & rumltz(ndax*ndcomp),wrmuoz(ndax*ndcomp),wrmzrz(ndax*ndcomp)
       common /oldcom/
     & wuormz(ndax*ndcomp),wrmzoz(ndax*ndcomp),ggivyz(17,ndcomp),
     & rnalfz(ndax*ndcomp),rnoxdz(ndax*ndcomp),dzfclz(ndax*ndcomp),
     & tcolcz(2*ndax*ndcomp),h2oxdz(ndax*ndcomp),ioxerz(ndax*ndcomp),
     & ltrnsz(ndax*ndcomp),nfrslz(ndax*ndcomp),noxidz(ndax*ndcomp),
     & rpelz(ndax*ndcomp),fpivyz(ndax*16,ndcomp),nfiz(ndax*ndcomp),
     & wfruoz(ndax*ndcomp),wfrzrz(ndax*ndcomp),iphasz(ndax*ndcomp),
     & vldebz(ndax*ndcomp),qotz,qocz,qorz,qprz,
     & pcoolz,qosz,qonz,qooz,qoez,qstz,qtor0z(ndcomp),qst0z,tupolz,
     & wupolz,wzpolz,qdpolz,wapolz,wspolz,qhpolz,hnpolz(ndcomp),repolz,
     & vlpolz,eltldz,qrdsrz(2*ndax*ndcomp),
     & pwseqz(200),ethdbz(200),
     # timszs(200),timsze(200),wagsqz(200),
     & wbcsqz(200),wsssqz(200),wuosqz(200),wursqz(200),wzosqz(200),
     & wzrsqz(200),rrstoz(ndax*ndcomp),rrsx0z(ndax*ndcomp),
     & rcoiz(ndax*ndcomp),rcoz(ndax*ndcomp),stzroz(ndax*ndcomp),
     & tmzo2z(ndax,ndcomp),wbtabz(ndcomp),wbtsrz(ndcomp),
     & cumcoz(ndcomp),cumco2z(ndcomp),cumch4z(ndcomp),
     & wh2b4cz(ndcomp)
       common /oldcom/
     & wfrabz(ndax*ndcomp),wfrsrz(ndax*ndcomp),wrmabz(ndax*ndcomp),
     & winclz(ndax,ndcomp),thnclz(ndax,ndcomp),winrmz(ndax,ndcomp),
     & winfrz(ndax,ndcomp),wnliqz(ndax,ndcomp),wfrsriz(ndax*ndcomp),
     & rdmatz(ndmatr+1,ndax,ndcomp),wlxxxz(19,maxcpm,maxstp),
     & wlxdtz(19,maxcpm,maxstp),wfrabiz(ndax*ndcomp),
     & rbcz(ndax*ndcomp),rboz(ndax*ndcomp),
     & rssz(ndax*ndcomp),rsoz(ndax*ndcomp), r1z(ndax*ndcomp),
     & r2z(ndax*ndcomp),r1bcsz(ndax*ndcomp),r1bclz(ndax*ndcomp),
     & r1bosz(ndax*ndcomp), r1bolz(ndax*ndcomp),r2sssz(ndax*ndcomp),
     & r2sslz(ndax*ndcomp),r2sosz(ndax*ndcomp), r2solz(ndax*ndcomp),
     & vssz(ndax*ndcomp),rnoxdiz(ndax*ndcomp),rnalfiz(ndax*ndcomp)
       common /oldcom/ wssconz(ndax,ndcomp,8),
     &  wrbsziz(ndax,ndcomp,12),wrbszoz(ndax,ndcomp,12),
     &  cwb4cz(ndax,ndcomp),cwb2o3z(ndax,ndcomp)
     & ,oxdwci2z(ndax,ndcomp),reazsz(ndax,ndcomp)
       real wssconz, wrbsziz,wrbszoz,cwb4cz,cwb2o3z,reazsz
       common /oldcom/ cfnckz(ndax),cfncnz(ndax),
     & ccwkfz(ndax),ccwnfz(ndax),caadz(ndax),cacdz(ndax),
     & cardz(ndax),cfcpz(ndax),cfapz(ndax),cfrpz(ndax),cepz(ndax),
     & cepsz(ndax,3),ceppz(ndax,3),deppz(ndax,3),edotz(ndax)
       common /oldcom/ etrucz(ndax,ndcomp),dcfrcz(ndax,ndcomp),
     & eplscz(ndax,ndcomp),cnckcz(ndax,ndcomp),cncncz(ndax,ndcomp),
     & cwnfcz(ndax,ndcomp),caadcz(ndax,ndcomp),cacdcz(ndax,ndcomp),
     & cardcz(ndax,ndcomp),cfcpcz(ndax,ndcomp),cfapcz(ndax,ndcomp),
     & cfrpcz(ndax,ndcomp),cepcz(ndax,ndcomp),edotcz(ndax,ndcomp),
     & cepscz(ndax,3,ndcomp),ceppcz(ndax,3,ndcomp),
     & deppcz(ndax,3,ndcomp),hpmxcz(ndcomp),rmincz(ndcomp),
     & creacz(ndcomp),cflxcz(ndcomp),cnwdcz(ndcomp),cdt0cz(ndcomp),
     & rraicz(ndcomp),fraicz(ndcomp),hpmncz(ndcomp),blkycz(ndax,ndcomp),
     & rfarz(ndax,ndcomp),hoopz(ndax*ndcomp)
       real cfnckz,cfncnz,ccwkfz,ccwnfz,caadz,cacdz,cardz,cfcpz,cfapz,
     & cfrpz,cepz,cepsz,ceppz,deppz,edotz,wfrsriz,wh2b4cz
       real etrucz,cnckcz,cncncz,cwnfcz,caadcz,cacdcz,cardcz,cfcpcz,
     & cfapcz,cfrpcz,cepcz,cepscz,ceppcz,deppcz,edotcz
       real dcfrcz,eplscz,hfixfz,hfixgz,hpmxcz,rmincz,
     & creacz,cflxcz,cnwdcz,cdt0cz,rraicz,fraicz,hpmncz,blkycz,
     & rfarz,hoopz,suriratz
       real rbcz,rboz,rssz,rsoz,r1z,r2z,r1bcsz,r1bclz,rciz,rcrstz,
     & r1bosz,r1bolz,r2sssz,r2sslz,vfuelz,vldebz,pwseqz,ethdbz,
     & timszs,timsze,rnoxdiz,rnalfiz,cumcoz,cumco2z,cumch4z,
     & wagsqz,wbcsqz,wsssqz,wuosqz,wursqz,wzosqz,wzrsqz,qflx0z,
     & tupolz,wupolz,wzpolz,qdpolz,wapolz,wspolz,rissz,rosabz,
     & qhpolz,hnpolz,repolz,vlpolz,eltldz,rdmatz,b4cgsz,
     & r2sosz,r2solz,vssz,wlxxxz,wlxdtz,tkhpnz,ahdpnz,bhdpnz,chdpnz
       common /oldcom/ wrmsrz(ndax*ndcomp),wzincz(ndax,ndcomp),
     & wzgfzz(ndax,ndcomp),dzrnfz(ndax,ndcomp),dnzrfz(ndax,ndcomp),
     & dxdisz(ndax,ndcomp),tkgplz(ndax,ndcomp), rtabgz(ndax,ndcomp),
     & dxgrdz(ndax,ndcomp),dgrdmz(ndax,ndcomp),da1grz(ndax,ndcomp),
     & dz1grz(ndax,ndcomp),odhccz(ndax,ndcomp),odhfcz(ndax,ndcomp),
     & huoxiz(ndax,ndcomp),uwgoz(ndax,ndcomp),huoxoz(ndax,ndcomp),
     & quoxiz(ndax,ndcomp),quoxoz(ndax,ndcomp),
     & odwaiz(ndax,ndcomp),odwaoz(ndax,ndcomp),
     & thtgrz(ndax,ndcomp),uwgiz(ndax,ndcomp),
     & alfooz(ndax,ndcomp),hoxdoz(ndax,ndcomp),
     & ralfoz(ndax,ndcomp),roxdoz(ndax,ndcomp),odhcoz(ndax,ndcomp),
     & rcooz(ndax,ndcomp),oxdooz(ndax,ndcomp),
     & tmarxz(8,ndcomp,ndax),tmvrxz(8,ndcomp,ndax),
     & dlarxz(8,ndcomp,ndax),dlvrxz(8,ndcomp,ndax),
     & qchdbz(ndax,nxdbrg),qhlbnz(ndax,ndcomp),
     & brchvz(ndax,ndcomp),dfrcqz(ndax,ndcomp),pwrubz(ndax,ndcomp),
     & gtoxz(ndax,ndcomp),b4coxz(ndax,ndcomp),oxdsoz(ndax*ndcomp),
     & b4cgsz(ndax,ndcomp,5),suriratz(ndax,ndcomp)
       common /oldcom/ efoxdz(ndcomp,ndax)
       real acrstz,afuelz,pgasz,alfaiz,alfaoz,tcondz,vfvodz,xcondz,
     & flwh2z,flstmz,effcfz,effqfz,oxdeiz,oxdeoz,alfooz,oxdsoz,
     & oxdwcz,oxdwfz,oxdwsz,odwcoz,h2oxdz,hoxdoz,qchdbz,xcondy,
     & dzfrcz,rcrmxz,qcladz,ruliqz,vlcrsz,wbtuoz,wbtoxz,wbtzrz,
     & wumltz,rumltz,wrmuoz,wrmzrz,wuormz,odwaoz,
     & wrmzoz,uwgiz,huoxiz,quoxiz,uwgoz,huoxoz,quoxoz,odwaiz,
     & ggivyz,rnalfz,rnoxdz,ralfoz,roxdoz,odhcoz,dzfclz,fpivyz,
     & tcolcz,rpelz,wfruoz,wfrzrz,oxdwci2z,
     & rcoiz,rcoz,rrstoz,rrsx0z,stzroz,tmzo2z,wbtabz,wfrabiz,
     &  wbtsrz,wfrabz,wfrsrz,wrmabz,tmarxz,tmvrxz,dlarxz,dlvrxz,
     &  winclz,thnclz,winrmz,winfrz,wnliqz,wrmsrz,wzincz,wzgfzz,qotz,
     & qocz,qorz,qprz,pcoolz,qosz,qonz,qooz,qoez,qstz,qtor0z,qst0z,
     & dzrnfz,dnzrfz,dxdisz,tkgplz,rtabgz,dxgrdz,thtgrz,dgrdmz,brchvz,
     & efoxdz,odhccz,odhfcz,da1grz,dz1grz,rcooz,
     & oxdooz,dfrcqz,pwrubz,paxpzz,qrdsrz,qhlbnz,
     & gtoxz,b4coxz
       logical ltrnsz
c  atr common block
       common/oldcom/mscaoz(ndax,ndcomp),
     & mscooz(ndax,ndcomp),mscaiz(ndax,ndcomp),mscoiz(ndax,ndcomp),
     & masfaz(ndax,ndcomp),msfaoz(ndax,ndcomp),masfuz(ndax,ndcomp),
     & msfuoz(ndax,ndcomp),ttmasz(ndax,ndcomp)
       real mscaoz,mscooz,mscaiz,mscoiz,masfaz,msfaoz,masfuz,msfuoz,
     & ttmasz
c
c  paragrass common block.
       common /oldcom/ ciz(15*ndax*ndcomp),acaez(ndax*ndcomp),
     & prfz(ndax*ndcomp),gsgz(5*ndax*ndcomp),gouz(6*ndax*ndcomp),
     & disz(16*ndax*ndcomp),dlmoz(4*ndax*ndcomp),griraz(5*ndax*ndcomp),
     & tliqsz(ndax*ndcomp),tcapz(ndax*ndcomp),bukz(ndax*ndcomp),
     & rxdz(4*ndax*ndcomp),fgrmgz(ndax*ndcomp),svz(4*ndax*ndcomp),
     & hhz(ndax*ndcomp), tkgsz(ndax*ndcomp),vlmz(ndax*ndcomp),
     & grainz(ndax*ndrd*ndcomp),atoz(4*ndax*ndcomp),ccz(5*ndax*ndcomp),
     & iliqz(ndax*ndcomp),kraphz(ndcomp)
       real ciz,acaez,prfz,gsgz,gouz,disz,dlmoz,
     & griraz,tliqsz,tcapz,bukz,rxdz,
     & fgrmgz,svz,hhz,tkgsz,vlmz,grainz,atoz,ccz
c
       common / oldcom /
     & irubpz(ndax,ndcomp),nhrdpz(ndcomp),idebcz(ndcomp),
     & icladz(ndcomp),iiz(ndcomp),ical0z(ndcomp),nbnclz(ndcomp),
     & lcrucz(ndax,ndcomp),irubqz(ndax,ndcomp),ienblz(ndax,ndcomp),
     & itopdz(ndax,ndcomp),idebqz(ndax,ndcomp),nblkrz(ndax,ndcomp),
     & numrtz,jnumrz(ndax),knumrz(ndax),
     & jrtpoz(ndax),kbtpoz(ndcomp),numbtz,jnumbz(ndcomp),knumbz(ndcomp),
     & nbypsz,lbpsiz(ndax),
     & nplblz(ndcomp,ndax),nbublz(ndcomp,ndax),nunblz(ndcomp,ndax),
     & nunb2z(ndcomp,ndax),
     & nflgz(2*(ndax-1),ndcomp),icohpz(ndax,ndcomp),icohtz(ndcomp),
     & icohbz(ndcomp),nflg1z(2*(ndax-1),ndcomp),nodez(ndax),
     & nsqarz(ndcomp,ndax),nsqvrz(ndcomp,ndax),nmaxrz,icrc2z,
     & nswcez,nswchz,nswhdz,nswliz,nswqz,nswq2z,nswqdz,nswruz,nswtoz,
     & numdez,nswblz,newpbz,newpuz
c
       integer irubpz,nhrdpz,idebcz,icladz,iiz,ical0z,nbnclz,
     & lcrucz,irubqz,ienblz,
     & itopdz,idebqz,nblkrz,numrtz,jnumrz,knumrz,
     & jrtpoz,kbtpoz,numbtz,jnumbz,knumbz,nbypsz,lbpsiz,
     & nplblz,nbublz,nunblz,nunb2z,nenhyz,
     & nflgz,icohpz,icohtz,icohbz,nflg1z,nodez,
     & nsqarz,nsqvrz,nmaxrz,icrc2z,
     & nswcez,nswchz,nswhdz,nswliz,nswqz,nswq2z,nswqdz,nswruz,nswtoz,
     & numdez,nswblz
       logical newpbz,newpuz
c
       common / oldcom / invz, ncnt1z, ncnt2z, ncvolz,
     &         nqcycz, nsqslz,
     &         nobroz(maxcpm), nctcnz(maxcpm), nctcoz(maxcpm),
     &         ncmesz(maxcpm), nslphz(maxcpm), nslumz(maxcpm),
     &         nstslz(maxcpm), ntsoiz(maxcpm), ntpslz(maxcpm),
     &         ntstrz(maxcpm),
     &         nsptrz(maxcpm,maxstp), iksavz(maxcpm),
     &         icmesz(6,maxcpm), ifpdbz(19,maxcpm,maxstp) ,mcme99
       integer nslumz,nstslz,nsqslz,nqcycz,ncvolz,invz,
     &         nctcnz, nctcoz, ntsoiz, ntpslz, ntstrz, iksavz,
     &         nslphz, nsptrz, ifpdbz, nobroz, ncmesz, icmesz,
     &         ncnt1z, ncnt2z
       integer iliqz,kraphz,iphasz,ioxerz,noxidz,nfiz,nfrslz,mcme99
*endif
