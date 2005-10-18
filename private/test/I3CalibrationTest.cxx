#include <I3Test.h>

#include "dataclasses/I3Calibration.h"
#include "dataclasses/I3InIceCalibration.h"
#include "dataclasses/I3DOMCalibration.h"
#include "dataclasses/I3CalibrationHeader.h"
#include "dataclasses/I3Units.h"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

TEST_GROUP(I3CalibrationTest);

// Test conversion back and forth from counts to volts
TEST(bin_parameters)
{	
    try
    {
	I3Calibration* calib = new I3Calibration();
      
	I3InIceCalibration& inice_calib = calib->GetInIceCalibration();
      
	I3DOMCalibPtr dom_calib(new I3DOMCalibration);
      
	int id = 0;
	int channel = 0;
	int bin = 127;
      
	double slope = -0.002*I3Units::mV;  // volt/count
	double intercept = 2.9*I3Units::V; 
	double regress_coeff = 0.99; 
	double gain = -17.0;
	double gainErr = 0.0;

	double fe_pedestal = 2.6*I3Units::V;
	int count = 100;

	dom_calib->SetATWDGain(channel,gain,gainErr);

	dom_calib->SetATWDBinParameters(id,
					channel,
					bin,
					slope,
					intercept,
					regress_coeff);

	dom_calib->SetATWDBaselineParameters(id, channel, 
					     1200*I3Units::V, 
					     0.0);
	
	dom_calib->SetATWDBaselineParameters(id, channel, 
					     1300*I3Units::V, 
					     0.0);

	double HV = 1250*I3Units::V;
					     
	inice_calib[OMKey(20,20)] = dom_calib;
      
	I3DOMCalibPtr domptr = inice_calib[OMKey(20,20)];
      
	ENSURE_DISTANCE(gain, 
			domptr->GetATWDGain(channel), 
			0.0001,
			"Failed to get gain from I3DOMCalibration");
      
	ENSURE_DISTANCE(intercept, 
			domptr->GetATWDVoltage(id,channel,bin,0.0,HV,0), 
			0.0001*I3Units::V,
			"Failed to get fit.intercept from I3DOMCalibration");

	ENSURE_DISTANCE(domptr->GetATWDBinIntercept(id,channel,bin),
			domptr->GetATWDVoltage(id,channel,bin,0.0,HV,0),
			0.0001*I3Units::V,
			"Failed to get fit.intercept from I3DOMCalibration");
	
	double voltage = domptr->GetATWDVoltage(id,channel,bin,fe_pedestal,HV,count);
	
	ENSURE_DISTANCE(count,
			domptr->GetATWDCount(id,channel,bin,fe_pedestal,HV,voltage),
			0.0001,
			"Failed to convert count to voltage");
    }
  
    catch(exception& e)
    {
	ENSURE("No exceptions thrown ",0);
    }
}

// Test baseline parameters
TEST(baseline_parameters)
{
    try
    {
	I3Calibration* calib = new I3Calibration();
	I3InIceCalibration& inice_calib = calib->GetInIceCalibration();
	I3DOMCalibPtr dom_calib(new I3DOMCalibration);
      
	dom_calib->SetATWDBaselineParameters(0, 0, 1800*I3Units::V, 0.0030828859*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 1, 1800*I3Units::V, -6.415634e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 2, 1800*I3Units::V, 1.4792923e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 0, 1800*I3Units::V, 0.0016722014*I3Units::V);	
	dom_calib->SetATWDBaselineParameters(1, 1, 1800*I3Units::V, -2.7254072e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 2, 1800*I3Units::V, 6.474013e-4*I3Units::V);

	dom_calib->SetATWDBaselineParameters(0, 0, 1900*I3Units::V, 0.003377001*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 1, 1900*I3Units::V, -6.809217e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 2, 1900*I3Units::V, 1.644716e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 0, 1900*I3Units::V, 0.0018482722*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 1, 1900*I3Units::V, -3.1075595e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 2, 1900*I3Units::V, 6.432433e-4*I3Units::V);

	inice_calib[OMKey(20,20)] = dom_calib;
	I3DOMCalibPtr domptr = inice_calib[OMKey(20,20)];
	
	// Test that you get back what you put in for a HV value
 	double HV = 1899*I3Units::V;
	
	/*
	ENSURE_DISTANCE(0.003377001*I3Units::V, 
			domptr->GetATWDBaseline(0,0,HV), 0.0001*I3Units::V,
			"Failed to get baseline from I3DOMCalibration");

	ENSURE_DISTANCE(-6.809217e-4*I3Units::V, 
			domptr->GetATWDBaseline(0,1,HV), 0.0001*I3Units::V,
			"Failed to get baseline from I3DOMCalibration");

	ENSURE_DISTANCE(1.644716e-4*I3Units::V, 
			domptr->GetATWDBaseline(0,2,HV), 0.0001*I3Units::V,
			"Failed to get baseline from I3DOMCalibration");

	ENSURE_DISTANCE(0.0018482722*I3Units::V, 
			domptr->GetATWDBaseline(1,0,HV), 0.0001*I3Units::V,
			"Failed to get baseline from I3DOMCalibration");
	
	ENSURE_DISTANCE(-3.1075595e-4*I3Units::V, 
			domptr->GetATWDBaseline(1,1,HV), 0.0001*I3Units::V,
			"Failed to get baseline from I3DOMCalibration");
	
	ENSURE_DISTANCE(6.432433e-4*I3Units::V, 
			domptr->GetATWDBaseline(1,2,HV), 0.0001*I3Units::V,
			"Failed to get baseline from I3DOMCalibration");
	*/
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
	dom_calib->SetATWDBinParameters(id,channel,bin,slope,intercept,regress_coeff);
      
	dom_calib->ToStream(cout);
	cout<< dom_calib;
    }
  
    catch(exception& e)
    {
	ENSURE("No exceptions thrown",0);
    }
}

