/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id: I3AMANDAPMTPulse.h,v 1.5 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3AMANDAPMTPulse.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author ehrlich
 *
 */
#ifndef I3AMANDAPMTPULSE_H_INCLUDED
#define I3AMANDAPMTPULSE_H_INCLUDED

#include "dataclasses/I3PMTPulse.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Units.h"

// oddness on darwin
#ifdef __ppc__
#ifndef isnan 
#define isnan __isnan
#endif
#endif

using namespace I3Constants;
using namespace I3Units;

/**
 * @brief Implementation of PMTPulse for an AMANDA pulse shape
 * 
 * This class records the true (simulated) voltage, as a function of
 * time, produced by a single photoelectron (hit). 
 */

class I3AMANDAPMTPulse : public I3PMTPulse {
    
public:
  /**
   * constructor
   */
  I3AMANDAPMTPulse() : 
	  normalization_(0.), 
	  norm_(0.),
	  weight_(0.),
	  stdDev1_(0.),
	  mu1_(0.),
	  stdDev2_(0.),
	  mu2_(0.),
	  timeZero_(0.),
	  pedestal_(0.) {};
  
  /**
   * Gets/Sets the normalization of this pulse
   * (e.g. ROMEO uses integrated charge * terminator [50 ohms]).
   */
  virtual double GetNormalization() {return normalization_;};
  virtual void SetNormalization(const double norm) {normalization_ = norm;};

  /**
   * Gets/Sets the norm of this pulse 
   * (a paramter of the AMANDA waveform formula).
   */
  virtual double GetNorm() {return norm_;};
  virtual void SetNorm(const double norm) {norm_ = norm;};

  /**
   * Gets/Sets the weight used to determine to ration between the two terms 
   * of the AMANDA waveform formula.
   */
  virtual double GetWeight() {return weight_;};
  virtual void SetWeight(const double weight) {weight_ = weight;};

  /**
   * Gets/Sets the Stddev for the first term of the AMANDA waveform formula
   */
  virtual double GetStddev1() {return stdDev1_;};
  virtual void SetStddev1(const double stddev1) {stdDev1_ = stddev1;};

  /**
   * Gets/Sets Mu for the first term of the AMANDA waveform formula
   */
  virtual double GetMu1() {return mu1_;};
  virtual void SetMu1(const double mu1) {mu1_ = mu1;};

  /**
   * Gets/Sets the Stddev for the second term of the AMANDA waveform formula
   */
  virtual double GetStddev2() {return stdDev2_;};
  virtual void SetStddev2(const double stddev2) {stdDev2_ = stddev2;};

  /**
   * Gets/Sets Mu for the second term of the AMANDA waveform formula
   */
  virtual double GetMu2() {return mu2_;};
  virtual void SetMu2(const double mu2) {mu2_ = mu2;};


  /** 
   * Gets/Sets the zero time for the pulse. 
   * Times before T0 are invalid for this pulse when the pulse starts.
   */  
  virtual double GetTimeZero() {return timeZero_;};
  virtual void SetTimeZero(const double time) {timeZero_ = time;};

  /** 
   * Gets/Sets the pedestal. This is a linear offset to the pulse voltage curve.
   */
  virtual double GetPedestal() {return pedestal_;};
  virtual void SetPedestal(const double ped) {pedestal_ = ped;};

  /** 
   * Returns the voltage at the given time. Voltage is negative.
   */  
  virtual double GetVoltage(const double time) 
  {
    double t             = (time-timeZero_) / I3Units::ns;               //need to convert into explicite units
    double normalization = normalization_ / (I3Units::ns * I3Units::V);  //since the formula below requires explicite units

    return(t>0 ? 
       - I3Units::V * normalization * norm_ 
                * ( weight_/(sqrt(2*pi*stdDev1_*stdDev1_)) * (1/t)
                    * exp(-(log(t)-mu1_)*(log(t)-mu1_)/(2*stdDev1_*stdDev1_))
                    - (1-weight_)/(sqrt(2*pi*stdDev2_*stdDev2_)) * (1/t)
                    * exp(-(log(t)-mu2_)*(log(t)-mu2_)/(2*stdDev2_*stdDev2_)) )
       + pedestal_ : 0);
  };

  /** 
   * Returns the time at which the pulse reaches its peak voltage.
   * Returns NAN if it can't find the peak.
   */ 
  virtual double GetPeakTime() 
  {
    double t = timeZero_ / I3Units::ns;  //need to convert into explicite units
                                           //since the formula below requires explicite units
    
    //get the peak time for the first term, the peak for the entire formula should be close to it
    double t1 = t + exp(stdDev1_*stdDev1_ + mu1_);  //this value is in ns
    
    double v_before_t1 = GetVoltage((t1-1)*I3Units::ns);
    double v_at_t1     = GetVoltage((t1)*I3Units::ns);
    double v_after_t1  = GetVoltage((t1+1)*I3Units::ns);

    if(v_at_t1 <= v_before_t1 && v_at_t1 <= v_after_t1) return(t1*I3Units::ns);

    if(v_at_t1 > v_before_t1)
    {
      for(int i=0; i<10000; i++)
      {
        t1--;
        v_before_t1 = GetVoltage((t1-1)*I3Units::ns);
        v_at_t1     = GetVoltage((t1)*I3Units::ns);
        v_after_t1  = GetVoltage((t1+1)*I3Units::ns);
        if(v_at_t1 <= v_before_t1 && v_at_t1 <= v_after_t1) return(t1*I3Units::ns);
      }
      return(NAN);   //didn't find peak within 10000ns
    }

    if(v_at_t1 < v_before_t1)
    {
      for(int i=0; i<10000; i++)
      {
        t1++;
        v_before_t1 = GetVoltage((t1-1)*I3Units::ns);
        v_at_t1     = GetVoltage((t1)*I3Units::ns);
        v_after_t1  = GetVoltage((t1+1)*I3Units::ns);
        if(v_at_t1 <= v_before_t1 && v_at_t1 <= v_after_t1) return(t1*I3Units::ns);
      }
      return(NAN);   //didn't find peak within 10000ns
    }

    return(NAN);   //didn't find peak
  }

  /** 
   * Returns the peak voltage for this pulse.  The pulse is negative,
   * so the peak value is a negative number.
   * Returns NAN if it can't find the peak.
   */ 
  virtual double GetPeakVoltage() 
  {
    double peak = GetPeakTime();
    if (isnan(peak)) 
      return NAN;
    else
      return GetVoltage(peak);
  };

private:

  double normalization_;
  double norm_;
  double weight_;
  double stdDev1_;
  double mu1_;
  double stdDev2_;
  double mu2_;
  double timeZero_;
  double pedestal_;

  //ROOT macro
  ClassDef(I3AMANDAPMTPulse, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3AMANDAPMTPulse>  I3AMANDAPMTPulsePtr;

#endif
