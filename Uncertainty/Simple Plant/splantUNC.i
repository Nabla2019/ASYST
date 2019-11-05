========================================================================
* merge steady-state and transient input decks for uncertainty analysis
* search for *splant
*=======================================================================
*
*  sample problem: two simple loops with a steam generator,
*         nuclear core, pump and pressurizer.
*  The problem to be run is in two parts.
*      part 1...achieve steady state
*      part 2...renodalize and run a transient
*    The system is composed of a primary loop and a secondary loop.
*    primary loop:
*        system piping,
*        core vessel containing the nuclear core
*        pressurizer (steam bubble modeled as a time dep vol for s.s.)
*            with a surge line
*        steam generator (counter flow, single pass)
*        a westinghouse pump
*    secondary loop:
*        steam generator tube sheet (boiler section)
*        separator
*        steam dome
*        steam dome outlet time dependent volume
*        downcommer annulus with a feedwater inlet
*    The basic dimensions and parameters describing each volume and
*        junction element are noted in the comment preceding each
*        component description.
*    initial conditions
*        primary system
*            p              = 1.5e+7 pa
*            avg temp       = 550 k
*            flow           = 131 kg/sec
*            core power     = 50 mw
*        secondary system
*            p              = 2.0e+6 pa
*            feedwater flow = 26.1 kg/sec
*            feedwater temp = 478 k
*======================================================================
* title card
*======================================================================
=relap5 simplified pwr sample problem, steady state
*======================================================================
* problem type and option
*======================================================================
*crdno     problem type     option
*splant 100                 new     stdy-st
100                 new     transnt
*======================================================================
* cpu time remaining card
*======================================================================
*crdno   time1   time2   cpu-time
*105        5.0     6.0   500.0  
*======================================================================
* time step control cards
*======================================================================
*crdno end time  min dt   max dt  control  minor ed  major ed  restart
*splant 000201    1000.  1.0-6     0.1     3        100       100    1000
*splant 000201    1000.  1.0-6     0.1      3        100       100    1000
*splant 000202    2000.  1.0-6     0.2     11         10       500    5000
000201    1000.  1.0-6     0.1      3       1000      1000    5000
000202    2000.  1.0-6     0.1     11         10       500    5000
*======================================================================
* minor edit requests
*======================================================================
*crdno    v-code     parameter
301       p          130040000
302       p          120010000
303       p          230010000
311       tempf      100010000
312       tempf      120010000
321       mflowj     120030000
322       mflowj     151000000
323       mflowj     251000000
324       mflowj     231000000
325       velfj      260020000
331       voidg      260010000
332       voidg      230010000
333       voidgj     260010000
334       voidfj     260020000
335       voidg      220010000
341       cntrlvar   10
342       cntrlvar   11
343       cntrlvar   12
351       cntrlvar   20
352       cntrlvar   21
361       emass       0
362       cntrlvar  264
*======================================================================
* plot requests
20300011       p          130040000 1
20300012       p          120010000 1
20300013       p          230010000 2
*20300231       httemp     110000810 1
*======================================================================
*                          trips
*======================================================================
* no  left variable   rel   rt variable + const   function
501   time        0    gt   null   0     1000.00  l * for pump + logical
502   p   290010000    gt   null   0      2.40+6  n * s.g. relief vlv
*                                     high pressure set point (c-232)
503   p   290010000    gt   null   0      1.80+6  n * s.g. relief vlv
*                                      low pressure set point (c-232)
*splant 506   time        0    gt   null   0      1000.0  l * for power
* logical trips
*     notes
*         if a logical trip tests a higher number logical trip then
*             the higher number trip refers to the previous time step
*         if a logical trip tests a lower number logical trip then
*             the lower number trip refers to the present time step
*         all trips are initialized to false for new problems
* no  left trp   rel   rt trp   function
601       -501   and     -501   n 0.0 * for s.g. steam ctl vlv (c-231)
602       -604   and      502   n * logic for  relief vlv opening
603        604   and      503   n * logic for  relief vlv closeing
604        602    or      603   n * s.g. relief vlv stays open
605        501   and      604   n * s.g. relief vlv opens if true
*splant: logic for transient, to be combined with steady-state
*splant  through 1bor 0 trips
504   p   132020000    gt   null   0      1.80+7  n * pressurizer
*                    relief vlv...high pressure set point (c-133)
505   p   132020000    gt   null   0      1.35+7  n * pressurizer
*                    relief vlv....low pressure set point (c-133)
506   time        0    gt   timeof 608    5.0     l * time for pzr
*splant: trip added for power.
616   501  and  506 n -1.0
*                                                     relief vlv
* logical trips
*     notes
*         if a logical trip tests a higher number logical trip then
*             the higher number trip refers to the previous time step
*         if a logical trip tests a lower number logical trip then
*             the lower number trip refers to the present time step
*         all trips are initialized to false for new problems
* no  left trp   rel   rt trp   function
606       -608   and      504   n * logic for relief vlv opening
607        608   and      505   n * logic for relief vlv closeing
608        606    or      607   n * pzr relief vlv stays open
*splant: trip added for pzr valve logic
618        608    and     501   n 0.0
619        618     or    -501   n 0.0
*splant
*======================================================================
*                      component data
*======================================================================
*                      component 100
* cold leg, pump to core inlet (pipe: 0.25m dia, 2.0m long)
*crdno        name         type
1000000     pump-out     snglvol
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
1000101  0.05      2.0      0     0    0.0     0.0      0.0    0.0     0
*crdno   ctl     pressure     temp
1000200    3        1.5+7    550.0
*----------------------------------------------------------------------
*                      component 101
* vessel inlet (abrupt: 0.25m pipe to 0.51m vessel)
*crdno        name         type
1010000 vesselin sngljun
*crdno    from          to            area     floss     rloss     flag
1010101   100010000     105000000        0         0         0      100
*crdno    ctl     flowf    flowg    velj
1010201     1     131.0     0.0        0
*----------------------------------------------------------------------
*                      component 105
* lower plenum (pipe: 0.51m dia, 2.0m long)
*crdno        name         type
1050000     low-plen     snglvol
*crdno   area   length volume h-ang  v-ang  delz  rough dhy  ctl
1050101  0.17   2.0    0      0      90.0   2.0   0.0   0.0  0
*crdno   ctl     pressure     temp
1050200    3        1.5+7    550.0
*----------------------------------------------------------------------
*                      component 106
* core inlet (0.51m vessel)
*crdno        name         type
1060000 corein sngljun
*crdno    from          to            area     floss     rloss     flag
1060101   105010000     110000000        0         0         0      000
*crdno    ctl     flowf    flowg    velj
1060201     1     131.0     0.0        0
*----------------------------------------------------------------------
*                      component 110
* core (vessel: 0.51m dia, 3.0m long)
*      (rods: 350 rods, 0.0107m dia)
*crdno        name         type
1100000       core         pipe
*crdno     no.vols.
1100001          12
*crdno     area                             vol.no.
1100101    0.17                                  12
*crdno     length                           vol.no.
1100301       0.25                                12
*crdno     v-ang                            vol.no.
1100601     90.0                                 12
*crdno     rough     dhy                    vol.no.
1100801        0    0.051                        12
*crdno     ctl                              vol.no.
1101001      0                                   12
*crdno     ctl                              jun.no.
1101101      0                                   11
*crdno     ctl       pressure     temp      vol.no.
1101201      3          1.5+7    550.0  0 0 0    12
*crdno     i.c.
1101300      1
*crdno     flowf     flowg        velj      jun.no.
1101301    131.0      0.0            0           11
*----------------------------------------------------------------------
*                      component 114
* core outlet (0.51m vessel)
*crdno        name         type
1140000 corout sngljun
*crdno    from          to            area     floss     rloss     flag
1140101   110010000     115000000        0         0         0      000
*crdno    ctl     flowf    flowg    velj
1140201     1     131.0     0.0        0
*----------------------------------------------------------------------
*                      component 115
* upper plenum (pipe: 0.51m dia, 1.0m long)
*crdno        name         type
1150000     low-plen     snglvol
*crdno   area   length volume h-ang  v-ang  delz rough  dhy   ctl
1150101  0.17   1.0    0      0      90.0   1.0  0.0    0.0   0
*crdno   ctl     pressure     temp
1150200    3        1.5+7    550.0
*----------------------------------------------------------------------
*                      component 120
* hot leg, core outlet to pressurizer (pipe: 0.25m dia, 2.0m long)
*          junctions connect volumes 1150000, 1400000, 1300000 to this
*                    volume
*crdno        name         type
1200000 coreout branch
*crdno   no.juns.    ctl
1200001        3       1
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
1200101  0.05      2.0    0.0 180.0    0.0     0.0      0.0    0.0     0
*crdno   ctl    pressure     temp
1200200    3       1.5+7    550.0
*crdno   from          to            area     floss     rloss     flag
1201101  115010000     120000000        0         0         0      100
1202101  120010000     140000000        0         0         0      100
1203101  120010006     130000000        0         0         0      100
*crdno   flowf    flowg    velj
1201201  131.0     0.0        0
1202201  131.0     0.0        0
1203201     0        0        0
*----------------------------------------------------------------------
*                      component 130
* pressurizer (surge line: 0.043m dia, 8.0m long)
*             (vessel: 0.87m dia, 7.5m long, reference bubble below)
*crdno        name         type
1300000     prsszr         pipe
*crdno     no.vols.
1300001          4
*crdno     area                             vol.no.
1300101    1.45-3                                1
1300102     0.6                                  4
*crdno     length                           vol.no.
1300301       8.0                                1
1300302       1.5                                4
*crdno     v-ang                            vol.no.
1300601     90.0                                 4
*crdno     rough     dhy                    vol.no.
1300801        0       0                         4
*crdno     ctl                              vol.no.
1301001      0                                   4
*crdno     ctl                              jun.no.
1301101      0                                   3
*crdno     ctl       pressure    quals      vol.no.
1301201      2          1.5+7      0.0  0 0 0    4
*crdno     i.c.
1301300      1
*crdno     flowf     flowg        velj      jun.no.
1301301       0         0            0           3
*----------------------------------------------------------------------
*                      component 131
* pressurizer liquid - bubble interface (reference vessel above)
*crdno        name         type
1310000     prz-stm      sngljun
*crdno    from          to            area     floss     rloss     flag
1310101   130010000     132000000        0         0         0        0
*crdno    ctl     flowf    flowg    velj
1310201     1        0        0        0
*----------------------------------------------------------------------
*splant *                      component 132
*splant * pressurizer steam bubble...(time dep vol, reference vessel above)
*splant *crdno        name         type
*splant 1320000 przbndry tmdpvol
*splant *crdno  area length volume h-ang  v-ang    delz    rough    dhy   ctl
*splant 1320101  0.6    3.0      0     0      0       0        0      0     0
*splant *crdno   ctl
*splant 1320200    2
*splant *crdno   time     pressure     quals
*splant 1320201   0.0        1.5+7       0.0
*splant: non-steady state nodalization but trips added to behave like stst.
*======================================================================
*                      component 132
* pressurizer top (top 3.0m of vessel: 0.87m dia, 7.5m long)
*                 (reference problem 2, component 130, 131, 132)
*crdno        name         type
1320000    prssztop        pipe
*crdno     no.vols.
1320001          2
*crdno     area                             vol.no.
1320101     0.6                                  2
*crdno     length                           vol.no.
1320301       1.5                                2
*crdno     v-ang                            vol.no.
1320601     90.0                                 2
*crdno     rough     dhy                    vol.no.
1320801        0       0                         2
*crdno     ctl                              vol.no.
1321001      0                                   2
*crdno     ctl                              jun.no.
1321101      0                                   1
*crdno     ctl       pressure    quals      vol.no.
1321201      2          1.5+7      1.0   0 0 0   2
*crdno     i.c.
1321300      1
*crdno     flowf     flowg        velj      jun.no.
1321301        0         0           0           1
*-----------------------------------------------------------------------
*                      component 133
* pressurizer, relief valve
*crdno        name         type
1330000     prz-relv       valve
*crdno    from          to            area     floss     rloss     flag
1330101   132010000     134000000     0.0005       0         0      100
*crdno    ctl     flowf    flowg    velj
1330201     1       0.0      0.0       0
*crdno      name
1330300     trpvlv
*crdno      trip no
*splant 1330301         608
*splant: trip changed
1330301         619
*-----------------------------------------------------------------------
*                      component 134
* pressurizer boundary tdv...(time dep vol, atmo pressure)
*crdno        name         type
1340000    przbndry        tmdpvol
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
1340101   0.6      1.0      0     0      0       0        0      0     0
*crdno   ctl
1340200    3
*crdno   time     pressure     temp
*splant 1340201   0.0        1.0+5     600.0
1340201    0.0        1.5+7     600.0  *alt. ctl=2, quals=0.0
1340202 1000.0        1.5+7     600.0  *alt. ctl=2, quals=0.0
1340203 1001.0        1.0+5     600.0  *alt. ctl=2, quals=1.0
1340204 2000.0        1.0+5     600.0  *alt. ctl=2, quals=1.0
*splant: end pzr nodalization
*----------------------------------------------------------------------
*                      component 140
* hot leg, pressurizer to steam generator inlet
*     (pipe: 0.25m dia, 4.0m long)
*crdno        name         type
1400000     stgen-in       pipe
*crdno     no.vols.
1400001          2
*crdno     area                             vol.no.
1400101    0.05                                  2
*crdno     length                           vol.no.
1400301       2.0                                2
*crdno     h-ang                            vol.no.
1400501    180.0                                 2
*crdno     v-ang                            vol.no.
1400601      0.0                                 2
*crdno     rough     dhy                    vol.no.
1400801        0       0                         2
*crdno     ctl                              vol.no.
1401001      0                                   2
*crdno     ctl                              jun.no.
1401101      0                                   1
*crdno     ctl       pressure     temp      vol.no.
1401201      3          1.5+7    550.0  0 0 0    2
*crdno     i.c.
1401300      1
*crdno     flowf     flowg        velj      jun.no.
1401301    131.0      0.0            0           1
*----------------------------------------------------------------------
*                      component 141
* steam generator inlet (abrupt: 0.25m pipe to 0.041sqm tube sheet)
*       connects volumes 1400000, 1500000
*crdno        name         type
1410000     stgen-in     sngljun
*crdno    from          to            area     floss     rloss     flag
1410101   140010000     150000000        0         0         0      100
*crdno    ctl     flowf    flowg    velj
1410201     1     131.0     0.0        0
*----------------------------------------------------------------------
*                      component 150
* steam generator tube sheet, primary side
*       (tubes: 500 tubes, 0.01021m id, 6.0m long)
*crdno        name         type
1500000      stgen         pipe
*crdno     no.vols.
1500001          3
*crdno     area                             vol.no.
1500101    0.041                                 3
*crdno     length                           vol.no.
1500301       2.0                                3
*crdno     v-ang                            vol.no.
1500601    -90.0                                 3
*crdno     rough     dhy                    vol.no.
1500801        0    0.01021                      3
*crdno     ctl                              vol.no.
1501001      0                                   3
*crdno     ctl                              jun.no.
1501101      0                                   2
*crdno     ctl       pressure     temp      vol.no.
1501201      3          1.5+7    550.0  0 0 0    3
*crdno     i.c.
1501300      1
*crdno     flowf     flowg        velj      jun.no.
1501301    131.0      0.0            0           2
*----------------------------------------------------------------------
*                      component 151
* steam generator outlet (abrupt: 0.041sqm tube sheet to 0.25m pipe)
*crdno        name         type
1510000 stgenout sngljun
*crdno    from          to            area     floss     rloss     flag
1510101   150010000     160000000        0         0         0      100
*crdno    ctl     flowf    flowg    velj
1510201     1     131.0     0.0        0
*----------------------------------------------------------------------
*                      component 160
* cold leg, steam generator outlet to pump (pipe: 0.25m dia, 2.0m long)
*crdno        name         type
1600000     pump-in      snglvol
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
1600101  0.05      2.0      0     0    0.0     0.0      0.0    0.0     0
*crdno   ctl     pressure     temp
1600200    3        1.5+7    550.0
*----------------------------------------------------------------------
*                      component 170
* pump
*     westinghouse homologous pump curves
*     flow area = 0.07 sqm, volume = 0.14 cum
*     ratings:  speed = 369 rpm                 flow = 0.81 cum/sec
*                head = 27.5 m                torque = 500.0 nm
*              mom.i. = 1.43 kg*sqm          density = 614.0 kg/cum
*     actual speed = 369 rpm
*crdno        name         type
1700000       pump         pump
*crdno     area   length volume h-ang   v-ang   delz   ctl
1700101    0.07      2.0      0     0     0.0    0.0     0
*crdno     from          area     floss     rloss     flag
1700108    160010000        0         0         0        0
*crdno     to            area     floss     rloss     flag
1700109    100000000        0         0         0        0
*crdno     ctl    pressure     temp
1700200      3       1.5+7    550.0
*crdno     ctl     flowf    flowg    velj
1700201      1     131.0     0.0        0
1700202      1     131.0     0.0        0
*crdno      id    2faz   2fazd   tork   pvel   ptrip   rvrs
1700301     -2       0      -2     -1      0     501      1
*crdno     rpvel  initv   rflo   rhead   rtork   momi   rdens
1700302    369.0    1.0   0.81    27.5   500.0   1.43   614.0
*crdno     rmotk   tf2    tf0    tf1     tf3
1700303        0  153.0  0.003  14.5       0
*crdno     ctl
1703000      0
*crdno     void   head   void   head   void   head
1703001     0.0    0.0   0.02   0.02   0.06   0.05
1703002     0.1    0.1   0.2    0.46   0.24   0.8
1703003     0.3    0.96  0.4    0.98   0.6    0.97
1703004     0.8    0.9   0.9    0.8    0.96   0.5
1703005     1.0    0.0
*crdno     ctl
1703100      0
*crdno     void   tork   void   tork   void   tork
1703101    0.0    0.0    0.125  0.07   0.165  0.125
1703102    0.24   0.56   0.8    0.56   0.96   0.45
1703103    1.0    0.0
* pump rotational velocity table
1706100  601  cntrlvar,601
1706101  0.0,0.0  500.0,500.0
*----------------------------------------------------------------------
*                      component 200
* steam generator feedwater supply...(time dep vol)
*       (vessel: 6.16m dia, 3.05m long)
*crdno        name         type
2000000 feedtank tmdpvol
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
2000101  29.8     3.05      0     0      0       0        0      0     0
*crdno   ctl
2000200    1
*crdno   time     temp     quals
2000201   0.0     478.0      0.0
*----------------------------------------------------------------------
*                      component 201
* steam generator feedwater inlet...(time dep jun)
*       (note: for s.s. feedwater inflow = steam dome outflow)
*crdno        name         type
2010000     aufwva       tmdpjun
*crdno    from          to            area
2010101   200010002     250010005     0.05
**2010113   0.0 0.0  1.0 180.0
*crdno    ctl     trip.no.     alph code     num.code
2010200     1         601      cntrlvar      751
*crdno    C-751     flowf     flowg     velj
2010201    -1.00     0.0       0.0      0.0
2010202     0.00     0.0       0.0      0.0
2010203     0.0      0.0       0.0      0.0
2010204    50.00    50.0       0.0      0.0
*----------------------------------------------------------------------
*                      component 210
* steam generator secondary, tube sheet section
*       (shroud: 0.919m dia, 6.0m long)
*       (tubes: 500 tubes, 0.01021m id, 0.0127m od)
*crdno        name         type
2100000     stgen-2        pipe
*crdno     no.vols.
2100001          3
*crdno     area                             vol.no.
2100101    0.60                                  3
*crdno     length                           vol.no.
2100301       2.0                                3
*crdno     v-ang                            vol.no.
2100601     90.0                                 3
*crdno     rough     dhy                    vol.no.
2100801        0    0.1051                       3
*crdno     floss     rloss                  jun.no.
2100901     15.0      15.0                       2
*crdno     ctl                              vol.no.
2101001      0                                   3
*crdno     ctl                              jun.no.
2101101      0                                   2
*crdno     ctl       pressure    quals      vol.no.
2101201      2          2.0+6    0.010 0 0 0     1
2101202      2          2.0+6    0.010 0 0 0     2
2101203      2          2.0+6    0.030 0 0 0     3
*crdno     i.c.
2101300      1
*crdno     flowf     flowg        velj      jun.no.
2101301    240.0     10.0            0           1
2101302    230.0     20.0            0           2
*----------------------------------------------------------------------
*                      component 220
* steam generator separator (annulus: 0.666m id, 1.099m od)
*                           (      0.239m gap, 2.0m long)
*    junctions connect volumes 2300000, 2700000, 2600000
*        to this volume
*crdno        name         type
2200000 secupdc branch
*crdno   ctl   i.c.
2200001    2     1
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
2200101  0.600     2.0    0.0   0.0   90.0     2.0      0.0    0.0     0
*crdno   ctl     pressure     quals
2200200    2        2.0+6      0.10
*crdno    from          to            area     floss     rloss     flag
2201101   220010000     290000000        0         0         0      100
2202101   220000000     270000000       0.15       0         0      100
*crdno    flowf    flowg    velj
2201201    0.0      6.0        0
2202201    0.0      0.0        0
*----------------------------------------------------------------------
2900000     bypass       branch
2900001    1     1
2900101  0.100     2.0    0.0   0.0   90.0     2.0      0.0    0.0     0
2900200    2        2.0+6      1.00
2901101   290010005     230010006      0.0        0         0      0
2901201    0.0      0.0        0
*----------------------------------------------------------------------
*                      component 230
* steam generator steam dome (0.357m dia, 2.0m long)
*crdno        name         type
2300000     sepa-con     snglvol
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
2300101  0.1       2.0    0.0   0.0   90.0     2.0      0.0    0.0     0
*crdno   ctl     pressure     quals
2300200    2        2.0+6       1.0
*----------------------------------------------------------------------
*                      component 231
* steam generator, steam dome outlet valve
*crdno        name         type
2310000 condenin valve
*crdno    from          to            area     floss     rloss     flag
2310101   230010000     240000000    0.01          0         0   000000
*crdno    ctl     flowf    flowg    velj
2310201     1      0.0     26.0        0
*crdno      name
2310300     srvvlv
2310301     702
2310401  0.0,9000.0,9000.0  1.0,0.0,0.0
*----------------------------------------------------------------------
*                      component 232
* steam generator, relief valve
*crdno        name         type
2320000     stm-relv       valve
*crdno    from          to            area     floss     rloss     flag
2320101   290010000     280000000     0.004        0         0      100
*crdno    ctl     flowf    flowg    velj
2320201     1      0.0      0.0        0
*crdno      name
2320300     trpvlv
*crdno      trip no
2320301     605
*----------------------------------------------------------------------
*                      component 240
* secondary outlet...tdv for steam dome outlet valve (comp 231)
*     (0.357m dia, 18.0m long)
*crdno        name         type
2400000 condensr tmdpvol
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
2400101  1.000    18.0      0     0      0       0        0      0     0
*crdno   ctl
2400200    3
*crdno   time     pressure     temp
2400201   0.0        1.0+5     435.0
*----------------------------------------------------------------------
*                      component 250
* steam generator downcommer...bottom (reference downcommer...top)
*crdno        name         type
2500000 downcmr annulus
*crdno     no.vols.
2500001          2
*crdno     area                             vol.no.
2500101    0.3                                   2
*crdno     length                           vol.no.
2500301       2.0                                2
*crdno     v-ang                            vol.no.
2500601    -90.0                                 2
*crdno     rough     dhy                    vol.no.
2500801        0    0.18                         2
*crdno     ctl                              vol.no.
2501001      0                                   2
*crdno     ctl                              jun.no.
2501101      0                                   1
*crdno     ctl       pressure    quals      vol.no.
2501201      2          2.0+6      0.0    0 0 0  2
*crdno     i.c.
2501300      1
*crdno     flowf     flowg        velj      jun.no.
2501301    249.0      1.0            0           1
*----------------------------------------------------------------------
*                      component 251
* steam generator, secondary side inlet...sg.dc. to tube section
*crdno        name         type
2510000 dwncsecs sngljun
*crdno    from          to            area     floss     rloss     flag
2510101   250010000     210000000        0      25.0      25.0      100
2510113   0.356824 -90.0  0.0 0.0
*crdno    ctl     flowf    flowg    velj
2510201     1     250.0     0.0        0
*----------------------------------------------------------------------
*                      component 260
* steam generator, secondary separator-chimney section
*       (chimney: 0.62m dia, 2.0m long)
*crdno        name         type
2600000     sepa-in      separatr
*crdno   ctl   i.c.
2600001    3     1
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
2600101   0.3      2.0    0.0   0.0   90.0     2.0      0.0    0.0     0
*crdno   ctl     pressure     quals
2600200    2        2.0+6      0.03
*crdno    from          to            area     floss     rloss     flag
2601101   260010000     230000000   0       0         0      100   0.40
2602101   260010001     270010001   0.15    0         0      100   0.50
2602113   0.178412 -90.0  0.178412 -90.0
2603101   210010000     260000000   0.15    0         0      100
*crdno    flowf    flowg    velj
2601201    0.0     26.0        0
2602201   100.0     4.0        0
2603201   100.0    26.0        0
*----------------------------------------------------------------------
*                      component 270
* steam generator downcommer...top
*       (annulus: 0.919m id, 1.099m od, 0.09m gap, 6.0m long)
*crdno        name         type
2700000 downcmr annulus
*crdno     no.vols.
2700001          1
*crdno     area                             vol.no.
2700101    0.3                                   1
*crdno     length                           vol.no.
2700301       2.0                                1
*crdno     v-ang                            vol.no.
2700601    -90.0                                 1
*crdno     rough     dhy                    vol.no.
2700801        0    0.18                         1
*crdno     ctl                              vol.no.
2701001      0                                   1
*crdno     ctl       pressure    quals      vol.no.
2701201      2          2.0+6      0.0    0 0 0  1
*----------------------------------------------------------------------
*                      component 271
* steam generator downcommer, jun...top to bottom
*crdno        name         type
2710000 dwnc sngljun
*crdno    from          to            area     floss     rloss     flag
2710101   270010000     250000000        0       0.0       0.0        0
*crdno    ctl     flowf    flowg    velj
2710201     1     220.0     4.0        0
*----------------------------------------------------------------------
*                      component 280
* secondary outlet...tdv for s. g. relief valve (comp 232)
*     (0.357m dia, 18.0m long)
*crdno        name         type
2800000 stmbndy tmdpvol
*crdno   area   length volume h-ang  v-ang    delz    rough    dhy   ctl
2800101  0.100    18.0      0     0      0       0        0      0     0
*crdno   ctl
2800200    3
*crdno   time     pressure     temp
2800201   0.0        1.0+5     435.0
*======================================================================
* control systems (for ploted powers)
*=====================================================================
* total core power in and s.g. power out (primary and secondary)
*crdno     name     type     scale     i.c.     flag
20501000 powerin    sum       1.0      0.0         1
20501100 powerout   sum       1.0      0.0         1
20501200 sgpower    sum       1.0      0.0         1
*crdno   a0   a1  v1           a2  v2           a3  v3
20501001 0.0  1.0 q 110010000  1.0 q 110020000  1.0 q 110030000
20501101 0.0 -1.0 q 150010000 -1.0 q 150020000 -1.0 q 150030000
20501201 0.0  1.0 q 210010000  1.0 q 210020000  1.0 q 210030000
* collapsed liquid levels in sg boiler and sg dc
*crdno     name     type     scale     i.c.     flag
20502000 sglevel    sum       1.0      0.0         1
20502100 sgdclvl      sum       1.0      0.0         1
*crdno   a0   a1  v1              a2  v2
20502001 0.0  2.0 voidf 210010000 2.0 voidf 210020000
20502002      2.0 voidf 210030000 2.0 voidf 260010000
20502101 0.0  2.0 voidf 250010000 2.0 voidf 250020000
20502102      2.0 voidf 270010000 2.0 voidf 220010000
* delta emass
20526400  delmass      sum       1.0      0.0         0
20526401  0.0
20526402  1.0 emass 0
20526403 -1.0 cntrlvar 265
* old time emass
20526500  oldemass   sum       1.0      0.0         0
20526501  0.0
20526502  1.0 emass 0
*======================================================================
*                       heat structures
*======================================================================
*                   heat structure 110
* core fuel rods within component 110
*    (350 rods, uo2 = 0.009294m dia, gap = 9.5e-5m,
*    (clad = 6.08e-4m thick, 3.0m long)
*crdno     no.h.s   no.m.p   geo   s.s.flg   left
11100000        12       10     2         0    0.0
11100001      2.46+6 110120000
11100011      1.0-6   2.0-6    0.0  0.0    12
*crdno     mesh flg   fmt
11100100          0     1
*crdno     intvl    rt.cor   intvl    rt.cor   intvl    rt.cor
11100101       5   4.647-3       1   4.742-3       3    5.35-3
*crdno     comp   intvl   comp   intvl   comp   intvl
11100201      1       5     -2       6     -3       9
*crdno     source   intvl   source   intvl
11100301      1.0       5        0       9
*crdno     temp     intvl
11100401   550.0       10
*crdno     left vol      incr   b.c   sacode   safac   h.s.no
11100501   0                0     0        1   87.5        12 * 350 rods
*crdno     rt vol        incr   b.c   sacode   safac   h.s.no
11100601   110010000    10000     1        1   87.5        12 * 350 rods
*crdno     s.type   mult   dir.left   dir.rt   h.s.no
11100701       10    0.0833333333 0        0        1
11100702       10    0.0833333333 0        0        2
11100703       10    0.0833333333 0        0        3
11100704       10    0.0833333333 0        0        4
11100705       10    0.0833333333 0        0        5
11100706       10    0.0833333333 0        0        6
11100707       10    0.0833333333 0        0        7
11100708       10    0.0833333333 0        0        8
11100709       10    0.0833333333 0        0        9
11100710       10    0.0833333333 0        0       10
11100711       10    0.0833333333 0        0       11
11100712       10    0.0833333333 0        0       12
*crdno     dhy
11100901   0.0  10.0,10.0  0.0,0.0  0.0,0.0  1.0    12
*----------------------------------------------------------------------
*                   heat structure 150
* steam generator tube sheet between components 210 and 150
*       (500 tubes, 0.01021m id, wall = 0.001244m thick, 6.0m long)
*crdno     no.h.s   no.m.p   geo   s.s.flg   left
11500000        3        8     2         1   0.005105
*crdno     mesh flg   fmt
11500100          0     1
*crdno     intvl    rt.cor
11500101       7   0.006349
*crdno     comp   intvl
11500201      6       7
*crdno     source   intvl
11500301        0       7
*crdno     temp     intvl
11500401   550.0        8
*crdno     left vol      incr   b.c   sacode   safac  h.s.no
11500501   150010000    10000     1        1  1000.0       3 * 500 tubes
*crdno     rt vol        incr   b.c   sacode   safac  h.s.no
11500601   210030000   -10000     1        1  1000.0       3 * 500 tubes
*crdno     s.type   mult   dir.left   dir.rt   h.s.no
11500701        0      0          0        0        3 * left side
11500801  0.0 10.0,10.0  0.0,0.0  0.0,0.0  1.0  3
11500901  0.0 10.0,10.0  0.0,0.0  0.0,0.0  1.0  3
*======================================================================
* general tables
*======================================================================
* table of time, core power
*crdno     name     trip     factor
*splant 20201000   power     506
*splant: trip substitution so that condition + time>1000.sec
20201000   power     616 -1.0 -1.0 -1.0 1
*crdno     time     watts
20201001    0.0     5.0+7  50.0 2.5+6  2500.0 0.0
*splant
*======================================================================
* heat structure thermal property data
*======================================================================
*crdno     mtl.type     th.con     ht.cap
20100100   tbl/fctn          1          1 * uo2
20100200   tbl/fctn          3          1 * gap
20100300   zr                             * zirconium
20100600   tbl/fctn          1          1 * inconel 600
*======================================================================
* thermal conductivity uo2
*======================================================================
*crdno      temp          th.con.
20100101   273.15         8.44
20100102   416.67         6.46
20100103   533.15         5.782385
20100104   699.8167       4.633177
20100105   866.4833       3.880307
20100106  1033.150        3.357625
20100107  1088.706        3.155129
20100108  1199.817        2.983787
20100109  1283.150        2.836674
20100110  1366.483        2.713792
20100111  1533.150        2.521680
20100112  1616.483        2.448990
20100113  1699.817        2.391875
20100114  1977.594        2.289762
20100115  2255.372        2.307069
20100116  2533.150        2.433413
20100117  2810.928        2.661870
20100118  3088.706        2.994171
20100119  4088.706        2.994171
*======================================================================
* thermal conductivity gap
*======================================================================
*crdno      gas           mole fraction
20100201   helium         1.00
*======================================================================
* thermal conductivity inconel 600
*======================================================================
*crdno      temp          th.con.
20100601     0.0          13.85
20100602   366.5          13.85
20100603   477.6          15.92
20100604   588.7          18.17
20100605   700.0          20.42
20100606   810.9          22.50
20100607   922.0          24.92
20100608  1033.2          26.83
20100609  1144.3          29.42
20100610  1477.6          36.06
*======================================================================
* volumetric heat capacity uo2
*======================================================================
*crdno      temp          ht.cap.
20100151   273.15         2310427.0
20100152   323.15         2571985.0
20100153   373.15         2746357.0
20100154   673.15         3138694.0
20100155  1373.15         3443844.0
20100156  1773.15         3531030.0
20100157  1973.15         3792588.0
20100158  2173.15         4228518.0
20100159  2373.15         4882412.0
20100160  2673.15         6015829.0
20100161  2773.15         6320980.0
20100162  2873.15         6582538.0
20100163  2973.15         6713317.0
20100164  3113.15         6800503.0
20100165  4699.817        6800503.0
*======================================================================
* volumetric heat capacity gap
*======================================================================
*crdno      temp          ht.cap.
20100251   273.15         5.4
20100252  3260.0          5.4
*======================================================================
* volumetric heat capacity inconel 600
*======================================================================
*crdno      temp          ht.cap.
20100651     0.0          3.908e6
20100652   366.5          3.908e6
20100653   477.6          4.084e6
20100654   588.7          4.260e6
20100655   700.0          4.436e6
20100656   810.9          4.665e6
20100657   922.0          4.929e6
20100658  1033.2          5.105e6
20100659  1477.6          5.727e6
*  controllers added for control system
20560000  pumpctl  constant  275.0
20560100  pumpctl  pumpctl  500.0  275.0  0  3  0.0  500.0
20560101  cntrlvar,600  mflowj,120010000  500.0  5.0  5.0
*
20565900  onoffsw  tripunit  1.0  1.0  1  0
20565901  601
20570000  steamctl  constant  2.6+6
20570100  steamctl  steamctl  1.0  0.2  0  3  0.0  1.0
20570101  cntrlvar,700  p,230010000  -1.0+7  10.0  10.0
*
20570200  steamctl  mult  1.0  1.0  1  0
20570201  cntrlvar,659  cntrlvar,701
*
20574900  feedctl  sum  1.0  0.0  1  0
20574901  0.0,  2.0,voidf,220010000  2.0,voidf,270010000
20574902  2.0,voidf,250010000  2.0,voidf,250020000
*
20575000  feedctl  constant  6.5
20575100  feedctl  feedctl  50.0  15.0  0  3  0.0  50.0
20575101  cntrlvar,750  cntrlvar,749  6.5
20575102  mflowj,231000000 mflowj,201000000  30.0 15.0  15.0
*splant: additional variables
20590000  T-616     tripunit  1.0 1.0 1 0
20590001  616
20800001   gntblval 10
20800002   httemp   110001010
.*-------------------- end of input -----------------------------------
