
#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Double.h>

template <class Archive>
void
I3Double::serialize(Archive& ar,unsigned)
{
  ar & make_nvp("TObject",base_object<TObject>(*this));
  ar & make_nvp("value",value_);
}

I3_SERIALIZABLE(I3Double);

