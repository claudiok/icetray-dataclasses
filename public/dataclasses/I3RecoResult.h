/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResult.h,v 1.12 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.12 $
    @date $Date: 2004/02/20 21:42:08 $
    @author

    @todo get/set best stuff

*/
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include "I3RecoTrackList.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3RecoResultHeader { };

typedef StoragePolicy<I3RecoTrackList> I3RecoResultStoragePolicy;
typedef AugVec<I3RecoResultHeader, I3RecoTrackList, I3RecoResultStoragePolicy> I3RecoResult;

#endif
