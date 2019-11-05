= simple cheap 2 channel vessel problem with debris formation
*  couple model is used
*  creep rupture calcs are done for both the vessel wall and
*    relap5 heat structures
*  Two core channels added to test radial spreading of molten pool
$=======================================================================
*misc    problem type   problem option
100        new            transnt
*misc    inp-chk/run option
101            run
*misc  in units   out units
102      si         si
*misc no restart/plot file written
104      none
*misc cpu limit 1    cpu limit 2   cpu allocated
105      3.              5.        *infinite
*misc gas types and mass fractions
110  hydrogen  helium  krypton  xenon
115    0.0       1.0     0.0      0.0
$=======================================================================
*                           time step control
*       time    min     max  ssdtt  minor   major   restart
201    150.0  1.e-7    0.10  00039    10     500      500
$=======================================================================
*                       variable trip input
*    v code   parameter  rel  v code parameter  constant  l timeof
590   time    0          ge    null  0            0.0     l  0.0
505   time    0          ge    null  0           -1.      n
506   time    0          lt    null  0           69.9     n
507   time    0          ge    null  0          466.      n
508   time    0          lt    null  0          849.0     n
510   time    0          ge    null  0           70.0     n
511   time    0          le    null  0          465.      n
512   time    0          ge    null  0          850.0     n
599   p       060010000  gt    null  0          2.0e7     n
$=======================================================================
*                       logical trip input
*     trip   operator  trip  l timeof         comments
604   507     and       508  n
606   604     or        605  n
608   510     and       511  n
605   505     and       506  n
609   608     or        512  n
$    Trip stop card.
600  599
$=======================================================================
*                       hydrodynamic components
$=======================================================================
*hydro         component name     component type
100000          sourvol             tmdpvol
$-----------------------------------------------------------------------
*hydro         area      length      volume
100101       20.0         5.0        0.0
*
*hydro       horz angle  vert angle   delta z
100102        0.0        90.0          5.0
*
*hydro        roughness   hyd diam    pvbfe
100103         0.0        0.0        00000
*
*hydro   ebt
100200  003
*
*hydro  time      pressure    temp
100201  0.0       7.000e6    311.00
$=======================================================================
*hydro         component name     component type
500000          sourjun            tmdpjun
$-----------------------------------------------------------------------
*hydro      from       to          area
500101   010000000   060000000    0.01 * 5xarea of tmi hpi
*
*hydro   vel/flw    trip    alpha var   num var
500200     0       590      cntrlvar     136
*
*hydro    time    f vel   g vel    i vel
500201  -1.e99    0.0     0.0      0.0
500202   0.0      0.0     0.0      0.0
500203   1000.    1000.   1000.    0.0
$=======================================================================
*hydro         component name     component type
600000           vesbot            snglvol
$-----------------------------------------------------------------------
*hydro   area   length   volume
600101  4.229    1.5     0.0
*
*hydro   horz angle   vert angle   delta Z
600102     0.0         90.0         1.5
*
*hydro   roughness   hyd diam   pvbfe
600103    3.8e-7     3.54677      00
*
*hydro   ebt   pressure   quality
600200  002     7.0e+6     0.02
$=======================================================================
*hydro         component name     component type
800000          vbtocor            branch
$-----------------------------------------------------------------------
*hydro   no. juns   vel/flw
800001     4          0
*hydro   area   length   volume
800101  4.565  0.672      0.0
*
*hydro   horz angle   vert angle   delta Z
800102     0.0         90.0        0.672
*
*hydro   roughness   hyd diam   pvbfe
800103    3.8e-7    3.54677       00
*
*hydro   ebt   pressure   quality
800200  002    7.0e6      1.0
*
*hydro   from          to     area   f loss   r loss   fvcahs
801101  060010000  080000000  0.0     5.       5.     00100
802101  080010000  100000000  2.1145    30.      30.    00100
803101  080010000  101000000  2.1145  30.0     30.0   00100
804101  080010000  105000000  0.336   21.0     21.0   00100
*
*hydro   f vel   g vel   i vel
801201   0.0     0.0     0.0
802201   0.0     0.0     0.0
803201   0.0     0.0     0.0
804201   0.0     0.0     0.0
$=======================================================================
*hydro         component name     component type
1000000           core1              pipe
$-----------------------------------------------------------------------
*hydro   no. vol
1000001     6
*
*hydro   vol area      vol
1000101  2.1145         6
*
*hydro   jun area      jun
1000201   0.0           5
*
*hydro   length        vol
1000301  0.6095833      6
*
*hydro   volume        vol
1000401    0.0          6
*
*hydro   horz angle    vol
1000501     0.0         6
*
*hydro   vert angle    vol
1000601    90.0         6
*
*hydro   delta Z       vol
1000701  0.6095833      6
*
*hydro   roughness   hyd diam   vol
1000801   1.e-6      1.33e-2     6
*
*hydro   f loss   r loss   jun
1000901  5.e-2    5.e-2     5
*
*hydro   pvbfe      vol
1001001     00       6
*
*hydro   fvcahs     jun
1001101  00100       5
*
*hydro   ebt   pressure   quality                   vol
1001201  002    7.e6        1.0   0.0  0.0  0.0      1
1001203  002    7.0e6       1.0   0.0  0.0  0.0      6
*
*hydro   vel/flw
1001300     1
*
*hydro   f flw   g flw   i flw   jun
1001301   0.0     0.0     0.0     5
$=======================================================================
*hydro         component name     component type
1010000           core2              pipe
$-----------------------------------------------------------------------
*hydro   no. vol
1010001     6
*
*hydro   vol area      vol
1010101  2.1145         6
*
*hydro   jun area      jun
1010201   0.0           5
*
*hydro   length        vol
1010301  0.6095833      6
*
*hydro   volume        vol
1010401    0.0          6
*
*hydro   horz angle    vol
1010501     0.0         6
*
*hydro   vert angle    vol
1010601    90.0         6
*
*hydro   delta Z       vol
1010701  0.6095833      6
*
*hydro   roughness   hyd diam   vol
1010801   1.e-6      1.33e-2     6
*
*hydro   f loss   r loss   jun
1010901  5.e-2    5.e-2     5
*
*hydro   pvbfe      vol
1011001     00       6
*
*hydro   fvcahs     jun
1011101  00100       5
*
*hydro   ebt   pressure   quality                   vol
1011201  002    7.e6        1.0   0.0  0.0  0.0      1
1011203  002    7.0e6       1.0   0.0  0.0  0.0      6
*
*hydro   vel/flw
1011300     1
*
*hydro   f flw   g flw   i flw   jun
1011301   0.0     0.0     0.0     5
$=======================================================================
*hydro         component name     component type
1050000           bypass              pipe
$-----------------------------------------------------------------------
*hydro   no. vol
1050001     6
*
*hydro   vol area       vol
1050101    0.336         6   * flow area, 8%  of core flow area
*
*hydro   jun area       jun
1050201    0.0           5
*
*hydro   length         vol
1050301  0.6095833       6
*
*hydro   volume         vol
1050401    0.0           6
*
*hydro   horz angle     vol
1050501    0.0           6
*
*hydro   vert angle     vol
1050601     90.0         6
*
*hydro   delta Z        vol
1050701  0.6095833       6
*
*hydro   roughness   hyd diam   vol
1050801    1.e-6       1.e-2     6
*
*hydro   f loss   r loss   jun
1050901   0.0      0.0      5
*
*hydro   pvbfe          vol
1051001     00           6
*
*hydro   fvcahs         jun
1051101  00100           5
*
*hydro   ebt   pressure   quality                vol
1051201  002     7.e+6      1.0    0.0  0.0  0.0  6
*
*hydro   vel/flw
1051300     1
*
*hydro   f flw   g flw   i flw   jun
1051301   0.0     0.0     0.0     5
$=======================================================================
*hydro        component name     component type
1190000          zip1               mtpljun
$-----------------------------------------------------------------------
*hydro   no. juns.    vel/flw
1190001    6             0
*
*hydro         from          to      area    f loss   r loss     vcahs
1190011     100010004    101010003   3.5650  32.04    32.04      00003
*
*hydro     sub coeff    2phs coeff    super coeff
1190012     1.0          1.0            1.0
*
*hydro       from incr    to incr   ???   jun limit
1190013     000010000    000010000  0       6
*
*hydro       f velocity   g velocity    jun limit
1191011        0.0          0.0          6
$=======================================================================
*hydro        component name     component type
1200000          zip2               mtpljun
$-----------------------------------------------------------------------
*hydro   no. juns.    vel/flw
1200001    6             0
*
*hydro         from          to      area    f loss   r loss     vcahs
1200011     101010004     105010003  7.13    18.0     18.0       00003
*
*hydro     sub coeff    2phs coeff    super coeff
1200012     1.0          1.0            1.0
*
*hydro       from incr    to incr   ???   jun limit
1200013     000010000    000010000  0       6
*
*hydro       f velocity   g velocity    jun limit
1201011        0.0          0.0          6
$=======================================================================
*hydro        component name     component type
1100000           vesplen           branch
$-----------------------------------------------------------------------
*hydro   no. juns   vel/flw
1100001     4          0
*
*hydro   area   length   volume
1100101  11.0731  6.      0.0
*
*hydro   horz angle   vert angle   delta Z
1100102     0.0         90.0         6.0
*
*hydro   roughness   hyd diam   pvbfe
1100103    3.8e-7      3.5         00
*
*hydro   ebt   pressure   quality
1100200  002    7.0e+6      1.0
*
*hydro     from        to     area   f loss   r loss   fvcahs
1101101  100010000  110000000  0.0     0.0     0.0     00100
1102101  101010000  110000000  0.0     0.0     0.0     00100
1103101  105010000  110000000  0.0     0.0     0.0     00100
1104101  110010000  125000000  0.0     0.0     0.0     00100
*
*hydro   f vel   g vel   i vel
1101201   0.0     0.0     0.0
1102201   0.0     0.0     0.0
1103201   0.0     0.0     0.0
1104201   0.0     0.0     0.0
$=======================================================================
*hydro        component name     component type
1250000         vsoutlet           snglvol
$-----------------------------------------------------------------------
*hydro   area   length   volume
1250101  1.e-2   100.0    0.0
*
*hydro   horz angle   vert angle   delta Z
1250102     90.0         0.0         0.0
*
*hydro   roughness   hyd diam   pvbfe
1250103    0.0         0.0         11
*
*hydro   ebt   pressure   quality
1250200  002     7.0e6      1.0     0.0   0.0   0.0
$=======================================================================
*hydro        component name     component type
1500000          sinkjun             valve
$-----------------------------------------------------------------------
*hydro     from       to      area   f loss   r loss   fvcahs
1500101  125010000  200000000 1.e-2    10.     10.     00100
*
*hydro   vel/flw   f flw   g flw   i flw
1500201     1       0.0     0.0     0.0
*
*hydro   valve type
1500300    mtrvlv
*
*hydro   open   close   rate   init pos
1500301   606   609      0.1       1.
$=======================================================================
*hydro        component name     component type
2000000          sinkvol           tmdpvol
$-----------------------------------------------------------------------
*hydro   area   length   volume
2000101   200.0   50.0     0.0
*
*hydro   horz angle   vert angle   delta Z
2000102     0.0          90.0       50.0
*
*hydro   roughness   hyd diam   pvbfe
2000103     0.0        0.0         00
*
*hydoro   ebt
2000200   002
*
*hydro   time   pressure   quality
2000201   0.0   0.2e6        0.0
$=======================================================================
*
*                        heat structure input
*
$=======================================================================
*htstr    nhst  nodes  geo  ss init  l coord
11001000   1     4      2      1      2.215
*
*htstr    location   format
11001100    0          1
*
*htstr    intervals   r coord
11001101     3         2.3515
*
*htstr    comp   interval
11001201    1       3
*
*htstr    source   interval
11001301   0.0        3
*
*htstr    temp    mesh pt
11001401  558.94     4
*
*htstr      vol     incr  type  code  factor  ht no
11001501  100010000  0     1     1      3.6     1
11001601          0  0     0     1      3.6     1
*
*htstr     source  mult  l heat  r heat  ht no
11001701     0     0.0    0.0     0.0      1
*
*htstr h diam  f len  r len  grid f  grid r  f loss  r loss  boil  ht no
11001801    0    10.    10.       0       0       0       0    1.      1
$=======================================================================
*htstr    nhst  nodes  geo  ss init  l coord
11102000   1      4     3      1      2.215
*
*htstr    location   format
11102100     0         1
*
*htstr    intervals   r coord
11102101    3          2.3515
*
*htstr    comp   interval
11102201    1        3
*
*htstr    source   interval
11102301   0.0        3
*
*htstr    temp    mesh pt
11102401  558.94     4
*
*htstr      vol     incr  type  code  factor  ht no
11102501  110010000  0      1     1    0.5      1
11102601          0  0      0     1    0.5      1
*
*htstr     source  mult  l heat  r heat  ht no
11102701      0    0.0    0.0     0.0      1
*
*htstr h diam  f len  r len  grid f  grid r  f loss  r loss  boil  ht no
11102801    0    10.    10.       0       0       0       0    1.      1
$=======================================================================
*htstr    nhst  nodes  geo  ss init  l coord
11253000   1     4      2      1     0.0564
*
*htstr    location   format
11253100    0          1
*
*htstr    intervals   r coord
11253101    3         0.0589
*
*htstr    comp   interval
11253201    1       3
*
*htstr    source   interval
11253301   0.0        3
*
*htstr    temp    mesh pt
11253401  558.94     4
*
*htstr      vol     incr  type  code  factor  ht no
11253501  125010000  0     1     1     100.0    1
11253601          0  0     0     1     100.0    1
*
*htstr     source  mult  l heat  r heat  ht no
11253701     0      0.0    0.0     0.0     1
*
*htstr h diam  f len  r len  grid f  grid r  f loss  r loss  boil  ht no
11253801    0    10.    10.       0       0       0       0    1.      1
$=======================================================================
*
*                   heat structure thermal properties
*
$=======================================================================
*htstr    material type
20100100     c-steel
20100200     s-steel
$=======================================================================
*
*                   general table data
*
$=======================================================================
*    table specifying mass flow rate of hpi as function of time
$=======================================================================
*table     type  trip
20271100  reac-t  590
*table     time          flow
*table     (s)          (kg/s)
20271101  -1.e99          0.0
20271102  75.             0.0
20271103 162.5           16.15
20271104 162.5            0.0
20271105   1.0e6          0.0
$======================================================================
*     table specifying power decay
$=======================================================================
20290000  power     590       1.0      934.+6
20290001     0.0    1.
20290002  3000.     1.
$=======================================================================
*
*                  control system input
*
$=======================================================================
*    control variable for specifying hpi to vessel
$=======================================================================
*cntrl      name     type   factor   init   flag
20513600  "ahpi vel"  div    100.     0.0    1
*
*cntrl    alpha v1  num v1    alpha v2  num v2
20513601    rho    010010000  cntrlvar    134
$=======================================================================
*cntrl      name      type   factor   init   flag
20513400  "a hpi tb" function  1.0     0.0     1
*
*cntrl    alpha v1  num v1  table
20513401   time       0      711
$=======================================================================
* the following control variables compute mass, enthalpy, and energy
* flows through the relief valves to the containment for contain input
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20540100    mflow    sum     1.0      0.0    0    0
*
*cntrl    cnst Ao  cnst A1  alpha v1  num v1
20540101    0.0      1.0     mflowj  150000000
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20540200    liqfrac  sum    1.0      0.0     0    0
*
*cntrl    cnst Ao  cnst A1  alpha v1  num v1
20540201    1.0     -1.0     quals   110010000
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20540300    stmfrac  sum    1.0      0.0     0    0
*
*cntrl    cnst Ao  cnst A1  alpha v1  num v1
20540301    1.0     -1.0     quala   110010000
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20540400    liqflow  mult    1.0      0.0    0    0
*
*cntrl      alpha v1  num v1   alpha v2  num v2
20540401    cntrlvar  401      cntrlvar   402
$=======================================================================
*cntrl      name     type      factor   init   flag lim
20540500    liqflowi  integral   1.0    0.0      0   0
*
*cntrl      alpha v1  num v1
20540501    cntrlvar   404
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20540600    stmflow  mult   1.0      0.0     0    0
*
*cntrl      alpha v1  num v1   alpha v2  num v2   alpha v3  num v3
20540601    cntrlvar   401     quals    110010000 cntrlvar   403
$=======================================================================
*cntrl      name     type        factor   init   flag lim
20540700    stmflowi   integral   1.0      0.0     0   0
*
*cntrl      alpha v1  num v1
20540701    cntrlvar   406
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20540800    ncflow   mult   1.0       0.0    0    0
*
*cntrl      alpha v1  num v1   alpha v2  num v2   alpha v3  num v3
20540801    cntrlvar   401      quals   110010000 quala    110010000
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20540900    ncflowi   integral   1.0   0.0   0   0
*
*cntrl      alpha v1  num v1
20540901    cntrlvar   408
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20541100    liqwork  div    1.0       0.0    0    0
*
*cntrl      alpha v1  num v1    alpha v2  num v2
20541101    rhof     110010000    p      110010000
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20541200    liqenth  sum    1.0       0.0    0    0
*
*cntrl    cnst Ao  cnst A1  alpha v1  num v1   cnst a2  alpha v2  num v2
20541201    0.0      1.0      uf     110010000    1.0   cntrlvar    411
$=======================================================================
*cntrl      name     type      factor   init   flag lim
20541300    liqenthi  integral   1.0     0.0     0   0
*
*cntrl      alpha v1  num v1
20541301    cntrlvar   412
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20541400    vapwork  div     1.0      0.0    0    0
*
*cntrl      alpha v1  num v1    alpha v2  num v2
20541401    rhog     110010000    p      110010000
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20541500    vapenth  sum      1.0    0.0     0    0
*
*cntrl    cnst Ao  cnst A1  alpha v1  num v1   cnst a2  alpha v2  num v2
20541501    0.0     1.0       ug     110010000  1.0     cntrlvar    414
$=======================================================================
*cntrl      name     type      factor   init   flag lim
20541600    vapenthi integral   1.0      0.0    0   0
*
*cntrl      alpha v1  num v1
20541601    cntrlvar   415
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20542100    liqener  mult     1.0      0.0    0    0
*
*cntrl      alpha v1  num v1   alpha v2  num v2
20542101    cntrlvar   404     cntrlvar   412
$=======================================================================
*cntrl      name     type      factor   init   flag lim
20542200    liqeneri integral   1.0      0.0    0   0
*
*cntrl      alpha v1  num v1
20542201    cntrlvar   421
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20542300    vapener  mult   1.0       0.0    0    0
*
*cntrl      alpha v1  num v1   alpha v2  num v2
20542301    cntrlvar   406     cntrlvar    415
$=======================================================================
*cntrl      name     type      factor   init   flag lim
20542400    vapeneri integral   1.0      0.0     0   0
*
*cntrl      alpha v1  num v1
20542401    cntrlvar   423
$=======================================================================
*cntrl      name     type   factor   init   flag lim
20542500    ncener   mult   1.0       0.0    0    0
*
*cntrl      alpha v1  num v1   alpha v2  num v2
20542501    cntrlvar   408    cntrlvar    415
$=======================================================================
*cntrl      name     type      factor   init   flag lim
20542600    nceneri integral   1.0       0.0     0   0
*
*cntrl      alpha v1  num v1
20542601    cntrlvar    425
$=======================================================================
*  fission product transport input
*20700000  3
*20700001  100010000
*20700011  csi  csoh  te  sn
***     couple wall creep rupture input
*          imat  ncnvol  pext
21000000    1       0   100000.0
21000001     6
21000002    15  20
21000003    27  28  35
21000004     9
20800001  dcrepc 1
20800002  dcrepc 2
20800003  dcrepc 3
20800004  dcrepc 4
***     heat structures creep rupture input
*          heat str.  mat   l. pr.   r. pr.
21000101    1001001    1     0.0    100000.0
21000102    1102001    1     0.0    100000.0
21000103    1253001    2     0.0    100000.0
20800005  dcreph 5
20800006  dcreph 6
20800007  dcreph 7
$=======================================================================
*      axial nodes    heat.conduction   environment   power.history.type
40000100    6                 1               1                 2
*         node heights
40000201  0.6096   6
*         source of power data
40000600  table 900
*         grid spacer height
40001000   0.30
*         grid matl  mass       height   plate        radius/contact
40001001     0       0.002      0.037     0.005       0.001            1
*         core bypass volumes
40001101  105010000 105020000 105030000 105040000 105050000 105060000
*         core bypass elevations
40001201  0.6096  1.2192  1.8288  2.4384  3.0480  3.6576
*misc      ncvol     nvoltp
40002000  060010000 110010000
$=======================================================================
*         name      type
40010000  rod1      fuel
*         number  pitch    burnup
40010100  18408  0.014427  2.808e+5
*  plenum length    volume
40010200  0.2318    1.490e-5
* radius of pellet,  clad id,  clad od
40010301  0.004699  0.004788  0.005461  6
*         upper      lower       hydrodynamic volumes
40010400  60010000  110010000
*         volume    increment  node
40010401  100010000  10000  6
*         radial mesh spacing
40010501  0.0 0.001566  0.003133  0.004699  0.004788  0.005461 6
*         initial temperatures                   node
40010601  900.0  900.0  900.0  900.0  900.0  900.0 6
*         power multipler for this component
40011100  .5
*         axial profile end time
40011310  12000.0
*         axial profile #1
40011311  0.4 1.116 1.214 1.232 0.600 0.589
*         radial profile
40011401  1. 4
*         shutdown time and density
40011500  8. 0.95
*         previous power history
40011601  4.3e+8    7.7e+5
*         gap inventory
40012200  kr
40012201  0.5356
*         he inventory and pressure
40013000  1.2650e-4 5.8140e+6
*  ----------------------------------------------------------
40020000  contrl1  control
*         number   pitch
40020100  118     0.014427
*         absorber sheath   guide i.r. guide o.r.
40020301  0.005055 0.005588 0.006325 0.006731 6
*         upper and lower volumes
40020400  60010000  110010000
*         volume    increment node
40020401  100010000  10000  6
*          radial mesh spacing
40020501  0.0, 0.005055  0.005588  0.006325 0.006731 6
*         initial temperatures
40020601  900.0  900.0  900.0  900.0  900.0  6
*         gas pressure
40020700  0.
*         mass of tin, silver
40020800  0.0  155.3
*-----------------------------------------------------------------------
*         name      type
40030000  rod2      fuel
*         number  pitch    burnup
40030100  18408  0.014427  2.808e+5
*  plenum length    volume
40030200  0.2318    1.490e-5
* radius of pellet,  clad id,  clad od
40030301  0.004699  0.004788  0.005461  6
*         upper      lower       hydrodynamic volumes
40030400  60010000  110010000
*         volume    increment  node
40030401  101010000  10000  6
*         radial mesh spacing
40030501  0.0 0.001566  0.003133  0.004699  0.004788  0.005461 6
*         initial temperatures                   node
40030601  900.0  900.0  900.0  900.0  900.0  900.0 6
40031100   0.5
*         axial profile end time
40031310  12000.0
*         axial profile #1
40031311  0.38 1.060 1.153 1.170 0.570 0.557
*         radial profile
40031401  1. 4
*         shutdown time and density
40031500  8. 0.95
*         previous power history
40031601  4.3e+8    7.7e+5
*         gap inventory
40032200  kr
40032201  0.5356
*         he inventory and pressure
40033000  1.2650e-4 5.8140e+6
*  ----------------------------------------------------------
40040000  contrl1  control
*         number   pitch
40040100  118     0.014427
*         absorber sheath   guide i.r. guide o.r.
40040301  0.005055 0.005588 0.006325 0.006731 6
*         upper and lower volumes
40040400  60010000  110010000
*         volume    increment node
40040401  101010000  10000  6
*          radial mesh spacing
40040501  0.0, 0.005055  0.005588  0.006325 0.006731 6
*         initial temperatures
40040601  900.0  900.0  900.0  900.0  900.0  6
*         gas pressure
40040700  0.
*         mass of tin, silver
40040800  0.0  155.3
* --------------------------------------------------------------------
49050000  bundle
*         component numbers in this enclosure
49051000  1   2
*         view factors input
49051001  0.9062  0.0938
49051002  0.9311  0.0689
*         path lengths input
49051101  0.01202 0.01189
49051102  0.01189 0.01070
* --------------------------------------------------------------------
49060000  bundle
*         component numbers in this enclosure
49061000  3   4
*         view factors input
49061001  0.9062  0.0938
49061002  0.9311  0.0689
*         path lengths input
49061101  0.01202 0.01189
49061102  0.01189 0.01070
50000000  couple  new
*misc   icin    ncvol   nslphs   nobrok   ntsc   dtcoup
51010000   1   060010000    0        1      1       1.
51014000   13   17    6    0   0.02540
51020001 4  1  1     0.0     0.0  2  1 23.7660  3.1053  0 0 0.0 92.5750
51020002 4  2  1 23.7660  3.1053  3  1 33.3370  6.2110  0 0 0.0 92.5750
51020003 4  3  1 33.3370  6.2110  4  1 40.4730  9.3159  0 0 0.0 92.5750
51020005 4  4  1 40.4730  9.3159  5  1 46.3190 12.4210  0 0 0.0 92.5750
51020007 4  5  1 46.3190 12.4210  6  1 51.5570 15.6860  0 0 0.0 92.5750
51020009 4  6  1 51.5570 15.6860  7  1 56.1200 18.9500  0 0 0.0 92.5750
51020011 4  7  1 56.1200 18.9500  8  1 60.1630 22.2159  0 0 0.0 92.5750
51020013 4  8  1 60.1630 22.2150  9  1 63.7830 25.4790  0 0 0.0 92.5750
51020015 4  9  1 63.7830 25.4790 10  1 68.9380 30.7880  0 0 0.0 92.5750
51020017 4 10  1 68.9380 30.7880 11  1 73.3500 36.0960  0 0 0.0 92.5750
51020019 4 11  1 73.3500 36.0960 12  1 77.1470 41.4040  0 0 0.0 92.5750
51020021 4 12  1 77.1470 41.4040 13  1 81.8770 49.3750  0 0 0.0 92.5750
51020023 1  2  1 23.7760  3.1053  2  3 22.4820  7.7373
51020025 1  3  1 33.3370  6.2110  3  3 31.5360 10.8750
51020027 1  4  1 40.4730  9.3159  4  3 38.2870 13.8130
51020029 1  5  1 46.3190 12.4210  5  3 43.8170 16.7500
51020031 1  6  1 51.5570 15.6860  6  3 48.7720 19.8390
51020033 1  7  1 56.1200 18.9500  7  3 53.0890 22.9270
51020035 1  8  1 60.1630 22.2153  8  3 56.9140 26.0160
51020037 1  9  1 63.7830 25.4790  9  3 60.3380 29.1030
51020039 1 10  1 68.9380 30.7880 10  3 65.2150 34.1250
51020041 1 11  1 73.3500 36.0960 11  3 69.3880 39.1460
51020043 1 12  1 77.1470 41.4040 12  3 72.9800 44.1680
51020045 1  2  3 22.4820  7.7373  2  5 22.3960  8.3000
51020047 1  3  3 31.5360 10.8750  3  5 31.4010 11.2250
51020049 1  4  3 38.2870 13.8130  4  5 38.1230 14.1500
51020051 1  5  3 43.8170 16.7500  5  5 43.6300 17.0750
51020053 1  6  3 48.7720 19.8390  6  5 48.5640 20.1500
51020055 1  7  3 53.0890 22.9270  7  5 52.8620 23.2250
51020057 1  8  3 56.9140 26.0160  8  5 56.6700 26.3000
51020059 1  9  3 60.3380 29.1030  9  5 60.0800 29.3750
51020061 1 10  3 65.2150 34.1250 10  5 64.9350 34.3750
51020063 1 11  3 69.3880 39.1460 11  5 69.0910 39.3750
51020065 1 12  3 72.9800 44.1680 12  5 72.6680 44.3750
51020067 4  1  4     0.0  5.3750  2  4 22.3960  8.3000  0 0 0.0 92.5750
51020069 4  2  4 22.3960  8.3000  3  4 31.4010 11.2250  0 0 0.0 92.5750
51020071 4  3  4 31.4010 11.2250  4  4 38.1230 14.1500  0 0 0.0 92.5750
51020073 4  4  4 38.1230 14.1500  5  4 43.6300 17.0750  0 0 0.0 92.5750
51020075 4  5  4 43.6300 17.0750  6  4 48.5640 20.1500  0 0 0.0 92.5750
51020077 4  6  4 48.5640 20.1500  7  4 52.8620 23.2250  0 0 0.0 92.5750
51020079 4  7  4 52.8620 23.2250  8  4 56.6700 26.3000  0 0 0.0 92.5750
51020081 4  8  4 56.6700 26.3000  9  4 60.0800 29.3750  0 0 0.0 92.5750
51020083 4  9  4 60.0800 29.3750 10  4 64.9350 34.3750  0 0 0.0 92.5750
51020085 4 10  4 64.9350 34.3750 11  4 69.0910 39.3750  0 0 0.0 92.5750
51020087 4 11  4 69.0910 39.3750 12  4 72.6680 44.3750  0 0 0.0 92.5750
51020089 4 12  4 72.6680 44.3750 13  4 75.7470 49.3750  0 0 0.0 92.5750
51020091 4  1  5     0.0  5.3750  2  5 22.3960  8.3000  0 0 0.0 92.5750
51020093 4  2  5 22.3960  8.3000  3  5 31.4010 11.2250  0 0 0.0 92.5750
51020095 4  3  5 31.4010 11.2250  4  5 38.1230 14.1500  0 0 0.0 92.5750
51020097 4  4  5 38.1230 14.1500  5  5 43.6300 17.0750  0 0 0.0 92.5750
51020099 4  5  5 43.6300 17.0750  6  5 48.5640 20.1500  0 0 0.0 92.5750
51020103 4  6  5 48.5640 20.1500  7  5 52.8620 23.2250  0 0 0.0 92.5750
51020105 4  7  5 52.8620 23.2250  8  5 56.6700 26.3000  0 0 0.0 92.5750
51020107 4  8  5 56.6700 26.3000  9  5 60.0800 29.3750  0 0 0.0 92.5750
51020109 4  9  5 60.0800 29.3750 10  5 64.9350 34.3750  0 0 0.0 92.5750
51020113 4 10  5 64.9350 34.3750 11  5 69.0910 39.3750  0 0 0.0 92.5750
51020115 4 11  5 69.0910 39.3750 12  5 72.6680 44.3750  0 0 0.0 92.5750
51020117 4 12  5 72.6680 44.3750 13  5 75.7470 49.3750  0 0 0.0 92.5750
51020119 1  1  1     0.0     0.0  1  2     0.0     2.5
51020121 1  1  2     0.0     2.5  1  3     0.0     5.0
51020123 1  1  3     0.0     5.0  1  4     0.0  5.3750
51020125 1  1  4     0.0  5.3750  1  5     0.0  5.3750
51020127 1  1  5     0.0  5.3750  1  6     0.0  8.3000
51020129 1  1  6     0.0  8.3000  1  7     0.0 11.2250
51020131 1  1  7     0.0 11.2250  1  8     0.0 14.1500
51020133 1  1  8     0.0 14.1500  1  9     0.0 17.0750
51020135 1  1  9     0.0 17.075   1 10     0.0 20.1500
51020137 1  1 10     0.0 20.1500  1 11     0.0 23.2250
51020139 1  1 11     0.0 23.2250  1 12     0.0 26.3000
51020141 1  1 12     0.0 26.3000  1 13     0.0 29.3750
51020143 1  1 13     0.0 29.3750  1 14     0.0 34.3750
51020145 1  1 14     0.0 34.3750  1 15     0.0 39.3750
51020147 1  1 15     0.0 39.3750  1 16     0.0 44.3750
51020149 1  1 16     0.0 44.3750  1 17     0.0 49.3750
51020151 1  1  6     0.0  8.3000  2  6 11.1980  8.3000
51020153 1  2  6 11.1980  8.3000  2  5 22.3960  8.3000
51020155 1  1  7     0.0 11.2250  3  7 15.7010 11.2250
51020157 1  3  7 15.7010 11.2250  3  5 31.4010 11.2250
51020159 1  1  8     0.0 14.1500  4  8 19.0620 14.1500
51020161 1  4  8 19.0620 14.1500  4  5 38.1230 14.1500
51020163 1  1  9     0.0 17.0750  5  9 21.8150 17.0750
51020165 1  5  9 21.8150 17.0750  5  5 43.6300 17.0750
51020167 1  1 10     0.0 20.1500  6 10 24.2820 20.1500
51020169 1  6 10 24.2820 20.1500  6  5 48.5640 20.1500
51020171 1  1 11     0.0 23.2250  7 11 26.4310 23.2250
51020173 1  7 11 26.4310 23.2250  7  5 52.8620 23.2250
51020175 1  1 12     0.0 26.3000  8 12 28.3350 26.3000
51020177 1  8 12 28.3350 26.3000  8  5 56.6700 26.3000
51020179 1  1 13     0.0 29.3750  9 13 30.0400 29.3750
51020181 1  9 13 30.0400 29.3750  9  5 60.0800 29.3750
51020183 1  1 14     0.0 34.3750 10 14 32.4680 34.3750
51020185 1 10 14 32.4680 34.3750 10  5 64.9350 34.3750
51020187 1  1 15     0.0 39.3750 11 15 34.5460 39.3750
51020189 1 11 15 34.5460 39.3750 11  5 69.0910 39.3750
51020193 1  1 16     0.0 44.3750 12 16 36.3340 44.3750
51020195 1 12 16 36.3340 44.3750 12  5 72.6680 44.3750
51020197 1  1 17     0.0 49.3750 13 17 37.8740 49.3750
51020199 1 13 17 37.8740 49.3750 13  5 75.7470 49.3750
51020201 1 13  1 81.7700 49.3750 13  2 79.0400 49.3750
51020203 1 13  2 79.0400 49.3750 13  3 76.1780 49.3750
51020205 1 13  3 76.1780 49.3750 13  4 75.7470 49.3750
51020207 1 13  4 75.7470 49.3750 13  5 75.7470 49.3750
51040001    4    1   13    1    3       0.0    0    0
51040002    2    1   13    3    4       0.0    0    0
51040003    6    1   13    4    5       0.0    0    0
51040004    1    1   13    5   17       1.0    0    0
51040005    1    1    9    5   13       1.0    0    0
51040006    1    1    5    5    9       1.0    0    0
51050000   0.8
51050001  1     10180.0   5.0    5.0    500.0
51050001  2      7000.0  20.0   20.0    400.0
51050001  3      6440.0  20.0   20.0    400.0
51050001  4      6440.0  20.0   20.0    400.0
51050001  5    209601.    0.01   0.01     0.0673
51050001  6         0.0   0.0    0.0      0.0
51060000  0.5    1.0    87.2
51060001  583.3
51070000  0.0    5.375    1   10
51080000  5
51110000  182
51110001    1   17  13   17   0.0  060010000
51110003    1   16  13   16   0.0  060010000
51110004    1   15  13   15   0.0  060010000
51110005    1   14  13   14   0.0  060010000
51110006    1   13  13   13   0.0  060010000
51110007    1   12  13   12   0.0  060010000
51110008    1   11  13   11   0.0  060010000
51110009    1   10  13   10   0.0  060010000
51110010    1    9  13    9   0.0  060010000
51110011    1    8  13    8   0.0  060010000
51110012    1    7  13    7   0.0  060010000
51110013    1    6  13    6   0.0  060010000
51110014    1    4  13    4   1.0e04
51110015    1    5  13    5   1.0e04
. end of relap5, scdap, and couple data.
