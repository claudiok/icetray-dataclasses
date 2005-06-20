#include <I3Test.h>

#include "dataclasses/I3Calibration.h"
#include "dataclasses/I3InIceCalibration.h"
#include "dataclasses/I3DOMCalibration.h"
#include "dataclasses/I3CalibrationHeader.h"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

TEST_GROUP(I3CalibrationTest);

// Test file I/O
TEST(file_io)
{	
  try
    {
      I3Calibration* calib = new I3Calibration();
      //	    calib->ls();
      
      I3InIceCalibration& inice_calib = calib->GetInIceCalibration();
      //	    inice_calib.ls();
      
      I3DOMCalibPtr dom_calib(new I3DOMCalibration);
      //	    dom_calib->ls();
      
      int id = 0;
      int channel = 0;
      int bin = 127;
      
      double slope = -0.002;
      double intercept = 2.9; 
      double regress_coeff = 0.99;
      double gain = -17.0;
      
      double val;
      double gainErr = 0.0;
      
      val = slope;
      
      dom_calib->SetATWDGain(channel,gain,gainErr);
      dom_calib->SetATWDParameters(id,channel,bin,slope,intercept,regress_coeff);
      
      inice_calib[OMKey(20,20)] = dom_calib;
      
      I3DOMCalibPtr domptr = inice_calib[OMKey(20,20)];
      
      ENSURE_DISTANCE(gain, domptr->GetATWDGain(0), 0.0001,
		      "Failed to get gain from I3DOMCalibration "
		      "read from disk");
      ENSURE_DISTANCE(intercept, 
		      domptr->GetATWDVoltage(0, 0,0,0.0, 0)*gain, 
		      0.0001,
		      "Failed to get voltage from "
		      "I3DOMCalibration read from disk");
    }
  
  catch(exception& e)
    {
      ENSURE("No exceptions thrown ",0);
    }
}

  
  // Test I/O streams
TEST(to_stream)
{	
  try
    {
      I3DOMCalibPtr dom_calib(new I3DOMCalibration);
      
      int id = 0;
      int channel = 0;
      int bin = 128;
      
      double slope = -0.002;
      double intercept = 2.9; 
      double regress_coeff = 0.99;
      double gain = -17.0;
      
      double val;
      double gainErr = 0.0;
      
      val = slope;
      
      dom_calib->SetATWDGain(channel,gain,gainErr);
      dom_calib->SetATWDParameters(id,channel,bin,slope,intercept,regress_coeff);
      
      dom_calib->ToStream(cout);
      cout<< dom_calib;
    }
  
  catch(exception& e)
    {
      ENSURE("No exceptions thrown",0);
    }
}

