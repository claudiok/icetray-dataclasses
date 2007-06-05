#include <icetray/serialization.h>
#include <dataclasses/physics/I3MCHit.h>
#include <dataclasses/physics/I3Particle.h>
I3MCHit::~I3MCHit() { }

void I3MCHit::SetParticleID(const I3Particle& p) { 
  particleID_ = p.GetMinorID(); 
  particleMajorID_ = p.GetMajorID();
}


template <class Archive>
  void I3MCHit::serialize (Archive &ar, unsigned version)
  {
  if (version>i3mchit_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3MCHit class.",version,i3mchit_version_);

    ar & make_nvp("time",time_);
    ar & make_nvp("hitID",hitID_);
    ar & make_nvp("Weight", weight_);
    ar & make_nvp("ParticleID", particleID_);
    if(version>0)
      ar & make_nvp("ParticleMajorID", particleMajorID_);
    ar & make_nvp("CherenkovDistance", cherenkovDistance_);
    if(version>1)
      ar & make_nvp("HitSource", source_);
  }     

  

I3_SERIALIZABLE(I3MCHit);
I3_SERIALIZABLE(I3MCHitSeriesMap);
