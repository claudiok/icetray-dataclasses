/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoTrackList.h,v 1.8 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.8 $
    @date $Date: 2004/02/20 21:42:08 $
    @author

    @todo

*/
#ifndef I3RECOTRACKLIST_H
#define I3RECOTRACKLIST_H

#include "I3RecoTrack.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3RecoTrackListHeader { };

typedef StoragePolicy<I3RecoTrack> I3RecoTrackListStoragePolicy;
typedef AugVec<I3RecoTrackListHeader, I3RecoTrack, I3RecoTrackListStoragePolicy> I3RecoTrackList;



#endif
