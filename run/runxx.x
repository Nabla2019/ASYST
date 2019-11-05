rm -f edhtrkp.r edhtrkp.p edrstp.p edplot.p
../relap5o.x -i edhtrkp.i -o edhtrkp.p -r edhtrkp.r -w ../tpfh2o
../relap5o.x -i edrst.i -o edrstp.p -r edhtrkp.r -w ../tpfh2o
../relap5o.x -i edplot.i -o edplot.p -r edhtrkp.r -w ../tpfh2o
rm -f edhtrkp.r typpwrp.r typpwrp.p
../relap5o.x -i typpwrp.i -o typpwrp.p -r typpwrp.r -w ../tpfh2o
rm -f typpwrp.r ans79.p
../relap5o.x -i ans79.i -o ans79.p -w ../tpfh2o
rm -f edhtrk.r edhtrk.p edrst.p edstrip.p edstrip.st
../relap5o.x -i edhtrk.i -o edhtrk.p -r edhtrk.r -w ../tpfh2o
../relap5o.x -i edrst.i -o edrst.p -r edhtrk.r -w ../tpfh2o
../relap5o.x -i edstrip.i -o edstrip.p -r edhtrk.r -s edstrip.st
rm -f edhtrk.r edhtrkd.r edhtrkd.p ../relap5o.x -i edhtrkd.i -o edhtrkd.p -r edhtrkd.r -d ../tpfd2o
rm -f edhtrkd.r edhtrkn.r edhtrkn.p
../relap5o.x -i edhtrkn.i -o edhtrkn.p -r edhtrkn.r -w ../tpfh2o
rm -f edhtrkn.r marpzd4.r marpzd4.p
../relap5o.x -i marpzd4.i -o marpzd4.p -r marpzd4.r -d ../tpfd2o
rm -f marpzd4.r pump2.p
../relap5o.x -i pump2.i -o pump2.p -w ../tpfh2o
rm -f typpwr.r typpwr.p
../relap5o.x -i typpwr.i -o typpwr.p -r typpwr.r -w ../tpfh2o
rm -f typpwr.r typpwrn.r typpwrn.p typextr.p typextr.st
../relap5o.x -i typpwrn.i -o typpwrn.p -r typpwrn.r -w ../tpfh2o
../relap5o.x -i typextr.i -o typextr.p -r typpwrn.r -w ../tpfh2o -s typextr.st
rm -f typpwrn.r typ1200n.r typ1200n.p
../relap5o.x -i typ1200n.i -o typ1200n.p -r typ1200n.r -w ../tpfh2o
rm -f typ1200n.r typpwrr.r typpwrr.p compare.p
../relap5o.x -i typpwrr.i -o typpwrr.p -r typpwrr.r -w ../tpfh2o
../relap5o.x -i compare.i -o compare.p -w ../tpfh2o
rm -f typpwrr.r dumpfil1 dumpfil2 tbt.p tbt.r
../relap5o.x -i tbt.i -o tbt.p -r tbt.r -w ../tpfh2o
rm -f tbt.r cstest1.p cstest2.p cstest.r cstest1.p cstest2.p cstest.r
../relap5o.x -i cstest1.i -o cstest1.p -r cstest.r -w ../tpfh2o
../relap5o.x -i cstest2.i -o cstest2.p -r cstest.r -w ../tpfh2o
rm -f cstest.r radtst.p radtst.r
../relap5o.x -i radtst.i -o radtst.p -r radtst.r -w ../tpfh2o
rm -f radtst.r boiloff.p boiloff.r
../relap5o.x -i boiloff.i -o boiloff.p -r boiloff.r -w ../tpfh2o
rm -f boiloff.r scp2.r scp2.p scrst.p
../relap5o.x -i scp2.i -o scp2.p -r scp2.r -w ../tpfh2o
../relap5o.x -i scrst.i -o scrst.p -r scp2.r -w ../tpfh2o
rm -f scp2.r scvp2.p
../relap5o.x -i scvp2.i -o scvp2.p -w ../tpfh2o
