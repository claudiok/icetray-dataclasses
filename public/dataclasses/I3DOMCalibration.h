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

#include <stdint.h>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>

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
 * @author Tom McCauley <tpmccauley@lbl.gov>
 *
 * @todo Not all of the calib. info. is dealt with here
 *       (and maybe some things are handled but not needed?)
 * @todo Documentation needs to be added 
 * @todo Units (or is that handled by the user, i.e. the one that fills the info?)
 * @todo My big worry is that the interface is too tied to the way the calibration is done.
 *       Will the calibration ever change too much in the future (or change too rapidly) 
 *       that this interface will become obsolete and useless?
 * @todo The FADC calibration is still a work a progress and therefore changes 
 *       here will be necessary.
*/

struct LinearFit
{
    double slope;
    double intercept;
    double regressCoeff;

private: 
    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive& ar, unsigned version);
};

struct ChargeHistogramEntry
{
    double charge;
    double count;

private: 
    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive& ar, unsigned version);
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
    void serialize(Archive& ar, unsigned version);
};

class I3DOMCalibration
{
public:
    I3DOMCalibration();
    virtual ~I3DOMCalibration()
	{};

    uint64_t GetMainboardID(){return mainboardId_;}
	
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
     * Get slope parameter from domcal file <atwdfreq> which is 
     * the sampling rate calibration for each ATWD chip 0 or 1 
     */
    double GetATWDFreqSlope(unsigned int chip)
	{  
	    struct LinearFit fit;
	    fit = atwdFreq_[chip];
	    return  fit.slope;
	};

    /**
     * Get Intercept parameter from domcal file <atwdfreq> which is 
     * the sampling rate calibration for each ATWD chip 0 or 1 
     */
    double GetATWDFreqIntercept(unsigned int chip)
	{  
	    struct LinearFit fit;
	    fit = atwdFreq_[chip];
	    return  fit.intercept;
	};

    /**
     * Get RegressCoeff parameter from domcal file <atwdfreq> which is 
     * the sampling rate calibration for each ATWD chip 0 or 1 
     */
    double GetATWDFreqRegressCoeff(unsigned int chip)
	{  
	    struct LinearFit fit;
	    fit = atwdFreq_[chip];
	    return  fit.regressCoeff;
	};
  
    /**
     * Get the slope for the bin calibration.
     * This is really the conversion factor from
     * counts to volts.
     */
    double GetATWDBinSlope(unsigned int id,	
			   unsigned int channel,
			   unsigned int bin)
	{
	    struct LinearFit fit = GetATWDBinParameters(id)[channel][bin];
	    return fit.slope;
	};
    
    /**
     * Get the intercept for the bin calibration.
     */
    double GetATWDBinIntercept(unsigned int id,
			       unsigned int channel,
			       unsigned int bin)
	{
	    struct LinearFit fit = GetATWDBinParameters(id)[channel][bin];
	    return fit.intercept;
	};
    
    /**
     * Get the regression coeff. for the bin calibration.
     */
    double GetATWDBinRegressCoeff(unsigned int id, 
				  unsigned int channel,
				  unsigned int bin)
	{
	    struct LinearFit fit = GetATWDBinParameters(id)[channel][bin];
	    return fit.regressCoeff;
	};
        
    /**
     * Get the baseline for a given ATWD, channel, and HV
     * This return value is a linear interpolation from 
     * the baseline vs. HV calibration parameters
     */
    /*
    double GetATWDBaseline(unsigned int id, 
			   unsigned int channel, 
			   double HV);
    */

    /**
     * Get gain and error on gain for ATWD by channel
     */
    double GetATWDGain(unsigned int channel);
    double GetATWDGainErr(unsigned int channel);	
  
    /**
     * Return the voltage value corresponding to the count 
     * for a specific ATWD id, channel, and bin.
     * Have to specify the bias voltage 
     * which aren't known at calibration time
     */
    double GetATWDVoltage(unsigned int id,
			  unsigned int channel, 
			  unsigned int bin,
			  double fe_pedestal,
			  int count);
    /*
    double GetATWDVoltage(unsigned int id, 
			  unsigned int channel, 
			  unsigned int bin,
			  double fe_pedestal,
			  double pmtHV,
			  int count);
    */

    /**
     * Return the count value corresponding to a voltage
     * for a specific ATWD id, channel, and bin: 
     * the inverse calibration, if you will
     */
    double GetATWDCount(unsigned int id,
			unsigned int channel,
			unsigned int bin,
			double fe_pedestal,
			double voltage);

