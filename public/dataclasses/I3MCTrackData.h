/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackData.h,v 1.7 2004/02/17 15:48:13 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/17 15:48:13 $
    @author

    @todo need to add "truth"

*/
#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include "dataclasses/I3MCTrackList.h"

class I3MCTrackDataHeader { };

typedef TClonesPolicy<I3MCTrackList> I3MCTrackDataStoragePolicy;

typedef GarnishedVector<I3MCTrackDataHeader, 
			I3MCTrackList, 
			I3MCTrackDataStoragePolicy> I3MCTrackData;

#endif
