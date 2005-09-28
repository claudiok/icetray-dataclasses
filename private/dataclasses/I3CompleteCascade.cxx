#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3CompleteCascade.h>

template <class Archive>
    void I3CompleteCascade::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3CompleteCascade", 
		  base_object<I3CascadeImpl< I3Directional,
	                                     I3Localized,
	                                     I3Energetic,
		                             I3NonComposite> >(*this));
  }
  

I3_SERIALIZABLE(I3CompleteCascade);
