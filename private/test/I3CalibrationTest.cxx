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
	dom_calib->SetATWDBinParameters(id,channel,bin,slope,intercept,regress_coeff);
      
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

// Test baseline parameters
TEST(baseline_parameters)
{
    try
    {
	I3Calibration* calib = new I3Calibration();
	I3InIceCalibration& inice_calib = calib->GetInIceCalibration();
	I3DOMCalibPtr dom_calib(new I3DOMCalibration);
      
	// Set parameters here: Yes, I know it's ugly
	

	dom_calib->SetATWDBaselineParameters(0, 0, 1200*I3Units::V, 0.0021311853*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 1, 1200*I3Units::V, -3.8649596e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 2, 1200*I3Units::V, 1.5045324e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 0, 1200*I3Units::V, 0.0010479711*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 1, 1200*I3Units::V, -2.093523e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 2, 1200*I3Units::V, 4.4550316e-4*I3Units::V);

	dom_calib->SetATWDBaselineParameters(0, 0, 1300*I3Units::V, 0.0022805776*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 1, 1300*I3Units::V, -3.8092467e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 2, 1300*I3Units::V, 1.9525197e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 0, 1300*I3Units::V, 0.0012036572*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 1, 1300*I3Units::V, -1.986274e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 2, 1300*I3Units::V, 4.721305e-4*I3Units::V);

	dom_calib->SetATWDBaselineParameters(0, 0, 1400*I3Units::V, 0.002476789*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 1, 1400*I3Units::V, -4.4895257e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 2, 1400*I3Units::V, 1.9198915e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 0, 1400*I3Units::V, 0.0013408196*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 1, 1400*I3Units::V, -2.1567232e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 2, 1400*I3Units::V, 4.7289158e-4*I3Units::V);

	dom_calib->SetATWDBaselineParameters(0, 0, 1500*I3Units::V, 0.0026243115*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 1, 1500*I3Units::V, -5.1012635e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 2, 1500*I3Units::V, 1.8842256e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 0, 1500*I3Units::V, 0.0014135607*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 1, 1500*I3Units::V, -2.3106372e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 2, 1500*I3Units::V, 4.5968135e-4*I3Units::V);

	dom_calib->SetATWDBaselineParameters(0, 0, 1600*I3Units::V, 0.0028538548*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 1, 1600*I3Units::V, -5.491635e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 2, 1600*I3Units::V, 1.8574475e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 0, 1600*I3Units::V, 0.0015212294*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 1, 1600*I3Units::V, -2.3648492e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 2, 1600*I3Units::V, 6.0196675e-4*I3Units::V);

	dom_calib->SetATWDBaselineParameters(0, 0, 1700*I3Units::V, 0.0029737877*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 1, 1700*I3Units::V, -5.9185695e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(0, 2, 1700*I3Units::V, 1.4653799e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 0, 1700*I3Units::V, 0.0015711711*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 1, 1700*I3Units::V, -2.935434e-4*I3Units::V);
	dom_calib->SetATWDBaselineParameters(1, 2, 1700*I3Units::V, 5.4523064e-4*I3Units::V);

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
	
	// Test that you get back you put in for a HV value
 	double HV = 1899*I3Units::V;
	
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

