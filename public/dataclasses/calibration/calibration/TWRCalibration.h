/**
 *
 * @version $Id$
 * @date $Date$
 */

#ifndef TWRCALIBRATION_H_INCLUDED
#define TWRCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"
// Include I3DOMCalibration for LinearFit struct
#include "dataclasses/calibration/I3DOMCalibration.h"

static const unsigned twrxtcal_version_ = 0;

/**
 * @brief This structure contains the TWR-specific Cross talk calibration
 */
struct TWRXTCal
{
  
  /**
   * SPE net charge cut value for each OM (cutoff in units of SPE charge)
   */
  double speNetChargeCut;

  /**
   * slope and intercept for amplitude to net charge cut-off line
   */
  LinearFit chargeVsAmplCut;

  /**
   * cutoff for 1st values of waveform
   *  Optical Channels only!
   */
  double startBinCut;

  /**
   *  cutoff for last values of waveform
   *  Optical Channels only!
   */
  double endBinCut;

  /**
   * cutoff for maximum pulse amplitude
   *  Optical Channels only!
   */
  double amplitudeCut;

  /**
   * cutoff for minimum pulse amplitude
   *  Optical Channels only!
   */
  double invAmplitudeCut;



  TWRXTCal()
  {
    speNetChargeCut  = NAN;
    startBinCut=NAN;
    endBinCut = NAN;
    amplitudeCut = NAN;
    invAmplitudeCut = NAN;
  }
  virtual ~TWRXTCal();
  
  template <class Archive> void serialize(Archive & ar, unsigned version);
};

/**
 * @brief This structure contains the TWR-specific calibration
 * structure.  This has been separated from the mu-daq specific
 *  calibration structures for cleanliness and perhaps someday the mudaq
 *  stuff will be depricated. This class contains the waveform calibration
 *  inforamtion and the cross talk cleaning constants.
 */
static const unsigned twrcalibration_version_ = 0;


struct TWRCalibration
{    
  /**
   * Number of photoelectrons per unit area of waveform
   */
  double peArea;
  
  /**
   * T0 information per channel for timing calibration
   */
  double twrT0;
  
  /**
   * TWRXTCal struct containing Cross talk removal constants.
   */
  TWRXTCal xtcal;
  
  TWRCalibration()
  {
    peArea = NAN;
    twrT0 = NAN;
 
  }
  virtual ~TWRCalibration();
  
  template <class Archive> void serialize(Archive & ar, unsigned version);

};

I3_POINTER_TYPEDEFS(TWRCalibration);



#endif //TWRCALIBRATION_H_INCLUDED

