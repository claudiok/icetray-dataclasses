/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3TriggerDict.h
 * @version $Revision: 1.4 $
 * @date $Date$
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
#include <sstream>

/**
 * @brief A place holder for the Trigger data within the event
 *
 */
class I3TriggerDict : public TObject, public STLMapStoragePolicy<string,I3TriggerPtr>
{
  public:
  I3TriggerDict() {};
  virtual ~I3TriggerDict() {};

  virtual void ToStream(ostream& o) const
  {
    o<<"[ I3TriggerDict: \n";
    I3TriggerDict::const_iterator iter;
    for(iter=begin();iter!=end();iter++)
    {
      o<<iter->first;
      if(iter->second==I3TriggerPtr((I3Trigger*)0)) o<<"Null I3Trigger";
      else o<<*(iter->second);
    }
    o<<"]\n";
  }
  
  virtual string ToString() const
  {
    ostringstream out;
    ToStream(out);
    return out.str();
  }

  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3TriggerDict", base_object< STLMapStoragePolicy<string, I3TriggerPtr>  >(*this));
  }

  // ROOT Macro
  ClassDef(I3TriggerDict, 1);
};

/**
 * streams an I3TriggerDict to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3TriggerDict& v)
{
  v.ToStream(o);
  return o;
}


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3TriggerDict> I3TriggerDictPtr;

#endif

