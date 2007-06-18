/**
 *
 * @version $Id: I3VEMCalibration.cxx$
 * @file I3VEMCalibration.cxx
 * @date $Date: 2007-04-11 15:35:43 -0400 (Mi, 11 Apr 2007) $
 */


#include <icetray/serialization.h>
#include "dataclasses/calibration/I3VEMCalibration.h"

I3VEMCalibration::~I3VEMCalibration() {}

template <class Archive>
void I3VEMCalibration::serialize(Archive& ar, unsigned version)
{
  if (version>i3vemcalibration_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3VEMCalibration class.",version,i3vemcalibration_version_);

    ar & make_nvp("pePerVEM",      pePerVEM);
    ar & make_nvp("muPeakWidth",   muPeakWidth);
    ar & make_nvp("hglgCrossOver", hglgCrossOver);
    ar & make_nvp("corrFactor",    corrFactor);
}

I3_SERIALIZABLE(I3VEMCalibration);

