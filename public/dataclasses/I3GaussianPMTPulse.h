/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id: I3GaussianPMTPulse.h,v 1.1.2.1 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3GaussianPMTPulse.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2005/02/04 21:49:05 $
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
  I3GaussianPMTPulse() : fNormalization(0.), 
			 fSigma(0.),
			 fTimeZero(0.),
			 fPedestal(0.) {};
  
  /** 
   * Returns the voltage at the given time.  Voltage is negative.
   */  
  virtual Float_t GetVoltage(const Float_t time) {
    return (- fNormalization / (sqrt(2 * pi) * fSigma)
	    * exp( - (time - fTimeZero) * (time - fTimeZero) 
		   / (2 * fSigma * fSigma)) + fPedestal);
  };

  /** 
   * Returns the peak voltage for this pulse.  The pulse is negative,
   * so the peak value is a negative number.
   */ 
  virtual Float_t GetPeakVoltage() {
    return ( -fNormalization / (sqrt(2 * pi) * fSigma) + fPedestal);
  };

  /** 
   * Returns the time at which the pulse reaches its peak voltage.
   */ 
  virtual Float_t GetPeakTime() {
    return fTimeZero;
  };

  /** 
   * Set the zero time for the Gaussian describing the pulse.  This is
   * the time at which the pulse reaches its peak voltage.
   */  
  virtual void SetPeakTime(const Float_t time) {
    fTimeZero = time;
  };

  /**
   * Get the time at which the pulse first crosses the given voltage
   * threshold.  Remember that the pulse is negative.
   */
  virtual Float_t GetStartTime(const Float_t threshold) {
    Float_t thres = (threshold >= GetPedestal() ? 
		     GetPedestal() - 1. * microvolt : 
		     threshold);
    return fTimeZero - fSigma * 
      sqrt(-2 * log((fPedestal-thres) / fNormalization * fSigma * sqrt(2*pi)));
  };

  /** 
   * Return the pedestal on which the Gaussian peak lies.  This is a
   * linear offset to the pulse voltage curve.
   */
  virtual Float_t GetPedestal() {
    return fPedestal;
  };

  /**
   * Set the pedestal for this channel.
   */
  virtual void SetPedestal(const Float_t ped) {
    fPedestal = ped;
  };

  /**
   * Return the Gaussian width of the pulse.
   */
  virtual Float_t GetSigma() {
    return fSigma;
  };

  /**
   * Set the Gaussian width of the pulse.
   */
  virtual void SetSigma(const Float_t sigma) {
    fSigma = sigma;
  };

  /**
   * Get the normalization parameter of the Gaussian describing this
   * pulse.  This is *not* the peak voltage.
   */
  virtual Float_t GetNormalization() {
    return fNormalization;
  };

  /** 
   * Set the normalization parameter for this pulse.  This is *not*
   * the peak voltage.
   */
  virtual void SetNormalization(const Float_t norm) {
    fNormalization = norm;
  };

  /**
   * assignment operator is a member-wise assignment
   */
  const I3GaussianPMTPulse& operator=(const I3GaussianPMTPulse &rhs) { 
    if (this == &rhs) return *this; // check for assignment to self
    I3PMTPulse::operator=(rhs);
    fSigma = rhs.fSigma;
    fNormalization = rhs.fNormalization;
    fTimeZero = rhs.fTimeZero;
    fPedestal = rhs.fPedestal;
    return *this;
  }

  /**
   * copy constructor just uses assignment operator
   */
  I3GaussianPMTPulse(const I3GaussianPMTPulse &rhs) { *this = rhs; } 

private:

  Double_t fNormalization;
  Double_t fSigma;
  Double_t fTimeZero;
  Double_t fPedestal;

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3GaussianPMTPulse>::ThePolicy I3GaussianPMTPulsePtr;

#endif
