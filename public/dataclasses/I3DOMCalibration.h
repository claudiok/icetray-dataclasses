/**
 *
 * Definition of I3DOMCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3DOMCalibration.h,v 1.3 2004/11/11 15:25:08 tmccauley Exp $
 *
 * @file I3DOMCalibration.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/11/11 15:25:08 $
 * @author tmccauley
 */
#ifndef I3DOMCALIBRATION_H
#define I3DOMCALIBRATION_H

#include "dataclasses/StoragePolicy.h"

#include <map>
#include <TObject.h>

using namespace std;

/**
 * @brief Class that stores the calibration information for a DOM
 * 
 * This class stores the information from the Calibration stream.
 *
 @author Tom McCauley

 @todo Not all of the calib. info. is dealt with here. Documentation
       needs to be added as well as units (or is that handled by the user?) 
*/

struct LinearFit
{
    Double_t fSlope;
    Double_t fIntercept;
    Double_t fRegressCoeff;
};

class I3DOMCalibration : public TObject
{
public:
    Double_t GetDate()
	{
	    return fDate;
	};
    
    UInt_t GetDOMId()
	{
	    return fDOMId;
	};
    
    Double_t GetTemperature()
	{
	    return fTemperature;
	};
    
    Double_t GetFADCGain()
	{
	    return fFADCGain;
	};
    
    Double_t GetFADCPedestal()
	{
	    return fFADCPedestal;
	};
    
    // Get gain and error on gain for ATWD by channel
    Double_t GetATWDGain(Int_t channel);
    Double_t GetATWDGainErr(Int_t channel);
 
    // Return the voltage value corresponding to the count 
    // for a specific ATWD id, channel, and bin.
    Double_t GetATWDVoltage(Int_t id, Int_t channel, Int_t bin, Int_t count);
    
    //map<Int_t, Double_t>& GetATWDVoltage(Int_t id, Int_t channel);
    

public:
    I3DOMCalibration();

    virtual ~I3DOMCalibration()
	{};
     
    // Perhaps this should take a time stamp as argument?
    void SetCalibrationConstants();

    void SetDate(Double_t date)
	{
	    fDate = date;
	};
    
    void  SetDOMId(UInt_t id)
	{
	    fDOMId = id;
	};

    void SetTemperature(Double_t temperature)
	{
	    fTemperature = temperature;
	};

    // Set parameters for conversion of count to voltage 
    // for each ATWD, each ATWD channel, and each ATWD bin.
    void SetATWDParameters(Int_t id,
			   Int_t channel,
			   Int_t bin,
			   Double_t slope,
			   Double_t intercept,
			   Double_t regress_coeff);
    
    void SetFADCParameters(Double_t pedestal,
			   Double_t gain)
	{
	    fFADCPedestal = pedestal;
	    fFADCGain     = gain;
	};
      
    // Set gain and error on gain for ATWD (specified by channel).
    void SetATWDGain(Int_t channel, Double_t gain, Double_t gainErr);
  
    void SetHighVoltage(Double_t voltage)
	{
	    fPMTHighVoltage = voltage;
	};
    
    Double_t GetHighVoltage()
	{
	    return fPMTHighVoltage;
	};
    
    void SetPedestalVoltage(Double_t voltage)
	{
	    fPedestalVoltage = voltage;
	};
    
    Double_t GetPedestalVoltage()
	{
	    return fPedestalVoltage;
	};
    
    void SetSamplingRate(Int_t id, Double_t rate);
    
    Double_t GetSamplingRate(Int_t id);
    
private:
    // Simple data types
    Double_t  fDate;  
    UInt_t    fDOMId;
    Double_t  fTemperature;
    
    // Gain and pedestal values for FADC
    Double_t fFADCGain;
    Double_t fFADCPedestal;

    Double_t fPMTHighVoltage;
    Double_t fPedestalVoltage;
    
    Double_t fSamplingRate0;
    Double_t fSamplingRate1;

    // Gain and error on gain for ATWD channels.
    // The key corresponds to the channel.
    map<Int_t, Double_t> fAmpGains;
    map<Int_t, Double_t> fAmpGainErrs;
    
    // First key corresponds to channel.
    // Key in internal map corresponds to bin.
    map< Int_t, map<Int_t,LinearFit> > fATWD0;
    map< Int_t, map<Int_t,LinearFit> > fATWD1;
    map< Int_t, map<Int_t,LinearFit> >& GetATWDById(Int_t id);

    // Copy constructor and assignment operator
    I3DOMCalibration(const I3DOMCalibration& calibration);
    const I3DOMCalibration& operator=(const I3DOMCalibration& calibration);

    // ROOT macro
    ClassDef(I3DOMCalibration,1);
};

typedef PtrPolicy<I3DOMCalibration>::ThePolicy I3DOMCalibPtr;

#endif
