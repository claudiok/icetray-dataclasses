/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackList.h,v 1.11 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.11 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo

*/
#ifndef I3MCTRACKLIST_H
#define I3MCTRACKLIST_H

#include "I3MCTrack.h"
#include "StoragePolicy.h"

class I3MCTrackList : public VectorPolicy<I3MCTrack>::ThePolicy
{
 public:
  virtual ~I3MCTrackList(){};
  ClassDef(I3MCTrackList,1);
};

#endif
