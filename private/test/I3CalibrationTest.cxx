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
    I3Calibration* calib = new I3Calibration();
      
    I3InIceCalibration& inice_calib = calib->GetInIceCalibration();
    
    I3DOMCalibrationPtr dom_calib(new I3DOMCalibration);
    
    int id = 0;
    int channel = 0;
    int bin = 127;  //Set() method expects time reversed order.this is earliest bin
    
    LinearFit fit;  
    fit.slope = -0.002*I3Units::V;  // volt/count
    fit.intercept = 2.9*I3Units::V; 
    
    const double temp = 900.00;
    
    
    

    double gain = -17.0;
    
    dom_calib->SetTemperature(temp);
    
    dom_calib->SetATWDGain(channel,gain);
    
    dom_calib->SetATWDBinCalibFit(id,
				  channel,
				  bin,
				  fit);

    inice_calib[OMKey(20,20)] = dom_calib;
    
    I3DOMCalibrationPtr domptr = inice_calib[OMKey(20,20)];
      
    ENSURE_DISTANCE(gain, 
		    domptr->GetATWDGain(channel), 
		    0.0001,
		    "Failed to get proper gain from I3DOMCalibration");
      
    bin = 0; //We store the domcal info in proper time order

    //check we got what we stored.
    ENSURE_DISTANCE(900.00,
		    domptr->GetTemperature(),0.1,
		    "Temperature came back from storage with wrong value");



    ENSURE_DISTANCE(-0.002,
		    domptr->GetATWDBinCalibFit(id,channel,bin).slope/I3Units::V,
		    0.0001,
		    "Failed to properly return fit slope (test1)");

    ENSURE_DISTANCE(2.9,
		    domptr->GetATWDBinCalibFit(id,channel,bin).intercept/I3Units::V,
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

