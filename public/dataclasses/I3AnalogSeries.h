/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3AnalogSeries.h,v 1.9 2004/02/21 17:38:10 pretz Exp $

    @version $Revision: 1.9 $
    @date $Date: 2004/02/21 17:38:10 $
    @author

    @todo

*/
#ifndef I3ANALOGSERIES_H
#define I3ANALOGSERIES_H

#include "I3Analog.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3AnalogSeriesHeader { };

typedef StoragePolicy<I3Analog> I3AnalogSeriesStoragePolicy;

class I3AnalogSeries : public AugVec<I3AnalogSeriesHeader, I3Analog, I3AnalogSeriesStoragePolicy>
{
  ClassDef(I3AnalogSeries,1);
};

#endif

