#ifndef I3OBSERVABLEPARTICLE_H
#define I3OBSERVABLEPARTICLE_H

#include "dataclasses/I3Particle.h"

class I3ObservableParticle : public I3Particle
{
 public:
  virtual Bool_t IsCascade() =0;
  virtual Bool_t IsTrack() =0;
  ClassDef(I3ObservableParticle,1);
};

#endif //I3OBSERVABLEPARTICLE_H
