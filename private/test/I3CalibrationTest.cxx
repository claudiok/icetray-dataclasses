#include "TUT/tut.h"

#include "dataclasses/I3Calibration.h"
#include "dataclasses/I3InIceCalibration.h"
#include "dataclasses/I3DOMCalibration.h"

#include "TFile.h"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

namespace tut
{
    struct I3CalibrationTest
    {};
    
    typedef test_group<I3CalibrationTest> factory;
    typedef factory::object object;
}

namespace
{
    static tut::factory t("I3CalibrationTest");
    
}

namespace tut 
{
    template<> template<>
    void object::test<1>()
    {	
	I3Calibration* calib = new I3Calibration();
	
	calib->ls();

	I3InIceCalibration& inice_calib = calib->GetInIceCalibration();
	
	inice_calib.ls();
	
	I3DOMCalibPtr dom_calib(new I3DOMCalibration);

	dom_calib->ls();
	
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

	inice_calib[OMKey(20,20)] = dom_calib;

	//cout<<"Opening ROOT file for writing"<<endl;
	
	TFile fileOut("test.root","RECREATE");
	
	//cout<<"Writing calibration to file"<<endl;
	
	calib->Write();
	
	//cout<<"Closing file"<<endl;
	
	fileOut.Close();
	
	//cout<<"Opening file"<<endl;
	
	TFile fileIn("test.root");
	
	//cout<<"Reading in calibration from file"<<endl;
	
	I3Calibration* calib_in = (I3Calibration*) fileIn.FindObjectAny("I3Calibration");
	ensure("Failed to find I3Calibration object on disk",
	       calib_in != 0);
	
	//cout<<"Contents of calibration from file:"<<endl;
	
	calib_in->ls();

	I3InIceCalibration& inice = calib_in->GetInIceCalibration();

	inice.ls();

	I3DOMCalibPtr domptr = inice_calib[OMKey(20,20)];
	
	ensure("Failed to get I3DOMCalibration",
	       calib_in->GetInIceCalibration()[OMKey(20,20)] != I3DOMCalibPtr((I3DOMCalibration*)0) );

	domptr->ls();

	ensure_distance("Failed to get gain from I3DOMCalibration read from disk", 
			gain, domptr->GetATWDGain(0), 0.0001);
	
	ensure_distance("Failed to get voltage from I3DOMCalibration read from disk",
			intercept, domptr->GetATWDVoltage(0, 0, 0, 0.0), 0.0001);

	//cout<<"Gain: "<< domptr->GetATWDGain(0) <<endl;
    }
}
