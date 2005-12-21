#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3IceCubeDOMStatusDict.h>

I3IceCubeDOMStatusDict::~I3IceCubeDOMStatusDict() {}

template <class Archive>
  void I3IceCubeDOMStatusDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3IceCubeDOMStatus",
		  base_object< map<OMKey,I3DOMStatusPtr> >(*this));
  }


I3_SERIALIZABLE(I3IceCubeDOMStatusDict);
