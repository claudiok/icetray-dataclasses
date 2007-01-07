#include <icetray/serialization.h>
#include <dataclasses/TankKey.h>

TankKey::~TankKey() { }

template <typename Archive>
void 
TankKey::serialize (Archive & ar, unsigned)
{
  ar & make_nvp("StringNumber",  stringNumber_);
  ar & make_nvp("TankID",  tankID_);
}

I3_SERIALIZABLE(TankKey);



