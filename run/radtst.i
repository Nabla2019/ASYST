= Test Scdap Radiation
0000100  new  transnt
**105 10.0 11.0 500.0 1,3
0000110  hydrogen argon
0000115  0.0  1.0
*        tend   dtmin   dtmax  flag  edmin edmaj  nrest
0000201  100.0  1.0e-8 0.05  00015   20   500  5000
*
* oxide shattering Trip
000401 time 0 ge null 0 4870.0 l  
*  Minor edits.
301  cadct 060201
302  cadct 060202
303  cadct 050203
304  cadct 060205
305  cadct 010204
306  cadct 170204
307  cadct 010206
308  tempg 22010000
309  tempg 42010000
310  tempg 82010000
*  Plot input.
20300010 cadct 060201 1  cadct 060202 1  cadct 050203 1  cadct 060205 1
20300011 cadct 010204 1  cadct 170204 1  cadct 010206 1
20300012 tempg 22010000 1  tempg 42010000 1  tempg 82010000 1
*
*                   Control Variables
*                    Hydrogen production integral
20549900  hydrogen  integral  1.0  0.0  0  0
20549901  bgth 0
*
* test bundle volumes
0210000  test1  snglvol
0210101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
0210200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
0220000  test2  snglvol
0220101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
0220200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
0230000  test3  snglvol
0230101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
0230200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0240000  test4  snglvol
**0240101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
**0240200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0250000  test5  snglvol
**0250101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
**0250200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0260000  test6  snglvol
**0260101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
**0260200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0270000  test7  snglvol
**0270101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
**0270200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0280000  test8  snglvol
**0280101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
**0280200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0290000  test9  snglvol
**0290101  5.664e-3 1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
**0290200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0300000  test10  snglvol
**0300101  5.664-3 1.1e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.79e-2  00
**0300200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
** bypass annulus volumes for half interfacing with flow shroud
0410000  bypas1  snglvol
0410101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
0410200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
0420000  bypas2  snglvol
0420101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
0420200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
0430000  bypas3  snglvol
0430101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
0430200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0440000  bypas4  snglvol
**0440101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0440200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0450000  bypas5  snglvol
**0450101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0450200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0460000  bypas6  snglvol
**0460101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0460200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0470000  bypas7  snglvol
**0470101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0470200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0480000  bypas8  snglvol
**0480101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0480200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0490000  bypas9  snglvol
**0490101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0490200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0500000  bypas10  snglvol
**0500101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0500200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
** bypass annulus volumes for half interfacing with HTS
*  next volume up
0810000  bypa21  snglvol
0810101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
0810200  006  2.20e5  5.00e5  4.00e5  1.0  .9999
*
0820000  bypa22  snglvol
0820101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
0820200  006  2.20e5  5.00e5  4.00e5  1.0  .9999
*
0830000  bypa23  snglvol
0830101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
0830200  006  2.20e5  5.00e5  4.00e5  1.0  .9999
*
**0840000  bypa24  snglvol
**0840101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0840200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0850000  bypa25  snglvol
**0850101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0850200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0860000  bypa26  snglvol
**0860101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0860200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0870000  bypa27  snglvol
**0870101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0870200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0880000  bypa28  snglvol
**0880101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0880200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0890000  bypa29  snglvol
**0890101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0890200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**0900000  bypa210  snglvol
**0900101  1.59e-2  1.0e-1  0.0  0.0  90.0  1.0e-1 4.e-5 1.27e-1  00
**0900200  006  2.20e5  5.00e5  5.00e5  1.0  .9999
*
**** junctions ***
*** test bundle junctions
1210000  testj1  sngljun
1210101  021010000  022000000  0.0  0.0  0.0  01000
1210201  1   0.0  8.0e-3
*
1220000  testj2  sngljun
1220101  022010000  023000000  0.0  0.0  0.0  01000
1220201  1   0.0  8.0e-3
*
**1230000  testj3  sngljun
**1230101  023010000  024000000  0.0  0.0  0.0  01000
**1230201  1   0.0  8.0e-3
*
**1240000  testj4  sngljun
**1240101  024010000  025000000  0.0  0.0  0.0  01000
**1240201  1   0.0   8.0e-3
*
**1250000  testj5  sngljun
**1250101  025010000  026000000  0.0  0.0  0.0  01000
**1250201  1   0.0   8.0e-3
*
**1260000  testj6  sngljun
**1260101  026010000  027000000  0.0  0.0  0.0  01000
**1260201  1   0.0  8.0e-3
*
**1270000  testj7  sngljun
**1270101  027010000  028000000  0.0  0.0  0.0  01000
**1270201  1   0.0  8.0e-3
*
**1280000  testj8  sngljun
**1280101  028010000  029000000  0.0  0.0  0.0  01000
**1280201  1   0.0  8.0e-3
*
**1290000  testj9  sngljun
**1290101  029010000  030000000  0.0  0.0  0.0  01000
**1290201  1   0.0  8.0e-3
*
** bypass annulus junctions for half interfacing with flow shroud
1410000  bypsj1  sngljun
1410101  041010000  042000000  0.0  0.0  0.0  01000
1410201  1   0.0   0.0
*
1420000  bypsj2  sngljun
1420101  042010000  043000000  0.0  0.0  0.0  01000
1420201  1   0.0   0.0
*
**1430000  bypsj3  sngljun
**1430101  043010000  044000000  0.0  0.0  0.0  01000
**1430201  1   0.0   0.0
*
**1440000  bypsj4  sngljun
**1440101  044010000  045000000  0.0  0.0  0.0  01000
**1440201  1   0.0   0.0
*
**1450000  bypsj5  sngljun
**1450101  045010000  046000000  0.0  0.0  0.0  01000
**1450201  1   0.0   0.0
*
**1460000  bypsj6  sngljun
**1460101  046010000  047000000  0.0  0.0  0.0  01000
**1460201  1   0.0   0.0
*
**1470000  bypsj7  sngljun
**1470101  047010000  048000000  0.0  0.0  0.0  01000
**1470201  1   0.0   0.0
*
**1480000  bypsj8  sngljun
**1480101  048010000  049000000  0.0  0.0  0.0  01000
**1480201  1   0.0   0.0
*
**1490000  bypsj9  sngljun
**1490101  049010000  050000000  0.0  0.0  0.0  01000
**1490201  1   0.0   0.0
*
** bypass annulus junctions
1810000  byp2j1  sngljun
1810101  081010000  082000000  0.0  0.0  0.0  01000
1810201  1   0.0   0.0
*
1820000  byp2j2  sngljun
1820101  082010000  083000000  0.0  0.0  0.0  01000
1820201  1   0.0   0.0
*
**1830000  byp2j3  sngljun
**1830101  083010000  084000000  0.0  0.0  0.0  01000
**1830201  1   0.0   0.0
*
**1840000  byp2j4  sngljun
**1840101  084010000  085000000  0.0  0.0  0.0  01000
**1840201  1   0.0   0.0
*
**1850000  byp2j5  sngljun
**1850101  085010000  086000000  0.0  0.0  0.0  01000
**1850201  1   0.0   0.0
*
**1860000  byp2j6  sngljun
**1860101  086010000  087000000  0.0  0.0  0.0  01000
**1860201  1   0.0   0.0
*
**1870000  byp2j7  sngljun
**1870101  087010000  088000000  0.0  0.0  0.0  01000
**1870201  1   0.0   0.0
*
**1880000  byp2j8  sngljun
**1880101  088010000  089000000  0.0  0.0  0.0  01000
**1880201  1   0.0   0.0
*
**1890000  byp2j9  sngljun
**1890101  089010000  090000000  0.0  0.0  0.0  01000
**1890201  1   0.0   0.0
*  General table
20210000  power
20210001  0.0 0.0
* end of relap input
* * * * * * * * * * * * * * * * * * * * * * *
*  Component 1 - fuel rod
*  Component 2 - simulator rod
*  Component 3 - control rod
*  Component 4 - shroud
*  Component 5 - hot simulater rod
*  Component 6 - High Temperature Shield
* * * * * * * * * * * * * * * * * * * * * * *
40002000 021010000 023010000 1.4e-5             
*        axnodes 2dflag cora  pbf power  oxide shater
40000100   3      1      5     3            
*       axnode height  axnode number
40000201  0.1             3
*         zro2 fail  oxthk  dsoxid  pratmx     
*         Tfox    oxth e2ox  pratmx Tdropf pratmn Amn transm fmdiff nsmdif
40000300  2500.0  0.60 0.14  0   
40000310  0.2    0.0      0.5
*         gamma heat fraction
40000400  0.026
*  cladding deformation and ballooning
40000500  0.18  0.15  0.248 0
*
40000600  table 100
*  core bypass volumes
40001101  041010000  042010000  043010000
*  core bypass elevations
40001201  0.1 0.2 0.3
* user specified material 9 steam gas mixture
40009091 520. 520. 520. 520. 520. 520. 520. 520. 520. 520.
40009092 1.624 0.886 0.609 0.464 0.375 0.437 0.401 0.385 0.229 0.192
40009093 .0177 .0267 .0373 .0454 .0501 .0547 .0620 .0677 .0709 .0783
* user specified material property(10)-low density zro2 with argon
40009101 506. 506. 506. 506. 506. 506. 506. 506. 506. 506.
40009102 480. 480. 480. 480. 480. 480. 480. 480. 480. 480.
40009103 .095 .115 .120 .135 .168 .182 .195 .280 .375 .458
* user specified material property(4)-stainless steel (HTS)
40009111 100. 100. 100. 100. 100. 100. 100. 100. 100. 100.
40009112 980. 980. 980. 980. 980. 980. 980. 980. 980. 980.
40009113 7.69 13.43 16.87 20.85 25.67 27.73 29.45 29.24 20.00 20.00
* * * * * * * * * * * *
*component 1--fuel rod*
* * * * * * * * * * * *
40010000  comp1      fuel
*      no.rods  pitch  burnup
40010100   7   0.0143  0.0
* fuel rod plenum length and void volume
40010200  0.066   2.425e-5
*pellet radius, ic radius, oc radius, axial node
40010301  4.600e-3  4.655e-3  5.375e-3  3
*  upper/lower hydraulic volumes
40010400  023010000  021010000
*  core hydraulic volumes
40010401  021010000  1000000  3
*radial mesh spacing
40010501  0.0 .003 .003883  .0046 .004655 .005375 10
40010601  1000.  1000.  1000.  1000.  1000.  1000.  3
*  power data
40011100  1.0e-4
*  end time of axial profile number 1
40011310  5000.
*axial power profile
40011311  1. 1. 1.
*radial power profile
40011401  1.000  1
40011402  1.000  2
40011403  1.000  3
40011404  0.000  4
*  shutdown time, fuel density
40011500  5000.  0.95
*  decay power
*40011501  6.25e-9      0.0   0.0     1.
*40011502  6.25e-9      0.0   0.0   8000.
*  prior power history
*40011601  0.953e+8  15900.            *prior power history
*40011602  1.90e+8   277826.
*40011603  4.48e+7   295836.
*40011604  10.       3.1e+5
*  helium inventory, internal gas pressure
40013000  1.391e-5  0.416e+6
40014000  limit on   
* * * * * * * * * * * * * * * *
*component 2--simulator rod
* * * * * * * * * * * * * * * *
40020000  comp2      cora
*        no.rods  pitch  wire radius
40020100  12     0.0143  0.003
*  rod plenum length and void volume
40020200  0.010   7.45e-5
*pellet radius, ic radius, oc radius, axial node
40020301  4.600e-3  4.655e-3  5.375e-3  3
*  upper/lower hydraulic volumes
40020400  023010000  021010000
*  core hydraulic volumes
40020401  021010000  1000000  3
*radial mesh spacing
40020501  0.0 .003 .0043  .0046 .004655 .005375 3
40020601  700.  700.  700.  700.  700.  700.  3
*  power data
*40021000  table   100
40021100  0.75
*  end time
40021310  5000.
*  axial power profile
40021311  1. 1. 1.
*radial power profile
40021401  1.000  1
40021402  1.000  2
40021403  0.000  3
40021404  0.000  4
*  shutdown time, fuel density
40021500  5000.  0.95
*  helium inventory, internal gas pressure
40023000  1.24e-05  2.20e+05
40024000  limit on   
* * * * * * * * * * * * * * * * * * * * * *
*component 3--control rod*
* * * * * * * * * * * * * * * * * * * * * *
40030000  comp3      control
*  number of rods, pitch
40030100  2  0.0143
*or absorber,or ss sheath,ir zr tube,or zr tube
40030301  4.43e-3  5.1e-3  6.1e-3 6.9e-3  3
*  upper/lower hydraulic volumes
40030400  023010000  021010000
*  core hydraulic volumes
40030401  021010000  1000000  3
*radial mesh spacing
40030501  0. 4.430e-3 5.100e-3 6.100e-3 6.90e-3 3
40030601  650.  650.  650.  650.  650.    3
*  internal gas pressure
40030700  0.0
*  mass of Ag
40030800  0.0 0.0
*  power data
*40031000  table 100
40031100  0.0
*  end time
40031310  5000.
*axial power profile
40031311  1. 1. 1.
*radial power profile
40031401  1.000  1
40031402  1.000  5
* power history
40031601 0.     1.
40031602 0.  8000.
* * * * * * * * * * * * * * * * * * * *
*component 4--shroud                  *
* * * * * * * * * * * * * * * * * * * *
40040000  comp4    shroud
*  number of shrouds
40040100  1
*inner shroud surface perimeter,flow area thickness
*40040200  0.324   6.9e-3  1  0.0   
40040200   0.324  6.9e-3                  
*  material index
40040300  10  1  1
*  material layer radii
40040301  0.0180  0.0181  0.0192      *material layer radii
*  upper/lower hydraulic volumes
40040400  023010000  021010000
*  core hydraulic volumes
40040401  021010000  041010000  1000000  3
*radial mesh spacing
40040501  0. 0.003 0.006 0.008 0.010 0.0115 0.0130 0.014 0.015
+         0.01575 0.0165 0.017 0.0175 0.01775 0.018 0.0181
+         0.0192  3
40040601  400.0    400.0    400.0    400.0    400.0   
+         400.0    400.0    400.0    400.0    400.0   400.0 
+         400.0    400.0    400.0    400.0    400.0   400.0  3

