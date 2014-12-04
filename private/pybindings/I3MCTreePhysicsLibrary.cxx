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

#include <vector>
#include <algorithm>
#include <exception>

#include <dataclasses/physics/I3MCTreePhysicsLibrary.hh>
#include <dataclasses/I3Constants.h>
#include <icetray/python/copy_suite.hpp>
#include <icetray/python/operator_suite.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>
#include <boost/python/exception_translator.hpp>
#include <boost/python/object.hpp>
#include <boost/python/slice.hpp>
#include <boost/python/extract.hpp>
#include <boost/function.hpp>

#include "I3MCTreePhysicsLibraryWrappers.hh"

using namespace boost::python;

void register_I3MCTreePhysicsLibrary()
{
  def("get_most_energetic_primary", get_most_energetic_primary, "");
  def("get_most_energetic_inice", &get_most_energetic_inice, "");
  def("get_most_energetic", &get_most_energetic, "");
  def("get_most_energetic_track", &get_most_energetic_track, "");
  def("get_most_energetic_cascade", &get_most_energetic_cascade, "");
  def("get_most_energetic_inice_cascade", &get_most_energetic_inice_cascade, "");
  def("get_most_energetic_neutrino", &get_most_energetic_neutrino, "");
  def("get_most_energetic_muon", &get_most_energetic_muon, "");
  def("get_most_energetic_nucleus", &get_most_energetic_nucleus, "");
}

