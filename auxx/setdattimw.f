       program setdattimw
!  Generates date and time information to be added to a module so that
!  Relap5 can generate a message in the print file identifying when the
!  executable file was created.
!
       integer values(8)
       character liner(10)*72
       character :: line*62=
!               1         2         3         4         5         6
!      123456789012345678901234567890123456789012345678901234567890
     &"integer :: datetimeqqq(8)=[1111,22,33,0,44,55,66,0]"
!  Get date and time.
       call date_and_time (values=values)
!  Convert results to a form that can be used in a Fortran source file.
       write (line(28:31),"(i4)") values(1)
       write (line(33:34),"(i2)") values(2)
       write (line(36:37),"(i2)") values(3)
       write (line(41:42),"(i2)") values(5)
       write (line(44:45),"(i2)") values(6)
       write (line(47:48),"(i2)") values(7)
!  Read the source file for module blddattim. 
       open (2,file='relap\blddattim.ff',access='sequential',
     & action='readwrite',form='formatted',status='unknown')
       do i = 1,9
         read (2,"(a72)") liner(i)
       enddo
!  Replace the line containing old date and time information with the 
!  newly obained date and time information.
       liner(7) = '       ' // line
!  Write the modified module.   
       rewind 2
       do i = 1,9
         write (2,"(a72)") liner(i)
       enddo
       close (2,status='keep')
       end program setdattimw
