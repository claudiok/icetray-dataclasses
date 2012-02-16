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

#include <dataclasses/physics/I3Particle.h>
#include <boost/preprocessor/seq.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/cat.hpp>
#include <icetray/python/std_vector_indexing_suite.hpp>
#include <icetray/python/stream_to_string.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;
 
#define ENUM_DEF(r,data,T) .value(BOOST_PP_STRINGIZE(T), data::T)

void register_I3Particle()
{

  {
    scope particle_scope = 
      class_<I3Particle, bases<I3FrameObject>, boost::shared_ptr<I3Particle> >("I3Particle")
      #define RO_PROPERTIES (MajorID)(MinorID)
      #define PROPERTIES (Time)(Energy)(Shape)(Type)(PdgEncoding)(Length)(Speed)(FitStatus)(LocationType) \
                         (ShapeString)(TypeString)(FitStatusString)(LocationTypeString)
      #define CONVENIENCE_BOOLS (IsTrack)(IsCascade)(IsPrimary)(IsTopShower)(IsNeutrino)
      BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_RO, I3Particle, RO_PROPERTIES)
      BOOST_PP_SEQ_FOR_EACH(WRAP_PROP, I3Particle, PROPERTIES)
      BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_BOOL, I3Particle, CONVENIENCE_BOOLS)
      #undef RO_PROPERTIES
      #undef PROPERTIES
      #undef CONVENIENCE_BOOLS
      .add_property("pos", make_function( (const I3Position& (I3Particle::*)()) &I3Particle::GetPos, return_internal_reference<1>() ),
					  (void (I3Particle::*)(const I3Position&)) &I3Particle::SetPos ) 
      .add_property("dir", make_function( (const I3Direction& (I3Particle::*)()) &I3Particle::GetDir, return_internal_reference<1>() ),
					  (void (I3Particle::*)(const I3Direction&)) &I3Particle::SetDir ) 
      .def("shift_along_track", &I3Particle::ShiftAlongTrack)
      .def_pickle(boost_serializable_pickle_suite<I3Particle>())
      .def( freeze() )
      .def("__str__", &stream_to_string<I3Particle>)
      ;

    enum_<I3Particle::FitStatus>("FitStatus")
      BOOST_PP_SEQ_FOR_EACH(ENUM_DEF,I3Particle,I3PARTICLE_H_I3Particle_FitStatus)
      .export_values()
      ;

    enum_<I3Particle::LocationType>("LocationType")
      BOOST_PP_SEQ_FOR_EACH(ENUM_DEF,I3Particle,I3PARTICLE_H_I3Particle_LocationType)
      .export_values()
      ;

    enum_<I3Particle::ParticleType>("ParticleType")
      BOOST_PP_SEQ_FOR_EACH(ENUM_DEF,I3Particle,I3PARTICLE_H_I3Particle_ParticleType)
      .export_values()
      ;

    enum_<I3Particle::ParticleShape>("ParticleShape")
      BOOST_PP_SEQ_FOR_EACH(ENUM_DEF,I3Particle,I3PARTICLE_H_I3Particle_ParticleShape)
      .export_values()
      ;

  }

  class_<std::vector<I3Particle> >("I3ParticleVect")
    .def(std_vector_indexing_suite<std::vector<I3Particle> >())
    .def("__str__", &stream_to_string<std::vector<I3Particle> >)
    .def_pickle(boost_serializable_pickle_suite<std::vector<I3Particle> >())
    ;

  register_pointer_conversions<I3Particle>();
}
