       program selectd
!  Program to delete options from a source file with each option being
!  able to be left in or deleted from the new source file.
!
       implicit none
!
       integer bufcn(100),i,ic,icl,iftbl(100),ifx,ihln(4),im,in,j,
     & jc,jcc,ncr,nd,nf,ni,nm,nstore,out,output,wd
       integer ifx8o
       logical chng,defio(100),ifdefc,ifdefn,iftbl6(100),iftbl7(100),
     & iftbl8(100),ifx6,ifx7,ifx8,ldef,lenif,lphlp,lphlpg,omito,omitn,
     & omitx
       character buf*96,bufh(100)*96,chnum*4,deftbl(100)*8,ihld(4)*8,
     & ihlde(2)*8,mesg(12)*36
!
       data in/5/, out/6/, output/1/
       data mesg/ ' ', 'unrecognizable !, * or $ line',
     & 'define line mispositioned',
     & 'incorrect define line',
     & 'too many define lines',
     & 'incorrect if line',
     & 'too many stacked if lines',
     & 'incorrect endif line',
     & 'col. 1 not blank, for ! insert',
     & 'if statement not nested',
     & 'endif not matched with if',
     & 'name in *call statement is too long'/
!
!  buf     Holds characters of current line being processed.
!  bufh    Array to hold lines that must be stored whenever if def lines
!          with count fields are active.
!  bufcn   Array corresponding to bufh; holds -1 if bufh holds other
!          than an if def with a count field; otherwise holds current
!          count field which is decremented as lines are omitted.
!  chng    If false, character processing is within a field; if true,
!          character processing is searching for next field.
!  defio   Array to determine if coding is to be included (true) or
!          deleted (false).
!  deftbl  Array to hold define names.
!  ic      Current character index in field.
!  icl     Number of characters left in field until full.
!  ifdefc  True if line is an if def with a count field, false
!          otherwise.
!  ifdefn  True if an if def with a count field is active, false
!          otherwise.
!  iftbl   Array for if def lines initially holding count of if idef
!          lines plus 1, and decremented as following lines are
!          processed.
!  iftbl6  Array for if def lines; false if line has a count field,
!          true if it does not.
!  iftbl7  Array for if def lines; false if define variable is
!          undefined, true if it is defined.
!  iftbl8  Array for if def lines; false if lines under control of if
!          are to be kept, true if they are to be deleted.
!  ifx     Count field of if def line plus 1.
!  ifx6    False if if def line has a count field, true if it does not.
!  ifx7    False if define variable is undefined, true if it is
!          defined.
!  ifx8    Initially defined false for if def, true for if -def. Then
!          edefined to be true if the lines under control of the if are
!          to be deleted, false otherwise.
!  ihld    Array to hold fields extracted during the processing of a
!          source input line.
!  ihlde   Array to hold fields from deck or comdeck lines for possible
!          diagnostic message.
!  ihln    Arrary to hold lengths of fields.
!  im      Number of diagnostic message to be issued.
!  in      Unit number for source input file.
!  j       Current character position in source line.
!  jc      Number of characters left in field being converted to integer
!          format.
!  jcc     Number of characters in line left to be processed.
!  ldef    Set true when define cards should no longer be encountered.
!  lenif   Set true when endif is being processed.
!  lphlp   Normally used to control exit from a do loop.
!  mesg    Array holding diagnostic messages.
!  ncr     Number of lines read.
!  nd      Number of define lines.
!  nf      Number of fields on a line.
!  ni      Number of if lines in stack.
!  nm      Number of diagnostic messages.
!  nstore  Number of lines storee in bufh.
!  omito   True if the current line is to be deleted.
!  omitn   True if the next line is to be deleted.
!  omitx   True if next line is normally deleted and the define
!          variable was entered.
!  out     Unit number for source output file.
!  output  Unit number for diagnostic message output file.
!  wd      Accumulates count for if lines.
!
!  Initialize.
       open (unit=output,file='fort.1',status='unknown')
       ldef = .false.
       nd = 0
       ni = 0
       ncr = 0
       nm = 0
       nstore = 0
       omito = .false.
       omitn = .false.
       ihlde(1) = ' '
       ihlde(2) = ' '
!  Read a line.
       do
         buf = ' '
         read (in,'(a)',end=220) buf
         ncr = ncr + 1
         im = 0
         ifdefc = .false.
         lenif = .false.
!  Check if !, $ or * line.
         if (buf(1:1).eq.'!' .or. buf(1:1).eq.'$' .or.
     &   buf(1:1).eq.'*') then
