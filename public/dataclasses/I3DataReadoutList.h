#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"

class I3DataReadoutListHeader { };

typedef TClonesPolicy<I3DataReadout> I3DataReadoutListStoragePolicy;

typedef GarnishedVector<I3DataReadoutListHeader, 
			I3DataReadout, 
			I3DataReadoutListStoragePolicy> I3DataReadoutList;


#endif

