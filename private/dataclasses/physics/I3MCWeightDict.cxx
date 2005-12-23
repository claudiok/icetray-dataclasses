#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCWeightDict.h>

I3MCWeightDict::~I3MCWeightDict(){}

template <class Archive>
  void I3MCWeightDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCWeightDict", base_object< map<string, double> >(*this));
  }
  

I3_SERIALIZABLE(I3MCWeightDict);
