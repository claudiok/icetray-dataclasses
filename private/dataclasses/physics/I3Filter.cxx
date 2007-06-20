#include <icetray/serialization.h>
#include <dataclasses/physics/I3Filter.h>

I3Filter::~I3Filter() {}

template <class Archive> void I3Filter::serialize(Archive& ar, unsigned version)  
  {
   if (version>i3filter_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3Filter class.",version,i3filter_version_);

    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("FilterPass",filterPass_);
  }
 
  

I3_SERIALIZABLE(I3Filter);
