/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackData.h,v 1.10 2004/02/21 02:24:13 pretz Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/21 02:24:13 $
    @author

    @todo need to add "truth"

*/
#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include "dataclasses/I3MCTrackList.h"

class I3MCTrackDataHeader { };

typedef StoragePolicy<I3MCTrackList> I3MCTrackDataStoragePolicy;

class I3MCTrackData : public AugVec<I3MCTrackDataHeader, 
				I3MCTrackList, 
				I3MCTrackDataStoragePolicy>{
ClassDef(I3MCTrackData,1);
};

#endif
