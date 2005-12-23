/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id$
 *
 * @file I3PMTPulse.h
 * @version $Revision: 1.4 $
 * @date $Date$
 * @author deyoung
 *
 */
#ifndef I3PMTPULSE_H
#define I3PMTPULSE_H

#include <TObject.h>
#include "dataclasses/StoragePolicy.h"

/**
 * @brief PMT voltage curve produced by a single hit
 * 
 * This class records the true (simulated) voltage, as a function of
 * time, produced by a single photoelectron (hit).  In addition to the
 * voltage curve, it contains the identity of the hit which produed
 * it (and which is recorded in the MCHitSeries). 
 */
class I3PMTPulse : public TObject {
    
public:
  /**
   * constructor
   */
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
  virtual double GetVoltage(const double time) = 0;

  virtual double GetPeakVoltage() = 0;

  virtual double GetPeakTime() = 0;

private:
  
  unsigned short hitNum_;

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("HitNum", hitNum_);
  }

  //ROOT macro
  //ClassDef(I3PMTPulse, 1);
};

BOOST_IS_ABSTRACT(I3PMTPulse);

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3PMTPulse>  I3PMTPulsePtr;

#endif