!  Break line into fields.
           lphlp = .false.
           nf = 1
           ihln(nf) = 0
           ihld(1) = ' '
           icl = 8
           j = 1
           jcc = 72
           chng = .false.
           do
             if (chng) then
               if (buf(j:j).eq.' ' .or. ichar(buf(j:j)).eq.13) go to 35
               if (buf(j:j) .eq. ',') then
                 lphlp = .true.
                 exit
               endif
               nf = nf + 1
               if (nf .gt. 4) then
                 lphlp = .true.
                 exit
               endif
               ihln(nf) = 0
               ihld(nf) = ' '
               chng = .false.
             else
               if (buf(j:j).eq.' ' .or. ichar(buf(j:j)).eq.13 .or.
     &         buf(j:j).eq.',') then
                 icl = 8
                 chng = .true.
                 go to 35
               endif
             endif
             icl = icl - 1
             if (icl .lt. 0) then
               lphlp = .true.
               exit
             endif
             ihln(nf) = ihln(nf) + 1
             ihld(nf)(ihln(nf):ihln(nf)) = buf(j:j)
   35        jcc = jcc - 1
             if (jcc .le. 0) exit
             j = j + 1
           enddo
!  Fields have been separated, now process different types of lines.
!  Check if [!*$]deck or [!*$]comdeck line.
           if (lphlp) then
           elseif (ihld(1)(2:8) .eq. 'deck' .or.
     &     ihld(1)(2:8) .eq. 'comdeck') then
             ihlde(1) = ihld(1)
             ihlde(2) = ihld(2)
!  Check if $define line.
           elseif (ihld(1)(2:8) .eq. 'define') then
             if (ldef) then
               im = 3
             elseif (nf .ne. 3) then
               im = 4
             elseif (nd .ge. 100) then
               im = 5
             elseif (ihld(3).ne.'on' .and. ihld(3).ne.'off') then
               im = 4
             else
               nd = nd + 1
               deftbl(nd) = ihld(2)
               buf(1:1) = '!'
               defio(nd) = .false.
               if (ihld(3) .eq. 'on') defio(nd) = .true.
               im = 1
               omito = .true.
               go to 200
             endif
!  Check if [!*$]call line.
           elseif (ihld(1) .eq. '*call') then
             ldef = .true.
             if (nf .ne. 2) then
               im = 12
             else
               buf = ' '
               buf(8:16) = 'include '''
               buf(17:24) = ihld(2)
               j = 16 + ihln(2)
               buf(j:j+2) = '.h'''
             endif
!  Check if $ctime line.
           elseif (ihld(1).eq.'$ctime' .or .ihld(1).eq.'$ntime') then
             ldef = .true.
             lphlp = .false.
             do i = 1,nd
               lphlp = deftbl(i) .eq. 'ctime   '
               if (lphlp) exit
             enddo
             if (lphlp) then
               if (ihld(1) .ne. '$ntime   ') then
                 buf(1:10) = 'cdir$ flow'
               else
                 buf(1:12) = 'cdir$ noflow'
               endif
             endif
!  Check if *if or $if line.
           elseif (ihld(1)(2:8) .eq. 'if') then
             ldef = .true.
             omitx = .false.
             if (nf .le. 2) then
               im = 6
             else
               lphlpg = .false.
               ifx = 0
               ifx8 = .false.
               if (ihld(2) .ne. 'def') then
                 if (ihld(2) .ne. '-def') then
                   im = 6
                   lphlpg = .true.
                 else
                   ifx8 = .true.
                 endif
               endif
               ifx8o = ifx8
               if (.not.lphlpg) then
                 lphlp = .true.
                 do i = 1,nd
                   lphlp = deftbl(i) .ne. ihld(3)
                   if (.not.lphlp) exit
                 enddo
                 if (lphlp) then
                   ifx7 = .false.
                   ifx8 = .false.
                   omitx = omito
                 else
                   omito = .true.
                   ifx7 = .true.
                   ifx8 = ifx8 .neqv. .not.defio(i)
                   omitx = ifx8 .and. .not.defio(i)
                 endif
                 if (nf .eq. 3) then
                   ifx6 = .true.
                 elseif (nf .ne. 4) then
                   im = 6
                   lphlpg = .true.
                 else
                   ifx6 = .false.
                   ifdefc = .true.
                   wd = 0
                   jc = 8
                   j = 0
                   do
                     j = j + 1
                     if (ihld(4)(j:j).eq.' ' .or.
     &               ichar(ihld(4)(j:j)).eq.13) exit
                     if (ihld(4)(j:j).lt.'0' .or. ihld(4)(j:j).gt.'9')
     &               then
                       im = 6
                       lphlpg = .true.
                       exit
                     else
                       wd = wd*10 + ichar(ihld(4)(j:j)) - ichar('0')
                       jc = jc - 1
                       if (jc .le. 0) exit
                     endif
                   enddo
                   if (.not.lphlpg) then
                     if (wd .gt. 100) then
                       im = 6
                       lphlpg = .true.
                     else
                       ifx = wd + 1
                       do i = 1,ni
                         if (.not.iftbl6(i) .and. iftbl(i).le.wd) then
                           im = 10
                           if (ni .lt. 100) exit
                           im = 7
                           lphlpg = .true.
                           exit
                         endif
                       enddo
                     endif
                   endif
                 endif
                 if (.not.lphlpg) then
                   ni = ni + 1
                   iftbl(ni) = ifx
                   iftbl6(ni) = ifx6
                   iftbl7(ni) = ifx7
                   iftbl8(ni) = ifx8
                   omitn = omitx .or. ifx8
