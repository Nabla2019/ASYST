       program builderm
!  Builds makefiles from base makefile and source decks that include
!  *call, include, use, and module dependencies.
!  Input prototype file is given from input parameter and output
!  makefile is makrelap.
!
$if -def,rk3d
$if def,msnt,1
       use dflib
$if def,linux,1
       use iflport,only:getenvqq
       implicit none
       integer, parameter :: work=1, makein=2, makeout=3, error=6
       integer, parameter :: numdir=5
       integer, parameter :: nflflim=2000,nflhlim=1000
       integer, parameter :: ndepenhp=10000,ndepenmp=5000,ndepenup=5000
       integer i,i2,iargc,idum,j,j2,k,k2,l,n,n1,ndepem,ndepen,ndepeu,
     & ndotfls,ndothls,ndoth2,ndoth2m,ndothmk,nmodls,nrules(0:2)
       logical fexist,tst,tstf(numdir)
       integer dotfd(nflflim),dothd(nflhlim),dotmd(ndepenmp),
     & dotud(ndepenup)
       character ch*1,dotfls(nflflim)*32,dothls(nflhlim)*32,
     & dothmk(nflhlim)*32,depenf*32,depenn*32,dum*32,
     & dum2*32,bcd*80,rules(40,2)*72
       type depens
         character :: i*32,d*32
       end type depens
       type (depens) depenh(ndepenhp),depenm(ndepenmp),depenu(ndepenup),
     & dumt
$if def,msnt
       character, parameter ::
     & filnmh(numdir)*16=(/'envrl\filedoth  ','matpro\filedoth ',
     & 'relap\filedoth  ','scdap\filedoth  ','rk3d\filedoth   '/),
     & filnmf(numdir)*16=(/'envrl\filedotf  ','matpro\filedotf ',
     & 'relap\filedotf  ','scdap\filedotf  ','rk3d\filedotf   '/)
       character, parameter ::
     & dirnm(numdir)*8=(/'envrl\  ','matpro\ ','relap\  ','scdap\  ',
     & 'rk3d\   '/)
       character, parameter :: chnm*6='$(NM)\'
$endif
$if -def,msnt
       character, parameter ::
     & filnmh(numdir)*16=(/'envrl/filedoth  ','matpro/filedoth ',
     & 'relap/filedoth  ','scdap/filedoth  ','rk3d/filedoth   '/),
     & filnmf(numdir)*16=(/'envrl/filedotf  ','matpro/filedotf ',
     & 'relap/filedotf  ','scdap/filedotf  ','rk3d/filedotf   '/)
       character, parameter ::
     & dirnm(numdir)*8=(/'envrl/  ','matpro/ ','relap/  ','scdap/  ',
     & 'rk3d/   '/)
       character, parameter :: chnm*6='$(NM)/'
$endif
       character makerp*16
       character, parameter :: astrks*8='********'
