/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id: I3GaussianPMTPulse.h,v 1.2 2005/02/08 22:45:51 ehrlich Exp $
 *
 * @file I3GaussianPMTPulse.h
 * @version $Revision: 1.2 $
 * @date $Date: 2005/02/08 22:45:51 $
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
  virtual Double_t GetVoltage(const Double_t time) {
    return (- fNormalization / (sqrt(2 * pi) * fSigma)
	    * exp( - (time - fTimeZero) * (time - fTimeZero) 
		   / (2 * fSigma * fSigma)) + fPedestal);
  };

  /** 
   * Returns the peak voltage for this pulse.  The pulse is negative,
   * so the peak value is a negative number.
   */ 
  virtual Double_t GetPeakVoltage() {
    return ( -fNormalization / (sqrt(2 * pi) * fSigma) + fPedestal);
  };

  /** 
   * Returns the time at which the pulse reaches its peak voltage.
   */ 
  virtual Double_t GetPeakTime() {
    return fTimeZero;
  };

  /** 
   * Set the zero time for the Gaussian describing the pulse.  This is
   * the time at which the pulse reaches its peak voltage.
   */  
  virtual void SetPeakTime(const Double_t time) {
    fTimeZero = time;
  };

  /**
   * Get the time at which the pulse first crosses the given voltage
   * threshold.  Remember that the pulse is negative.
   */
  virtual Double_t GetStartTime(const Double_t threshold) {
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
  virtual Double_t GetPedestal() {
    return fPedestal;
  };

  /**
   * Set the pedestal for this channel.
   */
  virtual void SetPedestal(const Double_t ped) {
    fPedestal = ped;
  };

  /**
   * Return the Gaussian width of the pulse.
   */
  virtual Double_t GetSigma() {
    return fSigma;
  };

  /**
   * Set the Gaussian width of the pulse.
   */
  virtual void SetSigma(const Double_t sigma) {
    fSigma = sigma;
  };

  /**
   * Get the normalization parameter of the Gaussian describing this
   * pulse.  This is *not* the peak voltage.
   */
  virtual Double_t GetNormalization() {
    return fNormalization;
  };

  /** 
   * Set the normalization parameter for this pulse.  This is *not*
   * the peak voltage.
   */
  virtual void SetNormalization(const Double_t norm) {
    fNormalization = norm;
  };

private:

  Double_t fNormalization;
  Double_t fSigma;
  Double_t fTimeZero;
  Double_t fPedestal;

  //ROOT macro
  ClassDef(I3GaussianPMTPulse, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3GaussianPMTPulse>::ThePolicy I3GaussianPMTPulsePtr;

#endif
