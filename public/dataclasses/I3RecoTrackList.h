/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoTrackList.h,v 1.7 2004/02/17 16:54:39 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/17 16:54:39 $
    @author

    @todo

*/
#ifndef I3RECOTRACKLIST_H
#define I3RECOTRACKLIST_H

#include "I3RecoTrack.h"
#include "StoragePolicy.h"
#include "GarnishedVector.h"

class I3RecoTrackListHeader { };

typedef StoragePolicy<I3RecoTrack> I3RecoTrackListStoragePolicy;
typedef GarnishedVector<I3RecoTrackListHeader, I3RecoTrack, I3RecoTrackListStoragePolicy> I3RecoTrackList;



#endif
