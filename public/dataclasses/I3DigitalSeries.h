/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DigitalSeries.h,v 1.11 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.11 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo

*/
#ifndef I3DIGITALSERIES_H
#define I3DIGITALSERIES_H

#include "I3Digital.h"
#include "StoragePolicy.h"

class I3DigitalSeries : VectorPolicy<I3Digital>::ThePolicy
{
  Double_t    fStarttime;
  
  I3DigitalSeries(const I3DigitalSeries&);
  const I3DigitalSeries& operator=(const I3DigitalSeries&);

 public:
  I3DigitalSeries() {fStarttime = 0; }
  virtual ~I3DigitalSeries(){;}
  
  double StartTime() const { return fStarttime; }
  void   StartTime(double starttime_) { fStarttime = starttime_; }

  ClassDef(I3DigitalSeries,1);
};

#endif

