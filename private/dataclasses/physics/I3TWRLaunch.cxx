#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3TWRLaunch.h>

I3TWRLaunch::~I3TWRLaunch() {}

template<class Archive> 
void 
I3TWRLaunch::serialize (Archive& ar, unsigned version)
{
  ar & make_nvp("I3TWRLaunch", base_object< I3Vector<I3TWRFrag> >(*this));
  ar & make_nvp("ID",id);
  ar & make_nvp("BinSize",bin_size);
  ar & make_nvp("Baseline",baseline);
  ar & make_nvp("StopDelay",stop_delay);
  ar & make_nvp("Threshold",threshold);
  ar & make_nvp("Optical",optical);
}

I3_SERIALIZABLE(I3TWRLaunch);
