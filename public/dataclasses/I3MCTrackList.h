/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackList.h,v 1.9 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.9 $
    @date $Date: 2004/02/20 21:42:08 $
    @author

    @todo

*/
#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

#include "I3MCTrack.h"
#include "StoragePolicy.h"
#include "AugVec.h"


class I3MCTrackListHeader { };

typedef StoragePolicy<I3MCTrack> I3MCTrackListStoragePolicy;

typedef AugVec<I3MCTrackListHeader, 
			I3MCTrack, 
			I3MCTrackListStoragePolicy> I3MCTrackList;

#endif
