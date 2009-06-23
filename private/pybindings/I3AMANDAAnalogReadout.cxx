//
//   Copyright (c) 2009   Troy D. Straszheim  
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

#include <dataclasses/physics/I3AMANDAAnalogReadout.h>
#include <icetray/python/std_map_indexing_suite.hpp>

using namespace boost::python;

void register_I3AMANDAAnalogReadout()
{
  class_<I3AMANDAAnalogReadout, 
    boost::shared_ptr<I3AMANDAAnalogReadout> >("I3AMANDAAnalogReadout")
    .add_property("ADC", 
		  &I3AMANDAAnalogReadout::GetADC,
		  &I3AMANDAAnalogReadout::SetADC)
    .add_property("Amplitude", 
		  &I3AMANDAAnalogReadout::GetAmplitude,
		  &I3AMANDAAnalogReadout::SetAmplitude)
    .add_property("Overflow", 
		  &I3AMANDAAnalogReadout::GetOverflow,
		  &I3AMANDAAnalogReadout::SetOverflow)
    .add_property("Calibrated", 
		  &I3AMANDAAnalogReadout::IsCalibrated,
		  &I3AMANDAAnalogReadout::SetCalibrated)
    ;

  class_<I3AMANDAAnalogReadoutMap, 
    bases<I3FrameObject>, 
    I3AMANDAAnalogReadoutMapPtr>("I3AMANDAAnalogReadoutMap")
    .def(std_map_indexing_suite<I3AMANDAAnalogReadoutMap>())
    ;

  register_pointer_conversions<I3AMANDAAnalogReadoutMap>();
}
