/**
 *
 * Definition of I3DOMCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3DOMCalibration.h,v 1.13 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3DOMCalibration.h
 * @version $Revision: 1.13 $
 * @date $Date: 2005/04/12 18:55:28 $
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
    double slope_;
    double intercept_;
    double regressCoeff_;
};

class I3DOMCalibration : public TObject
{
public:
    double GetDate()
	{
	    return date_;
	};
    
    unsigned int GetDOMId()
	{
	    return DOMId_;
	};
    
    double GetTemperature()
	{
	    return temperature_;
	};
    
    double GetFADCGain()
	{
	    return FADCGain_;
	};
    
    double GetFADCPedestal()
	{
	    return FADCPedestal_;
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
	    date_ = date;
	};
    
    void  SetDOMId(unsigned int id)
	{
	    DOMId_ = id;
	};

    void SetTemperature(double temperature)
	{
	    temperature_ = temperature;
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
	    FADCPedestal_ = pedestal;
	    FADCGain_     = gain;
	};
      
    // Set gain and error on gain for ATWD (specified by channel).
    void SetATWDGain(int channel, double gain, double gainErr);
  
    void SetHighVoltage(double voltage)
	{
	    PMTHighVoltage_ = voltage;
	};
    
    double GetHighVoltage()
	{
	    return PMTHighVoltage_;
	};
    
    void SetSingleSPEThresholdVoltage(double voltage)
	{
	    singleSPEThresholdVoltage_ = voltage;
	};
    
    double GetSingleSPEThresholdVoltage()
	{
	    return singleSPEThresholdVoltage_;
	};
    
    void SetPedestalVoltage(double voltage)
	{
	    pedestalVoltage_ = voltage;
	};
    
    double GetPedestalVoltage()
	{
	    return pedestalVoltage_;
	};

    void SetPeakToValley(double p2v)
	{
	    peakToValley_ = p2v;
	};
    
    double GetPeakToValley()
	 {
	    return peakToValley_;
	 };

    void SetSPEMean(double mean)
	{
	    SPEMean_ = mean;
	};
    
    /*
    void SetOnePEinPC(double OnePE)
	{
	    onePEinPC_ = OnePE;
	};
    */

    double GetSPEMean()
	{
	    return SPEMean_;
	};
    
    /*
    double GetOnePEinPC()
	{
	    return onePEinPC_;
	};
    */

    void SetSPEWidth(double width)
	{
	    SPEWidth_ = width;
	};
    
    /*
    void SetWidth1PEinPC(double width1pe)
	{
	    width1PEinPC_ = width1pe;
	};
    */

    double GetSPEWidth()
	{
	    return SPEWidth_;
	};
    
    /*
    double GetWidth1PEinPC()
	{
	    return width1PEinPC_;
	};
    */

    void SetSamplingRate(int id, double rate);
    
    double GetSamplingRate(int id);

    virtual void ToStream(ostream& o) const
    {
	o<<"[ "
	 <<"Calibration:"
	 <<"\tDate: "<<date_<<endl
	 <<"\tDOM ID: "<<DOMId_<<endl
	 <<"\tSPE Mean: "<<SPEMean_<<endl
	 <<"\tPeak-to-Valley: "<<peakToValley_<<endl
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
    double  date_;  
    unsigned int    DOMId_;
    double  temperature_;
    
    // Gain and pedestal values for FADC
    double FADCGain_;
    double FADCPedestal_;

    double PMTHighVoltage_;
    double pedestalVoltage_;
    double singleSPEThresholdVoltage_;
   
    // Parameters describing the SPE charge distribution
    double peakToValley_;
    double SPEMean_;
    double SPEWidth_; 

    //double onePEinPC_;
    //double width1PEinPC_;

    double samplingRate0_;
    double samplingRate1_;

    // Gain and error on gain for ATWD channels.
    // The key corresponds to the channel.
    map<int, double> ampGains_;
    map<int, double> ampGainErrs_;
    
    // First key corresponds to channel.
    // Key in internal map corresponds to bin.
    map< int, map<int,LinearFit> > ATWD0_;
    map< int, map<int,LinearFit> > ATWD1_;
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
