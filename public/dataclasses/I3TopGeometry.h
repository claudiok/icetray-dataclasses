/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopGeometry.h,v 1.9.2.1 2004/07/19 22:26:51 ehrlich Exp $
 *
 * @file I3TopGeometry.h
 * @version $Revision: 1.9.2.1 $
 * @date $Date: 2004/07/19 22:26:51 $
 * @author Peter Niessen Thu Feb 19 12:48:42 EST 2004
 */
#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include <TObject.h>

#include "I3DataExecution.h"
#include "dataclasses/I3TopStationGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief This is an collection of tanks.
 */
class I3TopGeometry : public TObject, public VecPointainerPolicy<I3TopStationGeoPtr>::ThePolicy
{
 public:

  /**
   * Constructor
   */
  I3TopGeometry () {}

  /**
   * Virtual Destructor
   */
  virtual ~I3TopGeometry(){}

 private:
  ClassDef(I3TopGeometry,1);
};

#endif
