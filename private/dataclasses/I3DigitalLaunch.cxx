#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DigitalLaunch.h>

I3DigitalLaunch::~I3DigitalLaunch(){}

template <class Archive>
  void I3DigitalLaunch::serialize(Archive& ar, unsigned version)
  {
    //This method needs to be empty
  }

  

I3_SERIALIZABLE(I3DigitalLaunch);
