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
  enum TrigSubDetector {Unknown=0, InIce=1, IceTop=2, Amanda=3, Global=4};
    
  I3Trigger() {}

  virtual ~I3Trigger() {}
    
  private:
  vector<double>  TriggerTime;       // Time at which the trigger was issued
  vector<double>  TriggerLength;     // Duration of triggered readout window
  int             TriggerChannel;    // Trigger Channel
  bool            Fired;             // true id trigger fired
  TrigSubDetector TriggerSubDetector;// subdetector on which this trigger ran

  public:

  const vector<double> GetTriggerTime() const {return TriggerTime;}
  vector<double> GetTriggerTime() {return TriggerTime;}

  const vector<double> GetTriggerLength() const {return TriggerLength;}
  vector<double> GetTriggerLength() {return TriggerLength;}

  const int GetTriggerChannel() const {return TriggerChannel;}
  int GetTriggerChannel() {return TriggerChannel;}

  void SetTriggerChannel(int channel) {TriggerChannel = channel;}

  const bool GetTriggerFired() const {return Fired;}
  bool GetTriggerFired() {return Fired;}

  void SetTriggerFired(bool fired) {Fired = fired;}

  const TrigSubDetector GetSubDetector() const {return TriggerSubDetector;}
  TrigSubDetector GetSubDetector() {return TriggerSubDetector;}
  
  void SetSubDetector(TrigSubDetector subdetector) {TriggerSubDetector = subdetector;}

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
    o<<"[ "<<IsA()->GetName()<<" ]\n";
  }

  private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive& ar, unsigned version)  
  { 
    ar & make_nvp("TriggerTime",TriggerTime);
    ar & make_nvp("TriggerLength",TriggerLength);
    ar & make_nvp("TriggerChannel",TriggerChannel);
    ar & make_nvp("Fired",Fired);
    ar & make_nvp("TriggerSubDetector",TriggerSubDetector);
  }
 
  ClassDef(I3Trigger,1);
};

BOOST_IS_ABSTRACT(I3Trigger);

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

