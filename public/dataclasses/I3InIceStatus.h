#ifndef I3INICESTATUSDATA_H
#define I3INICESTATUSDATA_H

#include "TObject.h"
#include "I3OMStatusIcecube.h"

/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceStatus.h,v 1.1 2004/03/02 20:58:51 pretz Exp $
 *
 *
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/02 20:58:51 $
 * @author pretz
 *
 * @todo 
 */

class I3InIceStatus 
: public TObject, 
  public VectorPolicy<I3OMStatusIcecube>::ThePolicy{
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
