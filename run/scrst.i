*                    Configuration Control Problem
*       The scp2 problem runs to 1555 s, writes a restart tape, and
*  then continues to run until 1600.
*  This problem restarts that problem at 1555 s and runs to 1600 s.
*  Problem results at the end of this and the scp2 problem should
*  have identical simulation results.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
100 restart transnt
*  Following card specific to the scp2 benchmark problem
103 2098 cmpress scp2.r
201   1600.0    1.e-6   0.50  00007  10   700  700
.  end of data
