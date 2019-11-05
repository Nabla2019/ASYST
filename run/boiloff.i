= Vessel boiloff problem, RELAP5 vs. SCDAP 
*
*   Benchmark problem to verify the SCDAP interface and time step repetition
*   logic.  Developed by C.A. Dobbe.
*
*   Parallel core channels modeled with one using a SCDAP component to
*   simulate the fuel and the other using a RELAP5 heat structure, both
*   with the same dimensions and axial power shape and both driven with
*   the kinetics package.
*
*   Success is achieved if control variable 110 matches variable 111.
*   These variables track heat to the hydrodynamic volumes, and should
*   differ only slightly due to marginal differences in thermal properties
*   and interpolation.
*   All comparison is invalid once oxidation begins to take effect, because
*   RELAP5 heat structures can't handle that.
*
100  new        transnt
101  run
102  si         si
105  3.         5.
* non-condensible control
110  hydrogen  helium  nitrogen xenon
115    1.0      0.0     0.0      0.0
* time step control
200  0.0     
201  0.1       1.e-6   0.02  00047   25  200  500
202  1.0       1.e-6   0.05  00047   10  200  1000
205  300.0     1.e-6   0.10  00047   5   500  500  
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
* Hydrodynamic system.  Boundary conditions are basically an 8 volume
* pipe with a time-dependent volume and a time-dependent junction at
* bottom and a time dependent volume and single junction at the top.
* The time-dependent volumes specify hydrodynamic conditions and the
* time-dependent junction provides mass-flow
100000  sourvol    tmdpvol
100101  0.32828  1.0  0.0      0.0  90.0  1.0  0.0  0.0  11
100200  02
100201  0.0  6.9e6  0.0        
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$
500000  sourjun    tmdpjun
500101  010000000  100000000  0.0
500200  1
*    mass flow history
500201  0.0      1.0    0.0     0.0
500202  50.0     1.0    0.0     0.0
500203  50.5     0.1    0.0     0.0
500204  100.     0.1    0.0     0.0
500205  100.5    0.0    0.0     0.0
500206  9000.    0.0    0.0     0.0
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$
1000000  testbun    pipe
1000001  8
1000101  3.6850e-3  8  *  flow area
1000201  0.0        7  *  jfa
1000301  0.1143     8  *  vol length
1000401  0.0        8  *  volume
1000501  0.0        8  *  h angle
1000601  90.0       8  *  v angle
1000701  0.1143     8  *  dz
1000801  1.e-6      1.2457e-2    8  *  rough, hd
1000901  0.0   0.0  7  *  kloss
1001001  00         8
1001101  0          7
1001201  02   6.9e6  0.0    0.0   0.0   0.0       1 * initial conditions
1001202  02   6.9e6  0.0    0.0   0.0   0.0       2
1001203  02   6.9e6  0.0    0.0   0.0   0.0       8
1001300  1
1001301   0.0    1.0   0.0   7 * initial mass flow rate
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
1500000  sinkjun    sngljun
1500101  100010000  200000000  1.6464e-3  0.0  0.0  00
1500201  1     1.0   0.0      0.0
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$
2000000  sinkvol    tmdpvol
2000101  0.32828   1.0  0.32828  0.0  90.0  1.0  0.0  0.0  11
2000200  02
2000201  0.0   6.89e6   1.0          
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
2100000  sourvol    tmdpvol
2100101  0.32828  1.0  0.0      0.0  90.0  1.0  0.0  0.0  11
2100200  02
2100201  0.0  6.9e6  0.0        
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$
2500000  sourjun    tmdpjun
2500101  210000000  300000000  0.0
2500200  1
*    mass flow history
2500201  0.0      1.0    0.0     0.0
2500202  50.0     1.0    0.0     0.0
2500203  50.5     0.1    0.0     0.0
2500204  100.     0.1    0.0     0.0
2500205  100.5    0.0    0.0     0.0
2500206  9000.    0.0    0.0     0.0
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$
3000000  testbun    pipe
3000001  8
3000101  3.6850e-3  8  *  flow area
3000201  0.0        7  *  jfa
3000301  0.1143     8  *  vol length
3000401  0.0        8  *  volume
3000501  0.0        8  *  h angle
3000601  90.0       8  *  v angle
3000701  0.1143     8  *  dz
3000801  1.e-6      1.2457e-2    8  *  rough, hd
3000901  0.0   0.0  7  *  kloss
3001001  00         8
3001101  0          7
3001201  02   6.9e6  0.0    0.0   0.0   0.0       1 * initial conditions
3001202  02   6.9e6  0.0    0.0   0.0   0.0       2
3001203  02   6.9e6  0.0    0.0   0.0   0.0       8
3001300  1
3001301   0.0    1.0   0.0   7 * initial mass flow rate
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
3500000  sinkjun    sngljun
3500101  300010000  400000000  1.6464e-3  0.0  0.0  00
3500201  1     1.0   0.0      0.0
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$
4000000  sinkvol    tmdpvol
4000101  0.32828   1.0  0.32828  0.0  90.0  1.0  0.0  0.0  11
4000200  02
4000201  0.0   6.89e6   1.0          
*************************************************************************
*   kinetics input - taken from Surry input with power set to 58.5e3 w  *
*************************************************************************
*
30000000  point separabl
30000001  gamma-ac 58.5e3  0.0 244.0 1.0 0.7
30000002  ans79-3 200. .49 .07 .44
*
* previous power history data
30000401  58.5e3   104.  wk  .49 .07 .44
*
**********************************************************************
*
*                relap5 heat structures
*
**********************************************************************
*        heat structure 3001      fuel rods
13001000     8    17    2     1     0.0        0
13001100          0           1
13001101          6           4.135e-3
13001102          2           4.215e-3
13001103          8           4.815e-3
13001201          5           6
13001202          6           8
13001203          4           16
13001301          1.0         6
13001302          0.0         16
13001401          575.0       17
13001501    0           0       0    1   3.6608     8 
13001601    300010000   10000   1    1   3.6608     8 
13001701    1000  0.07426  0.0   0.0    1
13001702    1000  0.11758  0.0   0.0    2
13001703    1000  0.14851  0.0   0.0    3
13001704    1000  0.16584  0.0   0.0    4
13001705    1000  0.16584  0.0   0.0    5
13001706    1000  0.14851  0.0   0.0    6
13001707    1000  0.11386  0.0   0.0    7
13001708    1000  0.06560  0.0   0.0    8
13001901    0.0   10.0   10.0   0.0   0.0   0.0   0.0   1.0   8
*
**********************************************************************
*
*                       material properties
*
*  conductivity values in units of Watts/m-K      
*  volumetric heat capacity values in units of J/m3-K       
*
**********************************************************************
*  thermal properties of cladding - composition 4
**********************************************************************
20100400 tbl/fctn         2         1          * cladding
20100401  295.0  2800.0  1.67  3.62e-4  0.0  0.0  0.0  0.0  0.0
*20100401            4.731500e2     1.200458e1 
*20100402            6.731500e2     1.400524e1
*20100403            8.731500e2     1.700779e1 
*20100404            1.073150e3     1.900845e1 
*20100405            1.273150e3     2.200975e1 
*20100406            1.473150e3     2.501105e1 
*20100407            1.673150e3     3.001239e1 
*20100408            1.873150e3     3.601500e1 
*20100409            2.073150e3     4.401764e1 
*20100410            2.273150e3     5.502345e1 
*20100411            2.473150e3     6.802618e1 
*20100451            2.950000e2     2.711e6
*20100452            1.077761e3     3.931e6
*20100453            1.185928e3     5.712422e6
*20100454            1.248428e3     2.305062e6
*20100455            2.199817e3     2.312171e6
*20100455            2.199817e3     2.711e6
* vol. heat cap. vs temp.
20100451  295.0  2.711e6
20100452  550.0  3.736e6
20100453  1481.0  4.297e6
20100454  1500.0  3.630e6
20100455  1991.0  3.630e6
20100456  2950.0  4.920e6
20100457  4000.0  3.600e6
**********************************************************************
*  thermal properties of uo2 - composition 5
**********************************************************************
20100500 tbl/fctn         1         1          * uo2
20100501            3.601500e2     8.000148e0
20100502            4.401500e2     7.000129e0 
20100503            5.001500e2     6.200115e0
20100504            5.331500e2     5.782412e0 
20100505            6.164833e2     4.622765e0 
20100506            6.998167e2     4.633170e0 
20100507            7.831500e2     4.221262e0 
20100508            8.664833e2     3.880321e0 
20100509            9.498167e2     3.596453e0 
20100510            1.033150e3     3.357632e0 
20100511            1.088706e3     3.155136e0 
20100512            1.199817e3     2.983793e0 
20100513            1.283150e3     2.836688e0 
20100514            1.366483e3     2.713820e0 
20100515            1.449817e3     2.608210e0 
20100516            1.533150e3     2.521667e0 
20100517            1.616483e3     2.449017e0 
20100518            1.699817e3     2.391882e0 
20100519            1.977594e3     2.289762e0 
20100520            2.255372e3     2.307083e0 
20100521            2.533150e3     2.433441e0 
20100522            2.810928e3     2.661856e0 
20100523            3.088706e3     2.994199e0 
20100551            2.731500e2     2.310427e6
20100552            3.231500e2     2.571985e6
20100553            3.731500e2     2.746357e6
20100554            4.731500e2     2.920729e6
20100555            6.731500e2     3.138694e6
20100556            1.373150e3     3.443844e6
20100557            1.773150e3     3.531030e6
20100558            1.973150e3     3.792588e6
20100559            2.173150e3     4.228518e6
20100560            2.373150e3     4.882412e6
20100561            2.673150e3     6.015829e6
20100562            2.773150e3     6.320980e6
20100563            2.873150e3     6.582538e6
20100564            2.973150e3     6.713317e6
20100565            3.113150e3     6.800503e6
20100566            4.699817e3     6.800503e6
**********************************************************************
*  thermal properties of fuel gap(average core) - composition 6
**********************************************************************
20100600 tbl/fctn         1         1          * fuel gap
20100601             1.246129
20100651             5.029958
*
**********************************************************************
*  core heat transfer  (relap=300, scdap=100)
**********************************************************************
20511000    corerq    sum    1.0    0.0       1    0
20511001    0.0    1.0  q  300010000      1.0  q  300020000
20511002           1.0  q  300030000      1.0  q  300040000
20511003           1.0  q  300050000      1.0  q  300060000
20511004           1.0  q  300070000      1.0  q  300080000
**********************************************************************
20511100    coresq    sum    1.0    0.0       1    0
20511101    0.0    1.0  q  100010000      1.0  q  100020000
20511102           1.0  q  100030000      1.0  q  100040000
20511103           1.0  q  100050000      1.0  q  100060000
20511104           1.0  q  100070000      1.0  q  100080000
**********************************************************************
* SCDAP INPUT
40000100  8  1  1  3
40000201  0.11430 8
40000400  0.026
40000500  0.02  0.02  0.02  0
40000600  kinetics
40001000  0.05000, 0.40000, 0.62800
40001001  1 0.002 0.037 0.005 0.001 3
40001101 100010000 100020000 100030000 100040000
40001102 100050000,  100060000,  100070000,  100080000
40001201 0.1143  .2286  .3429  .4572  .5715  .6858
40001202  .8001  .9144
40002000 100010000  100080000  0.0
* component 1
40010000 fuelrod  fuel
40010100 32 0.01280 3.e5
40010200 0.0752,   0.5403e-5
40010301 4.135e-3 4.215e-3 4.815e-3 8
40010400 100010000  100080000
40010401 100010000 10000 8
40010501 3 1 1 8
40010601 605.1   601.9   592.4   576.5   563.7  561.1  1
40010602 605.1   601.9   592.4   576.5   563.7  561.1  2
40010603 605.1   601.9   592.4   576.5   563.7  561.1  3
40010604 605.1   601.9   592.4   576.5   563.7  561.1  4
40010605 605.1   601.9   592.4   576.5   563.7  561.1  5
40010606 605.1   601.9   592.4   576.5   563.7  561.1  6
40010607 605.1   601.9   592.4   576.5   563.7  561.1  7
40010608 605.1   601.9   592.4   576.5   563.7  561.1  8
*          fission 
40011100   1.00   
*
* 40011310  360.
* 40011311  1.00 1.00 1.00 1.00  1.00 1.00 1.00 1.00
40011310  3000.
* 40011311  0.60 0.95 1.20 1.34  1.34 1.20 0.92 0.53
* renormalized axial power shape
40011311 0.5941 0.9406 1.1881 1.3267 1.3267 1.1881 0.9109 0.5248
40011401  .95481 1
40011402  .95481 2
40011403  1.0157 3
40011404  1.0157 4
40011500  1200. 0.95
40011601  0.953e+08 15900.
40011602  1.90e+08  277836.
40011603  4.48e+07  295836.
40011604  0.        3.1e5
40013000  3.00e-05 3.8e+06
* radiation heat transfer input
49010000  bundle
49012000  0.0128 0
49012001  0, 1, 1, 1, 1, 0
49012002  1, 1, 1, 1, 1, 1
49012003  1, 1, 1, 1, 1, 1
49012004  1, 1, 1, 1, 1, 1
49012005  1, 1, 1, 1, 1, 1
49012006  0, 1, 1, 1, 1, 0
.   *  end of data *
