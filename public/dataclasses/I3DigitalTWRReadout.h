/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalTWRReadout.h,v 1.4 2004/07/15 20:29:25 deyoung Exp $
 *
 * @file I3DigitalTWRReadout.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/07/15 20:29:25 $
 * @author pretz
 *
 */
#ifndef I3DIGITALTWRREADOUT_H
#define I3DIGITALTWRREADOUT_H

#include "dataclasses/I3DigitalReadout.h"
/**
 * @brief Implementation of the AMANDA TWR response
 * @todo This class isn't implemented yet.  It's just holding the place
 */
class I3DigitalTWRReadout : public I3DigitalReadout{
 public:
  /**
   * constructor ... for when there's something to construct
   */ 
  I3DigitalTWRReadout(){}

  /**
   * destructor
   */
  virtual ~I3DigitalTWRReadout(){}
 private:
  // copy and assignment declared private
  I3DigitalTWRReadout(const I3DigitalTWRReadout&);
  const I3DigitalTWRReadout& operator=(const I3DigitalTWRReadout&);

  //ROOT macro
  ClassDef(I3DigitalTWRReadout,1);
};


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalTWRReadout>::ThePolicy I3DigitalTWRReadoutPtr;

#endif

