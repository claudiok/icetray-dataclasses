#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3IceCubeDOMStatusDict.h>

I3IceCubeDOMStatusDict::~I3IceCubeDOMStatusDict() {}

template <class Archive>
  void I3IceCubeDOMStatusDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3IceCubeDOMStatus",
		  base_object< STLMapStoragePolicy<OMKey,I3DOMStatus> >(*this));
  }


I3_SERIALIZABLE(I3IceCubeDOMStatusDict);
