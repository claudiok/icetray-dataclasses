#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3DataReadoutListHeader { };

typedef StoragePolicy<I3DataReadout> I3DataReadoutListStoragePolicy;

typedef AugVec<I3DataReadoutListHeader, 
			I3DataReadout, 
			I3DataReadoutListStoragePolicy> I3DataReadoutList;


#endif

