//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
//   $Id: ithon.cxx 25598 2006-11-25 02:52:57Z troy $
//
//   This file is part of IceTray.
//
//   IceTray is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 3 of the License, or
//   (at your option) any later version.
//
//   IceTray is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <vector>

#include <dataclasses/I3DOMFunctions.h>

using namespace boost::python;

void register_I3DOMFunctions()
{

  def("ATWDSamplingRate",&ATWDSamplingRate);
  def("PMTGain",&PMTGain);
  def("SPEMean",&SPEMean);
  def("FADCBaseline",&FADCBaseline);
  def("TransitTime",&TransitTime);
  def("SPEDriscriminatorThreshold",&SPEDiscriminatorThreshold);
  def("MPEDriscriminatorThreshold",&MPEDiscriminatorThreshold);
  def("OldspeThreshold",&OldspeThreshold);
  def("OldmpeThreshold",&OldmpeThreshold);
  def("DOMCalVersion",&DOMCalVersion);
  def("WhichATWD",&WhichATWD);

} 
