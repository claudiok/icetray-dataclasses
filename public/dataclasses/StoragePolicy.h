/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: StoragePolicy.h,v 1.1 2004/02/17 16:54:39 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/17 16:54:39 $
    @author

    @todo

*/

// inlcude one and only one

#ifndef STORAGEPOLICY_H
#define STORAGEPOLICY_H

// TDS:  something like this would be nice but rootcint wont take it
//template <class Stored>
//struct GlobalPolicy {
//  typedef TClonesPolicy<Stored> ThePolicy;
//}
//typedef GlobalPolicy<I3RecoHit>::ThePolicy I3RecoHitSeriesStoragePolicy;


#include "STLVectorPolicy.h"
//#include "TClonesPolicy.h"

#endif
