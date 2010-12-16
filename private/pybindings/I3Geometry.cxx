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

#include <dataclasses/geometry/I3Geometry.h>
#include <dataclasses/geometry/I3OMGeo.h>
#include <dataclasses/geometry/I3TankGeo.h>
#include <icetray/python/std_map_indexing_suite.hpp>
#include <icetray/python/std_vector_indexing_suite.hpp>
#include <icetray/python/copy_suite.hpp>

using namespace boost::python;

void register_I3Geometry()
{

  //
  // I3Geometry
  //
  class_<I3Geometry, bases<I3FrameObject>, boost::shared_ptr<I3Geometry> >("I3Geometry")
    .def(copy_suite<I3Geometry>())
    .def_readwrite("omgeo", &I3Geometry::omgeo)
    .def_readwrite("stationgeo", &I3Geometry::stationgeo)
    .def_readwrite("startTime", &I3Geometry::startTime)
    .def_readwrite("endTime", &I3Geometry::endTime)
    ;

  class_<std::map<OMKey, I3OMGeo> >("Map_OMKey_I3OMGeo")
    .def(std_map_indexing_suite<std::map<OMKey, I3OMGeo> >())
    ;

  {
    //
    // I3OMGeo
    //
    scope omg = class_<I3OMGeo, boost::shared_ptr<I3OMGeo> >("I3OMGeo")
      .def(copy_suite<I3OMGeo>())
      .def_readwrite("position", &I3OMGeo::position)
      .def_readwrite("omtype", &I3OMGeo::omtype)
      .def_readwrite("orientation", &I3OMGeo::orientation)
      .def_readwrite("area", &I3OMGeo::area)
      .def_readwrite("aziangle", &I3OMGeo::aziangle)
      ;

    enum_<I3OMGeo::OMType>("OMType")
      .value("AMANDA", I3OMGeo::AMANDA)
      .value("IceCube", I3OMGeo::IceCube)
      .value("IceTop", I3OMGeo::IceTop)
      .export_values()
      ;

    enum_<I3OMGeo::Orientation>("Orientation")
    .value("Unspecified", I3OMGeo::Unspecified)
    .value("Up", I3OMGeo::Up)
    .value("Down", I3OMGeo::Down)
    .export_values()
    ;

  }
  def("identity", identity_<I3OMGeo::OMType>);

  class_<I3Vector<OMKey>, bases<I3FrameObject> >("I3Vector_OMKey")
    .def(std_vector_indexing_suite<I3Vector<OMKey> >())
    ;

  //
  // I3TankGeo
  //
  {
    scope tankgeo = class_<I3TankGeo, boost::shared_ptr<I3TankGeo> >("I3TankGeo")
      .def(copy_suite<I3TankGeo>())
      .def_readwrite("position",&I3TankGeo::position)
      .def_readwrite("orientation",&I3TankGeo::orientation)
      .def_readwrite("tankradius",&I3TankGeo::tankradius)
      .def_readwrite("tankheight",&I3TankGeo::tankheight)
      .def_readwrite("fillheight",&I3TankGeo::fillheight)
      .def_readwrite("omKeyList",&I3TankGeo::omKeyList_)
      .def_readwrite("snowheight",&I3TankGeo::snowheight)
      .def_readwrite("tanktype",&I3TankGeo::tanktype)
      ;

    enum_<I3TankGeo::TankType>("TankType")
      .value("NotSet", I3TankGeo::NotSet)
      .value("Tyvek_Lined", I3TankGeo::Tyvek_Lined)
      .value("Zirconium_Lined", I3TankGeo::Zirconium_Lined)
      .export_values()
      ; 
  }

  class_<std::vector<I3TankGeo> >("I3StationGeo")
    .def(copy_suite<I3StationGeo>())
    .def(std_vector_indexing_suite<std::vector<I3TankGeo> >())
    ;

  class_<std::map<int, I3StationGeo> >("I3StationGeoMap")
    .def(std_map_indexing_suite<std::map<int, I3StationGeo> >())
    ;

  register_pointer_conversions<I3Geometry>();
  //  boost::python::register_ptr_to_python<boost::shared_ptr<I3Geometry> >();
}
