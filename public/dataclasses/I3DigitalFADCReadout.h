/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalFADCReadout.h,v 1.4 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3DigitalFADCReadout.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3DIGITALFADCREADOUT_H
#define I3DIGITLAFADCREADOUT_H

#include "I3DigitalReadout.h"

/**
 * @brief A class to represent the FADC readout of a particular om.
 *
 * @todo Right now, theres no implementation beyond that of I3DigitalReadout
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

