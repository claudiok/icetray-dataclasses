#ifndef I3OMGEOICECUBE_H
#define I3OMGEOICECUBE_H

#include "I3OMGeo.h"

#include <string>

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeoIcecube.h,v 1.7 2004/03/04 16:45:56 troy Exp $
 *
 * This is the IceCube specialization of the OMGeometry.  The stuff that 
 * an IceCube DOM has that an AMANDA OM doesn't
 *
 * @version $Revision: 1.7 $
 * @date $Date: 2004/03/04 16:45:56 $
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

  // for testing
  virtual std::string iam() { return "I3OMGeoIcecube"; }

 private:

  ClassDef(I3OMGeoIcecube,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMGeoIcecube>::ThePolicy I3OMGeoIcecubePtr;

#endif

