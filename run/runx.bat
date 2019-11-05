del edhtrkp.rr
del edhtrkp.pp
del edrstp.pp
del edplot.pp
..\relap5d -i edhtrkp.i -o edhtrkp.pp -r edhtrkp.rr -w ..\tpfh2o -Q
..\relap5d -i edrst.i -o edrstp.pp -r edhtrkp.rr -w ..\tpfh2o -Q
..\relap5d -i edplot.i -o edplot.pp -r edhtrkp.rr -w ..\tpfh2o -Q
del edhtrkp.rr
del typpwrp.rr
del typpwrp.pp
..\relap5d -i typpwrp.i -o typpwrp.pp -r typpwrp.rr -w ..\tpfh2o -Q
del typpwrp.rr
del ans79.pp
..\relap5d -i ans79.i -o ans79.pp -w ..\tpfh2o -Q
del edhtrk.rr
del edhtrk.pp
del edrst.pp
del edstrip.pp
del edstrip.stt
..\relap5d -i edhtrk.i -o edhtrk.pp -r edhtrk.rr -w ..\tpfh2o -Q
..\relap5d -i edrst.i -o edrst.pp -r edhtrk.rr -w ..\tpfh2o -Q
..\relap5d -i edstrip.i -o edstrip.pp -r edhtrk.rr -s edstrip.stt -Q
del edhtrk.rr
del edhtrkd.rr
del edhtrkd.pp
..\relap5d -i edhtrkd.i -o edhtrkd.pp -r edhtrkd.rr -d ..\tpfd2o -Q
del edhtrkd.rr
del edhtrkn.rr
del edhtrkn.pp
..\relap5d -i edhtrkn.i -o edhtrkn.pp -r edhtrkn.rr -w ..\tpfh2o -Q
del edhtrkn.rr
del marpzd4.rr
del marpzd4.pp
..\relap5d -i marpzd4.i -o marpzd4.pp -r marpzd4.rr -d ..\tpfd2o -Q
del marpzd4.rr
del pump2.pp
..\relap5d -i pump2.i -o pump2.pp -w ..\tpfh2o -Q
del typpwr.rr
del typpwr.pp
..\relap5d -i typpwr.i -o typpwr.pp -r typpwr.rr -w ..\tpfh2o -Q
del typpwr.rr
del typpwrn.rr
del typpwrn.pp
del typextr.pp
del typextr.stt
..\relap5d -i typpwrn.i -o typpwrn.pp -r typpwrn.rr -w ..\tpfh2o -Q
..\relap5d -i typextr.i -o typextr.pp -r typpwrn.rr -w ..\tpfh2o -s typextr.stt -Q
del typpwrn.rr
del typ1200n.rr
del typ1200n.pp
..\relap5d -i typ1200n.i -o typ1200n.pp -r typ1200n.rr -w ..\tpfh2o -Q
del typ1200n.rr
del typpwrr.rr
del typpwrr.pp
del compare.pp
..\relap5d -i typpwrr.i -o typpwrr.pp -r typpwrr.rr -w ..\tpfh2o -Q
..\relap5d -i compare.i -o compare.pp -w ..\tpfh2o -Q
del typpwrr.rr
del dumpfil1
del dumpfil2
del tbt.pp
del tbt.rr
..\relap5d -i tbt.i -o tbt.pp -r tbt.rr -w ..\tpfh2o -Q
del tbt.rr
del cstest1.pp cstest2.pp cstest.rr
..\relap5d -i cstest1.i -o cstest1.pp -r cstest.rr -w ..\tpfh2o -Q
..\relap5d -i cstest2.i -o cstest2.pp -r cstest.rr -w ..\tpfh2o -Q
del cstest.rr
del radtst.pp radtst.rr
..\relap5d -i radtst.i -o radtst.pp -r radtst.rr -w ..\tpfh2o -Q
del radtst.rr
del boiloff.pp
del boiloff.rr
..\relap5d -i boiloff.i -o boiloff.pp -r boiloff.rr -w ..\tpfh2o -Q
del boiloff.rr
del scp2.rr
del scp2.pp
del scrst.pp
..\relap5d -i scp2.ii -o scp2.pp -r scp2.rr -w ..\tpfh2o -Q
..\relap5d -i scrst.ii -o scrst.pp -r scp2.rr -w ..\tpfh2o -Q
del scp2.rr
del scvp2.pp
..\relap5d -i scvp2.i -o scvp2.pp -w ..\tpfh2o -Q
