#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoResult.h>

I3RecoResult::~I3RecoResult(){}

template <class Archive>
  void I3RecoResult::serialize(Archive& ar, unsigned version)
  {
    //This method intentionally left blank
  }

  

I3_SERIALIZABLE(I3RecoResult);
