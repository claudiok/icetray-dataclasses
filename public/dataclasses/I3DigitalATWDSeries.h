/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalATWDSeries.h,v 1.7 2004/02/25 20:10:24 pretz Exp $
 *
 * Adds the ATWD gain to the standard I3DigitalSeries
 *
 * @version $Revision: 1.7 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo Is the 'gain' a static thing that can be put into Monitoring??
 *
 */
#ifndef I3DIGITALATWDSERIES_H
#define I3DIGITALATWDSERIES_H

#include "I3DigitalSeries.h"

class I3DigitalATWDSeries : public I3DigitalSeries
{
  Float_t  fGain;

  public:
  /**
   * constructor
   */
  I3DigitalATWDSeries() : I3DigitalSeries() { fGain=0; }

  /**
   * @return the gain of this ATWD for this series
   */
  Float_t Gain() const { return fGain; }

  /**
   * @param gain the new gain setting
   */
  void Gain(Float_t  gain) { fGain=gain; }

 private:
  // copy and assignment private
  I3DigitalATWDSeries(const I3DigitalATWDSeries& rhs);
  const I3DigitalATWDSeries& operator=(const I3DigitalATWDSeries& rhs);
  
  // ROOT Macro
  ClassDef(I3DigitalATWDSeries,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalATWDSeries>::ThePolicy I3DigitalATWDSeriesPtr;

#endif

