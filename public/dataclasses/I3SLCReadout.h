/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3SLCReadout.h,v 1.4 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3SLCReadout.h
 * @version $Revision: 1.4 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author pretz
 */
#ifndef I3SLCREADOUT_H
#define I3SLCREADOUT_H

#include "I3AnalogReadout.h"
#include "StoragePolicy.h"

/**
 * @brief An IceCube Single Local Coincidence hit. 
 *
 * Just a time stamp.
 */
class I3SLCReadout : public I3AnalogReadout
{ 
  double fTime;

 public:
  /**
   * constructor
   */
  I3SLCReadout(){}

  /**
   * destructor
   */
  virtual ~I3SLCReadout() {;}

  /**
   * @return the time of the first LE in the readout
   */
  double GetFirstLE() const {return fTime;}

  /**
   * @return the time of the SLC hit
   */
  double GetTime() const{ return fTime;}

  /**
   * @param time the new time for the SLC hit
   */
  void SetTime(double time) {fTime = time;}

 private:
  // copy and assignment private
  I3SLCReadout(const I3SLCReadout &);
  const I3SLCReadout& operator=(const I3SLCReadout&);

  // ROOT macro
  ClassDef(I3SLCReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3SLCReadout>::ThePolicy I3SLCReadoutPtr;
#endif

