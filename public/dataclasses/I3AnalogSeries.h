/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3AnalogSeries.h,v 1.6 2004/02/15 19:27:04 troy Exp $

    @version $Revision: 1.6 $
    @date $Date: 2004/02/15 19:27:04 $
    @author

    @todo

*/
#ifndef I3ANALOGSERIES_H
#define I3ANALOGSERIES_H

#include "I3Analog.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"

class I3AnalogSeriesHeader { };

typedef TClonesPolicy<I3Analog> I3AnalogSeriesStoragePolicy;
typedef GarnishedVector<I3AnalogSeriesHeader, I3Analog, I3AnalogSeriesStoragePolicy> I3AnalogSeries;

#endif

