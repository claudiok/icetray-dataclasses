/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Hit.h,v 1.19 2004/07/19 16:46:01 pretz Exp $
 *
 * @file I3Hit.h
 * @version $Revision: 1.19 $
 * @date $Date: 2004/07/19 16:46:01 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3HIT_H
#define I3HIT_H

#include <TObject.h>
#include "StoragePolicy.h"
#include <iostream>
#include "TClass.h"

using namespace std;

/**
 * @brief Base class for hit (photoelectron time) records
 *
 * This class records a single photoelectron (PE) produced at the
 * photocathode of an optical module.  I3MCHit and I3RecoHit, and
 * further subclasses, add additional information.  Hardware or
 * DAQ-level records are stored as I3DataReadouts or
 * I3MCPMTResponses.
 */
class I3Hit : public TObject
{
  Double_t fTime;

  public:
  /**
   * constructor
   */
  I3Hit() { fTime = 0; }

  /**
   * copy constructor.
   */
  I3Hit(const I3Hit& rhs) { *this = rhs; }

  /**
   * assignment operator
   */
  const I3Hit& operator=(const I3Hit& rhs) {
    if (this == &rhs) return *this;
    fTime = rhs.fTime;
    return *this;
  }
      
  bool operator==(const I3Hit& rhs) {
    return (fTime == rhs.fTime); 
  }

  /**
   * @returns the time of the hit
   */
  Double_t GetTime() const { return fTime; }

  /**
   * @param time_ the new time of the hit
   */
  void SetTime(Double_t time) { fTime = time; }

  /**
   * @todo finish implementing this method
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ "<<IsA()->GetName()<<": Time:"<<fTime<<" ]\n";
    }

 private:
  // ROOT Macro
  ClassDef(I3Hit, 1);
};

/** 
 * streaming operator
 */ 
inline ostream& operator<<(ostream& o,const I3Hit& hit)
{
  hit.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Hit>::ThePolicy I3HitPtr;


#endif

