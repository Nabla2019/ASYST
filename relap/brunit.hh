*mlist
c
c  Cognizant engineer: dmk.
c *** scale si to british units
c              vsi = si variable,
c           convxx = si to british conversion factor
c
      brunit(vsi, convxx) = vsi * max(0.0, convxx)
     *           - min(0.0, sign(1.8,convxx)) * (vsi + convxx)
