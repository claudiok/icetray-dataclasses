/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3SummaryPulseReadout.h,v 1.4 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3SummaryPulseReadout.h
 * @version $Revision: 1.4 $
 * @date $Date: 2005/04/04 15:49:25 $
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
  double fTime;
  double fAmplitude;

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
  double GetFirstLE() const {return fTime;}

  /**
   * @return the time of the signal
   */
  double GetTime() const{ return fTime;}

  /**
   * @param time the new time for the signal
   */
  void SetTime(double time) {fTime = time;}

  /**
   * @return the amplitude of the signal
   */
  double GetAmplitude() {return fAmplitude;}

  /**
   * @param amp the new amplitude for the signal
   */
  void SetAmplitude(double amp){fAmplitude = amp;}

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

