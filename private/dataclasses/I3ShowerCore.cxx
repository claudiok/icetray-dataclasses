#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3ShowerCore.h>

I3ShowerCore::~I3ShowerCore() {}

template <class Archive>
    void I3ShowerCore::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3ShowerCore",
		  base_object< I3TopShowerImpl<I3NonDirectional,
	                                       I3CoreLocalized,
                                               I3NonEnergetic> >(*this));
  }

  

I3_SERIALIZABLE(I3ShowerCore);
