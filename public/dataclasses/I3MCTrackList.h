/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackList.h,v 1.7 2004/02/16 04:19:10 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/16 04:19:10 $
    @author

    @todo

*/
#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

#include "I3MCTrack.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"


class I3MCTrackListHeader { };

typedef TClonesPolicy<I3MCTrack> I3MCTrackListStoragePolicy;

typedef GarnishedVector<I3MCTrackListHeader, 
			I3MCTrack, 
			I3MCTrackListStoragePolicy> I3MCTrackList;

#endif
