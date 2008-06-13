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

#include <dataclasses/physics/I3TWRLaunch.h>

using namespace boost::python;

void register_I3TWRLaunch()
{
  std::vector<I3TWRFrag>& (I3TWRLaunch::*get_fragments)(void) = &I3TWRLaunch::GetFragments;
  
  {
    scope outer = 
    class_<I3TWRLaunch, boost::shared_ptr<I3TWRLaunch> >("I3TWRLaunch")
      .def("GetBaseline", &I3TWRLaunch::GetBaseline)
      .def("GetWaveform", get_fragments,
	   return_internal_reference<1>())
    ;

  }

  class_<std::vector<I3TWRLaunch> >("Vector_I3TWRLaunch")
    .def(vector_indexing_suite<std::vector<I3TWRLaunch> >())
    ;
    
  class_<I3TWRLaunchSeriesMap, bases<I3FrameObject>, I3TWRLaunchSeriesMapPtr>("Map_OMKey_VectorI3TWRLaunch")
    .def(map_indexing_suite<I3TWRLaunchSeriesMap>())
    ;
    
  register_pointer_conversions<I3TWRLaunchSeriesMap>();
}
