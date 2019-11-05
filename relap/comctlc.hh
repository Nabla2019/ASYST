*mlist
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: rjw.
c
c  ncoms   number of common control slots.
c  nfiles  number of dynamic file slots.
c  comdat  index relative to fa of first word of common block to be
c          saved.
c  comdln  length of common block to be saved.
c  filid   ftb filid for dynamic storage files.
c  filsiz  length of dynamic file.
c  safe1   not  written on restart file, provided to allow length
c          checking when reading from restart file.  Used for
c          timer argument when timing transient subroutine
c          execution times.
c  newrst  true if a restart problem, used during input processing.
c  filndx  index of dynamic file in fast or ftblcm block.
c  filflg  flag for dynamic file on disk to be written at complete
c          restart (bit 1), flag to write common block file at complete
c          restart (bit 4).
c  filid(1)  input data and work scratch space during advancement.
c  filid(3)  component description block.
c  filid(4)  hydrodynamic volumes block.
c  filid(5)  hydrodynamic junctions block.
c  filid(6)  Thermodynamic property file.
c  filid(8)  heat structure geometry and temperature block.
c  filid(9)  heat structure material property storage.
c  filid(12) minor edit file.
c  filid(14) table of heat structures and data for each volume.
c  filid(16) minor edit control, save area, and labels.
c  filid(18) trip block.
c  filid(21) reactor kinetics data.
c  filid(25) Volume data needed for a moving system.
c  filid(27) control system block.
c  filid(28) component indices in normal (input) order.
c  filid(29) Tabular data for rotations and translations for moving
c            problem.
c  filid(31) code coupling data
c  filid(32) reflood rezoning model storage space.
c  filid(34) fission product data.
c  filid(35) fixed list vectors.
c  filid(37) steady state initialization check file.
c  filid(38) file for radiation heat transfer.
c  filid(43) file for level model geometry description (i.e. stacks).
