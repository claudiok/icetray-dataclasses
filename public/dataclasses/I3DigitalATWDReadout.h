/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalATWDReadout.h,v 1.3 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3DigitalATWDReadout.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3DIGITALATWDREADOUT_H
#define I3DIGITALATWDREADOUT_H

#include "I3DigitalReadout.h"

/**
 * @brief Adds the ATWD gain to the standard I3DigitalReadout
 *
 */
class I3DigitalATWDReadout : public I3DigitalReadout
{
 public:
  enum GainSetting{ Unspecified, VeryLow, Low, High, VeryHigh};

 private:
  GainSetting fGain;
  public:
  /**
   * constructor
   */
  I3DigitalATWDReadout() { fGain=Unspecified; }

  /**
   * @return the gain of this ATWD for this series
   */
  GainSetting Gain() const { return fGain; }

  /**
   * @param gain the new gain setting
   */
  void Gain(GainSetting  gain) { fGain=gain; }

 private:
  // copy and assignment private
  I3DigitalATWDReadout(const I3DigitalATWDReadout& rhs);
  const I3DigitalATWDReadout& operator=(const I3DigitalATWDReadout& rhs);
  
  // ROOT Macro
  ClassDef(I3DigitalATWDReadout,1);
};


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalATWDReadout>::ThePolicy I3DigitalATWDReadoutPtr;

#endif