c      write (6,"('###',3x,a30,3x,2i5,8l5)") buf(1:30),ni,iftbl(ni),
c    & iftbl6(ni),iftbl7(ni),iftbl8(ni),omito,omitn,omitx,ifx8o,defio(i)
                 endif
               endif
             endif
!  Check if *endif or $endif line.
           elseif (ihld(1)(2:8) .eq. 'endif') then
             if (nf .ne. 1) then
               im = 8
             else
               lenif = .true.
             endif
           endif
         endif
!  Delete any exhausted if's from table.
         chng = .false.
         ifdefn = .false.
         if (ni .ne. 0) then
           wd = 0
           do i = 1,ni
             if (.not.iftbl6(i)) then
               iftbl(i) = iftbl(i) - 1
               if (iftbl(i) .eq. 0) then
                 chng = .true.
                 cycle
               endif
               ifdefn = .true.
             endif
             wd = wd + 1
             if (chng) then
               iftbl(wd) = iftbl(i)
               iftbl6(wd) = iftbl6(i)
               iftbl8(wd) = iftbl8(i)
             endif
           enddo
           ni = wd
         endif
         if (lenif) then
           if (ni .eq. 0) then
             lphlp = .false.
           else
             lphlp = .true.
             if (.not.iftbl6(ni)) then
               wd = ni
               lphlp = .false.
               do i = 1,ni
                 if (iftbl6(wd)) then
                   lphlp = .true.
                   exit
                 endif
                 wd = wd - 1
               enddo
               if (lphlp) then
                 ic = ni - 1
                 do i = wd,ic
                   iftbl(wd) = iftbl(wd+1)
                   iftbl6(wd) = iftbl6(wd+1)
                   iftbl8(wd) = iftbl8(wd+1)
                 enddo
                 im = 10
               endif
             else
               if (iftbl7(ni)) omito = .true.
             endif
             ni = ni - 1
             chng = .true.
           endif
           if (.not.lphlp) im = 11
         endif
         if (chng) then
           omitn = .false.
           do i = 1,ni
             omitn = omitn .or. iftbl8(i)
           enddo
         endif
!  Decrement count field of stored if def lines with a count field and
!  line is being deleted.
  200    if (omito .and. nstore.ne.0) then
           do i = 1,nstore
             if (bufcn(i) .gt. 0) bufcn(i) = bufcn(i) - 1
           enddo
         endif
         if (ifdefn) then
           if (.not.omito) then
!  If line must be written but a if def with a count field is active,
!  line must be temporarily stored.
             nstore = nstore + 1
             bufh(nstore) = buf
             if (ifdefc) then
               bufcn(nstore) = iftbl(ni)
             else
               bufcn(nstore) = -1
             endif
           endif
         else
!  No if def lines with count fields are active, writes can take place.
!  Write out any stored lines.
           do i = 1,nstore
             if (bufcn(i) .ne. -1) then
               icl = len_trim(bufh(i))
               ic = scan(bufh(i)(1:icl),' ,',.true.) + 1
               bufh(i)(ic:icl) = ' '
               write (chnum,"(i4)") bufcn(i)
               bufh(i)(ic:icl) = adjustl(chnum)
             endif
             write (out,'(a)') bufh(i)
             nstore = 0
           enddo
!  Write current line.
           if (.not.omito) write (out,'(a)') buf
         endif
!  Write diagnostic message for line if error has been detected.
         if (im .gt. 1) then
           if (im .ne. 0) then 
             if (nm.eq.0 .and. ihlde(1).ne.' ') write (output,"(' select
     &: ',a8,1x,a8)") ihlde
             nm = nm + 1
           endif
           write (output,"(' ',i6,':  ',a,3x,a)") ncr,buf,mesg(im)
         endif
         omito = omitn
       enddo
!  Finish up.
  220  if (ni .ne. 0) then
         if (nm.eq.0 .and. ihlde(1).ne.' ') write (output,"(' select: ',
     & a8,1x,a8)") ihlde
         write (output,"(' E O F',88x,'unsatisfied $if lines remain')")
         nm = nm + 1
       endif
       if (nm .ne. 0) write (output,"('0Number of lines processed =',i8,
     & ', Number of error messages =',i8,'.')") ncr,nm
       end program selectd
