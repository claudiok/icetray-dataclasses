#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Energetic.h>

template <class Archive>
  void I3Energetic::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Energy", energy_);
  }

  

I3_SERIALIZABLE(I3Energetic);
