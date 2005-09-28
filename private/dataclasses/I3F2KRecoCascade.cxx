#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3F2KRecoCascade.h>

template <class Archive>
    void I3F2KRecoCascade::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3F2KRecoCascade",
		  base_object< I3CascadeImpl< I3Directional,
                                              I3Localized,
                                              I3NonEnergetic,
                                              I3NonComposite> >(*this));
  }

  

I3_SERIALIZABLE(I3F2KRecoCascade);
