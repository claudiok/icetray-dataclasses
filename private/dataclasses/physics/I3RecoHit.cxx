#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoHit.h>

I3RecoHit::~I3RecoHit() {}

template <class Archive>
    void I3RecoHit::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3Hit", base_object<I3Hit>(*this));
  }



I3_SERIALIZABLE(I3RecoHit);
