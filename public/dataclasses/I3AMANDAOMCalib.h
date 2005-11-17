/**
 *
 * Definition of I3AMANDAOMCalibration class
 *
 * Based of the sieglinde class SLCalibrateDBAmacalib
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3AMANDAOMCalibration.h 7421 2005-05-09 03:41:09Z aya $
 *
 * @file I3AMANDAOMCalibration.h
 * @version $Revision: 1.14 $
 * @date $Date: 2005-05-08 23:41:09 -0400 (Sun, 08 May 2005) $
 * @author tmccauley
 * @author olivas
 * @author ehrlich
 */
#ifndef I3AMANDAOMCALIBRATION_H
#define I3AMANDAOMCALIBRATION_H

#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3AMANDAOMCalib_XTalk.h"

#include <vector>
#include <sstream>
#include <TObject.h>

using namespace std;

/**
 * @brief Class that stores the calibration information for an AMANDA OM
 * 
 * This class stores the information from the Calibration stream.
 *
 */

class I3AMANDAOMCalib : public TObject
{
  double adc_a0_;
  double adc_beta_;

  double tdc_alpha_;
  double tdc_beta_;
  double tdc_t0_;
  int    tdc_pol_;

  double tot_beta_;
  double tot_tot0_;
  int    tot_pol_;

  double omo_a_, omo_b_, omo_c_, omo_d_, omo_e_;  //for ADC-TOT cut
  double omo_lowlim_;
  double omo_highlim_;

  vector<I3AMANDAOMCalib_XTalk> xtalk_receivers_;

  public:

  I3AMANDAOMCalib() 
  {
    adc_a0_=NAN;
    adc_beta_=NAN;
    tdc_alpha_=NAN;
    tdc_beta_=NAN;
    tdc_t0_=NAN;
    tdc_pol_=0;
    tot_beta_=NAN;
    tot_tot0_=NAN;
    tot_pol_=0;

    omo_a_=NAN;
    omo_b_=NAN;
    omo_c_=NAN;
    omo_d_=NAN;
    omo_e_=NAN;
    omo_lowlim_=NAN;
    omo_highlim_=NAN;
  };
  virtual ~I3AMANDAOMCalib();

  double GetADC_A0()     {return adc_a0_;}
  double GetADC_Beta()   {return adc_beta_;}

  double GetTDC_Alpha()  {return tdc_alpha_;}
  double GetTDC_Beta()   {return tdc_beta_;}
  double GetTDC_T0()     {return tdc_t0_;}
  int    GetTDC_Pol()    {return tdc_pol_;}

  double GetTOT_Beta()   {return tot_beta_;}
  double GetTOT_TOT0()   {return tot_tot0_;}
  int    GetTOT_Pol()    {return tot_pol_;}

  void SetADC_A0(double a0)       {adc_a0_=a0;}
  void SetADC_Beta(double beta)   {adc_beta_=beta;}

  void SetTDC_Alpha(double alpha) {tdc_alpha_=alpha;}
  void SetTDC_Beta(double beta)   {tdc_beta_=beta;}
  void SetTDC_T0(double t0)       {tdc_t0_=t0;}
  void SetTDC_Pol(int pol)        {tdc_pol_=pol;}

  void SetTOT_Beta(double beta)   {tot_beta_=beta;}
  void SetTOT_TOT0(double tot0)   {tot_tot0_=tot0;}
  void SetTOT_Pol(int pol)        {tot_pol_=pol;}

  double GetOMO_A()       {return omo_a_;}
  double GetOMO_B()       {return omo_b_;}
  double GetOMO_C()       {return omo_c_;}
  double GetOMO_D()       {return omo_d_;}
  double GetOMO_E()       {return omo_e_;}
  double GetOMO_LowLim()  {return omo_lowlim_;}
  double GetOMO_HighLim() {return omo_highlim_;}

  void SetOMO_A(double a)             {omo_a_=a;}
  void SetOMO_B(double b)             {omo_b_=b;}
  void SetOMO_C(double c)             {omo_c_=c;}
  void SetOMO_D(double d)             {omo_d_=d;}
  void SetOMO_E(double e)             {omo_e_=e;}
  void SetOMO_LowLim(double lowlim)   {omo_lowlim_=lowlim;}
  void SetOMO_HighLim(double highlim) {omo_highlim_=highlim;}

  vector<I3AMANDAOMCalib_XTalk> &GetXTalk_Receivers() {return xtalk_receivers_;}

  virtual void ToStream(ostream& o) const
  {
    o<<"[ "
     <<"AMANDACalibration"
     <<"]\n";
  };
  
  virtual string ToString() const
  {
    ostringstream out;
    ToStream(out);
    return out.str();
  };


  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

/**
 * streams an I3AMANDAOMCalib to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o, const I3AMANDAOMCalib& c)
{
    c.ToStream(o); 
    return o;
}

typedef shared_ptr<I3AMANDAOMCalib>  I3AMANDAOMCalibPtr;

#endif

