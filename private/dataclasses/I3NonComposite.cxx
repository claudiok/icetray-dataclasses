#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3NonComposite.h>

template <class Archive>
  void I3NonComposite::serialize(Archive& ar, unsigned version)
  {
    //Nothing to serialize, but I think a serialize method
    //is still needed
  }
  

I3_SERIALIZABLE(I3NonComposite);
