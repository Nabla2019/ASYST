       program cnv32
c  Program to convert from 64 bit to 32 bit computers.
c
       parameter (nmodx=1024)
       character buf*72,bufe*72,bufo*120,modv(nmodx)*8,var*16,varh*8,
     & tvar*12,ins*2,quotch*1
       equivalence (varh,var)
       logical bs,bs2,bsd,bsi,cskp,dk1,dk2,eset,in32,modc,mlstpr,per,
     & quot,quot2,skp,tst,
     & wr
       integer i,in,is1,is2,isv,j,nbl,out,output
c
       data in/5/,out/6/,output/2/,mlist/8/
c
       dk1 = .true.
       dk2 = .true.
       in32 = .false.
       open (unit=output,file='fort.2',status='unknown')
       mlstpr = .false.
    1  nmod = 0
       bs2 = .true.
       if (.not.mlstpr) go to 40
       rewind mlist
    2  nmod = nmod + 1
       if (nmod .gt. nmodx) go to 301
       read (mlist,'(a)',end=3) modv(nmod)
       do i = 1,8
         if (ichar(modv(nmod)(i:i)) .eq. 13) then
           modv(nmod)(i:i) = ' '
           exit
         endif
       enddo
       go to 2
  301  write (output,1011) nmodx - 1
 1011  format ('0******** Too many variables in mlist file or *in32 card
     &s, limit is',i6)
       stop 'trouble'
    3  nmod = nmod - 1
   40  i = 1
    4  nmods2 = i
       i = i + i
       if (i .le. nmod) go to 4
c  Sort variables into increasing order, writing messages if not
c  already in order or duplicate variables.
       if (nmod .gt. 1) then
         bsi = .false.
         bsd = .false.
         do i = 2,nmod
           if (modv(i) .lt. modv(i-1)) then
             varh = modv(i)
             j = i - 1
             bsi = .true.
    6        modv(j+1) = modv(j)
             j = j - 1
             if (j .ne. 0) then
               if (varh .lt. modv(j)) go to 6
             endif
             modv(j+1) = varh
           else
             bsd = bsd .or. modv(i) .eq. modv(i-1)
           endif
         enddo
         if (bsi .and. bs2) write (output,1003)
 1003  format (' ******** Variables not in ascending order.')
         if (bsd) write (output,1004)
 1004  format (' ******** Duplicate variables.')
       endif
       if (.not.bs2) go to 11
       bs2 = .false.
c  Set up.
       ins = '2,'
       bs = .true.
       skp = .false.
       quot = .false.
       quot2 = .false.
       lc = 0
       nm = 0
       nw = 0
c  Read a statement.
   10  buf = ' '
       read (in,'(a)',end=200) buf
       do i = 1,72
         if (ichar(buf(i:i)) .eq. 13) then
           do j = i,72
             buf(j:j) = ' '
           enddo
           exit
         endif
       enddo
       lc = lc + 1
c  Check if local variables are entered.
       if (buf(1:1).eq.'*' .or. buf(1:1).eq.'!') then
         if (buf(2:7) .eq. 'mlist ') then
           inquire (file='auxx/mlist',exist=mlstpr)
           if (mlstpr) then
             open (mlist,file='auxx/mlist',status='old')
             go to 1
           endif
         elseif (buf(2:6) .eq. 'in32 ') then
           nmod = nmod + 1
           if (nmod .gt. nmodx) go to 301
           modv(nmod) = buf(7:14)
           go to 11
         elseif (buf(2:8) .eq. 'in32end') then
           go to 40
         elseif (buf(2:5).eq.'deck' .or. buf(2:8).eq.'comdeck') then
           bufe = buf
           if (dk1) then
             dk1 = .false.
           else
             dk2 = .false.
           endif
         elseif (buf(2:8) .eq. 'define ') then
           do i = 9,68
             if (buf(i:i) .ne. ' ') go to 8
           enddo
           go to 11
    8      if (buf(i:i+3) .eq. 'in32') in32 = .true.
         endif
         go to 11
       endif
c  Skip if comment line.
       if (buf(1:1).eq.'c' .or. buf(1:1).eq.'!') go to 11
c  Skip if blank line.
       cskp = .false.
       modc = .false.
       wr = .false.
       if (buf .eq. ' ') go to 12
       tst = buf(6:6).eq.' ' .or. buf(6:6).eq.'0'
       if (bs) then
         if (.not.tst) wr = .true.
       else
         if (tst) then
           ins = '2,'
           bs = .true.
           skp = .false.
           quot = .false.
           quot2 = .false.
         endif
       endif
       if (.not.skp) then
         per = .false.
         is1 = 1
         is2 = 1
         i = 7
c  Skip over blanks.
   14    if (buf(i:i) .eq. ' ') go to 13
c  Finish quot delimited character field.
         if (quot) then
           if (buf(i:i) .eq. quotch) then
             if (quot2) then
               quot2 = .false.
             else
               quot2 = .true.
             endif
             go to 13
           else
             if (quot2) then
               quot = .false.
             else
               go to 13
             endif
           endif
         endif
c  Alphabetic character handling.
         if (buf(i:i).ge.'a' .and. buf(i:i).le.'z') then
           if (cskp) go to 13
           ic = 1
           var = buf(i:i)
   16      if (i .ge. 72) go to 28
           i = i + 1
           if (buf(i:i) .eq. ' ') go to 16
           if ((buf(i:i).ge.'a' .and. buf(i:i).le.'z') .or.
     &     (buf(i:i).ge.'0' .and. buf(i:i).le.'9')) then
             ic = ic + 1
             if (ic .gt. 16) then
               cskp = .true.
               go to 13
             endif
             var(ic:ic) = buf(i:i)
             if (ic .eq. 4) im = i
             go to 16
           endif
   28      if (bs) then
             bs = .false.
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
c  Include this coding only for Sun compilers if it is desired to have
c  implicit none converted to implicit undefined(a-z).
*if def,sun,5
*            if (var(1:12) .eq. 'implicitnone') then
*              buf(1:30) = '       implicit undefined(a-z)'
*              i = 30
*              go to 55
*            endif
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
             if (var(1:6).eq.'format' .or. var(1:7).eq.'program' .or.
     &       var(1:9).eq.'character' .or. var(1:8).eq.'implicit' .or.
     &       var(1:8).eq.'external') then
               skp = .true.
               go to 11
             elseif (var(1:7).eq.'integer' .or. var(1:7).eq.'logical')
     &       then
               tvar = var(8:16)
               var = tvar
               go to 17
             elseif (var(1:4) .eq. 'real') then
               skp = .true.
               if (ic .eq. 4) go to 11
               bufo(1:im) = buf(1:im)
               is1 = im + 1
               is2 = is1 + 2
               bufo(is1:is1+1) = '*8'
               bufo(is2:120) = ' '
               modc = .true.
               go to 19
             elseif (var .eq. 'equivalence') then
               ins = '1,'
               go to 13
             elseif (var .eq. 'dimension') then
               tvar = var(10:16)
               var = tvar
               go to 17
             elseif (var.eq.'end' .and. i.eq.72) then
               dk2 = .false.
               go to 11
             endif
           endif
   17      if (buf(i:i) .eq. '.') then
             if (per) then
               per = .false.
               go to 13
             endif
           elseif (buf(i:i).eq.'(' .or. buf(i:i).eq.'[' .or.
     &     buf(i:i).eq.'{' .or. buf(i:i).eq.'<') then
             if (nmod .eq. 0) go to 13
             j = nmods2
             ir = j
   30        if (varh .eq. modv(j)) go to 15
             tst = varh .lt. modv(j)
   31        ir = ir/2
             if (ir .eq. 0) go to 13
             if (tst) go to 32
             j = j + ir
             if (j .le. nmod) go to 30
             j = j - ir
             go to 31
   32        j = j - ir
             go to 30
   15        if (.not.modc) bufo = ' '
             j = i - is1 + is2
             bufo(is2:j) = buf(is1:i)
             is1 = i + 1
             is2 = j + 1
             if (buf(i:i) .eq. '(') then
               bufo(is2:is2+1) = ins
             elseif (buf(i:i) .eq. '{') then
               bufo(is2-1:is2+1) = '(:,'
               buf(i:i) = '('
             elseif (buf(i:i) .eq. '<') then
               bufo(is2-1:is2+3) = '(1:2,'
               buf(i:i) = '('
               is2 = is2 + 2
             else
               bufo(is2-1:is2+1) = '(1,'
               buf(i:i) = '('
             endif
             is2 = is2 + 2
             modc = .true.
             go to 13
           endif
           go to 13
c  Number character processing.
         elseif (buf(i:i).ge.'0' .and. buf(i:i).le.'9') then
           if (cskp) go to 13
           eset = .false.
           isv = 0
   26      nbl = 0
   23      if (i .ge. 72) go to 24
           i = i + 1
           if (buf(i:i) .eq. ' ') then
             nbl = nbl + 1
             go to 23
           endif
           if (buf(i:i).ge.'0' .and. buf(i:i).le.'9') then
             nbl = 0
             go to 23
           endif
           if (buf(i:i) .eq. 'e') then
             if (eset) go to 12
             eset = .true.
             if (.not.modc) bufo = ' '
             j = i - is1 + is2
             bufo(is2:j-1) = buf(is1:i-1)
             bufo(j:j) = 'd'
             isv = j
             is1 = i + 1
             is2 = j + 1
             modc = .true.
             per = .false.
             go to 23
           elseif (buf(i:i) .eq. '.') then
             if (per) go to 29
             per = .true.
             nbl = 0
   25        if (i .ge. 72) go to 24
             i = i + 1
             if (buf(i:i) .eq. ' ') then
               nbl = nbl + 1
               go to 25
             endif
             if (buf(i:i).ge.'0' .and. buf(i:i).le.'9') go to 26
             if (buf(i:i) .eq. 'e') then
   27          if (i .ge. 72) then
                 wr = .true.
                 go to 12
               endif
               i = i + 1
               if (buf(i:i) .eq. ' ') go to 27
               if ((buf(i:i).ge.'0' .and. buf(i:i).le.'9') .or.
     &         buf(i:i).eq.'+' .or. buf(i:i).eq.'-') then
                 if (.not.modc) bufo = ' '
                 j = i - is1 + is2
                 isv = j - 1
                 bufo(is2:isv) = buf(is1:i-1)
                 bufo(isv:isv) = 'd'
                 bufo(j:j) = buf(i:i)
                 is1 = i + 1
                 is2 = j + 1
                 modc = .true.
                 per = .false.
                 go to 23
               elseif (buf(i:i) .eq. '_') then
                 if (isv .ne. 0) bufo(isv:isv) = 'e'
                 per = .false.
                 cskp = .true.
                 go to 13
               else
                 go to 13
               endif
             else
               if (buf(i:i) .eq. '.') then
                 i = i - nbl
                 nbl = 0
               elseif (buf(i:i).ge.'a' .and. buf(i:i).le.'z') then
                 go to 13
               endif
             endif
           elseif (buf(i:i) .eq. '_') then
             if (isv .ne. 0) bufo(isv:isv) = 'e'
             per = .false.
             cskp = .true.
             go to 13
           endif
   29      i = i - 1
   24      if (.not.per) go to 13
           per = .false.
           if (.not.modc) bufo = ' '
           j = i - is1 + is2 - nbl
           bufo(is2:j) = buf(is1:i-nbl)
           bufo(j+1:j+2) = 'd0'
           is1 = i + 1
           is2 = j + 3
           modc = .true.
           go to 13
c  Non-alphanumeric character processing.
         else
           cskp = .false.
           if (buf(i:i) .eq. '.') then
             if (per) then
               per = .false.
             else
               per = .true.
             endif
           elseif (buf(i:i).eq.'''' .or. buf(i:i).eq.'"') then
             quotch = buf(i:i)
             quot = .true.
             quot2 = .false.
           endif
         endif
   13    if (i .ge. 72) go to 19
         i = i + 1
         go to 14
       endif
   19  if (.not.wr) go to 18
   12  if (nw.eq.0 .and. bufe.ne.' ') write (output,'('' cnv32: '',a)')
     & bufe
       write (output,'('' '',a)') buf
       nw = nw + 1
   18  if (.not.modc) go to 11
       nm = nm + 1
       if (.not.in32) go to 11
       if (is1 .ne. 73) then
         j = 72 - is1 + is2
         bufo(is2:j) = buf(is1:72)
       endif
       is2 = 120
       do i = 1,48
         if (bufo(is2:is2) .ne. ' ') go to 21
         is2 = is2 - 1
       enddo
   21  do i = 72,2,-1
         if (bufo(i:i) .ne. ' ') go to 51
       enddo
       i = 1
c  Two write statements appear here and with other write statements
c  concerning file 'out'.  The Masscomp version requires an extra blank
c  at the beginning of a line.  One of the two statements should be
c  commented out.
*if -def,mass,1
   51  write (out,'(a)') bufo(1:i)
*if def,mass,1
*  51  write (out,'('' '',a)') bufo(1:i)
       if (is2 .gt. 72) then
         do i = 120,74,-1
           if (bufo(i:i) .ne. ' ') go to 53
         enddo
         i = 73
   53    write (out,1002) bufo(73:i)
*if -def,mass,1
 1002  format (5x,'#',a)
*if def,mass,1
*1002  format (' ',5x,'#',a)
       endif
       go to 10
   11  do i = 72,1,-1
         if (buf(i:i) .ne. ' ') go to 55
       enddo
       i = 1
*if -def,mass,1
   55  write (out,'(a)') buf(1:i)
*if def,mass,1
*  55  write (out,'('' '',a)') buf(1:i)
       if (dk2) go to 10
       dk2 = .true.
       go to 1
c
  200  if (nw .ne. 0) write (output,1001) lc,nm,nw
 1001  format ('0Number of lines processed =',i6/
     & ' number of lines converted =',i6/
     & ' number of warning lines printed =',i6)
       end
