/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopStatus.h,v 1.2 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3IceTopStatus.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author pretz
 */
#ifndef I3ICETOPSTATUS_H
#define I3ICETOPSTATUS_H

#include "TObject.h"
#include "I3IceTopStationStatus.h"
#include "StoragePolicy.h"

/**
 * @brief a container for I3IcetTopStationStatus objects
 */
class I3IceTopStatus 
: public TObject, 
  public VectorPolicy<I3IceTopStationStatus>::ThePolicy{
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
