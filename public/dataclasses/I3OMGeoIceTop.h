/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeoIceTop.h,v 1.1 2004/09/03 23:32:08 niessen Exp $
 * 
 * @file I3OMGeoIceTop.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/09/03 23:32:08 $
 * @author niessen
 */

#ifndef I3OMGEOICETOP_H
#define I3OMGEOICETOP_H

#include "I3OMGeo.h"

#include <string>

/**
 * @brief This is the ice top specialisation of the OM geometry
 *
 * Specify that the coordinates of the PMT are relative to the tank,
 * not the centre of the array.
 */
class I3OMGeoIceTop : public I3OMGeo {

 public:

  /**
   * constructor
   */
  I3OMGeoIceTop () {}

  /**
   * copy constructor performs assignment
   */
  I3OMGeoIceTop (const I3OMGeoIceTop &rhs) {
    *this = rhs;
  }
    
  /**
   * virtual destructor
   */
  virtual ~I3OMGeoIceTop () {}

  /**
   * assignment operator
   */
  const I3OMGeo &operator= (const I3OMGeoIceTop &rhs) {
    if (this == &rhs)
      return *this;
    I3OMGeo::operator= (rhs);
    return *this;
  }

  /**
   * identify as IceTop om
   */
  virtual EOMType GetOMType () const {
    return IceTop;
  }

 private:

  ClassDef (I3OMGeoIceTop, 1);

};

/**
 * define a pointer with the current storage policy
 */
typedef PtrPolicy<I3OMGeoIceTop>::ThePolicy I3OMGeoIceTopPtr;

#endif
 
