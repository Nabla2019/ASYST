rm -f edhtrkp.rr edhtrkp.pp edrstp.pp edplot.pp
../relap5d.x -i edhtrkp.i -o edhtrkp.pp -r edhtrkp.rr -w ../tpfh2o
../relap5d.x -i edrst.i -o edrstp.pp -r edhtrkp.rr -w ../tpfh2o
../relap5d.x -i edplot.i -o edplot.pp -r edhtrkp.rr -w ../tpfh2o
rm -f edhtrkp.rr
rm -f typpwrp.rr typpwrp.pp
../relap5d.x -i typpwrp.i -o typpwrp.pp -r typpwrp.rr -w ../tpfh2o
rm -f typpwrp.rr
rm -f ans79.pp
../relap5d.x -i ans79.i -o ans79.pp -w ../tpfh2o
rm -f edhtrk.rr edhtrk.pp edrst.pp edstrip.pp edstrip.stt
../relap5d.x -i edhtrk.i -o edhtrk.pp -r edhtrk.rr -w ../tpfh2o
../relap5d.x -i edrst.i -o edrst.pp -r edhtrk.rr -w ../tpfh2o
../relap5d.x -i edstrip.i -o edstrip.pp -r edhtrk.rr -s edstrip.stt
rm -f edhtrk.rr 
rm -f edhtrkd.rr edhtrkd.pp
../relap5d.x -i edhtrkd.i -o edhtrkd.pp -r edhtrkd.rr -d ../tpfd2o
rm -f edhtrkd.rr
rm -f  edhtrkn.rr edhtrkn.pp
../relap5d.x -i edhtrkn.i -o edhtrkn.pp -r edhtrkn.rr -w ../tpfh2o
rm -f edhtrkn.rr
rm  marpzd4.rr marpzd4.pp
../relap5d.x -i marpzd4.i -o marpzd4.pp -r marpzd4.rr -d ../tpfd2o
rm -f marpzd4.rr
rm -f pump2.pp
../relap5d.x -i pump2.i -o pump2.pp -w ../tpfh2o
rm -f typpwr.rr typpwr.pp
../relap5d.x -i typpwr.i -o typpwr.pp -r typpwr.rr -w ../tpfh2o
rm -f typpwr.rr typpwrn.rr
rm -f typpwrn.pp typextr.pp typextr.stt
../relap5d.x -i typpwrn.i -o typpwrn.pp -r typpwrn.rr -w ../tpfh2o
../relap5d.x -i typextr.i -o typextr.pp -r typpwrn.rr -w ../tpfh2o -s typextr.stt
rm -f typpwrn.rr
rm -f typ1200n.rr typ1200n.pp
../relap5d.x -i typ1200n.i -o typ1200n.pp -r typ1200n.rr -w ../tpfh2o
rm -f typ1200n.rr
rm -f typpwrr.rr typpwrr.pp compare.pp dumpfil1 duumpfil2
../relap5d.x -i typpwrr.i -o typpwrr.pp -r typpwrr.rr -w ../tpfh2o
../relap5d.x -i compare.i -o compare.pp -w ../tpfh2o
rm -f typpwrr.rr dumpfil1 dumpfil2
rm -f tbt.pp tbt.rr
../relap5d.x -i tbt.i -o tbt.pp -r tbt.rr -w ../tpfh2o
rm -f tbt.rr
rm -f tbt.rr
rm -f cstest1.pp cstest2.pp cstest.rr
../relap5d.x -i cstest1.i -o cstest1.pp -r cstest.rr -w ../tpfh2o
../relap5d.x -i cstest2.i -o cstest2.pp -r cstest.rr -w ../tpfh2o
rm -f cstest.rr radtst.pp radtst.rr
../relap5d.x -i radtst.i -o radtst.pp -r radtst.rr -w ../tpfh2o
rm -f radtst.rr boiloff.pp
rm -f boiloff.rr
../relap5d.x -i boiloff.i -o boiloff.pp -r boiloff.rr -w ../tpfh2o
rm -f boiloff.rr scp2.rr
rm -f scp2.pp scrst.pp
../relap5d.x -i scp2.ii -o scp2.pp -r scp2.rr -w ../tpfh2o
../relap5d.x -i scrst.ii -o scrst.pp -r scp2.rr -w ../tpfh2o
rm -f scp2.rr
rm -f scvp2.pp
../relap5d.x -i scvp2.i -o scvp2.pp -w ../tpfh2o
