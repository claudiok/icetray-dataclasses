/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoTrackList.h,v 1.10 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo

*/
#ifndef I3RECOTRACKLIST_H
#define I3RECOTRACKLIST_H

#include "I3RecoTrack.h"
#include "StoragePolicy.h"

class I3RecoTrackList : public VectorPolicy<I3RecoTrack>::ThePolicy
{
 public:
  virtual ~I3RecoTrackList(){};
  ClassDef(I3RecoTrackList, 1);
};

#endif
