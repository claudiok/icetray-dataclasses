/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerDict.h,v 1.2 2004/08/01 00:41:01 pretz Exp $
 *
 * @file I3TriggerDict.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/08/01 00:41:01 $
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
 * 
 * 
 *
 */
class I3TriggerDict : public TObject,
		      public MapPolicy<string,I3TriggerPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3TriggerDict() {};

  /**
   * destructor
   */
  virtual ~I3TriggerDict() {};

 private:

  // copy and assignment are private
  I3TriggerDict(const I3TriggerDict&);
  const I3TriggerDict& operator=(const I3TriggerDict&);
  // ROOT Macro
  ClassDef(I3TriggerDict, 1);
};

/**
 * streams an I3TriggerDict to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3TriggerDict& v)
{
  o<<"[ I3TriggerDict: \n";
  I3TriggerDict::const_iterator iter;
  for(iter=v.begin();iter!=v.end();iter++)
    {
      o<<iter->first;
      if(iter->second==I3TriggerPtr((I3Trigger*)0))
        o<<"Null I3Trigger";
      else
        o<<*(iter->second);
    }
  o<<"]\n";
  return o;
}


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3TriggerDict>::ThePolicy I3TriggerDictPtr;

#endif

