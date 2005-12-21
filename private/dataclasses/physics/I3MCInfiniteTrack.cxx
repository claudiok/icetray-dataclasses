#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCInfiniteTrack.h>

I3MCInfiniteTrack::~I3MCInfiniteTrack() {}

template <class Archive>
  void I3MCInfiniteTrack::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCInfiniteTrack", base_object< I3TrackImpl<I3Infinite,
                                                          I3Energetic,
	                                                  I3Composite> >(*this));
    ar & make_nvp("Weight", weight_ );
  }

  

I3_SERIALIZABLE(I3MCInfiniteTrack);
