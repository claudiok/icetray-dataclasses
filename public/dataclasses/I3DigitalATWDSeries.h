/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DigitalATWDSeries.h,v 1.4 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/02/20 21:42:08 $
    @author

    @todo

*/
#ifndef I3DIGITALATWDSERIES_H
#define I3DIGITALATWDSERIES_H

#include "I3DigitalSeries.h"

class I3DigitalATWDSeriesHeader : public I3DigitalSeriesHeader
{
  Float_t  gain;

  public:

  I3DigitalATWDSeriesHeader() : I3DigitalSeriesHeader() { gain=0; }

  Float_t Gain() const { return gain; }
  void Gain(Float_t  gain_) { gain=gain_; }

};

typedef StoragePolicy<I3Digital> I3DigitalSeriesStoragePolicy;

typedef AugVec<I3DigitalATWDSeriesHeader, 
			I3Digital, 
			I3DigitalSeriesStoragePolicy> I3DigitalATWDSeries;

#endif

