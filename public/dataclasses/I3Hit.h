/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Hit.h,v 1.22.2.1 2005/01/25 23:33:44 troy Exp $
 *
 * @file I3Hit.h
 * @version $Revision: 1.22.2.1 $
 * @date $Date: 2005/01/25 23:33:44 $
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
  I3Hit() { time_ = 0; }

  /**
   * copy constructor.
   */
  I3Hit(const I3Hit& rhs) { *this = rhs; }

  /**
   * assignment operator
   */
  const I3Hit& operator=(const I3Hit& rhs) {
    if (this == &rhs) return *this;
    time_ = rhs.time_;
    return *this;
  }

  /**
   * equality operator
   * @param rhs the right hand side of the equality
   * @return true if the times are equal
   */      
  bool operator==(const I3Hit& rhs) {
    return (time_ == rhs.time_); 
  }

  /**
   * @return the time at which the hit occured
   */
  double GetTime() const { return time_; }

  /**
   * @param time the new time of the hit
   */
  void SetTime(double time) { time_ = time; }

  /**
   * @return the unique ID of this hit
   */
  int GetID() const { return hitID_; }

  /**
   * @param hitid the ID number to assign to this hit.  Should be
   * unique, but no checking is done.
   */
  void SetID(const int hitid) { hitID_ = hitid; }

  /**
   * @todo finish implementing this method
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ "<<IsA()->GetName()<<": Time:"<<time_<<" ]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    using boost::serialization::make_nvp;

    ar & make_nvp("Time", time_);
    ar & make_nvp("HitID", hitID_);
  }
  
  double time_;
  int hitID_;

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

