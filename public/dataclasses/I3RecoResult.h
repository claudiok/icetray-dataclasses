/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResult.h,v 1.13 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.13 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo get/set best stuff

*/
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include "I3RecoTrackList.h"

#include "StoragePolicy.h"

class I3RecoResult : public VectorPolicy<I3RecoTrackList>::ThePolicy
{

 public:
  virtual ~I3RecoResult() {};

  ClassDef(I3RecoResult, 1);
};

#endif
