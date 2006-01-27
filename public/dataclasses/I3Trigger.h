/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Trigger.h
 * @version $Revision: 1.5 $
 * @date $Date$
 * @author blaufuss
 * @author deyoung
 * @author ehrlich
 */

#ifndef I3TRIGGER_H
#define I3TRIGGER_H

#include <TObject.h>
#include <TClass.h>
#include <string>
#include <iostream>
#include <sstream>

#include "dataclasses/StoragePolicy.h"

using namespace std; 

/**
 * @brief The basic Trigger class.  
 * 
 * This is the base class for trigger records that will live in the I3TriggerDict.
 */
class I3Trigger : public TObject
{
  public:
  /**
   * An enumerated type for the Subdetector type that generated the trigger
   */
  enum TrigSubDetector {Unknown=0, InIce=1, IceTop=2, Amanda=3, Global=4, Calib=5};
    
  I3Trigger() {
    fired_=false; 
    triggerTime_=0.0; 
    triggerLength_=0.0; 
    triggerSubDetector_=Unknown;
  }

  virtual ~I3Trigger();
    
  private:
  double  triggerTime_;       // Time at which the trigger was issued
  double  triggerLength_;     // Duration of triggered readout window
  bool    fired_;             // true if trigger fired (used for simulations)
  TrigSubDetector triggerSubDetector_;// subdetector on which this trigger ran

  public:

  double GetTriggerTime() const {return triggerTime_;}
  void SetTriggerTime(double time) {triggerTime_ = time;}

  double GetTriggerLength() const {return triggerLength_;}
  void SetTriggerLength(double length) {triggerLength_ = length;}

  bool GetTriggerFired() const {return fired_;}
    void SetTriggerFired(bool fired) {fired_ = fired;}

  TrigSubDetector GetSubDetector() const {return triggerSubDetector_;}
  TrigSubDetector GetSubDetector() {return triggerSubDetector_;}
  
  void SetSubDetector(TrigSubDetector subdetector) {triggerSubDetector_ = subdetector;}

  /**
   * @todo finish implementing this method
   */
  virtual const string ToString() const
  {
    ostringstream out;
    ToStream(out);
    return out.str();
  }

  /**
   * @todo finish with all the data
   */
  virtual void ToStream(ostream& o) const
  {
  o<<"[I3Trigger:   TrigTime:"<<triggerTime_<< "\n"
     <<"            TrigLength:"<<triggerLength_<< "\n"
     <<"            SubDectectorID:"<<triggerSubDetector_<< "\n"
     <<"            Fired:"<<fired_<<" ]\n";
  }

  private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
ClassDef(I3Trigger,1);
};

/**
 * streams an I3Trigger to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3Trigger& trig)
{
  trig.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3Trigger> I3TriggerPtr;

#endif


