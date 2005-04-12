/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeoIceCube.h,v 1.3 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3OMGeoIceCube.h
 * @version $Revision: 1.3 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3OMGEOICECUBE_H
#define I3OMGEOICECUBE_H

#include "I3OMGeo.h"

#include <string>

/**
 * @brief This is the IceCube specialization of the OMGeometry.  
 * 
 * The stuff that an IceCube DOM has that an AMANDA OM doesn't
 */

class I3OMGeoIceCube : public I3OMGeo
{
  public:
  /**
   * constructor
   */
  I3OMGeoIceCube() { };

  /**
   * copy constructor just uses assignment
   */
  I3OMGeoIceCube(const I3OMGeoIceCube& rhs){*this = rhs;}

  /**
   * destructor
   */
  virtual ~I3OMGeoIceCube(){};

  /**
   * assignment is just member-wise assignment
   */
  const I3OMGeo& operator=(const I3OMGeoIceCube& rhs){
    if(this == &rhs) return *this;
    I3OMGeo::operator=(rhs);
    return *this;
  }

  /**
   * identifies this OM as an IceCube om
   */
  virtual EOMType GetOMType() const { return IceCube;}

 private:

  ClassDef(I3OMGeoIceCube,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3OMGeoIceCube>  I3OMGeoIceCubePtr;

#endif

