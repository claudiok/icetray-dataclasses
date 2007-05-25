#include <icetray/serialization.h>
#include <dataclasses/TankKey.h>

TankKey::~TankKey() { }

template <typename Archive>
void 
TankKey::serialize (Archive & ar, unsigned)
{
  if (version>tankkey_version_)
    log_fatal("Attempting to read version %s from file but running version %s of TankKey class.",version,tankkey_version_);

  ar & make_nvp("StringNumber",  stringNumber_);
  ar & make_nvp("TankID",  tankID_);
}

I3_SERIALIZABLE(TankKey);



