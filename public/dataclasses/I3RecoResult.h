/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResult.h,v 1.10 2004/02/16 16:13:28 troy Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/16 16:13:28 $
    @author

    @todo get/set best stuff

*/
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include "I3RecoTrackList.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"

class I3RecoResultHeader { };

typedef TClonesPolicy<I3RecoTrackList> I3RecoResultStoragePolicy;
typedef GarnishedVector<I3RecoResultHeader, I3RecoTrackList, I3RecoResultStoragePolicy> I3RecoResult;

#endif
