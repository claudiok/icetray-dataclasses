/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopStationStatus.h,v 1.4 2004/07/06 14:15:31 pretz Exp $
 *
 * @file I3IceTopStationStatus.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/07/06 14:15:31 $
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
  public VectorPolicy<I3OMStatusIceCube>::ThePolicy{
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
