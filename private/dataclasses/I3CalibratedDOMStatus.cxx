#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3CalibratedDOMStatus.h>

template <class Archive>
  void I3CalibratedDOMStatus::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("samplingRateA",samplingRateA_);
    ar & make_nvp("samplingRateB",samplingRateB_);
    ar & make_nvp("PMTGain",PMTGain_);
    ar & make_nvp("peakToValley",peakToValley_);
    ar & make_nvp("speMean",speMean_);
    ar & make_nvp("speWidth",speWidth_);
  }



I3_SERIALIZABLE(I3CalibratedDOMStatus);
