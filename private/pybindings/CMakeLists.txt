#
#  copyright (C) 2008
#  troy d. straszheim  <troy@resophonic.com>
#  
#  This file is part of icetray
#  
#  Traash is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 3 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>
#  

i3_add_pybindings(dataclasses
  I3AMANDAAnalogReadout.cxx
  I3Calibration.cxx
  I3Constants.cxx
  I3DOMLaunch.cxx
  I3DetectorStatus.cxx
  I3DOMFunctions.cxx
  I3Direction.cxx
  I3Double.cxx
  I3EventHeader.cxx
  I3FlasherInfo.cxx
  I3Geometry.cxx
  I3MCHit.cxx
  I3MCList.cxx
  I3MCTree.cxx
  I3Particle.cxx
  I3Position.cxx
  I3RecoHit.cxx
  I3RecoPulse.cxx
  I3String.cxx
  I3TWRFrag.cxx
  I3TWRLaunch.cxx
  I3Time.cxx
  I3Trigger.cxx
  I3Waveform.cxx
  I3Vectors.cxx
  I3MapString.cxx
  I3MapInt.cxx
  I3MapKey.cxx
  module.cxx
  USE_TOOLS boost python log4cplus
  USE_PROJECTS icetray dataclasses
  )

