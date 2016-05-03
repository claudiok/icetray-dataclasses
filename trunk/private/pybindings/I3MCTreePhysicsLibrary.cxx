//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
//   $Id: I3MCTree.cxx 126481 2014-12-02 22:45:21Z david.schultz $
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

#include <boost/python.hpp>
#include "I3MCTreePhysicsLibraryWrappers.hh"

namespace bp = boost::python;

void register_I3MCTreePhysicsLibrary()
{
  bp::def("get_most_energetic_primary", get_most_energetic_primary, "");
  bp::def("get_most_energetic_inice", &get_most_energetic_inice, "");
  bp::def("get_most_energetic", &get_most_energetic, "");
  bp::def("get_most_energetic_track", &get_most_energetic_track, "");
  bp::def("get_most_energetic_cascade", &get_most_energetic_cascade, "");
  bp::def("get_most_energetic_inice_cascade", &get_most_energetic_inice_cascade, "");
  bp::def("get_most_energetic_neutrino", &get_most_energetic_neutrino, "");
  bp::def("get_most_energetic_muon", &get_most_energetic_muon, "");
  bp::def("get_most_energetic_nucleus", &get_most_energetic_nucleus, "");
}

