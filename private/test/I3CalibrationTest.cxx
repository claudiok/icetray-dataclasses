#include "TUT/tut.h"

#include "dataclasses/I3Calibration.h"
#include "dataclasses/I3InIceCalibration.h"
#include "dataclasses/I3DOMCalibration.h"
#include "dataclasses/I3CalibrationHeader.h"

#include "icetray/I3TrayException.h"

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
    // Test file I/O
    template<> template<>
    void object::test<1>()
    {	
	try
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
	
	    TFile fileOut("test.root", "RECREATE");
	    calib->Write();
	    fileOut.Close();
	
	    TFile fileIn("test.root");
	
	    I3Calibration* calib_in = 
		(I3Calibration*) fileIn.FindObjectAny("I3Calibration");
	    ensure("Failed to find I3Calibration object on disk",
		   calib_in != 0);
	
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
			  intercept, domptr->GetATWDVoltage(0, 0, 128, 0), 0.0001);
      }

	catch(I3TrayException& e)
	{
	    ensure("No exceptions thrown",0);
	}
    }

    //
    template<> template<>
    void object::test<2>()
    {
	try
	{
	    I3DOMCalibration dom;
      
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
      
	    dom.SetATWDGain(channel,gain,gainErr);
	    dom.SetATWDParameters(id,channel,bin,slope,intercept,regress_coeff);
      
	    ensure_distance("Failed to get gain from I3DOMCalibration", 
			    gain, 
			    dom.GetATWDGain(0), 
			    0.0001);
      
	    ensure_distance("Failed to get voltage from I3DOMCalibration ",
			    intercept, 
			    dom.GetATWDVoltage(0, 0, 128, 0), 0.0001);
	}

	catch(I3TrayException& e)
	{
	    ensure("No Exceptions Thrown",0);
	}
    }

    // Test I/O streams
    template<> template<>
    void object::test<3>()
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

	catch(I3TrayException& e)
	{
	    ensure("No exceptions thrown",0);
	}
    }

    // Test Calibration header
    template<> template<>
    void object::test<4>()
    {	
	try
	{
	    I3CalibrationHeader header;
	    
	    I3Time time(1,1,1);
	    header.SetTime(time);

	    cout<< header.GetTime().GetJulianDay() <<endl;
	    cout<< header.GetTime().GetJulianSec() <<endl;
	    cout<< header.GetTime().GetJulianNanoSec() <<endl;

	    ensure("Failed to get julian day from calibration header", 
		   header.GetTime().GetJulianDay() == 1);

	    ensure("Failed to get seconds from calibration header", 
		   header.GetTime().GetJulianSec() == 1);

	    ensure("Failed to get nanoseconds from calibration header", 
		   header.GetTime().GetJulianNanoSec() == 1);

	    header.ToStream(cout);
	    cout<< &header <<endl;	    
	}

	catch(I3TrayException& e)
	{
	    ensure("No exceptions thrown",0);
	}
    }

}
