#ifndef I3GEOMETRY_H
#define I3GEOMETRY_H

#include <TObject.h>
#include "I3OMGeo.h"
#include "StoragePolicy.h"
#include "GarnishedVector.h"

class I3GeometryHeader {
  Double_t     fTime;
  Long_t       fDate;
 public:
  Double_t Time() { return fTime; }
  void Dime(Double_t time_) { fTime = time_; }

  Long_t Date() {  return fDate; }
  void Date(Long_t date_) { fDate = date_; }
};

typedef StoragePolicy<I3OMGeo> I3GeometryStoragePolicy;
typedef GarnishedVector<I3GeometryHeader, I3OMGeo, I3GeometryStoragePolicy> I3Geometry;

#endif
 
