#ifndef I3MCTRACK_H
#define I3MCTRACK_H

#include <TObject.h>
#include "I3RecoTrackComposite.h"

class I3MCTrack : public I3RecoTrackComposite
{
  float     weight;

  public:
  I3MCTrack();

  float GetWeight() const;
  void  SetWeight(float weight_);

  ClassDef(I3MCTrack, 1);
};
#endif

