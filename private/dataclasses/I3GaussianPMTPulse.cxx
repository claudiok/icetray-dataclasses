#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3GaussianPMTPulse.h>

template <class Archive>
    void I3GaussianPMTPulse::serialize(Archive& ar, unsigned version){
    make_nvp("I3PMTPulse",base_object<I3PMTPulse>(*this));
    make_nvp("Normalization",normalization_);
    make_nvp("Sigma",sigma_);
    make_nvp("TimeZero",timeZero_);
    make_nvp("Pedestal",pedestal_);
  }


I3_SERIALIZABLE(I3GaussianPMTPulse);
