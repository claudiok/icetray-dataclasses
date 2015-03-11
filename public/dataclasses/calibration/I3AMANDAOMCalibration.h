/**
 *
 * Definition of I3AMANDAOMCalibration class
 *
 * Based of the sieglinde class SLCalibrateDBAmacalib
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id$
 * @file I3AMANDAOMCalibration.h
 * @date $Date$
 */

#ifndef I3AMANDAOMCALIBRATION_H_INCLUDED
#define I3AMANDAOMCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/calibration/I3AMANDAOM_XTalk.h"
#include <vector>
#include <sstream>


/**
 * @brief Class that stores the calibration information for an AMANDA OM
 * 
 * This class stores the information from the Calibration stream.
 *
 */

static const unsigned i3amandaomcalibration_version_ = 0;

struct I3AMANDAOMCalibration 
{

  double adc_a0;
  double adc_beta;
  
  double tdc_alpha;
  double tdc_beta;
  double tdc_t0;
  int    tdc_pol;

  double tot_beta;
  double tot_tot0;
  int    tot_pol;

  //for ADC-TOT cut
  double omo_a, omo_b, omo_c, omo_d, omo_e;  
  double omo_lowlim;
  double omo_highlim;

  /**
   * TWR p.e/unit area constant
   */
  double pe_area;  


  std::vector<I3AMANDAOM_XTalk> xtalk_receivers;


  I3AMANDAOMCalibration() 
  {
    adc_a0=NAN;
    adc_beta=NAN;
    tdc_alpha=NAN;
    tdc_beta=NAN;
    tdc_t0=NAN;
    tdc_pol=0;
    tot_beta=NAN;
    tot_tot0=NAN;
    tot_pol=0;

    omo_a=NAN;
    omo_b=NAN;
    omo_c=NAN;
    omo_d=NAN;
    omo_e=NAN;
    omo_lowlim=NAN;
    omo_highlim=NAN;

    pe_area=NAN;
  };

  virtual ~I3AMANDAOMCalibration();
  
  bool operator==(const I3AMANDAOMCalibration rhs) const
  {
    return (adc_a0 == rhs.adc_a0 &&
        adc_beta == rhs.adc_beta &&
        tdc_alpha == rhs.tdc_alpha &&
        tdc_beta == rhs.tdc_beta &&
        tdc_t0 == rhs.tdc_t0 &&
        tdc_pol == rhs.tdc_pol &&
        tot_beta == rhs.tot_beta &&
        tot_tot0 == rhs.tot_tot0 &&
        tot_pol == rhs.tot_pol &&
        omo_a == rhs.omo_a &&
        omo_b == rhs.omo_b &&
        omo_c == rhs.omo_c &&
        omo_d == rhs.omo_d &&
        omo_e == rhs.omo_e &&
        omo_lowlim == rhs.omo_lowlim &&
        omo_highlim == rhs.omo_highlim &&
        pe_area == rhs.pe_area &&
        xtalk_receivers == rhs.xtalk_receivers);
  }
  bool operator!=(const I3AMANDAOMCalibration rhs) const
  {
    return !operator==(rhs);
  }

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3AMANDAOMCalibration);
BOOST_CLASS_VERSION(I3AMANDAOMCalibration, i3amandaomcalibration_version_);

#endif

