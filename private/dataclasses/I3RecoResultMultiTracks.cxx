#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoResultMultiTracks.h>

template <class Archive>
    void I3RecoResultMultiTracks::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResult",base_object<I3RecoResult>(*this));
    ar & make_nvp("I3ParticlePtrVector",base_object< STLVectorStoragePolicy<I3ParticlePtr> >(*this));
  }

  

I3_SERIALIZABLE(I3RecoResultMultiTracks);
