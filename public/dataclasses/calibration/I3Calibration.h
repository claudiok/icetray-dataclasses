/**
 *
 * Definition of I3Calibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id$
 * @file I3Calibration.h
 * @date $Date$
 */

#ifndef I3CALIBRATION_H_INCLUDED
#define I3CALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/calibration/I3DOMCalibration.h"
#include "dataclasses/calibration/I3AMANDAOMCalibration.h"
#include "dataclasses/calibration/I3TankCalibration.h"
#include "dataclasses/I3Time.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/TankKey.h"
#include <icetray/I3FrameObject.h>
#include <icetray/I3DefaultName.h>

static const unsigned i3calibration_version_ = 1;

struct I3Calibration : public I3FrameObject
{
public:
  I3Time startTime;
  I3Time endTime;

  I3Calibration() {};
    
  virtual ~I3Calibration();
    
  map<OMKey, I3DOMCalibration> domCal;
  map<OMKey, I3AMANDAOMCalibration> amandaCal;
  map<TankKey, I3TankCalibration> tankCal;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

BOOST_CLASS_VERSION(I3Calibration, i3calibration_version_);
I3_DEFAULT_NAME(I3Calibration);
I3_POINTER_TYPEDEFS(I3Calibration);

#endif // I3CALIBRATION_H_INCLUDED
    

