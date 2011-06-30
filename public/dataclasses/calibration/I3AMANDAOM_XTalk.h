/**
 *
 * Based of the sieglinde class SLCalibrateDBAmacalib
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id: I3AMANDAOMCalibration.h 7421 2005-05-09 03:41:09Z aya $
 * @file I3AMANDAOMCalibration.h
 * @date $Date: 2005-05-08 23:41:09 -0400 (Sun, 08 May 2005) $
 */

#ifndef I3AMANDAOMCALIBRATION_XTALK_H_INCLUDED
#define I3AMANDAOMCALIBRATION_XTALK_H_INCLUDED

#include <sstream>
#include "icetray/OMKey.h"

static const unsigned i3amandaom_xtalk_version_ = 0;

struct I3AMANDAOM_XTalk 
{
  OMKey  receiver;
  double timehigh;
  double timelow;
  double width;
  double threshold;
  

  I3AMANDAOM_XTalk() {timehigh=NAN; timelow=NAN; width=NAN;}
  virtual ~I3AMANDAOM_XTalk();

  template <class Archive> 
  void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3AMANDAOM_XTalk);
BOOST_CLASS_VERSION(I3AMANDAOM_XTalk, i3amandaom_xtalk_version_);

#endif //I3AMANDAOMCALIB_XTALK_H_INCLUDED

