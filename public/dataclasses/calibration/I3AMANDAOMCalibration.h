/**
 *
 * Definition of I3AMANDAOMCalibration class
 *
 * Based of the sieglinde class SLCalibrateDBAmacalib
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id: I3AMANDAOMCalibration.h 7421 2005-05-09 03:41:09Z aya $
 * @file I3AMANDAOMCalibration.h
 * @date $Date: 2005-05-08 23:41:09 -0400 (Sun, 08 May 2005) $
 */

#ifndef I3AMANDAOMCALIBRATION_H_INCLUDED
#define I3AMANDAOMCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/calibration/I3AMANDAOM_XTalk.h"
#include <vector>
#include <sstream>

using namespace std;

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


  vector<I3AMANDAOM_XTalk> xtalk_receivers;


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

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3AMANDAOMCalibration);
BOOST_CLASS_VERSION(I3AMANDAOMCalibration, i3amandaomcalibration_version_);

#endif

