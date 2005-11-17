#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3BasicTrack.h>

I3BasicTrack::~I3BasicTrack() {}

template <class Archive>
  void I3BasicTrack::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3BasicTrack", 
		  base_object< I3TrackImpl<I3Infinite,I3NonEnergetic,I3NonComposite> >(*this));
  }
  

I3_SERIALIZABLE(I3BasicTrack);
