*mlist
!  Cognizant engineer: wlw.
!
!  level stack table block.
       integer levskp
       parameter (levskp=6)
       integer levskn(l_),levskl(l_),levskh(l_),levska(l_),levskb(l_),
     & levskd(l_),levsko(l_)
       equivalence (levskn(1),ia(1)),(levskl(1),ia(2)),
     * (levsko(1),ia(3)),
     * (levskh(1),ia(4)),(levska(1),ia(5)),(levskb(1),ia(6)),
     * (levskd(1),ia(7))
!
!  levskn   number of level stacks in this system
!  levskl   index of volume containing level in this level stack
!  levsko   index of volume containing level in this stack during
!           previous time advancement
!  levskh   index of volume at head(top) of this level stack
!  levska   index of volume above head of this stack, used when moving
!           a level from the head volume of this stack into the
!           tail(bottom) volume of an adjacent stack where the adjacent
!           stack is above this stack
!  levskb   index of volume below the tail of this stack, used when
!           moving a level from the tail volume of this stack into the
!           head volume of an adjacent stack where the adjacent stack
!           is below this stack
!  levskd   flag indicating that this stack has been processed during
!           this time advancement, used when moving a level from one
!           stack into an adjacent stack
