#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCTopShower.h>

I3MCTopShower::~I3MCTopShower() {}

template <class Archive>
    void I3MCTopShower::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCTopShower",
		  base_object< I3TopShowerImpl<I3Directional,
	                                       I3CoreLocalized,
                                               I3Energetic> >(*this));
    ar & make_nvp("Weight", weight_);
  }
  

I3_SERIALIZABLE(I3MCTopShower);
