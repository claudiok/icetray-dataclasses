/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Event.h,v 1.32 2004/07/13 12:30:55 pretz Exp $
 *
 * @file I3Event.h
 * @version $Revision: 1.32 $
 * @date $Date: 2004/07/13 12:30:55 $
 * @author Ralf Ehrlich
 */
#ifndef I3EVENT_H
#define I3EVENT_H

#include <TObject.h>

#include "I3TriggerData.h"
#include "I3FilterData.h"
#include "I3MCParticleDict.h"
#include "I3OMResponseMap.h"
#include "I3RecoResultDict.h"
#include "I3Bag.h"
/**
 * @brief This class provides access to the all data containers which are 
 * related to each event. 
 */

class I3Event : public TObject
{
  I3TriggerData    fTriggerData; //||
  I3FilterData     fFilterData; //||
  I3OMResponseMap fOMResponseMap; //||
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
   * @return the TriggerData as constant
   */
  const I3TriggerData& GetTriggerData() const { return fTriggerData; }

  /**
   * @return the TriggerData as non-const
   */
  I3TriggerData& GetTriggerData() { return fTriggerData; }

  /**
   * @return the FilterData as a constant object
   */
  const I3FilterData& GetFilterData() const { return fFilterData;}

  /**
   * @return the FilterData as a non-constant object
   */
  I3FilterData& GetFilterData() { return fFilterData;}

  /**
   * @return the OMResponseMap of the event as a non-constant object
   */
  const I3OMResponseMap& GetOMResponseMap() const { return fOMResponseMap; }

  /**
   * @return the OMResponseMap as constant object
   */
  I3OMResponseMap& GetOMResponseMap() { return fOMResponseMap; }

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
       <<fTriggerData
       <<fFilterData
       <<fOMResponseMap
       <<fRecoResultDict
       <<fBag
       <<"]\n";
    }

 private:
  // copy and assignment private
  I3Event(const I3Event& rhs);
  const I3Event& operator=(const I3Event& rhs);

  //ROOT macro
  ClassDef(I3Event, 1);
};

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
