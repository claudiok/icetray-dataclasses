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

#include <dataclasses/physics/I3RecoHit.h>

using namespace boost::python;

void register_I3RecoHit()
{
  class_<I3RecoHit, boost::shared_ptr<I3RecoHit> >("I3RecoHit")
    PROPERTY(I3RecoHit, Time, Time)
    PROPERTY(I3RecoHit, ID, ID)
    PROPERTY(I3RecoHit, SourceIndex, SourceIndex)
    ;

  class_<std::vector<I3RecoHit> >("vector_I3RecoHit")
    .def(vector_indexing_suite<std::vector<I3RecoHit> >())
    ;

  class_<I3RecoHitSeriesMap, bases<I3FrameObject>, I3RecoHitSeriesMapPtr>("I3RecoHitSeriesMap")
    .def(map_indexing_suite<I3RecoHitSeriesMap>())
    ;
  register_pointer_conversions<I3RecoHitSeriesMap>();
}
