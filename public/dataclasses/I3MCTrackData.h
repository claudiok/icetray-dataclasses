/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrackData.h,v 1.13 2004/02/23 17:38:39 troy Exp $

    @version $Revision: 1.13 $
    @date $Date: 2004/02/23 17:38:39 $
    @author

    @todo need to add "truth"

*/
#ifndef I3MCTRACKDATA_H
#define I3MCTRACKDATA_H

#include "dataclasses/I3MCTrackList.h"
#include "TObject.h"

class I3MCTrackData : public TObject, public MapPolicy<I3MCTrackList>::ThePolicy
{
 public:
  virtual ~I3MCTrackData() {};
  ClassDef(I3MCTrackData,1);
};

#endif
