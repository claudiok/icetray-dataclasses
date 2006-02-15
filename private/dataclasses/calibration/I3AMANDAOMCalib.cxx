#include <dataclasses/BoostHeaders.h>
#include <dataclasses/calibration/I3AMANDAOMCalib.h>

I3AMANDAOMCalib::~I3AMANDAOMCalib() {}

template <class Archive>
  void I3AMANDAOMCalib::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object< TObject >(*this));
    ar & make_nvp("adc_a0_",adc_a0_);
    ar & make_nvp("adc_beta",adc_beta_);
    ar & make_nvp("tdc_alpha",tdc_alpha_);
    ar & make_nvp("tdc_beta",tdc_beta_);
    ar & make_nvp("tdc_t0",tdc_t0_);
    ar & make_nvp("tdc_pol",tdc_pol_);
    ar & make_nvp("tot_beta",tot_beta_);
    ar & make_nvp("tot_tot0",tot_tot0_);
    ar & make_nvp("tot_pol",tot_pol_);
    ar & make_nvp("omo_a",omo_a_);
    ar & make_nvp("omo_b",omo_b_);
    ar & make_nvp("omo_c",omo_c_);
    ar & make_nvp("omo_d",omo_d_);
    ar & make_nvp("omo_e",omo_e_);
    ar & make_nvp("omo_lowlim",omo_lowlim_);
    ar & make_nvp("omo_highlim",omo_highlim_);
    ar & make_nvp("pe_area",pe_area_);
    ar & make_nvp("xtalk_senders",xtalk_receivers_);
  }



I3_SERIALIZABLE(I3AMANDAOMCalib);
