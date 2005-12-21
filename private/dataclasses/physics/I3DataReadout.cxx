#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DataReadout.h>

I3DataReadout::~I3DataReadout() {}

template <class Archive>
  void I3DataReadout::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Raw", raw_);
  }

  

I3_SERIALIZABLE(I3DataReadout);
