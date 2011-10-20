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

#include <dataclasses/physics/I3RecoPulse.h>
#include <icetray/I3Frame.h>
#include <icetray/python/std_map_indexing_suite.hpp>
#include <icetray/python/std_vector_indexing_suite.hpp>
#include <icetray/python/copy_suite.hpp>
#include <icetray/python/stream_to_string.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;

static I3RecoPulseSeriesMapPtr
from_frame(I3Frame &frame, const std::string &name)
{
	I3RecoPulseSeriesMapConstPtr rpsm =
	    frame.Get<I3RecoPulseSeriesMapConstPtr>(name);
	return boost::const_pointer_cast<I3RecoPulseSeriesMap>(rpsm);
}

void register_I3RecoPulse()
{
  class_<std::vector<I3RecoPulse> >("vector_I3RecoPulse")
    .def(std_vector_indexing_suite<std::vector<I3RecoPulse> >())
    .def(copy_suite<std::vector<I3RecoPulse> >())
    .def("__str__", &stream_to_string<std::vector<I3RecoPulse> >)
    ;

  class_<I3RecoPulseSeriesMap, bases<I3FrameObject>, I3RecoPulseSeriesMapPtr>("I3RecoPulseSeriesMap")
    .def(std_map_indexing_suite<I3RecoPulseSeriesMap>())
    .def(copy_suite<I3RecoPulseSeriesMap>())
    .def("from_frame", &from_frame, args("frame", "key"),
        "Get an I3RecoPulseSeriesMap from the frame, performing any necessary "
        "format conversions behind the scenes.")
    .staticmethod("from_frame")
    .def("__str__", &stream_to_string<I3RecoPulseSeriesMap>)
    ;
  register_pointer_conversions<I3RecoPulseSeriesMap>();

  scope outer = 
  class_<I3RecoPulse, boost::shared_ptr<I3RecoPulse> >("I3RecoPulse")
    #define PROPS (Time)(Charge)(Width)(Flags)
    BOOST_PP_SEQ_FOR_EACH(WRAP_PROP, I3RecoPulse, PROPS)
    #undef PROPS
    .def(copy_suite<I3RecoPulse>())
    .def( self == self )
    .def("__str__", &stream_to_string<I3RecoPulse>)
    .def( freeze() )
    ;
  
  enum_<I3RecoPulse::PulseFlags>("PulseFlags")
    .value("LC", I3RecoPulse::LC)
    .value("ATWD", I3RecoPulse::ATWD)
    .value("FADC", I3RecoPulse::FADC)
    ;
}
