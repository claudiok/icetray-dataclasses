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
      PROPERTY(I3DOMCalibration, Temperature, Temperature)
      PROPERTY(I3DOMCalibration, TransitTime, TransitTime)
      PROPERTY(I3DOMCalibration, HVGainFit, HVGainFit)
      PROPERTY(I3DOMCalibration, FADCGain, FADCGain)
      PROPERTY(I3DOMCalibration, FADCBaselineFit, FADCBaselineFit)
      PROPERTY(I3DOMCalibration, FrontEndImpedance, FrontEndImpedance)
      PROPERTY(I3DOMCalibration, TauParameters, TauParameters)
      PROPERTY(I3DOMCalibration, FADCGain, FADCGain)
      PROPERTY(I3DOMCalibration, FADCBaselineFit, FADCBaselineFit)
      PROPERTY(I3DOMCalibration, FADCDeltaT, FADCDeltaT)
      PROPERTY(I3DOMCalibration, FrontEndImpedance, FrontEndImpedance)
      PROPERTY(I3DOMCalibration, ATWDGain, ATWDGain)
      PROPERTY(I3DOMCalibration, ATWDDeltaT, ATWDDeltaT)
      PROPERTY(I3DOMCalibration, ATWDFreqFit, ATWDFreqFit)
      PROPERTY(I3DOMCalibration, DOMCalVersion, DOMCalVersion)
      PROPERTY(I3DOMCalibration, ATWDBaseline, ATWDBaseline)
      PROPERTY(I3DOMCalibration, ATWDResponseWidth, ATWDResponseWidth)
      PROPERTY(I3DOMCalibration, FADCResponseWidth, FADCResponseWidth)
      PROPERTY(I3DOMCalibration, FADCResponseWidth, FADCResponseWidth)
      PROPERTY(I3DOMCalibration, SPEDiscCalib, SPEDiscCalib)
      PROPERTY(I3DOMCalibration, MPEDiscCalib, MPEDiscCalib)
      ;

  }

  register_pointer_conversions<I3Calibration>();
}