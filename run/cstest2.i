*======================================================================
*               idaho national engineering laboratory
*   sample problem number: continuation of steady state
*
*   The problem simulates a modified station blackout transient
*                restart from problem 1 at 200 sec
*
*   Reconfiguration (renodalization) is examined in this run.  at
*   restart, the time-dependent volume 132 is to be replaced by a
*   vertical 2-volume pipe component.  a pressurizer relief valve 133
*   and a time dependent volume 134 also added (see diagram below)
*
*           ..........
*           .        .     pressurizer time dep boundary
*           .   134  .
*           ..........
*               .
*           133 .          pressurizer relief valve
*               .          junction area = 0.0005 m**2
*           ..........
*           .        .     normal component representing the top 3.0m
*           . 13202  .     of the pressurizer containing the steam
*       132 ..........     bubble. replaces the tdv component 132 of
*           . 13201  .     problem 2.
*           ..........
*
*   Valve 133 will be open if p of 132 is above 18.0 mpa and will stay
*   open untill p is below 13.5 mpa.
*
*   Reactor shutdown will occur at 5 sec after the first opening of
*   valve 133.
*
*   Most of the input data for pipe 132, valve 133, valve 133 trip,
*   and reactor shutdown trip (number 506) are missing on the data
*   cards.  the missing data are indicated by the placeholder _____ .
*   the user is asked to supply the missing input data  and the
*   restart number.
*
*======================================================================
* title card
*======================================================================
=relap5 simplified pwr sample problem, transient case
*======================================================================
* problem type and option
*======================================================================
*crdno     problem type     option
100             restart     transnt
*======================================================================
* restart number
*======================================================================
*crdno   rst no
103      2006
*======================================================================
* time step control cards
*======================================================================
*crdno end time  min dt   max dt  control  minor ed  major ed  restart
201       200.0   1.0-6     0.05        7        10       500     5000
*======================================================================
* minor edit requests
*======================================================================
*crdno    v-code     parameter
301       p          110030000
302       p          132020000
303       p          230010000
311       tempf      110030000
321       mflowj     110020000
322       mflowj     133000000
323       mflowj     210020000
324       mflowj     250010000
325       mflowj     231000000
326       mflowj     232000000
341       pmpvel     170
351       cntrlvar   20
352       cntrlvar   21
*======================================================================
*                          trips
*======================================================================
* no  left variable   rel   rt variable + const   function
501   time        0    gt   null   0       0.0    l * pump + logical
504   p   132020000    gt   null   0      1.80+7  n * pressurizer
*                    relief vlv...high pressure set point (c-133)
505   p   132020000    gt   null   0      1.35+7  n * pressurizer
*                    relief vlv....low pressure set point (c-133)
506   time        0    gt   timeof 608    5.0     l * time for pzr
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
*======================================================================
*                      component data
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
1330301         608
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
1340201   0.0        1.0+5     600.0
. end of input
