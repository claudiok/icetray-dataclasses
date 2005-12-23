#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3BasicCascade.h>

I3BasicCascade::~I3BasicCascade(){}

template <class Archive>
    void I3BasicCascade::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3BasicCascade", 
		  base_object< I3CascadeImpl<I3NonDirectional,
		                             I3Localized,
		                             I3NonEnergetic,
		                             I3NonComposite> >(*this));
  }

  

I3_SERIALIZABLE(I3BasicCascade);
