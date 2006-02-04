#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCTruth.h>

I3MCTruth::~I3MCTruth() {}

template <class Archive>
void 
I3MCTruth::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object<TObject>(*this));
  ar & make_nvp("mcID",mcID_);
  ar & make_nvp("mcLength",mcLength_);
}
  

I3_SERIALIZABLE(I3MCTruth);
