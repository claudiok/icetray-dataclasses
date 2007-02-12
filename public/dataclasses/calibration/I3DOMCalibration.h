/**
 *
 * Definition of I3DOMCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id$
 * @file I3DOMCalibration.h
 * @date $Date$
 */

#ifndef I3DOMCALIBRATION_H_INCLUDED
#define I3DOMCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"

#include <map>
#include <vector>
#include <stdint.h>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

/**
 * @brief A struct to hold a linear fit 
 * A simple struct to define a linear fit:  intercept + slope*x
 */
struct LinearFit
{
  double slope;
  double intercept;
    
  template <class Archive>
  void serialize(Archive& ar, unsigned version);
  LinearFit()
  {
    slope = NAN;
    intercept = NAN;
  }

};

/**
 *  @brief A struct to hold the parameters of a Quadratic fit
 *  A simple struct to define a Quadratic fit:  A + B*x + C*x*x
 */
struct QuadraticFit
{
  double quadFitA;
  double quadFitB;
  double quadFitC;
    
  template <class Archive>
  void serialize(Archive& ar, unsigned version);
  QuadraticFit()
  {
    quadFitA = NAN;
    quadFitB = NAN;
    quadFitC = NAN;
  }

};



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
 * Nothing here really has units.  Most are fits/offsets that
 * convert values for later storage (at that SHOULD use I3Units)
 *
 * @author Tom McCauley <tpmccauley@lbl.gov>
 * @author Erik Blaufuss <blaufuss at icecube umd edu>
 *
 * 
 */

class I3DOMCalibration {
  
 public:
  I3DOMCalibration();
  virtual ~I3DOMCalibration();
  
  /**
   * Get MB Temperature at time of calibration
   */
  double GetTemperature() const { return temperature_; }
  
  /**
   * Set MB Temperature at time of calibration
   */
  void SetTemperature(double temperature) { temperature_ = temperature; }

  /**
   * Get DOMCAL measured PMT transit time
   */
  LinearFit GetTransitTime() const { return pmtTransitTime_; }

  /**
   * Set DOMCAL measured PMT transit time
   */
  void SetTransitTime(LinearFit pmtTransitTime) { pmtTransitTime_ = pmtTransitTime; }
    
  /**
   * Get DOMCAL measured PMT gain/HV relation:  log(10)Gain = slope*log(10)V + intercept
   */
  LinearFit GetHVGainFit() const { return hvGainRelation_; }

  /**
   * Set DOMCAL measured PMT gain/HV relation
   */
  void SetHVGainFit(LinearFit hvGainRelation) { hvGainRelation_ = hvGainRelation; }
    

  /**
   * Get FADC Gain- relation between measured counts and mV.
   */
  double GetFADCGain() const { return fadcGain_; }

  /**
   * Get FADC Pedestal- baseline point from which waveforms start.
   */
  LinearFit GetFADCBaselineFit() const { return fadcBaselineFit_ ; }

  /**
   *  Get the FADC intrinsic time offset (in units of time)
   */
  double GetFADCDeltaT() const { return fadcDeltaT_; }
  
  /**
   *  Get the Front End impedance (units are resistance)
   */
  double GetFrontEndImpedance() const { return frontEndImpedance_; }
    
  /**
   * Get parameters for droop correction on the baseline
   */
  vector<double> GetTauParameters() const { return tauparameters_; }
  
  /**
   * Set parameters for droop correction on the baseline
   */
  void SetTauParameters(vector<double> tauparameters) { tauparameters_ = tauparameters; }



  /**
   * Set FADC calibration parameters. Currently the FADC
   * calibration is a work in progress and a moving target
   * so this is only a tentative interface -tpm
   */
  void SetFADCGain(double gain)
  {
    fadcGain_     = gain;
  };

  void SetFADCBaselineFit(LinearFit basefit)
    {
      fadcBaselineFit_ = basefit;
    }
    
  void SetFADCDeltaT(double deltaT)
    {
      fadcDeltaT_ = deltaT;
    }

  void SetFrontEndImpedance(double feImped)
    {
      frontEndImpedance_ = feImped;
    }
    
