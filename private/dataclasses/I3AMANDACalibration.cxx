#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3AMANDACalibration.h>

template <class Archive>
  void I3AMANDACalibration::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3AMANDACalibration",
		  base_object< STLMapStoragePolicy<OMKey, I3AMANDAOMCalibPtr> >(*this));
  }

I3_SERIALIZABLE(I3AMANDACalibration);
