/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3OMTopMap.h,v 1.1 2004/09/03 23:32:08 niessen Exp $
 *
 * @file I3OMTopMap.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/09/03 23:32:08 $
 * @author niessen Wed Sep  1 19:48:06 EDT 2004
 */


#ifndef __I3OMTOPMAP_H_
#define __I3OMTOPMAP_H_

#include <TObject.h>

#include "I3DataExecution.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/I3OMGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief Basically the same as I3TopGeometry, but for the OMs in the
 * icetop tank.
 *
 * Primary purpose is to be able to access the oms in the tank with
 * the string/61-64 OMKey mechanism.
 *
 * @version $Revision: 1.1 $
 * @author niessen
 * @date $Date: 2004/09/03 23:32:08 $
 */
class I3OMTopMap : public TObject, public MapPolicy<OMKey, I3OMGeoPtr>::ThePolicy {

 public:

  /**
   * constructor
   */
  I3OMTopMap () {}

  /**
   * virtual destructor
   */
  virtual ~I3OMTopMap () {}

 private:

  ClassDef (I3OMTopMap, 1);

};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3OMTopMap>::ThePolicy I3OMTopMapPtr;


#endif
