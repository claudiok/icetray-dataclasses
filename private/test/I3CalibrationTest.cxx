
#include <I3Test.h>

#include "dataclasses/calibration/I3Calibration.h"
#include "dataclasses/calibration/I3DOMCalibration.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/I3Units.h"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

TEST_GROUP(I3DOMCalibrationTest);

// Test conversion back and forth from counts to volts
TEST(bin_parameters)
{	
    I3CalibrationPtr calib(new I3Calibration());
    OMKey omkey(20,20);
    
    I3DOMCalibration dom_calib;
    
    int id = 0;
    int channel = 0;
    int bin = 127;  //Set() method expects time reversed order.this is earliest bin
    
    LinearFit fit;  
    fit.slope = -0.002*I3Units::V;  // volt/count
    fit.intercept = 2.9*I3Units::V; 
    
    const double temp = 900.00;
    
    
    

    double gain = -17.0;
    
    dom_calib.SetTemperature(temp);
    
    dom_calib.SetATWDGain(channel,gain);
    
    dom_calib.SetATWDBinCalibFit(id,
				  channel,
				  bin,
				  fit);

    calib->domCal[omkey] = dom_calib;
    
      
    ENSURE_DISTANCE(gain, 
		    calib->domCal[omkey].GetATWDGain(channel), 
		    0.0001,
		    "Failed to get proper gain from I3DOMCalibration");
      
    bin = 0; //We store the domcal info in proper time order

    //check we got what we stored.
    ENSURE_DISTANCE(900.00,
		    calib->domCal[omkey].GetTemperature(),0.1,
		    "Temperature came back from storage with wrong value");



    ENSURE_DISTANCE(-0.002,
		    calib->domCal[omkey].GetATWDBinCalibFit(id,channel,bin).slope/I3Units::V,
		    0.0001,
		    "Failed to properly return fit slope (test1)");

    ENSURE_DISTANCE(2.9,
		    calib->domCal[omkey].GetATWDBinCalibFit(id,channel,bin).intercept/I3Units::V,
		    0.0001,
		    "Failed to properly return count (test2)");
    

}

// Test I/O streams
TEST(to_stream)
{	
    I3DOMCalibrationPtr dom_calib(new I3DOMCalibration);
    
    int id = 0;
    int channel = 0;
    int bin = 1;

    LinearFit fit;      
    fit.slope = -0.002*I3Units::V;
    fit.intercept = 2.9*I3Units::V; 
    double gain = -17.0;
	
    
    dom_calib->SetATWDGain(channel,gain);
    dom_calib->SetATWDBinCalibFit(id,channel,bin,fit);
    
    dom_calib->ToStream(cout);
}


