#ifndef I3OMGEOICECUBE_H
#define I3OMGEOICECUBE_H

#include "I3OMGeo.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeoIcecube.h,v 1.5 2004/02/26 03:51:13 pretz Exp $
 *
 * This is the IceCube specialization of the OMGeometry.  The stuff that 
 * an IceCube DOM has that an AMANDA OM doesn't
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/02/26 03:51:13 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 */
class I3OMGeoIcecube : public I3OMGeo
{
  public:
  /**
   * constructor
   */
  I3OMGeoIcecube();

  /**
   * copy constructor just uses assignment
   */
  I3OMGeoIcecube(const I3OMGeoIcecube& rhs){*this = rhs;}

  /**
   * destructor
   */
  virtual ~I3OMGeoIcecube(){};

  /**
   * assignment is just member-wise assignment
   */
  const I3OMGeo& operator=(const I3OMGeoIcecube& rhs){
    if(this == &rhs) return *this;
    I3OMGeo::operator=(rhs);
    return *this;
  }
 private:
  // ROOT macro
  ClassDef(I3OMGeoIcecube,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMGeoIcecube>::ThePolicy I3OMGeoIcecubePtr;

#endif

