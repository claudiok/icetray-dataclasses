/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoTrackList.h,v 1.6 2004/02/16 00:55:12 troy Exp $

    @version $Revision: 1.6 $
    @date $Date: 2004/02/16 00:55:12 $
    @author

    @todo

*/
#ifndef I3RECOTRACKLIST_H
#define I3RECOTRACKLIST_H

#include "I3RecoTrack.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"

class I3RecoTrackListHeader { };

typedef TClonesPolicy<I3RecoTrack> I3RecoTrackListStoragePolicy;
typedef GarnishedVector<I3RecoTrackListHeader, I3RecoTrack, I3RecoTrackListStoragePolicy> I3RecoTrackList;



#endif
