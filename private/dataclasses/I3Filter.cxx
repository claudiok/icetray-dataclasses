#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Filter.h>

I3Filter::~I3Filter() {}

template <class Archive> void I3Filter::serialize(Archive& ar, unsigned version)  
  { 
    ar & make_nvp("FilterPass",filterPass_);
  }
 
  

I3_SERIALIZABLE(I3Filter);