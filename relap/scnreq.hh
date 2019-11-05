       subroutine scnreq (ir,alph,num,itypi,pckcod,pckcodp,pckcodv,conv,
     & labl,error)
$if def,dll,1
!dec$ attributes dllexport:: scnreq
       integer, parameter :: kr=selected_real_kind(12,200)
       integer ir,num,itypi,pckcod(2)
       logical error
       real(kr) conv
       real(kr), pointer :: pckcodp,pckcodv(:)
       character alph*8,labl*64
       end subroutine scnreq
