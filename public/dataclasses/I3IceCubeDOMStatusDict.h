/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceCubeDOMStatusDict.h 11091 2005-09-27 09:32:13Z  $
 *
 * @file I3IceCubeDOMStatusDict.h
 * @version $Revision: 1.2 $
 * @date $Date: 2005-09-27 05:32:13 -0400 (Tue, 27 Sep 2005) $
 * @author pretz
 * @author blaufuss
 */
#ifndef I3ICECUBEDOMSTATUSDICT_H
#define I3ICECUBEDOMSTATUSDICT_H

#include "TObject.h"
#include "I3DOMStatus.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"
#include <sstream>

/**
 * @brief The status of the DeepIce detector.  
 *
 * Just a container for I3OMStatusIceCube objects
 */
class I3IceCubeDOMStatusDict 
: public TObject, 
  public STLMapStoragePolicy<OMKey,I3DOMStatus>{
 public:
  /**
   * constructor
   */
  I3IceCubeDOMStatusDict(){}

  /**
   * destructor
   */
  virtual ~I3IceCubeDOMStatusDict();

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"IMPLEMENT ME\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:
  // copy and assignment are private
  I3IceCubeDOMStatusDict(const I3IceCubeDOMStatusDict& rhs);
  const I3IceCubeDOMStatusDict& operator=(const I3IceCubeDOMStatusDict& rhs);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o, const I3IceCubeDOMStatusDict& status)
{
  status.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3IceCubeDOMStatusDict>  I3IceCubeDOMStatusDictPtr;

#endif

