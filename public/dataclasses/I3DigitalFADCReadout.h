#ifndef I3DIGITALFADCREADOUT_H
#define I3DIGITLAFADCREADOUT_H

#include "I3DigitalReadout.h"

class I3DigitalFADCReadout : public I3DigitalReadout{
 public:
  I3DigitalFADCReadout(){}
  virtual ~I3DigitalFADCReadout(){}
 private:
  I3DigitalFADCReadout(const I3DigitalFADCReadout&);
  const I3DigitalFADCReadout& operator=(const I3DigitalFADCReadout&);
  ClassDef(I3DigitalFADCReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalFADCReadout>::ThePolicy I3DigitalFADCReadoutPtr;
#endif

