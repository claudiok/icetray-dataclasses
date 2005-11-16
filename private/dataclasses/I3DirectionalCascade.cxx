#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DirectionalCascade.h>

template <class Archive>
    void I3DirectionalCascade::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DirectionalCascade",
		  base_object< I3CascadeImpl<I3Directional,
	                                     I3Localized,
                                             I3NonEnergetic,
		                             I3NonComposite> >(*this));
  }
  
  

I3_SERIALIZABLE(I3DirectionalCascade);
