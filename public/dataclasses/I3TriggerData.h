/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerData.h,v 1.4 2004/07/12 12:23:11 pretz Exp $
 *
 * @file I3TriggerData.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/07/12 12:23:11 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *

 */
#ifndef I3TRIGGERDATA_H
#define I3TRIGGERDATA_H

#include <TObject.h>
#include "StoragePolicy.h"
#include <iostream>

using namespace std;

/**
 * @brief A place holder for the Trigger data within the event
 * Needs to be designed an implemented yet.
 * 
 * @todo design and implement this class
 */
class I3TriggerData : public TObject
{
 public:
  /**
   * constructor
   */
  I3TriggerData(){};

  /**
   * destructor
   */
  virtual ~I3TriggerData(){};

  /**
   * @todo implement this method more
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3TriggerData ]\n";
    }

 private:
  // ROOT Macro
  ClassDef(I3TriggerData, 1);
};

inline ostream& operator<<(ostream& o,const I3TriggerData& trigger)
{
  trigger.ToStream(o);
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3TriggerData>::ThePolicy I3TriggerDataPtr;

#endif

