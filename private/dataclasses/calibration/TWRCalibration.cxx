/**
 *
 * @version $Id: TWRCalibration.cxx$
 * @date $Date: 2007-04-11 15:35:43 -0400 (Mi, 11 Apr 2007) $
 */


#include <icetray/serialization.h>
#include "dataclasses/calibration/TWRCalibration.h"

TWRCalibration::~TWRCalibration() {}

template <class Archive>
void TWRCalibration::serialize(Archive& ar, unsigned version)
{
  if (version>twrcalibration_version_)
    log_fatal("Attempting to read version %u from file but running version %u of TWRCalibration class.",version,twrcalibration_version_);

    ar & make_nvp("peArea", peArea);
    ar & make_nvp("twrT0",  twrT0);
    ar & make_nvp("XTcal",  xtcal);
}

I3_SERIALIZABLE(TWRCalibration);

TWRXTCal::~TWRXTCal() {}

template <class Archive>
void TWRXTCal::serialize(Archive& ar, unsigned version)
{
  if (version>twrxtcal_version_)
    log_fatal("Attempting to read version %u from file but running version %u of TWRXTCal class.",version,twrxtcal_version_);

    ar & make_nvp("speNetChargeCut", speNetChargeCut);
    ar & make_nvp("chargeVsAmplCut", chargeVsAmplCut);
    ar & make_nvp("startBinCut", startBinCut);
    ar & make_nvp("endBinCut", endBinCut);
    ar & make_nvp("amplitudeCut", amplitudeCut);
    ar & make_nvp("invAmplitudeCut", invAmplitudeCut);
}

I3_SERIALIZABLE(TWRXTCal);
