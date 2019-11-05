       program select
!  Program to select options from compile file.
!
       integer in,out,output,wd,ifx,idx,ihln(4),iftbl(100)
       logical ldef,lenif,chng,omito,omitn,ifx6,ifx8,idx8,
     & iftbl6(100),iftbl8(100)
       character buf*96,mesg(12)*36,ihld(4)*8,ihlde(2)*8,deftbl(100)*8
!
       data in/5/, out/6/, output/1/
       data mesg/ ' ', 'unrecognizable * or $ card',
     & 'define card mispositioned',
     & 'incorrect define card',
     & 'too many define cards',
     & 'incorrect if card',
     & 'too many stacked if cards',
     & 'incorrect endif card',
     & 'col. 1 not blank, for * insert',
     & 'if statement not nested',
     & 'endif not matched with if',
     & 'name in *call statement is too long'/
!  Initialize.
       open (unit=output,file='fort.1',status='unknown')
       ldef = .false.
       nd = 0
       ni = 0
       ncr = 0
       nm = 0
       omito = .false.
       omitn = .false.
       ihlde(1) = ' '
       ihlde(2) = ' '
!  Read a card.
   10  buf = ' '
       read (in,'(a)',end=220) buf
       ncr = ncr + 1
       im = 0
       lenif = .false.
!  Check if $ card.
       if (buf(1:1).ne.'$' .and. buf(1:1).ne.'*') go to 135
!  Break card into fields.
       nf = 1
       ihld(1) = ' '
       icl = 8
       ic = 0
       j = 1
       jcc = 72
       chng = .false.
   20  if (chng) then
         if (buf(j:j).eq.' ' .or. ichar(buf(j:j)).eq.13) go to 35
         if (buf(j:j) .eq. ',') go to 118
         nf = nf + 1
         if (nf .gt. 4) go to 118
         ihld(nf) = ' '
         chng = .false.
       else
         if (buf(j:j).eq.' ' .or. ichar(buf(j:j)).eq.13 .or.
     &   buf(j:j).eq.',') go to 30
       endif
       icl = icl - 1
       if (icl .lt. 0) go to 118
       ic = ic + 1
       ihld(nf)(ic:ic) = buf(j:j)
       go to 35
   30  ihln(nf) = ic
       icl = 8
       ic = 0
       chng = .true.
   35  jcc = jcc - 1
       if (jcc .gt. 0) go to 36
       if (.not.chng) go to 30
       go to 39
   36  j = j + 1
       go to 20
!  Check if *deck or *comdeck card.
   39  if (ihld(1)(2:8) .eq. 'deck' .or. ihld(1)(2:8) .eq. 'comdeck')
     & then
         ihlde(1) = ihld(1)
         ihlde(2) = ihld(2)
         go to 135
       endif
!  Check if $define card.
       if (ihld(1)(2:8) .ne. 'define') go to 46
       if (.not.ldef) go to 40
       im = 3
       go to 135
   40  if (nf .eq. 2) go to 45
       im = 4
       go to 135
   45  if (nd .lt. 100) go to 50
       im = 5
       go to 135
   50  nd = nd + 1
       deftbl(nd) = ihld(2)
       buf(1:1) = '!'
       im = 1
       go to 200
   46  if (ihld(1) .ne. '*call') go to 55
       if (nf .eq. 2) go to 47
       im = 12
       go to 135
   47  buf = ' '
       buf(7:15) = 'include '''
       buf(16:23) = ihld(2)
       j = 16 + ihln(2)
       buf(j:j+2) = '.h'''
       go to 135
!  Check if $ctime card.
   55  ldef = .true.
       if (ihld(1).ne.'$ctime' .and .ihld(1).ne.'$ntime')
     & go to 56
       if ( nd .eq. 0 ) go to 130
       do i = 1,nd
         if (deftbl(i) .eq. 'ctime   ') go to 58
       enddo
       go to 130
   58  if (ihld(1) .eq. '$ntime   ') go to 59
       buf(1:10) = 'cdir$ flow'
       go to 145
   59  buf(1:12) = 'cdir$ noflow'
       go to 145
