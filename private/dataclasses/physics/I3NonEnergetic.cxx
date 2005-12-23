#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3NonEnergetic.h>

I3NonEnergetic::~I3NonEnergetic(){}

template <class Archive>
  void I3NonEnergetic::serialize(Archive& ar, unsigned  version)
  {
    //Nothing to serialize, but I think a serialize method
    //is still needed
  }
  

I3_SERIALIZABLE(I3NonEnergetic);
