/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackList.h,v 1.8 2004/02/17 16:54:39 troy Exp $

    @version $Revision: 1.8 $
    @date $Date: 2004/02/17 16:54:39 $
    @author

    @todo

*/
#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

#include "I3MCTrack.h"
#include "StoragePolicy.h"
#include "GarnishedVector.h"


class I3MCTrackListHeader { };

typedef StoragePolicy<I3MCTrack> I3MCTrackListStoragePolicy;

typedef GarnishedVector<I3MCTrackListHeader, 
			I3MCTrack, 
			I3MCTrackListStoragePolicy> I3MCTrackList;

#endif
