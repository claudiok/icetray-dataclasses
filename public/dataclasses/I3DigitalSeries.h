/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DigitalSeries.h,v 1.10 2004/02/21 17:38:10 pretz Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/21 17:38:10 $
    @author

    @todo

*/
#ifndef I3DIGITALSERIES_H
#define I3DIGITALSERIES_H

#include "I3Digital.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3DigitalSeriesHeader 
{
  Double_t    fStarttime;
  
 public:
  I3DigitalSeriesHeader() {fStarttime = 0; }
  ~I3DigitalSeriesHeader(){};
  
  double StartTime() const { return fStarttime; }
  void   StartTime(double starttime_) { fStarttime = starttime_; }
};

typedef StoragePolicy<I3Digital> I3DigitalSeriesStoragePolicy;

class I3DigitalSeries : public AugVec<I3DigitalSeriesHeader, I3Digital, I3DigitalSeriesStoragePolicy>
{
  ClassDef(I3DigitalSeries,1);
};

#endif

