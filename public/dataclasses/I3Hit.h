/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Hit.h,v 1.22 2004/12/01 02:27:07 ehrlich Exp $
 *
 * @file I3Hit.h
 * @version $Revision: 1.22 $
 * @date $Date: 2004/12/01 02:27:07 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3HIT_H
#define I3HIT_H

#include <TObject.h>
#include "StoragePolicy.h"
#include <iostream>
#include <sstream>
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
class I3Hit : public TObject {
  
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

  /**
   * equality operator
   * @param rhs the right hand side of the equality
   * @return true if the times are equal
   */      
  bool operator==(const I3Hit& rhs) {
    return (fTime == rhs.fTime); 
  }

  /**
   * @return the time at which the hit occured
   */
  Double_t GetTime() const { return fTime; }

  /**
   * @param time the new time of the hit
   */
  void SetTime(Double_t time) { fTime = time; }

  /**
   * @return the unique ID of this hit
   */
  Int_t GetID() const { return fHitID; }

  /**
   * @param hitid the ID number to assign to this hit.  Should be
   * unique, but no checking is done.
   */
  void SetID(const Int_t hitid) { fHitID = hitid; }

  /**
   * @todo finish implementing this method
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ "<<IsA()->GetName()<<": Time:"<<fTime<<" ]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

private:

  Double_t fTime;
  Int_t fHitID;

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

