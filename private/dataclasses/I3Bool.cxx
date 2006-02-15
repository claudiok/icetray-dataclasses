#include <dataclasses/BoostHeaders.h>
#include "dataclasses/I3Bool.h"

template <class Archive>
void
I3Bool::serialize(Archive& ar,unsigned)
{
  ar & make_nvp("TObject",base_object<TObject>(*this));
  ar & make_nvp("value",value_);
}

I3_SERIALIZABLE(I3Bool);