* power data
40041100  1.0e-4
40041310  1.
40041311  1. 1. 1.
40041401  1. 17
40041601  0.    0.
40041602  0. 1000.
40044000  limit on    
*  shroud material, fail time, multiplier
40045000  10  4870.0  2.5       
* * * * * * * * * * * * * * * *
*component 5--simulator heater rod
* * * * * * * * * * * * * * * *
40050000  heater      cora
*        no.rods  pitch  wire radius
40050100  4     0.0143  0.003
*  rod plenum length and void volume
40050200  0.010   7.45e-5
*pellet radius, ic radius, oc radius, axial node
40050301  4.600e-3  4.655e-3  5.375e-3  3
*  upper/lower hydraulic volumes
40050400  023010000  021010000
*  core hydraulic volumes
40050401  021010000  1000000  3
*radial mesh spacing
40050501  0.0 .003 .0043  .0046 .004655 .005375 3
40050601  500.  500.  500.  500.  500.  500.  3
*  power data
40051100  0.25
*  end time
40051310  5000.
*  axial power profile
40051311  1. 1. 1.
*radial power profile
40051401  1.000  1
40051402  1.000  2
40051403  0.000  3
40051404  0.000  4
*  shutdown time, fuel density
40051500  5000.  0.95
*  helium inventory, internal gas pressure
40053000  1.24e-05  2.20e+05
40054000 limit on  
40060000  comp6    shroud
*  number of shrouds
40060100  1
*inner shroud surface perimeter,flow area thickness
40060200   0.961   6.52e-2   
*  material index
*                       ZrO2
*40060300  18, 16, 9, 18, 5, 1
40060300  18, 16, 9, 18, 10, 1
*  material layer radii
40060301  0.0020 0.0770 0.0920 0.1020 0.1395 0.1400          
*  upper/lower hydraulic volumes
40060400  023010000  021010000
*  core hydraulic volumes
*     Note; adiabatic boundary at radial node 1 of HTS.
40060401  081010000  0          1000000  3
*radial mesh spacing
40060501  0.0  0.0020  0.0140  0.0260 0.0380 0.0477 0.0575       
+         0.0672  0.0770  0.0845 0.0920  0.1020  0.1115  0.1210 
+         0.1305  0.1395  0.1400  3
40060601  300.0, 300.0, 300.0, 300.0, 300.0, 300.0, 300.0, 300.0,
+         300.0, 300.0, 300.0, 300.0, 300.0, 300.0, 300.0, 300.0,
+         300.0   3
* power data
*40061000  table 100
40061100  1.0e-4
40061310  1.
40061311  1. 1. 1.
*40061401  1. 15
40061401  1. 17
40061601  0.    0.
40061602  0. 1000.
40064000  limit on
*40064000  limit off
*  shroud material, fail time, multiplier
*  Note. code only stores one value for tfshrd, so make this
*        value for insulated shroud; coding uses tfshrd for
*        lowest component number.
40065000  10  4870.0  2.5    
*   heat flux history at outer surface of HTS.
40068101    0.0      0.0
40068201   6000.0    0.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* radiation enclosure grouping                               *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
49010000  bundle
49012000  .0143   4    * component pitch and shroud no.
*view factors
49012001  0  0  0  2  0  0  0
49012002  0  0  2  1  2  0  0
49012003  0  2  1  5  1  2  0
49012004  2  3  5  1  5  1  2
49012005  0  2  1  5  3  2  0
49012006  0  0  2  1  2  0  0
49012007  0  0  0  2  0  0  0
*   radiation between inner flow shroud and HTS.
49020000  bundle
49021000  4       6    * component #s of flow shroud and HTS.
*   view factors
49021001  0.0000         1.0000
49021002  0.337149       0.662851
*   radiation path lengths
49021101  0.1   0.1
49021102  0.1   0.1
. end of input
