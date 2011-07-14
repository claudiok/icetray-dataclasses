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

#include <dataclasses/physics/I3FlasherInfo.h>
#include "dataclasses/I3Vector.h"
#include <dataclasses/physics/I3DOMLaunch.h>
#include <icetray/python/std_vector_indexing_suite.hpp>

using namespace boost::python;

// Provide DerivedPolicies to override contains(), 
// which would otherwise use std::find, which in turn
// requires operator()==, which we don't have
namespace boost { namespace python { namespace detail {
   template <class Container, bool NoProxy = false>
   class vector_no_equality : public vector_indexing_suite<Container, NoProxy, vector_no_equality<Container, NoProxy > > {
      public:

         typedef typename Container::value_type key_type;

         static bool
         contains(Container& container, key_type const& key)
         {
            PyErr_SetString(PyExc_TypeError,"This vector does not support __contains__().");
            throw_error_already_set();

            return false; 
         }
    };
} } }

void register_I3FlasherInfo()
{
 const std::vector<int>& (I3FlasherInfo::*get_waveform)() const = &I3FlasherInfo::GetRawATWD3;
 {
   scope outer = 
   class_<I3FlasherInfo, bases<I3FrameObject>, I3FlasherInfoPtr>("I3FlasherInfo")
#define PROPS (FlashingOM)(FlashTime)(ATWDBinSize)(LEDBrightness)(Mask)(Width)(Rate)
     BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_NC, I3FlasherInfo, PROPS)
     #undef PROPS
     .add_property("RawATWD3", make_function(get_waveform,return_internal_reference<1>()), &I3FlasherInfo::SetRawATWD3)
   ;

 }

 class_<I3FlasherInfoVect, bases<I3FrameObject>, I3FlasherInfoVectPtr>("I3FlasherInfoVect")
   .def(std_vector_indexing_suite<I3FlasherInfoVect, 
        false, detail::vector_no_equality<I3FlasherInfoVect> >())
   ;

 register_pointer_conversions<I3FlasherInfo>();
 register_pointer_conversions<I3FlasherInfoVect>();
}
