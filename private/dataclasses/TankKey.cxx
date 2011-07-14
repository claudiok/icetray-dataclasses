#include <icetray/serialization.h>
#include "calibration/TankKey.h"



TankKey::~TankKey() { }

template <typename Archive>
void 
TankKey::serialize (Archive & ar, unsigned version)
{
  if (version>tankkey_version_)
    log_fatal("Attempting to read version %u from file but running version %u of TankKey class.",version,tankkey_version_);

  ar & make_nvp("StringNumber",  stringNumber_);
  ar & make_nvp("TankID",  tankID_);
}

I3_SERIALIZABLE(TankKey);


void TankKey::SetOMKey(const OMKey& omKey)
{
    if(omKey.IsIceTop())
    {
	stringNumber_ = omKey.GetString();
	tankID_ = ((omKey.GetOM()<63)?TankA:TankB);	
    }
    else
    {
	stringNumber_ = 0;
	tankID_ = TankA;
	log_error("%s is not an IceTop key!", omKey.str().c_str());
    }
}

std::ostream& operator<<(std::ostream& os, const TankKey& key)
{
    os << key.GetString();
    
    switch(key.GetTank())
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

