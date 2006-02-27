/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * @version $Id$
 * @file I3PMTPulse.h
 * @date $Date$
 */

#ifndef I3PMTPULSE_H_INCLUDED
#define I3PMTPULSE_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/I3Vector.h"
#include "dataclasses/I3Map.h"

/**
 * @brief PMT voltage curve produced by a single hit
 * 
 * This class records the true (simulated) voltage, as a function of
 * time, produced by a single photoelectron (hit).  In addition to the
 * voltage curve, it contains the identity of the hit which produed
 * it (and which is recorded in the MCHitSeries). 
 */
class I3PMTPulse {
    
public:

  I3PMTPulse() {hitNum_=0;}

  virtual ~I3PMTPulse();
  
  /**
   * @return the number of the hit (in the I3MCHitSeries) which caused this pulse
   */
  unsigned short GetHitNumber() const { return hitNum_; }
  
  /**
   * @param hitnum set the hit which caused this pulse
   */
  void SetHitNumber(unsigned short hitnum) { hitNum_ = hitnum; }
  
  /**
   * pure virtual function must be implemented in derived class
   */
  virtual double GetVoltage(const double time) 
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

  virtual double GetPeakVoltage()
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

  virtual double GetPeakTime()
    {  
      log_fatal("pure virtual method called"); return 0.0; 
    }

private:
  
  unsigned short hitNum_;

  friend class boost::serialization::access;

  template <class Archive>void serialize(Archive& ar, unsigned version);

  //ROOT macro
  //ClassDef(I3PMTPulse, 1);
};

I3_POINTER_TYPEDEFS(I3PMTPulse);

typedef I3Vector<I3PMTPulse> I3PMTPulseSeries;
typedef I3Map<OMKey, I3PMTPulseSeries> I3PMTPulseSeriesMap;

#endif //I3PMTPULSE_H_INCLUDED

