#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoResultDict.h>

I3RecoResultDict::~I3RecoResultDict() {}

template <class Archive>
  void I3RecoResultDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResultDict", 
		  base_object< STLMapStoragePolicy<string,I3RecoResultPtr> >(*this));
  }

  

I3_SERIALIZABLE(I3RecoResultDict);
