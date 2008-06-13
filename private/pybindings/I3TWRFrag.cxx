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

#include <dataclasses/physics/I3TWRFrag.h>

using namespace boost::python;

void register_I3TWRFrag()
{
  std::vector<unsigned int>& (I3TWRFrag::*get_waveform)(void) = &I3TWRFrag::GetWaveform;

  {
    scope outer = 
    class_<I3TWRFrag, boost::shared_ptr<I3TWRFrag> >("I3TWRFrag")
      .def("GetStartBin", &I3TWRFrag::GetStartBin)
      .def("GetWaveform", get_waveform,
	   return_internal_reference<1>())
    ;

  }

  class_<std::vector<I3TWRFrag> >("Vector_I3TWRFrag")
    .def(vector_indexing_suite<std::vector<I3TWRFrag> >())
    ;
    
}
