/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalReadout.h,v 1.1 2004/03/10 15:53:55 pretz Exp $
 *
 * A collection of digital signals.  
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/10 15:53:55 $
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3DIGITALREADOUT_H
#define I3DIGITALREADOUT_H

#include "StoragePolicy.h"
#include "I3DataReadout.h"
#include "I3Waveform.h"

class I3DigitalReadout : public I3DataReadout
{
  I3Waveform fWaveform;
  Double_t fStarttime;
 public:
  /**
   * constructor
   */
  I3DigitalReadout() {fStarttime = 0; }

  /**
   * destructor
   */
  virtual ~I3DigitalReadout(){;}
  
  /** 
   * @return the start time of the series
   */
  Double_t StartTime() const { return fStarttime; }

  /**
   * @param starttime the new start time for the series
   */
  void   StartTime(Double_t starttime) { fStarttime = starttime; }

  const I3Waveform& Waveform() const {return fWaveform;}

  I3Waveform& Waveform() {return fWaveform;}

 private:
  // copy and assignment private
  I3DigitalReadout(const I3DigitalReadout&);
  const I3DigitalReadout& operator=(const I3DigitalReadout&);

  // ROOT macro
  ClassDef(I3DigitalReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalReadout>::ThePolicy I3DigitalReadoutPtr;

#endif

