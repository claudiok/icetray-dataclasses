#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3OMSelectionDict.h>

I3OMSelectionDict::~I3OMSelectionDict() {}

template <class Archive>
  void I3OMSelectionDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3OMSelectionDict", 
		  base_object< STLMapStoragePolicy<string,I3OMResponseSelectionPtr> >(*this));
  }

  

I3_SERIALIZABLE(I3OMSelectionDict);
