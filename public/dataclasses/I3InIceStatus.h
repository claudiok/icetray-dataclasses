/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceStatus.h,v 1.5 2004/08/03 16:25:14 blaufuss Exp $
 *
 * @file I3InIceStatus.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/08/03 16:25:14 $
 * @author pretz
 */
#ifndef I3INICESTATUSDATA_H
#define I3INICESTATUSDATA_H

#include "TObject.h"
#include "I3OMStatusIceCube.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief The status of the DeepIce detector.  
 *
 * Just a container for I3OMStatusIceCube objects
 */
class I3InIceStatus 
: public TObject, 
  public MapPolicy<OMKey,I3OMStatusIceCubePtr>::ThePolicy{
 public:
  /**
   * constructor
   */
  I3InIceStatus(){}

  /**
   * destructor
   */
  virtual ~I3InIceStatus(){};

 private:
  // copy and assignment are private
  I3InIceStatus(const I3InIceStatus& rhs);
  const I3InIceStatus& operator=(const I3InIceStatus& rhs);

  // ROOT macro
  ClassDef(I3InIceStatus,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3InIceStatus>::ThePolicy I3InIceStatusPtr;

#endif
