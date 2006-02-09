#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3CalibratedDOMStatus.h>

I3CalibratedDOMStatus::~I3CalibratedDOMStatus(){}

template <class Archive>
void 
I3CalibratedDOMStatus::serialize (Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("samplingRateA",samplingRateA_);
  ar & make_nvp("samplingRateB",samplingRateB_);
  ar & make_nvp("PMTGain",PMTGain_);
  ar & make_nvp("speMean",speMean_);
}



I3_SERIALIZABLE(I3CalibratedDOMStatus);