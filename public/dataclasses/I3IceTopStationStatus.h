#ifndef I3ICETOPSTATIONSTATUS_H
#define I3ICETOPSTATIONSTATUS_H

#include "TObject.h"
#include "I3OMStatusIcecube.h"

/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopStationStatus.h,v 1.1 2004/03/02 20:58:51 pretz Exp $
 *
 *
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/02 20:58:51 $
 * @author pretz
 *
 * @todo 
 */

class I3IceTopStationStatus 
: public TObject, 
  public VectorPolicy<I3OMStatusIcecube>::ThePolicy{
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
