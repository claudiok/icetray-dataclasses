#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3F2KRecoInfiniteTrack.h>

template <class Archive>
    void I3F2KRecoInfiniteTrack::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3F2KRecoInfiniteTrack",
		  base_object< I3TrackImpl< I3Infinite,
                                            I3NonEnergetic,
                                            I3NonComposite> >(*this));
  }

  

I3_SERIALIZABLE(I3F2KRecoInfiniteTrack);
