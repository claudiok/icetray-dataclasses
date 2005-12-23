#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3RecoHitSeriesDict.h>

I3RecoHitSeriesDict::~I3RecoHitSeriesDict() {}

template <class Archive>
  void I3RecoHitSeriesDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoHitSeriesDict", 
		  base_object< map<string,I3RecoHitSeriesPtr> >(*this));
  }



  

I3_SERIALIZABLE(I3RecoHitSeriesDict);
