#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Localized.h>

I3Localized::~I3Localized(){}

template <class Archive>
    void I3Localized::serialize(Archive& ar, unsigned version){
    ar & make_nvp("Pos",pos_);
    ar & make_nvp("Time",time_);
  }
  

I3_SERIALIZABLE(I3Localized);
