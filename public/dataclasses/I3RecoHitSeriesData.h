#ifndef I3RECOHITSERIESDATA_H
#define I3RECOHITSERIESDATA_H

#include "I3RecoHitSeries.h"

class I3RecoHitSeriesDataHeader { };

typedef StoragePolicy<I3RecoHitSeries> I3RecoHitSeriesDataStoragePolicy;

typedef GarnishedVector<I3RecoHitSeriesDataHeader, 
			I3RecoHitSeries, 
			I3RecoHitSeriesDataStoragePolicy> I3RecoHitSeriesData;



#endif

