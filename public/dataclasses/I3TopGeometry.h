/**

    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TopGeometry.h,v 1.6 2004/02/26 21:04:09 pretz Exp $

    @version $Revision: 1.6 $
    @date $Date: 2004/02/26 21:04:09 $
    @author Peter Niessen Thu Feb 19 12:48:42 EST 2004

    @brief This is an collection of tanks.

    @todo 

*/

#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include "dataclasses/I3TankGeo.h"
#include "dataclasses/StoragePolicy.h"


class I3TopGeometry : public VectorPolicy<I3TankGeo>::ThePolicy
{
 public:
  virtual ~I3TopGeometry(){};
  ClassDef(I3TopGeometry,1);
};

#endif
