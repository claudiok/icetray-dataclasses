/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AnalogSeries.h,v 1.15 2004/03/10 02:42:24 pretz Exp $
 *
 * A series of analog pulses in the detector.  Just a container
 * for I3Analog's
 *
 * @version $Revision: 1.15 $
 * @date $Date: 2004/03/10 02:42:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 *  @todo
 *
 */
#ifndef I3ANALOGSERIES_H
#define I3ANALOGSERIES_H

#include "I3AnalogPulse.h"
#include "I3DataReadout.h"
#include "StoragePolicy.h"

class I3AnalogSeries : public I3DataReadout, public VectorPolicy<I3AnalogPulse>::ThePolicy
{ 
 public:
  /**
   * constructor
   */
  I3AnalogSeries(){}

  /**
   * destructor
   */
  virtual ~I3AnalogSeries() {;}

 private:
  // copy and assignment private
  I3AnalogSeries(const I3AnalogSeries &);
  const I3AnalogSeries& operator=(const I3AnalogSeries&);

  // ROOT macro
  ClassDef(I3AnalogSeries,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3AnalogSeries>::ThePolicy I3AnalogSeriesPtr;
#endif

