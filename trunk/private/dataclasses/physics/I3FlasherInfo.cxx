#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3FlasherInfo.h>



template <class Archive>
    void I3FlasherInfo::serialize(Archive& ar, unsigned version)
	{
	  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	  ar & make_nvp("FlasherOM", flasherOM_);
	  ar & make_nvp("FlashTime", flashTime_);
	  ar & make_nvp("ATWDBinSize", aTWDBinSize_);
	  ar & make_nvp("RawATWD3", rawATWD3_);
	  ar & make_nvp("mask", mask_);
	  ar & make_nvp("LEDBrightness", LEDBrightness_);
	  ar & make_nvp("width", width_);

	}



I3_SERIALIZABLE(I3FlasherInfo);
I3_SERIALIZABLE(I3FlasherInfoVect);
