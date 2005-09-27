#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3OMResponseMap.h>

template <class Archive>
  void I3OMResponseMap::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3OMResponseMap", 
		  base_object< STLMapStoragePolicy<OMKey,I3OMResponsePtr> >(*this));
  }

  

I3_SERIALIZABLE(I3OMResponseMap);
