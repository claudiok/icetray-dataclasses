#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3DOMLaunchSeries.h>

I3DOMLaunchSeries::~I3DOMLaunchSeries() {}

template <class Archive>
  void I3DOMLaunchSeries::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DOMLaunchSeries", base_object< vector<I3DOMLaunch> >(*this));
  }



  

I3_SERIALIZABLE(I3DOMLaunchSeries);
