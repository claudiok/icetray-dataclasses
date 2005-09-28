/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Event.h
 * @version $Revision: 1.50 $
 * @date $Date$
 * @author Ralf Ehrlich
 */
#ifndef I3EVENT_H
#define I3EVENT_H

#include <TObject.h>

#include "I3OMResponseMap.h"
#include "I3OMSelectionDict.h"
#include "I3RecoResultDict.h"
#include "I3TriggerDict.h"
#include "I3Bag.h"
#include <sstream>

/**
 * @brief Top-level object for the event-specifc information (Physics
 * stream)
 *
 * This class stores all the information that is specific to the
 * single event record: OM and IceTop tank responses, reconstruction
 * results, trigger and filter records, etc.
 * It does not contain more 
 * static information, like geometry, calibration, or monitoring
 * data.  It also contains an I3Bag of user-defined information.
 */

// class boost::serialization::access;

class I3Event : public TObject
{
  I3OMResponseMap   oMResponseMap_; //||
  I3OMResponseMap   topOMResponseMap_; //||
  I3OMSelectionDict oMSelectionDict_; //||
  I3RecoResultDict  recoResultDict_; //||
  I3TriggerDict     triggerDict_; //||
  I3Bag             bag_; //||
  
  public:
  /**
   * default constructor
   */
  I3Event() { };
  
  /**
   * default destructor
   */
  virtual ~I3Event() { };

  /**
   * @return the OMResponseMap of the event as a constant object
   */
  const I3OMResponseMap& GetOMResponseMap() const { return oMResponseMap_; }

  /**
   * @return the OMResponseMap as non-constant object
   */
  I3OMResponseMap& GetTopOMResponseMap() { return topOMResponseMap_; }

  /**
   * @return the TopOMResponseMap of the event as a constant object
   */
  const I3OMResponseMap& GetTopOMResponseMap() const { return topOMResponseMap_; }

  /**
   * @return the TopOMResponseMap as non-constant object
   */
  I3OMResponseMap& GetOMResponseMap() { return oMResponseMap_; }

  /**
   * @return the OMSelectionDict of the event as a constant object
   */
  const I3OMSelectionDict& GetOMSelectionDict() const { return oMSelectionDict_; }

  /**
   * @return the OMSelectionDict as a non-constant object
   */
  I3OMSelectionDict& GetOMSelectionDict() { return oMSelectionDict_; }

  /**
   * @return the RecoResult Data as a constant object
   */
  const I3RecoResultDict& GetRecoResultDict() const { return recoResultDict_; }

  /**
   * @return the RecoResultDict as a non-constant object
   */
  I3RecoResultDict& GetRecoResultDict() { return recoResultDict_; }

  /**
   * @return the TriggerDict Data as a constant object
   */
  const I3TriggerDict& GetTriggerDict() const { return triggerDict_; }

  /**
   * @return the TriggerDict as a non-constant object
   */
  I3TriggerDict& GetTriggerDict() { return triggerDict_; }

  /**
   * @return the Bag for this event as a constant object
   */
  const I3Bag& GetBag() const { return bag_; }

  /**
   * @return the Bag for this event as a non-constant object
   */
  I3Bag& GetBag() { return bag_; }

  /**
   * @param o the stream we're printing the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3Event \n"
       <<oMResponseMap_
       <<topOMResponseMap_
       <<oMSelectionDict_
       <<recoResultDict_
       <<triggerDict_
       <<bag_
       <<"]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

  // Allowing default copy and assignment operators

  private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

  //ROOT macro
  ClassDef(I3Event, 1);
};


/** 
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3Event& evt)
{
  evt.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3Event>  I3EventPtr;

#endif