  /**
   * Get gain and error on gain for ATWD by channel
   */
  double GetATWDGain(unsigned int channel) const;
  /**
   * Set gain and error on gain for ATWD (specified by channel).
   */
  void SetATWDGain(unsigned int channel, double gain);

  /**
   * Get fit parameters from domcal file <atwdfreq> which is 
   * the sampling rate calibration for each ATWD chip 0 or 1 
   */
  QuadraticFit GetATWDFreqFit (unsigned int chip) const;
  
 
  /**
   * Set parameters for sampling rate calibration for each 
   * ATWD chip as a function of the trigger_bias DAC setting
   */
  void SetATWDFreqFit(unsigned int chip, QuadraticFit fitParams);
			       

  /**
   * Get the fit paramaters for the bin calibration.
   * This is really the conversion factor from
   * counts to volts.
   */

  const LinearFit& GetATWDBinCalibFit(unsigned int id,	
				      unsigned int channel,
				      unsigned int bin) const;

  /**
   * Set parameters for conversion of count to voltage 
   * for each ATWD, each ATWD channel, and each ATWD bin.
   */
  void SetATWDBinCalibFit(unsigned int id,
			  unsigned int channel,
			  unsigned int bin,
			  LinearFit fitParams);

  /**
   *  Get/Set the version of DOMCal.
   */
  string GetDOMCalVersion() const
  {
    return domcalVersion_;
  }	
  
  void SetDOMCalVersion(string version)
  {
    domcalVersion_ = version;
  }
  
  template <class Archive>
    void serialize(Archive& ar, unsigned version);
    
 private:
  static const unsigned int N_ATWD_BINS = 128;
  
  //  Number of ATWD channels is set to 3 (4th ATWD channel doesn't
  //  have DOMCAL now)
  static const unsigned int N_ATWD_CHANNELS = 3;
  
  double  temperature_;
 
  /**
   * Gain and pedestal values for FADC
   */
  double fadcGain_;
  LinearFit fadcBaselineFit_;
  
  /**
   *	FADC inherent time offset (ns)
   */
  double fadcDeltaT_;
  /**
   *	Front-end impedance (Ohms)
   */
  double frontEndImpedance_;
  
  /**
   *   Parameters for droop correction   
   */
  vector<double> tauparameters_;
  
  /**
   * Gain for ATWD channels.
   * The key corresponds to the channel (0,1,2)
   */
  map<unsigned int, double> ampGains_;
    
  /**
   * Linear fit for each ATWD sampling frequency, one for each chip (0,1)
   * As of DOMCAL 5.14, this will be a quadratic fit.  So, use a Quadratic fit
   * and assume a linear fit if quadFitC==NULL.
   */
  map<unsigned int, QuadraticFit> atwdFreq_;

  /**
   * Results of the linear fit for the bin calibration
   * i.e. the values needed to convert from counts to voltage
   * for each bin in the ATWD.
   * First key corresponds to channel.
   * Key in internal map corresponds to bin.
   */
  typedef map<unsigned, map<unsigned, LinearFit> > ATWDBinParam_t;

  ATWDBinParam_t atwdBin0_, atwdBin1_;
  /**
   *  A convienence function to index these two mega-maps
   */

  const ATWDBinParam_t& 
  GetATWDBinParameters(unsigned int id) const;

  ATWDBinParam_t& 
  GetATWDBinParameters(unsigned int id);

  /** 
   *  DOMCAL calculated pmt transit time fit function.
   */

  LinearFit pmtTransitTime_;
  LinearFit hvGainRelation_;

    /**
     * Version of DOMCal used. For now, this only affects the 
     * FE load impedance. It might be useful for FADC calibration
     * as well. Use a string since we may have version numbers like
     * 6.1.2, e.g.
     */
    string domcalVersion_;
    

};

BOOST_CLASS_VERSION(I3DOMCalibration, 2);
I3_POINTER_TYPEDEFS(I3DOMCalibration);

#endif //I3DOMCALIBRATION_H_INCLUDED
