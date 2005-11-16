#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DoubleBang.h>

I3DoubleBang::~I3DoubleBang() {}

template <class Archive>
    void I3DoubleBang::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DoubleBang", 
		  base_object< I3TrackImpl<I3Contained,
		                           I3Energetic,
                                           I3Composite> >(*this));
  }

  

I3_SERIALIZABLE(I3DoubleBang);
