/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Geometry.h,v 1.14 2004/02/25 20:10:24 pretz Exp $
 *
 * Right now just a containter for IceCube and Amanda OMGeos.  Should be
 * replaced with a container for the InIce Geometry and the IceTop Geometry
 * The reason for the change would be that IceTop regards their Geometry
 * to really be an array of 'Stations' rather than an array of "OMs"
 *
 * @version $Revision: 1.14 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo This class should go to a holder for the InIce and the IceTop geometries
 * @todo Move the header-like data into the GeometryHeader
*/


#ifndef I3GEOMETRY_H
#define I3GEOMETRY_H

#include <TObject.h>
#include "I3OMGeo.h"
#include "StoragePolicy.h"

class I3Geometry : public TObject, public VectorPolicy<I3OMGeoPtr>::ThePolicy
{
  Double_t     fTime;
  Long_t       fDate;
 public:
  /** 
   * constructor
   */
  I3Geometry(){};

  /**
   * default destructor
   */
  virtual ~I3Geometry(){};

  /**
   * @return the time that this 'Geometry' is good for.
   */
  Double_t Time() const { return fTime; }

  /**
   * @param time the new time stamp on this geometry
   */
  void Time(Double_t time) { fTime = time; }

  /**
   * @return the date this geometry is good for
   */
  Long_t Date() const {  return fDate; }

  /**
   * @param date the new date this geometry is good for.
   */
  void Date(Long_t date) { fDate = date; }

 private:
  // copy and assignment are private
  I3Geometry(const I3Geometry& rhs);
  const I3Geometry& operator=(const I3Geometry& rhs);

  // ROOT macro
  ClassDef(I3Geometry,1);
};

typedef PtrPolicy<I3Geometry>::ThePolicy I3GeometryPtr;

#endif
 