!
!  depenh   Holds pairs of *.obj-*.h file names from include statements.
!  depenm   Holds pairs of *.obj-*.mod file names from module
!           statements.
!  depenu   Holds pairs of *.obj-*.mod file names from use statements.
!  dotfd    Holds directoty number of .ff files.
!  dotfls   Holds file name (not including directory name) of .ff files.
!  dothd    Holds directoty number of .hh files.
!  dothls   Holds file name (not including directory name) of .hh files.
!  dotmd    
!  ndepen   Number of pairs of *.obj-*.hh file names (number of entries
!           in depenh).
!  ndepenm  Number of pairs of *.obj-*.mod file names (number of entries
!           in depenm).
!  ndepenu  Number of pairs of *.obj-*.mod file names (number of entries
!           in depenu).
!  ndepenhp Dimensioned limit for depenh.
!  ndepenmp Dimensioned limit for depenm.
!  ndepenup Dimensioned limit for depenu.
!  ndotfls  Number of source files.
!  nflflim  Dimensioned limit of number of .ff files.
!  nflhlim  Dimensioned limit of number of .hh files.
!
!  Get file name of prototype makefile from parameter included in the
!  command invoking this program.
       i = iargc()
       if (i .ne. 1) then
         write (error,"(a8,1x,'Parameter indicating prototype make file 
     &was not included in command line.')") astrks
         stop
       endif
       call getarg (1,makerp)
!  Read list of *.ff files from results of ls *.ff.
       fexist = .false.
       do i = 1,numdir
         inquire (file=filnmf(i),exist=tstf(i))
         fexist = fexist .or. tstf(i)
       enddo
       if (fexist) then
         ndotfls = 0
         do i = 1,numdir
           if (tstf(i)) then
             open (unit=work,file=filnmf(i),access='sequential',
     &       action='read',form='formatted',status='unknown')
             do
               read (work,"(a32)",iostat=j) dotfls(ndotfls+1)
               dotfd(ndotfls+1) = i
               if (j .gt. 0) then
                 write (error,"(a8,1x,a' filedotf file error.')")
     &           astrks,filnmf(i)
                 stop
               elseif (j .eq. 0) then
                 ndotfls = ndotfls + 1
                 if (ndotfls .ge. nflflim) then
                   write (error,"(a8,' Too many *.ff files.')") astrks
                   stop
                   exit
                 endif
               else
                 close (unit=work)
                 exit
               endif
             enddo
           endif
         enddo
         if (ndotfls .eq. 0) then
           write (error,"(a8,' No *.ff files.')") astrks
           stop
         endif
!  Sort list of files from ls *.ff into order.
         call qsortci (dotfls,dotfd,1,ndotfls)
         fexist = .false.
         do i = 2,ndotfls
           if (dotfls(i) .eq. dotfls(i-1)) then
             write (error,"(a8,' Duplicate *.ff files in directories:',
     &       2x,a,'.')")
     &       astrks,dotfls(i)
             fexist = .true.
           endif
         enddo
         if (fexist) stop
       else
         write (error,"(a8,' No files from ls *.ff commands exist.')")
     &   astrks
         stop
       endif
!  Read list of *.hh files from results of ls *.hh.
       fexist = .false.
       do i = 1,numdir
         inquire (file=filnmh(i),exist=tstf(i))
         fexist = fexist .or. tstf(i)
       enddo
       if (fexist) then
         ndothls = 0
         do i = 1,numdir
           if (tstf(i)) then
             open (unit=work,file=filnmh(i),access='sequential',
     &       action='read',form='formatted',status='unknown')
             do
               read (work,"(a32)",iostat=j) dothls(ndothls+1)
               dothd(ndothls+1) = i
               if (j .gt. 0) then
                 write (error,"(a8,' filedoth file error',i8,'.')")
     &           astrks
                 stop
               elseif (j .eq. 0) then
                 ndothls = ndothls + 1
                 if (ndothls .ge. nflhlim) then
                   write (error,"(a8,' Too many *.hh files.')") astrks
                   stop
                   exit
                 endif
               else
                 close (unit=work)
                 exit
               endif
             enddo
           endif
         enddo
c        if (ndothls .eq. 0) then
c          write (error,"(a8,' No *.hh files.')") astrks
c          stop
c        endif
!  Sort list of files from ls *.hh into order.
         call qsortci (dothls,dothd,1,ndothls)
         fexist = .false.
         do i = 2,ndothls
           if (dothls(i) .eq. dothls(i-1)) then
             write (error,"(a8,' Duplicate *.hh files in directories:',
     &       2x,a,'.')")
     &       astrks,dothls(i)
             fexist = .true.
           endif
         enddo
         if (fexist) stop
!  Set up for binary search.
         i = 1
         do
           ndoth2 = i
           i = i + i
           if (i .gt. ndothls) exit
         enddo
       else
         write (error,"(a8,' No files from ls *.hh commands exist.')")
     &   astrks
         stop
       endif
!
!  Read *.ff list from prototype of make file.
c      inquire (file=makerp,exist=fexist)
c      if (.not.fexist) then
c        write (error,"(a8,' Prototype makefile is missing.')") astrks
c        stop
c      else
c        open (unit=makein,file=makerp,access='sequential',
c    &   action='read',form='formatted',status='unknown')
!  Find beginning of list of *.ff files in make prototype and copy lines
!  to new makefile.
c        open (unit=makeout,file='makrelap',access='sequential',
c    &   action='write',form='formatted',status='unknown')
c        fexist = .false.
c        do
c          read (makein,"(a80)",iostat=j) bcd
c          if (j .eq. 0) then
c            l = len_trim(bcd)
c            write (makeout,"(a)") bcd(1:l)
c            if (bcd(1:8) .eq. 'SRCS = \') then
c              fexist = .true.
c              exit
c            endif
c          endif
c        enddo
c        if (.not.fexist) then
c          write (error,"(a8,' SRCS definition not found in prototype ma
c    &kefile.')") astrks
c          stop
c        endif
c      endif
!  Read list of *.ff files in make prototype and also copy lines to new
!  makefile.
c      ndotfmk = 0
c      srce: do
c        read (makein,"(a80)",iostat=j) bcd
c        if (j .ne. 0) then
c          write (error,"(a8,' Read error or improper end of file on mak
c    &efile prototype.')") astrks
c          stop
c        else
c          l = len_trim(bcd)
c          write (makeout,"(a)") bcd(1:l)
c          fexist = .false.
c          i = 1
c          do
c            j = verify(bcd(i:72),' ')
c            if (j .eq. 0) then
c              exit srce
c            else
c              j = i + j - 1
c              if (bcd(j:j).ge.'a' .and. bcd(j:j).le.'z') then
c                i = index(bcd(j+1:72),' ')
c                i = j + i
c                if (bcd(i-3:i-1) .ne. '.ff') stop "14"
c                ndotfmk = ndotfmk + 1
c                if (ndotfmk .gt. 1000) then
c                  write (error,"(a8,' Too many *.ff files in makefile p
c    &rototype.')") astrks
c                  stop
c                endif
c                dotfmk(ndotfmk) = bcd(j:i-1)
c              elseif (bcd(j:j) .eq. '\') then
c                exit
c              else
c                stop "16"
c              endif
c            endif
c          enddo
c        endif
c      enddo srce
c      if (ndotfmk .eq. 0) then
c        write (error,"(a8,' No list of *.ff files in makefile prototype
c    &.')") astrks
c        stop
c      else
!  Sort list of *.ff files into order.
c        do i = 2,ndotfmk
c          if (dotfmk(i) .lt. dotfmk(i-1)) then
c            dum = dotfmk(i)
c            do j = i-1,1,-1
c              dotfmk(j+1) = dotfmk(j)
c              if (j .eq. 1) exit
c              if (dum .gt. dotfmk(j-1)) exit
c            enddo
c            dotfmk(j) = dum
c          endif
c        enddo
!  Check for duplicate entries in list of *.ff files in makefile
!  prototype.
c        do i = 2,ndotfmk
c          if (dotfmk(i) .eq. dotfmk(i-1)) then
c            write (error,"(a8,' Duplicate *.ff files in makefile protot
c    &ype list.')") astrks
c            stop
c          endif
c        enddo
c      endif
!
!  Check if *.ff files from make prototype are in directory.
c      ndothmk = 0
c      k = 1
c      do i = 1,ndotfmk
c        fexist = .false.
c        do j = k,ndotfls
c          if (dotfmk(i) .eq. dotfls(j)) then
c            k = j + 1
c            fexist = .true.
c            exit
c          elseif (dotfmk(i) .lt. dotfls(j)) then
c            k = j
c            exit
c          endif
c        enddo
c        if (.not.fexist) then
c          ndothmk = ndothmk + 1
c          dothmk(ndothmk) = dotfmk(i)
c        endif
c      enddo
c      if (ndothmk .ne. 0) then
c        write (error,"(a8,' Following *.ff files are in the makefile pr
c    &ototype but not in the directory:'/(3a25))") astrks,
c    &   (dothmk(i),i=1,ndothmk)
c        stop
c      endif
!  Read *.ff files and search for *call, include, use, or module
!  statements.
       ndepen = 0
       ndepem = 0
       ndepeu = 0
       ndothmk = 0
       do i = 1,ndotfls
         depenf = trim(dirnm(dotfd(i))) // dotfls(i)
         open (unit=work,file=depenf,access='sequential',
     &   action='read',form='formatted',status='unknown',iostat=j)
         depenf = dotfls(i)
         j = index(depenf,'.') + 1
         depenf(j:j+2) = '$O'
         depenn = trim(dirnm(dotfd(i))) // depenf
         do
           read (work,"(a72)",iostat=j) bcd(1:72)
           if (j .eq. 0) then
             j = scan(bcd(1:72),char(13))
             if (j .ne. 0) bcd(j:j) = ' '
             i2 = 0
             if (bcd(1:6) .eq. '*call ') then
!  Process *call statement by obtaining *.h file name.
               j = verify(bcd(7:72),' ')
               j = j + 6
               k = index(bcd(j:72),' ')
               k = j + k - 1
               dum = bcd(j:k-1) // '.h'
               dum2 = bcd(j:k-1) // '.hh'
               i2 = 1
             else
               j = verify(bcd(1:72),' ')
               if (bcd(j:j+7) .eq. 'include ') then
!  Process include statement by extracting *.h file name.
                 n = verify(bcd(j+8:72),' ')
                 if (n .ne. 0) then
                   j = j + 7 + n
                   if (bcd(j:j).eq.'"' .or. bcd(j:j).eq."'") then
                     ch = bcd(j:j)
                     k = index(bcd(j+1:72),ch)
                     if (k .ne. 0) then
                       k = j + k
                       dum = bcd(j+1:k-1)
                       dum2 = bcd(j+1:k-2) // 'hh'
                       i2 = 1
                     endif
                   endif
                 endif
               elseif (bcd(j:j+3) .eq. 'use ') then
!  Process use statement by obtaining module name to be used.
                 n = verify(bcd(j+4:72),' ')
                 if (n .ne. 0) then
                   j = j + 3 + n
                   k = scan(bcd(j+1:72),' ,')
                   if (k .ne. 0) then
                     k = j + k - 1
$if def,modcap
                     do i2 = j,k
                       if (bcd(i2:i2).ge.'a' .and. bcd(i2:i2).le.'z')
     &                 bcd(i2:i2) = char(ichar(bcd(i2:i2)) - 32)
                     enddo
$endif
                     dum = bcd(j:k) // '.mod'
                     i2 = 2
                   endif
                 endif
               elseif (bcd(j:j+6).eq.'module ' .and.
     &         bcd(j:j+15).ne.'module procedure') then
!  Process module statement by obtaining module name being defined.
                 n = verify(bcd(j+7:72),' ')
                 if (n .ne. 0) then
                   j = j + 6 + n
                   k = index(bcd(j+1:72),' ')
                   if (k .ne. 0) then
                     k = j + k - 1
$if def,modcap
                     do i2 = j,k
                       if (bcd(i2:i2).ge.'a' .and. bcd(i2:i2).le.'z')
     &                 bcd(i2:i2) = char(ichar(bcd(i2:i2)) - 32)
                     enddo
$endif
                     dum = bcd(j:k) // '.mod'
                     idum = dotfd(i)
                     i2 = 3
                   endif
                 endif
               endif
             endif
!  Store derived pairs into proper tables.
             if (i2 .eq. 1) then
!  Store *.obj-*.h pairs derived from *call or include statements.
!  Check if *.hh file is in directory.
               fexist = .false.
               j = ndoth2
               k = j
               chk1: do
                 if (dum2 .eq. dothls(j)) then
                   fexist = .true.
                   exit chk1
                 else
                   tst = dum2 .lt. dothls(j)
                   do 
                     k = ishft(k,-1)
                     if (k .eq. 0) exit chk1
                     if (.not.tst) then
                       j = j + k
                       if (j .le. ndothls) cycle chk1
                       j = j - k
                       cycle
                     else
                       j = j - k
                       exit
                     endif
                   enddo
                 endif
               enddo chk1
               if (fexist) then
!  Indicated *.hh file is in directory, add pair to tables.
                 ndepen = ndepen + 1
                 if (ndepen .gt. ndepenhp) then
                   write (error,"(a8,' Too many *.obj-*.hh pairs from us
     &e statements.')") astrks
                   stop
                 endif
                 depenh(ndepen)%d = depenn
                 depenh(ndepen)%i = trim(dirnm(dothd(j))) // dum
!  Add *.hh file to list for new makefile if not already in list.
                 if (ndothmk .eq. 0) then
                   ndothmk = 1
                   ndoth2m = 1
                   dothmk(ndothmk) = dum2
                 else
                   fexist = .false.
                   j = ndoth2m
                   k = j
                   chk2: do
                     if (dum2 .eq. dothmk(j)) then
                       fexist = .true.
                       exit chk2
                     else
                       tst = dum2 .lt. dothmk(j)
                       do
                         k = ishft(k,-1)
                         if (k .eq. 0) exit chk2
                         if (.not.tst) then
                           j = j + k
                           if (j .le. ndothmk) cycle chk2
                           j = j - k
                           cycle
                         else
                           j = j - k
                           exit
                         endif
                       enddo
                     endif
                   enddo chk2
                   if (.not.fexist) then
!  *.hh file is not already in list; add it.
                     if (.not.tst) j = j + 1
                     do k = ndothmk,j,-1
                       dothmk(k+1) = dothmk(k)
                     enddo
                     dothmk(j) = dum2
                     ndothmk = ndothmk + 1
                     j = 1
                     do
                       ndoth2m = j
                       j = j + j
                       if (j .gt. ndothmk) exit
                     enddo
                   endif
                 endif
               endif
             elseif (i2 .eq. 2) then
!  Store *.obj-*.mod pairs derived from use statements.
               ndepeu = ndepeu + 1
               if (ndepeu .gt. ndepenup) then
                 write (error,"(a8,' Too many *.obj-*.mod pairs from use
     & statements.')") astrks
                 stop
               endif
               depenu(ndepeu)%d = depenn
               depenu(ndepeu)%i = dum
             elseif (i2 .eq. 3) then
!  Store *.mod-*.obj-*.ff sets derived from module statements.
               ndepem = ndepem + 1
               if (ndepem .gt. ndepenmp) then
                 write (error,"(a8,' Too many *.obj-*.mod pairs from mod
     &ule statements.')") astrks
                 stop
               endif
               depenm(ndepem)%d = dum
               depenm(ndepem)%i = depenn
               dotmd(ndepem) = idum
             endif
           else
             close (unit=work)
             exit
           endif
         enddo
       enddo
!
!  Sort *.obj-*.h table into makefile order.
       call qsortdep (depenh,1,ndepen)
!  Remove duplicate entry from *.obj-*.h table.
       n = 0
       i = 2
       do j = 2,ndepen
         if (depenh(j)%i.eq.depenh(i-1)%i .and.
     &   depenh(j)%d.eq.depenh(i-1)%d) then
           n = n + 1
         else
           if (n .ne. 0) depenh(i) = depenh(j)
           i = i + 1
         endif
       enddo
       ndepen = ndepen - n
!  Sort *.obj-*.mod table into makefile order.
       call qsortdep (depenu,1,ndepeu)
!  Remove duplicate entry from *.obj-*.mod table.
       n = 0
       i = 2
       do j = 2,ndepeu
         if (depenu(j)%i.eq.depenu(i-1)%i .and.
     &   depenu(j)%d.eq.depenu(i-1)%d) then
           n = n + 1
         else
           if (n .ne. 0) depenu(i) = depenu(j)
           i = i + 1
         endif
       enddo
       ndepeu = ndepeu - n
!  Sort *.mod-*.obj table into reverse of makefile order for checking.
       call qsortdpi (depenm,dotmd,1,ndepem)
!  Check if duplicate module definitions.
       fexist = .false.
       do i = 2,ndepem
         if (depenm(i)%d .eq. depenm(i-1)%d) then
           fexist = .true.
           exit
         endif
       enddo
       if (fexist) then
         write (error,"(a8,' Duplicate definition of modules--'a32,'.')"
     &) astrks,depenm(i)%d
         stop
       endif
!  Eliminate references to modules not defined in *.ff files.
       n = 0
       i = 1
       l = 1
       do k = 1,ndepem
         fexist = .false.
         do j = l,ndepeu
           if (depenm(k)%d .eq. depenu(j)%i) then
             dotud(j) = dotmd(k)
             if (n .ne. 0) then
               depenu(i) = depenu(j)
               dotud(i) = dotud(j)
             endif
             i = i + 1
             l = j + 1
           else
             if (depenm(k)%d .gt. depenu(j)%i) then
               n = n + 1
               l = j + 1
             else
               l = j
               fexist = .true.
               exit
             endif
           endif
         enddo
         if (.not.fexist) exit
       enddo
       ndepeu = l - n - 1
!  Add directory name to file name of .mod file in *.obj-*.mod list.
       do i = 1,ndepeu
         dum = depenu(i)%i
         depenu(i)%i = chnm // dum
       enddo 
!  Add directory name to file name of .mod file in *.mod-*.obj list.
       do i = 1,ndepem
         dum = depenm(i)%d
         depenm(i)%d = chnm // dum
       enddo 
!  Sort *.obj-*.mod table into makefile order again due to directory
!  name addition.
!  Sort *.mod-*.obj table into makefile order.
       do i = 2,ndepem
         if (depenm(i)%i.lt.depenm(i-1)%i .or.
     &   (depenm(i)%i.eq.depenm(i-1)%i .and.
     &   depenm(i)%d.lt.depenm(i-1)%d)) then
           dumt = depenm(i)
           do j = i-1,1,-1
             depenm(j+1) = depenm(j)
             if (j .eq. 1) exit
             if (dumt%i.gt.depenm(j-1)%i .or.
     &       (dumt%i.eq.depenm(j-1)%i .and.
     &       dumt%d.gt.depenm(j-1)%d)) exit
           enddo
           depenm(j) = dumt
         endif
       enddo
!
!  Write module definitions to Makefile.
       inquire (file=makerp,exist=fexist)
       if (.not.fexist) then
         write (error,"(a8,' Prototype makefile is missing.')") astrks
         stop
       else
         open (unit=makein,file=makerp,access='sequential',
     &   action='read',form='formatted',status='unknown')
         open (unit=makeout,file='makrelap',access='sequential',
     &   action='write',form='formatted',status='unknown')
       endif
       if (ndepem .ne. 0) then
         do
           read (makein,"(a80)",iostat=j) bcd
           if (j .ne. 0) then
             write (error,
     & "(a8,' Read error or improper end of file on makefile prototype.'
     & )") astrks
             stop
           else
             l = len_trim(bcd)
             write (makeout,"(a)") bcd(1:l)
             if (bcd(1:17) .eq. '#  Module Targets') exit
           endif
         enddo
!  Read rules for building module.
         nrules = 0
         k2 = 0
         do
           read (makein,"(a80)",iostat=j) bcd
           if (j .ne. 0) then
             write (error,
     & "(a8,' Read error or improper end of file on makefile prototype.'
     & )") astrks
             stop
           endif
           if (bcd(1:72) .eq. ' ') exit
           if (bcd(1:7) .ne. '#  rule') then
             write (error,"(a8,' Line containing #  run was expected but
     & not read.')") astrks
             stop
           endif
           k2 = k2 + 1
           if (k2 .gt. 2) then
             write (error,"(a8,' Too many rules being entered.')")
     &       astrks
             stop
           endif
           tst = .false.
           do i = 1,40
             read (makein,"(a72)",iostat=j) rules(i,k2)
             if (j .ne. 0) then
               write (error,
     & "(a8,' Read error or improper end of file on makefile prototype.'
     & )")     astrks
               stop
             endif
             if (rules(i,k2)(1:72) .eq. ' ') then
               write (error,"(a8,' Blank line encountered in rule.')")
     &         astrks
             elseif (rules(i,k2)(1:10) .eq. '#  endrule') then
               nrules(k2) = i - 1
               tst = .true.
               exit
             endif
           enddo
           if (.not.tst) then
             write (error,"(a8,' Too many lines in a rule or #  endrule
     &does not terminate a rulexs.')") astrks
             stop
           endif
         enddo
         nrules(0) = k2
!
         i = 1
         do
           n = 0
           do k = 0,1
             if (k .eq. 0) then
               dum = depenm(i)%d
             else
               dum = depenm(i)%i
             endif
             l = len_trim(dum)
             if (n + l .gt. 68) then
c              bcd(n+1:n+1) = '\'
               bcd(n+1:n+1) = char(92)
               write (makeout,"(a)") bcd(1:n+1)
               n = 0
             endif
             n1 = n + 1
             n = n1 + l
             bcd(n1:n) = trim(dum)
           enddo
           bcd(n+1:n+2) = ': '
           n = n + 2
           if (n + l .gt. 71) then
c            bcd(n+1:n+1) = '\'
             bcd(n+1:n+1) = char(92)
             write (makeout,"(a)") bcd(1:n+1)
             n = 0
           endif
           n1 = n + 1
           n = n + l
cc
           if (dum(1:7) .eq. 'visasrc') then
             dum(l-1:l) = 'f '
             k2 = 2
           elseif (dum(1:4) .eq. 'rk3d') then
             dum(l-1:l) = 'f9'
             k2 = 2
           else
             dum(l-1:l) = 'ff'
             k2 = 1
           endif
cc
           bcd(n1:n) = trim(dum)
           write (makeout,"(a)") bcd(1:n)
           do j = 1,nrules(k2)
             l = len_trim(rules(j,k2))
             write (makeout,"(a)") rules(j,k2)(1:l)
           enddo
           i = i + 1
           if (i .gt. ndepem) exit
         enddo
       endif
!  Set up for binary search used in writing *.h and *.mod dependencies.
       if (ndepem .ne. 0) then
         i = 1
         do
           ndoth2 = i
           i = i + i
           if (i .gt. ndepem) exit
         enddo
       endif
!  Write *.h dependency information to Makefile.
       do
         read (makein,"(a80)",iostat=j) bcd
         if (j .ne. 0) then
           write (error,
     & "(a8,' Read error or improper end of file on makefile prototype.'
     & )") astrks
           stop
         else
           l = len_trim(bcd)
           write (makeout,"(a)") bcd(1:l)
           if (bcd(1:25) .eq. '#  Dependency Definitions') exit
         endif
       enddo
       if (ndepen .ne. 0) then
         i = 1
         do
           dum = depenh(i)%i
           do j = i+1,ndepen
             if (depenh(j)%i .ne. dum) exit
           enddo
           j = j - 1
           n = 0
           do k = i,j
             dum2 = depenh(k)%d
             do i2 = 0,1
               if (i2 .ne. 0) then
                 if (ndepem .eq. 0) exit
                 fexist = .false.
                 j2 = ndoth2
                 k2 = j2
                 chk3: do
                   if (dum2 .eq. depenm(j2)%i) then
                     fexist = .true.
                     exit chk3
                   else
                     tst = dum2 .lt. depenm(j2)%i
                     do
                       k2 = ishft(k2,-1)
                       if (k2 .eq. 0) exit chk3
                       if (.not.tst) then
                         j2 = j2 + k2
                         if (j2 .le. ndepem) cycle chk3
                         j2 = j2 - k2
                         cycle
                       else
                         j2 = j2 - k2
                         exit
                       endif
                     enddo
                   endif
                 enddo chk3
                 if (.not.fexist) cycle
                 dum2 = depenm(j2)%d
               endif
               l = len_trim(dum2)
               if (n + l .gt. 68) then
c                bcd(n+1:n+1) = '\'
                 bcd(n+1:n+1) = char(92)
                 write (makeout,"(a)") bcd(1:n+1)
                 n = 0
               endif
               n1 = n + 1
               n = n1 + l
               bcd(n1:n) = trim(dum2)
             enddo
           enddo
           bcd(n+1:n+2) = ': '
           n = n + 2
           l = len_trim(depenh(j)%i)
           if (n + l .gt. 71) then
c            bcd(n+1:n+1) = '\'
             bcd(n+1:n+1) = char(92)
             write (makeout,"(a)") bcd(1:n+1)
             n = 0
           endif
           n1 = n + 1
           n = n + l
           bcd(n1:n) = trim(depenh(j)%i)
           write (makeout,"(a)") bcd(1:n)
           i = j + 1
           if (i .gt. ndepen) exit
         enddo
       endif
!  Write *.mod dependency information to Makefile.
       if (ndepeu .ne. 0) then
         i = 1
         do
           dum = depenu(i)%i
           do j = i+1,ndepeu
             if (depenu(j)%i .ne. dum) exit
           enddo
           j = j - 1
           n = 0
           do k = i,j
             dum2 = depenu(k)%d
             do i2 = 0,1
               if (i2 .ne. 0) then
                 if (ndepem .eq. 0) exit
                 fexist = .false.
                 j2 = ndoth2
                 k2 = j2
                 chk4: do
                   if (dum2 .eq. depenm(j2)%i) then
                     fexist = .true.
                     exit chk4
                   else
                     tst = dum2 .lt. depenm(j2)%i
                     do
                       k2 = ishft(k2,-1)
                       if (k2 .eq. 0) exit chk4
                       if (.not.tst) then
                         j2 = j2 + k2
                         if (j2 .le. ndepem) cycle chk4
                         j2 = j2 - k2
                         cycle
                       else
                         j2 = j2 - k2
                         exit
                       endif
                     enddo
                   endif
                 enddo chk4
                 if (.not.fexist) cycle
                 dum2 = depenm(j2)%d
               endif
               l = len_trim(dum2)
               if (n + l .gt. 68) then
c                bcd(n+1:n+1) = '\'
                 bcd(n+1:n+1) = char(92)
                 write (makeout,"(a)") bcd(1:n+1)
                 n = 0
               endif
               n1 = n + 1
               n = n1 + l
               bcd(n1:n) = trim(dum2)
             enddo
           enddo
           bcd(n+1:n+2) = ': '
           n = n + 2
           l = len_trim(depenu(j)%i)
           if (n + l .gt. 71) then
c            bcd(n+1:n+1) = '\'
             bcd(n+1:n+1) = char(92)
             write (makeout,"(a)") bcd(1:n+1)
             n = 0
           endif
           n1 = n + 1
           n = n + l
           bcd(n1:n) = trim(depenu(j)%i)
           write (makeout,"(a)") bcd(1:n)
           i = j + 1
           if (i .gt. ndepeu) exit
         enddo
       endif
       stop
!
       contains
!
       recursive subroutine qsortdep (dep,m1,m2)
!  Sorts an array, dep(m1:m2), of type depens using the quicksort
!  algorithm.
!
       implicit none
       integer m1,m2
       type (depens) dep(*)
!
       integer i1,i2
!
!  Swap value at middle of array with value of first element of array.
       if (m2 - m1 .ge. 3) then
         i1 = (m1 + m2)/2
         dumt = dep(i1)
         dep(i1) = dep(m1)
         dep(m1) = dumt
       endif
!  Initialize left and right pointers.
       i1 = m1 + 1
       i2 = m2
!  Move data such that data less than value now in first element is to
!  the left and data greater than that value is to the right.
       outer: do
!  Move left pointer to the right.
         do
           if (i1 .gt. i2) exit outer
           if (dep(i1)%i .gt. dep(m1)%i) exit
           if (dep(i1)%i .eq. dep(m1)%i) then
             if (dep(i1)%d .gt. dep(m1)%d) exit
           endif
           i1 = i1 + 1
         enddo
!  Move right pointer to the left.
         do
           if (i2 .lt. i1) exit outer
           if (dep(i2)%i .lt. dep(m1)%i) exit
           if (dep(i2)%i .eq. dep(m1)%i) then
             if (dep(i2)%d .lt. dep(m1)%d) exit
           endif
           i2 = i2 - 1
         enddo
         dumt = dep(i2)
         dep(i2) = dep(i1)
         dep(i1) = dumt
       enddo outer
!  Move data in first element to divide the left and right regions.
       dumt = dep(i2)
       dep(i2) = dep(m1)
       dep(m1) = dumt
!  Set up and call for recursive sorts of the two regions if necessary.
       i2 = i2 - 1
       if (i2 .gt. m1) call qsortdep (dep,m1,i2)
       if (m2 .gt. i1) call qsortdep (dep,i1,m2)
       return
       end subroutine qsortdep
!
       recursive subroutine qsortci (crv1,irv2,m1,m2)
!  Sorts an array, crv1(m1:m2) and carries an associated array using
!  the quicksort algorithm.
!
       implicit none
       integer m1,m2
       character(32) crv1(*)
       integer irv2(*)
!
       character(32) tem
       integer is
       integer i1,i2
!
!  Swap value at middle of array with value of first element of array.
       if (m2 - m1 .ge. 3) then
         i1 = (m1 + m2)/2
         tem = crv1(i1)
         crv1(i1) = crv1(m1)
         crv1(m1) = tem
         is = irv2(i1)
         irv2(i1) = irv2(m1)
         irv2(m1) = is
       endif
!  Initialize left and right pointers.
       i1 = m1 + 1
       i2 = m2
!  Move data such that data less than value now in first element is to
!  the left and data greater than that value is to the right.
       outer: do
!  Move left pointer to the right.
         do
           if (i1 .gt. i2) exit outer
           if (crv1(i1) .gt. crv1(m1)) exit
           i1 = i1 + 1
         enddo
!  Move right pointer to the left.
         do
           if (i2 .lt. i1) exit outer
           if (crv1(i2) .lt. crv1(m1)) exit
           i2 = i2 - 1
         enddo
         tem = crv1(i2)
         crv1(i2) = crv1(i1)
         crv1(i1) = tem
         is = irv2(i2)
         irv2(i2) = irv2(i1)
         irv2(i1) = is
       enddo outer
!  Move data in first element to divide the left and right regions.
       tem = crv1(i2)
       crv1(i2) = crv1(m1)
       crv1(m1) = tem
       is = irv2(i2)
       irv2(i2) = irv2(m1)
       irv2(m1) = is
!  Set up and call for recursive sorts of the two regions if necessary.
       i2 = i2 - 1
       if (i2 .gt. m1) call qsortci (crv1,irv2,m1,i2)
       if (m2 .gt. i1) call qsortci (crv1,irv2,i1,m2)
       return
       end subroutine qsortci
!
       recursive subroutine qsortdpi (dep,irv2,m1,m2)
!  Sorts an array, dep(m1:m2), of type depens and an associated integer
!  array using the quicksort algorithm.
!
       implicit none
       integer m1,m2
       type (depens) dep(*)
       integer irv2(*)
!
       integer i1,i2
       integer is
!
!  Swap value at middle of array with value of first element of array.
       if (m2 - m1 .ge. 3) then
         i1 = (m1 + m2)/2
         dumt = dep(i1)
         dep(i1) = dep(m1)
         dep(m1) = dumt
         is = irv2(i1)
         irv2(i1) = irv2(m1)
         irv2(m1) = is
       endif
!  Initialize left and right pointers.
       i1 = m1 + 1
       i2 = m2
!  Move data such that data less than value now in first element is to
!  the left and data greater than that value is to the right.
       outer: do
!  Move left pointer to the right.
         do
           if (i1 .gt. i2) exit outer
           if (dep(i1)%d .gt. dep(m1)%d) exit
           if (dep(i1)%d .eq. dep(m1)%d) then
             if (dep(i1)%i .gt. dep(m1)%i) exit
           endif
           i1 = i1 + 1
         enddo
!  Move right pointer to the left.
         do
           if (i2 .lt. i1) exit outer
           if (dep(i2)%d .lt. dep(m1)%d) exit
           if (dep(i2)%d .eq. dep(m1)%d) then
             if (dep(i2)%i .lt. dep(m1)%i) exit
           endif
           i2 = i2 - 1
         enddo
         dumt = dep(i2)
         dep(i2) = dep(i1)
         dep(i1) = dumt
         is = irv2(i2)
         irv2(i2) = irv2(i1)
         irv2(i1) = is
       enddo outer
!  Move data in first element to divide the left and right regions.
       dumt = dep(i2)
       dep(i2) = dep(m1)
       dep(m1) = dumt
       is = irv2(i2)
       irv2(i2) = irv2(m1)
       irv2(m1) = is
!  Set up and call for recursive sorts of the two regions if necessary.
       i2 = i2 - 1
       if (i2 .gt. m1) call qsortdpi (dep,irv2,m1,i2)
       if (m2 .gt. i1) call qsortdpi (dep,irv2,i1,m2)
       return
       end subroutine qsortdpi
       end program builderm
$endif
$if def,rk3d
$if def,msnt,1
       use dflib
$if def,linux,1
       use iflport,only:getenvqq
       implicit none
       integer, parameter :: work=1, makein=2, makeout=3, error=6
       integer, parameter :: numdir=7
       integer, parameter :: nflflim=2000,nflhlim=1000
       integer, parameter :: ndepenhp=10000,ndepenmp=20000,
     & ndepenup=20000
       integer i,i2,iargc,idum,j,j2,k,k2,l,n,n1,ndepem,ndepen,ndepeu,
     & ndotfls,ndothls,ndoth2,ndoth2m,ndothmk,nmodls,nrules(0:2)
       logical fexist,tst,tstf(numdir)
       integer dotfd(nflflim),dothd(nflhlim),dotmd(ndepenmp),
     & dotud(ndepenup)
       character ch*1,dotfls(nflflim)*32,dothls(nflhlim)*32,
     & dothmk(nflhlim)*32,depenf*32,depenn*32,dum*32,
     & dum2*32,bcd*80,lcbcd*80,rules(40,2)*72
       type depens
         character :: i*32,d*32
       end type depens
       type (depens) depenh(ndepenhp),depenm(ndepenmp),depenu(ndepenup),
     & dumt
$if def,msnt
       character, parameter ::
     & filnmh(numdir)*16=(/'envrl\filedoth  ','matpro\filedoth ',
     & 'relap\filedoth  ','scdap\filedoth  ','contmn\filedoth ',
     & 'visasrc\filedoth','rk3d\filedoth   '/),
     & filnmf(numdir)*16=(/'envrl\filedotf  ','matpro\filedotf ',
     & 'relap\filedotf  ','scdap\filedotf  ','contmn\filedotf ',
     & 'visasrc\filedotf','rk3d\filedotf   '/)
       character, parameter ::
     & dirnm(numdir)*8=(/'envrl\  ','matpro\ ','relap\  ','scdap\  ',
     & 'contmn\ ','visasrc\','rk3d\   '/)
       character, parameter :: chnm*6='$(NM)\'
$endif
$if -def,msnt
       character, parameter ::
     & filnmh(numdir)*16=(/'envrl/filedoth  ','matpro/filedoth ',
     & 'relap/filedoth  ','scdap/filedoth  ','contmn/filedoth ',
     & 'visasrc/filedoth','rk3d/filedoth   '/),
     & filnmf(numdir)*16=(/'envrl/filedotf  ','matpro/filedotf ',
     & 'relap/filedotf  ','scdap/filedotf  ','contmn/filedotf ',
     & 'visasrc/filedotf','rk3d/filedotf   '/)
       character, parameter ::
     & dirnm(numdir)*8=(/'envrl/  ','matpro/ ','relap/  ','scdap/  ',
     & 'contmn/ ','visasrc/','rk3d/   '/)
       character, parameter :: chnm*6='$(NM)/'
$endif
       character makerp*16
       character, parameter :: astrks*8='********'
!
!  depenh   Holds pairs of *.obj-*.h file names from include statements.
!  depenm   Holds pairs of *.obj-*.mod file names from module
!           statements.
!  depenu   Holds pairs of *.obj-*.mod file names from use statements.
!  dotfd    Holds directory number of .ff files.
!  dotfls   Holds file name (not including directory name) of .ff files.
!  dothd    Holds directory number of .hh files.
!  dothls   Holds file name (not including directory name) of .hh files.
!  dotmd    
!  ndepen   Number of pairs of *.obj-*.hh file names (number of entries
!           in depenh).
!  ndepenm  Number of pairs of *.obj-*.mod file names (number of entries
!           in depenm).
!  ndepenu  Number of pairs of *.obj-*.mod file names (number of entries
!           in depenu).
!  ndepenhp Dimensioned limit for depenh.
!  ndepenmp Dimensioned limit for depenm.
!  ndepenup Dimensioned limit for depenu.
!  ndotfls  Number of source files.
!  nflflim  Dimensioned limit of number of .ff files.
!  nflhlim  Dimensioned limit of number of .hh files.
!
!  Get file name of prototype makefile from parameter included in the
!  command invoking this program.
       i = iargc()
       if (i .ne. 1) then
         write (error,"(a8,1x,'Parameter indicating prototype make file 
     &was not included in command line.')") astrks
         stop
       endif
       call getarg (1,makerp)
!  Read list of *.ff files from results of ls *.ff.
       fexist = .false.
       do i = 1,numdir
         inquire (file=filnmf(i),exist=tstf(i))
         fexist = fexist .or. tstf(i)
       enddo
       if (fexist) then
         ndotfls = 0
         do i = 1,numdir
           if (tstf(i)) then
             open (unit=work,file=filnmf(i),access='sequential',
     &       action='read',form='formatted',status='unknown')
             do
               read (work,"(a32)",iostat=j) dotfls(ndotfls+1)
               dotfd(ndotfls+1) = i
               if (j .gt. 0) then
                 write (error,"(a8,1x,a' filedotf file error.')")
     &           astrks,filnmf(i)
                 stop
               elseif (j .eq. 0) then
                 ndotfls = ndotfls + 1
                 if (ndotfls .ge. nflflim) then
                   write (error,"(a8,' Too many *.ff files.')") astrks
                   stop
                   exit
                 endif
               else
                 close (unit=work)
                 exit
               endif
             enddo
           endif
         enddo
         if (ndotfls .eq. 0) then
           write (error,"(a8,' No *.ff files.')") astrks
           stop
         endif
!  Sort list of files from ls *.ff into order.
         call qsortci (dotfls,dotfd,1,ndotfls)
         fexist = .false.
         do i = 2,ndotfls
           if (dotfls(i) .eq. dotfls(i-1)) then
             write (error,"(a8,' Duplicate *.ff files in directories:',
     &       2x,a,'.')")
     &       astrks,dotfls(i)
             fexist = .true.
           endif
         enddo
         if (fexist) stop
       else
         write (error,"(a8,' No files from ls *.ff commands exist.')")
     &   astrks
         stop
       endif
!  Read list of *.hh files from results of ls *.hh.
       fexist = .false.
       do i = 1,numdir
         inquire (file=filnmh(i),exist=tstf(i))
         fexist = fexist .or. tstf(i)
       enddo
       if (fexist) then
         ndothls = 0
         do i = 1,numdir
           if (tstf(i)) then
             open (unit=work,file=filnmh(i),access='sequential',
     &       action='read',form='formatted',status='unknown')
             do
               read (work,"(a32)",iostat=j) dothls(ndothls+1)
               dothd(ndothls+1) = i
               if (j .gt. 0) then
                 write (error,"(a8,' filedoth file error',i8,'.')")
     &           astrks
                 stop
               elseif (j .eq. 0) then
                 ndothls = ndothls + 1
                 if (ndothls .ge. nflhlim) then
                   write (error,"(a8,' Too many *.hh files.')") astrks
                   stop
                   exit
                 endif
               else
                 close (unit=work)
                 exit
               endif
             enddo
           endif
         enddo
!        if (ndothls .eq. 0) then
!          write (error,"(a8,' No *.hh files.')") astrks
!          stop
!        endif
!  Sort list of files from ls *.hh into order.
         call qsortci (dothls,dothd,1,ndothls)
         fexist = .false.
         do i = 2,ndothls
           if (dothls(i) .eq. dothls(i-1)) then
             write (error,"(a8,' Duplicate *.hh files in directories:',
     &       2x,a,'.')")
     &       astrks,dothls(i)
             fexist = .true.
           endif
         enddo
         if (fexist) stop
!  Set up for binary search.
         i = 1
         do
           ndoth2 = i
           i = i + i
           if (i .gt. ndothls) exit
         enddo
       else
         write (error,"(a8,' No files from ls *.hh commands exist.')")
     &   astrks
         stop
       endif
!
!  Read *.ff files and search for *call, include, use, or module
!  statements.
       ndepen = 0
       ndepem = 0
       ndepeu = 0
       ndothmk = 0
!      write (6,"('Search loop, depenf, depenn')")
       do i = 1,ndotfls
         depenf = trim(dirnm(dotfd(i))) // dotfls(i)
         open (unit=work,file=depenf,access='sequential',
     &   action='read',form='formatted',status='unknown',iostat=j)
         depenf = dotfls(i)
         j = index(depenf,'.') + 1
         depenf(j:j+2) = '$O'
         depenn = trim(dirnm(dotfd(i))) // depenf
!      write (6,"(2a40)") depenf,depenn
         do
           read (work,"(a80)",iostat=j) bcd(1:80)
           if (j .eq. 0) then
             j = scan(bcd(1:80),char(13))
             if (j .ne. 0) bcd(j:j) = ' '
             lcbcd = bcd
             call lwrcase (bcd(1:80),lcbcd(1:80))
             i2 = 0
             if (bcd(1:6) .eq. '*call ') then
!  Process *call statement by obtaining *.h file name.
               j = verify(bcd(7:80),' ')
               j = j + 6
               k = index(bcd(j:80),' ')
               k = j + k - 1
               dum = bcd(j:k-1) // '.h'
               dum2 = bcd(j:k-1) // '.hh'
               i2 = 1
             else
               j = verify(bcd(1:80),' ')
!      write (6,"('ZZZ',i5,3x,a80/11x,a80)") j,bcd(1:80),lcbcd(1:80)
               if (lcbcd(j:j+7) .eq. 'include ') then
!  Process include statement by extracting *.h file name.
                 n = verify(bcd(j+8:80),' ')
                 if (n .ne. 0) then
                   j = j + 7 + n
                   if (bcd(j:j).eq.'"' .or. bcd(j:j).eq."'") then
                     ch = bcd(j:j)
                     k = index(bcd(j+1:80),ch)
                     if (k .ne. 0) then
                       k = j + k
                       dum = bcd(j+1:k-1)
                       dum2 = bcd(j+1:k-2) // 'hh'
                       i2 = 1
                     endif
                   endif
                 endif
               elseif (lcbcd(j:j+3) .eq. 'use ') then
!!     write (6,"('use3',3x,a)") bcd
!  Process use statement by obtaining module name to be used.
                 n = verify(bcd(j+4:80),' ')
                 if (n .ne. 0) then
                   j = j + 3 + n
                   k = scan(bcd(j+1:80),' ,')
                   if (k .ne. 0) then
                     k = j + k - 1
                     dum = lcbcd(j:k) // '.mod'
!!     write (6,"('use4',3x,a)") dum
                     i2 = 2
                   endif
                 endif
               elseif (lcbcd(j:j+6).eq.'module ' .and.
     &         lcbcd(j:j+16).ne.'module procedure ') then
!      write (6,"('???',3x,a)") lcbcd
!  Process module statement by obtaining module name being defined.
                 n = verify(bcd(j+7:80),' ')
                 if (n .ne. 0) then
                   j = j + 6 + n
                   k = index(bcd(j+1:80),' ')
                   if (k .ne. 0) then
                     k = j + k - 1
                     dum = lcbcd(j:k) // '.mod'
                     idum = dotfd(i)
                     i2 = 3
                   endif
                 endif
               endif
             endif
!  Store derived pairs into proper tables.
             if (i2 .eq. 1) then
!  Store *.obj-*.h pairs derived from *call or include statements.
!  Check if *.hh file is in directory.
               fexist = .false.
               j = ndoth2
               k = j
               chk1: do
                 if (dum2 .eq. dothls(j)) then
                   fexist = .true.
                   exit chk1
                 else
                   tst = dum2 .lt. dothls(j)
                   do 
                     k = ishft(k,-1)
                     if (k .eq. 0) exit chk1
                     if (.not.tst) then
                       j = j + k
                       if (j .le. ndothls) cycle chk1
                       j = j - k
                       cycle
                     else
                       j = j - k
                       exit
                     endif
                   enddo
                 endif
               enddo chk1
               if (fexist) then
!  Indicated *.hh file is in directory, add pair to tables.
                 ndepen = ndepen + 1
                 if (ndepen .gt. ndepenhp) then
                   write (error,"(a8,' Too many *.obj-*.hh pairs from us
     &e statements.')") astrks
                   stop
                 endif
                 depenh(ndepen)%d = depenn
                 depenh(ndepen)%i = trim(dirnm(dothd(j))) // dum
!  Add *.hh file to list for new makefile if not already in list.
                 if (ndothmk .eq. 0) then
                   ndothmk = 1
                   ndoth2m = 1
                   dothmk(ndothmk) = dum2
                 else
                   fexist = .false.
                   j = ndoth2m
                   k = j
                   chk2: do
                     if (dum2 .eq. dothmk(j)) then
                       fexist = .true.
                       exit chk2
                     else
                       tst = dum2 .lt. dothmk(j)
                       do
                         k = ishft(k,-1)
                         if (k .eq. 0) exit chk2
                         if (.not.tst) then
                           j = j + k
                           if (j .le. ndothmk) cycle chk2
                           j = j - k
                           cycle
                         else
                           j = j - k
                           exit
                         endif
                       enddo
                     endif
                   enddo chk2
                   if (.not.fexist) then
!  *.hh file is not already in list; add it.
                     if (.not.tst) j = j + 1
                     do k = ndothmk,j,-1
                       dothmk(k+1) = dothmk(k)
                     enddo
                     dothmk(j) = dum2
                     ndothmk = ndothmk + 1
                     j = 1
                     do
                       ndoth2m = j
                       j = j + j
                       if (j .gt. ndothmk) exit
                     enddo
                   endif
                 endif
               endif
             elseif (i2 .eq. 2) then
!  Store *.obj-*.mod pairs derived from use statements.
               ndepeu = ndepeu + 1
               if (ndepeu .gt. ndepenup) then
                 write (error,"(a8,' Too many *.obj-*.mod pairs from use
     & statements.')") astrks
                 stop
               endif
               depenu(ndepeu)%d = depenn
               depenu(ndepeu)%i = dum
!!     write (error,"('use5 ',2a20)") depenu(ndepeu)
             elseif (i2 .eq. 3) then
!  Store *.mod-*.obj-*.ff sets derived from module statements.
               ndepem = ndepem + 1
               if (ndepem .gt. ndepenmp) then
                 write (error,"(a8,' Too many *.obj-*.mod pairs from mod
     &ule statements.')") astrks
                 stop
               endif
               depenm(ndepem)%d = dum
               depenm(ndepem)%i = depenn
               dotmd(ndepem) = idum
!!     write (error,"('use6 ',2a20,i5)") depenm(ndepem),dotmd(ndepem)
             endif
           else
             close (unit=work)
             exit
           endif
         enddo
       enddo
!
!  Sort *.obj-*.h table into makefile order.
       if (ndepen .ne. 0) then
         call qsortdep (depenh,1,ndepen)
!  Remove duplicate entry from *.obj-*.h table.
         n = 0
         i = 2
         do j = 2,ndepen
           if (depenh(j)%i.eq.depenh(i-1)%i .and.
     &     depenh(j)%d.eq.depenh(i-1)%d) then
             n = n + 1
           else
             if (n .ne. 0) depenh(i) = depenh(j)
             i = i + 1
           endif
         enddo
         ndepen = ndepen - n
       endif
!  Sort *.obj-*.mod table into makefile order.
       if (ndepeu .ne. 0) then
         call qsortdep (depenu,1,ndepeu)
!  Remove duplicate entry from *.obj-*.mod table.
         n = 0
         i = 2
         do j = 2,ndepeu
           if (depenu(j)%i.eq.depenu(i-1)%i .and.
     &     depenu(j)%d.eq.depenu(i-1)%d) then
             n = n + 1
           else
             if (n .ne. 0) depenu(i) = depenu(j)
             i = i + 1
           endif
         enddo
         ndepeu = ndepeu - n
       endif
!  Sort *.mod-*.obj table into reverse of makefile order for checking.
       if (ndepem .ne. 0) then
         call qsortdpi (depenm,dotmd,1,ndepem)
!  Check if duplicate module definitions.
         fexist = .false.
         do i = 2,ndepem
           if (depenm(i)%d .eq. depenm(i-1)%d) then
             fexist = .true.
             exit
           endif
         enddo
         if (fexist) then
           write (error,"(a8,' Duplicate definition of module, 'a32)")
     &     astrks,depenm(i)%d
           stop
         endif
       endif
!!     write (error,"('use7',i5,3x,2a40)") (i,depenm(i),i=1,ndepem) 
!  Eliminate references to modules not defined in *.ff files.
       n = 0
       i = 1
       l = 1
       do k = 1,ndepem
         fexist = .false.
         do j = l,ndepeu
           if (depenm(k)%d .eq. depenu(j)%i) then
             dotud(j) = dotmd(k)
             if (n .ne. 0) then
               depenu(i) = depenu(j)
               dotud(i) = dotud(j)
             endif
             i = i + 1
             l = j + 1
           else
             if (depenm(k)%d .gt. depenu(j)%i) then
               n = n + 1
               l = j + 1
             else
               l = j
               fexist = .true.
               exit
             endif
           endif
         enddo
         if (.not.fexist) exit
       enddo
       ndepeu = l - n - 1
!  Add directory name to file name of .mod file in *.obj-*.mod list.
       do i = 1,ndepeu
         dum = depenu(i)%i
         depenu(i)%i = chnm // dum
       enddo 
!  Add directory name to file name of .mod file in *.mod-*.obj list.
       do i = 1,ndepem
         dum = depenm(i)%d
         depenm(i)%d = chnm // dum
       enddo 
!  Sort *.obj-*.mod table into makefile order again due to directory
!  name addition.
       do i = 2,ndepem
         if (depenm(i)%i.lt.depenm(i-1)%i .or.
     &   (depenm(i)%i.eq.depenm(i-1)%i .and.
     &   depenm(i)%d.lt.depenm(i-1)%d)) then
           dumt = depenm(i)
           do j = i-1,1,-1
             depenm(j+1) = depenm(j)
             if (j .eq. 1) exit
             if (dumt%i.gt.depenm(j-1)%i .or.
     &       (dumt%i.eq.depenm(j-1)%i .and.
     &       dumt%d.gt.depenm(j-1)%d)) exit
           enddo
           depenm(j) = dumt
         endif
       enddo
!!     write (error,"('use8',i5,3x,2a40)") (i,depenm(i),i=1,ndepem)
!
!  Copy prototype makefile.up to comment, Makefle Targets.
       inquire (file=makerp,exist=fexist)
       if (.not.fexist) then
         write (error,"(a8,' Prototype makefile is missing.')") astrks
         stop
       else
         open (unit=makein,file=makerp,access='sequential',
     &   action='read',form='formatted',status='unknown')
         open (unit=makeout,file='makrelap',access='sequential',
     &   action='write',form='formatted',status='unknown')
       endif
       if (ndepem .ne. 0) then
         do
           read (makein,"(a80)",iostat=j) bcd
           if (j .ne. 0) then
             write (error,
     & "(a8,' Read error or improper end of file on makefile prototype.'
     & )") astrks
             stop
           else
             l = len_trim(bcd)
             write (makeout,"(a)") bcd(1:l)
             if (bcd(1:17) .eq. '#  Module Targets') exit
           endif
         enddo
!  Copy target rules for building modules.
         nrules = 0
         k2 = 0
         do
           read (makein,"(a80)",iostat=j) bcd
           if (j .ne. 0) then
             write (error,
     & "(a8,' Read error or improper end of file on makefile prototype.'
     & )") astrks
             stop
           endif
           if (bcd(1:72) .eq. ' ') exit
           if (bcd(1:7) .ne. '#  rule') then
             write (error,"(a8,' Line containing #  run was expected but
     & not read.')") astrks
             stop
           endif
           k2 = k2 + 1
           if (k2 .gt. 2) then
             write (error,"(a8,' Too many rules being entered.')")
     &       astrks
             stop
           endif
           tst = .false.
           do i = 1,40
             read (makein,"(a72)",iostat=j) rules(i,k2)
             if (j .ne. 0) then
               write (error,
     & "(a8,' Read error or improper end of file on makefile prototype.'
     & )")     astrks
               stop
             endif
             if (rules(i,k2)(1:72) .eq. ' ') then
               write (error,"(a8,' Blank line encountered in rule.')")
     &         astrks
             elseif (rules(i,k2)(1:10) .eq. '#  endrule') then
               nrules(k2) = i - 1
               tst = .true.
               exit
             endif
           enddo
           if (.not.tst) then
             write (error,"(a8,' In builerm, too many lines in a rule or
     & #  endrule does not terminate a rule.')") astrks
             stop
           endif
         enddo
         nrules(0) = k2
!  Write target rules for all modules and associated object files with
!  *.ff fies as prerequsites using *.mod-*.obj-*.ff tablei, one rule for
!  each module.
         i = 1
         do
           n = 0
           do k = 0,1
             if (k .eq. 0) then
               dum = depenm(i)%d
             else
               dum = depenm(i)%i
             endif
             l = len_trim(dum)
             if (k .eq. 0) then
               if (n + l .gt. 68) then
!!               bcd(n+1:n+1) = '\'  !  Replaced with statement below.
                 bcd(n+1:n+1) = char(92)
                 write (makeout,"(a)") bcd(1:n+1)
                 n = 0
               endif
               n1 = n + 1
               n = n1 + l
               bcd(n1:n) = trim(dum)
             endif
           enddo
           bcd(n+1:n+2) = ': '
           n = n + 2
           if (n + l .gt. 71) then
!            bcd(n+1:n+1) = '\'  !  Replaced with statement below.
             bcd(n+1:n+1) = char(92)
             write (makeout,"(a)") bcd(1:n+1)
             n = 0
           endif
           n1 = n + 1
           n = n + l
  
           if (dum(1:4) .eq. 'rk3d') then
             dum(l-1:l) = 'f9'
             k2 = 2
           else
             dum(l-1:l) = 'ff'
             k2 = 1
           endif
  
           bcd(n1:n) = trim(dum)
           write (makeout,"(a)") bcd(1:n)
           do j = 1,nrules(k2)
             l = len_trim(rules(j,k2))
             write (makeout,"(a)") rules(j,k2)(1:l)
           enddo
           i = i + 1
           if (i .gt. ndepem) exit
         enddo
       endif
!  Copy prototype lines unitl Dependency Definition line has been
!  read.
       do
         read (makein,"(a80)",iostat=j) bcd
         if (j .ne. 0) then
           write (error,
     & "(a8,' Read error or improper end of file on makefile prototype.'
     & )") astrks
           stop
         else
           l = len_trim(bcd)
           write (makeout,"(a)") bcd(1:l)
           if (bcd(1:25) .eq. '#  Dependency Definitions') exit
         endif
       enddo
!  Write target files for modules and object rules using .h files as 
!  prerequisites.
!  Set up for binary search used in writing *.h and *.mod dependencies.
       if (ndepem .ne. 0) then
         i = 1
         do
           ndoth2 = i
           i = i + i
           if (i .gt. ndepem) exit
         enddo
       endif
       if (ndepen .ne. 0) then
         i = 1
         do
           dum = depenh(i)%i
           do j = i+1,ndepen
             if (depenh(j)%i .ne. dum) exit
           enddo
           j = j - 1
           n = 0
           do k = i,j
             dum2 = depenh(k)%d
             do i2 = 0,1
               if (i2 .ne. 0) then
                 if (ndepem .eq. 0) exit
                 fexist = .false.
                 j2 = ndoth2
                 k2 = j2
                 chk3: do
                   if (dum2 .eq. depenm(j2)%i) then
                     fexist = .true.
                     exit chk3
                   else
                     tst = dum2 .lt. depenm(j2)%i
                     do
                       k2 = ishft(k2,-1)
                       if (k2 .eq. 0) exit chk3
                       if (.not.tst) then
                         j2 = j2 + k2
                         if (j2 .le. ndepem) cycle chk3
                         j2 = j2 - k2
                         cycle
                       else
                         j2 = j2 - k2
                         exit
                       endif
                     enddo
                   endif
                 enddo chk3
                 if (.not.fexist) cycle
                 dum2 = depenm(j2)%d
               endif
               l = len_trim(dum2)
               if (n + l .gt. 68) then
!              bcd(n+1:n+1) = '\'  !  Replaced with statement below.
                 bcd(n+1:n+1) = char(92)
                 write (makeout,"(a)") bcd(1:n+1)
                 n = 0
               endif
               n1 = n + 1
               n = n1 + l
               bcd(n1:n) = trim(dum2)
             enddo
           enddo
           bcd(n+1:n+2) = ': '
           n = n + 2
           l = len_trim(depenh(j)%i)
           if (n + l .gt. 71) then
!            bcd(n+1:n+1) = '\'  !  Replaced with statement below.
             bcd(n+1:n+1) = char(92)
             write (makeout,"(a)") bcd(1:n+1)
             n = 0
           endif
           n1 = n + 1
           n = n + l
           bcd(n1:n) = trim(depenh(j)%i)
           write (makeout,"(a)") bcd(1:n)
           i = j + 1
           if (i .gt. ndepen) exit
         enddo
       endif
!  Write target rules for modules and object files using .mod files as
!  prerequisites.
!!     write (error,"('Mod dependencies'/(i5,2a35))")
!!   & (i,depenu(i),i=1,ndepeu)
       if (ndepeu .ne. 0) then
         i = 1
         do
           dum = depenu(i)%i
           do j = i+1,ndepeu
             if (depenu(j)%i .ne. dum) exit
           enddo
           j = j - 1
           n = 0
           do k = i,j
             dum2 = depenu(k)%d
             do i2 = 0,1
               if (i2 .ne. 0) then
                 if (ndepem .eq. 0) exit
                 fexist = .false.
                 j2 = ndoth2
                 k2 = j2
                 chk4: do
                   if (dum2 .eq. depenm(j2)%i) then
                     fexist = .true.
                     exit chk4
                   else
                     tst = dum2 .lt. depenm(j2)%i
                     do
                       k2 = ishft(k2,-1)
                       if (k2 .eq. 0) exit chk4
                       if (.not.tst) then
                         j2 = j2 + k2
                         if (j2 .le. ndepem) cycle chk4
                         j2 = j2 - k2
                         cycle
                       else
                         j2 = j2 - k2
                         exit
                       endif
                     enddo
                   endif
                 enddo chk4
                 if (.not.fexist) cycle
                 dum2 = depenm(j2)%d
               endif
               l = len_trim(dum2)
               if (n + l .gt. 68) then
!                bcd(n+1:n+1) = '\'  !  Replaced with statement below.
                 bcd(n+1:n+1) = char(92)
                 write (makeout,"(a)") bcd(1:n+1)
                 n = 0
               endif
               n1 = n + 1
               n = n1 + l
               bcd(n1:n) = trim(dum2)
             enddo
           enddo
           bcd(n+1:n+2) = ': '
           n = n + 2
           l = len_trim(depenu(j)%i)
           if (n + l .gt. 71) then
!            bcd(n+1:n+1) = '\'  !  Replaced with statement below.
             bcd(n+1:n+1) = char(92)
             write (makeout,"(a)") bcd(1:n+1)
             n = 0
           endif
           n1 = n + 1
           n = n + l
           bcd(n1:n) = trim(depenu(j)%i)
           write (makeout,"(a)") bcd(1:n)
           i = j + 1
           if (i .gt. ndepeu) exit
         enddo
       endif
       stop
!
       contains
!
       subroutine lwrcase (mixedcase,lowercase)
!  Convert upper case alphabetic charactders to lower case.
!
       integer i
       character*80 mixedcase,lowercase
!
       lowercase = mixedcase
       do i = 1,80
         if (mixedcase(i:i).ge.'A' .and. mixedcase(i:i).le.'Z')  
     &   lowercase(i:i) = char(ichar(mixedcase(i:i)) + 32)
       enddo
       end subroutine lwrcase
!
       recursive subroutine qsortdep (dep,m1,m2)
!  Sorts an array, dep(m1:m2), of type depens using the quicksort
!  algorithm.
!
       implicit none
       integer m1,m2
       type (depens) dep(*)
!
       integer i1,i2
       logical mswap
!
!  Swap value at middle of array with value of first element of array.
       mswap = m2 - m1 .ge. 3
       i1 = (m1 + m2)/2
       if (mswap) then
         dumt = dep(i1)
         dep(i1) = dep(m1)
         dep(m1) = dumt
       endif
!  Initialize left and right pointers.
       i1 = m1 + 1
       i2 = m2
!  Move data such that data less than value now in first element is to
!  the left and data greater than that value is to the right.
       outer: do
!  Move left pointer to the right.
         do
           if (i1 .gt. i2) exit outer
           if (dep(i1)%i .gt. dep(m1)%i) exit
           if (dep(i1)%i .eq. dep(m1)%i) then
             if (dep(i1)%d .gt. dep(m1)%d) exit
           endif
           i1 = i1 + 1
         enddo
!  Move right pointer to the left.
         do
           if (i2 .lt. i1) exit outer
           if (dep(i2)%i .lt. dep(m1)%i) exit
           if (dep(i2)%i .eq. dep(m1)%i) then
             if (dep(i2)%d .lt. dep(m1)%d) exit
           endif
           i2 = i2 - 1
         enddo
         dumt = dep(i2)
         dep(i2) = dep(i1)
         dep(i1) = dumt
       enddo outer
!  Move data in first element to divide the left and right regions.
       dumt = dep(i2)
       dep(i2) = dep(m1)
       dep(m1) = dumt
!  Set up and call for recursive sorts of the two regions if necessary.
       i2 = i2 - 1
       if (i2 .gt. m1) call qsortdep (dep,m1,i2)
       if (m2 .gt. i1) call qsortdep (dep,i1,m2)
       return
       end subroutine qsortdep
!
       recursive subroutine qsortci (crv1,irv2,m1,m2)
!  Sorts an array, crv1(m1:m2) and carries an associated array using
!  the quicksort algorithm.
!
       implicit none
       integer m1,m2
       character(32) crv1(*)
       integer irv2(*)
!
       character(32) tem
       integer is
       integer i1,i2
       logical mswap
!
!  Swap value at middle of array with value of first element of array.
       mswap = m2 - m1 .ge. 3
       i1 = (m1 + m2)/2
       if (mswap) then
         tem = crv1(i1)
         crv1(i1) = crv1(m1)
         crv1(m1) = tem
         is = irv2(i1)
         irv2(i1) = irv2(m1)
         irv2(m1) = is
       endif
!  Initialize left and right pointers.
       i1 = m1 + 1
       i2 = m2
!  Move data such that data less than value now in first element is to
!  the left and data greater than that value is to the right.
       outer: do
!  Move left pointer to the right.
         do
           if (i1 .gt. i2) exit outer
           if (crv1(i1) .gt. crv1(m1)) exit
           if (crv1(i1) .eq. crv1(m1)) then
             if (i1 .gt. m1) exit
           endif 
           i1 = i1 + 1
         enddo
!  Move right pointer to the left.
         do
           if (i2 .lt. i1) exit outer
           if (crv1(i2) .lt. crv1(m1)) exit
           if (crv1(i2) .eq. crv1(m1)) then
             if (i2 .lt. m1) exit
           endif
           i2 = i2 - 1
         enddo
         tem = crv1(i2)
         crv1(i2) = crv1(i1)
         crv1(i1) = tem
         is = irv2(i2)
         irv2(i2) = irv2(i1)
         irv2(i1) = is
       enddo outer
!  Move data in first element to divide the left and right regions.
       tem = crv1(i2)
       crv1(i2) = crv1(m1)
       crv1(m1) = tem
       is = irv2(i2)
       irv2(i2) = irv2(m1)
       irv2(m1) = is
!  Set up and call for recursive sorts of the two regions if necessary.
       i2 = i2 - 1
       if (i2 .gt. m1) call qsortci (crv1,irv2,m1,i2)
       if (m2 .gt. i1) call qsortci (crv1,irv2,i1,m2)
       return
       end subroutine qsortci
!
       recursive subroutine qsortdpi (dep,irv2,m1,m2)
!  Sorts an array, dep(m1:m2), of type depens and an associated integer
!  array using the quicksort algorithm.
!
       implicit none
       integer m1,m2
       type (depens) dep(*)
       integer irv2(*)
!
       integer i1,i2
       integer is
       logical mswap
!
!  Swap value at middle of array with value of first element of array.
       mswap = m2 - m1 .ge. 3
       i1 = (m1 + m2)/2
       if (mswap) then
         dumt = dep(i1)
         dep(i1) = dep(m1)
         dep(m1) = dumt
         is = irv2(i1)
         irv2(i1) = irv2(m1)
         irv2(m1) = is
       endif
!  Initialize left and right pointers.
       i1 = m1 + 1
       i2 = m2
!  Move data such that data less than value now in first element is to
!  the left and data greater than that value is to the right.
       outer: do
!  Move left pointer to the right.
         do
           if (i1 .gt. i2) exit outer
           if (dep(i1)%d .gt. dep(m1)%d) exit
           if (dep(i1)%d .eq. dep(m1)%d) then
             if (dep(i1)%i .gt. dep(m1)%i) exit
           endif
           i1 = i1 + 1
         enddo
!  Move right pointer to the left.
         do
           if (i2 .lt. i1) exit outer
           if (dep(i2)%d .lt. dep(m1)%d) exit
           if (dep(i2)%d .eq. dep(m1)%d) then
             if (dep(i2)%i .lt. dep(m1)%i) exit
           endif
           i2 = i2 - 1
         enddo
         dumt = dep(i2)
         dep(i2) = dep(i1)
         dep(i1) = dumt
         is = irv2(i2)
         irv2(i2) = irv2(i1)
         irv2(i1) = is
       enddo outer
!  Move data in first element to divide the left and right regions.
       dumt = dep(i2)
       dep(i2) = dep(m1)
       dep(m1) = dumt
       is = irv2(i2)
       irv2(i2) = irv2(m1)
       irv2(m1) = is
!  Set up and call for recursive sorts of the two regions if necessary.
       i2 = i2 - 1
       if (i2 .gt. m1) call qsortdpi (dep,irv2,m1,i2)
       if (m2 .gt. i1) call qsortdpi (dep,irv2,i1,m2)
       return
       end subroutine qsortdpi
       end program builderm
$endif
