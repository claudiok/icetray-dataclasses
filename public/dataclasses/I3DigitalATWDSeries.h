/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DigitalATWDSeries.h,v 1.5 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo
n
*/
#ifndef I3DIGITALATWDSERIES_H
#define I3DIGITALATWDSERIES_H

#include "I3DigitalSeries.h"

class I3DigitalATWDSeries : public I3DigitalSeries
{
  Float_t  gain;

  public:

  I3DigitalATWDSeries() : I3DigitalSeries() { gain=0; }

  Float_t Gain() const { return gain; }
  void Gain(Float_t  gain_) { gain=gain_; }

};

#endif

