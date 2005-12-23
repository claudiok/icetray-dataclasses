#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Trigger.h>

I3Trigger::~I3Trigger(){ }
template <class Archive> void I3Trigger::serialize(Archive& ar, unsigned version)  
  { 
    ar & make_nvp("TriggerTime",triggerTime_);
    ar & make_nvp("TriggerLength",triggerLength_);
    ar & make_nvp("Fired",fired_);
    ar & make_nvp("TriggerSubDetector",triggerSubDetector_);
  }
 
  

I3_SERIALIZABLE(I3Trigger);
