/**
 *  $Id$
 *  
 *  Copyright (C) 2007
 *  the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 *  This file is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>
 *  
 */
#include <dataclasses/TankKey.h>
#include <icetray/python/copy_suite.hpp>

using namespace boost::python;

void register_TankKey()
{
  scope tankkey_scope = 
    class_<TankKey, boost::shared_ptr<TankKey> >("TankKey")
    .def(init<int,TankKey::TankID>())
    .def(init<OMKey>())
    .def(copy_suite<TankKey>())
    .def_readwrite("string", &TankKey::string)
    .def_readwrite("tank", &TankKey::tank)
    ;
  enum_<TankKey::TankID>("TankID")
    .value("TankA", TankKey::TankA)
    .value("TankB", TankKey::TankB)
    .export_values()
    ;
}
    