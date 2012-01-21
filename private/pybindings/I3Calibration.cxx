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

#include <dataclasses/calibration/I3Calibration.h>
#include <icetray/python/std_map_indexing_suite.hpp>
#include <icetray/python/copy_suite.hpp>
#include <icetray/python/indexed_property.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>

using namespace boost::python;

void register_I3Calibration()
{
  class_<I3Calibration, bases<I3FrameObject>, boost::shared_ptr<I3Calibration> >("I3Calibration")
    .def(copy_suite<I3Calibration>())
    #define I3CALPROPS (startTime)(endTime)(domCal)(vemCal)
    BOOST_PP_SEQ_FOR_EACH(WRAP_RW_RECASE, I3Calibration, I3CALPROPS)
    #undef I3CALPROPS
    .def_pickle(boost_serializable_pickle_suite<I3Calibration>())
    .def( freeze() )
    ;

  class_<std::map<OMKey, I3DOMCalibration> >("Map_OMKey_I3DOMCalibration")
    .def(std_map_indexing_suite<std::map<OMKey, I3DOMCalibration> >())
    .def_pickle(boost_serializable_pickle_suite<std::map<OMKey, I3DOMCalibration> >())
    ;

  //=======================================================================
  class_<std::map<OMKey, I3VEMCalibration> >("Map_OMKey_I3VEMCalibration")
    .def(std_map_indexing_suite<std::map<OMKey, I3VEMCalibration> >())
    .def_pickle(boost_serializable_pickle_suite<std::map<OMKey, I3VEMCalibration> >())
    ;
  //=======================================================================

    
  //
  // I3DOMCalibration
  //
  {
 
    class_<LinearFit>("LinearFit")
      .def_readwrite("slope", &LinearFit::slope)
      .def_readwrite("intercept", &LinearFit::intercept)
      .def_pickle(boost_serializable_pickle_suite<LinearFit>())
      .def( freeze() )
      ;

    class_<I3VEMCalibration>("I3VEMCalibration")
      .def(copy_suite<I3VEMCalibration>())
      #define I3VEMCALPROPS (pePerVEM)(muPeakWidth)(hglgCrossOver)(corrFactor) 
      BOOST_PP_SEQ_FOR_EACH(WRAP_RW_RECASE, I3VEMCalibration, I3VEMCALPROPS)
      #undef I3VEMCALPROPS
      .def_pickle(boost_serializable_pickle_suite<I3VEMCalibration>())
      .def( freeze() )
      ;

    class_<QuadraticFit>("QuadraticFit")
      .def_readwrite("quad_fit_a", &QuadraticFit::quadFitA)
      .def_readwrite("quad_fit_b", &QuadraticFit::quadFitB)
      .def_readwrite("quad_fit_v", &QuadraticFit::quadFitC)
      .def_pickle(boost_serializable_pickle_suite<QuadraticFit>())
      .def( freeze() )
      ;

    class_<TauParam>("TauParam")
      .def_readwrite("p0", &TauParam::P0)
      .def_readwrite("p1", &TauParam::P1)
      .def_readwrite("p2", &TauParam::P2)
      .def_readwrite("p3", &TauParam::P3)
      .def_readwrite("p4", &TauParam::P4)
      .def_readwrite("p5", &TauParam::P5)
      .def_readwrite("tau_frac", &TauParam::TauFrac)
      .def_pickle(boost_serializable_pickle_suite<TauParam>())
      .def( freeze() )
      ;
	  
    class_<SPETemplate>("SPETemplate")
      .def_readwrite("c", &SPETemplate::c)
      .def_readwrite("x0", &SPETemplate::x0)
      .def_readwrite("b1", &SPETemplate::b1)
      .def_readwrite("b2", &SPETemplate::b2)
      .def( freeze() )
      ;
    
    class_<I3DOMCalibration::DroopedSPETemplate>("DroopedSPETemplate",no_init)
      .def(init<const SPETemplate&>())
      .def(init<const SPETemplate&,const SPETemplate&,double,double,double>())
      .def("__call__",&I3DOMCalibration::DroopedSPETemplate::operator())
      .def(freeze())
      ;

    scope outer = 
      class_<I3DOMCalibration, boost::shared_ptr<I3DOMCalibration> >("I3DOMCalibration")
      .def(copy_suite<I3DOMCalibration>())
      #define I3DOMCALPROPS (Temperature)(TransitTime)(HVGainFit)(FADCGain)           \
                            (FADCBaselineFit)(FADCBeaconBaseline)(FrontEndImpedance)  \
                            (TauParameters)(FADCGain)(FADCDeltaT)(DOMCalVersion)      \
                            (ATWDResponseWidth)(FADCResponseWidth)(SPEDiscCalib)      \
                            (MPEDiscCalib)(PMTDiscCalib)(DomNoiseRate)(RelativeDomEff)
      BOOST_PP_SEQ_FOR_EACH(WRAP_PROP, I3DOMCalibration, I3DOMCALPROPS)
      #undef I3DOMCALPROPS
      // XXX Note:  These are some ugly interfaces from I3DOMCalibration that 
      //     proved to be difficult to handle in boost::python.  Left exposed for
      //     expert use, but proper pybindings here will have to wait for an
      //     updated I3DOMCalibration class  XXX 
      //      See TRAC ticket #300
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

  }

  register_pointer_conversions<I3Calibration>();
}
