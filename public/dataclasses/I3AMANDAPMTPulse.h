/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id$
 *
 * @file I3AMANDAPMTPulse.h
 * @version $Revision: 1.5 $
 * @date $Date$
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

class I3AMANDAPMTPulse : public I3PMTPulse 
{
    
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
  virtual double GetVoltage(const double time);

  /** 
   * Returns the time at which the pulse reaches its peak voltage.
   * Returns NAN if it can't find the peak.
   */ 
  virtual double GetPeakTime(); 

  /** 
   * Returns the peak voltage for this pulse.  The pulse is negative,
   * so the peak value is a negative number.
   * Returns NAN if it can't find the peak.
   */ 
  virtual double GetPeakVoltage();

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

  friend class boost::serialization::access;
  
  template <class Archive>
    void serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3PMTPulse", base_object<I3PMTPulse>(*this));
    ar & make_nvp("Normalization",normalization_);
    ar & make_nvp("Norm",norm_);
    ar & make_nvp("Weight",weight_);
    ar & make_nvp("StdDev1",stdDev1_);
    ar & make_nvp("Mu1",mu1_);
    ar & make_nvp("StdDev2",stdDev2_);
    ar & make_nvp("Mu2",mu2_);
    ar & make_nvp("TimeZero",timeZero_);
    ar & make_nvp("Pedestal",pedestal_);
  }

  //ROOT macro
  ClassDef(I3AMANDAPMTPulse, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3AMANDAPMTPulse>  I3AMANDAPMTPulsePtr;

#endif
