#ifndef I3OMGEOICECUBE_H
#define I3OMGEOICECUBE_H

#include "I3OMGeo.h"

class I3OMGeoIcecube : public I3OMGeo
{

  public:
  I3OMGeoIcecube();
  I3OMGeoIcecube(const I3OMGeoIcecube& rhs){*this = rhs;}
  virtual ~I3OMGeoIcecube(){};
  const I3OMGeo& operator=(const I3OMGeoIcecube& rhs){
    if(this == &rhs) return *this;
    I3OMGeo::operator=(rhs);
    return *this;
  }

  ClassDef(I3OMGeoIcecube,1);
};

typedef I3OMGeoIcecube* I3OMGeoIcecubePtr;

#endif

