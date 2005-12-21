#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3AMANDAOMCalib_XTalk.h>

I3AMANDAOMCalib_XTalk::~I3AMANDAOMCalib_XTalk() {}

template <class Archive>
  void I3AMANDAOMCalib_XTalk::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("receiver",receiver_);
    ar & make_nvp("timehigh",timehigh_);
    ar & make_nvp("timelow",timelow_);
    ar & make_nvp("width",width_);
    ar & make_nvp("threshold",threshold_);
  }

  

I3_SERIALIZABLE(I3AMANDAOMCalib_XTalk);
