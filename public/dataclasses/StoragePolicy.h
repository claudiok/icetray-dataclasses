/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.3 2004/02/23 02:13:50 troy Exp $

    @version $Revision: 1.3 $
    @date $Date: 2004/02/23 02:13:50 $
    @author

    @todo

*/

// inlcude one and only one

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "STLVectorStoragePolicy.h"
#include "STLMapStoragePolicy.h"

#include "TClonesPolicy.h"

// something like this would be nice but root wont allow it
template <class Stored>
struct VectorPolicy {
  typedef STLVectorStoragePolicy<Stored> ThePolicy;
  //  typedef TClonesArrayStoragePolicy<Stored> ThePolicy;
};

template <class Stored>
struct MapPolicy {
  typedef STLMapStoragePolicy<Stored> ThePolicy;
  //  typedef TClonesArrayStoragePolicy<Stored> ThePolicy;
};


#endif
