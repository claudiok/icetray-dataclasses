#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3OMResponseSelection.h>

I3OMResponseSelection::~I3OMResponseSelection() {}

template <class Archive>
  void I3OMResponseSelection::serialize(Archive& ar, unsigned version)
  {
    //Empty seriliaze method is needed here
  }

  

I3_SERIALIZABLE(I3OMResponseSelection);
