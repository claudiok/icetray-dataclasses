#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3ShowerDirection.h>

template <class Archive>
    void I3ShowerDirection::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3ShowerDirection",
		  base_object< I3TopShowerImpl<I3Directional, 
		                               I3NonLocalized, 
		                               I3NonEnergetic> >(*this));
  }

  

I3_SERIALIZABLE(I3ShowerDirection);
