#include <icetray/serialization.h>
#include "dataclasses/Utility.h"
#include "dataclasses/I3Quaternion.h"

template <class Archive> 
void I3Quaternion::serialize(Archive& ar, unsigned version)
{
	if (version>i3quaternion_version_)
		log_fatal("Attempting to read version %u from file but running version %u of I3Quaternion class.",version,i3quaternion_version_);
	
	ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	ar & make_nvp("x", x_);
	ar & make_nvp("y", y_);
	ar & make_nvp("z", z_);
	ar & make_nvp("w", w_);
}

I3_SERIALIZABLE(I3Quaternion);
