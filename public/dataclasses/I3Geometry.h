/**

    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Geometry.h,v 1.11 2004/02/21 02:24:13 pretz Exp $

    @version $Revision: 1.11 $
    @date $Date: 2004/02/21 02:24:13 $
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
class I3Geometry : public AugVec<I3GeometryHeader, I3OMGeoPtr, I3GeometryStoragePolicy>{
ClassDef(I3Geometry,1);
};

#endif
 
