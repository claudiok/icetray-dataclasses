#ifndef I3DIGITALTWRREADOUT_H
#define I3DIGITALTWRREADOUT_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalTWRReadout.h,v 1.1 2004/03/10 15:53:56 pretz Exp $
 *
 * Just a placeholder class for a different kind of response
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/10 15:53:56 $
 * @author pretz
 *
 * @todo implement this class
 */
#include "dataclasses/I3DigitalReadout.h"

class I3DigitalTWRReadout : public I3DigitalReadout{
 public:
  I3DigitalTWRReadout(){}
  virtual ~I3DigitalTWRReadout(){}
 private:
  I3DigitalTWRReadout(const I3DigitalTWRReadout&);
  const I3DigitalTWRReadout& operator=(const I3DigitalTWRReadout&);

};


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalTWRReadout>::ThePolicy I3DigitalTWRReadoutPtr;

#endif

