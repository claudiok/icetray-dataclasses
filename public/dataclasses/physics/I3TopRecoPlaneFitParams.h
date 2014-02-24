/**
 * Copyright (C) 2006
 * The IceCube collaboration
 * ID: $Id: I3TopRecoPlaneFitParams.h 67045 2010-09-27 12:04:00Z kislat $
 *
 * @file I3TopRecoPlaneFitParams.h
 * @version $Rev: 28258 $
 * @date $Date: 2010-09-27 08:04:00 -0400 (Mon, 27 Sep 2010) $
 * @author $Author: schlenst $
 */

#ifndef __I3TOPRECOPLANEFITPARAMS_H_
#define __I3TOPRECOPLANEFITPARAMS_H_

#include <icetray/I3FrameObject.h>
#include "dataclasses/Utility.h"

static const unsigned i3toprecoplanefitparams_version_ = 1;

/**
 * @brief This is a representation of the shower front by a
 * plane. Intention is to use it as a first guess. Adds a chi2 and a
 * t0 to the fit.
 */
class I3TopRecoPlaneFitParams : public I3FrameObject
{

  public:

  /**
   * The event time in secs since year began
   */
  int64_t ET;

  /**
   * The time which passed since the last event
   */
  double DeltaT;

  /**
   * the t0 of the track
   */
  float T0;
  
  /**
   * the x0 of the track
   */
  float X0;
  
  /**
   * the y0 of the track
   */
  float Y0;
  
  /**
   * The chi2
   */
  float Chi2;

  /**
   * The number of pulses used in this fit
   */
  unsigned int NPulses;


  I3TopRecoPlaneFitParams() :
    ET(-1),
    DeltaT(NAN),
    T0(NAN),
    X0(NAN),
    Y0(NAN),
    Chi2(NAN),
    NPulses(0)
    {};

  virtual ~I3TopRecoPlaneFitParams() {};

 private:

  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive& ar, unsigned version);

};
       
BOOST_CLASS_VERSION(I3TopRecoPlaneFitParams, i3toprecoplanefitparams_version_);       

/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
I3_POINTER_TYPEDEFS(I3TopRecoPlaneFitParams);

#endif
