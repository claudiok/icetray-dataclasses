/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopGeometry.h,v 1.9 2004/04/27 13:35:23 pretz Exp $
 *
 * @file I3TopGeometry.h
 * @version $Revision: 1.9 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author Peter Niessen Thu Feb 19 12:48:42 EST 2004
 */
#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include "dataclasses/I3TankGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief This is an collection of tanks.
 */
class I3TopGeometry : public TObject, public VectorPolicy<I3TankGeo>::ThePolicy
{
 public:
  virtual ~I3TopGeometry(){};
  ClassDef(I3TopGeometry,1);
};

#endif
