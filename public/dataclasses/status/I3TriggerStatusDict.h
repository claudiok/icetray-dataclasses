/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3TriggerStatusDict.h 11091 2005-09-27 09:32:13Z  $
 * @file I3TriggerStatusDict.h
 * @date $Date: 2005-09-27 05:32:13 -0400 (Tue, 27 Sep 2005) $
 */

#ifndef I3TRIGGERSTATUSDICT_H_INCLUDED
#define I3TRIGGERSTATUSDICT_H_INCLUDED

#include "dataclasses/I3Map.h"
#include "dataclasses/status/I3TriggerStatus.h"
#include "dataclasses/TriggerKey.h"
#include "dataclasses/Utility.h"
#include <sstream>

/**
 * @brief The set of Trigger status objects.  
 *
 * Just a container for I3TriggerStatus objects
 */
class I3TriggerStatusDict : public I3Map<TriggerKey,I3TriggerStatusPtr>
{
 public:

  I3TriggerStatusDict(){}

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


I3_POINTER_TYPEDEFS(I3TriggerStatusDict);

#endif //I3TRIGGERSTATUSDICT_H_INCLUDED

