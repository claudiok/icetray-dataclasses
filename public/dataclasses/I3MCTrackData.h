/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackData.h,v 1.8 2004/02/17 16:54:39 troy Exp $

    @version $Revision: 1.8 $
    @date $Date: 2004/02/17 16:54:39 $
    @author

    @todo need to add "truth"

*/
#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include "dataclasses/I3MCTrackList.h"

class I3MCTrackDataHeader { };

typedef StoragePolicy<I3MCTrackList> I3MCTrackDataStoragePolicy;

typedef GarnishedVector<I3MCTrackDataHeader, 
			I3MCTrackList, 
			I3MCTrackDataStoragePolicy> I3MCTrackData;

#endif
