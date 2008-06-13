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

#include <dataclasses/physics/I3MCHit.h>

using namespace boost::python;

void register_I3MCHit()
{
  {
    scope mchit_scope = 
      class_<I3MCHit, boost::shared_ptr<I3MCHit> >("I3MCHit")
      PROPERTY(I3MCHit, Time, Time)
      PROPERTY(I3MCHit, HitID, HitID)
      PROPERTY(I3MCHit, Weight, Weight)
      PROPERTY(I3MCHit, CherenkovDistance, CherenkovDistance)
      .def("GetHitSource", &I3MCHit::GetHitSource)
      ;

    enum_<I3MCHit::HitSource>("HitSource")
      .value("UNKNOWN", I3MCHit::UNKNOWN)
      .value("SPE", I3MCHit::SPE)
      .value("RANDOM", I3MCHit::RANDOM)
      .value("AFTER_PULSE", I3MCHit::AFTER_PULSE)
      .value("PRE_PULSE", I3MCHit::PRE_PULSE)
      .value("ELASTIC_LATE_PULSE", I3MCHit::ELASTIC_LATE_PULSE)
      .value("INELASTIC_LATE_PULSE", I3MCHit::INELASTIC_LATE_PULSE)
      .value("EARLY_AFTER_PULSE", I3MCHit::EARLY_AFTER_PULSE)
      ;
    def("identity", identity_<I3MCHit::HitSource>);  
  }

  class_<std::map<OMKey, I3MCHit> >("Map_OMKey_I3MCHit")
    .def(map_indexing_suite<std::map<OMKey, I3MCHit> >())
    ;

  class_<std::vector<I3MCHit> >("Vector_I3MCHit")
    .def(vector_indexing_suite<std::vector<I3MCHit> >())
    ;

  class_<I3MCHitSeriesMap, bases<I3FrameObject>, I3MCHitSeriesMapPtr>("Map_OMKey_VectorI3MCHit")
    .def(map_indexing_suite<I3MCHitSeriesMap>())
    ;

  register_pointer_conversions<I3MCHitSeriesMap>();
}
