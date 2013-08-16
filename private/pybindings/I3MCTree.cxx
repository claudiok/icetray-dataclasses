//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
//   $Id$
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
#include <exception>

#include <dataclasses/physics/I3MCTree.h>
#include <dataclasses/physics/I3MCTreeUtils.h>
#include <dataclasses/I3Constants.h>
#include <icetray/python/copy_suite.hpp>
#include <icetray/python/operator_suite.hpp>
#include <boost/python/exception_translator.hpp>

using namespace boost::python;

using std::cout;
using std::endl;

/*void default_dump(const I3MCTree& t) { 
  cout<< I3MCTreeTools::Dump(t) <<endl; 
}

void dump_to_cout(const I3MCTree& t, const std::string& config) { 
  cout<< I3MCTreeTools::Dump(t,config) <<endl; 
}

std::string stringize(const I3MCTree& t) { 
  return I3MCTreeTools::Dump(t); 
}*/

struct not_found_exception : std::exception
{
  char const* what() const  throw() { return "Particle not found in tree"; }
};
void translate(const not_found_exception& e)
{
    // Use the Python 'C' API to set up an exception object
    PyErr_SetString(PyExc_RuntimeError, e.what());
}

//I3MCTree::size_type (I3MCTree::*depth)(const I3ParticleID&) const = &I3MCTree::depth;
I3MCTree::size_type depth(const I3MCTree& t,const I3ParticleID& p)
{ return t.depth(p); }

I3Particle at(const I3MCTree& t,const I3ParticleID& p)
{
  I3MCTree::nonPtrType ret = t.at(p);
  if (ret)
    return *ret;
  else
    throw not_found_exception();
}

#define WRAP_PROP_FN(R, Data, Elem)\
	.add_property(snake_case(BOOST_PP_STRINGIZE(Elem)), BOOST_PP_CAT(&Get,Elem))
#define WRAP_PROP_BARE(R, Data, Elem)\
	.add_property(snake_case(BOOST_PP_STRINGIZE(Elem)), &Elem)
void register_I3MCTree()
{
  {
    register_exception_translator<not_found_exception>(&translate);
    
    scope outer = 
      class_<I3MCTree, bases<I3FrameObject>, I3MCTreePtr>("I3MCTree",
        "I3MCTree docstring")
        // I3MCTreeUtils
        .def("get_daughters",&I3MCTreeUtils::GetDaughters)
        //.def("get_most_energetic",&I3MCTreeUtils::GetMostEnergetic)
        //.def("get_number_of_stochastics",&I3MCTreeUtils::GetNumberOfStochastics)
        .def("has_parent",&I3MCTreeUtils::HasParent)
        .def("add_primary",&I3MCTreeUtils::AddPrimary)
        .def("get_primary",&I3MCTreeUtils::GetPrimary)
        .def("get_primaries",&I3MCTreeUtils::GetPrimaries)
        .def("append_child",&I3MCTreeUtils::AppendChild)
        .def("get_particle", &I3MCTreeUtils::GetParticle)
        //.def("dump", &dump_to_cout )
        //.def("dump", &default_dump )
        //.add_property("neutrino_event_type", &I3MCTreeTools::GetNeutrinoEventType )
        //.add_property("is_neutral_current", &I3MCTreeTools::IsNeutralCurrent )
        //.add_property("is_charged_current", &I3MCTreeTools::IsChargedCurrent )
        //.add_property("is_glashow_resonance", &I3MCTreeTools::IsGlashowResonance )
        //.def("check_neutrino", &I3MCTreeTools::CheckNeutrino )
        // end I3MCTreeUtils
        // BaseClassMethods
        //.def("merge",&I3MCTree::merge)
        .def("depth", &depth)
        /*.def("insert", &insert)
        .def("insert_after", &insert_after)
        .def("replace", &replace)
        .def("append_child", &append_child)
        .def("erase", &erase)*/
        // end from BaseClassMethods
        //.def("__str__", &stringize )
        .def("__len__",&I3MCTree::size)
        .def("__iter__", range<return_value_policy<copy_non_const_reference> >
         (
          (I3MCTree::pre_order_iterator(I3MCTree::*)()) &I3MCTree::begin, 
          (I3MCTree::pre_order_iterator(I3MCTree::*)()) &I3MCTree::end
          )
         )
         .def("__getitem__",&at)
        /*#define PROPS (MostEnergeticPrimary)(MostEnergeticCascade)	\
        (MostEnergeticNeutrino)(MostEnergeticNucleus)(MostEnergeticMuon) \
        (MostEnergeticInIce)(MostEnergetic)			\
        (MostEnergeticTrack)(InIce)(Primaries) \
        (MostEnergeticStochastic)		 \
        (NumberOfAtmosphericMuons )
        BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_FN, ~, PROPS)
        #undef PROPS
        #define BARE_PROPS (NCascades) 
        BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_BARE, ~, BARE_PROPS)
        #undef BARE_PROPS*/
        .def(copy_suite<I3MCTree>())
        .def(operator_suite<I3MCTree>())
      ;
    
/*
    enum_<NuEventType>("NuEventType")
      .value("CHARGED_CURRENT",CHARGED_CURRENT)
      .value("NEUTRAL_CURRENT",NEUTRAL_CURRENT)
      .value("GLASHOW_RESONANCE",GLASHOW_RESONANCE)
      .value("NO_INTERACTION",NO_INTERACTION)
      .export_values()
      ;*/
  }
  
  register_pointer_conversions<I3MCTree>();
}
#undef WRAP_PROP_FN
#undef WRAP_PROP_BARE
