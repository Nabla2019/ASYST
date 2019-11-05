*  problem does an input check only with extensive optional printout.
*                    Configuration Control Problem
*       The edhtrk problem runs to 0.5 s and writes a restart tape.
*  This problem restarts that problem at 0.2 s and runs to 0.5 s.
*  Problem results at the end of this and the edhtrk problem should
*  have identical simulation results.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
100 restart transnt
103 115

203 0.500,1.0-7 .001 7 10 50 100
.  end of data
