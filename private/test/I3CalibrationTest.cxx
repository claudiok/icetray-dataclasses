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

// Test conversion back and forth from counts to volts
TEST(conversion_counts_to_volts)
{	
    try
    {
	I3Calibration* calib = new I3Calibration();
      
	I3InIceCalibration& inice_calib = calib->GetInIceCalibration();
      
	I3DOMCalibPtr dom_calib(new I3DOMCalibration);
      
	int id = 0;
	int channel = 0;
	int bin = 127;
      
	// NOTE: In next iteration test the units
	double slope = -0.002;  // volt/count
	double intercept = 2.9; // volt
	double regress_coeff = 0.99; 
	double gain = -17.0;
	double gainErr = 0.0;

	double fe_pedestal = 2.6; // volt
	int count = 100;

	dom_calib->SetATWDGain(channel,gain,gainErr);
	dom_calib->SetATWDParameters(id,channel,bin,slope,intercept,regress_coeff);
      
	inice_calib[OMKey(20,20)] = dom_calib;
      
	I3DOMCalibPtr domptr = inice_calib[OMKey(20,20)];
      
	ENSURE_DISTANCE(gain, domptr->GetATWDGain(0), 0.0001,
			"Failed to get gain from "
			"I3DOMCalibration ptr");
      
	ENSURE_DISTANCE(intercept, 
			domptr->GetATWDVoltage(0,0,0,0.0,0)*gain, 
			0.0001,
			"Failed to get voltage from "
			"I3DOMCalibration ptr");

	
	double voltage = domptr->GetATWDVoltage(0,0,0, fe_pedestal, count);

	ENSURE_DISTANCE(count,
			domptr->GetATWDCount(0,0,0, fe_pedestal, voltage),
			0.0001,
			"Failed to convert count to voltage");
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
      
	double gainErr = 0.0;
      
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

