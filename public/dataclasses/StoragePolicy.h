/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.6 2004/03/01 20:19:49 pretz Exp $

    @version $Revision: 1.6 $
    @date $Date: 2004/03/01 20:19:49 $
    @author

    @todo

*/

// inlcude one and only one

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "STLVectorStoragePolicy.h"
#include "STLMapStoragePolicy.h"
#include "STLVecPointainerPolicy.h"
#include "STLMapPointainerPolicy.h"

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
struct VecPointainerPolicy{
  typedef STLVecPointainerPolicy<Stored> ThePolicy;
};

template <class Stored>
struct MapPolicy {
  typedef STLMapStoragePolicy<Stored> ThePolicy;
  // not yet implemented
  // typedef TMapStoragePolicy<Stored> ThePolicy;
};

template <class Stored>
struct MapPointainerPolicy{
  typedef STLMapPointainerPolicy<Stored> ThePolicy;
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
