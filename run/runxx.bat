del edhtrkp.r
del edhtrkp.p
del edrstp.p
del edplot.p
..\relap5o -i edhtrkp.i -o edhtrkp.p -r edhtrkp.r -w ..\tpfh2o -Q
..\relap5o -i edrst.i -o edrstp.p -r edhtrkp.r -w ..\tpfh2o -Q
..\relap5o -i edplot.i -o edplot.p -r edhtrkp.r -w ..\tpfh2o -Q
del edhtrkp.r
del typpwrp.r
del typpwrp.p
..\relap5o -i typpwrp.i -o typpwrp.p -r typpwrp.r -w ..\tpfh2o -Q
del typpwrp.r
del ans79.p
..\relap5o -i ans79.i -o ans79.p -w ..\tpfh2o -Q
del edhtrk.r
del edhtrk.p
del edrst.p
del edstrip.p
del edstrip.st
..\relap5o -i edhtrk.i -o edhtrk.p -r edhtrk.r -w ..\tpfh2o -Q
..\relap5o -i edrst.i -o edrst.p -r edhtrk.r -w ..\tpfh2o -Q
..\relap5o -i edstrip.i -o edstrip.p -r edhtrk.r -s edstrip.st -Q
del edhtrk.r
del edhtrkd.r
del edhtrkd.p
..\relap5o -i edhtrkd.i -o edhtrkd.p -r edhtrkd.r -d ..\tpfd2o -Q
del edhtrkd.r
del edhtrkn.r
del edhtrkn.p
..\relap5o -i edhtrkn.i -o edhtrkn.p -r edhtrkn.r -w ..\tpfh2o -Q
del edhtrkn.r
del marpzd4.r
del marpzd4.p
..\relap5o -i marpzd4.i -o marpzd4.p -r marpzd4.r -d ..\tpfd2o -Q
del marpzd4.r
del pump2.p
..\relap5o -i pump2.i -o pump2.p -w ..\tpfh2o -Q
del typpwr.r
del typpwr.p
..\relap5o -i typpwr.i -o typpwr.p -r typpwr.r -w ..\tpfh2o -Q
del typpwr.r
del typpwrn.r
del typpwrn.p
del typextr.p
del typextr.st
..\relap5o -i typpwrn.i -o typpwrn.p -r typpwrn.r -w ..\tpfh2o -Q
..\relap5o -i typextr.i -o typextr.p -r typpwrn.r -w ..\tpfh2o -s typextr.st -Q
del typpwrn.r
del typ1200n.r
del typ1200n.p
..\relap5o -i typ1200n.i -o typ1200n.p -r typ1200n.r -w ..\tpfh2o -Q
del typ1200n.r
del typpwrr.r
del typpwrr.p
del compare.p
..\relap5o -i typpwrr.i -o typpwrr.p -r typpwrr.r -w ..\tpfh2o -Q
..\relap5o -i compare.i -o compare.p -w ..\tpfh2o -Q
del typpwrr.r
del dumpfil1
del dumpfil2
del tbt.p
del tbt.r
..\relap5o -i tbt.i -o tbt.p -r tbt.r -w ..\tpfh2o -Q
del tbt.r
del cstest1.p cstest2.p cstest.r
del cstest1.p cstest2.p cstest.r
..\relap5o -i cstest1.i -o cstest1.p -r cstest.r -w ..\tpfh2o -Q
..\relap5o -i cstest2.i -o cstest2.p -r cstest.r -w ..\tpfh2o -Q
del cstest.r
del radtst.p radtst.r
..\relap5o -i radtst.i -o radtst.p -r radtst.r -w ..\tpfh2o -Q
del radtst.r
del boiloff.p
del boiloff.r
..\relap5o -i boiloff.i -o boiloff.p -r boiloff.r -w ..\tpfh2o -Q
del boiloff.r
del scp2.r
del scp2.p
del scrst.p
..\relap5o -i scp2.i -o scp2.p -r scp2.r -w ..\tpfh2o -Q
..\relap5o -i scrst.i -o scrst.p -r scp2.r -w ..\tpfh2o -Q
del scp2.r
del scvp2.p
..\relap5o -i scvp2.i -o scvp2.p -w ..\tpfh2o -Q
