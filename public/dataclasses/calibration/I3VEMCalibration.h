/**
 *
 * @version $Id: I3VEMCalibration.h$
 * @file I3VEMCalibration.h
 * @date $Date$
 */

#ifndef I3VEMCALIBRATION_H_INCLUDED
#define I3VEMCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"


/**
 * @brief This struct stores the VEM (Vertical Equivalent Muon) calibration
 * data for an IceTop DOM. In addition it contains information concerning the 
 * switching between the high gain (HG) and low gain (LG) DOMs in a Tank. 
 * @author Tilo Waldenmaier  (struct'd by Erik Blaufuss)
 */
static const unsigned i3vemcalibration_version_ = 0;


struct I3VEMCalibration
{    
  /**
   * Average number of PE per VEM  
   */
  double pePerVEM;
  
  /**
   * Width of the the average muon peak for this tank in PE
   */
  double muPeakWidth;
  
  /**
   * PE threshold for the HG pulses over which the 
   *  corresponding LG pulses in the tank are used.
   *  (This value is only valid/important for HG DOMs) 
   */
  double hglgCrossOver;
  
  /**
   * Optional correction factor to adjust high gain and low gain DOMs
   * (Default value is set to 1)
   */
  double corrFactor;
  

  I3VEMCalibration()
  {
    pePerVEM = NAN;
    muPeakWidth = NAN;
    hglgCrossOver = NAN;
    corrFactor = 1.0;
  }
  virtual ~I3VEMCalibration();
  
  template <class Archive> void serialize(Archive & ar, unsigned version);

};


BOOST_CLASS_VERSION(I3VEMCalibration, i3vemcalibration_version_);
I3_POINTER_TYPEDEFS(I3VEMCalibration);

#endif //I3VEMCALIBRATION_H_INCLUDED

