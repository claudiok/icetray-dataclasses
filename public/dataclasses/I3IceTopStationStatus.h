/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopStationStatus.h,v 1.5 2004/08/03 16:25:14 blaufuss Exp $
 *
 * @file I3IceTopStationStatus.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/08/03 16:25:14 $
 * @author pretz
 */
#ifndef I3ICETOPSTATIONSTATUS_H
#define I3ICETOPSTATIONSTATUS_H

#include "TObject.h"
#include "I3OMStatusIceCube.h"

/**
 * @brief the status of an IceTop station for the DetectorStatus stream.
 * Just holding a place for now
 *
 */
class I3IceTopStationStatus 
: public TObject, 
  public VectorPolicy<I3OMStatusIceCubePtr>::ThePolicy{
 public:
  /**
   * constructor
   */
  I3IceTopStationStatus(){}

  /**
   * destructor
   */
  virtual ~I3IceTopStationStatus(){};

 private:
  // copy and assignment are private
/*   I3IceTopStationStatus(const I3IceTopStationStatus& rhs); */
/*   const I3IceTopStationStatus& operator=(const I3IceTopStationStatus& rhs); */

  // ROOT macro
  ClassDef(I3IceTopStationStatus,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3IceTopStationStatus>::ThePolicy I3IceTopStationStatusPtr;

#endif
