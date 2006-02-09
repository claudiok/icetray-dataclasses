#include <dataclasses/BoostHeaders.h>
#include "dataclasses/physics/I3Waveform.h"

template <class Archive>
  void I3Waveform::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object<TObject>(*this));
    ar & make_nvp("startTime",startTime_);
    ar & make_nvp("binWidth",binWidth_);
    ar & make_nvp("waveform",waveform_);
    ar & make_nvp("source",source_);
  }