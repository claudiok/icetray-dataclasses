#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3TWRFrag.h>
I3TWRFrag::~I3TWRFrag() { }

template<class Archive>
void 
I3TWRFrag::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("ID",id);
  ar & make_nvp("ParentID",parent_id);
  ar & make_nvp("FragStartTime",frag_start_time);
  ar & make_nvp("FragStartBin",frag_start_bin);
  ar & make_nvp("Waveform",waveform);
}

I3_SERIALIZABLE(I3TWRFrag);
