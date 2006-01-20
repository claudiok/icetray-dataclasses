#ifndef I3ICEUBERESPONSE_H
#define I3ICEUBERESPONSE_H

#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/physics/I3DOMLaunch.h"

class I3IceCubeResponse : public I3Map<OMKey,vector<I3DOMLaunch> >
{
 public:
  I3IceCubeResponse(){}
  
  virtual ~I3IceCubeResponse()

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

#endif
