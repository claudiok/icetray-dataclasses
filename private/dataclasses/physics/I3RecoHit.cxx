#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3RecoHit.h>

I3RecoHit::~I3RecoHit() {}

template <class Archive>
    void I3RecoHit::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("time",time_);
    ar & make_nvp("hitID",hitID_);
    ar & make_nvp("user",user_);
  }

I3_SERIALIZABLE(I3RecoHit);
