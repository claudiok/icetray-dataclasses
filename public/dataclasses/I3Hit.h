/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Hit.h,v 1.22.2.5 2005/02/06 12:26:19 troy Exp $
 *
 * @file I3Hit.h
 * @version $Revision: 1.22.2.5 $
 * @date $Date: 2005/02/06 12:26:19 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3HIT_H
#define I3HIT_H

#include "StoragePolicy.h"

#include <iostream>
#include <sstream>

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
  
public:
  /**
   * constructor
   */
   I3Hit() { time_ = 0; hitID_ = 0; }

  /**
   * equality operator
   * @param rhs the right hand side of the equality
   * @return true if the times are equal
   */      
  bool operator==(const I3Hit& rhs) const 
  { 
    return time_ == rhs.time_ && hitID_ == rhs.hitID_; 
  }

  bool operator!=(const I3Hit& rhs) const 
  { 
    return !(*this==rhs); 
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

};

/** 
 * streaming operator
 */ 
inline ostream& operator<<(ostream& o,const I3Hit& hit)
{
  o << "[I3Hit]" << endl;
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Hit>::ThePolicy I3HitPtr;


#endif

