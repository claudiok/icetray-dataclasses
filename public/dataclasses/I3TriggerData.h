#ifndef I3TRIGGERDATA_H
#define I3TRIGGERDATA_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerData.h,v 1.2 2004/02/25 20:10:24 pretz Exp $
 *
 * A place holder for the Trigger data within the event
 * Needs to be designed an implemented yet.
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo design and implement this class
 */

#include <TObject.h>
#include "StoragePolicy.h"

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

