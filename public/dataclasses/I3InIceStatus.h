/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceStatus.h,v 1.3 2004/07/06 14:15:31 pretz Exp $
 *
 * @file I3InIceStatus.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/06 14:15:31 $
 * @author pretz
 */
#ifndef I3INICESTATUSDATA_H
#define I3INICESTATUSDATA_H

#include "TObject.h"
#include "I3OMStatusIceCube.h"

/**
 * @brief The status of the DeepIce detector.  
 *
 * Just a container for I3OMStatusIceCube objects
 */
class I3InIceStatus 
: public TObject, 
  public VectorPolicy<I3OMStatusIceCube>::ThePolicy{
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
