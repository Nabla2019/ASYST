*comdeck snapc
c
c  Routines to take a snapshot of a set of scalars, vector, matrix,
c  or tensor in integer, double precision, logical, character, or
c  binary format.  These routines are modified for use in relap5
c  where every other integer or logical is used when equivalenced
c  to a double precision number on 32-bit cpus.
c
c  Cognizant engineer: gam
c
c  ***  contains many snap subroutines
c       The naming convention is a follows:
c        s => scalar
c        v => vector (1D)
c        m => matrix (2D)
c        t => tensor (3D)
c        i => integer
c        d => double precision
c        l => logical
c        c => character*8
c        b => binary (1s and 0s)
c        ho => hollerith
c        1-5 => in last position = number of scalar variables
c        2 => in second position = (2,*) variables
c
c  The routines are listed below in the order they appear in the file:
c
c       snpho  writes out a string of characters
c       snpsc1,2 writes out 1,2 character*8 string variables
c       snpmd  writes out a double precision matrix
c       snpmi  writes out an integer matrix
c       snpml  writes out an logical matrix
c       snpsd1,2,3,4,5  writes out 1,2,3,4,5 double precision variables
c       s2psi1,2,3,4,5  writes out 1,2,3,4,5 integer (2,*) variables
c       snpsi1,2,3,4,5  writes out 1,2,3,4,5 integer variables
c       s2psl1,2,3,4,5  writes out 1,2,3,4,5 logical (2,*) variables
c       snpsl1,2,3,4,5  writes out 1,2,3,4,5 logical variables
c       snptd  writes out a 3-D double precision tensor
c       snpti  writes out a 3-D integer tensor
c       snptl  writes out a 3-D logical tensor
c       snpvc  writes out a character*8 string vector
c       snpvd  writes out a double precision vector
c       s2pvi  writes out a integer (2,*) vector
c       snpvi  writes out a integer vector
c       s2pvib writes out a integer (2,*) vector in binary format (1s &
c       snpvib writes out a integer vector in binary format (1s & 0s)
c       s2pvl  writes out a logical (2,*) vector
c       snpvl  writes out a logical vector
c       snpb01 returns a character string of 0s &1s for an integer input
c       s2psb1,2,3,4  writes out 1,2,3,4 (2,*) integers in binary format
c       snpsb1,2,3,4  writes out 1,2,3,4 integers in binary format
c
c
