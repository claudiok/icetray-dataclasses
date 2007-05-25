#include <icetray/serialization.h>
#include <dataclasses/physics/I3StationHit.h>

I3StationHit::~I3StationHit() {}

template <class Archive>
void 
I3StationHit::serialize (Archive& ar, unsigned version)
{
  if (version>i3stationhit_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3StationHit class.",version,i3stationhit_version_);

  ar & make_nvp("I3StationHit", 
		base_object< I3Vector<I3TankHitPtr> >(*this));
  ar & make_nvp("StationNumber",stationNumber_);
  
}

  

I3_SERIALIZABLE(I3StationHit);
I3_SERIALIZABLE(I3StationHitMap);
