#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3PMTPulseVect.h>

I3PMTPulseVect::~I3PMTPulseVect() {}

template <class Archive>
    void I3PMTPulseVect::serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3PMTPulseVect",
		  base_object< vector<I3PMTPulsePtr> >(*this));
  }
  

I3_SERIALIZABLE(I3PMTPulseVect);
