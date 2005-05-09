/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3OMGeoAMANDA.h
 * @version $Revision: 1.5 $
 * @date $Date$
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
class I3OMGeoAMANDA : public I3OMGeo
{
  double tZero_;

  public:
  /**
   * constructor
   */
  I3OMGeoAMANDA() {;}

  /**
   * copy constructor just uses assignment
   */
  I3OMGeoAMANDA(const I3OMGeoAMANDA& rhs){*this = rhs;}

  /**
   * destructor
   */
  virtual ~I3OMGeoAMANDA(){}

  /**
   * Identifies this OM as an AMANDA OM
   */
  virtual EOMType GetOMType() const { return AMANDA;}

  /**
   * @param t0 the new TZero for this OM
   */
  void SetTZero(double t0) { tZero_ = t0;}

  /**
   * @return the TZero for this OM
   */
  double GetTZero() const { return tZero_;}

  /**
   * assignment is just member-wise assignment
   */
  const I3OMGeoAMANDA& operator=(const I3OMGeoAMANDA& rhs){
    if(this == &rhs) return *this;
    I3OMGeo::operator=(rhs);
    tZero_ = rhs.tZero_;
    return *this;
  }

 private:

  ClassDef(I3OMGeoAMANDA,1);
};

#include "dataclasses/StoragePolicy.h"
/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3OMGeoAMANDA>  I3OMGeoAMANDAPtr;

#endif

