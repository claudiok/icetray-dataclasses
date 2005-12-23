#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Composite.h>

I3Composite::~I3Composite() {}

template <class Archive>
  void I3Composite::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Constituents", constituents_);
  }
  

I3_SERIALIZABLE(I3Composite);
