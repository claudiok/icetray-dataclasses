/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DigitalATWDSeries.h,v 1.2 2004/02/16 00:05:21 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/16 00:05:21 $
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

typedef TClonesPolicy<I3Digital> I3DigitalSeriesStoragePolicy;

typedef GarnishedVector<I3DigitalATWDSeriesHeader, 
			I3Digital, 
			I3DigitalSeriesStoragePolicy> I3DigitalATWDSeries;

#endif

