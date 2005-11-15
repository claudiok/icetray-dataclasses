#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Event.h>

template <class Archive>
void 
I3Event::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("OMResponseMap", oMResponseMap_);
  ar & make_nvp("TopOMResponseMap", topOMResponseMap_);
  ar & make_nvp("OMSelectionDict", oMSelectionDict_);
  ar & make_nvp("RecoResultDict", recoResultDict_);
  ar & make_nvp("TriggerDict", triggerDict_);
}

I3_SERIALIZABLE(I3Event);

