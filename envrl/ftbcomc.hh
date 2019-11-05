*comdeck ftbcomc
c
c
c  ftbcom description
c
c  Cognizant engineer: gam.
c
c T Name(dim)  Definition
c
c i lfsiz      size of a array in /fast/
c              size of b array in /ftblcm/
c              parameter is set here to 500,000
c              it is later set in fast.H comdeck to 2,200,000
c
c /fast/ common block (saved)
c
c T Name(dim)  Definition
c
c r a(lfsiz)   scm storage array for ftb files
c i ia(lfsiz)  equivalenced to a
c
c /ftblcm/ common block if lcm is defined
c
c T Name(dim)  Definition
c
c r b(lfsiz)   lcm storage pool for ftb files
c              equivalenced to a if in32 is defined
c
c /ftb/ common block
c
c T Name(dim)  Definition
c
c i first      flag, indicates the ftb routines have been initialized
c              initialized to 0 in ftbftb.f
c              set to iftb = 12345 in ftbint.f after the ftbftb call
c i size(7)    number of words on each unit
c i maxz(7)    address of last available word in pool on this unit
c              a(maxz(i)-1) = last location we can store information in
c i minz(7)    address of first available word in pool on this unit
c              a(minz(i)) = first location we can store information in
c i nolink     number of link tables
c i nofils     number of file descriptions in current link table
c i link1      address of first link table
c i lasdes     address of last described file
c i nexdes     address to place next file description
c i ndsk2      number of disk units defined (set to 7 in ftbftb.f)
c i reclim     length of buffer for disk files
c              initialized to 1024 in ftbftb.f
c i ireclt(5)  buffer size on units 3-7 (disk units)
c i szz(8)     initial space on each unit
c              units 1, 2, and 8 are initialized to 0 in ftbftb.f
c              units 3-7 are initialized to 100,000,000 in ftbftb.f
c l hilo       logical flag indicating preferred end of SCM
c              true if preferred end is the high end (RELAP5 uses this)
c              false if preferred end is the low end
c l dlt        logical flag to control link shifting
c              false implies that links are shifted as far as possible
c l dly        logical flag that is set when a write is issued to
c                force a check before deleting the buffer
c dpn(4)       logical flag to check for open files on units 3-6
c              true if a file is open on the unit
c
c /ftb/ common block on the cray only (saved)
c
c T Name(dim)  Definition
c
c i ftbun(5)   disk unit numbers on the cray
c              initialized in data statement to 21-25 in ftbftb.f
