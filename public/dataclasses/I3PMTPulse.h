/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id: I3PMTPulse.h,v 1.1.2.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3PMTPulse.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author deyoung
 *
 */
#ifndef I3PMTPULSE_H
#define I3PMTPULSE_H

#include "StoragePolicy.h"

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
  I3PMTPulse() {fHitNum=0;}
  
  /**
   * @return the number of the hit (in the I3MCHitSeries) which caused this pulse
   */
  UShort_t GetHitNumber() const { return fHitNum; }
  
  /**
   * @param hitnum set the hit which caused this pulse
   */
  void SetHitNumber(UShort_t hitnum) { fHitNum = hitnum; }
  
  /**
   * pure virtual function must be implemented in derived class
   */
  virtual Float_t GetVoltage(const Float_t time) = 0;

  virtual Float_t GetPeakVoltage() = 0;

  virtual Float_t GetPeakTime() = 0;

  virtual Float_t GetStartTime(const Float_t threshold) = 0;

  /**
   * assignment operator is a member-wise assignment
   */
  const I3PMTPulse& operator=(const I3PMTPulse &rhs) { 
    if (this == &rhs) return *this; // check for assignment to self
    fHitNum = rhs.fHitNum; 
    return *this;
  }

  /**
   * copy constructor just uses assignment operator
   */
  I3PMTPulse(const I3PMTPulse &rhs) { *this = rhs; } 

private:
  
  UShort_t fHitNum;

  //ROOT macro
  ClassDef(I3PMTPulse, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3PMTPulse>::ThePolicy I3PMTPulsePtr;

#endif

