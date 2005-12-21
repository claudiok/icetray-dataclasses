#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DigitalReadout.h>

I3DigitalReadout::~I3DigitalReadout() {}

template <class Archive>
  void I3DigitalReadout::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataReadout", base_object< I3DataReadout >(*this));
    ar & make_nvp("Vector", 
		  base_object< vector<I3DigitalLaunchPtr> >(*this));
  }

  

I3_SERIALIZABLE(I3DigitalReadout);
