#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3CoreLocalized.h>

template <class Archive>
  void I3CoreLocalized::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("CoreT", coreT_ );
    ar & make_nvp("CorePos", corePos_ );
  }

  

I3_SERIALIZABLE(I3CoreLocalized);