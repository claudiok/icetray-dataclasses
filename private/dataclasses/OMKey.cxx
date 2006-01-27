#include <dataclasses/BoostHeaders.h>
#include <dataclasses/OMKey.h>

OMKey::~OMKey() { }

template <typename Archive>
void 
OMKey::serialize (Archive & ar, unsigned)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("StringNumber",  stringNumber_);
  ar & make_nvp("OMNumber",  omNumber_);
}

I3_SERIALIZABLE(OMKey);
