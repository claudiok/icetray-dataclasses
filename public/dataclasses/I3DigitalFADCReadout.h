#ifndef I3DIGITALFADCREADOUT_H
#define I3DIGITLAFADCREADOUT_H

#include "I3DigitalReadout.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalFADCReadout.h,v 1.3 2004/03/13 19:51:20 pretz Exp $
 *
 * A class to represent the FADC readout of a particular om.
 *
 * @version $Revision: 1.3 $
 * @date $Date: 2004/03/13 19:51:20 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo Right now, theres no implementation beyond that of I3DigitalReadout
 *
 */
class I3DigitalFADCReadout : public I3DigitalReadout{
 public:
  /**
   * constructor
   */
  I3DigitalFADCReadout(){}

  /**
   * destructor
   */
  virtual ~I3DigitalFADCReadout(){}
 private:
  // copy and assignment private
  I3DigitalFADCReadout(const I3DigitalFADCReadout&);
  const I3DigitalFADCReadout& operator=(const I3DigitalFADCReadout&);

  //ROOT macro
  ClassDef(I3DigitalFADCReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalFADCReadout>::ThePolicy I3DigitalFADCReadoutPtr;
#endif

