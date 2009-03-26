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

using namespace boost::python;

// more pythonic interfaces for the std::map
template <typename MapType>
static boost::python::list map_keys(MapType const& x)
{
        boost::python::list t;
        for(typename MapType::const_iterator it = x.begin(); it != x.end(); it++)
          t.append(it->first);
        return t;
}

template <typename MapType>
static boost::python::list map_values(MapType const& x)
{
        boost::python::list t;
        for(typename MapType::const_iterator it = x.begin(); it != x.end(); it++)
          t.append(it->second);
        return t;
}

template <typename MapType, typename KeyType>
static bool map_has_key(const MapType &x, const KeyType &k)
{
        bool found=false;
	typename MapType::const_iterator it = x.find(k);
	if (it != x.end()) found = true;
	return found;
}

void register_I3RecoPulse()
{
  class_<I3RecoPulse, boost::shared_ptr<I3RecoPulse> >("I3RecoPulse")
    PROPERTY(I3RecoPulse, Time, Time)
    PROPERTY(I3RecoPulse, ID, ID)
    PROPERTY(I3RecoPulse, SourceIndex, SourceIndex)
    PROPERTY(I3RecoPulse, Charge, Charge)
    PROPERTY(I3RecoPulse, Width, Width)
    ;

  class_<std::vector<I3RecoPulse> >("vector_I3RecoPulse")
    .def(vector_indexing_suite<std::vector<I3RecoPulse> >())
    ;

  class_<I3RecoPulseSeriesMap, bases<I3FrameObject>, I3RecoPulseSeriesMapPtr>("I3RecoPulseSeriesMap")
    .def(map_indexing_suite<I3RecoPulseSeriesMap>())
    .def("keys",&map_keys<I3RecoPulseSeriesMap>)
    .def("values",&map_values<I3RecoPulseSeriesMap>)
    .def("has_key",&map_has_key<I3RecoPulseSeriesMap, OMKey>)
    ;
  register_pointer_conversions<I3RecoPulseSeriesMap>();

}
