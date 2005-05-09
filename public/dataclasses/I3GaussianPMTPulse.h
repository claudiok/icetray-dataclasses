/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id$
 *
 * @file I3GaussianPMTPulse.h
 * @version $Revision: 1.5 $
 * @date $Date$
 * @author deyoung
 *
 */
#ifndef I3GAUSSIANPMTPULSE_H_INCLUDED
#define I3GAUSSIANPMTPULSE_H_INCLUDED

#include "dataclasses/I3PMTPulse.h"

using namespace I3Constants;
using namespace I3Units;

/**
 * @brief Implementation of PMTPulse for Gaussian pulse shape
 * 
 * This class records the true (simulated) voltage, as a function of
 * time, produced by a single photoelectron (hit), using a Gaussian
 * model. 
 */
class I3GaussianPMTPulse : public I3PMTPulse {
    
public:
  /**
   * constructor
   */
  I3GaussianPMTPulse() : normalization_(0.), 
			 sigma_(0.),
			 timeZero_(0.),
			 pedestal_(0.) {};
  
  /** 
   * Returns the voltage at the given time.  Voltage is negative.
   */  
  virtual double GetVoltage(const double time) {
    return (- normalization_ / (sqrt(2 * pi) * sigma_)
	    * exp( - (time - timeZero_) * (time - timeZero_) 
		   / (2 * sigma_ * sigma_)) + pedestal_);
  };

  /** 
   * Returns the peak voltage for this pulse.  The pulse is negative,
   * so the peak value is a negative number.
   */ 
  virtual double GetPeakVoltage() {
    return ( -normalization_ / (sqrt(2 * pi) * sigma_) + pedestal_);
  };

  /** 
   * Returns the time at which the pulse reaches its peak voltage.
   */ 
  virtual double GetPeakTime() {
    return timeZero_;
  };

  /** 
   * Set the zero time for the Gaussian describing the pulse.  This is
   * the time at which the pulse reaches its peak voltage.
   */  
  virtual void SetPeakTime(const double time) {
    timeZero_ = time;
  };

  /**
   * Get the time at which the pulse first crosses the given voltage
   * threshold.  Remember that the pulse is negative.
   */
  virtual double GetStartTime(const double threshold) {
    float thres = (threshold >= GetPedestal() ? 
		     GetPedestal() - 1. * microvolt : 
		     threshold);
    return timeZero_ - sigma_ * 
      sqrt(-2 * log((pedestal_-thres) / normalization_ * sigma_ * sqrt(2*pi)));
  };

  /** 
   * Return the pedestal on which the Gaussian peak lies.  This is a
   * linear offset to the pulse voltage curve.
   */
  virtual double GetPedestal() {
    return pedestal_;
  };

  /**
   * Set the pedestal for this channel.
   */
  virtual void SetPedestal(const double ped) {
    pedestal_ = ped;
  };

  /**
   * Return the Gaussian width of the pulse.
   */
  virtual double GetSigma() {
    return sigma_;
  };

  /**
   * Set the Gaussian width of the pulse.
   */
  virtual void SetSigma(const double sigma) {
    sigma_ = sigma;
  };

  /**
   * Get the normalization parameter of the Gaussian describing this
   * pulse.  This is *not* the peak voltage.
   */
  virtual double GetNormalization() {
    return normalization_;
  };

  /** 
   * Set the normalization parameter for this pulse.  This is *not*
   * the peak voltage.
   */
  virtual void SetNormalization(const double norm) {
    normalization_ = norm;
  };

private:

  double normalization_;
  double sigma_;
  double timeZero_;
  double pedestal_;

  //ROOT macro
  ClassDef(I3GaussianPMTPulse, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3GaussianPMTPulse>  I3GaussianPMTPulsePtr;

#endif
