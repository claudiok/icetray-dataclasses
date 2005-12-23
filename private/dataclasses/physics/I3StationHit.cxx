#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3StationHit.h>

I3StationHit::~I3StationHit() {}

template <class Archive>
    void I3StationHit::serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3StationHit", 
		  base_object< vector<I3TankHitPtr> >(*this));
    ar & make_nvp("StationNumber",stationNumber_);

  }

  

I3_SERIALIZABLE(I3StationHit);
