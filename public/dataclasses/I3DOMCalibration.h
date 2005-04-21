/**
 *
 * Definition of I3DOMCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id$
 *
 * @file I3DOMCalibration.h
 * @version $Revision: 1.14 $
 * @date $Date$
 * @author tmccauley
 */
#ifndef I3DOMCALIBRATION_H
#define I3DOMCALIBRATION_H

#include "dataclasses/StoragePolicy.h"

#include <map>
#include <vector>
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

struct ChargeHistogramEntry
{
  double charge;
  double count;
};

struct ChargeHistogram
{
  double exponentialAmplitude;
  double exponentialWidth;
  double gaussianAmplitude;
  double gaussianMean;
  double gaussianWidth;
  double voltage;
  double convergent;
  double peakToValley;
  double noiseRate;
  vector<ChargeHistogramEntry> entries;
};

class I3DOMCalibration
{
public:
  long long GetMainboardID(){return mainboardId_;}
	
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
  
  /**
   * Get gain and error on gain for ATWD by channel
   */
  double GetATWDGain(int channel);

  double GetATWDGainErr(int channel);
  
  /**
   * Return the voltage value corresponding to the count 
   * for a specific ATWD id, channel, and bin.  
   * have to specify the front end pedestal which isn't known 
   * at calibration time
   */
  double GetATWDVoltage(int id, 
			int channel, 
			int bin,
			double fe_pedestal, 
			int count);
  
  I3DOMCalibration();
  
  virtual ~I3DOMCalibration()
    {};
  
  void SetMainboardID(long long mbid){mainboardId_ = mbid;}
  
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

  map<unsigned int,ChargeHistogram>& GetChargeHistograms()
    {
      return chargeHistograms_;
    }

  const map<unsigned int,ChargeHistogram>& GetChargeHistograms() const
    {
      return chargeHistograms_;
    }
  

  /**
   * Set gain and error on gain for ATWD (specified by channel).
   */
  void SetATWDGain(int channel, double gain, double gainErr);
  

  virtual void ToStream(ostream& o) const
    {
      o<<"[ "
       <<"Calibration:"
	//       <<"\tDate: "<<fDate<<endl
	//       <<"\tDOM ID: "<<fDOMId<<endl
	//       <<"\tSPE Mean: "<<fSPEMean<<endl
	//       <<"\tPeak-to-Valley: "<<fPeakToValley<<endl
       <<"\tSuppressing the rest of the output ]\n";
    };
  
    virtual string ToString() const
      {
	ostringstream out;
	ToStream(out);
	return out.str();
      };
    
 private:
    long long mainboardId_;
    
    // Simple data types
    double  fTemperature;
    
    // Gain and pedestal values for FADC
    double fFADCGain;
    double fFADCPedestal;

    //    double fPMTHighVoltage;
    double fPedestalVoltage;
   
    //double fOnePEinPC;
    //double fWidth1PEinPC;

    //    double fSamplingRate0;
    //    double fSamplingRate1;

    // Gain and error on gain for ATWD channels.
    // The key corresponds to the channel.
    map<int, double> fAmpGains;
    map<int, double> fAmpGainErrs;
    
    // First key corresponds to channel.
    // Key in internal map corresponds to bin.
    map< int, map<int,LinearFit> > fATWD0;
    map< int, map<int,LinearFit> > fATWD1;
    map< int, map<int,LinearFit> >& GetATWDById(int id);

    map<unsigned int,ChargeHistogram> chargeHistograms_;

    // Copy constructor and assignment operator
    I3DOMCalibration(const I3DOMCalibration& calibration);
    const I3DOMCalibration& operator=(const I3DOMCalibration& calibration);

};

/**
 * streams an I3DOMCalibration to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o, const I3DOMCalibration& c)
{
    c.ToStream(o); 
    return o;
}

typedef shared_ptr<I3DOMCalibration>  I3DOMCalibrationPtr;

typedef shared_ptr<I3DOMCalibration>  I3DOMCalibPtr;

#endif
