/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3AnalogSeries.h,v 1.11 2004/02/22 14:26:36 pretz Exp $

    @version $Revision: 1.11 $
    @date $Date: 2004/02/22 14:26:36 $
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
  I3AnalogSeries(){}
  virtual ~I3AnalogSeries() {;}
  ClassDef(I3AnalogSeries,1);
};

#endif

