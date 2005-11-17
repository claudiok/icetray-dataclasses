#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DataReadoutDict.h>

I3DataReadoutDict::~I3DataReadoutDict() {}

template <class Archive>
  void I3DataReadoutDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataReadoutDict", 
		  base_object< STLMapStoragePolicy<string,I3DataReadoutPtr> >(*this));
  }

  

I3_SERIALIZABLE(I3DataReadoutDict);
