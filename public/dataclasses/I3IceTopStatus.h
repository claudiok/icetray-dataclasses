/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopStatus.h,v 1.4 2004/08/03 16:25:14 blaufuss Exp $
 *
 * @file I3IceTopStatus.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/08/03 16:25:14 $
 * @author pretz
 */
#ifndef I3ICETOPSTATUS_H
#define I3ICETOPSTATUS_H

#include "TObject.h"
#include "I3IceTopStationStatus.h"
#include "StoragePolicy.h"

/**
 * @brief A station key used to access the IceTop stations.
 *
 * It's just an integer.
 */
typedef int StationKey;

/**
 * @brief a container for I3IcetTopStationStatus objects.  Just holding a place
 * for now
 */
class I3IceTopStatus : public TObject, 
		       public MapPolicy<StationKey,I3IceTopStationStatusPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3IceTopStatus(){}

  /**
   * destructor
   */
  virtual ~I3IceTopStatus(){};

 private:
  // copy and assignment are private
  I3IceTopStatus(const I3IceTopStatus& rhs);
  const I3IceTopStatus& operator=(const I3IceTopStatus& rhs);

  // ROOT macro
  ClassDef(I3IceTopStatus,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3IceTopStatus>::ThePolicy I3IceTopStatusPtr;

#endif
