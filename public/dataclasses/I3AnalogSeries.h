/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3AnalogSeries.h,v 1.7 2004/02/17 16:54:39 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/17 16:54:39 $
    @author

    @todo

*/
#ifndef I3ANALOGSERIES_H
#define I3ANALOGSERIES_H

#include "I3Analog.h"
#include "StoragePolicy.h"
#include "GarnishedVector.h"

class I3AnalogSeriesHeader { };

typedef StoragePolicy<I3Analog> I3AnalogSeriesStoragePolicy;
typedef GarnishedVector<I3AnalogSeriesHeader, I3Analog, I3AnalogSeriesStoragePolicy> I3AnalogSeries;

#endif

