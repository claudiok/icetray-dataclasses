#ifndef I3ICETOPSTATUS_H
#define I3ICETOPSTATUS_H

#include "TObject.h"
#include "I3IceTopStationStatus.h"
#include "StoragePolicy.h"

/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopStatus.h,v 1.1 2004/03/02 20:58:51 pretz Exp $
 *
 *
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/02 20:58:51 $
 * @author pretz
 *
 * @todo 
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
