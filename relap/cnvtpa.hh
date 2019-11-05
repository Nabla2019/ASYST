!  Array for control component alphanumeric type names.
!
!  Cognizant engineer: rjw.
!
$if -def,hydrolod,1
       integer, parameter :: cnvtpn=23
$if def,hydrolod,1
       integer, parameter :: cnvtpn=24
       character :: cnvtpa(cnvtpn)*8=
     & (/'sum','mult','div','diffreni','diffrend', 'integral',
     & 'delay','function','stdfnctn','tripunit','tripdlay','poweri',
     & 'powerr','powerx','prop-int','lag','lead-lag','constant',
$if -def,hydrolod,1
     & 'shaft','pumpctl','steamctl','feedctl','compare'/)
$if def,hydrolod,1
     & 'shaft','pumpctl','steamctl','feedctl','compare','frcsum'/)
