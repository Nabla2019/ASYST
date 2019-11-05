=  Simple three component system with heat structure
100  new  transnt
102  si  si
105  10.0 40.0 200.0
*
201  100.0  1.0e-6  0.01   3  10  500  20000
*
*20300011  mflowj 120000000 1
*20300012  mflowj 127000000 1
*20300021  httemp 125000501 1 httemp  125000401 1 httemp  125000301 1
*20300022  httemp 125000201 1 httemp  125000101 1
*20300031  cntrlvar 1 1
*20300041  cntrlvar 500 1 mflowj 120000000 1 cntrlvar 501 2
*
20500100 'intg.flo' integral 1.0 0.0 0
20500101 mflowj 127000000
*
1100000  "source"  tmdpvol
*        fa          l       vol azi   vert   dz     rough hydd flags
1100101  0.09290304  0.3048  0.0 0.0  -90.0  -0.3048 0.0   0.0  0000000
*Time dependent data to be pressure and temperature
1100200  003
*        time   press       temp
1100201  0.0    1034213.55  322.038889
*
1200000  'srvvlv'  valve
1200101  110010002  125010001  0.05571482  0.0    0.0    0000000
1200201  1       0.0            0.0             0.0
1200300  srvvlv
1200301  501
1200401  0.0,9000.0,9000.0  1.0,0.0,0.0
*
1250000  "stmpipe"  pipe
*     no. of vols
1250001  5
*        fa        vol no.
1250101  0.09290304  5
*        l    vol no.
1250301  1.524  5
*      az. ang vol no
1250501  0.0  5
*      vt. ang vol no
1250601  -90.0  5
*       rough hyd vol no.
1250801  0.0  0.0  5
*       f loss r loss jun. no.
1250901  0.0  0.0  4
*       vol flag  vol no
1251001  0000000  5
*       jun flag  jun. no
1251101  0000000  4
*      flag  pres     temp                vol. no.
1251201  3  689475.7  305.372222  0.0  0.0  0.0  5
*       flag
1251300  0
*     liq. vel vap. vel  int. vel  jun no.
1251301  0.0    0.0       0.0      4
*
1270000  "sngljuno"  sngljun
*        from vol   to vol     fa f. loss r. loss  flag
1270101  125050002  130010001  0.0  0.0  0.0 0000100
*      flag  liq mass flow  vap mass flow  inter. veloc.
1270201  1  0.0  0.0  0.0
*
1300000  "sink"  tmdpvol
*        fa          l       vol   azi   vert   dz    rough hyd d flags
1300101  0.09290304  0.3048  0.0    0.0  -90.0  -0.3048  0.0  0.0  0000000

*Time dependent data to be pressure and temperature
1300200  3
*        time   press     temp
1300201  0.0  344737.85  305.372222
*
*Pipe wall added by heat structure
11250000  5  5  2  0  0.17196499
11250100  0  1
11250101  4  0.19736499
11250201  5,4
11250301  0.0,4
11250401  283.15,5
11250501  125010000,010000  1  1  1.524  5
11250601          0,     0  0  1  1.524  5
11250701  0  0  0  0  5
11250801  0.0  10.0  10.0  0.0  0.0  0.0  0.0  1.0  5
*
*  stainless steel
20100500  tbl/fctn  1  1  *  stainless steel
*
*           temperature   thermal conductivity
20100501          273.15              12.98
20100502         1199.82              25.106
*
*           temperature   heat capacity
20100551          273.15          3830421.67
20100552          422.04          3964822.43
20100553          477.59          4099223.19
20100554          533.15          4233623.95
20100555          588.71          4334424.52
20100556          644.26          4435090.96
20100557          699.82          4502425.47
20100558          810.93          4636826.23
20100559         1366.48          5376030.42
*Units of steam controller must be in SI
20550000  flowset  constant  1500.0
20550100  flowctl  steamctl  1.0  0.5  0  3  0.0  1.0
20550101  cntrlvar,500  mflowj,120000000  1500.0  10.0  10.0
*
. End of input.
