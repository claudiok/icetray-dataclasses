/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3AnalogSeries.h,v 1.10 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo

*/
#ifndef I3ANALOGSERIES_H
#define I3ANALOGSERIES_H

#include "I3Analog.h"
#include "StoragePolicy.h"

class I3AnalogSeries : public VectorPolicy<I3Analog>::ThePolicy
{ 
  I3AnalogSeries(const I3AnalogSeries &);
  const I3AnalogSeries& operator=(const I3AnalogSeries&);

 public:
  virtual ~I3AnalogSeries() {;}
  ClassDef(I3AnalogSeries,1);
};

#endif

