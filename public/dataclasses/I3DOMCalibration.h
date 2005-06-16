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
#include <cmath>
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
 * Calibration information is fetched by the time-ordered bin numbers.
 *
 @author Tom McCauley

 @todo Not all of the calib. info. is dealt with here. Documentation
       needs to be added as well as units (or is that handled by the user?) 
*/

struct LinearFit
{
  double slope;
  double intercept;
  double regressCoeff;

  private: 

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("slope",slope);
    ar & make_nvp("intercept",intercept);
    ar & make_nvp("regressCoeff",regressCoeff);
  }
};

struct ChargeHistogramEntry
{
  double charge;
  double count;

  private: 

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("charge",charge);
    ar & make_nvp("count",count);
  }
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

  private: 

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("exponentialAmplitude",exponentialAmplitude);
    ar & make_nvp("exponentialWidth",exponentialWidth);
    ar & make_nvp("gaussianAmplitude",gaussianAmplitude);
    ar & make_nvp("gaussianAmplitude",gaussianAmplitude);
    ar & make_nvp("gaussianMean",gaussianMean);
    ar & make_nvp("gaussianWidth",gaussianWidth);
    ar & make_nvp("voltage",voltage);
    ar & make_nvp("convergent",convergent);
    ar & make_nvp("peakToValley",peakToValley);
    ar & make_nvp("noiseRate",noiseRate);
    ar & make_nvp("entries",entries);
  }

};

class I3DOMCalibration
{
public:
  unsigned long long GetMainboardID(){return mainboardId_;}
	
  double GetTemperature()
    {
      return temperature_;
    };
  
  double GetFADCGain()
    {
      return fadcGain_;
    };
  
  double GetFADCPedestal()
    {
      return fadcPedestal_;
    };
 
  /**
   * get slope parameter from domcal file <atwdfreq> which is 
   * the sampling rate calibration for each ATWD chip 0 or 1 
   */
  double GetATWDfreqSlope(int chip)
    {  
      struct LinearFit fit;
      fit = atwdFreq_[chip];
      return  fit.slope;
    };

  /**
   * get Intercept parameter from domcal file <atwdfreq> which is 
   * the sampling rate calibration for each ATWD chip 0 or 1 
   */
  double GetATWDfreqIntercept(int chip)
    {  
      struct LinearFit fit;
      fit = atwdFreq_[chip];
      return  fit.intercept;
    };

  /**
   * get RegressCoeff parameter from domcal file <atwdfreq> which is 
   * the sampling rate calibration for each ATWD chip 0 or 1 
   */
  double GetATWDfreqRegressCoeff(int chip)
    {  
      struct LinearFit fit;
      fit = atwdFreq_[chip];
      return  fit.regressCoeff;
    };
  
  /**
   * Get gain and error on gain for ATWD by channel
   */
  double GetATWDGain(int channel);
  
  double GetATWDGainErr(int channel);
  
  /**
   * Returns the ATWD trace in ATWD counts, not converted to
   * voltage, with the pedestal pattern subtracted 
   */

  int GetPedestalSubtractedCount(int id,  
				 int channel, 
				 int bin, 
				 double fe_pedestal,
				 int count);


  /**
   * Converts the pedestal-subtracted ATWD trace from
   * ATWD counts to voltage.
   *
   */

  double GetPedestalSubtractedVoltage(int id, 
				      int channel, 
				      int bin, 
				      double fe_pedestal,
				      int count);

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
  
  void SetMainboardID(unsigned long long mbid){mainboardId_ = mbid;}
  
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


 // Set parameters for sampling rate calibration for each 
 // ATWD chip as a function of the trigger_bias DAC setting

  void SetATWDFreqParameters(int chip,
			     double slope,
			     double intercept,
			     double regress_coeff);
   
  void SetFADCParameters(double pedestal,
			 double gain)
    {
      fadcPedestal_ = pedestal;
      fadcGain_     = gain;
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
    unsigned long long mainboardId_;
    
    // Simple data types
    double  temperature_;
    
    // Gain and pedestal values for FADC
    double fadcGain_;
    double fadcPedestal_;

    //    double fPMTHighVoltage;
    double pedestalVoltage_;
   
    //double fOnePEinPC;
    //double fWidth1PEinPC;

    // Gain and error on gain for ATWD channels.
    // The key corresponds to the channel.
    map<int, double> ampGains_;
    map<int, double> ampGainErrs_;
    
    map<int, LinearFit> atwdFreq_;

    // First key corresponds to channel.
    // Key in internal map corresponds to bin.
    map< int, map<int,LinearFit> > atwd0_;
    map< int, map<int,LinearFit> > atwd1_;

    map< int, map<int,LinearFit> >& GetATWDById(int id);
    map<unsigned int,ChargeHistogram> chargeHistograms_;

    // Copy constructor and assignment operator
    I3DOMCalibration(const I3DOMCalibration& calibration);
    const I3DOMCalibration& operator=(const I3DOMCalibration& calibration);

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("mainboardId",mainboardId_);
    ar & make_nvp("temperature",temperature_);
    ar & make_nvp("fadcGain",fadcGain_);
    ar & make_nvp("fadcPedestal",fadcPedestal_);
    ar & make_nvp("pedestalVoltage",pedestalVoltage_);
    ar & make_nvp("ampGains",ampGains_);
    ar & make_nvp("ampGainErrs",ampGainErrs_);
    ar & make_nvp("atwdFreq",atwdFreq_);
    ar & make_nvp("atwd0",atwd0_);
    ar & make_nvp("atwd1",atwd1_);
    ar & make_nvp("chargeHistograms",chargeHistograms_);
  }

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
