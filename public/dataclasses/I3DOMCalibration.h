
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
 * @author blaufuss
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
  * @brief A struct to hold a linear fit 
  * A simple struct to define a linear fit:  intercept + slope*x
  */
struct LinearFit
    {
    double slope;
    double intercept;
    
    private: 
    friend class boost::serialization::access;
    
    template <class Archive>
    void serialize(Archive& ar, unsigned version);
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
    
    private: 
    friend class boost::serialization::access;
    
    template <class Archive>
    void serialize(Archive& ar, unsigned version);
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
 * WARNING:
 * See documentation below and in the DOMCal XML Users' Guide for
 * guidance on the units of the values returned in the Linear and
 * Quadratic fits. These return the raw values from the DOMCal file.
 * Use them without understanding at your peril. 
 *
 * @author Tom McCauley <tpmccauley@lbl.gov>
 * @author Erik Blaufuss <blaufuss at icecube umd edu>
 *
 * 
*/

class I3DOMCalibration
    {

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
     * Get DOMCAL measured PMT transit time relation:  time(ns) = slope/sqrt(V) + intercept
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
    double GetFADCPedestal() const { return fadcPedestal_; }

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
     * Get gain and error on gain for ATWD by channel
     */
    const double GetATWDGain(unsigned int channel);
    /**
     * Set gain and error on gain for ATWD (specified by channel).
     */
    void SetATWDGain(unsigned int channel, double gain);

    /**
     * Get fit parameters from domcal file <atwdfreq> which is 
     * the sampling rate calibration for each ATWD chip 0 or 1 
     */
    const QuadraticFit GetATWDFreqFit(unsigned int chip);
    
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

    const LinearFit GetATWDBinCalibFit(unsigned int id,	
				    unsigned int channel,
				    unsigned int bin);

    /**
     * Set parameters for conversion of count to voltage 
     * for each ATWD, each ATWD channel, and each ATWD bin.
     */
    void SetATWDBinCalibFit(unsigned int id,
			    unsigned int channel,
			    unsigned int bin,
			    LinearFit fitParams);

   
    
    virtual void ToStream(ostream& o) const
	{
	    o<<"[ "
	     <<"Calibration:"
	     <<"\tSuppressing the rest of the output.  I am big. ]\n";
	};
  
    virtual string ToString() const
      {
	  ostringstream out;
	  ToStream(out);
	  return out.str();
      };
    
private:
    static const unsigned int N_ATWD_BINS;
    static const unsigned int N_ATWD_CHANNELS;

    double  temperature_;
    
    /**
     * Gain and pedestal values for FADC
     */
    double fadcGain_;
    double fadcPedestal_;

    /**
     * Gain for ATWD channels.
     * The key corresponds to the channel (0,1,2)
     */
    map<unsigned int, double> ampGains_;
    
    /**
     * Linear fit for each ATWD sampling frequency, one for each chip (0,1)
     * As of DOMCAL 5.14, this will be a quadratic fit.  So, use a Quadratic fit
     * and asuume a linear fit if quadFitC==NULL.
     */
    map<unsigned int, QuadraticFit> atwdFreq_;

    /**
     * Results of the linear fit for the bin calibration
     * i.e. the values needed to convert from counts to voltage
     * for each bin in the ATWD.
     * First key corresponds to channel.
     * Key in internal map corresponds to bin.
     */
    map< unsigned int, map<unsigned int,LinearFit> > atwdBin0_;
    map< unsigned int, map<unsigned int,LinearFit> > atwdBin1_;
    /**
     *  A convienence function to index these two mega-maps
     */
    map< unsigned int, map<unsigned int,LinearFit> >& GetATWDBinParameters(unsigned int id);

    /** 
     *  DOMCAL calculated pmt transit time fit function.
     */

    LinearFit pmtTransitTime_;
    LinearFit hvGainRelation_;

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

#endif
