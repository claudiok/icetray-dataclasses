#ifndef I3GEOMETRY_H
#define I3GEOMETRY_H

#include <TObject.h>
#include "I3OMGeo.h"

class I3Geometry : public TObject
{
  double     time;
  long       date;
  TObjArray  *omgeo;

  public:
   I3Geometry();
  ~I3Geometry();

  double GetTime() const;
  long   GetDate() const;
  void SetTime(double time_);
  void SetDate(long date_);

  int            GetNumberOMGeos() const;
  const I3OMGeo& GetOMGeo(unsigned short index) const;
  bool HasOMGeoNumber(unsigned short omnumber) const;
  const I3OMGeo& FindOMGeo(unsigned short omnumber) const;
  void           AddOMGeo(I3OMGeo* omgeo_);

 private:
  const I3OMGeo* FindOMGeoPtr(unsigned short omnumber) const;

  ClassDef(I3Geometry, 1);
};
#endif
 
