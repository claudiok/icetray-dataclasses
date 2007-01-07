#include <icetray/serialization.h>
#include <dataclasses/calibration/I3AMANDAOMCalibration.h>

I3AMANDAOMCalibration::~I3AMANDAOMCalibration() {}

template <class Archive>
  void I3AMANDAOMCalibration::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("adc_a0_",adc_a0);
    ar & make_nvp("adc_beta",adc_beta);
    ar & make_nvp("tdc_alpha",tdc_alpha);
    ar & make_nvp("tdc_beta",tdc_beta);
    ar & make_nvp("tdc_t0",tdc_t0);
    ar & make_nvp("tdc_pol",tdc_pol);
    ar & make_nvp("tot_beta",tot_beta);
    ar & make_nvp("tot_tot0",tot_tot0);
    ar & make_nvp("tot_pol",tot_pol);
    ar & make_nvp("omo_a",omo_a);
    ar & make_nvp("omo_b",omo_b);
    ar & make_nvp("omo_c",omo_c);
    ar & make_nvp("omo_d",omo_d);
    ar & make_nvp("omo_e",omo_e);
    ar & make_nvp("omo_lowlim",omo_lowlim);
    ar & make_nvp("omo_highlim",omo_highlim);
    ar & make_nvp("pe_area",pe_area);
    ar & make_nvp("xtalk_senders",xtalk_receivers);
  }



I3_SERIALIZABLE(I3AMANDAOMCalibration);
