#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCEventWeight.h>

I3MCEventWeight::~I3MCEventWeight() { }

template <class Archive>
  void I3MCEventWeight::serialize (Archive &ar, unsigned version)
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("weight",weight);
    ar & make_nvp("livetimePerFile",livetimePerFile);
    
  }     

I3_SERIALIZABLE(I3MCEventWeight);
