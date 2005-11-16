#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Infinite.h>

I3Infinite::~I3Infinite() {}

template <class Archive>
  void I3Infinite::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Pos", pos_ );
    ar & make_nvp("Dir", dir_ );
    ar & make_nvp("Time", time_ );
  }
  

I3_SERIALIZABLE(I3Infinite);
