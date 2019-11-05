*mlist
c
c  Cognizant engineer: wlw.
c
c  levskn   number of level stacks in this system
c  levskl   index of volume containing level in this level stack
c  levsko   index of volume containing level in this stack during
c           previous time advancement
c  levskh   index of volume at head(top) of this level stack
c  levska   index of volume above head of this stack, used when moving
c           a level from the head volume of this stack into the
c           tail(bottom) volume of an adjacent stack where the adjacent
c           stack is above this stack
c  levskb   index of volume below the tail of this stack, used when
c           moving a level from the tail volume of this stack into the
c           head volume of an adjacent stack where the adjacent stack
c           is below this stack
c  levskd   flag indicating that this stack has been processed during
c           this time advancement, used when moving a level from one
c           stack into an adjacent stack
