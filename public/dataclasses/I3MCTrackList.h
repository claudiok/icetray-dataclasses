/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackList.h,v 1.10 2004/02/21 02:24:13 pretz Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/21 02:24:13 $
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

class I3MCTrackList : public AugVec<I3MCTrackListHeader, 
  				I3MCTrack, 
				I3MCTrackListStoragePolicy>{
ClassDef(I3MCTrackList,1);
};

#endif
