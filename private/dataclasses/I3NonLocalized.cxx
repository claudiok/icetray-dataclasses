#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3NonLocalized.h>

template <class Archive>
  void I3NonLocalized::serialize(Archive& ar, unsigned version)
  {
    //This method intentionally left blank
  }

  

I3_SERIALIZABLE(I3NonLocalized);
