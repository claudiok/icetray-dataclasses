/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeoAmanda.h,v 1.12 2004/07/05 17:13:11 pretz Exp $
 *
 * @file I3OMGeoAmanda.h
 * @version $Revision: 1.12 $
 * @date $Date: 2004/07/05 17:13:11 $
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
 */
class I3OMGeoAmanda : public I3OMGeo
{
  Double_t fTZero;

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
  virtual EOMType GetOMType() const { return AMANDA;}

  /**
   * @param t0 the new TZero for this OM
   */
  void SetTZero(Double_t t0) { fTZero = t0;}

  /**
   * @return the TZero for this OM
   */
  Double_t GetTZero() const { return fTZero;}

  /**
   * assignment is just member-wise assignment
   */
  const I3OMGeoAmanda& operator=(const I3OMGeoAmanda& rhs){
    if(this == &rhs) return *this;
    I3OMGeo::operator=(rhs);
    fTZero = rhs.fTZero;
    return *this;
  }

 private:

  ClassDef(I3OMGeoAmanda,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3OMGeoAmanda>::ThePolicy I3OMGeoAmandaPtr;

#endif

