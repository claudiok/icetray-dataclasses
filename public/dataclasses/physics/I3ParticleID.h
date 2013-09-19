#ifndef I3ParticleID_H_INCLUDED
#define I3ParticleID_H_INCLUDED

#ifndef __CINT__
#include <icetray/serialization.h>
#endif

/**
 * @brief A single object for holding the ID numbers of an I3Particle
 */

struct I3ParticleID{
	uint64_t majorID;
	int32_t minorID;
	
	bool operator==(const I3ParticleID& other) const {
		return(majorID==other.majorID && minorID==other.minorID);
	}
	
	bool operator<(const I3ParticleID& other) const {
		if (majorID!=other.majorID)
			return(majorID<other.majorID);
		return(minorID<other.minorID);
	}
	
private:
#ifndef __CINT__
	friend class boost::serialization::access;
		
	template <class Archive> void serialize(Archive & ar, const unsigned version)
	{
		ar & make_nvp("majorID",majorID);
		ar & make_nvp("minorID",minorID);
	}
#endif
};

#ifndef __CINT__
#include <I3/hash_map.h>

#ifdef USING_GCC_EXT_HASH_MAP

namespace __gnu_cxx{
	template<>
	struct hash<I3ParticleID>{
		size_t operator()(const I3ParticleID& id) const{
			return(id.majorID + id.minorID);
		}
	};
}

#else //using std::unordered_map

template<>
struct i3hash<I3ParticleID>{
	size_t operator()(const I3ParticleID& id) const{
		return(id.majorID + id.minorID);
	}
};

#endif
#endif

#endif
