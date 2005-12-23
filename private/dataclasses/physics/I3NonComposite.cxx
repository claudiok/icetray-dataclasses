#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3NonComposite.h>

I3NonComposite::~I3NonComposite(){}

template <class Archive>
  void I3NonComposite::serialize(Archive& ar, unsigned version)
  {
    //Nothing to serialize, but I think a serialize method
    //is still needed
  }
  

I3_SERIALIZABLE(I3NonComposite);