    /*
    double GetATWDCount(unsigned int id, 
			unsigned int channel,
			unsigned int bin,
			double fe_pedestal,
			double pmtHV,
			double voltage);
    */

    map<unsigned int,ChargeHistogram>& GetChargeHistograms()
	{
	    return chargeHistograms_;
	}

    const map<unsigned int,ChargeHistogram>& GetChargeHistograms() const
	{
	    return chargeHistograms_;
	}

    void SetMainboardID(uint64_t mbid)
	{
	    mainboardId_ = mbid;
	};
  
    void SetTemperature(double temperature)
	{
	    temperature_ = temperature;
	};
  
    /**
     * Set parameters for conversion of count to voltage 
     * for each ATWD, each ATWD channel, and each ATWD bin.
     */
    void SetATWDBinParameters(unsigned int id,
			      unsigned int channel,
			      unsigned int bin,
			      double slope,
			      double intercept,
			      double regress_coeff);

    /**
     * Set parameters for sampling rate calibration for each 
     * ATWD chip as a function of the trigger_bias DAC setting
     */
    void SetATWDFreqParameters(unsigned int chip,
			       double slope,
			       double intercept,
			       double regress_coeff);
   
    /**
     * Set the baseline parameters (baseline vs. HV) 
     * for each ATWD and each channel
     */
    /*
    void SetATWDBaselineParameters(unsigned int id,
				   unsigned int channel,
				   double HV, double baseline);
    */

    /**
     * Set FADC calibration parameters. Currently the FADC
     * calibration is a work in progress and a moving target
     * so this is only a tentative interface -tpm
     */
    void SetFADCParameters(double pedestal,
			   double gain)
	{
	    fadcPedestal_ = pedestal;
	    fadcGain_     = gain;
	};

    /**
     * Set gain and error on gain for ATWD (specified by channel).
     */
    void SetATWDGain(unsigned int channel, double gain, double gainErr);
    
    virtual void ToStream(ostream& o) const
	{
	    o<<"[ "
	     <<"Calibration:"
	     <<"\tSuppressing the rest of the output ]\n";
	};
  
    virtual string ToString() const
      {
	  ostringstream out;
	  ToStream(out);
	  return out.str();
      };
    
private:
    static const unsigned int N_ATWD_BINS;

    uint64_t mainboardId_;
    double  temperature_;
    
    /**
     * Gain and pedestal values for FADC
     */
    double fadcGain_;
    double fadcPedestal_;

    /**
     * Gain and error on gain for ATWD channels.
     * The key corresponds to the channel.
     */
    map<unsigned int, double> ampGains_;
    map<unsigned int, double> ampGainErrs_;
    
    /**
     * Linear fit for each ATWD sampling frequency
     */
    map<unsigned int, LinearFit> atwdFreq_;

    /**
     * Results of the linear fit for the bin calibration
     * i.e. the values needed to convert from counts to voltage
     * for each bin in the ATWD.
     * First key corresponds to channel.
     * Key in internal map corresponds to bin.
     */
    map< unsigned int, map<unsigned int,LinearFit> > atwdBin0_;
    map< unsigned int, map<unsigned int,LinearFit> > atwdBin1_;
    
    map< unsigned int, map<unsigned int,LinearFit> >& GetATWDBinParameters(unsigned int id);

    /**
     * The remnant baseline (measured at various HV settings)
     * These are subtracted after the waveforms are converted 
     * from counts to volts and the bias level has been subtracted
     * The outer index is the ATWD channel and the interior map
     * is: map<double HV, double baseline>
     *
     * NOTE: This doesn't seem to be a reliable function of HV
     * and furthermore it's not clear that why it should be.
     * It's probably best to dynamically subtract whatever 
     * baseline is left on a waveform-by-waveform basis 
     * dynamically.
     * I'll leave the support for it here anyway (commented out) - tpm
     */
    /*
    map< unsigned int, map<double,double> > atwdBaseline0_;
    map< unsigned int, map<double,double> > atwdBaseline1_;

    map< unsigned int, map<double,double> >& GetATWDBaselineParameters(unsigned int id);
    */

    /**
     *	Charge histogram parameters
     */
    map<unsigned int,ChargeHistogram> chargeHistograms_;

    /**
     * Copy constructor and assignment operator
     */
    I3DOMCalibration(const I3DOMCalibration& calibration);
    const I3DOMCalibration& operator=(const I3DOMCalibration& calibration);

    friend class boost::serialization::access;

    template <class Archive>
      void serialize(Archive& ar, unsigned version);
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
