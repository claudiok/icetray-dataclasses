/**
 * Copyright (C) 2006
 * The IceCube collaboration
 * ID: $Id: I3TopLateralFitParams.h 87697 2012-04-26 18:47:12Z kath $
 *
 * @file I3TopLateralFitParams.h
 * @version $Rev: 28706 $
 * @date $Date: 2012-04-26 14:47:12 -0400 (Thu, 26 Apr 2012) $
 * @author $Author: kislat $
 */

#ifndef __I3TOPLATERALFITPARAMS_H_
#define __I3TOPLATERALFITPARAMS_H_ 3

#include <icetray/I3FrameObject.h>
#include <dataclasses/Utility.h>

static const unsigned i3toplateralfitparams_version_ = 4;

/**
 * @brief This is a representation of the lateral fit made with a shower 
 */
class I3TopLateralFitParams : public I3FrameObject
{

  public:

  /**
   * The error on the core X.
   */
  double Xc_err;

  /**
   * The error on the core Y.
   */
  double Yc_err;
 
  /**
   * Pulse height in 125m distance from the core (Fit parameter: log10(S125)).
   */
  double S125;

  /**
   * Error of that.
   */
  double Log10_S125_err;

  /**
   * Pulse height in 50m distance from the core.
   */
  double S50;

  /**
   * Pulse height in 70m and 80m distance from the core.
   */
  double S70;
  double S80;

  /**
   * Pulse height in 100m distance from the core.
   */
  double S100;

  /**
   * Pulse height in 150m distance from the core.
   */
  double S150;

  /**
   * Pulse height in 180m distance from the core.
   */
  double S180;

  /**
   * Pulse height in 250m distance from the core.
   */
  double S250;

  /**
   * Pulse height in 500m distance from the core.
   */
  double S500;

  /**
   * The integral over the lateral distribution function.
   */
  double Sint;

  /**
   * Error of that.
   */
  double Sint_err;

  /**
   * Energy as determined by S_100, S_125, S180.
   */
  double E_50;
  double E_100;
  double E_125;
  double E_180;
  double E_500;

  /**
   * First Guess Energy as determined by SAF report formula.
   */

  double E_firstguess;

  /**
   * Energy for proton and iron assumption as determined by Bakhtiyar Ruzybayez (TODO: add ref.).
   */
  double E_proton;
  double E_iron;


  /**
   * The slope parameter of the lateral fit.
   */
  double Beta;

  /**
   * Error of that.
   */
  double Beta_err;

  /**
   * The age parameter of the shower. In case of DLP function,
   * this is converted as shown in the SAF report (s. Internal
   * Report Repository).
   */
  double Age;

  /**
   * Error of direction (from combined fit).
   */
  double Dir_err;

  /**
   * The Log-Likelihood of the fit, divided by the degrees of freedom.
   */
  double Llh;
  double Llh_silent;

  /**
   * The Chi square, divided by the degrees of freedom.
   */
  double Chi2;

  /**
   * The Chi square, divided by the degrees of freedom, for the timing fit.
   */
  double Chi2_time;

  /**
   * The number of degrees of freedom (after all cuts).
   */
  int Ndf;

  /**
   * Other gulliverish stuff!
   * Reduced log-likelihood, and number of minimizations
   */
  double RLogL;
  int NMini;

  /**
   * Sum of all VEM in all available Tanks.
   */
  double SumVEM;

  /**
   * Core radius of the closest used pulse
   */
  double Rmin;


  /**
   * Core radius of most distant used pulse
   */
  double Rmax;


  /**
   * Radius used in energy extraction.
   */
  double Rtrans;

  /**
   * Loudest Station in this event.
   */
  int LoudestStation;


  /**
   * Best-fit (or user-parameter) snow correction factor,
   * and its error
   */
   double SnowFactor;
   double SnowFactor_err;

  /**
   * The correlations of the fit variables. It is taken from the Minuit Error
   * Matrix Corr_1_2 = ErrMat[1][2] / Err1 / Err2
   */

  double Corr_Xc_Yc;
  double Corr_Xc_Log10_S125;
  double Corr_Xc_Beta;
  double Corr_Yc_Log10_S125;
  double Corr_Yc_Beta;
  double Corr_Log10_S125_Beta;

  I3TopLateralFitParams() :
    Xc_err(NAN),
    Yc_err(NAN),
    S125(NAN),
    Log10_S125_err(NAN),
    S50(NAN),
    S70(NAN),
    S80(NAN),
    S100(NAN),
    S150(NAN),
    S180(NAN),
    S250(NAN),
    S500(NAN),
    Sint(NAN),
    E_50(NAN),
    E_100(NAN),
    E_125(NAN),
    E_180(NAN),
    E_500(NAN),
    E_proton(NAN),
    E_iron(NAN),
    Beta(NAN),
    Beta_err(NAN),
    Dir_err(NAN),
    Llh(NAN),
    Llh_silent(NAN),
    Chi2(NAN),
    Chi2_time(NAN),
    Ndf(0),
    RLogL(NAN),
    NMini(0),
    SumVEM(NAN),
    Rmax(NAN),
    Rtrans(NAN),
    LoudestStation(-1),
    SnowFactor(NAN),
    SnowFactor_err(NAN),
    Corr_Xc_Yc(NAN),
    Corr_Xc_Log10_S125(NAN),
    Corr_Xc_Beta(NAN),
    Corr_Yc_Log10_S125(NAN),
    Corr_Yc_Beta(NAN),
    Corr_Log10_S125_Beta(NAN)
    {};

  virtual ~I3TopLateralFitParams() {};

 private:

  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive& ar, unsigned version);

};

BOOST_CLASS_VERSION(I3TopLateralFitParams, i3toplateralfitparams_version_);       

/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
I3_POINTER_TYPEDEFS(I3TopLateralFitParams);

#endif
