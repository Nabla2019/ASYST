*mlist
*comdeck couplc
c
c
c  Descriptive sentence goes here.
c
c  Cognizant engineer: ewc.
c
*if def,selap
c  common block for couple debris bed model.  saved on restart file.
c       afrdeb = atomic fractions of debis bed.
c       dtcoup = couple time step.  used with ntsc to determine
c                when to call couple.
c       hgtdeb = height of debris bed.
c       pdmave = sum of particle diameter * mass of material slumped.
c       pmufot = multiplier for Couple mesh fission power or total power
c       pmufdk = multiplier for Couple mesh fission product decay power
c       pmuadk = multiplier for Couple mesh actinide decay power
c       qfrspi = fraction of fission product decay heat for each species
c       porave = sum of porosity * mass of material slumped.
c       powave = sum of dt * power of material slumped.
c       powdmx = maximum power density in debris bed.
c       pdbtot = total power density in the couple mesh.
c       stmass = steam production rate of debris in couple mesh, kg/s.
c       tave   = sum of temperature * mass of material slumped.
c       timc   = selap time for next call to couple.
c       tmpdmx = maximum temperature in debris bed.
c       twalmx = maximum temperature of structure in couple mesh.
c       tmpdav = average temp. of debris bed (material 1)
c       twalav = average temp. of structure (materials 2, 3, and 4)
c       wtmdeb = total mass in debris bed.
c       ws     = mass of each material which has slumped into the
c                couple mesh since last couple call.
c                the order = zr, u, ss, ag, b4c, uo2, zro2, al, li, cd.
c       wst    = total mass of each material which has slumped
c                into the couple mesh.
c       icoup  = couple status indicator -
c                   0 - couple model not used.
c                   1 - couple model used, no debris bed yet.
c                   2 - couple model used, debris bed is forming.
c       invc   = index offset of data for volume ncvolc.
c       itsc   = number of selap hydraulic time steps since last
c                call to couple.
c       mcostr = pointer to start of couple data in array a for mesh mcp
c       ncdtsl = no. of selap time steps since last significant slump.
c       ncpowi = indicator for type of power source -
c                  0 = Constant power from slumping material
c                      at time of slumping
c                  1 = Power is determined by Relap5 reactor
c                      kinetics power in the associated Scdap
c                      components.
c                  2 = Power is determined by power other than
c                      Relap5 reactor kinetics power in the
c                      associated Scdap components.
c       ncslp  = indicator for whether or not any material has
c                slumped into couple mesh this couple time step.
c                  0 = no, 1 = yes.
c       ncvolc = number of the Relap5 volume to receive Couple debris.
c       npowdm = node no. of current maximum debris bed power density.
c       ntmpdm = node no. of current maximum debris bed temp.
c       ntsc   = maximum number of selap hydraulic time steps to
c                use per couple time step.
c       ntwalm = element no. of current maximum structure temp.
c       nmcpwr = Number of Couple mesh to be written to output file.
c       kpr    = interval of relap5 time steps to write output file
c       nrecno = Next record number in Couple output file.
*endif
