#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3IceCubeStatus.h>

template <class Archive>
  void I3IceCubeStatus::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3IceCubeStatus",
		  base_object< STLMapStoragePolicy<OMKey,I3DOMStatus> >(*this));
  }


I3_SERIALIZABLE(I3IceCubeStatus);
