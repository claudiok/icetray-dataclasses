/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.2 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo

*/

// inlcude one and only one

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

#include "STLVectorStoragePolicy.h"

// something like this would be nice but root wont allow it
template <class Stored>
struct VectorPolicy {
  typedef STLVectorStoragePolicy<Stored> ThePolicy;
  //  typedef TClonesArrayStoragePolicy<Stored> ThePolicy;
};

//#include "TClonesPolicy.h"

#endif
