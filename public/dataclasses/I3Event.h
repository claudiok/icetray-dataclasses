/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Event.h,v 1.40 2004/08/31 02:56:29 pretz Exp $
 *
 * @file I3Event.h
 * @version $Revision: 1.40 $
 * @date $Date: 2004/08/31 02:56:29 $
 * @author Ralf Ehrlich
 */
#ifndef I3EVENT_H
#define I3EVENT_H

#include <TObject.h>

#include "I3TriggerDict.h"
#include "I3FilterDict.h"
#include "I3OMResponseMap.h"
#include "I3ArrayHitDict.h"
#include "I3RecoResultDict.h"
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

class I3Event : public TObject
{
  I3TriggerDict    fTriggerDict; //||
  I3FilterDict     fFilterDict; //||
  I3OMResponseMap  fOMResponseMap; //||
  I3ArrayHitDict   fTopResponseDict; //||
  I3RecoResultDict fRecoResultDict; //||
  I3Bag            fBag; //||
  
 public:
  /**
   * default constructor
   */
  I3Event();
  
  /**
   * default destructor
   */
  virtual ~I3Event();

  /**
   * @return the TriggerDict as constant
   */
  const I3TriggerDict& GetTriggerDict() const { return fTriggerDict; }

  /**
   * @return the TriggerDict as non-const
   */
  I3TriggerDict& GetTriggerDict() { return fTriggerDict; }

  /**
   * @return the FilterDict as a constant object
   */
  const I3FilterDict& GetFilterDict() const { return fFilterDict;}

  /**
   * @return the FilterDict as a non-constant object
   */
  I3FilterDict& GetFilterDict() { return fFilterDict;}

  /**
   * @return the OMResponseMap of the event as a non-constant object
   */
  const I3OMResponseMap& GetOMResponseMap() const { return fOMResponseMap; }

  /**
   * @return the OMResponseMap as constant object
   */
  I3OMResponseMap& GetOMResponseMap() { return fOMResponseMap; }

   /**
   * @return the Array hit data as constant object
   */
  const I3ArrayHitDict& GeTopResponseDict () const { return fTopResponseDict; }

  /**
   * @ return the Array hit data a non-const object
   */
  I3ArrayHitDict& GetTopResponseDict () { return fTopResponseDict; }

  /**
   * @return the RecoResult Data as a constant object
   */
  const I3RecoResultDict& GetRecoResultDict() const { return fRecoResultDict; }

  /**
   * @return the RecoResultDict as a non-constant object
   */
  I3RecoResultDict& GetRecoResultDict() { return fRecoResultDict; }

  /**
   * @return the Bag for this event as a constant object
   */
  const I3Bag& GetBag() const { return fBag; }

  /**
   * @return the Bag for this event as a non-constant object
   */
  I3Bag& GetBag() { return fBag; }

  /**
   * @param o the stream we're printing the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3Event \n"
       <<fTriggerDict
       <<fFilterDict
       <<fOMResponseMap
       <<fRecoResultDict
       <<fBag
       <<"]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
 private:
  // copy and assignment private
  I3Event(const I3Event& rhs);
  const I3Event& operator=(const I3Event& rhs);

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
typedef PtrPolicy<I3Event>::ThePolicy I3EventPtr;

#endif
