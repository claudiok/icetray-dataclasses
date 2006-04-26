#include <dataclasses/BoostHeaders.h>
#include <dataclasses/calibration/I3AMANDAOM_XTalk.h>

I3AMANDAOM_XTalk::~I3AMANDAOM_XTalk() {}

template <class Archive>
  void I3AMANDAOM_XTalk::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("receiver",receiver);
    ar & make_nvp("timehigh",timehigh);
    ar & make_nvp("timelow",timelow);
    ar & make_nvp("width",width);
    ar & make_nvp("threshold",threshold);
  }

  

I3_SERIALIZABLE(I3AMANDAOM_XTalk);
