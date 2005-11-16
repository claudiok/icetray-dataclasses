#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoHitSeriesDict.h>

template <class Archive>
  void I3RecoHitSeriesDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoHitSeriesDict", 
		  base_object< STLMapStoragePolicy<string,I3RecoHitSeriesPtr> >(*this));
  }



  

I3_SERIALIZABLE(I3RecoHitSeriesDict);
