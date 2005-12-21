#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Event.h>

I3Event::~I3Event() {}

template <class Archive>
void 
I3Event::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("OMResponseMap", oMResponseMap_);
  ar & make_nvp("TopOMResponseMap", topOMResponseMap_);
}

I3_SERIALIZABLE(I3Event);

