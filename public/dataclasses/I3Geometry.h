/**

    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Geometry.h,v 1.13 2004/02/23 17:14:19 pretz Exp $

    @version $Revision: 1.13 $
    @date $Date: 2004/02/23 17:14:19 $
    @author Some lazy sucker who did not put the header here.

    @todo 

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
  Double_t Time() const { return fTime; }
  void Time(Double_t time_) { fTime = time_; }

  Long_t Date() const {  return fDate; }
  void Date(Long_t date_) { fDate = date_; }

  virtual ~I3Geometry(){};
  ClassDef(I3Geometry,1);
};




#endif
 
