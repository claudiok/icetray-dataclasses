#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCCascade.h>

template <class Archive>
    void I3MCCascade::serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3MCCascade",
		  base_object< I3CascadeImpl<I3Directional,
		  I3Localized,
		  I3Energetic,
		  I3Composite> >(*this));
    ar & make_nvp("Weight",weight_);
  }

  

I3_SERIALIZABLE(I3MCCascade);