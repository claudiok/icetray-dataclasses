#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCCorePrimary.h>

template <class Archive>
    void I3MCCorePrimary::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCCorePrimary",
		   base_object< I3PrimaryImpl<I3Directional,
	                                      I3CoreLocalized,
		                              I3Energetic> >(*this));
  }

  

I3_SERIALIZABLE(I3MCCorePrimary);
