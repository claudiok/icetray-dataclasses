#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3ContainedTrack.h>

I3ContainedTrack::~I3ContainedTrack() {}

template <class Archive>
    void I3ContainedTrack::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3ContainedTrack",
		  base_object< I3TrackImpl< I3Contained,
                                            I3NonEnergetic,
                                            I3NonComposite> >(*this));
  }

  

I3_SERIALIZABLE(I3ContainedTrack);
