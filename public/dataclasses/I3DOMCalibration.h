/**
 *
 * Definition of I3DOMCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3DOMCalibration.h,v 1.12 2005/04/09 03:02:10 olivas Exp $
 *
 * @file I3DOMCalibration.h
 * @version $Revision: 1.12 $
 * @date $Date: 2005/04/09 03:02:10 $
 * @author tmccauley
 */
#ifndef I3DOMCALIBRATION_H
#define I3DOMCALIBRATION_H

#include "dataclasses/StoragePolicy.h"

#include <map>
#include <sstream>
#include <TObject.h>

using namespace std;

/**
 * @brief Class that stores the calibration information for a DOM
 * 
 * This class stores the information from the Calibration stream.
 *
 * ATTENTION:
 * Calibration information is set assuming the bin number as it is in
 * the calibration database (reversed in time for bins 0-127).
 * Calibration information is fetched by the time-oerdered bin numbers.
 *
 @author Tom McCauley

 @todo Not all of the calib. info. is dealt with here. Documentation
       needs to be added as well as units (or is that handled by the user?) 
*/

struct LinearFit
{
    double fSlope;
    double fIntercept;
    double fRegressCoeff;
};

class I3DOMCalibration : public TObject
{
public:
    double GetDate()
	{
	    return fDate;
	};
    
    unsigned int GetDOMId()
	{
	    return fDOMId;
	};
    
    double GetTemperature()
	{
	    return fTemperature;
	};
    
    double GetFADCGain()
	{
	    return fFADCGain;
	};
    
    double GetFADCPedestal()
	{
	    return fFADCPedestal;
	};
    
    // Get gain and error on gain for ATWD by channel
    double GetATWDGain(int channel);
    double GetATWDGainErr(int channel);
 
    // Return the voltage value corresponding to the count 
    // for a specific ATWD id, channel, and bin.

    double GetATWDVoltage(int id, int channel, int bin, int count);
    
    //map<int, double>& GetATWDVoltage(int id, int channel);
    

public:
    I3DOMCalibration();

    virtual ~I3DOMCalibration()
	{};
     
    // Perhaps this should take a time stamp as argument?
    void SetCalibrationConstants();

    void SetDate(double date)
	{
	    fDate = date;
	};
    
    void  SetDOMId(unsigned int id)
	{
	    fDOMId = id;
	};

    void SetTemperature(double temperature)
	{
	    fTemperature = temperature;
	};

    // Set parameters for conversion of count to voltage 
    // for each ATWD, each ATWD channel, and each ATWD bin.
    void SetATWDParameters(int id,
			   int channel,
			   int bin,
			   double slope,
			   double intercept,
			   double regress_coeff);
    
    void SetFADCParameters(double pedestal,
			   double gain)
	{
	    fFADCPedestal = pedestal;
	    fFADCGain     = gain;
	};
      
    // Set gain and error on gain for ATWD (specified by channel).
    void SetATWDGain(int channel, double gain, double gainErr);
  
    void SetHighVoltage(double voltage)
	{
	    fPMTHighVoltage = voltage;
	};
    
    double GetHighVoltage()
	{
	    return fPMTHighVoltage;
	};
    
    void SetSingleSPEThresholdVoltage(double voltage)
	{
	    fSingleSPEThresholdVoltage = voltage;
	};
    
    double GetSingleSPEThresholdVoltage()
	{
	    return fSingleSPEThresholdVoltage;
	};
    
    void SetPedestalVoltage(double voltage)
	{
	    fPedestalVoltage = voltage;
	};
    
    double GetPedestalVoltage()
	{
	    return fPedestalVoltage;
	};

    void SetPeakToValley(double p2v)
	{
	    fPeakToValley = p2v;
	};
    
    double GetPeakToValley()
	{
	    return fPeakToValley;
	};

    void SetSPEMean(double mean)
	{
	    fSPEMean = mean;
	};
    
    /*
    void SetOnePEinPC(double OnePE)
	{
	    fOnePEinPC = OnePE;
	};
    */

    double GetSPEMean()
	{
	    return fSPEMean;
	};
    
    /*
    double GetOnePEinPC()
	{
	    return fOnePEinPC;
	};
    */

    void SetSPEWidth(double width)
	{
	    fSPEWidth = width;
	};
    
    /*
    void SetWidth1PEinPC(double width1pe)
	{
	    fWidth1PEinPC = width1pe;
	};
    */

    double GetSPEWidth()
	{
	    return fSPEWidth;
	};
    
    /*
    double GetWidth1PEinPC()
	{
	    return fWidth1PEinPC;
	};
    */

    void SetSamplingRate(int id, double rate);
    
    double GetSamplingRate(int id);

    virtual void ToStream(ostream& o) const
    {
	o<<"[ "
	 <<"Calibration:"
	 <<"\tDate: "<<fDate<<endl
	 <<"\tDOM ID: "<<fDOMId<<endl
	 <<"\tSPE Mean: "<<fSPEMean<<endl
	 <<"\tPeak-to-Valley: "<<fPeakToValley<<endl
	 <<"\tSuppressing the rest of the output ]\n";
    };

    virtual string ToString() const
    {
	ostringstream out;
	ToStream(out);
	return out.str();
    };
    
private:
    // Simple data types

    // What is Date? UTC? GPS ns?
    double  fDate;  
    unsigned int    fDOMId;
    double  fTemperature;
    
    // Gain and pedestal values for FADC
    double fFADCGain;
    double fFADCPedestal;

    double fPMTHighVoltage;
    double fPedestalVoltage;
    double fSingleSPEThresholdVoltage;
   
    // Parameters describing the SPE charge distribution
    double fPeakToValley;
    double fSPEMean;
    double fSPEWidth; 

    //double fOnePEinPC;
    //double fWidth1PEinPC;

    double fSamplingRate0;
    double fSamplingRate1;

    // Gain and error on gain for ATWD channels.
    // The key corresponds to the channel.
    map<int, double> fAmpGains;
    map<int, double> fAmpGainErrs;
    
    // First key corresponds to channel.
    // Key in internal map corresponds to bin.
    map< int, map<int,LinearFit> > fATWD0;
    map< int, map<int,LinearFit> > fATWD1;
    map< int, map<int,LinearFit> >& GetATWDById(int id);

    // Copy constructor and assignment operator
    I3DOMCalibration(const I3DOMCalibration& calibration);
    const I3DOMCalibration& operator=(const I3DOMCalibration& calibration);

    // ROOT macro
    ClassDef(I3DOMCalibration,1);
};

/**
 * streams an I3DOMCalibration to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o, const I3DOMCalibration& c)
{
    c.ToStream(o); 
    return o;
}

typedef shared_ptr<I3DOMCalibration>  I3DOMCalibPtr;

#endif
