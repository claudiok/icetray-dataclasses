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

#include <dataclasses/calibration/I3DOMCalibration.h>
#include <icetray/python/copy_suite.hpp>
#include <icetray/python/indexed_property.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>

using namespace boost::python;

void register_I3DOMCalibration()
{

  {

    scope outer = 
      class_<I3DOMCalibration, boost::shared_ptr<I3DOMCalibration> >("I3DOMCalibration")
      .def(copy_suite<I3DOMCalibration>())
      #define I3DOMCALPROPS (Temperature)(TransitTime)(HVGainFit)(FADCGain)           \
                            (FADCBaselineFit)(FADCBeaconBaseline)(FrontEndImpedance)  \
                            (TauParameters)(FADCGain)(FADCDeltaT)(DOMCalVersion)      \
                            (ATWDResponseWidth)(FADCResponseWidth)(SPEDiscCalib)      \
                            (MPEDiscCalib)(PMTDiscCalib)(DomNoiseRate)(RelativeDomEff)\
                            (ToroidType)(DomNoiseThermalRate)(DomNoiseDecayRate)      \
                            (DomNoiseScintillationMean)(DomNoiseScintillationSigma)   \
                            (DomNoiseScintillationHits)
      BOOST_PP_SEQ_FOR_EACH(WRAP_PROP, I3DOMCalibration, I3DOMCALPROPS)
      #undef I3DOMCALPROPS
      #define EVIL_PROPS (ATWDBaseline)(ATWDBeaconBaseline)(ATWDDeltaT) \
                         (ATWDFreqFit)(ATWDGain)(ATWDBinCalibFit)
      BOOST_PP_SEQ_FOR_EACH(WRAP_EVIL_PROP, I3DOMCalibration, EVIL_PROPS)
      #undef EVIL_PROPS
      .def("atwd_pulse_template", &I3DOMCalibration::ATWDPulseTemplate)
      .def("fadc_pulse_template", &I3DOMCalibration::FADCPulseTemplate)
      .def("discriminator_pulse_template", &I3DOMCalibration::DiscriminatorPulseTemplate)
      .def_pickle(boost_serializable_pickle_suite<I3DOMCalibration>())
      .def( freeze() )
      ;

    enum_<I3DOMCalibration::ToroidType>("ToroidType")
      .value("OLD_TOROID", I3DOMCalibration::OLD_TOROID)
      .value("NEW_TOROID", I3DOMCalibration::NEW_TOROID)
      .export_values()
      ;

  }

}
