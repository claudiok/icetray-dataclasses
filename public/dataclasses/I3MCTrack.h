/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3MCTrack.h,v 1.3 2004/02/18 16:10:33 troy Exp $

    @version $Revision: 1.3 $
    @date $Date: 2004/02/18 16:10:33 $
    @author

    @todo

*/
#ifndef I3MCTRACK_H
#define I3MCTRACK_H

#include <TObject.h>
#include "dataclasses/I3Track.h"

class I3MCTrack : public I3Track
{
  float     fWeight;

  public:
  I3MCTrack() { fWeight=1; }

  float Weight() const { return fWeight; }
  void  Weight(float weight_) { fWeight = weight_; }

  ClassDef(I3MCTrack, 1);
};
#endif

