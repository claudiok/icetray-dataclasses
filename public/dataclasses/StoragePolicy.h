/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.5 2004/02/24 02:48:43 troy Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/24 02:48:43 $
    @author

    @todo

*/

// inlcude one and only one

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "STLVectorStoragePolicy.h"
#include "STLMapStoragePolicy.h"

//#include "TClonesPolicy.h"
#include "SmartPtr.h"

// something like this would be nice but root wont allow it
template <class Stored>
struct VectorPolicy {
  typedef STLVectorStoragePolicy<Stored> ThePolicy;
  // half-implemented
  // typedef TClonesArrayStoragePolicy<Stored> ThePolicy;
};

template <class Stored>
struct MapPolicy {
  typedef STLMapStoragePolicy<Stored> ThePolicy;
  // not yet implemented
  // typedef TMapStoragePolicy<Stored> ThePolicy;
};

template <class Pointed>
struct PtrPolicy {
  //  typedef SmartPtr<Pointed> ThePolicy;

  // to not use smart pointers: currently this results in a bad memory
  // leak.  We will have smart pointers working shortly, they have
  // been tested and work, but not in this build at the moment

  typedef Pointed* ThePolicy;
};

#endif
