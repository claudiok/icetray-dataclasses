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

#include <dataclasses/physics/I3Waveform.h>
#include <icetray/python/std_map_indexing_suite.hpp>
#include <icetray/python/std_vector_indexing_suite.hpp>
#include <icetray/python/copy_suite.hpp>

using namespace boost::python;

void register_I3Waveform()
{
  std::vector<double>& (I3Waveform::*get_waveform)() = &I3Waveform::GetWaveform;
  const std::vector<I3Waveform::StatusCompound>& 
    (I3Waveform::*get_waveform_information)() const = &I3Waveform::GetWaveformInformation;
  object get_waveform_func = make_function(get_waveform, return_internal_reference<1>());
  object get_waveform_information_func = make_function(get_waveform_information, return_internal_reference<1>());

  {
    scope waveform_scope =
      class_<I3Waveform, bases<I3FrameObject>, boost::shared_ptr<I3Waveform> >("I3Waveform")
      .def(copy_suite<I3Waveform>())
      .def("GetStartTime", &I3Waveform::GetStartTime)
      .def("SetStartTime", &I3Waveform::SetStartTime)
      .def("GetBinWidth", &I3Waveform::GetBinWidth)
      .def("SetBinWidth", &I3Waveform::SetBinWidth)
      .def("GetWaveform", get_waveform_func)
      .def("SetWaveform", &I3Waveform::SetWaveform)
      .def("GetWaveformInformation", get_waveform_information_func)
	#define PROPS (StartTime)(BinWidth)(Source)
	BOOST_PP_SEQ_FOR_EACH(WRAP_PROP, I3Waveform, PROPS)
      .add_property("waveform",get_waveform_func,&I3Waveform::SetWaveform)
      .add_property("waveform_information",get_waveform_information_func)
      // for static methods you need the both of these
      .def("GetStatus", &I3Waveform::GetStatus)
      .staticmethod("GetStatus")
      ;

    const std::pair<unsigned long long int, unsigned long long int>&
      (I3Waveform::StatusCompound::* get_interval)() const 
      = &I3Waveform::StatusCompound::GetInterval;

    class_<I3Waveform::StatusCompound>("StatusCompound")
      .def("GetInterval", get_interval, return_value_policy<copy_const_reference>())
      .def("GetStatus", &I3Waveform::StatusCompound::GetStatus)
      .def("SetStatus", &I3Waveform::StatusCompound::SetStatus)
      ;

    enum_<I3Waveform::Source>("Source")
      .value("ATWD", I3Waveform::ATWD)
      .value("FADC", I3Waveform::FADC)
      .value("TWR_ELECTRICAL", I3Waveform::TWR_ELECTRICAL)
      .value("TWR_OPTICAL", I3Waveform::TWR_OPTICAL)
      .value("ETC", I3Waveform::ETC)
      .export_values()
      ;

    enum_<I3Waveform::Status>("Status")
      .value("VIRGINAL", I3Waveform::VIRGINAL)
      .value("SHADY", I3Waveform::SHADY)
      .value("ADULTERATED", I3Waveform::ADULTERATED)
      .export_values()
      ;
  }

  class_<std::vector<I3Waveform> >("I3WaveformSeries")
    .def(std_vector_indexing_suite<std::vector<I3Waveform> >())
    .def(copy_suite<std::vector<I3Waveform> >())
    ;

  class_<std::vector<I3Waveform::StatusCompound> >("VectorI3WaveformStatusCompound")
    .def(std_vector_indexing_suite<std::vector<I3Waveform::StatusCompound> >())
    .def(copy_suite<std::vector<I3Waveform::StatusCompound> >())
    ;

  class_<I3WaveformSeriesMap, bases<I3FrameObject>, I3WaveformSeriesMapPtr>("I3WaveformSeriesMap")
    .def(std_map_indexing_suite<I3WaveformSeriesMap>())
    .def(copy_suite<I3WaveformSeriesMap>())
    ;

  register_pointer_conversions<I3WaveformSeriesMap>();
}
