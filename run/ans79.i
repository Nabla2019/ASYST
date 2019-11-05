= Long term decay heat study
*                    Configuration Control Problem
*  Input contains minimum hydrodynamics to allow testing of reactor
*  kinetics and decay heat calculation for long time periods.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
100 new transnt
104 none
301 rktpow
302 rkfipow
303 rkgapow
304 rkreac
*  time step control
201 10.0 1.0-7 0.1 7 1 10000 10000
202 100.0 1.0-7 1.0 7 1 10000 10000
203 1000.0 1.0-7 10.0 7 1 10000 10000
204 10000.0 1.0-7 100.0 7 1 10000 10000
205 100000.0 1.0-7 1000.0 7 1 10000 10000
206 1000000.0 1.0-7 10000.0 7 1 10000 10000
*
0030000 edwards pipe
0030001 2
0030101 4.56037-3,2
0030301 2.04801-1,2
0030601 0,2
0030801 1.177911-6,0,2
0031001 0,2
0031101 0,1
0031201 0,7.0+6,9.78293+5,2.58184+6,0,0,2
0031301 0,0,0,1
* reactivity table
20201100 reac-t
20201101 -1.0,0.0  0.0,0.0, 5.0,-20.0
* reactor kinetics input
30000000 point
30000001 gamma-ac  1.0+6  -1.0-20  200.0 1.0 1.0
30000002 ans79-3  200.0  0.81  0.13  0.06
30000011 11
30000401 1.0+6  200.0 wk  0.81  0.13  0.06
. end of case
