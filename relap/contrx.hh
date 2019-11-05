*mlist
c  Variables in comctl.h common block.
c
c  Cognizant engineer: rjw.
c
c T Name    Definition
c r dthy    Hydrodynamic time step requested by user.
c r dtht    Heat structure time step, currently the same as dthy.
c r dtn     Time step limit due to material transport stability limit
c              (Courant limit).
c r dt      Current time step.
c r timehy  Problem time for hydrodynamic advancements.
c r timeht  Problem time for heat structure advancements.
c r errmax  Error estimate used in time step control.
c r tmass   Total mass of water in system currently.
c r tmasso  Total mass of water in system at time = 0.0.
c r emass   Current mass error.
c r emasso  Old mass error.
c r cpurem(5)  Contains cpu remaining times values and advancement
c                 counts to start/stop diagnostic edit from input.
c i cpurei  Integer values (5) of the real cpurem
c           (1=>3) not used
c           (4) word 4 from 105 card
c               = ncount1, ncount for starting diagnostic edits
c               = -1, write to dumpfil1 for ncount2 = cpurei(5), stop
c               = -2, write to dumpfil1 for ncount2 = cpurei(5),
c                     redo timestep, write to dumpfil2, stop
c               = -3, set in dtstep for -2 case.
c           (5) word 5 from 105 card
c               = ncount2, ncount for terminating diagnostic edits
c r stdtrn  Steady state - transient flag
c           0.0 = steady state
c           1.0 = transient
c r gravcn  Gravitational constant (which may be set by input).
c r testda  Data array for minor edits and plotting during debug.
c           Temporary coding is used to load data in this array and
c           scnreq accepts testda as a legal request.
c l aflag   Is set true in dtstep when heat structures are to be
c           advanced; checked in htadv
c i print   Misc. packed word.
c           Bits numbered 1-32 from right end.
c           1 (=1) restart enable bit,
c             (bit 1 is set in inputd if rstrip is to write formatted
c             output.
c           2 (=2) major edit enable bit,
c           3 (=4) minor edit enable bit,
c           4 (=8) plot enable bit,
c           5 (=16) complete restart switch,
c           6 (=32) interactive flag,
c           7 (=64) implicit heat transfer flag,
c           8 (=128) two step flag,
c           9 (=256) steady state termination flag,
c           10 (=512) on-line selection of time integration flag,
c           11 (=1024) athena option,
c           12 (=2048) scdap option,
c           13 (=4096) plot record squoz flag,
c           14 (=8192) restart-plot file compress flag,
c           15 (=16384) transient rotation flag,
c           16-32 restart block number.
c i succes  Integer flag indicating success of the advancement.
c           0 = no need to repeat advancement with reduced time step
c           1 = excessive truncation error
c           2 = water property error
c           3 = non-diagonal matrix
c           4 = metal appears
c i done    Integer flag indicating state of transient.
c           0   = advancements are to continue,
c           !=0 = advancements are to be terminated.
c i ncount  Count of number of advancements, successful or otherwise.
c r countn  Real value of the integer ncount
c i nstsp   Number of standard advancements.
c i nrepet  Number of hydrodynamic advancements at current dt to finish
c           a requested time step of dthy.
c i help    Used to control debug editing and termination.
c i nany    Number of mass error messages remaining to be issued.
c l skipt   Logical flag used to control first entry processing in
c           subroutine dtstep.
c i iroute  Problem type and problem option from 100 card
c           Initially = -1 in blkdta
c           Set to 0 at top of rcards, reset to 1, if insufficient room
c           In inputd, it contains two integers packed into one word
c           Problem type, bits 1-6 (see ityp1 in inputd)
c            1 = new
c            2 = restart
c            3 = relap5 internal plots
c            4 = generate initial condition input data
c            5 = strip
c            6 = cmpcom (compare dump records)
c           Problem option, bits 7-12 (see ityp2 in inputd)
c            1 = stdy-st (1 and 2 are used for new and restart)
c            2 = transnt
c            3 = binary (3 and 4 are used for strip)
c            4 = fmtout
c           if rnewp is called in inputd, iroute = problem option
c           if rstrip is called in inputd, iroute = 5
c i ncase   Case number
c           Initially = -1 in blkdta
c           = zero if last case of series
c l fail    Set to true if error encountered.
c l uniti   If true, SI units on input.
c l unito   If true, SI units on output.
c i iextra  Packed word containing flags indicating what models
c           were changed at restart.
c           Bits numbered 1-32 from right end.
c           1 (=1) hydrodynamic change
c           2 (=2) heat conduction change
c           3 (=4) reactor kinetics change
c           4 (=8) plot record change
c           5 (=16) radiation change
c           6 (=32) fission product change
c           7 (=64) control system change
c           This quantity could be equivalenced with nmechk
c           if this quantity is not needed to pad to an even number
c           of integer words.
c i pageno  Page number.
c i iplotlen  Length of plot records in full precision words before
c             data words are converted to half precision.
c r safe2   Same purpose as safe1
c l nmechk  true if no mass error check requested on time step card
c             (no 1 bit on time step card)
c           equivalenced to safe2
c imdctl(1) control word for individual code models
c           Bits numbered 1-32 from right end
c           1 (=1) level model activated
c           2 (=2) level crossing activated
c           3 (=4) Bit off means no input GUI mode, bit on means input
c           GUI mode.
c           4 (=8) Bit off means no transient GUI mode, bit on means
c           transient GUI mode.
c           5 (=z'10') dmwrite bit on means damage statement written to
c           inpout, to be copied to print file if advancement
c           successful.
c           6-31 not used
c imdctl(2) not used
