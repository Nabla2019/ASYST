        program test

        interface
        subroutine CP (expDy, expDt, status, errstr, prd, ver) 
     &  bind (C, name = "CP")
        use, intrinsic :: iso_c_binding
        implicit none
!       character(1) :: licStatus, licType, expDt, cpID
        integer expDy, status
        character(1) expDt, errstr, prd, ver
        end subroutine CP
        end interface

!       character licStatus*50, licType*50, expDt*50, cpID*50
        integer expDy, status
        character*512 errstr
        character*16 expDt, prd, ver
        status = 0
        errstr = ''

! Test Fortran program calling a C subroutine
        write (*,*) 'This is a Fortran program!!'
c       call CP(licStatus, licType, expDt, cpID)
c       write(6,*) licStatus
c       write(6,*) licType
c       write(6,*) expDt
c       write(6,*) cpID
        call CP(expDy, expDt, status, errstr, prd, ver)
        write(6,"('Product: ', a,' version: ',a)") prd, ver
        if (status .ne. 0) then
c               write(6,*) 'Check License Error!'
                write(6,*) errstr
                STOP
        else
c               write(6,*) expDy
                write(6,"('The expiration date is ', a)") expDt
                write(6,*) 
     & 'Checkout license succesfully'
                pause
        endif
        write (*,*) 'This ends a Fortran program!!'
        end
