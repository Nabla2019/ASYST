*deck usplit
       program usplit  
c  program to split update source into *.F files.
c
       integer cend,in,out,output,ihln(2)
       logical chng,once,skipo
       character buf*80,ihld(2)*12,file*14,filen*14
c
       data cend/72/, in/5/, out/11/, output/7/
c  initialize.
       write (output,1000) 
 1000  format ('1program to split update source file into *.F files.')
       skipo = .false.
       once = .true.
       ncr = 0
       nz = 0
       nm = 0
c  read a card.
   10  buf = ' '
       read (in,'(a)',end=220) buf
c  check if * card.
       if (buf(1:1) .ne. '*') goto 135
c  break card into fields.
       nf = 1
       ihld(1) = ' '
       icl = 12
       ic = 0
       j = 1
       jcc = 72
       chng = .false.
   20  if (chng) then
         if (buf(j:j) .eq. ' ') goto 35
         if (buf(j:j) .eq. ',') goto 135
         nf = nf + 1
         if (nf .gt. 2) go to 135
         ihld(nf) = ' '
         chng = .false.
       else
         if (buf(j:j).eq.' ' .or. buf(j:j).eq.',') goto 30
       endif
       icl = icl - 1
       if (icl .lt. 0) goto 135
       ic = ic + 1
       ihld(nf)(ic:ic) = buf(j:j)
       goto 35
   30  ihln(nf) = ic
       icl = 12
       ic = 0
       chng = .true.
   35  jcc = jcc - 1
       if (jcc .gt. 0) goto 36
       if (.not.chng) goto 30
       goto 39
   36  j = j + 1
       goto 20
c  check if *comdeck card.
   39  if (ihld(1).ne.'*comdeck' .and. ihld(1).ne.'*COMDECK') goto 55
       if (nf .eq. 2) go to 47
       write (output,1001) ncr
 1001  format (' card',i6,' is a bad *comdeck card.')
       nm = nm + 1
       go to 135
   47  filen = ihld(2)
       jn = ihln(2) + 1
       filen(jn:jn+1) = '.H'
       cend = 72
       go to 128
c check if *deck card.
   55  if (ihld(1).ne.'*deck' .and. ihld(1).ne.'*DECK') goto 235
       if (nf .eq. 2) go to 48
       write (output,1002) ncr
 1002  format (' card',i6,' is a bad *deck card.')
       nm = nm + 1
       go to 135
   48  filen = ihld(2)
       jn = ihln(2) + 1
       filen(jn:jn+1) = '.F'
       cend = 72
       go to 128
  235  if (ihld(1) .ne. '*hlpdeck') go to 135
       if (nf .ne. 2) then
         write (output,1007) ncr
 1007 format (' card',i6,' is a bad *hlpdeck card.')
         nm = nm + 1
         go to 135
       else
         jn = ihln(2) - 1
         filen = ihld(2)
         skipo = .true.
       cend = 80
       endif
  128  if (nz .ne. 0) then
         close (unit=out)
         write (output,1003) file(1:jo+1),nz
 1003  format (' file ',a,' has',i6,' cards.')
         nz = 0
       endif
       file = filen
       jo = jn
       open (unit=out,file=file,status='new')
       once = .false.
c  write card.
  135  if (once) then
         write (output,1005)
 1005  format ('0*comdeck or *deck card must be first card.')
         stop 'trouble'
       endif
       do 136 i =cend,2,-1
         if (buf(i:i) .ne. ' ') go to 137
  136  continue
       i = 1
  137   if (skipo) then
          skipo = .false.
        else
c  One of the following two write statements must be commented, the 
c  other not commented.  One writes an extra blank at the beginning
c  of a line for a nonstandard Masscomp feature.
         write (out,'(a)') buf(1:i)
c        write (out,'(1x,a)') buf(1:i)
       endif
       ncr = ncr + 1
       nz = nz + 1
       goto 10
c  finish up.
  220  if (once) then
         write (output,1006) 
 1006  format ('0input file is empty.')
         stop 'no input'
       endif
       if (nz .ne. 0) then
         close (unit=out)
         write (output,1003) file(1:jo+1),nz
       endif
       write (output,1004) ncr,nm
 1004  format ('0number of cards processed =',i8,', number of error mess
     *ages =',i8,'.')
       stop
       end
