#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3BadOMSelection.h>

I3BadOMSelection::~I3BadOMSelection() {}

template <class Archive>
  void I3BadOMSelection::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3BadOMSelection", base_object<I3OMListSelection>(*this) );
  }
 
I3_SERIALIZABLE(I3BadOMSelection);
