/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id: I3AMANDAPMTPulse.h,v 1.1 2005/02/08 22:45:51 ehrlich Exp $
 *
 * @file I3AMANDAPMTPulse.h
 * @version $Revision: 1.1 $
 * @date $Date: 2005/02/08 22:45:51 $
 * @author ehrlich
 *
 */
#ifndef I3AMANDAPMTPULSE_H_INCLUDED
#define I3AMANDAPMTPULSE_H_INCLUDED

#include "dataclasses/I3PMTPulse.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Units.h"

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
  I3AMANDAPMTPulse() : fNormalization(0.), 
	               fNorm(0.),
		       fWeight(0.),
		       fStddev1(0.),
                       fMu1(0.),
                       fStddev2(0.),
                       fMu2(0.),
		       fTimeZero(0.),
		       fPedestal(0.) {};
  
  /**
   * Gets/Sets the normalization of this pulse
   * (e.g. ROMEO uses integrated charge * terminator [50 ohms]).
   */
  virtual Double_t GetNormalization() {return fNormalization;};
  virtual void SetNormalization(const Double_t norm) {fNormalization = norm;};

  /**
   * Gets/Sets the norm of this pulse 
   * (a paramter of the AMANDA waveform formula).
   */
  virtual Double_t GetNorm() {return fNorm;};
  virtual void SetNorm(const Double_t norm) {fNorm = norm;};

  /**
   * Gets/Sets the weight used to determine to ration between the two terms 
   * of the AMANDA waveform formula.
   */
  virtual Double_t GetWeight() {return fWeight;};
  virtual void SetWeight(const Double_t weight) {fWeight = weight;};

  /**
   * Gets/Sets the Stddev for the first term of the AMANDA waveform formula
   */
  virtual Double_t GetStddev1() {return fStddev1;};
  virtual void SetStddev1(const Double_t stddev1) {fStddev1 = stddev1;};

  /**
   * Gets/Sets Mu for the first term of the AMANDA waveform formula
   */
  virtual Double_t GetMu1() {return fMu1;};
  virtual void SetMu1(const Double_t mu1) {fMu1 = mu1;};

  /**
   * Gets/Sets the Stddev for the second term of the AMANDA waveform formula
   */
  virtual Double_t GetStddev2() {return fStddev2;};
  virtual void SetStddev2(const Double_t stddev2) {fStddev2 = stddev2;};

  /**
   * Gets/Sets Mu for the second term of the AMANDA waveform formula
   */
  virtual Double_t GetMu2() {return fMu2;};
  virtual void SetMu2(const Double_t mu2) {fMu2 = mu2;};


  /** 
   * Gets/Sets the zero time for the pulse. 
   * Times before T0 are invalid for this pulse when the pulse starts.
   */  
  virtual Double_t GetTimeZero() {return fTimeZero;};
  virtual void SetTimeZero(const Double_t time) {fTimeZero = time;};

  /** 
   * Gets/Sets the pedestal. This is a linear offset to the pulse voltage curve.
   */
  virtual Double_t GetPedestal() {return fPedestal;};
  virtual void SetPedestal(const Double_t ped) {fPedestal = ped;};

  /** 
   * Returns the voltage at the given time. Voltage is negative.
   */  
  virtual Double_t GetVoltage(const Double_t time) 
  {
    Double_t t             = (time-fTimeZero) / I3Units::ns;               //need to convert into explicite units
    Double_t normalization = fNormalization / (I3Units::ns * I3Units::V);  //since the formula below requires explicite units

    return(t>0 ? 
       - I3Units::V * normalization * fNorm 
                * ( fWeight/(sqrt(2*pi*fStddev1*fStddev1)) * (1/t)
                    * exp(-(log(t)-fMu1)*(log(t)-fMu1)/(2*fStddev1*fStddev1))
                    - (1-fWeight)/(sqrt(2*pi*fStddev2*fStddev2)) * (1/t)
                    * exp(-(log(t)-fMu2)*(log(t)-fMu2)/(2*fStddev2*fStddev2)) )
       + fPedestal : 0);
  };

  /** 
   * Returns the time at which the pulse reaches its peak voltage.
   * Returns NAN if it can't find the peak.
   */ 
  virtual Double_t GetPeakTime() 
  {
    Double_t t = fTimeZero / I3Units::ns;  //need to convert into explicite units
                                           //since the formula below requires explicite units
    
    //get the peak time for the first term, the peak for the entire formula should be close to it
    Double_t t1 = t + exp(fStddev1*fStddev1 + fMu1);  //this value is in ns
    
    Double_t v_before_t1 = GetVoltage((t1-1)*I3Units::ns);
    Double_t v_at_t1     = GetVoltage((t1)*I3Units::ns);
    Double_t v_after_t1  = GetVoltage((t1+1)*I3Units::ns);

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
  virtual Double_t GetPeakVoltage() 
  {
    if(isnan(GetPeakTime())) return(NAN);

    return(GetVoltage(GetPeakTime()));
  };

private:

  Double_t fNormalization;
  Double_t fNorm;
  Double_t fWeight;
  Double_t fStddev1;
  Double_t fMu1;
  Double_t fStddev2;
  Double_t fMu2;
  Double_t fTimeZero;
  Double_t fPedestal;

  //ROOT macro
  ClassDef(I3AMANDAPMTPulse, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3AMANDAPMTPulse>::ThePolicy I3AMANDAPMTPulsePtr;

#endif
