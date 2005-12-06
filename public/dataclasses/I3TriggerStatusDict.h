/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerStatusDict.h 11091 2005-09-27 09:32:13Z  $
 *
 * @file I3TriggerStatusDict.h
 * @version $Revision: 1.2 $
 * @date $Date: 2005-09-27 05:32:13 -0400 (Tue, 27 Sep 2005) $
 * @author blaufuss
 */
#ifndef I3TRIGGERSTATUSDICT_H
#define I3TRIGGERSTATUSDICT_H

#include "TObject.h"
#include "dataclasses/I3TriggerStatus.h"
#include "dataclasses/TriggerKey.h"
#include "dataclasses/StoragePolicy.h"
#include <sstream>

/**
 * @brief The set of Trigger status objects.  
 *
 * Just a container for I3TriggerStatus objects
 */
class I3TriggerStatusDict 
: public TObject, 
  public STLMapStoragePolicy<TriggerKey,I3TriggerStatusPtr>{
 public:
  /**
   * constructor
   */
  I3TriggerStatusDict(){}

  /**
   * destructor
   */
  virtual ~I3TriggerStatusDict();

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"IMPLEMENT ME: no status for you\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:
  // copy and assignment are private
  I3TriggerStatusDict(const I3TriggerStatusDict& rhs);
  const I3TriggerStatusDict& operator=(const I3TriggerStatusDict& rhs);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o, const I3TriggerStatusDict& status)
{
  status.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3TriggerStatusDict>  I3TriggerStatusDictPtr;

#endif

