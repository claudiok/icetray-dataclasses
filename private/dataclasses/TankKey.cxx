#include <icetray/serialization.h>
#include "dataclasses/TankKey.h"


template <typename Archive>
void 
TankKey::serialize (Archive & ar, unsigned version)
{
  if (version>tankkey_version_)
    log_fatal("Attempting to read version %u from file but running version %u of TankKey class.",version,tankkey_version_);

  ar & make_nvp("StringNumber",  string);
  ar & make_nvp("TankID",  tank);
}

I3_SERIALIZABLE(TankKey);


void TankKey::SetOMKey(const OMKey& omKey)
{
    if(omKey.IsIceTop())
    {
	string = omKey.GetString();
	tank = ((omKey.GetOM()<63) ? TankA : TankB);	
    }
    else
    {
	string = 0;
	tank = TankA;
	log_error("%s is not an IceTop key!", omKey.str().c_str());
    }
}

std::ostream& operator<<(std::ostream& os, const TankKey& key)
{
    os << key.string;
    
    switch (key.tank)
    {
	case TankKey::TankA: {os << "A"; break;}
	case TankKey::TankB: {os << "B"; break;}
	default:             {os << "?"; break;}
    }
    
    return os;
}

std::string TankKey::str() const
{
    std::stringstream os;
    os << *this;
    return os.str();
}

