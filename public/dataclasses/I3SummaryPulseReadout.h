/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3SummaryPulseReadout.h,v 1.2 2004/04/27 13:35:23 pretz Exp $
 *
 * @file I3SummaryPulseReadout.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author pretz
 */
#ifndef I3SUMMARYPULSEREADOUT_H
#define I3SUMMARYPULSEREADOUT_H

#include "I3AnalogReadout.h"
#include "StoragePolicy.h"

/**
 * @brief An IceCube Single Local Coincidence hit.  Just a time stamp.
 *
 */
class I3SummaryPulseReadout : public I3AnalogReadout
{ 
  Double_t fTime;
  Double_t fAmplitude;

 public:
  /**
   * constructor
   */
  I3SummaryPulseReadout(){}

  /**
   * destructor
   */
  virtual ~I3SummaryPulseReadout() {;}

  /**
   * @return the time of the first LE in the readout
   */
  Double_t FirstLE() const {return fTime;}

  /**
   * @return the time of the signal
   */
  Double_t Time() const{ return fTime;}

  /**
   * @param time the new time for the signal
   */
  void Time(Double_t time) {fTime = time;}

  /**
   * @return the amplitude of the signal
   */
  Double_t Amplitude() {return fAmplitude;}

  /**
   * @param amp the new amplitude for the signal
   */
  void Amplitude(Double_t amp){fAmplitude = amp;}

 private:
  // copy and assignment private
  I3SummaryPulseReadout(const I3SummaryPulseReadout &);
  const I3SummaryPulseReadout& operator=(const I3SummaryPulseReadout&);

  // ROOT macro
  ClassDef(I3SummaryPulseReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3SummaryPulseReadout>::ThePolicy I3SummaryPulseReadoutPtr;
#endif

