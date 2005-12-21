#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3OMResponseMap.h>

I3OMResponseMap::~I3OMResponseMap() {}

template <class Archive>
  void I3OMResponseMap::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3OMResponseMap", 
		  base_object< map<OMKey,I3OMResponsePtr> >(*this));
  }

  

I3_SERIALIZABLE(I3OMResponseMap);
