#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3F2KRecoTrack.h>

template <class Archive>
    void I3F2KRecoTrack::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3F2KRecoTrack",
		  base_object< I3TrackImpl< I3Contained,
                                            I3NonEnergetic,
                                            I3NonComposite> >(*this));
  }

  

I3_SERIALIZABLE(I3F2KRecoTrack);