!  Check if *if or $if card.
   56  if (ihld(1)(2:8) .ne. 'if') go to 115
       if (nf .le. 2) go to 87
       ifx = 0
       ifx6 = .false.
       ifx8 = .false.
       if (ihld(2) .eq. 'def') go to 60
       if (ihld(2) .ne. '-def') go to 87
       ifx8 = .true.
   60  idx = 0
       idx8 = .false.
       if (nd .eq. 0) go to 70
       do i = 1,nd
         if (deftbl(i) .eq. ihld(3)) go to 75
       enddo
   70  idx8 = .true.
   75  ifx8 = ifx8 .neqv. idx8
       if (nf .gt. 3) go to 80
       ifx6 = .true.
       go to 100
   80  if (nf .ne. 4) go to 87
       wd = 0
       jc = 8
       j = 0
   85  j = j + 1
       if (ihld(4)(j:j).eq.' ' .or. ichar(ihld(4)(j:j)).eq.13) go to 95
       if (ihld(4)(j:j).ge.'0' .and. ihld(4)(j:j).le.'9') go to 90
   87  im = 6
       go to 135
   90  wd = wd*10 + ichar(ihld(4)(j:j)) - ichar('0')
       jc = jc - 1
       if (jc .gt. 0) go to 85
   95  if (wd .gt. 4094) go to 87
       ifx = wd + 1
       if (ni .eq. 0) go to 105
       do i = 1,ni
         if (.not.iftbl6(i) .and. iftbl(i).le.wd) then
           im = 10
           go to 100
         endif
       enddo
  100  if (ni .lt. 100) go to 105
       im = 7
       go to 135
  105  ni = ni + 1
       iftbl(ni) = ifx
       iftbl6(ni) = ifx6
       iftbl8(ni) = ifx8
       omitn = omito .or. ifx8
       go to 130
!  Check if *endif or $endif card.
  115  if (ihld(1)(2:8) .eq. 'endif') go to 120
  118  if (buf(1:1) .eq. '*') go to 135
       im = 2
       go to 135
  120  if (nf .eq. 1) go to 125
       im = 8
       go to 135
  125  lenif = .true.
!  Change $ to * on acceptable $ cards.
  130  buf(1:1) = '!'
       if (im .eq. 0) im = 1
       go to 145
!  Set * in column 1 of card if omit flag is on.
  135  ldef = .true.
       if (omito) then
         if (buf(1:1) .ne. '*') then
           if (buf(1:1).eq.'c' .or. buf(1:1).eq.'!') then
             if (buf(2:5) .eq. '$par') then
               buf(2:5) = 'cpar'
             elseif (buf(2:5).eq.'dec$' .or. buf(2:5).eq.'DEC$' .or.
     &       buf(2:5).eq.'$omp' .or. buf(2:5).eq.'$OMP') then
               buf(2:5) = '***$'
             endif
           elseif (buf(1:1).ne.' ') then
             im = 9
           endif
           buf(1:1) = '!'
         endif
       endif
!  Delete any exhausted if's from table.
  145  chng = .false.
       if (ni .eq. 0) go to 160
       wd = 0
       do 155 i = 1,ni
         if (iftbl6(i)) go to 150
         iftbl(i) = iftbl(i) - 1
         if (iftbl(i) .ne. 0) go to 150
         chng = .true.
         go to 155
  150    wd = wd + 1
         if (chng) then
           iftbl(wd) = iftbl(i)
           iftbl6(wd) = iftbl6(i)
           iftbl8(wd) = iftbl8(i)
         endif
  155  continue
       ni = wd
  160  if (.not.lenif) go to 190
       if (ni .eq. 0) go to 170
       if (iftbl6(ni)) go to 185
       wd = ni
       do i = 1,ni
         if (iftbl6(wd)) go to 175
         wd = wd - 1
       enddo
  170  im = 11
       go to 190
  175  ic = ni - 1
       do i = wd,ic
         iftbl(wd) = iftbl(wd+1)
         iftbl6(wd) = iftbl6(wd+1)
         iftbl8(wd) = iftbl8(wd+1)
       enddo
       im = 10
  185  ni = ni - 1
       chng = .true.
  190  if (.not.chng) go to 200
       omitn = .false.
       if (ni .eq. 0) go to 200
       do i = 1,ni
         omitn = omitn .or. iftbl8(i)
       enddo
!  Write card.
  200  write (out,'(a)') buf
!  Print legal $ card or error message if needed.
!  Note: Two if tests on im follow; use first if statement if prinout of
!  control cards is desired, use second if statement otherwise. Unused
!  statement has cc in col 1-2.
!  Erroneous cards always printout.
cc     if (im .ge. 1) then
       if (im .gt. 1) then
         if (im .ne. 0) then 
           if (nm.eq.0 .and. ihlde(1).ne.' ') write (output,1000) ihlde
 1000  format (' select: ',a8,1x,a8)
           nm = nm + 1
         endif
         write (output,1002) ncr,buf,mesg(im)
 1002  format (' ',i6,':  ',a,3x,a)
       endif
       omito = omitn
       go to 10
!  Finish up.
  220  if (ni .ne. 0) then
         if (nm.eq.0 .and. ihlde(1).ne.' ') write (output,1000) ihlde
         write (output,1004)
 1004  format (' E O F',88x,'unsatisfied $if cards remain')
         nm = nm + 1
       endif
       if (nm .ne. 0) write (output,1003) ncr,nm
 1003  format ('0Number of cards processed =',i8,', Number of error mess
     &ages =',i8,'.')
       end
