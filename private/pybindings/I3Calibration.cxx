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

#include <dataclasses/status/I3Calibration.h>

using namespace boost::python;

void register_I3Calibration()
{
  class_<I3Calibration, bases<I3FrameObject>, boost::shared_ptr<I3Calibration> >("I3Calibration")
    .def_readwrite("startTime", &I3Calibration::startTime)
    .def_readwrite("endTime", &I3Calibration::endTime)
    .def_readwrite("domCal", &I3Calibration::domCal)
    //.def_readwrite("amandaCal", &I3Calibration::amandaCal)
    //.def_readwrite("vemCal", &I3Calibration::vemCal)
    //.def_readwrite("twrCal", &I3Calibration::twrCal)
    .def_readwrite("TWRGlobalT0", &I3Calibration::TWRGlobalT0)
    .def_readwrite("TWRI3TimeOffset", &I3Calibration::TWRI3TimeOffset)
    ;

  class_<std::map<OMKey, I3DOMCalibration> >("Map_OMKey_I3DOMCalibration")
    .def(map_indexing_suite<std::map<OMKey, I3DOMCalibration> >())
    ;
    
  //
  // I3DOMCalibration
  //
  {
 
    class_<LinearFit>("LinearFit")
      .def_readwrite("slope", &LinearFit::slope)
      .def_readwrite("intercept", &LinearFit::intercept)
      ;

    class_<QuadraticFit>("QuadraticFit")
      .def_readwrite("quadFitA", &QuadraticFit::quadFitA)
      .def_readwrite("quadFitB", &QuadraticFit::quadFitB)
      .def_readwrite("quadFitC", &QuadraticFit::quadFitC)
      ;

    class_<TauParam>("TauParam")
      .def_readwrite("P0", &TauParam::P0)
      .def_readwrite("P1", &TauParam::P1)
      .def_readwrite("P2", &TauParam::P2)
      .def_readwrite("P3", &TauParam::P3)
      .def_readwrite("P4", &TauParam::P4)
      .def_readwrite("P5", &TauParam::P5)
      .def_readwrite("TauFrac", &TauParam::TauFrac)
      ;

    scope outer = 
      class_<I3DOMCalibration, boost::shared_ptr<I3DOMCalibration> >("I3DOMCalibration")
      .def_readwrite("temperature", &I3DOMCalibration::temperature)
      .def_readwrite("fadcGain", &I3DOMCalibration::fadcGain)
      .def_readwrite("fadcBaselineFit", &I3DOMCalibration::fadcBaselineFit)
      .def_readwrite("fadcDeltaT", &I3DOMCalibration::fadcDeltaT)
      .def_readwrite("frontEndImpedance", &I3DOMCalibration::frontEndImpedance)
      .def_readwrite("tauparameters", &I3DOMCalibration::tauparameters)
      .def_readwrite("ampGains", &I3DOMCalibration::ampGains)
      .def_readwrite("atwdFreq", &I3DOMCalibration::atwdFreq)
      .def_readwrite("atwdBin0", &I3DOMCalibration::atwdBin0)
      .def_readwrite("atwdBin1", &I3DOMCalibration::atwdBin1)
      .def_readwrite("pmtTransitTime", &I3DOMCalibration::pmtTransitTime)
      .def_readwrite("hvGainRelation", &I3DOMCalibration::hvGainRelation)
      .def_readwrite("domcalVersion", &I3DOMCalibration::domcalVersion)
      .def_readwrite("atwdBaselines", &I3DOMCalibration::atwdBaselines)
      .def_readwrite("atwdResponseWidth", &I3DOMCalibration::atwdResponseWidth)
      .def_readwrite("fadcResponseWidth", &I3DOMCalibration::fadcResponseWidth)
      .def_readwrite("atwdDeltaT", &I3DOMCalibration::atwdDeltaT)
      .def_readwrite("speDiscrimCalib", &I3DOMCalibration::speDiscrimCalib)
      .def_readwrite("mpeDiscrimCalib", &I3DOMCalibration::mpeDiscrimCalib)
      ;

  }

  register_pointer_conversions<I3Calibration>();
}
