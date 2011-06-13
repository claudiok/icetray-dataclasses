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

#include <string>
#include "dataclasses/Utility.h"

#include <map>
#include <vector>
#include <stdint.h>
#include <sstream>
#include <cmath>
#include <string>

static const unsigned i3domcalibration_version_ = 9;
static const unsigned linearfit_version_ = 0;
static const unsigned quadraticfit_version_ = 0;
static const unsigned tauparam_version_ = 0;

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
BOOST_CLASS_VERSION(LinearFit, linearfit_version_);

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
BOOST_CLASS_VERSION(QuadraticFit, quadraticfit_version_);

/**
 *  @brief A struct to hold the parameters of the toroid time constants parameters
 * for electronic droop correction
 * The two time constants parametrize this correction as a
 * function of temperature (T):
 *   Tau_1(T) = P0 + ( P1/(1+exp(-(T/P2)) ))
 *   Tau_2(T) = P3 + ( P4/(1+exp(-(T/P5)) ))
 * the functions exp(-t/tau1) and exp(-t/tau2) are combined in the TauFrac proportion to reproduce
 * the electronics behaviour through (1-Taufrac)exp(-t/tau1) + TauFrac exp(-t/tau2)
 */

struct TauParam
{
  double P0;
  double P1;
  double P2;
  double P3;
  double P4;
  double P5;
  double TauFrac;
    
  template <class Archive>
  void serialize(Archive& ar, unsigned version);
  TauParam()
  {
    P0 = NAN;
    P1 = NAN;
    P2 = NAN;
    P3 = NAN;
    P4 = NAN;
    P5 = NAN;
    TauFrac = NAN;
  }

};

