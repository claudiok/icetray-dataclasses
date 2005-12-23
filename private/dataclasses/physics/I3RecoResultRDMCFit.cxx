#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3RecoResultRDMCFit.h>

I3RecoResultRDMCFit::~I3RecoResultRDMCFit() {}

template <class Archive> void I3RecoResultRDMCFit::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResultSingleTrack", base_object<I3RecoResultSingleParticle>(*this));
    ar & make_nvp("FitName", fitName_);
    ar & make_nvp("Parameters", parameters_);
  }

  

I3_SERIALIZABLE(I3RecoResultRDMCFit);
