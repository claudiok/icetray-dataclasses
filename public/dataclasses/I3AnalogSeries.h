/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3AnalogSeries.h,v 1.8 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.8 $
    @date $Date: 2004/02/20 21:42:08 $
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
typedef AugVec<I3AnalogSeriesHeader, I3Analog, I3AnalogSeriesStoragePolicy> I3AnalogSeries;

#endif