BOOST_CLASS_VERSION(TauParam, tauparam_version_);



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
 * @author Erik Blaufuss \<blaufuss at icecube umd edu\>
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
   * Get the FADC baseline in data-taking mode, as measured from beacon launches.
   *
   * XXX WARNING DANGER DANGER DANGER: The beacon baseline depends implicitly
   * on the front-end bias voltage. If the bias voltage is ever changed, new
   * baselines will have to be collected.
   */
  double GetFADCBeaconBaseline() const { return fadcBeaconBaseline_; }

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
  TauParam GetTauParameters() const { return tauparameters_; }
  
  /**
   * Set parameters for droop correction on the baseline
   */
  void SetTauParameters(TauParam tauparameters) { tauparameters_ = tauparameters; }



  /**
   * Set FADC calibration parameters. Currently the FADC
   * calibration is a work in progress and a moving target
   * so this is only a tentative interface -tpm
   */
  void SetFADCGain(double gain)
  {
    fadcGain_     = gain;
  };

  void SetFADCBeaconBaseline(double bsl)
  {
    fadcBeaconBaseline_ = bsl;
  }

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
   * Get atwd DeltaT by chip
   */
  double GetATWDDeltaT(unsigned int chip) const;
  /**
   * Set atwd DeltaT by chip
   */
  void SetATWDDeltaT(unsigned int chip, double deltat);

  /**
   * Get fit parameters from domcal file \<atwdfreq\> which is 
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
 std::string GetDOMCalVersion() const
  {
    return domcalVersion_;
  }	
  
  void SetDOMCalVersion(std::string version)
  {
    domcalVersion_ = version;
  }

  /**
   *  Get the basline value for a particular atwd chip(id)[0-1], gain channel[0-2] and bin[0-127]
   */
  
  double GetATWDBaseline(unsigned int id,	
			       unsigned int channel,
			       unsigned int bin) const;
  /**
   *  Set the basline value for a particular atwd chip(id)[0-1], gain channel[0-2] and bin[0-127]
   */
  
  void SetATWDBaseline(unsigned int id,
		       unsigned int channel,
		       unsigned int bin,
		       double baseval);

  /**
   * Get the average ATWD baseline in data-taking mode, as measured from beacon launches.
   *
   * XXX WARNING DANGER DANGER DANGER: The beacon baseline depends implicitly
   * on the front-end bias voltage. If the bias voltage is ever changed, new
   * baselines will have to be collected.
   */
  double GetATWDBeaconBaseline(unsigned int id, unsigned int channel) const;
 
  void SetATWDBeaconBaseline(unsigned int id, unsigned int channel, double bsl);  

  /**
   * Get electronics response width for ATWD 
   */
  double GetATWDResponseWidth() const { return atwdResponseWidth_; }
  
  /**
   * Set electronics response width for ATWD 
   */
  void SetATWDResponseWidth(double atwdResponseWidth)
  {
    atwdResponseWidth_ = atwdResponseWidth;
    toroidType_ = (atwdResponseWidth_ > 0.4) ? NEW_TOROID : OLD_TOROID;
  }

  /**
   * Get electronics response width for FADC 
   */
  double GetFADCResponseWidth() const { return fadcResponseWidth_; }
  
  /**
   * Set electronics response width for FADC 
   */
  void SetFADCResponseWidth(double fadcResponseWidth) { fadcResponseWidth_ = fadcResponseWidth; }


  /**
   *  Get/Set functions for speDiscrimCalib
   */
  void SetSPEDiscCalib(LinearFit speDiscrimCalib) 
  {
    speDiscrimCalib_ = speDiscrimCalib;
  }

  LinearFit GetSPEDiscCalib() const { return speDiscrimCalib_ ; }  

  /**
   *  Get/Set functions for mpeDiscrimCalib
   */
  void SetMPEDiscCalib(LinearFit mpeDiscrimCalib) 
  {
    mpeDiscrimCalib_ = mpeDiscrimCalib;
  }

  LinearFit GetMPEDiscCalib() const { return mpeDiscrimCalib_ ; }  

  /**
   *  Get/Set functions for pmtDiscrimCalib
   */
  void SetPMTDiscCalib(LinearFit pmtDiscrimCalib) 
  {
    pmtDiscrimCalib_ = pmtDiscrimCalib;
  }

  LinearFit GetPMTDiscCalib() const { return pmtDiscrimCalib_ ; }  

  /**
   *  Get/set for relativeDomEff
   */
  double GetRelativeDomEff() const { return relativeDomEff_ ; }
  void SetRelativeDomEff(double relaeff)
  {
    relativeDomEff_ = relaeff;
  }

  /**
   * Get/set for DOM noise rate
   */
  double GetDomNoiseRate() const { return noiseRate_ ; }
  void SetDomNoiseRate(double noiserate)
  {
    noiseRate_ = noiserate;
  }

  double ATWDPulseTemplate(double time, unsigned int channel = 0) const;
  double FADCPulseTemplate(double time) const;
 
  template <class Archive>
    void serialize(Archive& ar, unsigned version);
    
 private:
  static const unsigned int N_ATWD_BINS = 128;
  
  //  Number of ATWD channels is set to 3 (4th ATWD channel doesn't
  //  have DOMCAL now)
  static const unsigned int N_ATWD_CHANNELS = 3;
  
  enum ToroidType {
    OLD_TOROID = 0,
    NEW_TOROID = 1
  };

  double  temperature_;
 
  /**
   * Gain and pedestal values for FADC
   */
  double fadcGain_;
  LinearFit fadcBaselineFit_;

  /**
   * Pedestal in data-taking mode, as measured from beacon launches.
   * XXX WARNING DANGER DANGER DANGER: The beacon baseline depends implicitly
   * on the front-end bias voltage. If the bias voltage is ever changed, new
   * baselines will have to be collected.
   */
  double fadcBeaconBaseline_;
  
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
  TauParam tauparameters_;
  
  /**
   * Gain for ATWD channels.
   * The key corresponds to the channel (0,1,2)
   */
  //map<unsigned int, double> ampGains_;
  double ampGains_[3];

  /**
   * Linear fit for each ATWD sampling frequency, one for each chip (0,1)
   * As of DOMCAL 5.14, this will be a quadratic fit.  So, use a Quadratic fit
   * and assume a linear fit if quadFitC==NULL.
   */
  //map<unsigned int, QuadraticFit> atwdFreq_;
  QuadraticFit atwdFreq_[2];
  
