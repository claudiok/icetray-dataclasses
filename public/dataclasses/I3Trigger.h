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
  enum TrigSubDetector {InIce,IceTop,Amanda,Global};
    
  /**
   * constructor
   */
  I3Trigger() {}
    
  /**
   * destructor
   */
  virtual ~I3Trigger() {}
    
  /**
   * @return the subdetector on which this trigger ran
   */
  virtual TrigSubDetector GetSubDetector() const = 0;
    
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
   * 
   */
  virtual void ToStream(ostream& o) const
  {
    o<<"[ "<<IsA()->GetName()<<" ]\n";
  }

  private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive& ar, unsigned version)  { }
 
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

