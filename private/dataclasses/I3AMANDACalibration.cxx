#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3AMANDACalibration.h>

I3AMANDACalibration::~I3AMANDACalibration(){}

template <class Archive>
  void I3AMANDACalibration::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3AMANDACalibration",
		  base_object< map<OMKey, I3AMANDAOMCalibPtr> >(*this));
  }

I3_SERIALIZABLE(I3AMANDACalibration);