/**
   * Results of the linear fit for the bin calibration
   * i.e. the values needed to convert from counts to voltage
   * for each bin in the ATWD.
   * First key corresponds to channel.
   * Key in internal map corresponds to bin.
   */
  //typedef map<unsigned, map<unsigned, LinearFit> > ATWDBinParam_t;
  //ATWDBinParam_t atwdBin0_, atwdBin1_;
 
  LinearFit atwdBin0_[N_ATWD_CHANNELS][N_ATWD_BINS];
  LinearFit atwdBin1_[N_ATWD_CHANNELS][N_ATWD_BINS];
  
  /** 
   *  DOMCAL calculated pmt transit time fit function.
   */

  LinearFit pmtTransitTime_;
  LinearFit hvGainRelation_;

  /**
   * Version of DOMCal used. For now, this only affects the 
   * FE load impedance. It might be useful for FADC calibration
   * as well. Use a std::string since we may have version numbers like
   * 6.1.2, e.g.
   */
 std::string domcalVersion_;

  /**
   *  Dumb-ol-array to hold the baseline corrections.
   *  [atwd chip id (0-1)] [ gain channel(0-2) ] [ atwd bin (0-127) ]
   */

  double atwdBaselines_[2][N_ATWD_CHANNELS][N_ATWD_BINS];

  /**
   *  Dumb-ol-array to hold the average baseline corrections measured from beacon launches.
   *  [atwd chip id (0-1)] [ gain channel(0-2) ]
   *
   * XXX WARNING DANGER DANGER DANGER: The beacon baseline depends implicitly
   * on the front-end bias voltage. If the bias voltage is ever changed, new
   * baselines will have to be collected.
   */

  double atwdBeaconBaselines_[2][N_ATWD_CHANNELS];

  /**
   *  Stores the toroid type (pre-2006 droopy or post-2006 sligthly-less-droopy) 
   */
  ToroidType toroidType_;
  
  /**
   *  Stores the response witdth of the electronics to a pulse (ATWD). To be used with  
   *  the simulation. It changed with 2006 toroid change.  
   */

  double atwdResponseWidth_;

  /**
   *  Stores the response witdth of the electronics to a pulse (FADC). To be used with  
   *  the simulation. It changed with 2006 toroid change.  
   */

  double fadcResponseWidth_;

  /**
   *  Store the ATWD time offset from domcal calibration.  the ATWD used in transit time
   *  calibratin will be 0.0, while the other could have up to a few ns offset...
   */

  double atwdDeltaT_[2];

  /**
   * The SPE discriminator calibration.  A linear fit between
   *   DAC(9) value and charge level in pC.
   */
  LinearFit speDiscrimCalib_;

  /**
   * The MPE discriminator calibration.  A linear fit between
   *   DAC(8) value and charge level in pC.
   */
  LinearFit mpeDiscrimCalib_;

  /**
   * A refined SPE discriminator calibration generated using actual PMT pulses.  
   *   A linear fit between DAC(8) value and charge level in pC.
   */
  LinearFit pmtDiscrimCalib_;

  /**
   *  Relative DOM efficiency, normalized to 1.0 for the average dom.
   */
  double relativeDomEff_;

  /**
   *  Measure DOM noise rate, in Hz, 
   */
  double noiseRate_;


};

BOOST_CLASS_VERSION(I3DOMCalibration, i3domcalibration_version_);
I3_POINTER_TYPEDEFS(I3DOMCalibration);

#endif //I3DOMCALIBRATION_H_INCLUDED
