=LBLOCA:5 vertical reflood slabs (cccg=7771) in pipe 777.
* 5 horizontal bundles (134) slabs (cccg=5134) in pipe 555
* plus 5 110 slabs in 777  (cccg=7110) with PG-CHF.
* plus 5 102 slabs (parallel plates cccg=8102) in vert pipe 888.
*--------------------------------------------------------------------
*problem  type      option
0000100   new    transnt
*            inp-chk or run
0000101                 run
*
*units      input    output   (si or british)
0000102       si       si
*
*0000105       1. 3.      1000.    1  100
*110         hydrogen
*              ref-vol     ref-elev       fluid     name
*0000120    777010000        0.            h2on       rex
*           t-end     mn-st  mx-st  st-cl     minor     mj     wr
0000201        1.0   1.0-7,  0.05      7,        1,     100,  4000
0000202       10.0   1.0-7,  0.05      7,        10,     100,  4000
0000203       60.0   1.0-7,  0.2,      7,        10,     100,  4000
*=================================================================
20800001   htmode   777100501
20800002   zqbot    7771
20800003   zqtop    7771
20800004   zqbot    7110
20800005   zqtop    7110
20800006   fines    7771
20800007   fines    7110
20800017   hif    777010000
20800018   hig    777010000
*==============================================================
* lower plenum (vol no. 1)
0050000   "low-plen"  tmdpvol
*         area   len  vol theta vert  dz   eps  Dh tlpvbfe
0050101   1.0e6   1.57  0.0 0.0  90.0 1.57   0.  0.    0
0050200   0      *  p       uf         ug      voidg
0050201    0.0000   3.e6   3.5e5   2.5e6        0.
*=======================================================
*hydro             component name      component type
4900000              "bot-bran"             branch
*----------------------------------------------------------------------$
*hydro           no. juns            vel/flw
4900001   3 0
*
*hydro            area               length              volume
4900101            0.                0.433               0.4600
*
*hydro         horz angle          vert angle            delta z
4900102            0.                90.                  0.433
*
*hydro          roughness           hyd diam               fe
4900103         0.0000457           0.2970                00
*
*hydro  ebt pressure     qual
4900200 2  3.0e6      0.
*
*hydro    from          to           area      f loss    r loss    vcahs
4901101     5010000     490010003    0.           0.        0.     01101
*
4901110   0.3255 0.0 1.0 1.0
*
4901201   7.18713    7.18713 0. * 656.577
*
*hydro    from          to           area      f loss    r loss    vcahs
4904101   490010000     777000000    0.           0.        0.     01100
*
4904110   0.1799 0.0 1.0 1.0
*
4904201   16.37995 16.61813 0. * 1844.74
*
*hydro    from          to           area      f loss    r loss    vcahs
* tune: Kentrance = 152
4905101   490010000     888000000    0.        152.00    152.00    01000
*
4905201   1.186765   1.404193 0. * 147.7398
*
*--------------------------------------------------------------*
*               name      type
7770000         tube      pipe
*             no.vol
7770001           5
*vol            area    vol n0
7770101      1.      1
7770102      1.      5
*jun            area    jun no
7770201           1.         4
*            vol lgh    vol no
7770301      .6            1
7770302      .6            5
*             vr ang    vol no
7770601        90.0,       5
*               roug    hy dia    vol no
7770801           0.      .128    5
*vol         ctl-flg-pvbfe    vol no
7771001              00100    5
*jun         flg-fvcahs jun no
7771101          001000     4
*vol     ebt  pressure    uf        ug       void   blank  vol no
7771201  000   3.e6      1.0e6  2.606e6       .0    0.     5
*jun in          ctl
7771300            0
*jun in        f vel     g vel    if vel    jun no
7771301       .0          0.      0.          4   *  .346696
*--------------------------------------------------------------*
*               name      type
8880000         tube      pipe
*             no.vol
8880001           5
*vol            area    vol n0
8880101      1.      1
8880102      1.      5
*jun            area    jun no
8880201           1.         4
*            vol lgh    vol no
8880301      .6            1
8880302      .6            5
*             vr ang    vol no
8880601        90.0,       5
*               roug    hy dia    vol no
8880801           0.      .128    5
*vol         ctl-flg-pvbfe    vol no
8881001              00200    5
*jun         flg-fvcahs jun no
8881101          001000     4
*vol     ebt  pressure    uf        ug       void   blank  vol no
8881201  000   3.e6      1.0e6  2.606e6       .0    0.     5
*jun in          ctl
8881300            0
*jun in        f vel     g vel    if vel    jun no
8881301       .0          0.      0.          4   *  .346696
*hydro   jun hyd diam                                               jun
8881401      0.0024831   0.0 1.0 1.0                               4
*        pit         span      num
8883101  1.25947e-3  84.33e-3  5
*=======================================================
*hydro             component name      component type
5900000              "top-bran"             branch
*----------------------------------------------------------------------$
*hydro           no. juns            vel/flw
5900001   3 0
*
*hydro            area               length              volume
5900101            0.                0.433               0.4600
*
*hydro         horz angle          vert angle            delta z
5900102            0.                90.                  0.433
*
*hydro          roughness           hyd diam               fe
5900103         0.0000457           0.2970                00
*
*hydro  ebt pressure     qual
5900200 2  3.0e6      0.
*
*hydro    from          to           area      f loss    r loss    vcahs
5901101   777050002     590010003    0.           0.        0.     01101
*
5901110   0.3255 0.0 1.0 1.0
*
5901201   7.18713    7.18713 0. * 656.577
*
*hydro    from          to           area      f loss    r loss    vcahs
5904101   888050002     590010003    0.           0.        0.     01100
*
5904110   0.1799 0.0 1.0 1.0
*
5904201   16.37995 16.61813 0. * 1844.74
*
*hydro    from          to           area      f loss    r loss    vcahs
* tune: Kentrance = 152
5905101   590010000     555000000    0.        152.00    152.00    01000
*
5905201   1.186765   1.404193 0. * 147.7398
*
*=======================================================
*               name      type
5550000         tube      pipe
*             no.vol
5550001           5
*vol            area    vol n0
5550101      1.      1
5550102      1.      5
*jun            area    jun no
5550201           1.         4
*            vol lgh    vol no
5550301      .6            1
5550302      .6            5
*             vr ang    vol no
5550601        0.0,       5
*               roug    hy dia    vol no
5550801           0.      .128    5
*vol         ctl-flg-pvbfe    vol no
5551001              00100    5
*jun         flg-fvcahs jun no
5551101          001000     4
*vol     ebt  pressure    uf        ug       void   blank  vol no
5551201  000   3.e6      1.0e6  2.606e6       .0    0.     5
*jun in          ctl
5551300            0
*jun in        f vel     g vel    if vel    jun no
5551301       .0          0.      0.          4   *  .346696
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
0070000 "exit" tmdpvol
*         area len vol theta vert  dz   eps  Dh tlpvbfe
0070101   1.e6 1.   0.   0.    0.   0.   0.   0.   0
0070200   2 *       p          x
0070201    0.0000   1.e5       1.0
*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
2070000  break-j   sngljun *   area     kf     kr  jefvcahs
2070101   555010000  007000000  0.1    5.0    5.0     0100
2070201   1          0.0        0.0     0.0
*......................................................................
* pipe  heat structure
*gl data          nh        np      type    s-flg   l-cor ref Left mesh
17771000          5,        3,        2,      0,     0.1   2   1  4
*mesh        loc flg   frm flg
17771100           0,        1
*             no intervals     r-cor
17771101           2      .167
*cmp             flg
*17771200           0
*             cmp no    itv no
17771201           1,        2
*ht so       dis flg
*17771300           0
*             source    itv no
17771301         1.0,        2
*ini temp        flg (-1 means; separate dist for each NH)
17771400           -1
*               temp   mesh pt
17771401    400.      400.   400.
17771402    600.      600.   600.
17771403    830.      830.   830.
17771404   1140.     1140.  1140.
17771405    850.      850.   850.
*l-bndy       hy vol       inc     b-cdt    a-code    a/l   h-st-no
17771501           0,        0,      0,        1,   2.16667        5
*r-bndy
17771601   777010000,    10000,        1,        1,   2.16667      5
*source         type   is mplr    l-dr-ht  r-dr-ht   h-st no
17771701         100, 0.1192662,        0,       0,        5
*         heat.    heat.    heat.  grid  grid  grid  grid  axial  heat
*        equiv.    len.     len.   spa.  spa.  loss  loss  peak.  str.
*        diam.     forward  rev.   for.  rev.  for.  rev.  fact.  no.
17771801 .1414628  1.08333  1.0    0.0   0.0   0.0   0.0   1.0     5
17771901 .1414628  1.08333  1.0    0.0   0.0   0.0   0.0   1.0     5
*          1        2        3      4     5    6      7     8      9
*......................................................................
* pipe  heat structure
*gl data          nh        np      type    s-flg   l-cor ref Left mesh
17110000          5,        3,        2,      0,     0.1   2   1  4
*mesh        loc flg   frm flg
17110100           0,        1
*             no intervals     r-cor
17110101           2      .167
*cmp             flg
*17110200           0
*             cmp no    itv no
17110201           1,        2
*ht so       dis flg
*17110300           0
*             source    itv no
17110301         1.0,        2
*ini temp        flg (-1 means; separate dist for each NH)
17110400           -1
*               temp   mesh pt
17110401    400.      400.   400.
17110402    600.      600.   600.
17110403    830.      830.   830.
17110404   1140.     1140.  1140.
17110405    850.      850.   850.
*l-bndy       hy vol       inc     b-cdt    a-code       a/l   h-st no
17110501           0,        0,      0,        1,   2.16667        5
*r-bndy
17110601   777010000,    10000,        1,        1,   2.16667        5
*source         type   is mplr    l-dr-ht  r-dr-ht   h-st no
17110701         100, 0.1192662,        0,       0,        5
17110800  0
*         heat.    heat.    heat.  grid  grid  grid  grid  axial  heat
*        equiv.    len.     len.   spa.  spa.  loss  loss  peak.  str.
*        diam.     forward  rev.   for.  rev.  for.  rev.  fact.  no.
17110801 .1414628  1.08333  1.0    0.0   0.0   0.0   0.0   1.0     5
17110900  2
*          1        2    3   4   5   6      7         8       9  10  11  12 13
17110901 0.138   0.1   1.  1.  1.  1.  490010000 590010000  0.  1.  1.  13  1
17110902  0.138  0.2   1.  1.  1.  1.  490010000 590010000  0.  1.  1.  13  2
17110903  0.138  0.3   1.  1.  1.  1.  490010000 590010000  0.  1.  1.  13  3
17110904  0.138  0.4   1.  1.  1.  1.  490010000 590010000  0.  1.  1.  13  4
17110905  0.138  0.5   1.  1.  1.  1.  490010000 590010000  0.  1.  1.  13  5
*......................................................................
* vertical rod  heat structure
*gl data          nh        np      type    s-flg   l-cor ref Left mesh
18102000          5,        3,        2,      0,     0.0
*mesh        loc flg   frm flg
18102100           0,        1
*             no intervals     r-cor
18102101           2      .01
*             cmp no    itv no
18102201           1,        2
*             source    itv no
18102301         1.0,        2
*ini temp        flg (-1 means; separate dist for each NH)
18102400           -1
*               temp   mesh pt
18102401    500.      500.   500.
18102402    600.      600.   600.
18102403    830.      830.   830.
18102404   1140.     1140.  1140.
18102405    850.      850.   850.
*l-bndy       hy vol       inc     b-cdt    a-code       a/l   h-st-no
18102501           0,        0,      0,        1,   100.         5
*r-bndy
18102601   888010000,    10000,      102,        1,   100.      5
*source         type   is-mult    l-dr-ht  r-dr-ht   h-st no
18102701         900     .6          0,       0,        1
18102702         900     .8          0,       0,        2
18102703         900     1.          0,       0,        3
18102704         900     1.2         0,       0,        4
18102705         900      .8         0,       0,        5
18102800    0
18102900    1
*       heat.    heat.    heat. grid  grid   grid  grid  axial nat pit ff heat
*      equiv.    len.     len.   spa.  spa.  loss  loss  peak. con ovr   str.
*      diam.     forward  rev.   for.  rev.  for.  rev.  fact. len dia ff no.
18102801  0.141   1.08333  1.0  0.0   0.0   0.0   0.0   1.0    5
18102901  0.141   1.08333  1.0  0.0   0.0   0.0   0.0   1.0    3. 1.2 1.  5
*         1         2       3     4    5    6      7      8    9  10  11 12
*......................................................................
* Horizontal rod  heat structure
*gl data          nh        np      type    s-flg   l-cor ref Left mesh
15134000          5,        3,        2,      0,     0.0
*mesh        loc flg   frm flg
15134100           0,        1
*             no intervals     r-cor
15134101           2      .01
*             cmp no    itv no
15134201           1,        2
*             source    itv no
15134301         1.0,        2
*ini temp        flg (-1 means; separate dist for each NH)
15134400           -1
*               temp   mesh pt
15134401    500.      500.   500.
15134402    600.      600.   600.
15134403    830.      830.   830.
15134404   1140.     1140.  1140.
15134405    850.      850.   850.
*l-bndy       hy vol       inc     b-cdt    a-code    a/l   h-st-no
15134501           0,        0,      0,        1,   100.           5
*r-bndy
15134601   555010000,    10000,      134         1,   100.        5
*source         type   is mplr    l-dr-ht  r-dr-ht   h-st no
15134701         900     1.          0,       0,        5
15134900    1
*         heat.   heat.    heat. grid  grid  grid  grid  axial nat pit ff heat
*        equiv.  len.     len.   spa.  spa.  loss  loss  peak. con ovr    str.
*        diam.   forward  rev.   for.  rev.  for.  rev.  fact. len dia     no.
15134901 .141      1.08333  1.0    0.0   0.0   0.0   0.0   1.0   .14 1.2 1.  5
*         1         2       3       4     5      6   7      8    9   10  11  12
*......................................................................
*heat structure thermal property data
*               type    cn flg    ca flg
*nomonic  80a
20100100    tbl/fctn         1         1
*......................................................................
*    material properties data
*    thermal conductivity data
*    nomonic 80a
20100101           0.0     18.
20100102         100.0     18.
20100103        1500.0     18.
20100104        5000.0     18.
*.......................................................................
*     volumetric heat capacity data
*      nomonic 80a
20100151      32.  3.28e6      5100.0         3.28e6
*............. power table   ..........................
20210000    power
20210001       0.   0.       5000.0         0.
*............right boundary heat loss.................
20290000       power
20290001       0.0       10000000.
20290002       5.0       10000000.
20290003      15.0        1000000.
20290004   50000.0        1000000.
.
