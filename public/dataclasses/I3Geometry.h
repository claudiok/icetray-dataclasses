/**

    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Geometry.h,v 1.10 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/20 21:42:08 $
    @author Some lazy sucker who did not put the header here.

    @todo 

*/


#ifndef I3GEOMETRY_H
#define I3GEOMETRY_H

#include <TObject.h>
#include "I3OMGeo.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3GeometryHeader {
  Double_t     fTime;
  Long_t       fDate;
 public:
  Double_t Time() const { return fTime; }
  void Time(Double_t time_) { fTime = time_; }

  Long_t Date() const {  return fDate; }
  void Date(Long_t date_) { fDate = date_; }
};

typedef StoragePolicy<I3OMGeoPtr> I3GeometryStoragePolicy;
typedef AugVec<I3GeometryHeader, I3OMGeoPtr, I3GeometryStoragePolicy> I3Geometry;

#endif
 
