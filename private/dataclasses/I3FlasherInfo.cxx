#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3FlasherInfo.h>

template <class Archive>
    void I3FlasherInfo::serialize(Archive& ar, unsigned version)
	{
	   // ar & make_nvp("I3Trigger", base_object<I3Trigger>(*this) );	    
	    ar & make_nvp("FlasherOM", flasherOM_);
	    ar & make_nvp("FlashTime", flashTime_);
	    ar & make_nvp("ATWDBinSize", aTWDBinSize_);
	    //ar & make_nvp("Trigger", trigger_);
	    //trigger_ isn't defined anywhere
	    ar & make_nvp("RawATWD3", rawATWD3_);
	    //ar & make_nvp("PedestalSubtractedATWD3", pedestalSubtractedATWD3_);
	    ar & make_nvp("mask", mask_);
	    ar & make_nvp("LEDBrightness", LEDBrightness_);
//	    ar & make_nvp("EventFlasherStatus", eventFlasherStatus_);
	}

I3_SERIALIZABLE(I3FlasherInfo);
