/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackData.h,v 1.11 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.11 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo need to add "truth"

*/
#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include "dataclasses/I3MCTrackList.h"

class I3MCTrackData : public VectorPolicy<I3MCTrackList>::ThePolicy
{
 public:
  virtual ~I3MCTrackData(){};
  ClassDef(I3MCTrackData,1);
};

#endif
