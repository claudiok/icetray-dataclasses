/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DigitalSeries.h,v 1.7 2004/02/17 16:54:39 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/17 16:54:39 $
    @author

    @todo

*/
#ifndef I3DIGITALSERIES_H
#define I3DIGITALSERIES_H

#include "I3Digital.h"
#include "StoragePolicy.h"
#include "GarnishedVector.h"

class I3DigitalSeriesHeader 
{
  Double_t    fStarttime;
  
 public:
  I3DigitalSeriesHeader() {fStarttime = 0; }
  ~I3DigitalSeriesHeader();
  
  double StartTime() const { return fStarttime; }
  void   StartTime(double starttime_) { fStarttime = starttime_; }
};

typedef StoragePolicy<I3Digital> I3DigitalSeriesStoragePolicy;

typedef GarnishedVector<I3DigitalSeriesHeader, 
			I3Digital, 
			I3DigitalSeriesStoragePolicy> I3DigitalSeries;

#endif

