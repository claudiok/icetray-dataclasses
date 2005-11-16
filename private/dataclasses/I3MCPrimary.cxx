#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCPrimary.h>

I3MCPrimary::~I3MCPrimary() { }

template <class Archive>
    void I3MCPrimary::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCPrimary",  
		  base_object< I3PrimaryImpl<I3Directional,
	                                     I3Localized,
	                                     I3Energetic> >(*this));
  }

  

I3_SERIALIZABLE(I3MCPrimary);
