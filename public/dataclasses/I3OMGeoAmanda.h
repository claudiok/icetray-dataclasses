/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeoAmanda.h,v 1.11 2004/07/03 19:39:20 pretz Exp $
 *
 * @file I3OMGeoAmanda.h
 * @version $Revision: 1.11 $
 * @date $Date: 2004/07/03 19:39:20 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3OMGEOAMANDA_H
#define I3OMGEOAMANDA_H

#include "I3OMGeo.h"
#include <string>

/**
 * @brief This is the AMANDA specialization of the standard optical module 
 * geometry.  
 *
 * Stuff that an AMANDA OM had that an IceCube DOM doesn't *
 * @todo expand this to accomodate a full AMANDA geometry record
 */
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
   * Identifies this OM as an AMANDA OM
   */
  virtual EOMType GetOMType() { return AMANDA;}

  /**
   * assignment is just member-wise assignment
   */
  const I3OMGeoAmanda& operator=(const I3OMGeoAmanda& rhs){
    if(this == &rhs) return *this;
    I3OMGeo::operator=(rhs);
    return *this;
  }

  // for testing
  virtual std::string iam() { return "I3OMGeoAmanda"; }

 private:

  ClassDef(I3OMGeoAmanda,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3OMGeoAmanda>::ThePolicy I3OMGeoAmandaPtr;

#endif

