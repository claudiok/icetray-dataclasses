#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DigitalReadout.h>

template <class Archive>
  void I3DigitalReadout::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataReadout", base_object< I3DataReadout >(*this));
    ar & make_nvp("Vector", 
		  base_object< STLVectorStoragePolicy<I3DigitalLaunchPtr> >(*this));
  }

  

I3_SERIALIZABLE(I3DigitalReadout);