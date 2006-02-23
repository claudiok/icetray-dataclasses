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



#endif //I3DOMFUNCTIONS_H_INCLUDED
