#ifndef I3SLCREADOUT_H
#define I3SLCREADOUT_H

#include "I3AnalogReadout.h"
#include "StoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3SLCReadout.h,v 1.1 2004/03/10 02:42:24 pretz Exp $
 *
 * An IceCube Single Local Coincidence hit.  Just a time stamp.
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/10 02:42:24 $
 * @author pretz
 *
 *  @todo
 *
 */
class I3SLCReadout : public I3AnalogReadout
{ 
  Double_t fTime;

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
  Double_t FirstLE() const {return fTime;}

  /**
   * @return the time of the SLC hit
   */
  Double_t Time() const{ return fTime;}

  /**
   * @param time the new time for the SLC hit
   */
  void Time(Double_t time) {fTime = time;}

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

