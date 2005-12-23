#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCTrack.h>

I3MCTrack::~I3MCTrack(){}

template <class Archive>
  void I3MCTrack::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCTrack", base_object< I3TrackImpl<I3Contained,
		                                              I3Energetic,
		                                              I3Composite> >(*this));
    ar & make_nvp("Weight", weight_ );
  }

  

I3_SERIALIZABLE(I3MCTrack);
