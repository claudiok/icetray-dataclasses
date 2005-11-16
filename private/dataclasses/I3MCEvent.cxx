#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCEvent.h>

I3MCEvent::~I3MCEvent() {}

template <class Archive>
void 
I3MCEvent::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3Event", base_object<I3Event>(*this));
  ar & make_nvp("MCFrameStart", MCFrameStart_);
  ar & make_nvp("MCFrameStop",MCFrameStop_ );
  ar & make_nvp("MCParticleData", MCParticleData_);
  ar & make_nvp("MCWeightDict", MCWeightDict_);
}

I3_SERIALIZABLE(I3MCEvent);

