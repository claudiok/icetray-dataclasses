/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerData.h,v 1.3.2.1 2004/07/28 18:56:13 deyoung Exp $
 *
 * @file I3TriggerData.h
 * @version $Revision: 1.3.2.1 $
 * @date $Date: 2004/07/28 18:56:13 $
 * @author ehrlich
 * @author troy
 * @author pretz
 * @author deyoung
 *
 */
#ifndef I3TRIGGERDATA_H
#define I3TRIGGERDATA_H

#include <TObject.h>
#include "StoragePolicy.h"
#include "I3Trigger.h"

/**
 * @brief A place holder for the Trigger data within the event
 * Needs to be designed an implemented yet.
 * 
 * @todo design and implement this class
 */
class I3TriggerData : public TObject,
		      public MapPointainerPolicy<I3TriggerPtr>::ThePolicy
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

 private:
  // ROOT Macro
  ClassDef(I3TriggerData, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3TriggerData>::ThePolicy I3TriggerDataPtr;

#endif

