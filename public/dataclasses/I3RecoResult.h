/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResult.h,v 1.11 2004/02/17 16:54:39 troy Exp $

    @version $Revision: 1.11 $
    @date $Date: 2004/02/17 16:54:39 $
    @author

    @todo get/set best stuff

*/
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include "I3RecoTrackList.h"
#include "StoragePolicy.h"
#include "GarnishedVector.h"

class I3RecoResultHeader { };

typedef StoragePolicy<I3RecoTrackList> I3RecoResultStoragePolicy;
typedef GarnishedVector<I3RecoResultHeader, I3RecoTrackList, I3RecoResultStoragePolicy> I3RecoResult;

#endif
