/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeoAmanda.h,v 1.7 2004/03/03 15:37:01 troy Exp $
 *
 * This is the AMANDA specialization of the standard optical module 
 * geometry.  Stuff that an AMANDA OM had that an IceCube DOM doesn't
 *
 * @version $Revision: 1.7 $
 * @date $Date: 2004/03/03 15:37:01 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo expand this to accomodate a full AMANDA geometry record
 *
 */
#ifndef I3OMGEOAMANDA_H
#define I3OMGEOAMANDA_H

#include "I3OMGeo.h"
#include <string>

class I3OMGeoAmanda : public I3OMGeo
{
  public:
  /**
   * constructor
   */
  I3OMGeoAmanda() {;}

  /**
   * copy constructor just uses assignment
   */
  I3OMGeoAmanda(const I3OMGeoAmanda& rhs){*this = rhs;}

  /**
   * destructor
   */
  virtual ~I3OMGeoAmanda(){}

  /**
   * assignment is just member-wise assignment
   */
  const I3OMGeoAmanda& operator=(const I3OMGeoAmanda& rhs){
    if(this == &rhs) return *this;
    I3OMGeo::operator=(rhs);
    return *this;
  }

  // for testing
  virtual std::string iam() { return "OMGeoAmanda"; }

 private:

  ClassDef(I3OMGeoAmanda,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3OMGeoAmanda>::ThePolicy I3OMGeoAmandaPtr;

#endif

