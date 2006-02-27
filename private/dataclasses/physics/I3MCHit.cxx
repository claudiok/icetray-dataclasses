#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCHit.h>
I3MCHit::~I3MCHit() { }
template <class Archive>
  void I3MCHit::serialize (Archive &ar, unsigned version)
  {
    ar & make_nvp("time",time_);
    ar & make_nvp("hitID",hitID_);
    ar & make_nvp("Weight", weight_);
    ar & make_nvp("ParticleID", particleID_);
    ar & make_nvp("CherenkovDistance", cherenkovDistance_);
  }     

  

I3_SERIALIZABLE(I3MCHit);
