/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3SurfModuleVector.h,v 1.1 2004/09/03 23:32:08 niessen Exp $
 *
 * @file I3SurfModuleVector.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/09/03 23:32:08 $
 * @author Peter Niessen Wed Sep  1 20:09:35 EDT 2004
 */

#ifndef I3SURFMODULEVECTOR_H
#define I3SURFMODULEVECTOR_H

#include "I3DataExecution.h"
#include "dataclasses/I3SurfModuleGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A vector which stores the tanks in icetop
 * 
 * A vector which can store the tanks in icetop. Facilitates looping
 * for dropping particles, doing reconstruction, ...
 *
 */
class I3SurfModuleVector : public TObject, public VectorPolicy<I3SurfModuleGeoPtr>::ThePolicy {

 public:

  /**
   * constructor
   */
  I3SurfModuleVector () {}

  /**
   * virtual dextructor
   */
  virtual ~I3SurfModuleVector () {}

 private:

  ClassDef (I3SurfModuleVector, 1);

};

/**
 * pointer type to hide away the implementation
 */
typedef PtrPolicy<I3SurfModuleVector>::ThePolicy I3SurfModuleVectorPtr;

#endif
