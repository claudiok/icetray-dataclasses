#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3GoodOMSelection.h>

template <class Archive>
  void I3GoodOMSelection::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3GoodOMSelection", base_object<I3OMListSelection>(*this) );
  }

  

I3_SERIALIZABLE(I3GoodOMSelection);
