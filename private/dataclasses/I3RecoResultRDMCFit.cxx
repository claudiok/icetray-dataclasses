#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoResultRDMCFit.h>

template <class Archive> void I3RecoResultRDMCFit::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResultSingleTrack", base_object<I3RecoResultSingleTrack>(*this));
    ar & make_nvp("FitName", fitName_);
    ar & make_nvp("Parameters", parameters_);
  }

  

I3_SERIALIZABLE(I3RecoResultRDMCFit);
