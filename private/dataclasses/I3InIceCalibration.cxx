#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3InIceCalibration.h>

template <class Archive>
  void I3InIceCalibration::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3IceCubeStatus",
		  base_object< STLMapStoragePolicy<OMKey,I3DOMCalibPtr> >(*this));
  }



I3_SERIALIZABLE(I3InIceCalibration);
