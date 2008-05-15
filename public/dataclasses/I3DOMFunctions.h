/**
 * copyright  (C) 2006
 * the icecube collaboration
 * @version $Id:  $
 * @file I3DOMFunctions.h
 * @date $Date: $
 */
#ifndef I3DOMFUNCTIONS_H_INCLUDED
#define I3DOMFUNCTIONS_H_INCLUDED

//includes
#include "dataclasses/status/I3DOMStatus.h"
#include "dataclasses/calibration/I3DOMCalibration.h"
#include <vector>

/** 
 * @brief  A class containing a collection of functions that 
 *  use dom status/calibration information to return "calculated"
 *  status items (Gain, SPEMean, etc)
 *
 * expandible in the future, as needed
 */

/**
 * Return the ATWD sampling rate for chip 0 or 1
 */
double ATWDSamplingRate (unsigned int chip, const I3DOMStatus& , const I3DOMCalibration&);

/**
 * Return the calculated PMT gain
 */
double PMTGain (const I3DOMStatus& , const I3DOMCalibration&);

/**
 * Return the calculated SPEMean
 */
double SPEMean (const I3DOMStatus& , const I3DOMCalibration&);

/**
 * Get the FADC baseline (in counts)
 */
double FADCBaseline (const I3DOMStatus& , const I3DOMCalibration&);

/**
 * Get the total transit time (PMT transit time + delay)
 */
double TransitTime (const I3DOMStatus&, const I3DOMCalibration&);

/**
 * Get the calibrated SPE Discrimiator threshold (pC)
 */
double SPEDiscriminatorThreshold (const I3DOMStatus&, const I3DOMCalibration&);

/**
 * Get the calibrated MPE Discrimiator threshold (pC)
 */
double MPEDiscriminatorThreshold (const I3DOMStatus&, const I3DOMCalibration&);



/**
 * Given a string which contains the DOMCal version (e.g. "6.1.0"), return a vector<int>
 * which contains the numbers as its elements (i.e. what's between the separating "."s)
 */
vector<int> DOMCalVersion (const I3DOMCalibration&);

#endif //I3DOMFUNCTIONS_H_INCLUDED
