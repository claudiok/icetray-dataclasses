/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.4 2004/02/23 22:36:49 troy Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/02/23 22:36:49 $
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
  typedef SmartPtr<Pointed> ThePolicy;

  // to not use smart pointers:
  // this is probably not something you ever want to do 
  // because the app will leak memory like a stuck pig

  // typedef Pointed* ThePolicy;
};

#endif
