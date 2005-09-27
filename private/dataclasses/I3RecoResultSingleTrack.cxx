#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoResultSingleTrack.h>

template <class Archive>
  void I3RecoResultSingleTrack::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResultSingleParticle", 
		  base_object<I3RecoResultSingleParticle>(*this));
  }

  

I3_SERIALIZABLE(I3RecoResultSingleTrack);
