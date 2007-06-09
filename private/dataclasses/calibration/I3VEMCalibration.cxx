/**
 *
 * @version $Id: I3VEMCalibration.cxx$
 * @file I3VEMCalibration.cxx
 * @date $Date: 2007-04-11 15:35:43 -0400 (Mi, 11 Apr 2007) $
 */


#include <icetray/serialization.h>
#include "dataclasses/calibration/I3VEMCalibration.h"


I3VEMCalibration::I3VEMCalibration():
    pePerVEM_(NAN), 
    muPeakWidth_(NAN),
    hglgCrossOver_(NAN),
    corrFactor_(1.0)
{}

I3VEMCalibration::~I3VEMCalibration() {}

template <class Archive>
void I3VEMCalibration::serialize(Archive& ar, unsigned version)
{
    ar & make_nvp("pePerVEM",      pePerVEM_);
    ar & make_nvp("muPeakWidth",   muPeakWidth_);
    ar & make_nvp("hglgCrossOver", hglgCrossOver_);
    ar & make_nvp("corrFactor",    corrFactor_);
}

I3_SERIALIZABLE(I3VEMCalibration);

