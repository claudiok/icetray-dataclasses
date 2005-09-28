/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3IceCubeStatus.h
 * @version $Revision: 1.2 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3STATUSICECUBE_H
#define I3STATUSICECUBE_H

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
class I3IceCubeStatus 
: public TObject, 
  public STLMapStoragePolicy<OMKey,I3DOMStatus>{
 public:
  /**
   * constructor
   */
  I3IceCubeStatus(){}

  /**
   * destructor
   */
  virtual ~I3IceCubeStatus(){};

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
  I3IceCubeStatus(const I3IceCubeStatus& rhs);
  const I3IceCubeStatus& operator=(const I3IceCubeStatus& rhs);

  // ROOT macro
  ClassDef(I3IceCubeStatus,1);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o, const I3IceCubeStatus& status)
{
  status.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3IceCubeStatus>  I3IceCubeStatusPtr;

#endif

