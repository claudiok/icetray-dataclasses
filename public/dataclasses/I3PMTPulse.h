/**
 * copyright  (C) 2004
 * the IceCube Collaboration
 * $Id: I3PMTPulse.h,v 1.2 2005/02/08 22:45:51 ehrlich Exp $
 *
 * @file I3PMTPulse.h
 * @version $Revision: 1.2 $
 * @date $Date: 2005/02/08 22:45:51 $
 * @author deyoung
 *
 */
#ifndef I3PMTPULSE_H
#define I3PMTPULSE_H

#include <TObject.h>
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
  virtual Double_t GetVoltage(const Double_t time) = 0;

  virtual Double_t GetPeakVoltage() = 0;

  virtual Double_t GetPeakTime() = 0;

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

