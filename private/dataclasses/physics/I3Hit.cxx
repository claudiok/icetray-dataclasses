#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Hit.h>

I3Hit::~I3Hit() {}

template <class Archive>
void 
I3Hit::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("time",time_);
  ar & make_nvp("hitID",hitID_);
  ar & make_nvp("user",user_);
}

I3_SERIALIZABLE(I3Hit);
