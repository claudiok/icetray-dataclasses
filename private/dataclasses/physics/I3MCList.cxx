#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCList.h>

I3MCList::~I3MCList() {}

template <class Archive>
  void I3MCList::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCList", base_object< I3Vector<I3ParticlePtr> >(*this));
  }
  

I3_SERIALIZABLE(I3MCList);
